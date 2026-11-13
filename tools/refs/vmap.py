#!/usr/bin/env python3
"""Version map: a position (file offset) of FW.021 -> the same position in FW.020 / FW.016 / FW.012.

usage:  python3 -I tools/refs/vmap.py V020 0x2A0380 [more offsets]   mapped offset + bytes of both files
        python3 -I tools/refs/vmap.py --stats                          mapped / unmapped bytes per region and version
        python3 -I tools/refs/vmap.py --build [V020 V016 V012]          rebuild work/refs/vmap_<version>.json
        python3 -I tools/refs/vmap.py --check                           self-checks (function starts, init-data words)
API:    import vmap; m = vmap.load("V016"); m.map(off) -> offset or None; m.shift_at(off) -> mapped - off or None
        m.map(off, loose=True) also returns "P" positions (see below); m.kind(off) -> "S"/"C"/"A"/"P"/None

FORMAT of work/refs/vmap_<version>.json:
  {"version": "V016", "file": "<firmware file>", "regions": [[name, a_lo, a_hi, b_lo, b_hi, moved], ...],
   "segs": [[a, b, n, kind], ...]}           (sorted by a, no overlaps in a nor in b)
  Each seg says: FW.021 bytes a..a+n-1 correspond to bytes b..b+n-1 of the older file. kind:
    S  the bytes are identical
    C  code: instruction words equal once call displacements, sethi immediates and the %lo immediates of a sethi
       base are masked (FW.021 function bodies only). Calls among them were checked: the call target maps to the
       older call's target (else P); sethi+%lo pairs: the address they build translates to the older pair's (else P)
    A  4-byte word whose value differs and whose FW.021 value is an address whose target maps (through this map) to
       exactly the address stored in the older file: an address that moved with its target (re-checked on the final
       map)
    P  word or byte paired by position between two matched blocks, value changed and NOT explained by the map (a real
       change, a number, an address whose target has no image such as RAM without initial value, a wrong twin).
       map() returns None for P unless loose=True.
  Inside a region the map is monotonic except where the older file has whole functions (or blocks >= 1024 bytes)
  in another order: FW.016/FW.012's input processor was linked in another function order, and a few main-program
  functions moved; such blocks are each monotonic and never overlap others.

METHOD (build(), 4 passes, about 15 s per version):
  1. Region starts in the older file from the partition table at file 0x6000 (8-byte records: flash address,
     length). Leon2M initialised data sits at 0x0FC000 in the older versions (0x0EC000 in FW.021); everything else
     starts at the same offset with other lengths; the 8051 part is byte-identical.
  2. Streams: X = FW.021 with function bodies normalised (as tools/fwdiff.py) and, from pass 2 on, every data word
     whose value is an address with a mapped target replaced by the older address it predicts; Y = older file with
     the images of the FW.021 function bodies normalised.
  3. Blocks: (i) whole FW.021 functions found exactly once (normalised; body unique among FW.021 functions) and
     seeds from votes (4.); (ii) maximal blocks seeded by 32-byte strings unique on both sides in X, then (iii) the
     same in untranslated X where nothing is taken yet. Selection: strong first, then longest; overlaps cut; the
     heaviest in-order chain is kept, off-chain blocks only when strong or >= 1024 bytes. Gaps between consecutive
     blocks that are in order on both sides: 16- and 8-byte unique anchors, then a word-level longest common
     subsequence (a FW.021 data word may also match the word its translation predicts; blocks of >= 2-6 words with
     informative values), leftovers of equal length (<= 64 words) and equal-shift stretches (<= 1024 bytes,
     identical bytes) paired by position.
  4. Votes: every mapped call and every mapped data word that names a function start votes for that start's older
     position (call target / stored address); >= 2 votes, >= 80 % agreeing and contradicting the map -> seed block
     (equal normalised words from the voted start) for the next pass.
  5. Classification S/C/A/P per word and the final checks (calls, A words, sethi/%lo pairs).
SELF-CHECK: python3 -I tools/refs/vmap_check.py (function starts, init-data function pointers, sure jump tables).
"""
import bisect, json, pathlib, struct, sys, difflib, time

ROOT = pathlib.Path(__file__).resolve().parents[2]
FILES = {"V021": "MSI_MPG321URX_V021_7F69.bin", "V020": "MSI_MPG321URX_V020_95AB.bin",
         "V016": "MSI_MPG321URX_V016_C6FB.bin", "V012": "MSI_MPG321URX_V012_91A5.bin"}
OLD = ("V020", "V016", "V012")
_IMG = {}
def img(v):
    if v not in _IMG: _IMG[v] = (ROOT / "firmware" / FILES[v]).read_bytes()
    return _IMG[v]

def partitions(d):
    out = []
    for i in range(0, 0x100, 8):
        a, l = struct.unpack_from(">II", d, 0x6000 + i)
        if a == 0 and l == 0: break
        out.append((a, l))
    return out

