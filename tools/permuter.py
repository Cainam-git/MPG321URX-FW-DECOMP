#!/usr/bin/env python3
"""Structural permuter for near-misses (fully mechanical): compiles thousands of rewrites of a close draft and keeps what
the byte judge likes. Extends tools/permute.py (types, line swaps, lost results) with the rewrites that decide
register allocation and instruction order: pointer variables vs inline expressions, table pointer before the
index multiply, constant vs symbol addressing, loop forms and bound types, hoisting into / out of if-arms,
temporaries for call arguments, masks vs casts. Search = first-improvement hill climb on (shape score,
register-blind score) with random multi-step restarts when stuck, under a time budget.

A draft that reaches byte-exact is filed on master (src/<cpu>/<fn>.c + symbols, by="permuter"); improved
drafts overwrite work/autoc/<cpu>/<fn>.c so later passes start from them.

usage: permuter.py <cpu> [--names a,b] [--min 80] [--max 99.99] [--budget 180] [--restarts 12] [--jobs 4]
       permuter.py <cpu> --names FN --src path.c [--write]     (ad-hoc run from any draft)"""
import argparse, difflib, hashlib, json, pathlib, random, re, subprocess, sys, tempfile, time
from multiprocessing import Pool
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import diff, permute
ROOT = pathlib.Path(__file__).resolve().parent.parent
CFG = permute.CFG; GCC = permute.GCC
MASK = re.compile(r"%[gloi][0-7]")
import os
PAR = int(os.environ.get("PERMUTER_PAR", "0") or 0) or max(4, (os.cpu_count() or 4) * 2)   # compilers per search; PERMUTER_PAR caps it (32 x 4 parallel searches can starve the machine)
ITYPES = {"unsigned char": "u8", "unsigned short": "u16", "unsigned int": "u32", "int": "i32", "char": "i8", "short": "i16"}


def evaluate(cpu, fn, src, tmp):
    """(shape, blind, match, flags): best over the core's flag sets"""
    import os
    fd, cn_ = tempfile.mkstemp(suffix=".c", dir=tmp); os.close(fd); c = pathlib.Path(cn_); o = c.with_suffix(".o"); c.write_text(src); best = (-1.0, -1.0, False, "")
    for fl in [CFG[cpu]["cflags"]] + CFG[cpu].get("alt_cflags", []):
        r = subprocess.run([GCC, *fl.split(), "-w", "-c", str(c), "-o", str(o)], capture_output=True)
        if r.returncode: continue
        try: tn, cn, sm, same, total, shape, match = diff.compare(cpu, fn, str(o))
        except BaseException: continue
        tm, cm = [MASK.sub("%R", x) for x in tn], [MASK.sub("%R", x) for x in cn]
        sm2 = difflib.SequenceMatcher(a=tm, b=cm, autojunk=False)
        blind = 100.0 * sum(b.size for b in sm2.get_matching_blocks()) / max(len(tm), len(cm), 1)
        cand = (shape, blind, match, fl)
        if cand[:2] > best[:2] or (match and not best[2]): best = cand
        if match: break
    c.unlink(missing_ok=True); o.unlink(missing_ok=True)
    return best


# ---------- structural rewrites ----------
def header_split(fn, src):
    m = re.search(r"^[A-Za-z_][\w ]*?\s*\**\s*" + re.escape(fn) + r"\s*\([^)]*\)\s*\{", src, re.M)
    return (m.end(), src[:m.end()], src[m.end():]) if m else (0, "", src)


def extern_types(src):
    """symbol -> element type from 'extern T NAME[];' / 'extern T NAME;' / struct arrays"""
    t = {}
    for m in re.finditer(r"^extern\s+((?:(?:const|volatile|unsigned|signed|struct\s+\w+)\s+)*\w+)\s*(\**)\s*(\w+)\s*(\[[^\]]*\])?\s*;", src, re.M):
        t[m.group(3)] = (m.group(1).strip() + (" *" if m.group(2) else ""), bool(m.group(4)))
    return t


def declare(body, decl):
    """add a declaration line right after the opening brace of the function body"""
    i = body.find("\n") + 1
    return body[:i] + decl + body[i:]


