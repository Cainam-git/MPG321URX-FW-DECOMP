#!/usr/bin/env python3
"""Hill-climb 8051 near-misses (Keil C51) by small type / memory-space changes. Fully mechanical. Slow (Wine):
each try is a Keil compile. Starts from work/auto8051/<bank>/<fn>.c, keeps improvements.
usage: permute8051.py <bank> [--min 20] [--jobs 6]"""
import json, re, sys, pathlib, argparse, tempfile, shutil
from concurrent.futures import ThreadPoolExecutor
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import diff8051
ROOT = pathlib.Path(__file__).resolve().parent.parent
TYPES = ["unsigned char", "char", "unsigned int", "int", "unsigned long", "long", "bit"]
SPACES = ["xdata", "data", "idata", "pdata", "code"]

def mutations(fn, src):
    m = re.search(r"^([A-Za-z_][\w ]*?)\s+" + re.escape(fn) + r"\s*\(([^)]*)\)", src, re.M)
    if m:
        for t in ["void"] + TYPES[:-1]:
            if t != m.group(1).strip(): yield f"return {t}", src[:m.start(1)] + t + src[m.end(1):]
        if m.group(2).strip() not in ("", "void"):
            parts = m.group(2).split(",")
            for i, p in enumerate(parts):
                pm = re.match(r"\s*(.*?)\s*(\w+)\s*$", p)
                if not pm or "*" in p: continue
                for t in TYPES[:-1]:
                    if t == pm.group(1): continue
                    np_ = parts[:]; np_[i] = (" " if i else "") + f"{t} {pm.group(2)}"
                    yield f"param {pm.group(2)} {t}", src[:m.start(2)] + ",".join(np_) + src[m.end(2):]
    for gm in re.finditer(r"^([\w ]+?) (xdata|data|idata|pdata|code) (\w+) _at_ (0x[0-9a-f]+);$", src, re.M):
        for t in TYPES[:-1]:
            if t != gm.group(1): yield f"global {gm.group(3)} {t}", src[:gm.start(1)] + t + src[gm.end(1):]
        for sp in SPACES:
            if sp != gm.group(2): yield f"space {gm.group(3)} {sp}", src[:gm.start(2)] + sp + src[gm.end(2):]
        yield f"volatile {gm.group(3)}", src[:gm.start(1)] + "volatile " + src[gm.start(1):]
    for em in re.finditer(r"^extern ([\w ]+?) (\w+)\(([^)]*)\);$", src, re.M):
        for t in ("void", "unsigned char", "unsigned int", "bit"):
            if t != em.group(1): yield f"callee {em.group(2)} {t}", src[:em.start(1)] + t + src[em.end(1):]
    for lm in re.finditer(r"^  (unsigned char|char|unsigned int|int|unsigned long|long) (\w+);$", src, re.M):
        for t in TYPES[:-1]:
            if t != lm.group(1): yield f"local {lm.group(2)} {t}", src[:lm.start(1)] + t + src[lm.end(1):]
    for rm in re.finditer(r"^(\s+)(\w+\([^;]*\));\n\s+return(?: [^;]*)?;\n", src, re.M):
        yield "return call result", src[:rm.start()] + f"{rm.group(1)}return {rm.group(2)};\n" + src[rm.end():]

def score(bank, fn, src):
    td = pathlib.Path(tempfile.mkdtemp(prefix="p51_")); p = td / f"{fn}.c"; p.write_text(src)
    try:
        r = diff8051.judge(bank, fn, str(p))
        return r.get("score", 0) if r.get("ok") else -1.0
    finally: shutil.rmtree(td, ignore_errors=True)

def climb(bank, fn):
    p = ROOT / "work" / "auto8051" / bank / f"{fn}.c"; src = p.read_text()
    best = start = score(bank, fn, src); steps = []
    for _ in range(3):
        improved = False
        for what, v in mutations(fn, src):
            s = score(bank, fn, v)
            if s > best:
                best, src, improved = s, v, True; steps.append(what)
                if best >= 100: break
        if not improved or best >= 100: break
    if best > start: p.write_text(src)
    return fn, start, best, steps

def main():
    ap = argparse.ArgumentParser(); ap.add_argument("bank"); ap.add_argument("--min", type=float, default=20); ap.add_argument("--jobs", type=int, default=6)
    a = ap.parse_args()
    scp = ROOT / "work" / "auto8051" / f"{a.bank}.scores.json"; scores = json.loads(scp.read_text())
    sym = json.loads((ROOT / "symbols" / f"{a.bank}.json").read_text())["functions"] if (ROOT / "symbols" / f"{a.bank}.json").exists() else {}
    done = {v["name"] for v in sym.values() if v.get("status") == "matched"}
    todo = [fn for fn, v in scores.items() if a.min <= v["score"] < 100 and fn not in done]
    with ThreadPoolExecutor(a.jobs) as ex: res = list(ex.map(lambda fn: climb(a.bank, fn), todo))
    for fn, s0, s1, steps in res:
        if s1 != scores[fn]["score"]: scores[fn]["score"] = s1
    scp.write_text(json.dumps(scores, indent=1, sort_keys=True))
    print(f"{a.bank}: {len(todo)} tried, {sum(1 for r in res if r[2] > r[1])} improved, {sum(1 for r in res if r[2] >= 100)} now match")

if __name__ == "__main__":
    main()