# partition index -> (region name, cpu whose functions are code there, kind)
# partition order (same in all four files): 0 bank1, 1 bank2, 2 leon2m start-up, 3 leon2m init data,
# 4 leon2m code window, 5 leon2s program, 6 leon2s part 2, 7 tensilica, 8 leon2s part 3
def region_pairs(v):
    """[(name, a_lo, a_hi, b_lo, b_hi, cpu, moved)]: FW.021 range, older range, cpu whose functions are code there,
    moved = blocks may be reordered (the input processor of FW.016/FW.012 was linked in another order)"""
    pa, pb = partitions(img("V021")), partitions(img(v))
    R = [("8051+partition table", 0x000000, 0x030000, 0x000000, 0x030000, None, False)]
    names = {2: ("leon2m startup", "leon2m"), 3: ("leon2m initdata", None), 4: ("leon2m window", "leon2m"),
             7: ("tensilica", None)}
    for i, (nm, cpu) in names.items():
        (a, la), (b, lb) = pa[i], pb[i]
        R.append((nm, a, a + la, b, b + lb, cpu, False))
    # input processor: three partitions inside 0x050000..0x0D0000 (5, 6, 8), same offsets in every version
    if img("V021")[0x50000:0xD0000] == img(v)[0x50000:0xD0000]:
        R.append(("leon2s", 0x50000, 0xD0000, 0x50000, 0xD0000, "leon2s", False))
    else:
        R.append(("leon2s", 0x50000, 0xD0000, 0x50000, 0xD0000, "leon2s", True))
    return sorted(R, key=lambda r: r[1])

# stats regions of docs/MAP.md (FW.021 offsets)
MAPREG = [("8051 banks 0-2 + partition", 0x000000, 0x030000), ("tensilica", 0x030000, 0x03D8DC),
          ("leon2s program", 0x050000, 0x0D0000), ("leon2m startup", 0x0D0000, 0x0D7B44),
          ("leon2m initdata", 0x0EC000, 0x0F2F38), ("edid", 0x118000, 0x11EE00),
          ("main program", 0x120000, 0x206B00), ("rodata", 0x206B00, 0x2101F0), ("fonts", 0x2101F0, 0x275DE8),
          ("texts", 0x275DE8, 0x280000), ("data image", 0x280000, 0x2A0380), ("panel mode table", 0x2A0380, 0x2A0488),
          ("data image (rest)", 0x2A0488, 0x2B0600), ("trailer", 0x2B0600, 0x2B0654)]

# ---------------------------------------------------------------- functions (FW.021 file ranges)
def name2off(cpu, a):
    if cpu == "leon2s": return a - 0xA0060000 + 0x50000
    return a - 0xA0028000 + 0x0D0000 if a < 0xA0030000 else a - 0xA0000000 + 0xA8000

_FUN = {}
def functions(cpu):
    if cpu not in _FUN:
        fl = json.loads((ROOT / f"symbols/{cpu}.functions.json").read_text())["functions"]
        _FUN[cpu] = sorted((name2off(cpu, f["start"]), name2off(cpu, f["start"]) + f["size"], f["name"]) for f in fl)
    return _FUN[cpu]

def code_runs(cpu, lo, hi, join=0x40):
    runs = []
    for s, e, n in functions(cpu):
        if n.startswith("switchdata") or s < lo or e > hi: continue
        if runs and s - runs[-1][1] <= join and s >= runs[-1][1]: runs[-1][1] = max(runs[-1][1], e)
        elif runs and s < runs[-1][1]: runs[-1][1] = max(runs[-1][1], e)
        else: runs.append([s, e])
    return runs

# ---------------------------------------------------------------- normalisation (as tools/fwdiff.py)
def normalise(buf, lo, hi):
    """normalise the 4-byte words of buf[lo:hi] in place (lo 4-aligned relative to the file)"""
    sethi = set()
    for off in range(lo, hi - 3, 4):
        w = struct.unpack_from(">I", buf, off)[0]; op = w >> 30
        if w & 0xffffe000 == 0x9de3a000: sethi = set()
        elif w in (0x81c3e008, 0x81c7e008): sethi = {r for r in sethi if r >= 16}
        if op == 1: n = 0x40000000
        elif op == 0 and (w >> 22) & 7 == 4: sethi.add((w >> 25) & 31); n = w & 0xffc00000
        elif op in (2, 3) and (w >> 13) & 1 and ((w >> 14) & 31) in sethi: n = w & ~0x1fff
        else: continue
        struct.pack_into(">I", buf, off, n)

# ---------------------------------------------------------------- block anchors
def find_blocks(X, Y, alo, ahi, blo, bhi, k, minlen):
    """maximal matching blocks seeded by k-grams unique in X[alo:ahi] and in Y[blo:bhi]; returns [(a, b, n)]"""
    if ahi - alo < k or bhi - blo < k: return []
    yd = {}
    for j in range(blo, bhi - k + 1):
        g = Y[j:j + k]
        yd[g] = -1 if g in yd else j
    xc = {}
    for i in range(alo, ahi - k + 1):
        g = X[i:i + k]
        if g in yd and yd[g] >= 0: xc[g] = xc.get(g, 0) + 1
    out = []; i = alo; aprev = alo
    while i <= ahi - k:
        g = X[i:i + k]; j = yd.get(g, -1)
        if j < 0 or xc.get(g) != 1: i += 1; continue
        s, t = i, j
        while s > aprev and t > blo and X[s - 1] == Y[t - 1]: s -= 1; t -= 1
        e, f = i + k, j + k
        while e < ahi and f < bhi and X[e] == Y[f]: e += 1; f += 1
        if e - s >= minlen: out.append((s, t, e - s))
        aprev = e; i = e
    return out

