#!/usr/bin/env python3
"""Names in the C source that carry an address instead of naming a function: func_0x<address>. The checking tools
turn such a name into the number written in it (tools/exact.py), so it does not follow when the function moves.
This script lists each such name with the function it stands for.
  leon2m: the address in a func_0x name was computed from the listing address of the calling function. The main
          program is listed 0xA0060000 above the address it runs at, so func_0x4008xxxx in a main-program file is
          the start-up routine at 0xA002xxxx (= FUN_a002xxxx). The start-up code is listed at its run address, so
          func_0x000xxxxx in a start-up file is the main-program function at that address (name = + 0xA0060000).
  leon2s: func_0xa0fxxxxx is 0xF10000 above the function it means (calls between the first and the third program
          part, see docs/MAP.md); func_0x9f1xxxxx is the third part at its run address (name = address + 0xF10000).
usage: aliases.py leon2m|leon2s [--export]   (--export writes symbols/<section>.aliases.json)"""
import json, pathlib, re, sys, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]; sec = sys.argv[1]
sys.path.insert(0, str(ROOT / "tools")); import srcpath
starts = {f["start"]: f["name"] for f in json.loads((ROOT / f"symbols/{sec}.functions.json").read_text())["functions"]}
def real(v):
    if sec == "leon2m":
        if 0x40088000 <= v < 0x4008FB44: return v - 0x40088000 + 0xA0028000
        if v < 0x1A8654: return v + 0xA0060000
        return v
    if 0xA0F70000 <= v < 0xA0FF0000: return v - 0xF10000
    if 0x9F1B0000 <= v < 0x9F1CEEC8: return v + 0xF10000
    return v
use = collections.Counter(); files = collections.defaultdict(set)
for p in srcpath.files(sec, ".c"):              # the code with its names put back to labels
    t = re.sub(r"/\*.*?\*/", "", srcpath.read_labels(sec, p), flags=re.S)
    for m in re.finditer(r"\bfunc_0x([0-9a-fA-F]{8})\b", t): use[m.group(0)] += 1; files[m.group(0)].add(p.name)
rows = []; unresolved = []
for n in sorted(use):
    a = real(int(n[7:], 16)); fn = starts.get(a)
    rows.append({"name": n, "stands_for": fn, "address": a, "files": len(files[n])})
    if not fn: unresolved.append(n)
print(sec, len(rows), "address-carrying names in", len(set().union(*files.values())) if files else 0, "files;", len(unresolved), "without a function start:", unresolved[:12])
if "--export" in sys.argv:
    (ROOT / f"symbols/{sec}.aliases.json").write_text('{"section":"%s","names":[\n' % sec + ",\n".join(json.dumps(r, separators=(",", ":")) for r in rows) + "\n]}\n")
