#!/usr/bin/env python3
"""Hill-climb near-misses by small type changes (a tiny decomp-permuter). Fully mechanical.

Starts from work/autoc/<cpu>/<fn>.c, tries changing the function's return type, each
parameter type, each global's type and each extern function's return type, keeps every
change that raises the score, repeats until nothing helps. Improved sources overwrite the
autoc file (so later passes start from them) and scores are updated.

usage: permute.py <cpu> [--min 60] [--max 99.99] [--jobs 8] [--names a,b]
"""
import json, re, sys, pathlib, argparse, subprocess, tempfile, os, hashlib
from multiprocessing import Pool
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import diff

ROOT = pathlib.Path(__file__).resolve().parent.parent
CFG = json.loads((ROOT / "tools" / "config.json").read_text())
GCC = str(ROOT / "toolchains" / "sparc-elf-3.4.4" / "bin" / "sparc-elf-gcc")
TYPES = ["int", "unsigned int", "unsigned char", "char", "signed char", "unsigned short", "short"]
RTYPES = ["void"] + TYPES

def score(cpu, fn, src, tmp):
    """best over the core's flag sets (leon2m: -O2 default, some files -Os)"""
    c = tmp / "p.c"; o = tmp / "p.o"; c.write_text(src); best = -1.0
    for fl in [CFG[cpu]["cflags"]] + CFG[cpu].get("alt_cflags", []):
        r = subprocess.run([GCC, *fl.split(), "-w", "-c", str(c), "-o", str(o)], capture_output=True)
        if r.returncode: continue
        try: best = max(best, diff.compare(cpu, fn, str(o))[5])
        except BaseException: pass
        if best >= 100: break
    return best