def chain(blocks, weight=None):
    """heaviest chain with a and b increasing and not overlapping (blocks are non-overlapping in a)"""
    if not blocks: return []
    blocks = sorted(blocks)
    ends = sorted({b + n for a, b, n in blocks})
    rank = {v: i + 1 for i, v in enumerate(ends)}
    N = len(ends); tree = [(0, -1)] * (N + 1)
    def upd(i, val):
        while i <= N:
            if val[0] > tree[i][0]: tree[i] = val
            i += i & -i
    def qry(i):
        best = (0, -1)
        while i > 0:
            if tree[i][0] > best[0]: best = tree[i]
            i -= i & -i
        return best
    prev = [-1] * len(blocks); score = [0] * len(blocks)
    # process in a order; a block may follow any earlier block whose b end <= its b start (and a end <= a start)
    # a-overlap: blocks from one scan never overlap in a; from different scans (seeds) they might -> sorted check
    pending = []   # (a_end, idx) not yet inserted (insert when a_end <= current a)
    import heapq
    for idx, (a, b, n) in enumerate(blocks):
        while pending and pending[0][0] <= a:
            _, j = heapq.heappop(pending); upd(rank[blocks[j][1] + blocks[j][2]], (score[j], j))
        r = bisect.bisect_right(ends, b)
        sc, p = qry(r)
        score[idx] = sc + (weight((a, b, n)) if weight else n); prev[idx] = p
        heapq.heappush(pending, (a + n, idx))
    i = max(range(len(blocks)), key=lambda x: score[x]); out = []
    while i >= 0: out.append(blocks[i]); i = prev[i]
    return out[::-1]

# ---------------------------------------------------------------- address translation (FW.021 value -> older value)
def spaces(v_old):
    """address spaces [(v_lo, v_hi, v_base, file_base_021, file_base_old)]: a FW.021 value v in [v_lo, v_hi) names
    file offset v - v_base + file_base_021; the older file names offset t with the value t - file_base_old + v_base"""
    pa, pb = partitions(img("V021")), partitions(img(v_old))
    return [
        (0x10000, pa[4][1], 0, 0x108000, pb[4][0]),                          # leon2m code window (CPU 0 = 0x108000)
        (0xA0028000, 0xA0028000 + pa[2][1], 0xA0028000, pa[2][0], pb[2][0]),  # leon2m start-up code
        (0x40088000, 0x40088000 + pa[2][1], 0x40088000, pa[2][0], pb[2][0]),  # same, second numbering
        (0xA8024000, 0xA8024000 + pa[3][1], 0xA8024000, pa[3][0], pb[3][0]),  # leon2m initialised data in RAM
        (0xA0060000, 0xA00E0000, 0xA0060000, 0x50000, 0x50000),              # leon2s program
        (0x9F150000, 0x9F1D0000, 0x9F150000, 0x50000, 0x50000),              # leon2s, values 0xF10000 below run address
        # leon2s initialised data: partition 6 (file 0x0A6000) is copied to 0x9F196000 = RAM 0xA8076000 (from
        # FUN_CODE_0b0d; the RAM-window equivalence is inferred). Only used when the translated value is found.
        (0xA8076000, 0xA8076000 + pa[6][1], 0xA8076000, pa[6][0], pb[6][0]),
    ]

class Map:
    def __init__(self, version, segs, regions):
        self.version = version; self.segs = segs; self.regions = regions
        self._a = [s[0] for s in segs]
    def _seg(self, off):
        i = bisect.bisect_right(self._a, off) - 1
        if i < 0: return None
        a, b, n, k = self.segs[i]
        return (a, b, n, k) if off < a + n else None
    def map(self, off, loose=False):
        s = self._seg(off)
        if s is None or (s[3] == "P" and not loose): return None
        return s[1] + off - s[0]
    def kind(self, off):
        s = self._seg(off); return s[3] if s else None
    def shift_at(self, off, loose=False):
        m = self.map(off, loose); return None if m is None else m - off

def translate(v, S, m):
    for lo, hi, vb, fa, fb in S:
        if lo <= v < hi:
            t = m.map(v - vb + fa)
            return None if t is None else t - fb + vb
    return None

