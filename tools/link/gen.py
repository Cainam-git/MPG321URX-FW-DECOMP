#!/usr/bin/env python3
"""Linked build of a LEON section (stage A: every piece pinned at its FW.021 address).
Pieces: the link-view object of every C function (.text and its jump-table sections), and generated data files
for every other byte of the section's regions, with a label at every address something refers to and a symbolic
word at every stored address (symbols/<sec>.refs.json). -> work/link/<sec>.ld, work/link/<sec>.elf, a comparison
with the firmware. usage: gen.py leon2m [--shift N]   (--shift: stage B test, see docs/LINKING.md)"""
import json, pathlib, re, struct, subprocess, sys, bisect, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import exact
sys.path.insert(0, str(ROOT / "tools/link")); import secs
FW = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()
sec = sys.argv[1]; L = ROOT / "work/link"; D = L / sec
SHIFT = int(sys.argv[sys.argv.index("--shift") + 1], 0) if "--shift" in sys.argv else 0
AT = int(sys.argv[sys.argv.index("--at") + 1], 0) if "--at" in sys.argv else 0
SEQ = "--seq" in sys.argv          # no pinned addresses in segment W: every piece follows the one before it
PAD = (int(sys.argv[sys.argv.index("--pad") + 1], 0), int(sys.argv[sys.argv.index("--pad") + 2], 0)) if "--pad" in sys.argv else None   # (address of a piece, bytes inserted in front of it)
TAG = f"{sec}.shift" if (SHIFT or SEQ) else sec
inv = json.loads((L / f"inv_{sec}.json").read_text()); symtab = json.loads((L / f"{sec}.symtab.json").read_text())
res = {r["name"]: r for r in json.loads((L / f"{sec}.resolve.json").read_text())}
refs = json.loads((ROOT / f"symbols/{sec}.refs.json").read_text())["refs"]
# segments: (name, run address, file offset, length)
SEGS = secs.SEGS[sec]; MV = sys.argv[sys.argv.index("--move") + 1] if "--move" in sys.argv else secs.MOVE[sec]
def vma(listing): return secs.vma(sec, listing)
def seg_of(a):
    for n, v, f, ln in SEGS:
        if v <= a < v + ln: return n, v, f, ln
    return None
def foff(a): s = seg_of(a); return a - s[1] + s[2]
def v_of_file(o):
    for n, v, f, ln in SEGS:
        if f <= o < f + ln: return o - f + v
    return None
# ---- pieces provided by objects
pieces = []            # (run address, size, input file, input section)
fstart = {}            # run address -> function name (every function-table entry)
for r in inv:
    if r["kind"] != "table": fstart[vma(r["start"])] = r["name"]
extra = json.loads((L / f"{sec}.extra.json").read_text()) if (L / f"{sec}.extra.json").exists() and "--conly" not in sys.argv else []
libr = sorted((e["base"], e["base"] + e["size"]) for e in extra if e["kind"] == "lib")
inlib = set()          # C functions whose bytes are part of a library member that is linked as a whole
for r in inv:
    if r["kind"] != "c": continue
    fn = r["name"]; o = D / f"{fn}.final.o"
    if any(a <= vma(r["start"]) and vma(r["end"]) <= b for a, b in libr): inlib.add(fn); continue
    pieces.append((vma(r["start"]), r["end"] - r["start"], o, ".text"))
    for k in range(1, res[fn]["tables"] + 1):
        s = f".jt.{fn}.{k}"; pieces.append((symtab[s], res[fn]["sections"][s], o, s))
# hand-written assembly functions and toolchain library members (tools/link/extra.py)
psym = {}              # run address of a library member's text -> script symbol placed there
for e in extra:
    pieces.append((e["base"], e["size"], pathlib.Path(e["obj"]), ".text"))
    if e["kind"] == "lib": psym[e["base"]] = f"P_{e['base']:08x}"
pieces.sort()
for a, b in zip(pieces, pieces[1:]): assert a[0] + a[1] <= b[0], ("overlap", a, b)
cover = [(p[0], p[0] + p[1]) for p in pieces]; cs = [c[0] for c in cover]
def in_piece(a):
    i = bisect.bisect_right(cs, a) - 1
    return i >= 0 and a < cover[i][1]
