#!/usr/bin/env python3
"""Check a shifted link (tools/link/gen.py --shift, --seq, --pad) against the pinned one, independently of the linker:
 V1  every symbol moved exactly as the layout says (new = old + N for run addresses in segment W at or after A);
 V2  the two images differ only inside relocation sites of the linked objects;
 V3  at every relocation site the new field encodes the moved target (calls: new displacement between the moved
     site and the moved target; 32-bit words: the moved address; high/low parts: the moved symbol address).
The layout of the changed link is read from the PA_ symbols that gen.py places in front of every piece.
usage: verify_shift.py leon2m"""
import json, pathlib, re, struct, sys, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import exact
sys.path.insert(0, str(ROOT / "tools/link")); import secs
sec = sys.argv[1]; L = ROOT / "work/link"; N = 0; AT = 0
SEGS = [(n, v, ln) for n, v, f, ln in secs.SEGS[sec]]; MV = sys.argv[sys.argv.index("--move") + 1] if "--move" in sys.argv else secs.MOVE[sec]
def seg(a):
    for n, v, ln in SEGS:
        if v <= a < v + ln: return n, v
    return None
import bisect
def syms0(elf):
    d = {}
    for m in re.finditer(r"^([0-9a-f]+) \w (\S+)$", exact.run(exact.tool("nm"), elf).stdout, re.M): d[m[2]] = int(m[1], 16)
    return d
_o, _n = syms0(L / f"{sec}.elf"), syms0(L / f"{sec}.shift.elf")
PM = sorted((_o[k], _n[k]) for k in _o if k.startswith("PA_")); PS = [x[0] for x in PM]     # piece start: old -> new
def mp(a):
    if not seg(a): return a
    i = bisect.bisect_right(PS, a) - 1
    return a if i < 0 else PM[i][1] + (a - PM[i][0])
GROW = max(n_ - o_ for o_, n_ in PM)
old = {n: (L / f"{sec}.{n}.bin").read_bytes() for n, _, _ in SEGS}; new = {n: (L / f"{sec}.shift.{n}.bin").read_bytes() for n, _, _ in SEGS}
def rd(img, a):
    n, v = seg(a) if img is old else seg_new(a)
    return struct.unpack(">I", img[n][a - v:a - v + 4])[0]
def seg_new(a):
    for n, v, ln in SEGS:
        if v <= a < v + ln + (GROW if n == MV else 0): return n, v
    return None
def syms(elf):
    d = {}
    for m in re.finditer(r"^([0-9a-f]+) \w (\S+)$", exact.run(exact.tool("nm"), elf).stdout, re.M): d[m[2]] = int(m[1], 16)
    return d
so, sn = syms(L / f"{sec}.elf"), syms(L / f"{sec}.shift.elf")
v1 = [(k, hex(so[k]), hex(sn.get(k, -1))) for k in so if sn.get(k) != mp(so[k]) and not k.startswith("PA_")]
print("V1 symbols:", len(so), "moved wrongly:", len(v1), v1[:5])
pieces = json.loads((L / f"{sec}.pieces.json").read_text())
secaddr = {(o, s): a for a, size, o, s in pieces}
rel = {}
def relocs(obj):
    if obj not in rel:
        r = collections.defaultdict(list); cur = None
        for ln in exact.run(exact.tool("objdump"), "-r", obj).stdout.splitlines():
            m = re.match(r"RELOCATION RECORDS FOR \[(\S+)\]", ln)
            if m: cur = m.group(1); continue
            m = re.match(r"^([0-9a-f]{8})\s+(R_SPARC_\w+)\s+(\S+?)(?:\+0x([0-9a-f]+))?\s*$", ln)
            if m: r[cur].append((int(m[1], 16), m[2], m[3], int(m[4] or "0", 16)))
        rel[obj] = r
    return rel[obj]
sites = {}
for a, size, o, s in pieces:
    for off, typ, sym, add in relocs(o).get(s, []): sites[a + off] = (typ, sym, add, o)
# V2
bad2 = []
for n, v, ln in SEGS:
    for a in range(v, v + ln - 3, 4):
        if old[n][a - v:a - v + 4] != new[n][mp(a) - v:mp(a) - v + 4] and a not in sites: bad2.append(hex(a))
    tail = [a for a in range(v + (ln & ~3), v + ln) if old[n][a - v] != new[n][mp(a) - v]]
    bad2 += [hex(a) for a in tail]
print("V2 words that differ outside a relocation site:", len(bad2), bad2[:8])
# V3
bad3 = collections.Counter(); ex = []; cnt = collections.Counter(); changed = 0
for a, (typ, sym, add, o) in sites.items():
    wo, wn = rd(old, a), rd(new, mp(a)); cnt[typ] += 1; changed += wo != wn
    def symaddr(tab, shifted):
        if sym.startswith(".") and (o, sym) in secaddr: return mp(secaddr[(o, sym)]) if shifted else secaddr[(o, sym)]
        return tab.get(sym)
    if typ in ("R_SPARC_WDISP30", "R_SPARC_WDISP22"):
        bits = 30 if typ.endswith("30") else 22; mask = (1 << bits) - 1
        d = wo & mask
        if d >> (bits - 1): d -= 1 << bits
        t = (a + 4 * d) & 0xFFFFFFFF
        exp = ((mp(t) - mp(a)) >> 2) & mask
        okk = (wn & mask) == exp and (wn & ~mask) == (wo & ~mask)
    elif typ == "R_SPARC_32": okk = wn == mp(wo)
    elif typ in ("R_SPARC_HI22", "R_SPARC_LO10", "R_SPARC_13"):
        S = symaddr(sn, True)
        if S is None: okk = False
        else:
            T = (S + add) & 0xFFFFFFFF
            okk = ((wn & 0x3FFFFF) == T >> 10 and wn >> 22 == wo >> 22) if typ == "R_SPARC_HI22" else ((wn & 0x1FFF) == (T & 0x3FF) and wn >> 13 == wo >> 13) if typ == "R_SPARC_LO10" else ((wn & 0x1FFF) == (T & 0x1FFF))
            So = symaddr(so, False)
            if So is not None and mp((So + add) & 0xFFFFFFFF) != T and seg((So + add) & 0xFFFFFFFF): okk = False
    else: okk = False
    if not okk:
        bad3[typ] += 1
        if len(ex) < 8: ex.append((hex(a), typ, sym, add, hex(wo), hex(wn)))
print("V3 relocation sites:", len(sites), dict(cnt), "| changed by the shift:", changed, "| wrong:", dict(bad3), ex)
print("RESULT:", "PASS" if not v1 and not bad2 and not bad3 else "FAIL")
