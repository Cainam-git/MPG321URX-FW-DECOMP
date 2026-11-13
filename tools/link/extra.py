#!/usr/bin/env python3
"""Objects that are not compiled C: the hand-written assembly functions and the toolchain library members of a
LEON section. Places each object's .text at its firmware address and reads every relocation site back from the
firmware, like linkview.py does for the C functions. -> work/link/<sec>.extra.json
usage: extra.py leon2m"""
import json, pathlib, re, struct, subprocess, sys, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import exact, libimport
sys.path.insert(0, str(ROOT / "tools/link")); import secs
sys.path.insert(0, str(ROOT / "tools/link")); import elfsplit
DATASECS = {".rodata", ".data", ".bss", ".rodata.cst4", ".rodata.cst8", ".rodata.cst16", ".rodata.str1.8", ".rodata.str1.1", ".sdata", ".sbss"}
FW = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()
sec = sys.argv[1]; L = ROOT / "work/link"; D = L / sec
inv = json.loads((L / f"inv_{sec}.json").read_text())
def vma(listing): return secs.vma(sec, listing)
def foff(v): return secs.foff(sec, v)
def relocs(obj):
    r = []; cur = None
    for ln in exact.run(exact.tool("objdump"), "-r", obj).stdout.splitlines():
        m = re.match(r"RELOCATION RECORDS FOR \[(\S+)\]", ln)
        if m: cur = m.group(1); continue
        m = re.match(r"^([0-9a-f]{8})\s+(R_SPARC_\w+)\s+(\S+?)(?:\+0x([0-9a-f]+))?\s*$", ln)
        if m: r.append((cur, int(m[1], 16), m[2], m[3], int(m[4] or "0", 16)))
    return r
def sections(obj):
    s = {}
    for m in re.finditer(r"^\s*\[\s*\d+\]\s+(\S+)\s+(\w+)\s+\w+\s+\w+\s+(\w+)\s+\w+\s+(\S*)", exact.run(exact.tool("readelf"), "-SW", obj).stdout, re.M):
        if int(m[3], 16) and "A" in m[4]: s[m[1]] = (int(m[3], 16), m[2])
    return s
def syms(obj):
    out = []
    for m in re.finditer(r"^([0-9a-f]+) (\w) (\S+)$", exact.run(exact.tool("nm"), obj).stdout, re.M): out.append((int(m[1], 16), m[2], m[3]))
    return out
def constraints(obj, base):
    c = collections.defaultdict(list)
    for s, off, typ, symb, add in relocs(obj):
        if s != ".text": continue
        w = struct.unpack(">I", FW[foff(base + off):foff(base + off) + 4])[0]
        if typ in ("R_SPARC_WDISP30", "R_SPARC_WDISP22"):
            bits = 30 if typ.endswith("30") else 22
            d = w & ((1 << bits) - 1)
            if d >> (bits - 1): d -= 1 << bits
            c[symb].append(("abs", add, (base + off + 4 * d) & 0xFFFFFFFF))
        elif typ == "R_SPARC_HI22": c[symb].append(("hi", add, (w & 0x3FFFFF) << 10))
        elif typ == "R_SPARC_LO10": c[symb].append(("lo", add, w & 0x3FF))
        elif typ == "R_SPARC_13": c[symb].append(("s13", add, w & 0x1FFF))
        elif typ == "R_SPARC_32": c[symb].append(("abs", add, w))
        else: c[symb].append(("other:" + typ, add, 0))
    return c
def ok(S, k, add, v):
    x = (S + add) & 0xFFFFFFFF
    return x == v if k == "abs" else ((x & 0xFFFFFC00) == v if k == "hi" else ((x & 0x3FF) == v if k == "lo" else (x & 0x1FFF) == v if k == "s13" else False))
def solve(cs):
    cand = {(v - add) & 0xFFFFFFFF for k, add, v in cs if k == "abs"}
    if not cand:
        for k, add, h in cs:
            if k != "hi": continue
            for k2, add2, l in cs:
                if k2 != "lo": continue
                S = ((h - add) & 0xFFFFFC00) | ((l - add2) & 0x3FF)
                cand |= {S, (S + 0x400) & 0xFFFFFFFF, (S - 0x400) & 0xFFFFFFFF}
    return sorted(S for S in cand if all(ok(S, *x) for x in cs))
