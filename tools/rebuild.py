#!/usr/bin/env python3
"""Rebuild the complete firmware image from source plus the remaining original bytes, and compare it with the
original file (docs/WORKFLOW.md, step 7).

Every function marked matched in symbols/<section>.json is built from src/<section>/ the way its judge builds it,
and its bytes are written at its place in a copy of firmware/MSI_MPG321URX_V021_7F69.bin:
 - LEON C (.c, the recorded cflags, else the section's flag sets as verify.py tries them) and assembly (.S): linked at
   the real address by tools/exact.py; library entries (.lib) from the toolchain archives by tools/libimport.py.
 - 8051 C: Keil C51 with the recorded options, fixups filled by tools/diff8051.py (a module file is compiled once per
   option set); Keil library entries (.lib) from the C51 .LIB files (tools/keillib.py); the start-up code with
   A51 + BL51 (tools/startup8051.py); the entries that STATUS.md lists under other judges with those judges.
Bytes a judge takes from the firmware instead of the build (address fields of jump tables, literal pools and
library members on the LEON side; library fixups, LX51 data addresses and common-entry operands on the 8051 side)
stay original and are counted apart. Bytes outside every matched function stay original. Functions whose build
differs are written anyway, so the comparison shows each differing byte with its function.
usage: rebuild.py [out.bin] [--jobs 4] [--sections leon2m leon2s 8051_bank0 ...]
  default out: build/MSI_MPG321URX_V021_rebuilt.bin; the full report goes next to it (.txt). Exits 1 unless the
  image is byte-identical and every matched function was built and judged exact.
"""
import argparse, json, pathlib, subprocess, sys, threading, time
from concurrent.futures import ThreadPoolExecutor
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import diff8051, exact, keillib, libimport, lx51judge, split, startup8051
FW = ROOT / "firmware" / "MSI_MPG321URX_V021_7F69.bin"
CFG = json.loads((ROOT / "tools" / "config.json").read_text())
PART = {p[0]: (p[1], p[2]) for p in split.PARTS}   # section -> (file offset, length)
LEON = ("leon2m", "leon2s")
BANKS = ("8051_bank0", "8051_bank1", "8051_bank2", "8051_bank3")
# entries judged by another tool than diff8051 (docs/STATUS.md, verification)
LX51 = {("8051_bank2", "FUN_CODE_cee9")}
WINE = threading.Semaphore(2)   # Keil / Wine jobs at a time


def file_off(sec, addr):
    return PART[sec][0] + addr - (exact.BASE[sec] if sec in LEON else 0)


def res(sec, fn, ok, why=None, place=None, kind="source", note=None):
    """place: list of (address, bytes, keep) with keep = offsets inside bytes that stay original"""
    return {"sec": sec, "fn": fn, "ok": ok, "why": why, "place": place or [], "kind": kind, "note": note}


def leon_build(sec, fn, src, fl):
    """(reason or None, placed dict) for one build of a LEON source with one flag set"""
    import tempfile
    pl = {}
    with tempfile.TemporaryDirectory() as td:
        o = pathlib.Path(td) / "x.o"
        cmd = ([exact.tool("as"), "-Av8", src, "-o", o] if src.suffix == ".S" else
               [exact.tool("gcc"), *fl.split(), "-w", "-c", src, "-o", o])
        r = exact.run(*cmd)
        if r.returncode: return "does not build: " + (r.stderr.strip().splitlines() or [""])[-1][:120], pl
        return exact.exact(sec, fn, o, placed=pl), pl


def leon_place(pl):
    raw, fin = pl["raw"], pl.get("final")
    keep = [i for i in range(len(raw)) if fin is not None and raw[i] != fin[i]]
    # jump tables the judge proved entry for entry (tools/exact.py): built from the compiled table's targets
    tabs = [(a, b"".join(v.to_bytes(4, "big") for v in vals), []) for a, vals in pl.get("tables", [])]
    return [(pl["lo"], raw, keep)] + tabs


