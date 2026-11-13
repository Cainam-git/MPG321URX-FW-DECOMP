#!/usr/bin/env python3
"""Print the firmware listing (Ghidra) of 8051 functions without compiling anything.
usage: lst8051.py <bank> <fn> [fn ...]"""
import json, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff8051
bank = sys.argv[1]
fs = {x["name"]: x for x in json.loads((ROOT / "symbols" / f"{bank}.functions.json").read_text())["functions"]}
for fn in sys.argv[2:]:
    f = fs[fn]; print(f"== {fn} @ 0x{f['start']:04x} ({f['size']} bytes)")
    out = diff8051.ghidra_listing(bank, f["start"], f["start"] + f["size"])
    print("\n".join(out) if isinstance(out, list) else out)