out = []; prob = collections.Counter(); ex = collections.defaultdict(list)
seen = {}
for r in inv:
    if r["kind"] == "asm":
        o = D / f"{r['name']}.o"; base = vma(r["start"]); e = {"kind": "asm", "name": r["name"], "obj": str(o), "base": base, "size": sections(o).get(".text", (0,))[0]}
        if e["size"] != r["end"] - r["start"]: prob["asm: size differs"] += 1; ex["asmsize"].append((r["name"], e["size"], r["end"] - r["start"]))
    elif r["kind"] == "lib":
        lib, member, symbol = r["lib"].split()[:3]; o = None
        for vi, arc in enumerate(libimport.archives(lib)):      # the multilib variant whose code is in the firmware
            td = D / "lib" / r["name"] / f"v{vi}"; td.mkdir(parents=True, exist_ok=True)
            subprocess.run([exact.tool("ar"), "x", str(arc), member], cwd=td, capture_output=True)
            cand = td / member
            if not cand.exists(): continue
            sy = syms(cand); off = next((a for a, t, n in sy if n == symbol and t in "TtW"), None)
            if off is None: continue
            base = vma(r["start"]) - off
            tb = td / "text.bin"; exact.run(exact.tool("objcopy"), "-O", "binary", "-j", ".text", cand, tb)
            got = bytearray(tb.read_bytes()); want = bytearray(FW[foff(base):foff(base) + len(got)])
            for s_, ro, typ, symb, add in relocs(cand):
                if s_ == ".text": got[ro:ro + 4] = b"\0\0\0\0"; want[ro:ro + 4] = b"\0\0\0\0"
            # relocated fields are compared by the constraints below; everything else must be identical
            same = sum(1 for a_, b_ in zip(got, want) if a_ == b_)
            if same >= len(got) - 0 and len(got) == len(want): o = cand; arcname = str(arc.relative_to(ROOT)); break
            if same >= 0.98 * len(got) and o is None: o2 = (cand, str(arc.relative_to(ROOT)), same, len(got))
        if o is None: prob["lib: no archive variant gives the firmware's code"] += 1; ex["novariant"].append((r["name"], member, symbol)); continue
        sy = syms(o); off = next((a for a, t, n in sy if n == symbol and t in "TtW"), None)
        base = vma(r["start"]) - off; key = (lib, member, base)
        if key in seen: seen[key]["entries"].append([r["name"], vma(r["start"]) - base]); continue
        sp = o.parent / "split.o"; elfsplit.split(o, sp, r["name"], DATASECS); o = sp
        e = {"kind": "lib", "name": r["name"], "member": f"{lib}:{member}", "archive": arcname, "obj": str(o), "base": base, "size": sections(o).get(".text", (0,))[0], "entries": [[r["name"], vma(r["start"]) - base]],
             "defs": [(n, base + a) for a, t, n in sy if t in "TW"]}
        seen[key] = e
    else: continue
    cs = constraints(o, base); e["sections"] = {k: v[0] for k, v in sections(o).items()}; e["syms"] = {}; e["unsolved"] = []
    for symb, c in cs.items():
        if any(k.startswith("other") for k, _, _ in c): prob["other relocation"] += 1; ex["other"].append((e["name"], symb, c[0][0])); continue
        S = solve(c)
        if len(S) == 1: e["syms"][symb] = S[0]
        else: e["unsolved"].append(symb); prob[f"{e['kind']}: not settled"] += 1; ex["unsettled"].append((e["name"], symb, [hex(x) for x in S][:3], [(k, a, hex(v)) for k, a, v in c[:3]]))
    # identical text?
    tb = L / "tmp_text.bin"; exact.run(exact.tool("objcopy"), "-O", "binary", "-j", ".text", o, tb)
    out.append(e)
(L / f"{sec}.extra.json").write_text(json.dumps(out))
print(sec, collections.Counter(e["kind"] for e in out), "problems:", dict(prob))
for k, v in ex.items(): print(" ", k, len(v), v[:5])