def mutations(fn, src):
    """yield variants of src, one small change each"""
    m = re.search(r"^([A-Za-z_][\w ]*?)\s+" + re.escape(fn) + r"\s*\(([^)]*)\)", src, re.M)
    if m:
        for t in RTYPES:
            if t != m.group(1).strip():
                yield f"return {t}", src[:m.start(1)] + t + src[m.end(1):]
        params = m.group(2)
        if params.strip() not in ("", "void"):
            parts = params.split(",")
            for i, p in enumerate(parts):
                pm = re.match(r"\s*(.*?)\s*(\**)\s*(\w+)\s*$", p, re.S)
                if not pm or pm.group(2): continue
                for t in TYPES:
                    if t == pm.group(1): continue
                    np_ = parts[:]; np_[i] = (" " if i else "") + f"{t} {pm.group(3)}"
                    yield f"param {pm.group(3)} {t}", src[:m.start(2)] + ",".join(np_) + src[m.end(2):]
        if params.strip() not in ("", "void"):   # Ghidra invents trailing params for tail calls: try dropping them
            parts = params.split(",")
            for k in range(1, len(parts)):
                kept = parts[:k]; dropped = {re.findall(r"\w+", x)[-1] for x in parts[k:]}
                if not any(re.search(r"\b" + d + r"\b", src[m.end():]) for d in dropped):
                    yield f"drop params from {k + 1}", src[:m.start(2)] + ",".join(kept) + src[m.end(2):]
    body_at = m.end() if m else 0
    if m and m.group(1).strip() == "void":   # Ghidra's void guess for a function that ends "return 0"
        last = src.rstrip().rfind("}")
        if last > m.end():
            t = src[:m.start(1)] + "int" + src[m.end(1):last] + "  return 0;\n" + src[last:]
            yield "void -> int, return 0", re.sub(r"\breturn;", "return 0;", t)
    for ct in sorted(set(re.findall(r"\((undefined\d?|uint|int|byte|char|ushort|short|bool|uchar|ulong|dword|word) \*\)", src[body_at:]))):
        for t in TYPES:   # pointer casts: change every (ct *) at once
            yield f"ptrcast {ct}* {t}", src[:body_at] + src[body_at:].replace(f"({ct} *)", f"({t} *)")
    for vt in sorted(set(re.findall(r"\((undefined\d?|uint|int|byte|char|ushort|short|bool|uchar)\)", src[body_at:]))):
        yield f"drop cast ({vt})", src[:body_at] + src[body_at:].replace(f"({vt})", "")
        for t in TYPES:
            yield f"cast ({vt}) {t}", src[:body_at] + src[body_at:].replace(f"({vt})", f"({t})")
    simple = r"(\(?[\w.]+(?: \* \d+| \* 0x[0-9a-f]+)?\)?|\(\w+\)\w+)"
    for k, am in enumerate(re.finditer(simple + r" \+ " + simple, src[body_at:])):   # a + b -> b + a (address operand order)
        if k >= 16: break
        a0, a1 = body_at + am.start(), body_at + am.end()
        yield f"swap {am.group(0)}", src[:a0] + f"{am.group(2)} + {am.group(1)}" + src[a1:]
    flip = {"<": ">", ">": "<", "<=": ">=", ">=": "<=", "==": "==", "!=": "!="}
    opnd = r"([\w.]+|\([\w. &|*+-]+\))"
    for k, cm in enumerate(re.finditer(opnd + r" (<=|>=|==|!=|<|>) " + opnd, src[body_at:])):   # a < b -> b > a
        if k >= 16: break
        a0, a1 = body_at + cm.start(), body_at + cm.end()
        yield f"flip {cm.group(0)}", src[:a0] + f"{cm.group(3)} {flip[cm.group(2)]} {cm.group(1)}" + src[a1:]
    lines = src.split("\n"); simple = [i for i, l in enumerate(lines) if i > 0 and re.match(r"^\s+[^\s{}].*;\s*$", l)
                                         and not re.match(r"^\s+(return|break|goto|continue)\b", l) and "{" not in l and "}" not in l]
    for k, i in enumerate(i for i in simple if i + 1 in simple):   # swap two neighbouring statements
        if k >= 24: break
        nl = lines[:]; nl[i], nl[i + 1] = nl[i + 1], nl[i]
        if lines[i].lstrip().split(" ")[0] in ("undefined", "undefined1", "undefined2", "undefined4", "uint", "int", "byte", "ushort", "short", "char", "bool"):
            continue   # declarations
        yield f"swap lines {i}", "\n".join(nl)
    for gm in re.finditer(r"^extern (volatile )?([\w ]+?) ((?:_?DAT|PTR|[ubcsip]Ram|usRam)\w*);$", src, re.M):
        for t in TYPES:
            if t != gm.group(2):
                yield f"global {gm.group(3)} {t}", src[:gm.start(2)] + t + src[gm.end(2):]
    for cm in re.finditer(r"^(\s+)(\w+\([^;]*\));\n\s+(\w+) = \3( & 0x[0-9a-f]+);$", src, re.M):   # Ghidra lost x = f(...)
        rep = f"{cm.group(1)}{cm.group(3)} = {cm.group(2)}{cm.group(4)};"
        yield f"result {cm.group(3)}", src[:cm.start()] + rep + src[cm.end():]
        pm = re.search(r"^\s+" + cm.group(3) + r" = " + cm.group(3) + r" & 0x[0-9a-f]+;\n\Z", src[:cm.start()], re.M)
        if pm: yield f"result {cm.group(3)} (merge)", src[:pm.start()] + rep.replace(f"({cm.group(3)}", f"({cm.group(3)}{cm.group(4)}", 1) + src[cm.end():]
    for cm in re.finditer(r"^(\s+)(\w+\(([^;]*)\));\n((?:\s+[^\n]*;\n){0,3}?)\s+(\w+) = \5( & 0x[0-9a-f]+);\n", src, re.M):
        v = cm.group(5)   # Ghidra lost "v = f(..v..)": the call's result is masked a few lines later
        if not re.search(r"\b" + v + r"\b", cm.group(3)) or re.search(r"\b" + v + r"\s*=[^=]", cm.group(4)): continue
        args = re.sub(r"\b" + v + r"\b(?! &)", f"{v} & 0xff", cm.group(3)) if v.startswith("param") else cm.group(3)
        for a in {cm.group(3), args}:
            call = cm.group(2)[:len(cm.group(2)) - len(cm.group(3)) - 1] + a + ")"
            t = src[:cm.start()] + f"{cm.group(1)}{v} = {call}{cm.group(6)};\n" + cm.group(4) + src[cm.end():]
            yield f"result {v} (far)", t
            pm = re.search(r"^\s+" + v + r" = " + v + r" & 0x[0-9a-f]+;\n\Z", src[:cm.start()], re.M)
            if pm: yield f"result {v} (far, drop pre-mask)", t[:pm.start()] + t[pm.end():]
    for cm in re.finditer(r"^(\s+)(\w+) = (\w+);\n\s+(\w+\([^;]*\));\n(\s+\2 = \2 & 0x[0-9a-f]+;)$", src, re.M):   # v = a; f(..); v &= m
        yield f"result {cm.group(2)} (via copy)", src[:cm.start()] + f"{cm.group(1)}{cm.group(2)} = {cm.group(4)};\n{cm.group(5)}" + src[cm.end():]
        hm = re.search(r"^extern \w+ " + re.escape(cm.group(4).split("(")[0]) + r"\(", src, re.M)
    if re.search(r"(?<!unsigned )\bchar \*", src):   # plain char is signed here; byte pointers often were unsigned
        yield "unsigned char pointers", re.sub(r"(?<!unsigned )(?<!signed )\bchar \*", "unsigned char *", src)
    if m:   # Ghidra's "f(..); return;" in a void function can be "return f(..);" (result lost by a void guess)
        for rm in re.finditer(r"^(\s+)(\w+\([^;]*\));\n\s+return(?: [^;]*)?;\n", src, re.M):
            body2 = src[:rm.start()] + f"{rm.group(1)}return {rm.group(2)};\n" + src[rm.end():]
            for t, mask in (("unsigned char", ""), ("int", ""), ("unsigned char", " & 1"), ("int", " & 1")):
                if mask: body2 = src[:rm.start()] + f"{rm.group(1)}return {rm.group(2)}{mask};\n" + src[rm.end():]
                hdr = re.search(r"^([A-Za-z_][\w ]*?)\s+" + re.escape(fn) + r"\s*\(", body2, re.M)
                yield f"return call result{mask} as {t}", body2[:hdr.start(1)] + t + body2[hdr.end(1):]
    for am in re.finditer(r"^(\s+\w+ \w+) ?\[(\d+)\];$", src, re.M):   # local array sizes set the stack frame
        n = int(am.group(2))
        for d in (-16, -8, -4, 4, 8, 16):
            if n + d > 0:
                yield f"array {n}->{n + d}", src[:am.start(2)] + str(n + d) + src[am.end(2):]
    for cm in re.finditer(r"^(\s+)(\w+) = ([\w&*()]+);\n\s+(\w+\([^;]*\));$", src, re.M):   # v = x; f(..);  ->  v = f(..);
        yield f"result {cm.group(2)} (loose)", src[:cm.start()] + f"{cm.group(1)}{cm.group(2)} = {cm.group(4)};" + src[cm.end():]
    cases = list(re.finditer(r"^(\s+)case [^:\n]+:\n(?:(?!\1case |\1default:).*\n)*?\s+break;\n", src, re.M))
    for k in range(len(cases) - 1):   # case order in a switch decides block layout
        a, b = cases[k], cases[k + 1]
        if a.end() == b.start():
            yield f"swap cases {k}", src[:a.start()] + b.group(0) + a.group(0) + src[b.end():]
    regs = [rm for rm in re.finditer(r"^extern (?:volatile )?([\w ]+?) (_?DAT_((?:cf|9f|80|c0)[0-9a-f]{6}));.*$", src, re.M)]
    def as_macro(t, rm):   # peripheral registers: Novatek code reads/writes them through a fixed address
        return t[:rm.start()] + f"#define {rm.group(2)} (*(volatile {rm.group(1)} *)0x{rm.group(3)})" + t[rm.end():]
    for rm in regs:
        yield f"register macro {rm.group(2)}", as_macro(src, rm)
    if len(regs) > 1:
        t = src
        for rm in reversed(regs): t = as_macro(t, rm)
        yield "register macros (all)", t
    for om in re.finditer(r"^(\s+)([^=\n]+?) = ([^|;\n]+?) \| ([^|;\n]+? & 0x[0-9a-f]+);$", src, re.M):   # a | (b & m): b&m via a temporary
        yield f"temp for mask term {om.start()}", src[:om.start()] + f"{om.group(1)}{{ uint t_ = {om.group(4)}; {om.group(2)} = {om.group(3)} | t_; }}" + src[om.end():]
    if re.search(r"(<<|>>) \(\(?(?:\(\w+\))?\w+\)? & 0x1f\)", src):   # Ghidra adds '& 0x1f' to shift counts
        yield "drop shift masks", re.sub(r"(<<|>>) \(\(?(?:\(\w+\))?(\w+)\)? & 0x1f\)", r"\1 \2", src)
    if re.search(r"(<<|>>) \(([^()]*?) & 0x1f\)", src):   # same, around a whole count expression ("n * '\x02' - 2U & 0x1f")
        yield "drop shift masks (expr)", re.sub(r"(<<|>>) \(([^()]*?) & 0x1f\)", r"\1 (\2)", re.sub(r"'\\x0([0-9])'", r"\1", src))
    for k in (2, 3, 4, 5):   # Ghidra's 6-parameter guesses pass leftover registers on: f(a, b, param_3..param_6)
        tail = "".join(f",\\s*param_{i}" for i in range(k + 1, 7))
        hits = re.findall(r"(\w+)\([^;()]*?" + tail + r"\)", src[body_at:])
        if hits:
            t = src[:body_at] + re.sub(r"(\w\([^;()]*?)" + tail + r"\)", r"\1)", src[body_at:])
            for callee in set(hits):   # callers do not set those registers: no full prototype in scope
                t = re.sub(r"^(extern [\w *]+?\b" + re.escape(callee) + r")\([^)]*\);", r"\1();", t, flags=re.M)
            yield f"drop pass-through args from {k + 1}", t
    for vm in re.finditer(r"^extern (volatile )?([\w ]+?) ((?:_?DAT|PTR|ARR|[ubcsip]Ram|usRam)\w*)(\[\])?;$", src, re.M):
        if vm.group(1): yield f"nonvolatile {vm.group(3)}", src[:vm.start(1)] + src[vm.end(1):]
        else: yield f"volatile {vm.group(3)}", src[:vm.start(2)] + "volatile " + src[vm.start(2):]
    if re.search(r"\*\((?!volatile)\w+ \*\)", src[body_at:]):
        yield "volatile all ptrcasts", src[:body_at] + re.sub(r"\*\((?!volatile)(\w+) \*\)", r"*(volatile \1 *)", src[body_at:])
    for em in re.finditer(r"^extern (int|void|unsigned char|unsigned short|char|short) (\w+)\(\);$", src, re.M):
        for t in ("void", "int", "unsigned char", "unsigned short"):
            if t != em.group(1):
                yield f"callee {em.group(2)} {t}", src[:em.start(1)] + t + src[em.end(1):]
    if m:   # Ghidra loses arguments it cannot prove: "f()" where the code passes a parameter on in %o0
        pnames = [re.findall(r"\w+", x)[-1] for x in m.group(2).split(",") if x.strip() not in ("", "void")][:3]
        empties = [em for em in re.finditer(r"(?<![\w.])(\w+)\(\)", src[body_at:]) if em.group(1) not in ("if", "while", "for", "switch", "return", "sizeof")]
        for pn in pnames:
            for callee in sorted({em.group(1) for em in empties}):
                yield f"lost arg {callee}({pn}) all", src[:body_at] + re.sub(r"(?<![\w.])" + re.escape(callee) + r"\(\)", f"{callee}({pn})", src[body_at:])
            for k, em in enumerate(empties[:6]):
                a0 = body_at + em.end() - 1
                yield f"lost arg {em.group(1)}({pn}) #{k}", src[:a0] + pn + src[a0:]
    for lm in re.finditer(r"^(\s+)((?:unsigned |signed )?(?:int|short|char)) (\w+(?:, \w+)*);$", src[body_at:], re.M):
        names = lm.group(3).split(", ")   # hand-written style locals ("unsigned int a, b;"): retype one at a time
        for n in names:
            rest = [x for x in names if x != n]
            for t in ("unsigned char", "char", "unsigned short", "short", "int", "unsigned int"):
                if t == lm.group(2): continue
                decl = (f"{lm.group(1)}{lm.group(2)} {', '.join(rest)};\n" if rest else "") + f"{lm.group(1)}{t} {n};"
                t2 = src[:body_at + lm.start()] + decl + src[body_at + lm.end():]
                yield f"local {n} {t}", t2
                if "char" in t and re.search(r"\b" + n + r" & 0xff\b", t2):   # a byte needs no mask
                    yield f"local {n} {t} (drop & 0xff)", re.sub(r"\b" + n + r" & 0xff\b", n, t2)
    for mask, ct in (("0xffff", "unsigned short"), ("0xff", "unsigned char")):   # "(v & 0xffff)" was "(unsigned short)v" (sll/srl, no sethi mask)
        vs = sorted(set(re.findall(r"\((\w+) & " + mask + r"\)", src[body_at:])))
        for v in vs:
            yield f"cast {v} {ct}", src[:body_at] + re.sub(r"\(" + v + r" & " + mask + r"\)", f"(({ct}){v})", src[body_at:])
    T = {"undefined1": "unsigned char", "byte": "unsigned char", "undefined2": "unsigned short", "ushort": "unsigned short",
         "undefined4": "unsigned int", "uint": "unsigned int", "int": "int", "short": "short", "char": "char"}
    pa = r"\*\((undefined[124]|byte|ushort|uint|int|short|char) \*\)\((param_\d+|\w+) \+ (?:\(uint\))?(\w+)\)"
    la = r"\*\((undefined[124]|byte|ushort|uint|int|short|char) \*\)\((\w+) \+ 0x([0-9a-f]{8})\)"
    if re.search(pa, src[body_at:]) or re.search(la, src[body_at:]):   # Ghidra's byte-offset access -> real array indexing
        b = src[body_at:]; ext = {}
        def lit(mm):
            ext[mm.group(3)] = T[mm.group(1)]; return f"DAT_{mm.group(3)}[{mm.group(2)}]"
        b = re.sub(la, lit, b)
        b = re.sub(pa, lambda mm: f"(({T[mm.group(1)]} *){mm.group(2)})[{mm.group(3)}]" if mm.group(1) in ("undefined1", "byte", "char") else mm.group(0), b)
        hdr = src[:body_at]; at = m.start() if m else 0
        decl = "".join(f"extern {t} DAT_{a}[];\n" for a, t in sorted(ext.items()) if f"DAT_{a}[]" not in hdr)
        yield "array form", hdr[:at] + decl + hdr[at:] + b
    for dm in re.finditer(r"^(\s+)(\w+) = 0;\n\s+do \{\n\s+\2 = \2 \+ 1;\n\s+\} while \(\2 < (\w+)\);$", src, re.M):   # empty count loop = nop delay loop
        yield f"nop delay loop {dm.group(2)}", src[:dm.start()] + f'{dm.group(1)}for ({dm.group(2)} = 0; {dm.group(2)} < {dm.group(3)}; {dm.group(2)}++) __asm__("nop");' + src[dm.end():]
    for ct in sorted(set(re.findall(r"\((unsigned char|unsigned short|signed char|unsigned int)\)", src[body_at:]))):   # stray narrowing casts
        yield f"drop cast ({ct})", src[:body_at] + src[body_at:].replace(f"({ct})", "")
    if re.search(r"\*\(volatile (?:ushort|uint|byte|unsigned short|unsigned char|unsigned int) \*\)\(&", src[body_at:]):   # table reads are not volatile
        yield "nonvolatile table reads", src[:body_at] + re.sub(r"\*\(volatile (\w+(?: \w+)?) \*\)\(&", r"*(\1 *)(&", src[body_at:])
    strides = sorted(set(re.findall(r"\b(\w+) \* (\d+|0x[0-9a-f]+)\]", src[body_at:])) | set(re.findall(r"\[(\w+) \* (\d+|0x[0-9a-f]+)", src[body_at:])))
    for v, n in strides[:6]:   # record stride counted in the wrong unit (bytes vs words): try x/4, x/2, x*2, x*4
        k = int(n, 0)
        for f in (0.25, 0.5, 2, 4):
            if (k * f) == int(k * f) and int(k * f) > 0:
                yield f"stride {v}*{n} -> {int(k * f)}", src[:body_at] + re.sub(r"\b" + re.escape(v) + r" \* " + re.escape(n) + r"\b", f"{v} * {int(k * f)}", src[body_at:])
    for sm in re.finditer(r"^(\s+\w+ = \w+) << ([1-3]);$", src[body_at:], re.M):   # index pre-scaled by Ghidra
        yield f"drop index shift {sm.group(2)}", src[:body_at + sm.start()] + sm.group(1) + ";" + src[body_at + sm.end():]
    for callee in sorted({em.group(1) for em in re.finditer(r"(?<![\w.])(\w+)\(\)", src[body_at:])} - {"if", "while", "for", "switch", "return", "sizeof"})[:6]:
        b = src[body_at:]   # lost constant argument: "f(); ... g(4, ...)" was "f(4); ... g(4, ...)"
        for k in range(3):   # the k-th following call with a constant first argument
            def fill(mm, k=k):
                nxt = re.findall(r"\b(?!" + re.escape(callee) + r"\b)\w+\(\s*(0x[0-9a-f]+|\d+)\s*[,)]", b[mm.end():mm.end() + 400])
                return f"{callee}({nxt[k]})" if len(nxt) > k else mm.group(0)
            t = re.sub(r"(?<![\w.])" + re.escape(callee) + r"\(\)", fill, b)
            if t != b: yield f"lost const arg {callee} #{k}", src[:body_at] + t
    for lm in re.finditer(r"^  (undefined\d?|uint|int|byte|char|ushort|short|bool|uchar) (\w+);$", src, re.M):
        for t in TYPES:
            yield f"local {lm.group(2)} {t}", src[:lm.start(1)] + t + src[lm.end(1):]

