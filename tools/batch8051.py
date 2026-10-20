#!/usr/bin/env python3
"""Batch judge for hand drafts on the 8051 side: every <dir>/<FUN_CODE_xxxx>[.variant].c is judged with every
Keil option set (tools/config.json c51opts + alt_c51opts), all in parallel, and the best result per function is
printed. Exact matches are reported as MATCH; nothing is accepted automatically (accepting = documented header +
tools/accept8051.py).
usage: batch8051.py <bank> <dir> [--jobs N] [--only FUN_CODE_a,FUN_CODE_b]"""
import argparse, concurrent.futures as cf, json, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff8051
CFG = json.loads((ROOT / "tools" / "config.json").read_text())["8051"]
OPTS = [CFG["c51opts"]] + CFG.get("alt_c51opts", [])

def one(job):
    bank, fn, path, opts = job
    try: r = diff8051.judge(bank, fn, str(path), opts)
    except Exception as e: return fn, path.name, opts, -1.0, False, str(e)[:80]
    if not r.get("ok"): return fn, path.name, opts, -1.0, False, (r.get("error") or "")[:80].replace("\n", " ")
    return fn, path.name, opts, r["score"], r["match"], r.get("exact") or ""

if __name__ == "__main__":
    ap = argparse.ArgumentParser(); ap.add_argument("bank"); ap.add_argument("dir")
    ap.add_argument("--jobs", type=int, default=6); ap.add_argument("--only", default="")
    a = ap.parse_args(); only = set(a.only.split(",")) if a.only else None
    jobs = []
    for p in sorted(pathlib.Path(a.dir).glob("FUN_CODE_*.c")):
        fn = p.name.split(".")[0]
        if only and fn not in only: continue
        jobs += [(a.bank, fn, p, o) for o in OPTS]
    best = {}
    with cf.ProcessPoolExecutor(a.jobs) as ex:
        for fn, name, opts, score, match, note in ex.map(one, jobs):
            b = best.get(fn)
            if b is None or (match, score) > (b[3], b[2]): best[fn] = (name, opts, score, match, note)
    for fn, (name, opts, score, match, note) in sorted(best.items()):
        print(f"{fn:16} {score:6.1f}% {'MATCH' if match else '     '} {name:28} {opts}  {note}")
