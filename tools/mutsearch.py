#!/usr/bin/env python3
"""Natural-mutation search over a C draft of one LEON function.

Usage: mutsearch.py <cpu> <function> <draft.c> <outdir> [--flags "-mcpu=v8 -O3 -g"] [--seconds 300] [--maxmut 3]
                    [--seed 1] [--objective score|exact|region:LO-HI[,LO-HI...]] [--stores] [--store-sym SYM[:SIZE]]
                    [--hill] [--sideways] [--jobs 1] [--ops mv,run,dc,dv,ty,part,read,case,neg]
                    [--type NAME=T,T,...] [--part-type T,...] [--funcs NAME,...] [--only REGEX] [--freeze REGEX]
                    [--dry N]

Every variant is the draft (or, with --hill, the best variant so far) plus 1..--maxmut random mutations that keep
the meaning of the C code. The function <function> (and the static helpers named by --funcs, which are inlined into
it) is parsed into statement lists; --only REGEX makes statements whose text matches it the preferred picks (80 %),
--freeze REGEX keeps matching statements in place. The mutations are:
  mv    move one statement within its list, only past statements it has no def/use conflict with
  run   move a run of 2-4 consecutive statements the same way
  dc    move one declaration within its declaration group (initialiser dependencies kept)
  dv    swap two declarators inside one declaration
  ty    change the type of one local among the types given by --type (only locals named there, or '*' for all
        scalar integer locals; the caller asserts that the values fit every listed type)
  part  compute a subexpression of an assignment's or return's value (the whole value, or a parenthesised part)
        into a new local first, at a legal earlier position ("value first", "part locals")
  read  the same for one read of a global (variable, member or constant-index element): "read positions"
  case  move one case group of a switch (groups that end in break/return/continue/goto; a fall-through group
        moves together with the group it falls into; a last group without an exit stays last)
  neg   swap the arms of an if/else whose arms are both blocks, with the condition inverted
Def/use: locals by name; globals by name and member/constant-index path (a variable index covers the whole
object); a call is a barrier for every global and memory access and for locals whose address is taken; volatile
accesses (macros or declarations containing 'volatile', '*(volatile ...)' casts, volatile locals and pointer locals) keep their order among themselves
and with calls and pointer accesses; statements with return/break/continue/goto, labels and declarations are not
crossed. Reads of ordinary globals may move past volatile accesses.

Types for ty / part / read: u8, u16, u32, s8, s16, int, or any C type name. --part-type (default u32) is the type of
the new local of part and read.

Objective (higher is better): score = tools/diff.py score; exact = register-exact firmware rows of the whole
function (tools/regions.py), then score; region:LO-HI,... = register-exact rows inside those firmware address ranges,
then score. --stores rejects a variant whose emitted store sequence (tools/stseq.py, with calls; --store-sym limits
it to one symbol) has more differing rows than the draft's.

Without --hill every variant starts from the draft; --hill continues from each better variant (--sideways: also
from equally good ones). Builds run one at a time under nice -n 10 (--jobs 2 at most). Output in <outdir>: base.c, log.tsv (every build:
number, objective, score, mutations), hit-NNNNN.c for every variant better than the draft (hits.tsv lists them),
best.c, and match.c (the search stops on a byte-exact match). Every hit needs checking by hand: a mutation keeps the
meaning only as far as the def/use model above sees it. --dry N writes N variants without compiling them.
"""
import argparse, hashlib, os, pathlib, random, re, subprocess, sys, tempfile, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import diff, regions, srcpath, stseq

TYPEALIAS = {"u8": "unsigned char", "u16": "unsigned short", "u32": "unsigned int", "s8": "signed char",
             "s16": "short", "int": "int"}
KEYWORDS = {"if", "else", "for", "while", "do", "switch", "case", "default", "break", "continue", "return", "goto",
            "sizeof", "typedef", "struct", "union", "enum", "static", "extern", "const", "volatile", "register",
            "auto", "inline", "__inline__", "signed", "unsigned", "char", "short", "int", "long", "float", "double",
            "void"}
TYPEWORDS = {"static", "const", "volatile", "register", "signed", "unsigned", "char", "short", "int", "long", "float",
             "double", "void", "inline", "__inline__", "auto"}
TOK = re.compile(r'0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*|[A-Za-z_]\w*|->|\+\+|--|<<=|>>=|<<|>>|<=|>=|==|!=|&&|\|\||'
                 r'[-+*/%&|^]=|[{}()\[\];,.?:=<>!~+\-*/%&|^]')
ASSIGN = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="}
REL = {"==": "!=", "!=": "==", "<": ">=", ">=": "<", ">": "<=", "<=": ">"}


def mask(src):
    """comments and string/char literals blanked (same length), so offsets stay valid"""
    def blank(m): return re.sub(r'[^\n]', ' ', m.group(0))
    return re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', blank, src, flags=re.S)


