#!/usr/bin/env python3
"""Link view of the compiled functions of a LEON section, and the address of everything they refer to.

For every C function: take the compiler's assembly (work/link/<sec>/<fn>.s, made by inventory.py with the proven
flags) and rewrite only where things live, not what the compiler generated:
 - debug sections and line directives are dropped;
 - of the function bodies in the file only <fn> itself is kept (copies of neighbours that a source file defines
   so that the compiler can inline them belong to those neighbours' own files);
 - jump tables (.subsection -1) go into their own section .jt.<fn>.<k>, so the linker can place them;
 - labels of the file's own literals (texts, constants, local const arrays) get unique global names
   LIT.<fn>.<label>; mode 'resolve' keeps their definitions, mode 'final' drops them (the firmware's data area
   holds them).
Then, from the 'resolve' object, every relocation site is read back from the firmware image: the address the
firmware uses there is the address of the symbol. -> work/link/<sec>.resolve.json
usage: linkview.py leon2m [--jobs 8]"""
import json, pathlib, re, struct, subprocess, sys, collections
from concurrent.futures import ThreadPoolExecutor
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import exact
sys.path.insert(0, str(ROOT / "tools/link")); import secs
FW = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()
sec = sys.argv[1]; jobs = int(sys.argv[sys.argv.index("--jobs") + 1]) if "--jobs" in sys.argv else 8
D = ROOT / "work/link" / sec
inv = json.loads((ROOT / "work/link" / f"inv_{sec}.json").read_text())

def vma(listing): return secs.vma(sec, listing)       # run address of a listing (Ghidra) address
def foff(v): return secs.foff(sec, v)                 # file offset of a run address
START = {r["name"]: r["start"] for r in inv}
NAMEAT = {r["start"]: r["name"] for r in inv if r["kind"] != "table"}

def canon(fn, text):
    """Names that carry an address (func_0x<address>, FUN_4008....) are replaced by the name of the function they
    mean. As a call target the address was computed from the listing address of the calling function, which for
    the main program of leon2m is 0xA0060000 above the run address (func_0x4008d1a0 called from the main program is
    the start-up routine at 0xA002D1A0); used as a value (function pointer) the name is the run address itself."""
    sh = secs.call_shift(sec, START[fn])
    def name(a):
        a = secs.listing(sec, a & 0xFFFFFFFF)
        return NAMEAT.get(a, f"FUN_{a:08x}")           # the function-table name at that address
    out = []
    for ln in text.split("\n"):
        if "func_0x" in ln or (sec == "leon2m" and "FUN_4008" in ln):
            call = re.match(r"\s*call\b", ln) is not None
            ln = re.sub(r"\b(?:func_0x|FUN_(?=4008))([0-9a-fA-F]{8})\b", lambda m: name(int(m.group(1), 16) - (sh if call else 0)), ln)
        out.append(ln)
    return "\n".join(out)

NUMSYM = json.loads((ROOT / f"symbols/{sec}.numsym.json").read_text()) if (ROOT / f"symbols/{sec}.numsym.json").exists() else {}
def numsym(fn, text):
    """Functions whose C source must write an address as a number to stay byte-exact (symbols/<section>.numsym.json): the
    compiler's 'sethi %hi(N), r' / 'or r, low, r2' pair for that number is rewritten to the symbol."""
    for v, name in NUMSYM.get(fn, []):
        hi, lo = v & ~0x3FF, v & 0x3FF; out = []; regs = set()
        for ln in text.split("\n"):
            m = re.match(r"(\s*sethi\s+%hi\()(\d+)(\),\s*)(%\w+)", ln)
            if m and int(m.group(2)) == hi: regs.add(m.group(4)); ln = f"{m.group(1)}{name}{m.group(3)}{m.group(4)}" + ln[m.end():]
            else:
                m = re.match(r"(\s*or\s+)(%\w+)(,\s*)(\d+)(\s*,.*)", ln)
                if m and m.group(2) in regs and int(m.group(4)) == lo: ln = f"{m.group(1)}{m.group(2)}{m.group(3)}%lo({name}){m.group(5)}"
            out.append(ln)
        assert regs, (fn, hex(v))
        text = "\n".join(out)
    return text

