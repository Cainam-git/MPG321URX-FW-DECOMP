#!/usr/bin/env python3
"""Compact diff of one work/autoc function: only differing hunks, best flag set.
usage: show.py <cpu> <fn> [file.c] [context]"""
import sys, subprocess, pathlib
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff, autoc
cpu, fn = sys.argv[1], sys.argv[2]
src = sys.argv[3] if len(sys.argv) > 3 and sys.argv[3] != "-" else str(ROOT / "work/autoc" / cpu / f"{fn}.c")
ctx = int(sys.argv[4]) if len(sys.argv) > 4 else 2
best = None
for fl in autoc.flag_sets(cpu):
    o = ROOT / "work/autoc/tmp/show.o"
    r = subprocess.run([str(ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc"), *fl.split(), "-w", "-c", src, "-o", str(o)], capture_output=True, text=True)
    if r.returncode: print(r.stderr[-800:]); continue
    res = diff.compare(cpu, fn, str(o))
    if best is None or res[5] > best[0][5]: best = (res, fl)
res, fl = best
L = diff.render(fn, cpu, *res).splitlines()
idx = [i for i, l in enumerate(L) if l.startswith("*")]
shown = set()
for i in idx:
    for j in range(max(1, i - ctx), min(len(L) - 2, i + ctx + 1)):
        if j not in shown:
            if shown and j - 1 not in shown: print("  ...")
            print(f"{j:4} {L[j]}"); shown.add(j)
print(fl, L[-1])
