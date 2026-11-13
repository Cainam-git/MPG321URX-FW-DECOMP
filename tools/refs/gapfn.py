#!/usr/bin/env python3
"""Routines outside the function table (leon2m / leon2s): split every code gap into (a) a trailing nop that belongs
to the listed function before the gap and (b) unlisted routines. Prints the plan; --json writes work/refs/gapfn_<section>.json.
usage: gapfn.py leon2m|leon2s [--json]"""
import json, pathlib, struct, sys
ROOT = pathlib.Path(__file__).resolve().parents[2]
FW = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()
sec = sys.argv[1]
if sec == "leon2m": foff = lambda a: a - 0xA0000000 + 0xA8000; lo, hi = 0x120000, 0x206B00
else: foff = lambda a: a - 0xA0060000 + 0x50000; lo, hi = 0x50000, 0xCEEC5
fl = json.loads((ROOT / f"symbols/{sec}.functions.json").read_text())["functions"]
r = sorted((f["start"], f["end"], f["name"]) for f in fl if lo <= foff(f["start"]) < hi)
W = lambda a: struct.unpack(">I", FW[foff(a):foff(a) + 4])[0]
NOP, SIBEND = 0x01000000, 0x9E104000
def iscall(w): return w >> 30 == 1
ext = []; new = []; other = []
prev_end = r[0][1]; prev = r[0]
for s, e, n in r[1:]:
    if s > prev_end:
        a = prev_end; words = [W(x) for x in range(a, s, 4)]
        if any(w not in (0, 0xFFFFFFFF) for w in words):
            i = 0
            if words[0] == NOP and not prev[2].startswith("switchdata") and (W(prev_end - 4) == SIBEND or iscall(W(prev_end - 8))):
                ext.append((prev[2], prev_end, "sibling" if W(prev_end - 4) == SIBEND else "call")); i = 1
            while i < len(words):
                j = i; ok = False
                while j < len(words):
                    if words[j] == SIBEND and j >= 2 and iscall(words[j - 1]): ok = True; break
                    j += 1
                if not ok: other.append((a + 4 * i, 4 * (len(words) - i), prev[2])); break
                j += 1
                if j < len(words) and words[j] == NOP: j += 1
                new.append((a + 4 * i, a + 4 * j)); i = j
    if e > prev_end: prev_end = e; prev = (s, e, n)
print(sec, "extend by a trailing nop:", len(ext), {k: sum(1 for x in ext if x[2] == k) for k in ("sibling", "call")})
print(sec, "new routines:", len(new), "bytes", sum(b - a for a, b in new))
print(sec, "other non-empty stretches:", len(other), "bytes", sum(x[1] for x in other))
for x in other[:30]: print("   other", hex(x[0]), x[1], "after", x[2], FW[foff(x[0]):foff(x[0]) + 12].hex())
if "--json" in sys.argv:
    (ROOT / f"work/refs/gapfn_{sec}.json").write_text(json.dumps({"ext": ext, "new": new, "other": other}))