def smutations(fn, src):
    at, hdr, body = header_split(fn, src)
    if not hdr: return
    et = extern_types(src)
    body_lines = body.split("\n")
    # S1: repeated SYM[EXPR (+ K)] family -> pointer variable (and S2: the inverse)
    fam = {}
    for m in re.finditer(r"\b(DAT_[0-9a-fA-F]{8}|ARR_[0-9a-fA-F]{8}|\w+)\[([^\[\]]+?)\]", body):
        sym, idx = m.group(1), m.group(2)
        if sym not in et or not et[sym][1] or "(" in idx: continue
        km = re.match(r"(.+?) \+ (0x[0-9a-fA-F]+|\d+)$", idx)
        base, k = (km.group(1), km.group(2)) if km else (idx, "0")
        fam.setdefault((sym, base), []).append((m.start(), m.end(), k))
    n = 0
    for (sym, base), uses in fam.items():
        if len(uses) < 2 or n >= 6: continue
        n += 1
        new = body
        for s, e, k in reversed(uses): new = new[:s] + f"p{n}_[{k}]" + new[e:]
        first = new.rfind("\n", 0, uses[0][0]) + 1   # assign right before the first use (its operands exist there)
        ind = re.match(r"[ \t]*", new[first:]).group(0)
        for label, init in ((f"ptrvar {sym}+{base}", f"{sym} + {base}"), (f"ptrvar const {sym}+{base}", f"({et[sym][0]} *)({base} + 0x{sym[-8:]})")):
            if "const" in label and not re.match(r"(DAT|ARR)_[0-9a-fA-F]{8}$", sym): continue
            yield label, hdr + declare(new[:first] + f"{ind}p{n}_ = {init};\n" + new[first:], f"    {et[sym][0]} *p{n}_;\n")
    for dm in re.finditer(r"^(\s+)((?:unsigned |signed )?(?:char|short|int|long) \*)(\w+) = (\w+) \+ ([^;]+);\n", body, re.M):   # inline a pointer var
        p, sym, base = dm.group(3), dm.group(4), dm.group(5)
        if sym not in et: continue
        new = body[:dm.start()] + body[dm.end():]
        new2 = re.sub(r"\b" + p + r"\[([^\]]+)\]", lambda mm: f"{sym}[{base} + {mm.group(1)}]" if mm.group(1) != "0" else f"{sym}[{base}]", new)
        if not re.search(r"\b" + p + r"\b", new2): yield f"inline ptr {p}", hdr + new2
    for dm in re.finditer(r"^(\s+)((?:unsigned |signed )?(?:char|short|int|long) \*)(\w+) = \(\2\)\((\w+) \+ 0x([0-9a-fA-F]{8})\);\n", body, re.M):   # const ptr var -> symbol forms
        p, base, addr = dm.group(3), dm.group(4), dm.group(5).lower()
        new = body[:dm.start()] + f"{dm.group(1)}{dm.group(2)}{p} = DAT_{addr} + {base};\n" + body[dm.end():]
        decl = "" if f"DAT_{addr}" in hdr else f"extern {dm.group(2).replace(' *', '')} DAT_{addr}[];\n"
        yield f"symbol ptr {p}", decl + hdr + new
    # S3: table pointer variable before the index multiply: &SYM[idx] / SYM + idx (struct arrays)
    for k, m in enumerate(re.finditer(r"(?:&(\w+)\[(\w+)\]|\b(\w+) \+ (\w+)\b)", body)):
        sym, idx = (m.group(1), m.group(2)) if m.group(1) else (m.group(3), m.group(4))
        if sym not in et or not et[sym][1] or not et[sym][0].startswith("struct") or k >= 8: continue
        if re.search(r"\btbl_\b", body): break
        new = body[:m.start()] + f"tbl_ + {idx}" + body[m.end():]
        yield f"tblvar {sym}", hdr + declare(new, f"    {et[sym][0]} *tbl_ = {sym};\n")
    # S4: constant <-> symbol addressing on casts
    for m in list(re.finditer(r"\(\*\((\w+(?: \w+)?) \*\)\((\w+) \+ 0x([0-9a-fA-F]{8})\)\)|\*\((\w+(?: \w+)?) \*\)\((\w+) \+ 0x([0-9a-fA-F]{8})\)", body))[:8]:
        t, base, addr = (m.group(1), m.group(2), m.group(3)) if m.group(1) else (m.group(4), m.group(5), m.group(6))
        addr = addr.lower(); decl = "" if f"DAT_{addr}" in hdr else f"extern {t} DAT_{addr}[];\n"
        yield f"symbol access {addr}", decl + hdr + body[:m.start()] + f"DAT_{addr}[{base}]" + body[m.end():]
    for m in list(re.finditer(r"\b(DAT_([0-9a-fA-F]{8}))\[([^\[\]]+)\]", body))[:8]:
        if m.group(1) in et and et[m.group(1)][1] and not et[m.group(1)][0].startswith("struct"):
            yield f"const access {m.group(2)}", hdr + body[:m.start()] + f"(*({et[m.group(1)][0]} *)({m.group(3)} + 0x{m.group(2).lower()}))" + body[m.end():]
    # S5: loop forms and bound types
    for m in re.finditer(r"^(\s+)for \((\w+) = 0; \2 < ([^;]+); \2\+\+\)\n[ \t]+([^ \t\n][^\n]*;)\n", body, re.M):
        ind, i, n, stmt = m.groups()
        yield f"for->dowhile {i}", hdr + body[:m.start()] + f"{ind}{i} = 0;\n{ind}if ({n} != 0) {{\n{ind}    do {{\n{ind}        {stmt}\n{ind}        {i}++;\n{ind}    }} while ({i} < {n});\n{ind}}}\n" + body[m.end():]
    for m in re.finditer(r"^([ \t]+)(\w+) = 0;\n[ \t]+if \(([^)]+?) != 0\) \{\n[ \t]+do \{\n((?:[ \t]+[^ \t\n][^\n]*\n)+?)[ \t]+\2\+\+;\n\s+\} while \(\2 < ([^)]+)\);\n[ \t]+\}\n", body, re.M):
        ind, i, n, stmts, n2 = m.groups()
        inner = "\n".join(ind + "    " + s.strip() for s in stmts.strip("\n").split("\n"))
        if stmts.count(";") == 1:
            yield f"dowhile->for {i}", hdr + body[:m.start()] + f"{ind}for ({i} = 0; {i} < {n2}; {i}++)\n{inner}\n" + body[m.end():]
        for cast in ("(unsigned char)", "(unsigned int)", "(int)"):
            if cast not in n2:
                yield f"bound cast {cast}{n2}", hdr + body[:m.start()] + m.group(0).replace(f"while ({i} < {n2})", f"while ({i} < {cast}{n2})") + body[m.end():]
    for m in re.finditer(r"while \((\w+) < \((unsigned char|unsigned int|int)\)(\w+)\)", body):   # drop a bound cast
        yield f"drop bound cast {m.group(3)}", hdr + body[:m.start()] + f"while ({m.group(1)} < {m.group(3)})" + body[m.end():]
    # S6: sink a statement before an if into both arms / hoist identical first statements of both arms (line-based)
    for i, line in enumerate(body_lines):
        im = re.match(r"^(\s+)if \((.*)\) \{$", line)
        if not im: continue
        ind = im.group(1); j = k = None
        for q in range(i + 1, len(body_lines)):
            if body_lines[q] == ind + "} else {" and j is None: j = q
            elif body_lines[q] == ind + "}" and j is not None: k = q; break
            elif body_lines[q] == ind + "}" and j is None: break
        if j is None or k is None: continue
        a, b = body_lines[i + 1:j], body_lines[j + 1:k]
        if i > 0:
            sm = re.match(r"^" + ind + r"(\w+) = ([^;]+);$", body_lines[i - 1])
            if sm and not re.search(r"\b" + sm.group(1) + r"\b", im.group(2)) and re.search(r"\b" + sm.group(1) + r"\b", "\n".join(a + b)):
                nl = body_lines[:i - 1] + [line, ind + "    " + body_lines[i - 1].strip()] + a + [ind + "} else {", ind + "    " + body_lines[i - 1].strip()] + b + body_lines[k:]
                yield f"sink {sm.group(1)} into arms", hdr + "\n".join(nl)
        if a and b and a[0] == b[0] and a[0].strip().endswith(";") and "{" not in a[0]:
            nl = body_lines[:i] + [ind + a[0].strip()] + [line] + a[1:] + [ind + "} else {"] + b[1:] + body_lines[k:]
            yield f"hoist {a[0].strip()[:24]}", hdr + "\n".join(nl)
    # S7: temporaries for call arguments / inline single-use temps
    for k, m in enumerate(re.finditer(r"^(\s+)(\w+)\(([^;\n]*)\);\n", body, re.M)):
        if k >= 12 or m.group(2) in ("if", "while", "for", "switch", "return"): continue
        args = [a.strip() for a in m.group(3).split(",")] if m.group(3).strip() else []
        for j, a in enumerate(args):
            if re.search(r"[+\-*&|>]", a) and not a.startswith('"'):
                na = args[:]; na[j] = f"t{k}{j}_"
                yield f"temp arg {m.group(2)}#{j}", hdr + body[:m.start()] + f"{m.group(1)}t{k}{j}_ = {a};\n{m.group(1)}{m.group(2)}({', '.join(na)});\n" + body[m.end():] if False else \
                      hdr + declare(body[:m.start()] + f"{m.group(1)}t{k}{j}_ = {a};\n{m.group(1)}{m.group(2)}({', '.join(na)});\n" + body[m.end():], f"    unsigned int t{k}{j}_;\n")
    for m in re.finditer(r"^(\s+)(\w+) = ([^;\n]+);\n", body, re.M):
        v = m.group(2)
        rest = body[m.end():]
        if len(re.findall(r"\b" + v + r"\b", rest)) == 1 and not re.search(r"\b" + v + r"\s*=[^=]", rest) and "(" not in m.group(3):
            yield f"inline temp {v}", hdr + body[:m.start()] + body[m.end():].replace(v, f"({m.group(3)})", 1) if False else \
                  hdr + body[:m.start()] + re.sub(r"\b" + v + r"\b", f"({m.group(3)})", rest, count=1)
    # S7b: plateau breakers (decomp-permuter style): self-assignment, "+ 0", split a = b op c
    locals_ = sorted(set(re.findall(r"^\s+(?:unsigned |signed )?(?:char|short|int|long)\s*\*?\s*(\w+)(?: =[^;]*)?;", body, re.M)))[:8]
    for v in locals_:
        for k, um in enumerate(list(re.finditer(r"^(\s+)[^\n]*\b" + v + r"\b[^\n]*;$", body, re.M))[:3]):
            yield f"selfassign {v}#{k}", hdr + body[:um.end()] + f"\n{um.group(1)}{v} = {v};" + body[um.end():]
    for k, m in enumerate(list(re.finditer(r"= (\w+) \* (0x[0-9a-fA-F]+|\d+);", body))[:4]):
        yield f"plus0 {m.group(1)}#{k}", hdr + body[:m.end() - 1] + " + 0;" + body[m.end():]
    for k, m in enumerate(list(re.finditer(r"^(\s+)(\w+) = ([^;\n()]+?) ([+|&]) ([^;\n()]+);$", body, re.M))[:6]):
        yield f"split {m.group(2)}#{k}", hdr + body[:m.start()] + f"{m.group(1)}{m.group(2)} = {m.group(3)};\n{m.group(1)}{m.group(2)} = {m.group(2)} {m.group(4)} {m.group(5)};" + body[m.end():]
    # S7c: declaration order (changes the compiler's pseudo numbering, hence register choice on ties)
    decls = [k for k, l in enumerate(body_lines) if re.match(r"^    (?:unsigned |signed |struct \w+ )?(?:char|short|int|long|\w+) \*?\w+(?:, \w+)*(?: = [^;]+)?;$", l) and not l.strip().startswith("return")]
    decls = [k for k in decls if k < 40]
    for a in range(len(decls) - 1):
        k1, k2 = decls[a], decls[a + 1]
        if k2 != k1 + 1 or "=" in body_lines[k1] or "=" in body_lines[k2]: continue
        nl = body_lines[:]; nl[k1], nl[k2] = nl[k2], nl[k1]
        yield f"declswap {a}", hdr + "\n".join(nl)
    if len(decls) > 2 and not any("=" in body_lines[k] for k in decls):
        nl = [l for k, l in enumerate(body_lines) if k not in decls]
        yield "decls reversed", hdr + "\n".join(nl[:1] + [body_lines[k] for k in reversed(decls)] + nl[1:])
    for k in decls[:6]:   # split "T a, b;" into two lines / move one declaration last
        m = re.match(r"^    (.+?) (\w+), (\w+);$", body_lines[k])
        if m:
            nl = body_lines[:]; nl[k:k + 1] = [f"    {m.group(1)} {m.group(2)};", f"    {m.group(1)} {m.group(3)};"]
            yield f"declsplit {m.group(2)}", hdr + "\n".join(nl)
    # S8: masks vs casts per occurrence
    for k, m in enumerate(re.finditer(r"\((\w+) & 0xff\)", body)):
        if k >= 8: break
        yield f"mask->cast {m.group(1)}#{k}", hdr + body[:m.start()] + f"(unsigned char){m.group(1)}" + body[m.end():]
    for k, m in enumerate(re.finditer(r"\(unsigned char\)(\w+)\b", body)):
        if k >= 8: break
        yield f"cast->mask {m.group(1)}#{k}", hdr + body[:m.start()] + f"({m.group(1)} & 0xff)" + body[m.end():]
    # S9: re-mask a parameter at a later use (fresh value, breaks CSE) / copy of a variable before a block
    pm = re.search(r"\(([^)]*)\)\s*\{", hdr)
    params = [re.findall(r"\w+", p)[-1] for p in (pm.group(1).split(",") if pm else []) if p.strip() not in ("", "void")]
    for p in params[:2]:
        uses = [u for u in re.finditer(r"\b" + p + r"\b", body)]
        for k, u in enumerate(uses[1:7]):
            yield f"remask {p}#{k}", hdr + body[:u.start()] + f"({p} & 0xff)" + body[u.end():]
    for m in re.finditer(r"^(\s+)if \(([^\n]*)\) \{\n", body, re.M):   # a block-local copy of a byte variable used inside
        for v in sorted(set(re.findall(r"\b(\w+)\b", m.group(2))))[:3]:
            if v in ("if",) or not re.search(r"^\s+(?:unsigned char|unsigned int|int) [^;]*\b" + v + r"\b", body, re.M): continue
            blk = body[m.end():]; close = blk.find("\n" + m.group(1) + "}")
            if close < 0: continue
            inner = blk[:close]
            if not re.search(r"\b" + v + r"\b", inner): continue
            new_inner = re.sub(r"\b" + v + r"\b", v + "c_", inner)
            yield f"blockcopy {v}", hdr + body[:m.end()] + f"{m.group(1)}    unsigned int {v}c_ = {v};\n" + new_inner + blk[close:]
    # S10: several scalar globals close together = fields of one struct whose base the firmware keeps in an %l register
    # ('sethi/or %lo(BASE), %lN' once, then '[ %lN + 4 ]', '[ %lN + 9 ]' ...). Rewrite them as offsets from one byte pointer
    # declared once; gcc then holds the base across the calls. A common pattern in the leon2m near-misses.
    scal = {}
    for m in re.finditer(r"^(?:extern\s+)?((?:(?:const|volatile|unsigned|signed)\s+)*(?:char|short|int|long))\s+DAT_([0-9a-fA-F]{8})\s*;", src, re.M):
        if len(re.findall(r"\bDAT_" + m.group(2) + r"\b", body)) >= 1: scal[int(m.group(2), 16)] = (m.group(1), m.group(2))
    if len(scal) >= 2:
        addrs = sorted(scal); lo = addrs[0]
        if addrs[-1] - lo < 0x1000:
            for base in dict.fromkeys((lo, lo & ~0xF, lo & ~0xFF)):
                if addrs[-1] - base >= 0x1000: continue
                new = body
                for a, (t, hx) in scal.items():
                    new = re.sub(r"\bDAT_" + hx + r"\b", f"(*(volatile {t.replace('volatile ', '')} *)(pb_ + {a - base}))", new)
                # the base must be a plain number cast to a pointer: with a named symbol gcc 3.4.4 folds sym+off back into
                # sethi %hi(sym+off) per use; with (volatile unsigned char *)0xA802E3D0 it materialises the constant once (tested)
                yield f"structbase {base:08x}", hdr + declare(new, f"    volatile unsigned char *pb_ = (volatile unsigned char *)0x{base:08X};\n")
                first = new.find("pb_"); first = new.rfind("\n", 0, first) + 1; ind = re.match(r"[ \t]*", new[first:]).group(0)
                yield f"structbase late {base:08x}", hdr + declare(new[:first] + f"{ind}pb_ = (volatile unsigned char *)0x{base:08X};\n" + new[first:], "    volatile unsigned char *pb_;\n")


