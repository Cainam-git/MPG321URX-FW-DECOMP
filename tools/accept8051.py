#!/usr/bin/env python3
"""Accept a documented 8051 hand match: re-judge <file.c> with every Keil option set in parallel, and on an exact
match copy it unchanged to src/<bank>/<fn>.c and mark it matched in symbols/<bank>.json (by, summary, winning
options when they differ from the default). Refuses files without a documentation header.
usage: accept8051.py <bank> <by> <fn> <file.c> "<one-line summary>" [--module <name>] [--dry-run]

Module files: one C file with several real functions (Keil common-entry blocks need the callers
and the callee in one module) is accepted per function with --module <name> (the file's first / main function):
 - the file goes to src/<bank>/<name>.c once; a later member with an identical file does not rewrite it, a member
   with a DIFFERENT file is refused (the already accepted members were judged on the old text);
 - the member's entry gets "module": <name> (tools/verify.py judges it from that file); when the module's own
   function is already matched, the member is judged ONLY with the module's option set (one module = one compile;
   e.g. FUN_CODE_dc80 alone is also byte-exact over 0xdc80..0xdcc9 at the default OPTIMIZE(7,SPEED), without its block);
 - functions.json pieces inside the judged span (diff8051 result "span") that are not the function itself are
   marked "kind": "common_entry" (the L? block in front, diff8051 result "block") or "kind": "part" (a later piece
   of the same C function, e.g. FUN_CODE_1397 inside the 0b0d span of diff8051.SPAN_END), with "of": <fn>. Pieces
   that already have an entry are left alone.
--dry-run judges and prints what would be written, without writing anything. ACCEPT8051_JOBS=n caps the parallel
Keil runs (default: one per option set)."""
import concurrent.futures as cf, json, os, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff8051
CFG = json.loads((ROOT / "tools" / "config.json").read_text())["8051"]
OPTS = [CFG["c51opts"]] + CFG.get("alt_c51opts", [])

def one(o):
    r = diff8051.judge(bank, fn, path, o)
    return o, bool(r.get("ok") and r.get("match")), r

args = [a for a in sys.argv[1:] if a != "--dry-run"]; dry = "--dry-run" in sys.argv
module = None
if "--module" in args: k = args.index("--module"); module = args[k + 1]; del args[k:k + 2]
bank, by, fn, path, summary = args[:5]; module = module or fn
src = pathlib.Path(path).read_text()
if not src.lstrip().startswith("/*") or len(src.split("*/")[0]) < 150: sys.exit(f"{fn}: needs a documentation header")
dst = ROOT / "src" / bank / f"{module}.c"
if module != fn and dst.exists() and dst.read_text() != src:
    sys.exit(f"{fn}: {dst} already holds a different version of module {module}; re-judge its members on the new text first")
sp = ROOT / "symbols" / f"{bank}.json"; s = json.loads(sp.read_text())
own = next((v for v in s["functions"].values() if v.get("name") == module and v.get("status") == "matched"), None)
if module != fn and not own: sys.exit(f"{fn}: accept the module's own function {module} first (its option set is the module's)")
if module != fn:   # a module is compiled once with ONE option set: a member must match with the module's own
    OPTS = [own.get("c51opts", CFG["c51opts"])]
with cf.ThreadPoolExecutor(int(os.environ.get("ACCEPT8051_JOBS", len(OPTS)))) as ex: res = list(ex.map(one, OPTS))   # env caps parallel Keil runs
win, r = next(((o, r) for o, m, r in res if m), (None, None))
if not win: sys.exit(f"{fn}: not byte-exact with any option set")
funcs = diff8051.funclist(bank)   # functions.json + the diff8051.EXTRA_FUNCS stand-ins
start = next(x["start"] for x in funcs if x["name"] == fn)
e = {"by": by, "comment": summary, "name": fn, "status": "matched"}
if win != CFG["c51opts"]: e["c51opts"] = win
if module != fn: e["module"] = module
new = {f"CODE:{start:04x}": e}
lo, hi = r["span"]
for x in funcs:   # other functions.json pieces inside the judged span: the L? block in front / later parts of fn
    if x["name"] == fn or not lo <= x["start"] < hi or f"CODE:{x['start']:04x}" in s["functions"]: continue
    kind = "common_entry" if x["start"] < start else "part"
    what = (f"Keil common-entry (L?) code in front of {fn}, in {fn}'s code segment" if kind == "common_entry"
            else f"part of the C function {fn} (one function 0x{lo:04x}..0x{hi:04x}, diff8051.SPAN_END)")
    new[f"CODE:{x['start']:04x}"] = {"by": by, "name": x["name"], "status": "matched", "kind": kind, "of": fn,
        "module": module, "comment": f"{what}; emitted by compiling src/{bank}/{module}.c, bytes judged with {fn} "
                                     f"over 0x{lo:04x}..0x{hi:04x}"}
print(f"{fn}: byte-exact ({win}), judged 0x{lo:04x}..0x{hi:04x}" + (f", block 0x{r['block'][0]:04x}" if r["block"] else ""))
for k, v in new.items(): print(f"  {'would write' if dry else 'write'} {k}: {json.dumps(v)}")
if dry: print(f"  {'would copy' if not dst.exists() or dst.read_text() != src else 'unchanged'} {path} -> {dst}"); sys.exit(0)
if not dst.exists() or dst.read_text() != src: dst.write_text(src)
s["functions"].update(new)
sp.write_text(json.dumps(s, indent=2, sort_keys=True))
print(f"{fn}: accepted ({win})")