def transform(fn, text, final):
    lines = numsym(fn, canon(fn, text)).split("\n")
    # pass 1: labels defined in literal sections
    cur = ".text"; lit = set()
    for ln in lines:
        m = re.match(r'\s*\.section\s+"?([\w.]+)"?', ln)
        if m: cur = m.group(1); continue
        if cur != ".text" and not cur.startswith(".debug"):
            m = re.match(r"([.\w$]+):", ln)
            if m: lit.add(m.group(1))
    ren = {l: f"LIT.{fn}.{l.lstrip('.')}" for l in lit}
    pat = re.compile("|".join(r"(?<![\w.$])" + re.escape(l) + r"(?![\w$.])" for l in sorted(lit, key=len, reverse=True))) if lit else None
    out = []; cur = ".text"; blk = None; pend = []; k = 0; kept = False
    for ln in lines:
        m = re.match(r'\s*\.section\s+"?([\w.]+)"?', ln)
        if m:
            cur = m.group(1)
            if cur == ".text": out.append('\t.section\t".text"')
            elif not cur.startswith(".debug") and not final: out.append(ln)
            continue
        if cur.startswith(".debug"): continue
        if re.match(r"\s*\.(loc|file|ident)\b", ln): continue
        if cur != ".text":                       # literal section
            if final: continue
            m = re.match(r"([.\w$]+):", ln)
            if m and m.group(1) in ren: out.append(f"\t.global {ren[m.group(1)]}"); out.append(ren[m.group(1)] + ":" + ln[m.end():]); continue
            if re.match(r"\s*\.(type|size)\b", ln): continue
            out.append(ln); continue
        # text
        m = re.match(r"\s*\.type\s+([\w.$]+),\s*#function", ln)
        if m:
            blk = m.group(1)
            if blk == fn: out.extend(pend); kept = True
            pend = []
        if blk is None:
            if re.match(r"\s*\.(align|global|proc)\b", ln): pend.append(ln)
            elif re.match(r"\.LL(e?text)\d+:", ln): pass
            else: pend.append(ln)
            continue
        end = re.match(r"\s*\.size\s+" + re.escape(blk) + r"\b", ln)
        if blk == fn:
            if re.match(r"\s*\.subsection\s+-1", ln): k += 1; ln = f'\t.section\t".jt.{fn}.{k}","ax",@progbits'
            if pat: ln = pat.sub(lambda mm: ren[mm.group(0)], ln)
            out.append(ln)
        if end: blk = None; pend = []
    return "\n".join(out) + "\n", kept, k

def relocs(obj):
    r = []; cursec = None
    for ln in exact.run(exact.tool("objdump"), "-r", obj).stdout.splitlines():
        m = re.match(r"RELOCATION RECORDS FOR \[(\S+)\]", ln)
        if m: cursec = m.group(1); continue
        m = re.match(r"^([0-9a-f]{8})\s+(R_SPARC_\w+)\s+(\S+?)(?:\+0x([0-9a-f]+))?\s*$", ln)
        if m: r.append((cursec, int(m[1], 16), m[2], m[3], int(m[4] or "0", 16)))
    return r

def one(r):
    fn = r["name"]; res = {"name": fn}
    src = (D / f"{fn}.s").read_text()
    for mode in ("resolve", "final"):
        t, kept, k = transform(fn, src, mode == "final")
        if not kept: res["error"] = "function block not found"; return res
        p = D / f"{fn}.{mode}.s"; p.write_text(t)
        x = exact.run(exact.tool("as"), "-Av8", p, "-o", D / f"{fn}.{mode}.o")
        if x.returncode: res["error"] = f"{mode}: " + x.stderr.strip().splitlines()[-1][:160]; return res
    o = D / f"{fn}.resolve.o"
    secs = {}
    for m in re.finditer(r"^\s*\[\s*\d+\]\s+(\S+)\s+(\w+)\s+\w+\s+\w+\s+(\w+)\s+\w+\s+(\S*)", exact.run(exact.tool("readelf"), "-SW", o).stdout, re.M):
        if int(m[3], 16) and "A" in m[4]: secs[m[1]] = int(m[3], 16)
    res["sections"] = secs; res["tables"] = k
    want = r["end"] - r["start"]
    if secs.get(".text", 0) != want: res["error"] = f".text {secs.get('.text', 0)} bytes, listed {want}"; return res
    lo = vma(r["start"]); f0 = foff(lo)
    got = {}
    for s, off, typ, symb, add in relocs(o):
        if s != ".text": continue            # table words and literal sections are placed, not read back here
        w = struct.unpack(">I", FW[f0 + off:f0 + off + 4])[0]
        if typ == "R_SPARC_WDISP30":
            d = w & 0x3FFFFFFF
            if d & 0x20000000: d -= 0x40000000
            got.setdefault((symb, add), {}).setdefault("abs", set()).add((lo + off + 4 * d) & 0xFFFFFFFF)
        elif typ == "R_SPARC_HI22": got.setdefault((symb, add), {}).setdefault("hi", set()).add((w & 0x3FFFFF) << 10)
        elif typ == "R_SPARC_LO10": got.setdefault((symb, add), {}).setdefault("lo", set()).add(w & 0x3FF)
        elif typ in ("R_SPARC_WDISP22", "R_SPARC_WDISP19", "R_SPARC_WDISP16"): pass
        else: got.setdefault((symb, add), {}).setdefault("other", set()).add(typ)
    refs = []
    for (symb, add), g in got.items():
        e = {"sym": symb, "add": add}
        if "other" in g: e["other"] = sorted(g["other"])
        if "abs" in g: e["target"] = sorted(g["abs"])
        if "hi" in g or "lo" in g:
            hi = sorted(g.get("hi", [])); lo_ = sorted(g.get("lo", []))
            e["hi"] = hi; e["lo"] = lo_
        refs.append(e)
    res["refs"] = refs
    return res
todo = [r for r in inv if r["kind"] == "c"]
with ThreadPoolExecutor(jobs) as ex: out = list(ex.map(one, todo))
(ROOT / "work/link" / f"{sec}.resolve.json").write_text(json.dumps(out))
err = [(r["name"], r["error"]) for r in out if "error" in r]
print(sec, len(out), "functions;", len(err), "errors"); print(collections.Counter(re.sub(r"FUN_\w+|\d+", "N", e[1])[:60] for e in err).most_common(8)); print(err[:6])
