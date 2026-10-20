#!/usr/bin/env python3
"""SPARC shape twins: an unmatched function with the same instruction shape as a MATCHED one gets the matched C
with the constants (addresses, call targets, immediates) swapped by position; a match must pass the full judge
(instruction shapes + exact bytes at the real address). Runs per core; the pipeline calls it every round.
usage: twin.py <cpu> [--dry]
"""
import hashlib, json, pathlib, re, subprocess, sys, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import diff
CFG = json.loads((ROOT / "tools" / "config.json").read_text())
GCC = str(ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc")


def shape_and_consts(cpu, fn):
    seq, consts = [], []
    for ln in (ROOT / "asm" / cpu / f"{fn}.s").open():
        m = re.match(r"[0-9a-f]{8}:\s+(?:[0-9a-f]{2} ){4}\s*(\S+)\s*(.*)$", ln)
        if not m: continue
        ops, _, note = m[2].partition("!")
        full = re.findall(r"0x([0-9a-f]{5,8})", note)          # objdump's resolved sethi/or address
        if full: consts.append(int(full[0], 16))
        elif m[1] == "call":
            t = re.search(r"0x([0-9a-f]+)", ops)   # "call %reg" has no target constant
            if t: consts.append(int(t[1], 16))
        elif m[1] == "sethi":
            h = re.search(r"%hi\(0x([0-9a-f]+)\)", ops)
            if h: consts.append(int(h[1], 16))
        else:
            for v in re.findall(r"(?<![\w%])(-?0x[0-9a-f]+|-?\d+)(?![\w(])", ops):
                consts.append(int(v, 0))
        seq.append(m[1] + " " + re.sub(r"0x[0-9a-f]+|-?\b\d+\b|%(hi|lo)\([^)]*\)", "N", ops).strip())
    return "|".join(seq), consts


def swap(src, old, new):
    if len(old) != len(new): return None
    pairs = {}
    for o, n in zip(old, new):
        if o != n and pairs.setdefault(o, n) != n: return None
    for o, n in sorted(pairs.items(), key=lambda kv: -abs(kv[0])):
        if o >= 0x10000:   # an address: names and literals
            src = re.sub(r"\b((?:FUN|DAT|PTR|ARR|LAB|s|u)_)%08x\b" % o, lambda m: f"{m.group(1)}{n:08x}", src, flags=re.I)
            src = re.sub(r"(?i)\b0x0*%x\b" % o, "0x%x" % n, src)
            src = re.sub(r"\b_?DAT_%08x\b" % o, lambda m: m.group(0).replace("%08x" % o, "%08x" % n), src)
        else:
            src = re.sub(r"(?i)(?<![\w.])0x0*%x(?![\w.])" % abs(o), "0x%x" % abs(n), src) if abs(o) > 9 else src
            src = re.sub(r"(?<![\w.])%d(?![\w.])" % o, str(n), src) if abs(o) > 9 else src
    return src


AS = str(ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-as")


def judge_asm(cpu, fn, src):
    with tempfile.TemporaryDirectory() as td:
        a = pathlib.Path(td) / f"{fn}.S"; o = pathlib.Path(td) / "x.o"; a.write_text(src)
        r = subprocess.run([AS, "-Av8", str(a), "-o", str(o)], capture_output=True)
        return r.returncode == 0 and diff.compare(cpu, fn, str(o))[6]


def judge(cpu, fn, src, entry):
    with tempfile.TemporaryDirectory() as td:
        c = pathlib.Path(td) / f"{fn}.c"; o = pathlib.Path(td) / "x.o"; c.write_text(src)
        for fl in ([entry["cflags"]] if entry.get("cflags") else []) + [CFG[cpu]["cflags"]] + CFG[cpu].get("alt_cflags", []):
            r = subprocess.run([GCC, *fl.split(), "-w", "-c", str(c), "-o", str(o)], capture_output=True)
            if r.returncode == 0 and diff.compare(cpu, fn, str(o))[6]: return fl
    return None


def main():
    cpu = sys.argv[1]; dry = "--dry" in sys.argv
    sp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(sp.read_text()); byname = {v["name"]: (k, v) for k, v in sym["functions"].items()}
    memo_p = ROOT / "work" / f"{cpu}-twin-tried.json"; memo = json.loads(memo_p.read_text()) if memo_p.exists() else {}
    groups = {}
    for p in sorted((ROOT / "asm" / cpu).glob("*.s")):
        sh, cs = shape_and_consts(cpu, p.stem); groups.setdefault(sh, []).append((p.stem, cs))
    (ROOT / "work" / f"{cpu}-shapes.json").write_text(json.dumps({fn: sh for sh, ms in groups.items() for fn, _ in ms}))   # shape of every function (finds similar examples)
    # how many unmatched functions share each unmatched function's shape (a match there cascades)
    weights = {fn: sum(1 for f2, _ in members if byname.get(f2, (0, {}))[1].get("status") != "matched")
               for members in groups.values() if len(members) > 1 for fn, _ in members if byname.get(fn, (0, {}))[1].get("status") != "matched"}
    (ROOT / "work" / f"{cpu}-twin-groups.json").write_text(json.dumps({k: v for k, v in weights.items() if v > 1}, indent=0))
    got = []
    for sh, members in groups.items():
        matched = [(fn, cs) for fn, cs in members if byname.get(fn, (0, {}))[1].get("status") == "matched"
                   and ((ROOT / "src" / cpu / f"{fn}.c").exists() or (ROOT / "src" / cpu / f"{fn}.S").exists())]
        if not matched or len(members) == 1: continue
        for fn, cs in members:
            if byname.get(fn, (0, {}))[1].get("status") == "matched": continue
            for mfn, mcs in matched:
                asm = not (ROOT / "src" / cpu / f"{mfn}.c").exists()   # hand-written assembly twin: same text, constants swapped
                st = (ROOT / "src" / cpu / f"{mfn}.{'S' if asm else 'c'}").read_text()
                body = st if asm else re.sub(r"/\*.*?\*/\s*", "", st, count=1, flags=re.S)
                src = swap(body, mcs, cs)
                if src is None: continue
                src = re.sub(r"\b%s\b" % re.escape(mfn), fn, src)
                if asm: src = re.sub(r"@ 0x[0-9a-f]{8}", f"@ 0x{fn[-8:]}", src)
                h = hashlib.sha1(src.encode()).hexdigest()
                if memo.get(fn) == h: continue
                memo[fn] = h
                fl = ("sparc-elf-as -Av8" if judge_asm(cpu, fn, src) else None) if asm else judge(cpu, fn, src, byname.get(mfn, (0, {}))[1])
                if not fl: continue
                got.append((fn, mfn))
                if not dry:
                    key = next((k for k, v in sym["functions"].items() if v.get("name") == fn), f"ram:{fn[-8:]}")
                    if asm:
                        (ROOT / "src" / cpu / f"{fn}.S").write_text(src)
                        sym["functions"][key] = {"name": fn, "status": "matched", "by": "asm", "comment": f"twin of {mfn}: identical hand-written assembly, constants swapped"}
                    else:
                        body = re.sub(r"[ \t]*/\*.*?\*/", "", src, flags=re.S)   # the original's comments describe the original's constants
                        (ROOT / "src" / cpu / f"{fn}.c").write_text(f"/* {cpu} {fn} @ 0x{fn[-8:]}  MATCH ({fl}, twin)\n * Twin of {mfn}: same code, constants swapped; byte-exact.\n * See {mfn} for the explanation; this copy's constants differ, so its comments were removed.\n */\n" + body)
                        sym["functions"][key] = {"name": fn, "status": "matched", "by": "twin", "cflags": fl, "comment": f"twin of {mfn} (constants swapped)"}
                break
    memo_p.write_text(json.dumps(memo, indent=0))
    if not dry and got:
        # the search above runs for a long time on a copy read at the start; writing that copy back would drop
        # accepts made meanwhile. Re-read under the core lock and add only this run's twin entries.
        import fcntl
        with open(ROOT / "work" / f"lock-{cpu}", "w") as lk:
            fcntl.flock(lk, fcntl.LOCK_EX)
            cur = json.loads(sp.read_text())
            for fn, _ in got:
                key = next((k for k, v in sym["functions"].items() if v.get("name") == fn), None)
                if key and not (cur["functions"].get(key, {}).get("status") == "matched"):
                    cur["functions"][key] = sym["functions"][key]
            sp.write_text(json.dumps(cur, indent=2, sort_keys=True))
    print(f"{cpu} twins: {len(got)} {'would be ' if dry else ''}imported")
    for fn, mfn in got[:12]: print(f"  {fn} <- {mfn}")


if __name__ == "__main__": main()
