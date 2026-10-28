#!/usr/bin/env python3
"""Re-verify every function marked matched in symbols/<cpu>.json: rebuild src/<cpu>/<fn>.{c,S}
with its recorded flags (or the core's flag sets) and judge it against the firmware.
usage: verify.py [cpu ...]   exits 1 if anything fails"""
import json, sys, pathlib, subprocess, tempfile
from concurrent.futures import ThreadPoolExecutor
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import diff, diff8051
CFG = json.loads((ROOT / "tools" / "config.json").read_text())
GCC = str(ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc"); AS = str(ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-as")

def check(cpu, fn, entry):
    if cpu.startswith("8051"):
        if entry.get("kind") == "vector":   # LJMP placed by C51 for 'interrupt n' of the matched function in "of"
            return fn, diff8051.vector(cpu, fn, entry)[0]
        if entry.get("kind") in ("common_entry", "part"):   # piece judged inside its function's span (accept8051)
            own = next((v for v in json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())["functions"].values()
                        if v.get("name") == entry["of"] and v.get("status") == "matched" and not v.get("kind")), None)
            if own is None: return fn, f"owner {entry['of']} not matched"
            return fn, check(cpu, entry["of"], own)[1]
        p = ROOT / "src" / cpu / f"{entry.get('module', fn)}.c"; lib = ROOT / "src" / cpu / f"{fn}.lib"   # module file (accept8051 --module)
        if lib.exists():   # Keil run-time library routine (tools/keillib.py)
            import keillib
            why = keillib.check(cpu, fn, *lib.read_text().split("\n", 1)[0].split())
            return fn, None if why is None else f"lib: {why}"
        if not p.exists(): return fn, "missing source"
        opts = [entry["c51opts"]] if "c51opts" in entry else None
        r = diff8051.judge(cpu, fn, str(p), opts[0]) if opts else diff8051.judge(cpu, fn, str(p))
        return fn, None if r.get("match") else f"{r.get('score', 0):.1f}%"
    if entry.get("kind") == "jump_table":   # proven entry for entry inside its matched function (tools/acctable.py)
        import acctable
        return fn, acctable.check(cpu, fn, entry)
    lib = ROOT / "src" / cpu / f"{fn}.lib"
    if lib.exists():   # toolchain library function: the archive member is the source (tools/libimport.py)
        import libimport
        why = libimport.check_lib(cpu, fn, *lib.read_text().split("\n", 1)[0].split())
        return fn, None if why is None else f"lib: {why}"
    with tempfile.TemporaryDirectory() as td:
        o = pathlib.Path(td) / "x.o"
        s = ROOT / "src" / cpu / f"{fn}.S"; c = ROOT / "src" / cpu / f"{fn}.c"
        if s.exists():
            r = subprocess.run([AS, "-Av8", str(s), "-o", str(o)], capture_output=True)
            ok = r.returncode == 0 and diff.compare(cpu, fn, str(o))[6]
            return fn, None if ok else "asm mismatch"
        if not c.exists(): return fn, "missing source"
        flags = [entry["cflags"]] if "cflags" in entry else [CFG[cpu]["cflags"]] + CFG[cpu].get("alt_cflags", [])
        for fl in flags:
            r = subprocess.run([GCC, *fl.split(), "-w", "-c", str(c), "-o", str(o)], capture_output=True)
            if r.returncode == 0 and diff.compare(cpu, fn, str(o))[6]: return fn, None
        return fn, "mismatch"

def main():
    cpus = sys.argv[1:] or ["leon2s", "leon2m", "8051_bank0", "8051_bank1", "8051_bank2", "8051_bank3"]
    bad = 0; total = 0
    for cpu in cpus:
        sp = ROOT / "symbols" / f"{cpu}.json"
        if not sp.exists(): continue
        items = [(v["name"], v) for v in json.loads(sp.read_text())["functions"].values() if v.get("status") == "matched"]
        with ThreadPoolExecutor(12 if not cpu.startswith("8051") else 4) as ex:
            res = list(ex.map(lambda it: check(cpu, *it), items))
        fails = [(fn, why) for fn, why in res if why]
        total += len(res); bad += len(fails)
        print(f"{cpu}: {len(res) - len(fails)}/{len(res)} verified" + (f", FAILED: {fails[:10]}" if fails else ""))
    print(f"total: {total - bad}/{total} verified")
    sys.exit(1 if bad else 0)

if __name__ == "__main__":
    main()
