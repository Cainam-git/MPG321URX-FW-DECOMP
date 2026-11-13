#!/usr/bin/env python3
"""From <sec>.resolve.json: one address per symbol, proven against the firmware: every reference site of the symbol
(call displacement, high part, low part) must agree with it. For names that carry an address (FUN_/DAT_/...) the
address the name says is tested; for the file's own literals, jump tables and library names it is solved.
-> work/link/<sec>.symtab.json {symbol: run address}; prints every disagreement. usage: symtab.py leon2m"""
import json, pathlib, re, sys, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]; sec = sys.argv[1]
R = json.loads((ROOT / "work/link" / f"{sec}.resolve.json").read_text())
sys.path.insert(0, str(ROOT / "tools/link")); import secs
FT = {f["name"]: f["start"] for f in json.loads((ROOT / f"symbols/{sec}.functions.json").read_text())["functions"]}
def name_addr(s):
    if s in FT: return secs.vma(sec, FT[s])
    m = re.fullmatch(r"_?(?:FUN|DAT|PTR|ARR|s|u)_([0-9a-fA-F]{8})(?:_\w+)?", s)
    if m:
        a = int(m.group(1), 16)
        return secs.vma(sec, a) if s.startswith("FUN_") else a
    return None
cons = collections.defaultdict(list)          # symbol -> constraints (kind, addend, value, function)
bad = collections.Counter(); ex = collections.defaultdict(list); cls = collections.Counter()
for r in R:
    startup = sec == "leon2m" and r["name"].startswith("FUN_a002")
    for e in r["refs"]:
        s, add = e["sym"], e["add"]
        if "other" in e: bad["other relocation type " + ",".join(e["other"])] += 1; ex["other"].append((r["name"], s)); continue
        for t in e.get("target", []): cons[s].append(("abs", add, t, r["name"]))
        for h in e.get("hi", []): cons[s].append(("hi", add, h, r["name"]))
        for l in e.get("lo", []): cons[s].append(("lo", add, l, r["name"]))
def ok(S, c):
    k, add, v, _ = c; x = (S + add) & 0xFFFFFFFF
    return x == v if k == "abs" else ((x & 0xFFFFFC00) == v if k == "hi" else (x & 0x3FF) == v)
out = {}
for s, cs in cons.items():
    w = name_addr(s)
    if w is not None:
        cls["named"] += 1
        f = [c for c in cs if not ok(w, c)]
        if f: bad["name and firmware disagree"] += 1; ex["disagree"].append((s, hex(w), [(c[0], c[1], hex(c[2]), c[3]) for c in f[:2]])); continue
        out[s] = w; continue
    k = "literal" if s.startswith("LIT.") else ("table" if s.startswith(".jt") else "other"); cls[k] += 1
    cand = {(c[2] - c[1]) & 0xFFFFFFFF for c in cs if c[0] == "abs"}
    if not cand:
        his = {((c[2] - c[1]) & 0xFFFFFFFF) for c in cs if c[0] == "hi"}; los = [c for c in cs if c[0] == "lo"]
        for h in his:
            for c in los:
                S = (h & 0xFFFFFC00) | ((c[2] - c[1]) & 0x3FF)
                for S2 in (S, (S + 0x400) & 0xFFFFFFFF, (S - 0x400) & 0xFFFFFFFF):
                    if all(ok(S2, x) for x in cs): cand.add(S2)
    cand = {S for S in cand if all(ok(S, x) for x in cs)}
    if len(cand) != 1: bad["not settled"] += 1; ex["unsettled"].append((s, [hex(x) for x in sorted(cand)][:3], [(c[0], c[1], hex(c[2])) for c in cs[:3]])); continue
    out[s] = cand.pop()
(ROOT / "work/link" / f"{sec}.symtab.json").write_text(json.dumps(out, indent=0, sort_keys=True))
print(sec, "symbols:", len(out), dict(cls)); print("problems:", dict(bad))
for k, v in ex.items(): print(" ", k, len(v), v[:6])
print("other names:", sorted(s for s in out if name_addr(s) is None and not s.startswith(("LIT.", ".jt")))[:40])