# ---------------------------------------------------------------- build
def build(v, log=print, passes=4):
    A, B = img("V021"), img(v)
    REG = region_pairs(v)
    # FW.021 code = function bodies (switch tables excluded)
    codeA = []
    for nm, alo, ahi, blo, bhi, cpu, moved in REG:
        if cpu: codeA += [(s, e) for s, e, n in functions(cpu) if not n.startswith("switchdata") and alo <= s and e <= ahi]
    codeA.sort(); inA_s = [r[0] for r in codeA]
    def acode(o):
        i = bisect.bisect_right(inA_s, o) - 1
        return i >= 0 and o < codeA[i][1]
    X0 = bytearray(A)
    for s, e in codeA: normalise(X0, s, e)
    m = None; codeB = []; seeds = []
    for rnd in range(passes + 4):          # extra passes only while votes still add seeds
        t0 = time.time()
        X = bytearray(X0); Y = bytearray(B)
        if m is not None:
            # data words of FW.021 replaced by the value their address translation predicts in the older file
            S = spaces(v); nt = 0
            for nm, alo, ahi, blo, bhi, cpu, moved in REG:
                if not nm.startswith("leon"): continue
                for p in range(alo, ahi - 3, 4):
                    if acode(p): continue
                    w = struct.unpack_from(">I", A, p)[0]; t = translate(w, S, m)
                    if t is not None and t != w: struct.pack_into(">I", X, p, t); nt += 1
            # older code = images of the FW.021 function bodies under the previous map
            codeB = []
            for s, e in codeA:
                p = s
                while p < e:
                    q = m.map(p, loose=True)
                    if q is None: p += 4; continue
                    r = p
                    while r < e and m.map(r, loose=True) == q + (r - p): r += 4
                    codeB.append((q, q + (r - p))); p = r
        else:
            codeB = first_codeB(A, B, X0, REG)
        codeB = merge_ranges(codeB)
        for s, e in codeB: normalise(Y, s - s % 4, e)
        inB_s = [r[0] for r in codeB]
        def bcode(o, codeB=codeB, inB_s=inB_s):
            i = bisect.bisect_right(inB_s, o) - 1
            return i >= 0 and o < codeB[i][1]
        Xb, Yb, X0b = bytes(X), bytes(Y), bytes(X0)
        all_blocks = []
        for nm, alo, ahi, blo, bhi, cpu, moved in REG:
            if A[alo:ahi] == B[blo:bhi]:
                all_blocks.append((nm, [(alo, blo, ahi - alo)], moved)); continue
            fb = function_blocks(Xb, Yb, alo, ahi, blo, bhi, cpu) if cpu else []
            sb = [x for x in seeds if alo <= x[0] < ahi and blo <= x[1] < bhi]
            fb = sb + fb
            kb = find_blocks(Xb, Yb, alo, ahi, blo, bhi, 32, 32)
            # also untranslated anchors (bitmap / number words that merely look like addresses), but only where no
            # translated anchor lies: an evenly stepping address table is raw-identical to itself one entry off
            rb = find_blocks(X0b, Yb, alo, ahi, blo, bhi, 32, 32) if m is not None else []
            blocks = select_global(fb, kb, rb)
            moved = True
            for k, ml in ((16, 16), (8, 8)):
                new = []
                for (a0, b0, n0), (a1, b1, n1) in gaps(blocks, alo, ahi, blo, bhi, moved):
                    new += chain(find_blocks(Xb, Yb, a0 + n0, a1, b0 + n0, b1, k, ml))
                blocks = sorted(blocks + new)
                if not moved: blocks = chain(blocks)
            all_blocks.append((nm, blocks, moved))
        Sp = spaces(v); mt = m if m is not None else Map(v, classify(A, B, Xb, Yb, all_blocks, [], acode), REG)
        extra = []
        for (nm, alo, ahi, blo, bhi, cpu, _), (_, bl, moved) in zip(REG, all_blocks):
            for (a0, b0, n0), (a1, b1, n1) in gaps(bl, alo, ahi, blo, bhi, moved):
                dl = (b0 - a0) if n0 else (b1 - a1)
                extra += gap_words(A, B, Xb, Yb, a0 + n0, a1, b0 + n0, b1, dl, acode, bcode, Sp, mt)
        segs = classify(A, B, Xb, Yb, all_blocks, extra, acode)
        m = Map(v, segs, REG)
        old = {x[0]: x for x in seeds}
        new = vote_seeds(A, B, Xb, Yb, m, acode, Sp, log)
        for x in new: old[x[0]] = x
        seeds = sorted(old.values())
        log(f"{v} pass {rnd + 1}: {len(segs)} segments, {sum(s[2] for s in segs if s[3] != 'P'):#x} bytes mapped, "
            f"{time.time() - t0:.1f}s")
        if rnd + 1 >= passes and not new: break
    m.segs = verify_calls(A, B, m, acode, log)
    m._a = [s[0] for s in m.segs]
    m.segs = verify_addresses(A, B, m, spaces(v), log)
    m._a = [s[0] for s in m.segs]
    m.segs = verify_sethi(A, B, m, acode, spaces(v), log)
    m._a = [s[0] for s in m.segs]
    m._a = [s[0] for s in m.segs]
    return m

def vote_seeds(A, B, X, Y, m, acode, S, log):
    """function starts re-anchored by evidence: calls (mapped call word -> its older target) and stored addresses
    (mapped data word -> the older function its value names) vote for the older position of each FW.021 function
    start. A start whose votes (>= 2, >= 80 % agreeing) contradict the map becomes a seed block for the next pass
    (seed = maximal run of equal normalised words from the voted start, >= 8 bytes)."""
    from collections import Counter, defaultdict
    starts = set()
    for cpu in ("leon2m", "leon2s"):
        starts |= {s for s, e, n in functions(cpu) if not n.startswith("switchdata")}
    votes = defaultdict(Counter)
    inv = [(lo, hi, vb, fa, fb) for lo, hi, vb, fa, fb in S]
    for a, b, n, k in m.segs:
        p0 = a + (-a) % 4
        for p in range(p0, a + n - 3, 4):
            q = b + (p - a)
            if q % 4: break
            wa = struct.unpack_from(">I", A, p)[0]; wb = struct.unpack_from(">I", B, q)[0]
            if acode(p):
                if k != "P" and wa >> 30 == 1 and wb >> 30 == 1:
                    ta = call_target(A, p)
                    if ta in starts: votes[ta][call_target(B, q)] += 1
                continue
            for lo, hi, vb, fa, fb in inv:
                if lo <= wa < hi:
                    ta = wa - vb + fa
                    if ta in starts and lo <= wb < hi + 0x10000: votes[ta][wb - vb + fb] += 1
                    break
    seeds = []; moved = 0
    for ta, c in votes.items():
        tb, cnt = c.most_common(1)[0]; tot = sum(c.values())
        if cnt < 2 or cnt < 0.8 * tot or tb is None or m.map(ta) == tb: continue
        xa = bytearray(A[ta:ta + 0x4000]); normalise(xa, 0, len(xa) & ~3)
        yb = bytearray(B[tb:tb + 0x4000]); normalise(yb, 0, len(yb) & ~3)
        n = 0
        while n + 4 <= min(len(xa), len(yb)) and xa[n:n + 4] == yb[n:n + 4]: n += 4
        if n >= 8: seeds.append((ta, tb, n)); moved += 1
    log(f"{m.version} vote seeds: {moved} function starts re-anchored by calls / stored addresses")
    return seeds