def all_mutations(fn, src):
    for m in permute.mutations(fn, src):
        yield m
    for m in smutations(fn, src):
        if m is not None and m[1] is not None: yield m


# ---------- search ----------
def search(cpu, fn, src, tmp, budget, restarts, log):
    t0 = time.time(); cache = {}
    def ev(s):
        h = hashlib.sha1(s.encode()).hexdigest()
        if h not in cache: cache[h] = evaluate(cpu, fn, s, tmp)
        return cache[h]
    def key(r): return (r[0], r[1])
    start = ev(src); best, bsrc, steps = start, src, []
    from concurrent.futures import ThreadPoolExecutor
    pool = ThreadPoolExecutor(max_workers=PAR)
    def ev_many(cands):
        todo = [(w, v) for w, v in cands if hashlib.sha1(v.encode()).hexdigest() not in cache]
        for (w, v), r in zip(todo, pool.map(lambda x: evaluate(cpu, fn, x[1], tmp), todo)):
            cache[hashlib.sha1(v.encode()).hexdigest()] = r
        return [(w, v, ev(v)) for w, v in cands]
    def climb(cur, cur_r, steps):
        while time.time() - t0 < budget:
            improved = False
            muts = list(all_mutations(fn, cur)); random.shuffle(muts)
            for b in range(0, len(muts), PAR):
                if time.time() - t0 > budget: break
                res = ev_many(muts[b:b + PAR])
                res = [x for x in res if key(x[2]) > key(cur_r)]
                if res:
                    what, v, r = max(res, key=lambda x: key(x[2]))
                    cur, cur_r, improved = v, r, True; steps = steps + [what]
                    if r[2]: return cur, cur_r, steps
                    break   # best of the batch: re-generate mutations from the new source
            if not improved: break
        return cur, cur_r, steps
    cur, cur_r, steps = climb(src, start, [])
    if key(cur_r) > key(best): best, bsrc = cur_r, cur
    rr = 0
    while not best[2] and time.time() - t0 < budget and (rr < restarts or True):   # random walks from the best until the budget is used
        rr += 1
        v, vs = bsrc, []
        for _ in range(random.randint(2, 6)):   # sideways/downhill steps: decomp-permuter style plateau exploration
            muts = list(all_mutations(fn, v))
            if not muts: break
            cands = random.sample(muts, min(PAR, len(muts)))
            scored = [x for x in ev_many(cands) if x[2][0] >= 0 and x[2][0] >= best[0] - 8]
            if not scored: break
            what, cand, r = random.choice(scored)
            v, vs = cand, vs + [what]
        c2, r2, s2 = climb(v, ev(v), vs)
        if key(r2) > key(best): best, bsrc, steps = r2, c2, steps + ["[walk]"] + s2
    log(f"{fn}: {start[0]:.1f}/{start[1]:.1f} -> {best[0]:.1f}/{best[1]:.1f}{(' already exact at start' if start[2] else ' MATCH') if best[2] else ''} ({len(cache)} compiles, {time.time() - t0:.0f}s)"
        + (f"  <- {'; '.join(steps)}" if steps else ""))
    return start, best, bsrc, steps


