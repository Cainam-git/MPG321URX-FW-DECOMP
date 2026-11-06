#!/usr/bin/env python3
"""Per-region comparison of one LEON function with the firmware, plus its stack-slot map.

Usage: regions.py <cpu> <function> <file.c|file.o> ... [--flags "-mcpu=v8 -O3 -g"] [--range LO-HI ...]
                  [--min N] [--slots name=off,...] [--brief]

Both sides are normalised by tools/diff.py. The rows are aligned register-blind (registers and numbers masked), and
every firmware row is put into a region by its address. Per region the tool prints:
  fw     firmware instructions in the region
  align  of those, rows that have a register-blind equal row in the compiled code
  exact  of those, rows whose normalised text is also equal (same registers, same constants)
  ours   compiled instructions between the aligned start and end of the region
Regions come from --range (firmware addresses, hex, inclusive start, exclusive end; repeatable) or, without it, from
the firmware listing: the function is cut at basic-block starts (branch targets, rows after an unconditional jump
and its delay slot) into pieces of at least --min instructions (default: a tenth of the function, at least 24).

Stack slots: the firmware's %fp offsets, the compiled code's %fp offsets, and the DWARF location of every named
local of the function in the object. --slots name=off,... names the firmware offset each local should have; the
tool then counts the locals that have it.

A .c file is compiled with --flags (default -mcpu=v8 -O3 -g) into a temporary directory. --brief prints one line
per file.

Library: evaluate(cpu, fn, obj, ranges=None, min_rows=None) -> dict (keys: regions, score, match, exact, align, n_fw,
n_ours); slot_map(obj, fn) -> {name: offset}; fp_offsets(rows) -> set; auto_ranges(cpu, fn, min_rows) -> [(lo, hi)];
build(src, obj, flags) -> bool.
"""
import argparse, difflib, os, pathlib, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import diff

ROOT = pathlib.Path(__file__).resolve().parent.parent
REGS = r'%(?:[goli][0-7]|sp|fp)'
UNCOND = re.compile(r'^(ba?|ba?,a|ret|retl|jmp)\b')


def blind(s):
    return re.sub(r'0x[0-9a-f]+|-?\d+', 'N', re.sub(REGS, 'R', s))


def build(src, obj, flags="-mcpu=v8 -O3 -g", cpu="leon2m"):
    cc = diff.toolchain(cpu) + "gcc"
    return subprocess.run(["nice", "-n", "10", cc, *flags.split(), "-w", "-c", str(src), "-o", str(obj)],
                          stderr=subprocess.DEVNULL).returncode == 0


