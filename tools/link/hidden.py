#!/usr/bin/env python3
"""Hidden addresses in instructions: every 'sethi' in the linked code that is NOT a relocation site is compared with
the same instruction in the three older firmware versions (tools/refs/vmap.py). A high part that changes between
versions is an address that moved with its target, i.e. an address the link does not know about.
usage: hidden.py leon2m"""
import json, pathlib, re, struct, sys, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); sys.path.insert(0, str(ROOT / "tools/refs")); import exact, vmap
sys.path.insert(0, str(ROOT / "tools/link")); import secs
sec = sys.argv[1]; L = ROOT / "work/link"
FW = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()
OLD = {"V020": "MSI_MPG321URX_V020_95AB.bin", "V016": "MSI_MPG321URX_V016_C6FB.bin", "V012": "MSI_MPG321URX_V012_91A5.bin"}
SEGS = [s for s in secs.SEGS[sec] if s[0] in secs.CODE[sec]]
def foff(a):
    for n, v, f, ln in SEGS:
        if v <= a < v + ln: return a - v + f
pieces = json.loads((L / f"{sec}.pieces.json").read_text())
rel = set()
for a, size, o, s in pieces:
    cur = None
    for ln in exact.run(exact.tool("objdump"), "-r", o).stdout.splitlines():
        m = re.match(r"RELOCATION RECORDS FOR \[(\S+)\]", ln)
        if m: cur = m.group(1); continue
        m = re.match(r"^([0-9a-f]{8})\s+R_SPARC", ln)
        if m and cur == s: rel.add(a + int(m[1], 16))
maps = {v: (vmap.load(v), (ROOT / "firmware" / f).read_bytes()) for v, f in OLD.items()}
tot = 0; changed = collections.defaultdict(list); nomap = 0
for a, size, o, s in pieces:
    if not (s == ".text"): continue
    for x in range(a, a + size, 4):
        if x in rel: continue
        f = foff(x)
        if f is None: continue
        w = struct.unpack(">I", FW[f:f + 4])[0]
        if w >> 30 != 0 or (w >> 22) & 7 != 4: continue            # sethi
        tot += 1; seen = False
        for v, (m, img) in maps.items():
            f2 = m.map(f)
            if f2 is None: continue
            seen = True
            w2 = struct.unpack(">I", img[f2:f2 + 4])[0]
            if w2 != w and (w2 >> 22) == (w >> 22): changed[x].append((v, hex((w & 0x3FFFFF) << 10), hex((w2 & 0x3FFFFF) << 10)))
        nomap += not seen
print(sec, "sethi instructions that are not relocation sites:", tot, "| not found in any older version:", nomap, "| high part differs in an older version:", len(changed))
import bisect
ps = sorted((a, a + size, pathlib.Path(o).name) for a, size, o, s in pieces if s == ".text"); st = [p[0] for p in ps]
by = collections.Counter(); ex = []
for x, v in sorted(changed.items()):
    i = bisect.bisect_right(st, x) - 1; by[ps[i][2]] += 1
    if len(ex) < 12: ex.append((hex(x), ps[i][2], v[0]))
cls = collections.Counter(); win = []
for x, v in sorted(changed.items()):
    h = int(v[0][1], 16)
    k = "RAM" if h >= 0xA8000000 else ("start-up code" if h >= 0xA0000000 else ("code window" if 0x10000 <= h < 0x1A8800 else "small number"))
    cls[k] += 1
    if k == "code window":
        i = bisect.bisect_right(st, x) - 1; win.append((hex(x), ps[i][2].split(".")[0], v))
print(dict(cls))
for w_ in win: print("  ", w_)