def file_match(cpu, fn, c, flags, steps):
    sym_all = json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())
    key = None
    for k, v in sym_all["functions"].items():
        if v.get("name") == fn: key = k[4:]
    if key is None:
        import exact; key = f"{exact.funcs(cpu)[fn][0]:08x}"
    header = (f"/* {cpu} {fn} @ 0x{key}  MATCH ({flags}, gcc 3.4.4, permuter)\n * reached byte-exact by tools/permuter.py: "
              + "; ".join(steps)[:600] + "\n */\n")
    out = ROOT / "src" / cpu / f"{fn}.c"; out.write_text(header + c)
    sym_all["functions"][f"ram:{key}"] = {"name": fn, "status": "matched", "by": "permuter", "comment": "permuter: " + "; ".join(steps)[:300]}
    if flags != CFG[cpu]["cflags"]: sym_all["functions"][f"ram:{key}"]["cflags"] = flags
    (ROOT / "symbols" / f"{cpu}.json").write_text(json.dumps(sym_all, indent=2, sort_keys=True))
    size = diff.target(cpu, fn); size = (size[-1][0] + 4 - size[0][0]) if size else 0
    # the caller (main) already holds work/lock-<cpu>; a second flock here would wait on itself forever
    subprocess.run(["git", "add", str(out.relative_to(ROOT)), f"symbols/{cpu}.json"], cwd=ROOT)
    subprocess.run(["git", "commit", "-q", "-m", f"{cpu}: match {fn} (permuter, {size} bytes)"], cwd=ROOT)