cfun = sorted([(vma(r["start"]), vma(r["end"]), r["name"]) for r in inv if r["kind"] == "c" and r["name"] not in inlib]
              + [(e["base"], e["base"] + e["size"], e["name"] if e["kind"] == "asm" else psym[e["base"]]) for e in extra]); cfs = [x[0] for x in cfun]
def code_expr(a):      # a run address inside a C function -> 'FUN + off', else None
    i = bisect.bisect_right(cfs, a) - 1
    if i >= 0 and a < cfun[i][1]: return cfun[i][2] if a == cfun[i][0] else f"{cfun[i][2]} + {a - cfun[i][0]}"
    return None
# ---- symbols that need a definition outside the C objects
defined = {r["name"] for r in inv if r["kind"] == "c" and r["name"] not in inlib} | {s for s in symtab if s.startswith(".jt.")}
want = dict(symtab)
for e in extra:
    if e["kind"] == "asm": defined.add(e["name"])
    else: defined |= {n for n, a in e["defs"]}
    for s_, a_ in e["syms"].items():
        if s_.startswith(".") and not s_.startswith(".jt."): continue       # the object's own section symbols
        if s_ in want and want[s_] != a_: print("CONFLICT", s_, hex(want[s_]), hex(a_), e["name"])
        want[s_] = a_
symtab = want
lib_alias = []          # function-table names of library functions, defined from the member's place
for e in extra:
    if e["kind"] == "lib":
        for nm, off in e["entries"]: lib_alias.append(f"{nm} = {psym[e['base']]} + {off};"); defined.add(nm)
for r in inv:           # a library entry that lies inside another member's text
    if (r["kind"] == "lib" or r["name"] in inlib) and r["name"] not in defined:
        ce = None; a = vma(r["start"]); i = bisect.bisect_right(cfs, a) - 1
        if i >= 0 and a < cfun[i][1]: lib_alias.append(f"{r['name']} = {cfun[i][2]} + {a - cfun[i][0]};"); defined.add(r["name"])
        else: print("library entry without a member:", r["name"])
labels = collections.defaultdict(list)       # run address in a data stretch -> names
assigns = []                                 # linker script assignments
for s, a in symtab.items():
    if s in defined: continue
    q = '"%s"' % s if not re.fullmatch(r"[A-Za-z_.][\w.]*", s) else s
    ce = code_expr(a)
    if ce: assigns.append(f"{q} = {ce};")
    elif seg_of(a): labels[a].append(s)
    else: assigns.append(f"{q} = 0x{a:x};")
# ---- stored addresses inside data stretches
stored = {}
for e in refs:
    a = v_of_file(e["off"])
    if a is None or in_piece(a): continue
    stored[a] = e
tlabel = {}
def target_expr(e):
    t = e["target"]
    if t is None: return None
    tv = v_of_file(t)
    if tv is None: return None
    ce = code_expr(tv)
    if ce: return ce, tv
    tlabel.setdefault(tv, f"L_{tv:08x}")
    return tlabel[tv], tv
exprs = {}
for a, e in stored.items():
    x = target_expr(e)
    if x and x[1] == (e["value"] if seg_of(e["value"]) else x[1]): exprs[a] = x[0]
    elif x: exprs[a] = x[0] + (f" + 0x{(e['value'] - x[1]) & 0xFFFFFFFF:x}" if e["value"] != x[1] else "")
for tv, name in tlabel.items(): labels[tv].append(name)
# ---- data files: every byte of the segments that no object piece provides
dfiles = []
for n, v, f, ln in SEGS:
    a = v; end = v + ln
    stretch = []
    for p in [p for p in pieces if v <= p[0] < end] + [(end, 0, None, None)]:
        if p[0] > a: stretch.append((a, p[0]))
        a = max(a, p[0] + p[1])
    for lo, hi in stretch:
        out = [f'\t.section ".d.{lo:08x}","ax",@progbits']; i = lo
        pts = sorted({x for x in labels if lo <= x < hi} | {x for x in exprs if lo <= x < hi} | {hi})
        for x in pts:
            if x > i:
                b = FW[foff(i):foff(i) + (x - i)]
                for j in range(0, len(b), 16): out.append("\t.byte " + ",".join(str(c) for c in b[j:j + 16]))
                i = x
            if x == hi: break
            for nm in labels.get(x, []): out.append(f'\t.global {nm}\n{nm}:' if re.fullmatch(r"[A-Za-z_.][\w.]*", nm) else f'\t.global "{nm}"\n"{nm}":')
            if x in exprs: out.append(f"\t.long {exprs[x]}"); i = x + 4
        p_ = D / f"data_{lo:08x}.s"; p_.write_text("\n".join(out) + "\n"); dfiles.append((lo, hi - lo, p_))
