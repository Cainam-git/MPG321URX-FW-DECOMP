#!/usr/bin/env python3
"""Inlined helpers: a MATCHED function's instruction body (save/ret/restore stripped, 6-60 instructions) that appears
verbatim inside an unmatched function's shape is an inlined copy of that helper: the original source defined the
helper `static inline` (gcc 3.4.4 -O2 inlines only inline-marked functions) and called it there. Pasting the
body instead never gives the register allocation. Output: work/<cpu>-inlined.json = {fn: [[first, last, helper], ...]}
(instruction indexes into asm/<cpu>/<fn>.s), a hint for hand work.
usage: inlined.py <cpu>
"""
import json, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
SKIP = ("save", "ret", "restore", "retl", "jmp")


def main():
    cpu = sys.argv[1]
    sym = json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())["functions"]; byname = {v["name"]: v for v in sym.values()}
    shapes = json.loads((ROOT / "work" / f"{cpu}-shapes.json").read_text()); tok = {f: s.split("|") for f, s in shapes.items()}
    helpers = []
    for m in shapes:
        if byname.get(m, {}).get("status") != "matched" or not (ROOT / "src" / cpu / f"{m}.c").exists(): continue
        core = [x for x in tok[m] if not x.startswith(SKIP)]
        if 6 <= len(core) <= 60: helpers.append((m, core))
    out = {}
    for f, t in tok.items():
        if byname.get(f, {}).get("status") == "matched": continue
        hits = []
        for m, core in helpers:
            if len(t) <= len(core) + 8: continue
            n = len(core)
            for i in range(len(t) - n + 1):
                if t[i] == core[0] and t[i:i + n] == core: hits.append([i, i + n - 1, m])
        if hits: out[f] = sorted(hits)
    (ROOT / "work" / f"{cpu}-inlined.json").write_text(json.dumps(out, indent=0))
    print(f"{cpu}: {sum(len(v) for v in out.values())} inlined helper copies in {len(out)} unmatched functions")


if __name__ == "__main__": main()