def run_one(args):
    cpu, fn, src_path, budget, restarts, write = args
    src = pathlib.Path(src_path).read_text()
    (ROOT / "work" / "autoc" / "tmp").mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=ROOT / "work" / "autoc" / "tmp") as td:
        lines = []
        start, best, bsrc, steps = search(cpu, fn, src, pathlib.Path(td), budget, restarts, lines.append)
    with open(ROOT / "work" / "permuter.log", "a") as lg:   # progress visible while a sweep runs
        for l in lines: lg.write(time.strftime("%F %T ") + cpu + " " + l + "\n")
    return cpu, fn, start, best, bsrc, steps, lines, write


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("cpu"); ap.add_argument("--names", default=""); ap.add_argument("--src", default="")
    ap.add_argument("--min", type=float, default=80); ap.add_argument("--max", type=float, default=99.99)
    ap.add_argument("--budget", type=float, default=180); ap.add_argument("--restarts", type=int, default=12)
    ap.add_argument("--jobs", type=int, default=4); ap.add_argument("--limit", type=int, default=0, help="at most N drafts per run, closest first (results are filed only at the end of a run)"); ap.add_argument("--write", action="store_true", help="with --src: also save/file results")
    a = ap.parse_args(); want = set(a.names.split(",")) if a.names else None
    scp = ROOT / "work" / "autoc" / f"{a.cpu}.scores.json"; scores = json.loads(scp.read_text())
    sym = json.loads((ROOT / "symbols" / f"{a.cpu}.json").read_text())["functions"]
    done = {v["name"] for v in sym.values() if v.get("status") == "matched"}
    if a.src:
        todo = [(a.cpu, a.names, a.src, a.budget, a.restarts, a.write)]
    else:
        todo = []
        for fn, v in scores.items():
            p = ROOT / "work" / "autoc" / a.cpu / f"{fn}.c"
            if not (a.min <= v.get("score", -1) <= a.max and fn not in done and (not want or fn in want) and p.exists()): continue
            if not want and v.get("permuter") == hashlib.sha1(p.read_bytes()).hexdigest() and v.get("permuter_budget", 0) >= a.budget: continue   # already permuted this exact draft with at least this budget
            todo.append((a.cpu, fn, str(p), a.budget, a.restarts, True))
        if a.limit: todo = sorted(todo, key=lambda t: -scores[t[1]].get("score", -1))[:a.limit]
    with Pool(max(1, min(a.jobs, len(todo) or 1))) as pool:
        res = list(pool.imap_unordered(run_one, todo, chunksize=1))
    up = matched = 0
    import fcntl
    lockf = open(ROOT / "work" / f"lock-{a.cpu}", "w"); fcntl.flock(lockf, fcntl.LOCK_EX)   # the searches ran unlocked; only the writes/commits take the core lock
    for cpu, fn, start, best, bsrc, steps, lines, write in res:
        for l in lines: print(l)
        if not write: continue
        scores.setdefault(fn, {})["permuter"] = hashlib.sha1((bsrc if best[0] > start[0] else pathlib.Path(ROOT / "work" / "autoc" / cpu / f"{fn}.c").read_text()).encode()).hexdigest()
        scores[fn]["permuter_budget"] = a.budget
        if best[2]:
            file_match(cpu, fn, bsrc, best[3], steps); matched += 1
            scores.setdefault(fn, {})["score"] = 100.0
        elif best[0] > start[0] or (best[0] == start[0] and best[1] > start[1]):
            (ROOT / "work" / "autoc" / cpu / f"{fn}.c").write_text(bsrc); scores.setdefault(fn, {})["score"] = best[0]; up += 1
    if any(r[7] for r in res): scp.write_text(json.dumps(scores, indent=1))
    fcntl.flock(lockf, fcntl.LOCK_UN); lockf.close()
    print(f"{len(res)} tried, {up} improved, {matched} now match")


if __name__ == "__main__": main()
