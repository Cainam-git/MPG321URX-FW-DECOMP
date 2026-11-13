#!/usr/bin/env python3
"""completeness checks of work/refs/8051_bank<b>.refs.json.
(a) CODE addresses named in a function's source that no entry inside that function carries
(b) data pieces (strings / byte runs) of the non-function regions that no entry points at
usage: python3 -I tools/refs/8051/check.py <bank>"""
import json, pathlib, sys
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import d51, gaps, refs  # noqa: E402

b = int(sys.argv[1]); B = refs.Bank(b)
E = json.loads((d51.ROOT / "work" / "refs" / f"8051_bank{b}.refs.json").read_text())
vals = {}
for e in E:
    loc = e["off"] - B.base
    vals.setdefault(e["value"] if e["width"] != 1 else None, []).append(loc)
tv = {e["target"]["off"] - B.base for e in E if e["target"].get("off") is not None}
print("(a) source-named CODE addresses (per source file) that no entry of that file's functions carries:")
byfile = {}
for e in E:
    loc = e["off"] - B.base
    f = B.owner(loc)
    inf = B.info(f) if f else None
    if inf: byfile.setdefault(inf["file"], set()).add(e["value"])
seenf = set()
for a, e, n in B.code:
    inf = B.info(n)
    if not inf or inf["file"] in seenf: continue
    seenf.add(inf["file"])
    for v, txt in inf["lit"].items():
        if v not in byfile.get(inf["file"], set()):
            print("   %s: %s" % (inf["file"], txt))
print("(b) data pieces with no entry pointing at their start:")
for s, e in B.regions:
    for k, x, y in gaps.pieces(B.bk, s, e):
        if k in ("ff", "zero"): continue
        if x not in tv:
            show = repr(B.bk[x:y - 1].decode("latin1"))[:60] if k == "str" else B.bk[x:min(y, x + 24)].hex(" ")
            print("   %04x-%04x %-5s %s" % (x, y, k, show))