def merge_ranges(r):
    out = []
    for s, e in sorted(r):
        if out and s <= out[-1][1]: out[-1][1] = max(out[-1][1], e)
        else: out.append([s, e])
    return [tuple(x) for x in out]

def first_codeB(A, B, X0, REG):
    """first pass: older code stretches from whole-function anchors (each FW.021 function searched normalised in the
    older region; hits unique on both sides); per FW.021 function the image is taken directly"""
    out = []
    for nm, alo, ahi, blo, bhi, cpu, moved in REG:
        if not cpu or A[alo:ahi] == B[blo:bhi]: continue
        Yall = bytearray(B[blo:bhi]); normalise(Yall, 0, len(Yall)); Yall = bytes(Yall)
        keys = {}
        for s, e, n in functions(cpu):
            if s < alo or e > ahi or e - s < 16 or n.startswith("switchdata"): continue
            keys.setdefault(bytes(X0[s:e]), []).append((s, e))
        for key, lst in keys.items():
            if len(lst) != 1: continue
            j = Yall.find(key)
            while j != -1 and j % 4: j = Yall.find(key, j + 1)
            if j < 0: continue
            j2 = Yall.find(key, j + 4)
            while j2 != -1 and j2 % 4: j2 = Yall.find(key, j2 + 1)
            if j2 != -1: continue
            out.append((blo + j, blo + j + len(key)))
    return out

def gaps(blocks, alo, ahi, blo, bhi, moved=False):
    """consecutive block pairs (in FW.021 order) whose older positions are in order too: the gaps to fill.
    moved regions (blocks may cross): only gaps of comparable size on both sides"""
    edges = [(alo, blo, 0)] + sorted(blocks) + [(ahi, bhi, 0)]
    out = []
    for (a0, b0, n0), (a1, b1, n1) in zip(edges, edges[1:]):
        ga, gb = a1 - a0 - n0, b1 - b0 - n0
        if ga <= 0 or gb <= 0: continue
        if moved and (gb > 4 * ga + 1024 or ga > 4 * gb + 1024): continue
        out.append(((a0, b0, n0), (a1, b1, n1)))
    return out

def select_global(first, blocks, later=(), keep_moved=1024, minlen=32):
    """reorder-tolerant selection: the whole-function matches and seeds first, then the longest blocks, then the
    `later` blocks; no overlap in either file (a block that overlaps taken ones is cut to its free parts of at least
    minlen bytes). Then the heaviest in-order chain is taken; a block off that chain (a moved block) is kept only
    when it is a whole-function match / seed or at least keep_moved bytes long (near-identical twin functions
    otherwise pair with the wrong twin)."""
    TA, TB = [], []          # taken intervals, sorted, non-overlapping: [start, end)
    def hits(T, x, e):
        i = bisect.bisect_left(T, (e,)) - 1; out = []
        while i >= 0 and T[i][1] > x:
            if T[i][0] < e: out.append(T[i])
            i -= 1
        return out
    out = []; strong = set()
    for cls, lst in ((0, list(first)), (1, sorted(blocks, key=lambda x: -x[2])), (2, sorted(later, key=lambda x: -x[2]))):
        for a, b, n in lst:
            d = b - a
            cuts = [(x, y) for x, y in hits(TA, a, a + n)] + [(x - d, y - d) for x, y in hits(TB, b, b + n)]
            pieces = [(a, a + n)]
            for x, y in cuts:
                nxt = []
                for p, q in pieces:
                    if y <= p or x >= q: nxt.append((p, q)); continue
                    if x > p: nxt.append((p, x))
                    if y < q: nxt.append((y, q))
                pieces = nxt
            for p, q in pieces:
                if cls == 0 and (p, q) != (a, a + n): continue      # strong blocks only whole
                if q - p < (8 if cls == 0 else minlen): continue
                bisect.insort(TA, (p, q)); bisect.insort(TB, (p + d, q + d))
                out.append((p, p + d, q - p))
                if cls == 0: strong.add((p, p + d, q - p))
    on = set(chain(out, lambda x: x[2] + (1 << 24 if x in strong else 0)))
    return sorted(x for x in out if x in on or x in strong or x[2] >= keep_moved)

