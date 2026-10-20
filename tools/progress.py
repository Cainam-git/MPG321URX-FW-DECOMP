#!/usr/bin/env python3
"""Scoreboard: bytes and functions matched per core, from symbols/<cpu>.json.
Usage: progress.py"""
import json, pathlib
ROOT = pathlib.Path(__file__).resolve().parent.parent
for cpu in ("leon2s", "leon2m", "8051_bank0", "8051_bank1", "8051_bank2", "8051_bank3"):
    fp = ROOT / "symbols" / f"{cpu}.functions.json"
    if not fp.exists(): continue
    funcs = {f"{f['start']:08x}": f for f in json.loads(fp.read_text())["functions"]}
    total_b = sum(f["size"] for f in funcs.values())
    matched = {}
    sp = ROOT / "symbols" / f"{cpu}.json"
    if sp.exists():
        for k, v in json.loads(sp.read_text())["functions"].items():
            if v.get("status") == "matched": matched[k.split(":")[-1]] = v.get("by", "?")
    mb = sum(funcs[k]["size"] for k in matched if k in funcs)
    by = {}
    for v in matched.values(): by[v] = by.get(v, 0) + 1
    print(f"{cpu}: {len(matched)}/{len(funcs)} functions, {mb}/{total_b} bytes ({100*mb/total_b:.2f}%) matched  {by}")
