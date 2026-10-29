#!/usr/bin/env python3
"""Jump tables of the LEON sections (switchdataD_* entries of symbols/<cpu>.functions.json).
A table counts as matched when the exact check of a matched function proves it entry for entry (tools/exact.py,
jump_tables): the function's switch compiles to the same targets, and the firmware table holds them at the
addresses the function's sethi/or pair names. The table's whole range must be covered by tables proven that way.
usage: acctable.py <cpu> [--write] [--gaps]   lists the tables the matched functions prove; --write records them in
       symbols/<cpu>.json (kind "jump_table", "of" = the function whose switch uses it); --gaps also adds a
       switchdataD_<address> entry to symbols/<cpu>.functions.json for each proven table that no entry covers yet"""
import json, pathlib, sys
from concurrent.futures import ThreadPoolExecutor
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import exact


def ranges(cpu):
    return {f["name"]: (f["start"], f["end"]) for f in
            json.loads((ROOT / "symbols" / f"{cpu}.functions.json").read_text())["functions"]}


def covered(lo, hi, tabs):
    """True when the proven tables cover every word of [lo, hi) (one proven table may span several entries)"""
    at = lo
    for a, vals in sorted(tabs):
        e = a + 4 * len(vals)
        if e <= at or a >= hi: continue
        if a > at: return False
        at = e
        if at >= hi: return True
    return at >= hi


def proven(cpu, fn, entry):
    """the tables proven by the exact check of matched function fn ([] when it has none or fails)"""
    import verify
    _, why = verify.check(cpu, fn, entry)
    return [] if why else exact.TABLES.get((cpu, fn), [])


def check(cpu, name, entry):
    """None when table `name` is proven inside its recorded function, else a reason"""
    lo, hi = ranges(cpu)[name]
    sym = json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())["functions"]
    own = next((v for v in sym.values() if v.get("name") == entry["of"] and v.get("status") == "matched"), None)
    if own is None: return f"function {entry['of']} not matched"
    tabs = proven(cpu, entry["of"], own)
    return None if covered(lo, hi, tabs) else f"not proven by {entry['of']}"


def main():
    cpu = sys.argv[1]; write = "--write" in sys.argv
    rg = ranges(cpu); sp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(sp.read_text())
    have = {v["name"] for v in sym["functions"].values() if v.get("status") == "matched"}
    todo = {n: r for n, r in rg.items() if n.startswith("switchdata") and n not in have}
    users = [(v["name"], v) for v in sym["functions"].values()
             if v.get("status") == "matched" and v.get("kind") != "jump_table"]
    with ThreadPoolExecutor(12) as ex:
        res = dict(zip([n for n, _ in users], ex.map(lambda it: proven(cpu, *it), users)))
    found = {}
    if "--gaps" in sys.argv and write:   # proven tables in no entry yet: add the entry, then record it below
        import fcntl
        lock = open(ROOT / "work" / "lock-accept", "a"); fcntl.flock(lock, fcntl.LOCK_EX)
        fp = ROOT / "symbols" / f"{cpu}.functions.json"; d = json.loads(fp.read_text()); fl = d["functions"]
        for fn, tabs in res.items():
            for a, vals in tabs:
                e = a + 4 * len(vals)
                if any(x["start"] < e and a < x["end"] for x in fl): continue
                name = f"switchdataD_{a:08x}"
                fl.append({"name": name, "start": a, "end": e, "size": e - a}); todo[name] = (a, e); rg[name] = (a, e)
                print(f"new entry {name} {e - a} B")
        fl.sort(key=lambda x: x["start"]); fp.write_text(json.dumps(d, separators=(",", ":")))
        fcntl.flock(lock, fcntl.LOCK_UN)
    for name, (lo, hi) in sorted(todo.items(), key=lambda x: x[1]):
        for fn, tabs in res.items():
            if tabs and covered(lo, hi, tabs): found[name] = fn; break
    for name, fn in found.items():
        print(f"{name} {rg[name][1] - rg[name][0]} B  proven by {fn}")
    print(f"{cpu}: {len(found)}/{len(todo)} unmatched tables proven, "
          f"{sum(rg[n][1] - rg[n][0] for n in found)} bytes")
    if write and found:   # the workers' accept scripts write the same file: re-read it under their lock
        import fcntl
        lock = open(ROOT / "work" / "lock-accept", "a"); fcntl.flock(lock, fcntl.LOCK_EX)
        sym = json.loads(sp.read_text())
        for name, fn in found.items():
            sym["functions"][f"ram:{rg[name][0]:08x}"] = {
                "name": name, "status": "matched", "kind": "jump_table", "of": fn, "by": "table",
                "comment": f"jump table of the switch in {fn}; proven entry for entry by its exact check"}
        sp.write_text(json.dumps(sym, indent=2, sort_keys=True))
        print(f"recorded {len(found)} in {sp.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
