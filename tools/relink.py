#!/usr/bin/env python3
"""Rebuild check over everything marked matched: each function, built with its proven flags, must link at its
real address and give the firmware's exact bytes (tools/exact.py; diff.compare applies the same judge).
usage: relink.py [cpu ...] [--jobs 8] [--demote]
  report in work/relink/<cpu>.txt; exits 1 on any failure.
  --demote: set failures back to unmatched (source kept in work/relink/demoted/<cpu>/) so the team redoes them.
"""
import argparse, concurrent.futures as cf, json, pathlib, shutil, subprocess, sys, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import diff, exact
CFG = json.loads((ROOT / "tools" / "config.json").read_text())


def check(cpu, fn, entry):
    s, c = ROOT / "src" / cpu / f"{fn}.S", ROOT / "src" / cpu / f"{fn}.c"
    with tempfile.TemporaryDirectory() as td:
        o = pathlib.Path(td) / "x.o"
        if s.exists():
            if exact.run(exact.tool("as"), "-Av8", s, "-o", o).returncode: return fn, "does not assemble"
            return fn, exact.exact(cpu, fn, o)
        why = "does not build"
        flags = [entry["cflags"]] if "cflags" in entry else [CFG[cpu]["cflags"]] + CFG[cpu].get("alt_cflags", [])
        for fl in flags:
            if exact.run(exact.tool("gcc"), *fl.split(), "-w", "-c", c, "-o", o).returncode: continue
            r = exact.exact(cpu, fn, o)
            if r is None: return fn, None
            why = r
        return fn, why


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("cpus", nargs="*", default=["leon2s", "leon2m"])
    ap.add_argument("--jobs", type=int, default=8); ap.add_argument("--demote", action="store_true")
    a = ap.parse_args(); bad = 0
    for cpu in a.cpus:
        sp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(sp.read_text())
        todo = [(k, v) for k, v in sym["functions"].items() if v.get("status") == "matched"]
        with cf.ThreadPoolExecutor(a.jobs) as ex:
            res = list(ex.map(lambda kv: check(cpu, kv[1]["name"], kv[1]), todo))
        fails = sorted((fn, why) for fn, why in res if why)
        rep = [f"{cpu}: {len(res) - len(fails)}/{len(res)} matched functions give the exact firmware bytes at their real address"]
        rep += [f"  {fn}: {why}" for fn, why in fails]
        out = ROOT / "work" / "relink"; out.mkdir(parents=True, exist_ok=True)
        (out / f"{cpu}.txt").write_text("\n".join(rep) + "\n")
        print(rep[0])
        if a.demote and fails:
            names = dict(fails); d = out / "demoted" / cpu; d.mkdir(parents=True, exist_ok=True)
            for k, v in list(sym["functions"].items()):
                if v.get("name") in names:
                    for f in (ROOT / "src" / cpu).glob(v["name"] + ".*"): shutil.move(str(f), d / f.name)
                    (d / f"{v['name']}.why").write_text(names[v["name"]] + "\n")
                    del sym["functions"][k]
            sp.write_text(json.dumps(sym, indent=2, sort_keys=True))
            print(f"{cpu}: demoted {len(fails)} back to the queue")
        bad += len(fails)
    sys.exit(1 if bad else 0)


main()