def match_close(m, p):
    """index of the bracket closing the one at p"""
    o = m[p]; c = {"(": ")", "[": "]", "{": "}"}[o]; d = 0
    for i in range(p, len(m)):
        if m[i] == o: d += 1
        elif m[i] == c:
            d -= 1
            if d == 0: return i
    raise ValueError("unbalanced " + o)


class Node:
    def __init__(self, kind, start, end, **kw):
        self.kind, self.start, self.end = kind, start, end
        self.__dict__.update(kw)


class Func:
    """parse of one function definition: statement lists, locals, def/use facts"""

    def __init__(self, src, fn):
        self.src = src; self.m = m = mask(src); self.fn = fn
        h = None
        for x in re.finditer(r'\b' + re.escape(fn) + r'\s*\(', m):
            q = match_close(m, x.end() - 1)
            r = re.match(r'\s*\{', m[q + 1:])
            if r: h = (x.start(), x.end() - 1, q, q + 1 + r.end() - 1); break
        if not h: raise SystemExit("no definition of %s in the draft" % fn)
        self.hstart, po, pc, self.open = h
        self.close = match_close(m, self.open)
        self.typedefs = set(re.findall(r'\btypedef\b[^;{]*?(\w+)\s*;', m)) | \
            set(re.findall(r'\btypedef\b[^;]*\(\s*\*\s*(\w+)\s*\)', m))
        self.volnames, self.callmacros = set(), set()
        for d in re.finditer(r'^\s*#\s*define\s+(\w+)(\()?([^\n]*)', src, re.M):
            if "volatile" in d.group(3): self.volnames.add(d.group(1))
            elif d.group(2): self.callmacros.add(d.group(1))
        top = m[:self.hstart]
        for st in re.finditer(r'[^;{}]*\bvolatile\b[^;{}]*;', top):
            t = st.group(0)
            if "(" in t and "#" not in t and "*" not in t.split("(")[0]: continue
            for nm in re.findall(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*(?:[,;=])', t): self.volnames.add(nm)
        self.locals = {}   # name -> dict(type, ptr, arr, node, decl)
        for p in m[po + 1:pc].split(","):
            ids = re.findall(r'[A-Za-z_]\w*', p)
            if ids and ids[-1] not in KEYWORDS:
                self.locals[ids[-1]] = {"type": " ".join(ids[:-1]), "ptr": "*" in p, "arr": "[" in p, "node": None,
                                        "param": True}
        self.root = self.parse_block(self.open)
        self.addr = set(n for n in re.findall(r'(?<![\w)\]])\s*&\s*([A-Za-z_]\w*)', m[self.open:self.close])
                        if n in self.locals)

    # ---- parser
    def ws(self, p):
        while p < len(self.m) and self.m[p].isspace(): p += 1
        return p

    def word(self, p):
        x = re.match(r'[A-Za-z_]\w*', self.m[p:p + 64])
        return x.group(0) if x else ""

    def parse_block(self, p):
        e = match_close(self.m, p)
        items, q = [], p + 1
        while True:
            q = self.ws(q)
            if q >= e: break
            n = self.parse_stmt(q); items.append(n); q = n.end
        return Node("block", p, e + 1, items=items)

    def scan_semi(self, p):
        i = p
        while self.m[i] != ";":
            if self.m[i] in "([{": i = match_close(self.m, i)
            i += 1
        return i + 1

    def parse_stmt(self, p):
        m = self.m
        if m[p] == "{": return self.parse_block(p)
        if m[p] == ";": return Node("empty", p, p + 1)
        w = self.word(p)
        if w == "if":
            c = self.ws(p + 2); ce = match_close(m, c)
            th = self.parse_stmt(self.ws(ce + 1)); q = self.ws(th.end); el, ek = None, None
            if self.word(q) == "else": ek = q; el = self.parse_stmt(self.ws(q + 4))
            return Node("if", p, (el or th).end, cond=(c + 1, ce), then=th, els=el, elsekw=ek)
        if w in ("for", "while", "switch"):
            c = self.ws(p + len(w)); ce = match_close(m, c)
            b = self.parse_stmt(self.ws(ce + 1))
            return Node(w, p, b.end, cond=(c + 1, ce), body=b)
        if w == "do":
            b = self.parse_stmt(self.ws(p + 2)); q = self.ws(b.end)
            return Node("do", p, self.scan_semi(q), body=b)
        if w in ("case", "default"):
            i, d, qm = p, 0, 0
            while True:
                ch = m[i]
                if ch in "([": i = match_close(m, i)
                elif ch == "?": qm += 1
                elif ch == ":":
                    if qm == 0: break
                    qm -= 1
                i += 1
            return Node("label", p, i + 1)
        x = re.match(r'([A-Za-z_]\w*)\s*:(?!:)', m[p:p + 80])
        if x and w not in KEYWORDS: return Node("label", p, p + x.end())
        e = self.scan_semi(p)
        if w in ("return", "break", "continue", "goto"): return Node(w, p, e)
        if self.is_decl(p, e):
            n = Node("decl", p, e); self.add_decl(n); return n
        return Node("expr", p, e)

    def is_decl(self, p, e):
        ts = TOK.findall(self.m[p:e])
        if not ts: return False
        if ts[0] in TYPEWORDS or ts[0] in ("struct", "union", "enum"): return True
        return ts[0] in self.typedefs and len(ts) > 1 and re.match(r'[A-Za-z_*]', ts[1]) is not None

    def decl_parts(self, n):
        """(type text end offset, [(start, end, name, ptr, arr, init)]) of a declaration node"""
        m = self.m; i = n.start
        while True:   # type specifiers
            i = self.ws(i); w = self.word(i)
            if w in TYPEWORDS or w in self.typedefs: i += len(w); continue
            if w in ("struct", "union", "enum"):
                i = self.ws(i + len(w)); i += len(self.word(i)); continue
            break
        tend = i; out = []; s = i; j = i
        while j < n.end - 1:
            if m[j] in "([{": j = match_close(m, j) + 1; continue
            if m[j] == ",":
                out.append((s, j)); s = j + 1
            j += 1
        out.append((s, n.end - 1))
        res = []
        for a, b in out:
            t = m[a:b]; nm = re.search(r'[A-Za-z_]\w*', t)
            if not nm: continue
            res.append((a, b, nm.group(0), "*" in t.split("=")[0], "[" in t.split("=")[0],
                        t.split("=", 1)[1] if "=" in t else None))
        return tend, res

    def add_decl(self, n):
        tend, ds = self.decl_parts(n)
        ty = re.sub(r'\s+', ' ', self.m[n.start:tend].strip())
        for a, b, nm, ptr, arr, init in ds:
            self.locals[nm] = {"type": ty, "ptr": ptr, "arr": arr, "node": n, "param": False}

    # ---- lists
    def lists(self):
        """every statement list: (block node, items)"""
        out = []

        def walk(n):
            if n is None: return
            if n.kind == "block":
                out.append(n)
                for x in n.items: walk(x)
            elif n.kind == "if": walk(n.then); walk(n.els)
            elif n.kind in ("for", "while", "switch", "do"): walk(n.body)
        walk(self.root)
        return out

    # ---- def/use
    def exits(self, n, loop=False, sw=False):
        """True when the statement can leave its list (return, goto, a label, break/continue not inside it)"""
        k = n.kind
        if k in ("return", "goto"): return True
        if k == "label": return not (sw and re.match(r'(case|default)\b', self.m[n.start:n.end]))
        if k == "break": return not (loop or sw)
        if k == "continue": return not loop
        if k == "block": return any(self.exits(x, loop, sw) for x in n.items)
        if k == "if": return self.exits(n.then, loop, sw) or (n.els is not None and self.exits(n.els, loop, sw))
        if k in ("for", "while", "do"): return self.exits(n.body, True, sw)
        if k == "switch": return self.exits(n.body, loop, True)
        return False

    def du_node(self, n):
        f = self.du(n.start, n.end); f["ctrl"] = n.kind in ("label", "decl") or self.exits(n)
        return f

    def du(self, a, b):
        """facts of source range [a, b): dict(ld, lu, g=[(name, path, write)], call, vol, mem=[write], ctrl)"""
        m = self.m[a:b]
        toks = [(x.group(0), x.start()) for x in TOK.finditer(m)]
        T = [t for t, _ in toks]
        f = {"ld": set(), "lu": set(), "g": [], "call": False, "vol": "volatile" in m, "mem": [], "ctrl": False}
        for k, t in enumerate(T):
            if t == "*" and T[k + 1:k + 2] == ["("] and (k == 0 or T[k - 1] in ASSIGN or T[k - 1] in
                                                         "([,;{}?:!~&|^+-*/%<>=" or T[k - 1] in ("return",)):
                f["mem"].append(True)
            if not re.match(r'[A-Za-z_]', t) or t in KEYWORDS or t in self.typedefs: continue
            if k > 0 and T[k - 1] in (".", "->"): continue
            nxt = T[k + 1] if k + 1 < len(T) else ""
            if nxt == "(" and t not in self.locals:
                if t in self.volnames: f["vol"] = True
                else: f["call"] = True
                continue
            if t in self.volnames: f["vol"] = True; continue
            if t in self.locals and "volatile" in self.locals[t]["type"]: f["vol"] = True   # volatile local / pointer
            # postfix chain
            j, path, idx_var = k + 1, [], False
            while j < len(T):
                if T[j] in (".", "->") and j + 1 < len(T):
                    path.append(T[j] + T[j + 1]); j += 2
                elif T[j] == "[":
                    d, q = 0, j
                    while q < len(T):
                        if T[q] == "[": d += 1
                        elif T[q] == "]":
                            d -= 1
                            if d == 0: break
                        q += 1
                    inner = T[j + 1:q]
                    if len(inner) == 1 and re.match(r'\d|0[xX]', inner[0]): path.append("[%d]" % int(inner[0].rstrip("uUlL"), 0))
                    else: path.append("[*]"); idx_var = True
                    j = q + 1
                else: break
            after = T[j] if j < len(T) else ""
            pre = T[k - 1] if k > 0 else ""
            write = after in ASSIGN or after in ("++", "--") or pre in ("++", "--")
            rmw = write and (after != "=")
            deref = pre == "*" and (k < 2 or T[k - 2] in ASSIGN or T[k - 2] in "([,;{}?:!~&|^+-*/%<>=" or T[k - 2] == "return")
            if t in self.locals:
                L = self.locals[t]
                through = L["ptr"] and (deref or any(p.startswith("->") or p.startswith("[") for p in path))
                if through:
                    f["lu"].add(t); f["mem"].append(write)
                elif t in self.addr:
                    f["g"].append(("&" + t, tuple(path), write))
                    if rmw: f["g"].append(("&" + t, tuple(path), False))
                else:
                    partial = bool(path)
                    if write:
                        f["ld"].add(t)
                        if rmw or partial: f["lu"].add(t)
                    else: f["lu"].add(t)
            else:
                if deref: f["mem"].append(write)
                f["g"].append((t, tuple(path), write))
                if rmw: f["g"].append((t, tuple(path), False))
        return f


def paths_overlap(p, q):
    for a, b in zip(p, q):
        if a == "[*]" or b == "[*]": return True
        if a != b: return False
    return True


def conflict(A, B):
    if A["ctrl"] or B["ctrl"]: return True
    if A["ld"] & (B["ld"] | B["lu"]) or B["ld"] & A["lu"]: return True
    for n1, p1, w1 in A["g"]:
        for n2, p2, w2 in B["g"]:
            if n1 == n2 and (w1 or w2) and paths_overlap(p1, p2): return True
    gw = lambda F: any(w for _, _, w in F["g"])
    anyg = lambda F: bool(F["g"])
    for X, Y in ((A, B), (B, A)):
        if X["call"] and (anyg(Y) or Y["mem"] or Y["call"] or Y["vol"]): return True
        if X["mem"] and (Y["mem"] and (any(X["mem"]) or any(Y["mem"])) or (any(X["mem"]) and anyg(Y)) or gw(Y)): return True
        if X["vol"] and (Y["vol"] or Y["mem"]): return True
    return False


# ---- mutations: each returns (new source, description) or None
def seg_reorder(F, blk, i, j, order):
    """rewrite items i..j (inclusive) of blk in the given order (list of indexes into i..j)"""
    it = blk.items
    s0 = it[i - 1].end if i > 0 else blk.start + 1
    segs = []
    for k in range(i, j + 1):
        a = it[k - 1].end if k > 0 else blk.start + 1
        segs.append(F.src[a:it[k].end])
    new = "".join(segs[k - i] for k in order)
    return F.src[:s0] + new + F.src[it[j].end:]


def segments(F, blk):
    """ranges of items between labels/declarations: [(lo, hi)] inclusive, movable statements only"""
    out, cur = [], []
    for k, n in enumerate(blk.items):
        if n.kind in ("label", "decl", "empty"):
            if cur: out.append(cur)
            cur = []
        else: cur.append(k)
    if cur: out.append(cur)
    return out


def pick_stmt(F, rnd, only, freeze):
    c = []
    for blk in F.lists():
        for seg in segments(F, blk):
            if len(seg) < 2: continue
            for k in seg:
                t = F.src[blk.items[k].start:blk.items[k].end]
                if freeze and re.search(freeze, t): continue
                c.append((blk, seg, k, bool(only and re.search(only, t))))
    if not c: return None
    foc = [x for x in c if x[3]]
    return rnd.choice(foc if foc and rnd.random() < 0.8 else c)


def dus(F, blk):
    return [F.du_node(n) for n in blk.items]


def mut_mv(F, rnd, a, run=1):
    p = pick_stmt(F, rnd, a.only, a.freeze)
    if not p: return None
    blk, seg, k, _ = p
    if run > 1:
        if seg.index(k) + run > len(seg): return None
    ks = list(range(k, k + run))
    if a.freeze and any(re.search(a.freeze, F.src[blk.items[x].start:blk.items[x].end]) for x in ks): return None
    D = dus(F, blk); me = [D[x] for x in ks]
    lo = k
    while lo - 1 >= seg[0] and not any(conflict(x, D[lo - 1]) for x in me): lo -= 1
    hi = k + run - 1
    while hi + 1 <= seg[-1] and not any(conflict(x, D[hi + 1]) for x in me): hi += 1
    if hi - lo + 1 <= run: return None
    nk = rnd.randint(lo, hi - run + 1)
    if nk == k: return None
    rest = [x for x in range(lo, hi + 1) if x not in ks]
    order = rest[:nk - lo] + ks + rest[nk - lo:]
    t = F.src[blk.items[k].start:blk.items[k].end].split("\n")[0].strip()
    return seg_reorder(F, blk, lo, hi, order), "%s '%s'%s %+d" % ("mv" if run == 1 else "run", t[:40],
                                                                     "" if run == 1 else " x%d" % run, nk - k)


def mut_run(F, rnd, a): return mut_mv(F, rnd, a, rnd.randint(2, 4))


def decl_groups(F):
    out = []
    for blk in F.lists():
        cur = []
        for k, n in enumerate(blk.items):
            if n.kind == "decl" and "static" not in F.m[n.start:n.end]: cur.append(k)
            else:
                if len(cur) > 1: out.append((blk, cur))
                cur = []
        if len(cur) > 1: out.append((blk, cur))
    return out


def mut_dc(F, rnd, a):
    g = decl_groups(F)
    if not g: return None
    blk, ks = rnd.choice(g)
    i, j = rnd.choice(ks), rnd.choice(ks)
    if i == j: return None
    names = lambda n: {d[2] for d in F.decl_parts(n)[1]}
    uses = lambda n: set(re.findall(r'[A-Za-z_]\w*', " ".join(d[5] or "" for d in F.decl_parts(n)[1])))
    lo, hi = min(i, j), max(i, j)
    x = blk.items[i]
    for k in range(lo, hi + 1):
        if k == i: continue
        y = blk.items[k]
        if names(x) & uses(y) or names(y) & uses(x): return None
    order = [k for k in range(lo, hi + 1) if k != i]
    order.insert(j - lo, i)
    return seg_reorder(F, blk, lo, hi, order), "dc '%s' %+d" % (F.src[x.start:x.end].strip()[:40], j - i)


def mut_dv(F, rnd, a):
    ds = [n for b in F.lists() for n in b.items if n.kind == "decl" and len(F.decl_parts(n)[1]) > 1]
    if not ds: return None
    n = rnd.choice(ds); _, parts = F.decl_parts(n)
    i, j = rnd.sample(range(len(parts)), 2)
    pi, pj = parts[i], parts[j]
    if any(re.search(r'\b%s\b' % re.escape(p[2]), q[5] or "") for p in parts for q in parts if p is not q): return None
    lo, hi = sorted((i, j))
    s = F.src
    A, B = parts[lo], parts[hi]
    ta, tb = s[A[0]:A[1]], s[B[0]:B[1]]
    la, lb = re.match(r'\s*', ta).group(0), re.match(r'\s*', tb).group(0)
    new = s[:A[0]] + la + tb.strip() + s[A[1]:B[0]] + lb + ta.strip() + s[B[1]:]
    return new, "dv %s<->%s" % (A[2], B[2])


def ctype(t): return TYPEALIAS.get(t, t)


INTTYPE = re.compile(r'^(?:(?:un)?signed )?(?:char|short|int|long)(?: int)?$|^(?:un)?signed$')


def mut_ty(F, rnd, a):
    if not a.types: return None
    c = []
    for nm, L in F.locals.items():
        if L["param"] or L["ptr"] or L["arr"] or L["node"] is None: continue
        base = re.sub(r'\b(const|register)\b\s*', '', L["type"]).strip()
        if "static" in L["type"] or "volatile" in L["type"]: continue
        opts = a.types.get(nm) or (a.types.get("*") if INTTYPE.match(base) else None)
        if opts:
            o = [ctype(t) for t in opts if ctype(t) != base]
            if o: c.append((nm, L, o))
    if not c: return None
    nm, L, o = rnd.choice(c); t = rnd.choice(o); n = L["node"]
    tend, parts = F.decl_parts(n)
    s = F.src
    if len(parts) == 1:
        new = s[:n.start] + t + " " + s[tend:n.end].lstrip() + s[n.end:]
    else:
        k = next(i for i, p in enumerate(parts) if p[2] == nm)
        ind = re.search(r'[ \t]*$', s[:n.start]).group(0)
        d = s[parts[k][0]:parts[k][1]].strip()
        keep = [s[p[0]:p[1]].strip() for i, p in enumerate(parts) if i != k]
        tyt = s[n.start:tend].strip()
        new = s[:n.start] + tyt + " " + ", ".join(keep) + ";\n" + ind + t + " " + d + ";" + s[n.end:]
    return new, "ty %s %s" % (nm, t)


def fresh(F, base):
    k = 0
    while re.search(r'\b%s%d\b' % (base, k), F.src): k += 1
    return "%s%d" % (base, k)


def insert_decl(F, src, decl):
    """add a declaration line at the end of the function's outermost declaration group (offsets before it shift)"""
    it = F.root.items
    last = None
    for n in it:
        if n.kind == "decl": last = n
        else: break
    if last is not None:
        ind = re.search(r'[ \t]*$', F.src[:last.start]).group(0)
        return last.end, "\n" + ind + decl
    first = it[0] if it else None
    ind = re.search(r'[ \t]*$', F.src[:first.start]).group(0) if first else "    "
    return F.root.start + 1, "\n" + ind + decl + "\n"


def mut_part(F, rnd, a, read=False):
    cand = []
    for blk in F.lists():
        for seg in segments(F, blk):
            for k in seg:
                n = blk.items[k]
                if n.kind not in ("expr", "return"): continue
                t = F.m[n.start:n.end]
                if n.kind == "return":
                    x = re.match(r'return\b\s*', t)
                    if not x or t[x.end():].strip() == ";": continue
                    vs = n.start + x.end()
                else:
                    x = re.match(r'[^;=]*?(?<![=!<>+\-*/%&|^])=(?!=)', t)
                    if not x: continue
                    vs = n.start + x.end()
                ve = n.end - 1
                while F.m[vs].isspace(): vs += 1
                cand.append((blk, seg, k, vs, ve))
    if not cand: return None
    blk, seg, k, vs, ve = rnd.choice(cand)
    m = F.m
    subs = []
    if read:
        for x in TOK.finditer(m[vs:ve]):
            t = x.group(0); p = vs + x.start()
            if not re.match(r'[A-Za-z_]', t) or t in KEYWORDS or t in F.locals or t in F.volnames: continue
            if p > 0 and m[p - 1] in ".>" or re.match(r'\s*\(', m[p + len(t):]): continue
            q = p + len(t)
            while True:
                r = re.match(r'\s*(\.|->)\s*[A-Za-z_]\w*|\s*\[\s*(?:0[xX][0-9a-fA-F]+|\d+)\s*\]', m[q:])
                if not r: break
                q += r.end()
            if re.match(r'\s*\[', m[q:]): continue
            subs.append((p, q))
    else:
        whole = m[vs:ve].strip()
        if not re.fullmatch(r'[A-Za-z_]\w*|0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*', whole): subs.append((vs, vs + len(whole)))
        for x in re.finditer(r'\(', m[vs:ve]):
            p = vs + x.start(); q = match_close(m, p) + 1
            pre = m[:p].rstrip()
            inner = m[p + 1:q - 1].strip()
            if re.search(r'[A-Za-z_]\w*$', pre) and not re.search(r'\b(return|sizeof)$', pre): continue   # call args
            if re.fullmatch(r'(?:(?:un)?signed\s+)?(?:char|short|int|long)(?:\s+int)?|[A-Za-z_]\w*\s*\*?|struct\s+\w+\s*\*?', inner) \
                    and (inner.split()[0] in TYPEWORDS or inner.split()[0] in F.typedefs or inner.startswith("struct")): continue   # cast
            if re.fullmatch(r'[A-Za-z_]\w*|0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*', inner): continue
            subs.append((p, q))
    if not subs: return None
    p, q = rnd.choice(subs)
    f = F.du(p, q)
    if f["ld"] or any(w for _, _, w in f["g"]) or f["call"] or f["vol"] or any(f["mem"]) or f["ctrl"]: return None
    if re.search(r'\+\+|--|(?<![=!<>])=(?!=)', m[p:q]): return None
    D = dus(F, blk)
    lo = k
    while lo - 1 >= seg[0] and not conflict(f, D[lo - 1]): lo -= 1
    nk = rnd.randint(lo, k)
    name = fresh(F, "r" if read else "v")
    ty = ctype(rnd.choice(a.part_type))
    n = blk.items[k]; ref = blk.items[nk]
    ind = re.search(r'[ \t]*$', F.src[:ref.start]).group(0)
    expr = F.src[p:q].strip()
    if expr.startswith("(") and match_close(m, p) == q - 1: expr = expr[1:-1].strip()
    s = F.src
    s2 = s[:p] + name + s[q:]          # replace the use (p, q lie inside item k, after ref.start)
    s3 = s2[:ref.start] + name + " = " + expr + ";\n" + ind + s2[ref.start:]
    at, txt = insert_decl(F, s3, ty + " " + name + ";")
    s4 = s3[:at] + txt + s3[at:]
    return s4, "%s %s=%s %+d" % ("read" if read else "part", name, re.sub(r'\s+', ' ', expr)[:30], nk - k)


def mut_read(F, rnd, a): return mut_part(F, rnd, a, True)


def mut_case(F, rnd, a):
    sws = []

    def walk(n):
        if n is None: return
        if n.kind == "switch" and n.body.kind == "block": sws.append(n)
        for x in getattr(n, "items", []): walk(x)
        for at in ("then", "els", "body"): walk(getattr(n, at, None))
    walk(F.root)
    if not sws: return None
    sw = rnd.choice(sws); it = sw.body.items
    groups, cur = [], []
    for k, n in enumerate(it):
        if n.kind == "label" and cur and it[cur[-1]].kind != "label": groups.append(cur); cur = []
        cur.append(k)
    if cur: groups.append(cur)
    units, u = [], []
    for g in groups:
        u += g
        last = it[g[-1]]
        if last.kind in ("break", "return", "continue", "goto"): units.append(u); u = []
    fixed_tail = u
    if len(units) < 2: return None
    i = rnd.randrange(len(units)); j = rnd.randrange(len(units))
    if i == j: return None
    us = units[:]; x = us.pop(i); us.insert(j, x)
    order = [k for uu in us for k in uu] + fixed_tail
    lab = lambda uu: F.src[it[uu[0]].start:it[uu[0]].end].strip()
    return seg_reorder(F, sw.body, 0, len(it) - 1, order), "case %s %+d" % (lab(x), j - i)


def invert(c):
    t = mask(c)
    depth, top = 0, []
    for x in TOK.finditer(t):
        s = x.group(0)
        if s in "([": depth += 1
        elif s in ")]": depth -= 1
        elif depth == 0: top.append((s, x.start(), x.end()))
    ops = [o for o in top if o[0] in REL]
    if not any(o[0] in ("&&", "||", "?", "=", "&", "|", "^", "<<", ">>", "+", "-", "*", "/", "%") for o in top) and len(ops) == 1:
        s, a, b = ops[0]
        return c[:a] + REL[s] + c[b:]
    cs = c.strip()
    if len(top) == 1 and top[0][0] == "!" and c[:top[0][1]].strip() == "":   # '!x' or '!(...)'
        return c[top[0][2]:].strip()
    return "!(" + cs + ")"


def mut_neg(F, rnd, a):
    c = []

    def walk(n):
        if n is None: return
        if n.kind == "if" and n.els is not None and n.then.kind == "block" and n.els.kind == "block": c.append(n)
        for x in getattr(n, "items", []): walk(x)
        for at in ("then", "els", "body"): walk(getattr(n, at, None))
    walk(F.root)
    if not c: return None
    n = rnd.choice(c); s = F.src
    a0, a1 = n.cond
    th, el = s[n.then.start:n.then.end], s[n.els.start:n.els.end]
    new = s[:a0] + invert(s[a0:a1]) + s[a1:n.then.start] + el + s[n.then.end:n.els.start] + th + s[n.els.end:]
    return new, "neg if (%s)" % re.sub(r'\s+', ' ', s[a0:a1])[:30]


OPS = {"mv": mut_mv, "run": mut_run, "dc": mut_dc, "dv": mut_dv, "ty": mut_ty, "part": mut_part, "read": mut_read,
       "case": mut_case, "neg": mut_neg}
WEIGHT = {"mv": 40, "run": 15, "dc": 8, "dv": 4, "ty": 10, "part": 8, "read": 8, "case": 12, "neg": 3}


def variant(src, fn, rnd, a):
    ds = []
    for _ in range(rnd.randint(1, a.maxmut)):
        try: F = Func(src, rnd.choice([fn] + a.funcs))
        except (ValueError, IndexError): return None, ds
        names = [o for o in a.ops]
        op = rnd.choices(names, [WEIGHT.get(o, 5) for o in names])[0]
        try: r = OPS[op](F, rnd, a)
        except (ValueError, IndexError, StopIteration): r = None
        if r: src, d = r; ds.append(d)
    return src, ds


# ---- evaluation
def objective(a, o):
    if a.objective == "score":
        r = diff.compare(a.cpu, a.fn, o); return (r[5],), r[5], r[6]
    ev = regions.evaluate(a.cpu, a.fn, o, a.ranges)
    return (ev["exact"], ev["score"]), ev["score"], ev["match"]


def stores_bad(a, o):
    fw, ours = stseq.sequence(a.cpu, a.fn, o, a.store_sym, calls=True)
    import difflib
    sm = difflib.SequenceMatcher(a=fw, b=ours, autojunk=False)
    return max(len(fw), len(ours)) - sum(b.size for b in sm.get_matching_blocks())


def main():
    ap = argparse.ArgumentParser(usage=__doc__.split("\n\n")[1])
    ap.add_argument("cpu"); ap.add_argument("fn"); ap.add_argument("draft"); ap.add_argument("outdir")
    ap.add_argument("--flags", default="-mcpu=v8 -O3 -g"); ap.add_argument("--seconds", type=float, default=300)
    ap.add_argument("--maxmut", type=int, default=3); ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--objective", default="score"); ap.add_argument("--stores", action="store_true")
    ap.add_argument("--store-sym", action="append"); ap.add_argument("--hill", action="store_true")
    ap.add_argument("--sideways", action="store_true"); ap.add_argument("--jobs", type=int, default=1)
    ap.add_argument("--ops", default="mv,run,dc,dv,ty,part,read,case,neg"); ap.add_argument("--type", action="append")
    ap.add_argument("--part-type", default="u32"); ap.add_argument("--only"); ap.add_argument("--freeze")
    ap.add_argument("--dry", type=int, default=0); ap.add_argument("--funcs", default="")
    a = ap.parse_args()
    a.ops = [o for o in a.ops.split(",") if o]; a.funcs = [f for f in a.funcs.split(",") if f]
    bad = [o for o in a.ops if o not in OPS]
    if bad: raise SystemExit("unknown --ops: " + ",".join(bad))
    a.types = {}
    for t in a.type or []:
        k, v = t.split("="); a.types[k] = v.split(",")
    if "ty" in a.ops and not a.types: a.ops.remove("ty")
    a.part_type = a.part_type.split(",")
    a.jobs = max(1, min(2, a.jobs))
    a.ranges = None
    if a.objective.startswith("region:"):
        a.ranges = regions.parse_ranges(a.objective[7:].split(","))
    elif a.objective not in ("score", "exact"): raise SystemExit("--objective: score, exact or region:LO-HI,...")
    a.store_sym = [stseq.parse_sym(s) for s in a.store_sym or []] or None
    out = pathlib.Path(a.outdir); out.mkdir(parents=True, exist_ok=True)
    base = open(a.draft).read()
    for f in [a.fn] + a.funcs: Func(base, f)
    (out / "base.c").write_text(base)
    rnd = random.Random(a.seed)
    if a.dry:
        for k in range(a.dry):
            v, ds = variant(base, a.fn, rnd, a)
            if v and ds: (out / ("dry-%03d.c" % k)).write_text(v); print("dry-%03d.c" % k, " | ".join(ds))
        return
    cc = diff.toolchain(a.cpu) + "gcc"
    work = tempfile.mkdtemp(dir=str(out), prefix="build.")
    slots = [os.path.join(work, str(k)) for k in range(a.jobs)]
    for s in slots: os.makedirs(s, exist_ok=True)

    def start(src, slot):
        c, o = os.path.join(slot, "v.c"), os.path.join(slot, "v.o")
        open(c, "w").write(src)
        if os.path.exists(o): os.unlink(o)
        return subprocess.Popen(["nice", "-n", "10", cc, *a.flags.split(), *srcpath.include(a.cpu, a.draft, a.fn), "-w", "-c", c, "-o", o],
                                stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL), o

    p, bo = start(base, slots[0])
    if p.wait(): raise SystemExit("the draft does not compile with " + a.flags)
    b_obj, b_score, b_match = objective(a, bo)
    b_st = stores_bad(a, bo) if a.stores else 0
    print("base %s score %.2f%s%s" % (b_obj, b_score, " stores-diff %d" % b_st if a.stores else "",
                                     " MATCH" if b_match else ""), flush=True)
    log = open(out / "log.tsv", "a"); hits = open(out / "hits.tsv", "a")
    cur, cur_obj, best_obj = base, b_obj, b_obj
    seen = {hashlib.sha1(base.encode()).hexdigest()}
    tend = time.time() + a.seconds; n = errs = nh = 0
    while time.time() < tend:
        batch = []
        tries = 0
        while len(batch) < a.jobs and tries < 200:
            tries += 1
            v, ds = variant(cur, a.fn, rnd, a)
            if not v or not ds: continue
            h = hashlib.sha1(v.encode()).hexdigest()
            if h in seen: continue
            seen.add(h); batch.append((v, ds))
        if not batch: print("no new variants (mutation space exhausted at --maxmut %d)" % a.maxmut); break
        procs = [(start(v, slots[k]), v, ds) for k, (v, ds) in enumerate(batch)]
        for (pr, o), v, ds in procs:
            n += 1
            if pr.wait(): errs += 1; log.write("%d\tERR\t\t%s\n" % (n, " | ".join(ds))); continue
            try: ob, sc, mt = objective(a, o)
            except (SystemExit, Exception) as e: errs += 1; log.write("%d\tERR %s\t\t%s\n" % (n, str(e)[:40], " | ".join(ds))); continue
            if a.stores and stores_bad(a, o) > b_st:
                log.write("%d\t%s\t%.2f\tSTORES\t%s\n" % (n, ob, sc, " | ".join(ds))); continue
            log.write("%d\t%s\t%.2f\t\t%s\n" % (n, ob, sc, " | ".join(ds)))
            if mt:
                (out / "match.c").write_text(v); print("MATCH", out / "match.c", " | ".join(ds), flush=True)
                log.close(); hits.close(); return
            if ob > b_obj:
                nh += 1; f = out / ("hit-%05d.c" % n); f.write_text(v)
                hits.write("%s\t%s\t%.2f\t%s\n" % (f.name, ob, sc, " | ".join(ds))); hits.flush()
            if ob > best_obj:
                best_obj = ob; (out / "best.c").write_text(v)
                print("best %s score %.2f build %d | %s" % (ob, sc, n, " | ".join(ds)), flush=True)
            if a.hill and (ob > cur_obj or (a.sideways and ob == cur_obj)):
                cur, cur_obj = v, ob
        log.flush()
    log.close(); hits.close()
    print("%d built, %d errors, %d hits, best %s (base %s)" % (n, errs, nh, best_obj, b_obj))


if __name__ == "__main__":
    main()
