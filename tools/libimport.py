#!/usr/bin/env python3
"""Import toolchain library functions found by libmatch.py: no decompiling, the library's own object is the source.

For every unmatched Ghidra function that libmatch identified uniquely, the archive member is extracted and must
give the firmware's exact bytes at the function's real address (tools/exact.py, with the addresses of the names it
calls read back from the firmware). On success: src/<cpu>/<fn>.lib  = "<archive> <member> <symbol>" and the
symbols entry becomes matched (by "lib"). verify.py re-checks .lib entries the same way.
usage: libimport.py <cpu> [--dry]
"""
import argparse, json, pathlib, subprocess, sys, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import exact
TC = ROOT / "toolchains" / "sparc-elf-3.4.4"


def archives(lib):
    """v8 multilib first, then the default one (__udivdi3 in the firmware is the default libgcc's)"""
    return [p for p in [TC / "sparc-elf" / "lib" / "v8" / lib] + sorted(TC.glob(f"lib/gcc/sparc-elf/*/v8/{lib}"))
            + [TC / "sparc-elf" / "lib" / lib] + sorted(TC.glob(f"lib/gcc/sparc-elf/*/{lib}"))
            + [TC / "sparc-elf" / "lib" / "soft" / lib] + sorted(TC.glob(f"lib/gcc/sparc-elf/*/soft/{lib}")) if p.exists()]


def archive(lib):
    a = archives(lib)
    return a[0] if a else None


def member_object(arc, member, td):
    subprocess.run([exact.tool("ar"), "x", str(arc), member], cwd=td, capture_output=True)
    o = pathlib.Path(td) / member
    return o if o.exists() else None


def check_lib(cpu, fn, lib, member, symbol, placed=None):
    arcs = archives(lib)
    if not arcs: return f"archive {lib} not found"
    why = f"member {member} not in {lib}"
    for arc in arcs:
        with tempfile.TemporaryDirectory() as td:
            o = member_object(arc, member, td)
            if not o: continue
            subprocess.run([exact.tool("objcopy"), "-R", ".eh_frame", "-R", ".comment", str(o)], capture_output=True)   # unwind info is not in the firmware
            why = exact.exact(cpu, fn, str(o), sym=symbol, solve=True, placed=placed)
            if why is None: return None
    return why


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("cpu"); ap.add_argument("--dry", action="store_true")
    a = ap.parse_args(); cpu = a.cpu
    hits = json.loads((ROOT / "symbols" / f"{cpu}.libmatch.json").read_text())
    sp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(sp.read_text())
    ok, fails = [], []
    for key, v in sorted(hits.items()):
        fn = v.get("ghidra")
        if not fn or sym["functions"].get(key, {}).get("status") == "matched": continue
        names = sorted(set(c["name"] for c in v["candidates"]))
        if len(names) != 1: continue                      # ambiguous stubs: not identifiable, leave them to the team
        symbol = names[0]; why = None
        for c in v["candidates"]:                         # libc.a and libg.a carry the same member: first that passes
            lib, member = c["lib"].split(":", 1)
            why = check_lib(cpu, fn, lib, member, symbol)
            if why is None: break
        if why: fails.append((fn, symbol, why)); continue
        ok.append((fn, symbol, lib, member, c["size"]))
        if a.dry: continue
        (ROOT / "src" / cpu / f"{fn}.lib").write_text(
            f"{lib} {member} {symbol}\n# {cpu} {fn}: toolchain library function {symbol} ({lib}:{member}, {c['size']} bytes),\n"
            f"# byte-exact at its address; the archive member is the source, nothing to decompile.\n")
        sym["functions"][key] = {"name": fn, "status": "matched", "by": "lib", "lib": f"{lib}:{member}", "symbol": symbol,
                                 "comment": f"toolchain library function {symbol} from {lib}:{member}; byte-exact, no C needed"}
    if not a.dry: sp.write_text(json.dumps(sym, indent=2, sort_keys=True))
    print(f"{cpu}: {len(ok)} library functions {'would be ' if a.dry else ''}imported ({sum(o[4] for o in ok)} bytes), {len(fails)} not exact")
    for fn, symbol, why in fails: print(f"  {fn} ({symbol}): {why}")


if __name__ == "__main__": main()
