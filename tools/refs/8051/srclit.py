#!/usr/bin/env python3
"""CODE-address facts from the matched C sources of one 8051 bank.
lits(b) -> {function: {"lit": {value: text}, "dat": {base: name}}} for every function defined in the C source files
of the bank (tools/srcpath.py; read with their names put back to labels),
where lit = values written as (... code *)0xNNNN (a 3-byte form 0xFFNNNN gives NNNN) and dat = DAT_CODE_xxxx
symbols the file uses (every function of a module file shares the file's list)."""
import pathlib, re, sys

ROOT = pathlib.Path(__file__).resolve().parents[3]
if str(ROOT / "tools") not in sys.path: sys.path.insert(0, str(ROOT / "tools"))
import srcpath
DEF = re.compile(r"^[A-Za-z_][\w \*]*?\b((?:thunk_)?FUN_CODE_[0-9a-f]+)\s*\([^;{]*\)\s*(?:large|reentrant|small|using \d|interrupt \d+|\s)*\{?\s*$", re.M)
LIT = re.compile(r"\(([^()]*\bcode\b[^()]*\*)\s*\)\s*(0x[0-9a-fA-F]+)")
DAT = re.compile(r"\bDAT_CODE_([0-9a-f]+)\b")


def strip(t):
    t = re.sub(r"/\*.*?\*/", " ", t, flags=re.S)
    return re.sub(r"//[^\n]*", " ", t)


def lits(b):
    out = {}
    for p in srcpath.files(f"8051_bank{b}", ".c"):
        t = strip(srcpath.read_labels(f"8051_bank{b}", p))
        lit = {}
        for m in LIT.finditer(t):
            v = int(m.group(2), 16)
            if v > 0xFFFF:
                if v >> 16 != 0xFF: continue   # not a CODE generic pointer
                v &= 0xFFFF
            lit[v] = m.group(0)
        dat = {int(m.group(1), 16): "DAT_CODE_" + m.group(1) for m in DAT.finditer(t)}
        fns = set(DEF.findall(t)) | {srcpath.label_of(f"8051_bank{b}", p)}
        for f in fns:
            out.setdefault(f, {"lit": {}, "dat": {}, "file": str(p.relative_to(ROOT))})
            out[f]["lit"].update(lit); out[f]["dat"].update(dat)
    return out


def match(info, v, span=0x2000):
    """evidence text when v is a CODE address the function's source names, else None"""
    if info is None: return None
    if v in info["lit"]: return "literal " + info["lit"][v]
    if v in info["dat"]: return info["dat"][v]
    best = None
    for base, n in info["dat"].items():
        if 0 < v - base < span and (best is None or base > best[0]): best = (base, n)
    if best: return "%s+0x%X" % (best[1], v - best[0])
    return None


if __name__ == "__main__":
    import sys
    d = lits(int(sys.argv[1]))
    print(len(d), "functions;", sum(len(x["lit"]) for x in d.values()), "literal uses;",
          sum(len(x["dat"]) for x in d.values()), "DAT_CODE uses")
