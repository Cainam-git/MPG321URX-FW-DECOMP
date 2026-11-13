#!/usr/bin/env python3
"""Self-checks of tools/refs/vmap.py (run: python3 -I tools/refs/vmap.py --check  [or this file directly]).
(a) every function start of symbols/leon2m + leon2s .functions.json mapped into each older version: does the target
    look like the same function start (same first word, or first two words equal with address fields masked)?
(b) every 4-byte word of the Leon2M initialised data (file 0x0EC000..0x0F2F38) whose value is exactly a function
    start (window CPU numbering, or start-up code numbering): at the mapped position the older file must hold the
    CPU address of the mapped function start."""
import pathlib, struct, sys
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import vmap

def w(d, o): return struct.unpack_from(">I", d, o)[0]

def norm2(d, o):
    b = bytearray(d[o:o + 8]); vmap.normalise(b, 0, 8); return bytes(b)

def check_a(v, verbose=False):
    m = vmap.load(v); A, B = vmap.img("V021"), vmap.img(v); res = {}
    for cpu in ("leon2m", "leon2s"):
        c = {"same-first-word": 0, "same-masked-2": 0, "differs": 0, "unmapped": 0, "unmapped-loose-only": 0}
        bad = []
        for s, e, n in vmap.functions(cpu):
            if n.startswith("switchdata"): continue
            t = m.map(s)
            if t is None:
                if m.map(s, loose=True) is not None: c["unmapped-loose-only"] += 1
                else: c["unmapped"] += 1
                continue
            if w(A, s) == w(B, t): c["same-first-word"] += 1
            elif norm2(A, s) == norm2(B, t): c["same-masked-2"] += 1
            else: c["differs"] += 1; bad.append((n, s, t))
        res[cpu] = (c, bad)
    return res

def check_b(v):
    m = vmap.load(v); A, B = vmap.img("V021"), vmap.img(v)
    pb = vmap.partitions(B)
    starts = {}
    for s, e, n in vmap.functions("leon2m"):
        if n.startswith("switchdata"): continue
        if s >= 0x108000: starts[s - 0x108000] = s
        else: starts[s - 0xD0000 + 0xA0028000] = s
    ok, bad, unm = 0, [], []
    for o in range(0xEC000, 0xF2F38, 4):
        val = w(A, o)
        if val not in starts: continue
        tgt = starts[val]; mo = m.map(o, loose=True); mt = m.map(tgt)
        if mo is not None and m.map(o + 3, loose=True) != mo + 3: mo = None     # word not mapped as a whole
        if mo is None or mt is None: unm.append((o, val, mo, mt)); continue
        exp = mt - 0x108000 if tgt >= 0x108000 else mt - pb[2][0] + 0xA0028000
        if w(B, mo) == exp: ok += 1
        else: bad.append((o, val, mo, w(B, mo), exp, m.kind(o)))
    return ok, bad, unm

def check_c(v, sec="leon2m"):
    """sure jump-table entries of work/refs/<sec>.refs.json (evidence R1-jumptable): the mapped word must hold the
    older address of the mapped target (kind A, or S with an unmoved target)"""
    import json
    p = vmap.ROOT / f"work/refs/{sec}.refs.json"
    if not p.exists(): return None
    m = vmap.load(v); B = vmap.img(v); S = vmap.spaces(v)
    ok, bad, unm = 0, [], 0
    for e in json.loads(p.read_text()):
        if e["status"] != "sure" or "R1-jumptable" not in e["evidence"]: continue
        o = e["off"]; mo = m.map(o, loose=True); t = vmap.translate(e["value"], S, m)
        if mo is not None and m.map(o + 3, loose=True) != mo + 3: mo = None
        if mo is None or t is None: unm += 1; continue
        if w(B, mo) == t: ok += 1
        else: bad.append((o, e["value"], mo, w(B, mo), t, m.kind(o)))
    return ok, bad, unm

if __name__ == "__main__":
    vs = [a for a in sys.argv[1:] if not a.startswith("-")] or list(vmap.OLD)
    for v in vs:
        r = check_a(v)
        for cpu, (c, bad) in r.items():
            print(f"{v} (a) {cpu}: {c}")
            for n, s, t in bad[:6]: print(f"      differs {n} {s:#x} -> {t:#x}")
        ok, bad, unm = check_b(v)
        print(f"{v} (b) initdata function-start words: pass {ok}, fail {len(bad)}, unmapped {len(unm)}")
        for x in bad[:10]: print("      fail off %#x val %#x -> %#x holds %#x expected %#x kind %s" % x)
        for x in unm[:10]: print("      unmapped off %#x val %#x map %s target-map %s" % x)
        r = check_c(v)
        if r:
            ok, bad, unm = r
            print(f"{v} (c) leon2m sure jump-table entries: pass {ok}, fail {len(bad)}, unmapped {unm}")
            for x in bad[:10]: print("      fail off %#x val %#x -> %#x holds %#x expected %#x kind %s" % x)