def leon(sec, fn, entry):
    d = ROOT / "src" / sec
    lib = d / f"{fn}.lib"
    if lib.exists():
        pl = {}
        why = libimport.check_lib(sec, fn, *lib.read_text().split("\n", 1)[0].split(), placed=pl)
        return res(sec, fn, why is None, why, leon_place(pl) if pl else None, "library")
    s, c = d / f"{fn}.S", d / f"{fn}.c"
    if s.exists():
        why, pl = leon_build(sec, fn, s, None)
        return res(sec, fn, why is None, why, leon_place(pl) if pl else None)
    if not c.exists(): return res(sec, fn, False, "no source file")
    rec = entry.get("cflags", CFG[sec]["cflags"])
    why, pl = leon_build(sec, fn, c, rec)
    if why is None: return res(sec, fn, True, None, leon_place(pl))
    others = [f for f in [CFG[sec]["cflags"]] + CFG[sec].get("alt_cflags", []) if f != rec]
    for fl in others:
        w2, p2 = leon_build(sec, fn, c, fl)
        if w2 is None:
            if "cflags" in entry:   # recorded flags fail: place their bytes, name the working set for the record
                return res(sec, fn, False, f"recorded flags '{rec}': {why}; exact with '{fl}'",
                           leon_place(pl) if pl else None)
            return res(sec, fn, True, None, leon_place(p2), note=f"exact only with '{fl}' (no cflags recorded)")
    return res(sec, fn, False, f"'{rec}': {why}", leon_place(pl) if pl else None)


def keil(bank, fn, path, opts):
    with WINE: return diff8051.judge(bank, fn, str(path), opts)


def i8051(bank, fn, entry, lsts):
    d = ROOT / "src" / bank
    lib = d / f"{fn}.lib"
    if lib.exists():
        f = lib.read_text().split("\n", 1)[0].split()
        why = keillib.check(bank, fn, *f)
        seg = keillib.segment(bank, fn, *f)
        if isinstance(seg, str): return res(bank, fn, False, why or seg, kind="library")
        m, sid, start = seg; code = bytes(m["segs"][sid])
        keep = sorted(k for s_, k in m["fix"] if s_ == sid and k < len(code))
        return res(bank, fn, why is None, why, [(start, code, keep)], "library")
    p = d / f"{entry.get('module', fn)}.c"
    if not p.exists(): return res(bank, fn, False, "no source file")
    rec = entry.get("c51opts", CFG["8051"]["c51opts"])
    if (bank, fn) in LX51:
        with WINE: r = lx51judge.judge(bank, fn, str(p), rec)
        if not r.get("ok"): return res(bank, fn, False, "lx51: " + r.get("error", "")[-200:])
        return res(bank, fn, r["match"], None if r["match"] else f"lx51: {r['score']:.1f}%",
                   [(r["start"], bytes.fromhex(r["compiled"]), r["masked_at"])])
    r = keil(bank, fn, p, rec); note = None
    if not r.get("match") and "c51opts" not in entry and entry.get("module", fn) == fn:   # as verify.py: all sets
        for o in [CFG["8051"]["c51opts"]] + CFG["8051"].get("alt_c51opts", []):
            if o == rec: continue
            r2 = keil(bank, fn, p, o)
            if r2.get("match"): r, note = r2, f"exact only with '{o}' (no c51opts recorded)"; break
    if r.get("lst"):
        try: lsts.add(pathlib.Path(r["lst"]).read_text(errors="replace"))
        except OSError: pass
    if not r.get("ok"): return res(bank, fn, False, "does not compile: " + r.get("error", "")[-200:])
    lo = r["span"][0]
    if r.get("match"): return res(bank, fn, True, None, [(lo, bytes.fromhex(r["linked_hex"]), [])], note=note)
    b = bytes.fromhex(r["compiled_hex"])   # not exact: the compiled bytes, fixup operands left original
    why = r.get("exact") or f"{r['score']:.1f}%, {r['len_compiled']} vs {r['len_target']} bytes"
    return res(bank, fn, False, why, [(lo, b, [k for k in r["fixups"] if k < len(b)])])


def startup(bank):
    with WINE: img, ranges, log = startup8051.build(bank, *startup8051.STARTUPS[bank])
    place, miss = [], []
    for lo, hi in ranges:
        place.append((lo, bytes(img.get(a, 0) for a in range(lo, hi)), [a - lo for a in range(lo, hi) if a not in img]))
        miss += [a for a in range(lo, hi) if a not in img]
    return res(bank, "start-up", not miss, f"{len(miss)} bytes not produced" if miss else None, place, "startup")