def function_blocks(X, Y, alo, ahi, blo, bhi, cpu):
    """whole FW.021 functions (normalised, >= 16 bytes, body unique among FW.021 functions) found exactly once in the
    older region (4-aligned)"""
    keys = {}
    for s, e, n in functions(cpu):
        if s < alo or e > ahi or e - s < 16 or n.startswith("switchdata"): continue
        keys.setdefault(X[s:e], []).append(s)
    Yr = Y[blo:bhi]; out = []
    for key, lst in keys.items():
        if len(lst) != 1: continue
        j = Yr.find(key)
        while j != -1 and j % 4: j = Yr.find(key, j + 1)
        if j < 0: continue
        j2 = Yr.find(key, j + 4)
        while j2 != -1 and j2 % 4: j2 = Yr.find(key, j2 + 1)
        if j2 != -1: continue
        out.append((lst[0], blo + j, len(key)))
    return sorted(out, key=lambda x: -x[2])

def classify(A, B, X, Y, blocklists, extra, acode):
    """segments [a, b, n, kind] from the matched blocks plus the gap word pairs"""
    segs = []
    for nm, bl, moved in blocklists:
        for a, b, n in bl:
            p = 0
            while p < n:
                if A[a + p] == B[b + p]:
                    q = p
                    while q < n and A[a + q] == B[b + q]: q += 1
                    segs.append([a + p, b + p, q - p, "S"]); p = q; continue
                w = (a + p) & ~3; d = w - a
                if d >= 0 and d + 4 <= n and (b + d) % 4 == 0 and X[w:w + 4] == Y[b + d:b + d + 4]:
                    kd = "C" if acode(w) else ("A" if X[w:w + 4] != A[w:w + 4] else None)
                    if kd:
                        while segs and segs[-1][0] + segs[-1][2] > w:
                            s = segs[-1]; cut = s[0] + s[2] - w
                            if cut >= s[2]: segs.pop()
                            else: s[2] -= cut
                        segs.append([w, b + d, 4, kd]); p = d + 4; continue
                p += 1          # unexplained difference: byte stays unmapped
    for a, b, kd in extra: segs.append([a, b, 1, "S"] if kd == "S1" else [a, b, 4, kd])
    segs.sort()
    out = []
    for s in segs:
        if out and s[0] < out[-1][0] + out[-1][2]: continue
        if out and out[-1][3] == s[3] and out[-1][0] + out[-1][2] == s[0] and out[-1][1] + out[-1][2] == s[1]:
            out[-1][2] += s[2]
        else: out.append(list(s))
    # one older byte never belongs to two FW.021 bytes: where segments overlap in the older file, keep the stronger
    # (S/C/A before P, then the longer) and drop the other
    rank = {"S": 0, "C": 0, "A": 1, "P": 2}
    byb = sorted(range(len(out)), key=lambda i: out[i][1]); drop = set(); last = None
    for i in byb:
        if last is not None and out[i][1] < out[last][1] + out[last][2]:
            x, y = out[last], out[i]
            loser = i if (rank[y[3]], -y[2]) >= (rank[x[3]], -x[2]) else last
            drop.add(loser)
            if loser == last: last = i
            continue
        last = i
    return [s for i, s in enumerate(out) if i not in drop]

def call_target(d, p):
    """file offset of the target of the call word at file offset p (None when outside the known code spaces)"""
    w = struct.unpack_from(">I", d, p)[0]
    disp = 4 * ((w & 0x3fffffff) - ((w & 0x20000000) << 1))
    if 0x50000 <= p < 0xD0000: pc = p - 0x50000 + 0xA0060000                      # leon2s
    elif 0xD0000 <= p < 0xD8000: pc = p - 0xD0000 + 0xA0028000                     # leon2m start-up code
    elif p >= 0x108000: pc = p - 0x108000                                          # leon2m code window
    else: return None
    t = (pc + disp) & 0xffffffff
    if 0xA0060000 <= t < 0xA00E0000: return t - 0xA0060000 + 0x50000
    if 0x9F150000 <= t < 0x9F1D0000: return t - 0x9F150000 + 0x50000             # leon2s, 0xF10000 below
    if 0xA0028000 <= t < 0xA0030000: return t - 0xA0028000 + 0xD0000
    if 0x40088000 <= t < 0x40090000: return t - 0x40088000 + 0xD0000
    if t < 0x1B0000 and p >= 0xD0000: return t + 0x108000
    return None

def verify_addresses(A, B, m, S, log):
    """A words re-checked against the final map: the older word must equal the translation of the FW.021 value"""
    ok = bad = 0; out = []
    for sg in m.segs:
        if sg[3] != "A": out.append(sg); continue
        a, b, n, _ = sg; cur = None
        for p in range(0, n, 4):
            t = translate(struct.unpack_from(">I", A, a + p)[0], S, m)
            kd = "A" if t is not None and t == struct.unpack_from(">I", B, b + p)[0] else "P"
            if kd == "A": ok += 1
            else: bad += 1
            if cur and cur[3] == kd and cur[0] + cur[2] == a + p: cur[2] += 4
            else:
                cur = [a + p, b + p, 4, kd]; out.append(cur)
    log(f"{m.version} A words re-checked on the final map: {ok} hold, {bad} no longer hold (-> P)")
    return out