def climb(args):
    cpu, fn, seen = args
    p = ROOT / "work" / "autoc" / cpu / f"{fn}.c"
    src = p.read_text()
    if seen == hashlib.sha1(src.encode()).hexdigest(): return fn, None, None, []   # unchanged since its last climb
    with tempfile.TemporaryDirectory(dir=ROOT / "work" / "autoc" / "tmp") as td:
        tmp = pathlib.Path(td)
        start = score(cpu, fn, src, tmp)
        def hill(src, best, steps):
            for _ in range(6):
                improved = False
                for what, v in mutations(fn, src):
                    s = score(cpu, fn, v, tmp)
                    if s > best:
                        best, src, improved = s, v, True; steps = steps + [what]
                        if best >= 100: break
                if not improved or best >= 100: break
            return best, src, steps
        best, out, steps = hill(src, start, [])
        if best < 100:   # structural fixes (lost call results) can dip first and pay off later: climb from them too
            for what, v in [m for m in mutations(fn, src) if m[0].startswith(("result", "return call"))][:4]:
                b2, o2, s2 = hill(v, score(cpu, fn, v, tmp), [what])
                if b2 > best: best, out, steps = b2, o2, s2
    if best > start: p.write_text(out)
    return fn, start, best, steps

def main():
    ap = argparse.ArgumentParser(); ap.add_argument("cpu"); ap.add_argument("--min", type=float, default=60)
    ap.add_argument("--max", type=float, default=99.99); ap.add_argument("--jobs", type=int, default=8); ap.add_argument("--names")
    a = ap.parse_args()
    scp = ROOT / "work" / "autoc" / f"{a.cpu}.scores.json"; scores = json.loads(scp.read_text())
    sym = json.loads((ROOT / "symbols" / f"{a.cpu}.json").read_text())["functions"]
    done = {v["name"] for v in sym.values() if v.get("status") == "matched"}
    want = set(a.names.split(",")) if a.names else None
    todo = [(a.cpu, fn, v.get("permuted") if v["score"] < 100 else None) for fn, v in scores.items()
            if a.min <= v["score"] <= a.max and fn not in done and (not want or fn in want)]
    with Pool(a.jobs) as pool:
        res = pool.map(climb, todo, chunksize=1)
    up = 0; matched = 0; skipped = 0
    for fn, s0, s1, steps in res:
        if s0 is None: skipped += 1; continue
        scores[fn]["permuted"] = hashlib.sha1((ROOT / "work" / "autoc" / a.cpu / f"{fn}.c").read_text().encode()).hexdigest()
        if s1 > s0: up += 1
        if s1 != scores[fn]["score"]: scores[fn]["score"] = s1   # also when only the judge changed (start already higher)
        if s1 >= 100: matched += 1
    scp.write_text(json.dumps(scores, indent=1, sort_keys=True))
    print(f"{a.cpu}: {len(todo) - skipped} tried ({skipped} unchanged, skipped), {up} improved, {matched} now match")
    for fn, s0, s1, steps in sorted([r for r in res if r[1] is not None], key=lambda r: r[2] - r[1], reverse=True)[:8]:
        if s1 > s0: print(f"  {fn}: {s0:.1f} -> {s1:.1f}  {'; '.join(steps)}")

if __name__ == "__main__":
    main()