def auto_ranges(cpu, fn, min_rows=None):
    t = diff.target(cpu, fn)
    if not t: return []
    lo, hi = t[0][0], t[-1][0] + 4
    if min_rows is None: min_rows = max(24, len(t) // 10)
    leaders = set()
    for i, (a, _, ins) in enumerate(t):
        m = re.match(r'^(b\w*|fb\w*)(,a)?\s+(?:0x)?([0-9a-f]+)', ins)
        if m:
            tgt = int(m.group(3), 16)
            if lo <= tgt < hi: leaders.add(tgt)
        if UNCOND.match(ins):
            k = i + (1 if ',a' in ins.split()[0] else 2)
            if k < len(t): leaders.add(t[k][0])
    cuts = [lo]
    for a, _, _ in t:
        if a in leaders and (a - cuts[-1]) // 4 >= min_rows and (hi - a) // 4 >= min_rows // 2:
            cuts.append(a)
    cuts.append(hi)
    return [(cuts[k], cuts[k + 1]) for k in range(len(cuts) - 1)]


def fp_offsets(rows):
    out = set()
    for r in rows:
        for m in re.finditer(r'\[\s*%fp\s*\+?\s*(-?(?:0x[0-9a-f]+|\d+))\s*\]', r):
            out.add(int(m.group(1), 0))
    return out


def slot_map(obj, fn):
    """name -> DW_OP_fbreg offset for the stack-resident locals and parameters of fn (inlined helpers' locals too)"""
    re_ = diff.toolchain("leon2m") + "readelf"
    txt = subprocess.run([re_, "--debug-dump=info", str(obj)], capture_output=True, text=True).stdout
    dies, cur = [], None
    for ln in txt.splitlines():
        h = re.match(r'\s*<(\d+)><([0-9a-f]+)>: Abbrev Number: \d+(?: \((\w+)\))?', ln)
        if h:
            cur = {"depth": int(h.group(1)), "off": int(h.group(2), 16), "tag": h.group(3)}; dies.append(cur); continue
        if cur is None: continue
        n = re.search(r'DW_AT_name\s*:\s*(?:\(indirect string, offset: 0x[0-9a-f]+\):\s*)?(\w+)', ln)
        if n: cur["name"] = n.group(1)
        o = re.search(r'DW_AT_abstract_origin\s*:\s*<(?:0x)?([0-9a-f]+)>', ln)
        if o: cur["origin"] = int(o.group(1), 16)
        y = re.search(r'DW_OP_fbreg: (-?\d+)', ln)
        if y: cur["fbreg"] = int(y.group(1))
    by_off = {d["off"]: d for d in dies}
    name = lambda d: d.get("name") or by_off.get(d.get("origin"), {}).get("name")
    out, inside, d0 = {}, False, 0
    for d in dies:
        if inside and d["depth"] <= d0: inside = False
        if not inside and d["tag"] == "DW_TAG_subprogram" and name(d) == fn: inside, d0 = True, d["depth"]; continue
        if inside and "fbreg" in d and name(d): out.setdefault(name(d), d["fbreg"])
    return out


def evaluate(cpu, fn, obj, ranges=None, min_rows=None):
    t = diff.target(cpu, fn)
    tn, cn, sm, same, total, score, match = diff.compare(cpu, fn, str(obj))
    if ranges is None: ranges = auto_ranges(cpu, fn, min_rows)
    addr = [t[i][0] if i < len(t) else t[-1][0] + 4 * (i - len(t) + 1) for i in range(len(tn))]
    bm = difflib.SequenceMatcher(a=[blind(x) for x in tn], b=[blind(x) for x in cn], autojunk=False)
    pair = {}
    for b in bm.get_matching_blocks():
        for k in range(b.size): pair[b.a + k] = b.b + k
    ops = bm.get_opcodes()

    def mapj(i):   # compiled position of fw row i (start of row)
        for tag, i1, i2, j1, j2 in ops:
            if i1 <= i < i2 or (i == i2 == len(tn)): return j1 + min(i - i1, j2 - j1)
        return len(cn)
    regs = []
    for lo, hi in ranges:
        idx = [i for i in range(len(tn)) if lo <= addr[i] < hi]
        al = [i for i in idx if i in pair]
        ex = [i for i in al if tn[i] == cn[pair[i]]]
        ours = (mapj(idx[-1] + 1) - mapj(idx[0])) if idx else 0
        regs.append({"lo": lo, "hi": hi, "fw": len(idx), "align": len(al), "exact": len(ex), "ours": ours})
    return {"regions": regs, "score": score, "match": match, "exact": sum(r["exact"] for r in regs),
            "align": sum(r["align"] for r in regs), "n_fw": len(tn), "n_ours": len(cn),
            "fw_fp": fp_offsets(tn), "our_fp": fp_offsets(cn)}


def parse_ranges(specs):
    out = []
    for s in specs or []:
        a, b = s.split("-")
        out.append((int(a, 16), int(b, 16)))
    return out or None


def main():
    ap = argparse.ArgumentParser(usage=__doc__.split("\n\n")[1])
    ap.add_argument("cpu"); ap.add_argument("fn"); ap.add_argument("files", nargs="+")
    ap.add_argument("--flags", default="-mcpu=v8 -O3 -g"); ap.add_argument("--range", action="append")
    ap.add_argument("--min", type=int); ap.add_argument("--slots", default="")
    ap.add_argument("--brief", action="store_true")
    a = ap.parse_args()
    want = {k: int(v) for k, v in (x.split("=") for x in a.slots.split(",") if x)}
    ranges = parse_ranges(a.range)
    with tempfile.TemporaryDirectory() as td:
        for f in a.files:
            obj = f
            if f.endswith(".c"):
                obj = os.path.join(td, "r.o")
                if not build(f, obj, a.flags, a.cpu): print("compile error", f); continue
            d = evaluate(a.cpu, a.fn, obj, ranges, a.min)
            sl = slot_map(obj, a.fn)
            good = sum(1 for k, v in want.items() if sl.get(k) == v)
            line = "%6.2f exact %d/%d align %d n %d/%d%s" % (d["score"], d["exact"], d["n_fw"], d["align"], d["n_ours"],
                   d["n_fw"], " MATCH" if d["match"] else "")
            if want: line += " slots %d/%d" % (good, len(want))
            if a.brief:
                print(line, " ".join("%x:%d/%d" % (r["lo"], r["exact"], r["fw"]) for r in d["regions"]), f); continue
            print(f); print(line)
            print("  %-21s %5s %5s %5s %5s" % ("region", "fw", "align", "exact", "ours"))
            for r in d["regions"]:
                print("  %08x-%08x %5d %5d %5d %5d%s" % (r["lo"], r["hi"], r["fw"], r["align"], r["exact"], r["ours"],
                      "" if r["exact"] == r["fw"] == r["ours"] else "  *"))
            print("  fw %fp offsets:   ", " ".join(str(x) for x in sorted(d["fw_fp"])))
            print("  ours %fp offsets: ", " ".join(str(x) for x in sorted(d["our_fp"])),
                  "| missing", sorted(d["fw_fp"] - d["our_fp"]), "extra", sorted(d["our_fp"] - d["fw_fp"]))
            if sl:
                print("  locals (? = offset not used by the fw, ! = not the --slots offset):", " ".join(
                    "%s=%d%s%s" % (k, v, "" if v in d["fw_fp"] else "?", "!" if k in want and want[k] != v else "")
                    for k, v in sorted(sl.items(), key=lambda kv: kv[1])))


if __name__ == "__main__":
    main()
