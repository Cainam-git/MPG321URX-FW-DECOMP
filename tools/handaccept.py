#!/usr/bin/env python3
"""Accept a documented hand match: re-judge the file (shape + exact bytes at the real address), copy it unchanged to
src/<cpu>/<fn>.c (the file carries its own documentation header and comments), mark it matched in symbols/<cpu>.json
with by=<by>, the given one-line summary, and the winning flags. Refuses anything that is not byte-exact or that has
no documentation header.
usage: handaccept.py <cpu> <by> <fn> <file.c> "<one-line summary>" """
import json, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import near, strcheck
cpu, by, fn, path, summary = sys.argv[1:6]
src = pathlib.Path(path).read_text()
if not src.lstrip().startswith("/*") or len(src.split("*/")[0]) < 200:
    sys.exit("refused: the file needs a documentation header comment")
score, match, reason, pairs, flags = near.judge(cpu, fn, path)
if not match: sys.exit(f"refused: not byte-exact ({score:.1f} %, {reason})")
img = (ROOT / "parts" / f"{cpu}.bin").read_bytes()
import re as _re   # declaration asm labels (asm("name")) are link names, not string data
src_nolabels = _re.sub(r'\b(?:__asm__|asm)\s*\(\s*"[A-Za-z_][A-Za-z0-9_]*"\s*\)', "", src)
# Big-chip unit strings can live in its DATA area (file = address + 0x108000, outside parts/leon2m.bin);
# exact.py already proves the reference addresses, so also accept literals present in the full FW.021 image
fwimg = (ROOT / "firmware" / "MSI_MPG321URX_V021_7F69.bin").read_bytes()
bad = [x for x in strcheck.literals(src_nolabels) if x + b"\0" not in img and x + b"\0" not in fwimg]
if bad: sys.exit(f"refused: string not in firmware: {bad[0][:60]}")
(ROOT / "src" / cpu / f"{fn}.c").write_text(src)
f = {g["name"]: g for g in json.loads((ROOT / "symbols" / f"{cpu}.functions.json").read_text())["functions"]}[fn]
sp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(sp.read_text())
cfg = json.loads((ROOT / "tools/config.json").read_text())[cpu]
e = {"name": fn, "status": "matched", "by": by, "comment": summary}
if flags != cfg["cflags"]: e["cflags"] = flags
sym["functions"][f"ram:{f['start']:08x}"] = e
sp.write_text(json.dumps(sym, indent=2, sort_keys=True))
sc = ROOT / "work/autoc" / f"{cpu}.scores.json"; s = json.loads(sc.read_text())
s.setdefault(fn, {})["score"] = 100.0; sc.write_text(json.dumps(s, indent=1, sort_keys=True))
print(f"{fn}: accepted ({flags})")