def common_blocks(bank, fn, start, lsts):
    """a common-entry block that a compiled module places in front of its callee and that covers start"""
    import re
    for txt in lsts:
        for label in sorted(set(re.findall(r"; FUNCTION (L\?\d+) \(BEGIN\)", txt))):
            blk = diff8051.common_entry_block(txt, label, bank)
            if not blk: continue
            base, rows, _ = blk; size = max((o + len(b) for o, b, _ in rows), default=0)
            if not base <= start < base + size: continue
            code, keep = bytearray(size), set(range(size))
            for o, b, fx in rows:
                code[o:o + len(b)] = b; keep -= {o} if fx else set(range(o, o + len(b)))   # fixup operands: original
            return res(bank, fn, True, None, [(base, bytes(code), sorted(keep))], note=f"common-entry block {label}")
    return None


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("out", nargs="?", default=str(ROOT / "build" / "MSI_MPG321URX_V021_rebuilt.bin"))
    ap.add_argument("--jobs", type=int, default=4); ap.add_argument("--sections", nargs="*", default=list(LEON + BANKS))
    a = ap.parse_args(); t0 = time.time()
    fw = FW.read_bytes()
    for sec, (off, ln) in PART.items():
        p = ROOT / "parts" / f"{sec}.bin"
        if not p.exists() or p.read_bytes() != fw[off:off + ln]:
            sys.exit(f"parts/{sec}.bin is missing or differs from the firmware: run tools/split.py first")
    diff8051.MEMO = {}
    jobs, later, data, lsts = [], [], [], {b: set() for b in BANKS}
    for sec in [s for s in BANKS + LEON if s in a.sections]:   # Keil jobs first, so Wine and GCC overlap
        ents = [v for v in json.loads((ROOT / "symbols" / f"{sec}.json").read_text())["functions"].values()
                if v.get("status") == "matched"]
        if sec in startup8051.STARTUPS: jobs.append((startup, (sec,)))
        st = (0, startup8051.STARTUPS[sec][0]) if sec in startup8051.STARTUPS else ()
        fl = {f["name"]: f for f in diff8051.funclist(sec)} if sec in BANKS else {}
        for e in ents:
            fn = e["name"]
            if sec in LEON and e.get("kind") == "jump_table": later.append((sec, e, None)); continue   # built with its function
            if sec in LEON: jobs.append((leon, (sec, fn, e))); continue
            f = fl.get(fn, {})
            if e.get("by") == "data": data.append((sec, fn, f.get("start"), f.get("end"))); continue
            if f.get("start") in st: continue   # reset jump and start-up code: the start-up build above
            if e.get("kind") in ("part", "common_entry"): later.append((sec, e, f)); continue
            d = ROOT / "src" / sec
            if not (d / f"{fn}.lib").exists() and not (d / f"{e.get('module', fn)}.c").exists():
                later.append((sec, e, f)); continue
            jobs.append((i8051, (sec, fn, e, lsts[sec])))
    done = [0]
    def run(j):
        r = j[0](*j[1]); done[0] += 1
        if done[0] % 250 == 0: print(f"  {done[0]}/{len(jobs)} built, {time.time() - t0:.0f} s", file=sys.stderr)
        return r
    with ThreadPoolExecutor(a.jobs) as ex: results = list(ex.map(run, jobs))
    for sec, e, f in later:   # common-entry blocks outside the own segment; others must lie inside a placed span
        if sec in LEON: continue
        r = common_blocks(sec, e["name"], f.get("start", -1), lsts[sec]) if f and e.get("kind") is None else None
        if r: results.append(r)
    img = bytearray(fw); state = bytearray(len(fw))   # 0 original, 1 source, 2 library, 3 kept (address field)
    owner = {}; conflicts = []
    code = {"source": 1, "startup": 1, "library": 2}
    for r in results:
        for lo, b, keep in r["place"]:
            k = set(keep); fo = file_off(r["sec"], lo)
            for i, v in enumerate(b):
                at = fo + i
                if at >= len(img): break
                prev = owner.get(at)
                if i in k:
                    if not state[at]: state[at] = 3
                    owner.setdefault(at, r["fn"]); continue
                if prev and state[at] in (1, 2) and img[at] != v:
                    conflicts.append((r["sec"], at, prev, r["fn"]))
                img[at] = v; state[at] = code[r["kind"]]; owner[at] = r["fn"]
    # pieces judged inside another function's span must be covered by it
    tabs = {sec: {t["name"]: (t["start"], t["end"]) for t in json.loads((ROOT / "symbols" / f"{sec}.functions.json")
            .read_text())["functions"]} for sec in LEON if sec in a.sections}
    for sec, e, f in later:
        if any(r["fn"] == e["name"] and r["sec"] == sec for r in results): continue
        lo, hi = tabs[sec].get(e["name"], (None, None)) if sec in LEON else (f.get("start"), f.get("end"))
        if lo is None or any(not state[file_off(sec, x)] for x in range(lo, hi)):
            results.append(res(sec, e["name"], False, "not covered by a built function"))
    out = pathlib.Path(a.out); out.parent.mkdir(parents=True, exist_ok=True); out.write_bytes(img)

    rep = []
    secs = sorted(PART.items(), key=lambda kv: kv[1][0]); rows = []; pos = 0
    for sec, (off, ln) in secs:
        if off > pos: rows.append(("(other)", pos, off))
        rows.append((sec, off, off + ln)); pos = off + ln
    if pos < len(fw): rows.append(("(other)", pos, len(fw)))
    rep.append(f"{'section':<12} {'file range':<19} {'bytes':>9} {'source':>9} {'library':>9} {'original':>9}"
               f" {'(fields)':>9} {'differ':>7}")
    tot = [0] * 6
    for sec, lo, hi in rows:
        n = [hi - lo, sum(1 for x in state[lo:hi] if x == 1), sum(1 for x in state[lo:hi] if x == 2),
             sum(1 for x in state[lo:hi] if x in (0, 3)), sum(1 for x in state[lo:hi] if x == 3),
             sum(1 for x in range(lo, hi) if img[x] != fw[x])]
        tot = [t + v for t, v in zip(tot, n)]
        rep.append(f"{sec:<12} 0x{lo:06X}-0x{hi:06X} {n[0]:>9,} {n[1]:>9,} {n[2]:>9,} {n[3]:>9,} {n[4]:>9,} {n[5]:>7,}")
    rep.append(f"{'total':<12} {'':<19} {tot[0]:>9,} {tot[1]:>9,} {tot[2]:>9,} {tot[3]:>9,} {tot[4]:>9,} {tot[5]:>7,}")
    rep.append("source = compiled C and assembly, library = toolchain library routines; original includes (fields): "
               "address fields inside built functions that the judges take from the firmware")
    bad = [r for r in results if not r["ok"]]; notes = [r for r in results if r["note"] and r["ok"]]
    rep.append(f"\n{len(results)} built entries, {len(results) - len(bad)} exact; {len(data)} entries recorded as data "
               f"(kept original); {len(conflicts)} overlap conflicts")
    diffs = []; x = 0
    while x < len(fw):
        if img[x] != fw[x]:
            y = x
            while y < len(fw) and img[y] != fw[y]: y += 1
            diffs.append((x, y)); x = y
        else: x += 1
    sec_of = lambda at: next(s for s, lo, hi in rows if lo <= at < hi)
    def where(at):
        s = sec_of(at); o = PART.get(s, (0,))[0]
        return f"{s} 0x{at - o + (exact.BASE[s] if s in LEON else 0):x}" if s in PART else s
    if diffs:
        rep.append(f"\nDIFFERENCES: {sum(y - x for x, y in diffs)} bytes in {len(diffs)} runs")
        for x, y in diffs[:400]:
            rep.append(f"  file 0x{x:06X}+{y - x:<4} {where(x):<26} {owner.get(x, '?')}: rebuilt {img[x:min(y, x + 8)].hex()}"
                       f" original {fw[x:min(y, x + 8)].hex()}")
    if bad:
        rep.append(f"\nNOT EXACT ({len(bad)}):")
        rep += [f"  {r['sec']} {r['fn']}: {r['why']}" for r in sorted(bad, key=lambda r: (r["sec"], r["fn"]))]
    if conflicts:
        rep.append("\nOVERLAP CONFLICTS (two functions place different bytes):")
        rep += [f"  {s} file 0x{at:06X}: {p} / {q}" for s, at, p, q in conflicts[:100]]
    if notes:
        rep.append(f"\nNOTES ({len(notes)}):")
        rep += [f"  {r['sec']} {r['fn']}: {r['note']}" for r in sorted(notes, key=lambda r: (r["sec"], r["fn"]))]
    rep.append("\nRECORDED AS DATA (no source, kept original): " + ", ".join(f"{s} {f}" for s, f, _, _ in data))
    same = img == fw
    rep.append(f"\n{out}: {len(img):,} bytes, file name sum {sum(img) & 0xFFFF:04X}, "
               + ("BYTE-IDENTICAL to the original" if same else "DIFFERS from the original")
               + f"; {time.time() - t0:.0f} s")
    txt = "\n".join(rep) + "\n"
    out.with_suffix(".txt").write_text(txt)
    lines = txt.splitlines()
    short = [l for l in lines if not l.startswith("  ")] if len(lines) > 80 else lines
    print("\n".join(short) + (f"\n(full lists in {out.with_suffix('.txt')})" if short is not lines else ""))
    sys.exit(0 if same and not bad and not conflicts else 1)


if __name__ == "__main__":
    main()
