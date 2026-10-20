#!/usr/bin/env python3
"""Near-twin drafts: an unmatched function whose instruction shape is >= 90 % similar (difflib over the shape tokens,
length within 3) to a MATCHED one with C gets that C as a draft, constants swapped by position when the counts agree
(tools/twin.py's swap; when they do not agree the names/constants stay and the permuters or hand work fix them). The draft
replaces work/autoc/<cpu>/<fn>.c only when it judges higher than the current draft, so permuter.py, permuter2.py and
hand work start from it. Exact matches are filed at once (by "sibling"). twin.py itself needs an identical shape.
usage: sibling.py <cpu> [--dry]
"""
import difflib, json, pathlib, re, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import twin, near, permuter as ours


def main():
    cpu = sys.argv[1]; dry = "--dry" in sys.argv
    sym = json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())["functions"]; byname = {v["name"]: v for v in sym.values()}
    shapes = json.loads((ROOT / "work" / f"{cpu}-shapes.json").read_text()); tok = {f: s.split("|") for f, s in shapes.items()}
    scp = ROOT / "work" / "autoc" / f"{cpu}.scores.json"; scores = json.loads(scp.read_text())
    matched = [f for f, v in byname.items() if v.get("status") == "matched" and (ROOT / "src" / cpu / f"{f}.c").exists() and f in shapes]
    by_len = {}
    for m in matched: by_len.setdefault(len(tok[m]), []).append(m)
    memo_p = ROOT / "work" / f"{cpu}-sibling-tried.json"; memo = json.loads(memo_p.read_text()) if memo_p.exists() else {}
    got = []; filed = 0
    for fn in shapes:
        if byname.get(fn, {}).get("status") == "matched" or fn.startswith("thunk"): continue
        n = len(tok[fn]); best, bm = 0.0, None
        for k in range(max(1, n - 3), n + 4):
            for m in by_len.get(k, []):
                r = difflib.SequenceMatcher(None, tok[fn], tok[m], autojunk=False).ratio()
                if r > best: best, bm = r, m
        if not bm or best < 0.9 or best >= 1.0: continue
        st = (ROOT / "src" / cpu / f"{bm}.c").read_text(); body = re.sub(r"/\*.*?\*/\s*", "", st, count=1, flags=re.S)
        _, cs = twin.shape_and_consts(cpu, fn); _, mcs = twin.shape_and_consts(cpu, bm)
        src = twin.swap(body, mcs, cs) if len(cs) == len(mcs) else None
        if src is None: src = body
        src = re.sub(r"\b%s\b" % re.escape(bm), fn, src)
        h = f"{bm}:{hash(src) & 0xffffffff:08x}"
        if memo.get(fn) == h: continue
        memo[fn] = h
        out = ROOT / "work" / "sibling" / cpu / f"{fn}.c"; out.parent.mkdir(parents=True, exist_ok=True); out.write_text(src)
        score, match, reason, pairs, flags = near.judge(cpu, fn, out)
        cur = (scores.get(fn) or {}).get("score", -1) or -1
        got.append((fn, bm, round(best, 2), round(score, 1), round(cur, 1), match))
        if dry: continue
        if match:
            ours.file_match(cpu, fn, src, flags, [f"sibling of {bm} (shape {best:.2f}), constants swapped"]); filed += 1
            scores.setdefault(fn, {})["score"] = 100.0
        elif score > cur + 0.05:
            (ROOT / "work" / "autoc" / cpu / f"{fn}.c").write_text(src); scores.setdefault(fn, {})["score"] = score
    memo_p.write_text(json.dumps(memo, indent=0))
    if not dry: scp.write_text(json.dumps(scores, indent=1))
    better = sum(1 for g in got if g[3] > g[4] + 0.05)
    print(f"{cpu} siblings: {len(got)} tried, {better} better than the current draft, {filed} now match" + (" (dry)" if dry else ""))
    for g in got[:12]: print("  ", *g)


if __name__ == "__main__": main()