print(sec, "object pieces:", len(pieces), "data files:", len(dfiles), "labels:", sum(len(v) for v in labels.values()), "stored addresses written symbolically:", len(exprs), "script assignments:", len(assigns))
# assemble the data files
from concurrent.futures import ThreadPoolExecutor
def asm(d):
    r = exact.run(exact.tool("as"), "-Av8", d[2], "-o", d[2].with_suffix(".o"))
    return (d[2].name, r.stderr.strip().splitlines()[-1][:200]) if r.returncode else None
with ThreadPoolExecutor(8) as ex: errs = [e for e in ex.map(asm, dfiles) if e]
print("data assembly errors:", len(errs), errs[:5])
allp = sorted(pieces + [(lo, n, p.with_suffix(".o"), f".d.{lo:08x}") for lo, n, p in dfiles])
sc = ["/* generated by tools/link/gen.py: every piece pinned at its FW.021 address */"]
sc += ["INPUT(" + " ".join(f'"{p}"' for p in sorted({str(x[2]) for x in allp})[i:i + 50]) + ")" for i in range(0, len({str(x[2]) for x in allp}), 50)]
sc.append("SECTIONS {")
def moved(n, a): return a + SHIFT if (SHIFT and n == MV and a >= AT) else a
for n, v, f, ln in SEGS:
    sc.append(f"  .seg{n} 0x{v:x} : {{")
    for a, size, o, s in allp:
        if not (v <= a < v + ln): continue
        if SEQ and n == MV:
            al = 8 if a % 8 == 0 else (4 if a % 4 == 0 else (2 if a % 2 == 0 else 1))
            pos = (f". += {PAD[1]}; " if PAD and PAD[0] == a else "") + (f". = ALIGN({al}); " if al > 1 else "")
        else: pos = f". = 0x{moved(n, a) - v:x}; "
        sc.append(f"    {pos}PA_{a:08x}_{len(sc)} = .; " + (f"{psym[a]} = .; " if a in psym and s == ".text" else "") + f'"{o}"({s})')
    sc.append("  }" if SEQ and n == MV else f"    . = 0x{moved(n, v + ln) - v:x};\n  }}")
sc.append("  /DISCARD/ : { *(*) }\n}")
sc += assigns + lib_alias
(L / f"{TAG}.ld").write_text("\n".join(sc) + "\n")
(L / f"{TAG}.pieces.json").write_text(json.dumps([[a, size, str(o), s_] for a, size, o, s_ in allp]))
r = exact.run(exact.tool("ld"), "-N", "-e", "0", "-T", L / f"{TAG}.ld", "-o", L / f"{TAG}.elf")
print("ld:", r.returncode, r.stderr.strip()[:1500])
if r.returncode == 0:
    tot = diff = 0
    for n, v, f, ln in SEGS:
        b = L / f"{TAG}.{n}.bin"; exact.run(exact.tool("objcopy"), "-O", "binary", "-j", f".seg{n}", L / f"{TAG}.elf", b)
        got = b.read_bytes(); want = FW[f:f + ln]
        if SHIFT or PAD: print(f"segment {n}: {len(got)} bytes built (original {ln})"); continue
        d = [i for i in range(min(len(got), len(want))) if got[i] != want[i]]
        print(f"segment {n}: {len(got)} bytes built, {ln} expected, differing bytes: {len(d)}", [hex(v + x) for x in d[:8]])
        tot += ln; diff += len(d) + abs(len(got) - ln)
    print("TOTAL differing bytes:", diff, "of", tot)