def verify_sethi(A, B, m, acode, S, log):
    """C words that are a sethi or its %lo partner: the address they build (sethi + the next simm13 use of the same
    register within 8 words, both inside FW.021 code) is translated through the map; when the translation exists and
    differs from the address the older pair builds, both words -> P (wrong twin / changed reference)"""
    ok = unv = bad = 0; down = set()
    for a, b, n, k in m.segs:
        if k != "C": continue
        for p in range(0, n, 4):
            wa = struct.unpack_from(">I", A, a + p)[0]
            if not (wa >> 30 == 0 and (wa >> 22) & 7 == 4): continue
            r = (wa >> 25) & 31
            for d in range(4, 36, 4):
                pa = a + p + d
                if not acode(pa): break
                w2 = struct.unpack_from(">I", A, pa)[0]
                if w2 >> 30 in (2, 3) and (w2 >> 13) & 1 and (w2 >> 14) & 31 == r:
                    qa, qb = m.map(a + p), m.map(pa)
                    if qa is None or qb is None or qb - qa != d: break
                    wb = struct.unpack_from(">I", B, qa)[0]; w2b = struct.unpack_from(">I", B, qb)[0]
                    sx = lambda x: (x & 0x1fff) - ((x & 0x1000) << 1)
                    va = ((wa & 0x3fffff) << 10) + sx(w2) & 0xffffffff
                    vb = ((wb & 0x3fffff) << 10) + sx(w2b) & 0xffffffff
                    t = translate(va, S, m)
                    if t is None: unv += 1
                    elif t == vb: ok += 1
                    else: bad += 1; down |= {a + p, pa}
                    break
                if w2 >> 30 == 0 and (w2 >> 22) & 7 == 4 and (w2 >> 25) & 31 == r: break   # register set again
    out = []
    for sg in m.segs:
        if sg[3] != "C" or not any(sg[0] <= x < sg[0] + sg[2] for x in down): out.append(sg); continue
        a, b, n, _ = sg; cur = None
        for p in range(0, n, 4):
            kd = "P" if a + p in down else "C"
            if cur and cur[3] == kd and cur[0] + cur[2] == a + p: cur[2] += 4
            else: cur = [a + p, b + p, 4, kd]; out.append(cur)
    log(f"{m.version} sethi/%lo address pairs in C words: translate to the older pair {ok}, not translatable {unv}, "
        f"contradicted {bad} (-> P)")
    return out

def verify_calls(A, B, m, acode, log):
    """C words that are calls: the call target must map to the older call's target; a contradicted call -> P"""
    ok = unv = bad = 0; out = []
    for s in m.segs:
        if s[3] != "C": out.append(s); continue
        a, b, n, _ = s; cur = None
        for p in range(0, n, 4):
            wa = struct.unpack_from(">I", A, a + p)[0]; wb = struct.unpack_from(">I", B, b + p)[0]; kd = "C"
            if wa >> 30 == 1 and wa != wb:
                ta, tb = call_target(A, a + p), call_target(B, b + p)
                mt = None if ta is None else m.map(ta)
                if mt is None: unv += 1
                elif mt == tb: ok += 1
                else: bad += 1; kd = "P"
            if cur and cur[3] == kd and cur[0] + cur[2] == a + p: cur[2] += 4
            else:
                cur = [a + p, b + p, 4, kd]; out.append(cur)
    log(f"{m.version} calls in C words: target maps to the older target {ok}, target unmapped {unv}, contradicted {bad} (-> P)")
    return out

