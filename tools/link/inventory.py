#!/usr/bin/env python3
"""Inventory for the linked build of a LEON section: build every function the way tools/rebuild.py does, keep the
object and the compiler's assembly, and record flags, sections, symbols and relocations. -> work/link/inv_<sec>.json
usage: inventory.py leon2m [--jobs 8]"""
import json, pathlib, re, subprocess, sys, collections
from concurrent.futures import ThreadPoolExecutor
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import exact, srcpath
sec = sys.argv[1]; jobs = int(sys.argv[sys.argv.index("--jobs") + 1]) if "--jobs" in sys.argv else 8
CFG = json.loads((ROOT / "tools/config.json").read_text())[sec]
sym = json.loads((ROOT / f"symbols/{sec}.json").read_text())["functions"]
byname = {v["name"]: v for v in sym.values() if "name" in v}
fl_ = json.loads((ROOT / f"symbols/{sec}.functions.json").read_text())["functions"]
OUT = ROOT / "work/link" / sec; OUT.mkdir(parents=True, exist_ok=True)
run = exact.run
def one(f):
    fn = f["name"]; e = byname.get(fn, {}); lib = srcpath.path(sec, fn, ".lib")
    r = {"name": fn, "start": f["start"], "end": f["end"]}
    if fn.startswith("switchdata") or e.get("kind") == "jump_table": r["kind"] = "table"; r["of"] = e.get("of"); return r
    if lib.exists(): r["kind"] = "lib"; r["lib"] = lib.read_text().split("\n", 1)[0]; return r
    s, c = srcpath.path(sec, fn, ".S"), srcpath.path(sec, fn, ".c"); o = OUT / f"{fn}.o"; inc = srcpath.include(sec, c, fn)
    if s.exists():
        r["kind"] = "asm"; x = run(exact.tool("as"), "-Av8", s, "-o", o)
        if x.returncode: r["error"] = x.stderr[-200:]; return r
    elif c.exists():
        r["kind"] = "c"; rec = e.get("cflags", CFG["cflags"]); ok = None
        for fl in [rec] + [x for x in [CFG["cflags"]] + CFG.get("alt_cflags", []) if x != rec]:
            x = run(exact.tool("gcc"), *fl.split(), *inc, "-w", "-c", c, "-o", o)
            if x.returncode: continue
            if exact.exact(sec, fn, o) is None: ok = fl; break
        if not ok: r["error"] = "no flag set exact"; return r
        r["flags"] = ok
        run(exact.tool("gcc"), *ok.split(), *inc, "-w", "-S", c, "-o", OUT / f"{fn}.s")
    else: r["kind"] = "none"; return r
    secs = {}
    for m in re.finditer(r"^\s*\[\s*\d+\]\s+(\S+)\s+(\w+)\s+\w+\s+\w+\s+(\w+)\s+\w+\s+(\S*)", run(exact.tool("readelf"), "-SW", o).stdout, re.M):
        if int(m[3], 16) and "A" in m[4]: secs[m[1]] = int(m[3], 16)
    r["sections"] = secs
    defs = []; und = []
    for m in re.finditer(r"^\s*\d+:\s+([0-9a-f]+)\s+(\d+)\s+(\w+)\s+(\w+)\s+\w+\s+(\w+)\s+(\S+)\s*$", run(exact.tool("readelf"), "-sW", o).stdout, re.M):
        val, size, typ, bind, ndx, name = m.groups()
        if ndx == "UND": und.append(name)
        elif typ in ("FUNC", "OBJECT") or bind == "GLOBAL": defs.append([name, typ, bind, int(val, 16), int(size)])
    r["defs"] = defs; r["undef"] = sorted(set(und))
    rel = collections.Counter()
    for m in re.finditer(r"^[0-9a-f]+\s+[0-9a-f]+\s+(R_SPARC_\w+)\s+[0-9a-f]+\s+(\S+)", run(exact.tool("readelf"), "-rW", o).stdout, re.M):
        rel[(m[1], m[2] if m[2].startswith(".") else "sym")] += 1
    r["relocs"] = [[k[0], k[1], n] for k, n in sorted(rel.items())]
    return r
with ThreadPoolExecutor(jobs) as ex: res = list(ex.map(one, fl_))
(ROOT / "work/link" / f"inv_{sec}.json").write_text(json.dumps(res))
c = collections.Counter(r["kind"] for r in res); print(sec, dict(c), "errors:", [(r["name"], r["error"][:60]) for r in res if "error" in r][:8])