def gap_words(A, B, X, Y, alo, ahi, blo, bhi, dl, acode, bcode, S, m, maxw=20000):
    """word pairs inside one gap: [(a, b, kind)] with kind S/C/A/P (4 bytes) or S1 (1 byte)"""
    pairs = []
    if ahi - alo == bhi - blo and ahi - alo <= 1024:
        # same shift on both sides: identical bytes that no aligned word covers (unaligned ends, odd phase)
        a0 = (alo + 3) & ~3; aligned_b = (a0 + (blo - alo)) % 4 == 0
        for p in range(alo, ahi):
            if aligned_b and a0 <= p < a0 + ((ahi - a0) // 4) * 4: continue
            if A[p] == B[p + blo - alo]: pairs.append((p, p + blo - alo, "S1"))
    a0 = (alo + 3) & ~3
    b0 = blo + ((a0 + dl - blo) % 4)          # older words at the phase of the left neighbour block
    na = (ahi - a0) // 4; nb = (bhi - b0) // 4
    if na <= 0 or nb <= 0 or na > maxw or nb > maxw: return pairs
    Aw = [struct.unpack_from(">I", A, a0 + 4 * i)[0] for i in range(na)]
    Bw = [struct.unpack_from(">I", B, b0 + 4 * i)[0] for i in range(nb)]
    aligned = b0 % 4 == 0
    bset = set(Bw)
    Atk, Tr = [], []; anycode = False
    for i, w in enumerate(Aw):
        p = a0 + 4 * i
        if acode(p):
            n = struct.unpack_from(">I", X, p)[0]; anycode = True
            Atk.append(w if n == w else ("c", n)); Tr.append(None); continue
        t = translate(w, S, m) if aligned else None
        Tr.append(t)
        Atk.append(t if (t is not None and t != w and t in bset) else w)
    # older side: words that normalisation changes become ("c", normalised) tokens; the gap is normalised on the
    # fly when FW.021 has code in it (the older code stretches of this pass may not cover it)
    Bn = Bw
    if anycode and aligned:
        tmp = bytearray(B[b0:b0 + 4 * nb]); normalise(tmp, 0, len(tmp))
        Bn = [struct.unpack_from(">I", tmp, 4 * j)[0] for j in range(nb)]
    elif aligned:
        Bn = [struct.unpack_from(">I", Y, b0 + 4 * j)[0] for j in range(nb)]
    Btk = [Bw[j] if Bn[j] == Bw[j] else ("c", Bn[j]) for j in range(nb)]
    def emit(i, j):
        p, q = a0 + 4 * i, b0 + 4 * j
        if Aw[i] == Bw[j]: pairs.append((p, q, "S"))
        elif aligned and isinstance(Atk[i], tuple) and Atk[i] == Btk[j]: pairs.append((p, q, "C"))
        elif Tr[i] is not None and Tr[i] == Bw[j] and aligned: pairs.append((p, q, "A"))
        else: pairs.append((p, q, "P"))
    if ahi - alo == bhi - blo and na == nb and na <= 1024:
        # same shift on both sides of the gap: substitutions, not an insertion plus a deletion -> pair by position
        for t in range(na): emit(t, t)
        return pairs
    sm = difflib.SequenceMatcher(None, Atk, Btk, autojunk=False)
    pi, pj = 0, 0
    def informative(t):
        return isinstance(t, tuple) or (0x100 <= t < 0xFFFFFF00)
    big = na > 256 or nb > 256
    good = [b for b in sm.get_matching_blocks()
            if b.size >= (6 if big else 4) or (b.size >= (3 if big else 2) and any(informative(Atk[b.a + t]) for t in range(b.size)))]
    for bk in good + [difflib.Match(na, nb, 0)]:
        li, lj = bk.a - pi, bk.b - pj
        if li == lj and 0 < li <= 64:          # equal-length leftover between two matches: pair by position
            for t in range(li): emit(pi + t, pj + t)
        for t in range(bk.size): emit(bk.a + t, bk.b + t)
        pi, pj = bk.a + bk.size, bk.b + bk.size
    return pairs

# ---------------------------------------------------------------- persistence
def save(m):
    p = ROOT / f"work/refs/vmap_{m.version}.json"
    p.write_text(json.dumps({"version": m.version, "file": FILES[m.version],
                             "regions": [list(r[:5]) + [bool(r[6])] for r in m.regions], "segs": m.segs}, separators=(",", ":")))
    return p

_LOADED = {}
def load(version):
    if version not in _LOADED:
        d = json.loads((ROOT / f"work/refs/vmap_{version}.json").read_text())
        _LOADED[version] = Map(version, [tuple(s) for s in d["segs"]], d["regions"])
    return _LOADED[version]

def stats(m):
    out = []
    for nm, lo, hi in MAPREG:
        cnt = {"S": 0, "C": 0, "A": 0, "P": 0}; nonff_un = 0; un = 0
        i = bisect.bisect_right(m._a, lo) - 1
        i = max(i, 0); pos = lo; A = img("V021")
        cov = bytearray(hi - lo)   # 0 = unmapped
        while i < len(m.segs) and m.segs[i][0] < hi:
            a, b, n, k = m.segs[i]
            s, e = max(a, lo), min(a + n, hi)
            if e > s:
                cnt[k] += e - s
                cov[s - lo:e - lo] = b"\x01" * (e - s)
            i += 1
        for j in range(hi - lo):
            if not cov[j]:
                un += 1
                if A[lo + j] != 0xFF: nonff_un += 1
        out.append((nm, lo, hi, cnt, un, nonff_un))
    return out

def main(argv):
    if not argv: print(__doc__); return
    if argv[0] == "--build":
        vs = argv[1:] or list(OLD)
        for v in vs:
            m = build(v); p = save(m); print(f"wrote {p} ({len(m.segs)} segments)")
        return
    if argv[0] == "--stats":
        for v in OLD:
            m = load(v)
            print(f"== {v}   bytes: S identical, C code masked, A moved address, P paired unexplained (loose only), "
                  f"un = unmapped (non-FF)")
            for nm, lo, hi, c, un, nf in stats(m):
                tot = hi - lo; mapped = c["S"] + c["C"] + c["A"]
                print(f"  {nm:28s} {lo:#08x}-{hi:#08x} mapped {100 * mapped / tot:6.2f}%  S {c['S']:#8x} C {c['C']:#7x} "
                      f"A {c['A']:#6x} P {c['P']:#6x}  un {un:#7x} ({nf:#x})")
        return
    if argv[0] == "--check":
        import runpy; runpy.run_path(str(ROOT / "tools/refs/vmap_check.py"), run_name="__main__"); return
    v = argv[0]; m = load(v); A, B = img("V021"), img(v)
    for s in argv[1:]:
        off = int(s, 0); t = m.map(off); tl = m.map(off, loose=True)
        print(f"{v} {off:#08x} -> {('%#08x' % t) if t is not None else 'None'}  kind {m.kind(off)}  "
              f"shift {m.shift_at(off, True) if tl is not None else None}")
        print(f"   V021 {A[off:off + 16].hex(' ')}")
        if tl is not None: print(f"   {v} {B[tl:tl + 16].hex(' ')}")

if __name__ == "__main__":
    sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
    main(sys.argv[1:])
