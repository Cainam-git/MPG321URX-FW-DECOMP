#!/usr/bin/env python3
"""Mechanical first pass for the 8051 banks: clean Ghidra's C for Keil C51, compile, judge. Fully mechanical.

Ghidra's 8051 type names become Keil types (int is 16 bit), DAT_EXTMEM/INTMEM/CODE globals
become absolute `_at_` variables in the right memory space, and every called function gets
the prototype Ghidra gave it. Functions that call Keil run-time helpers or use raw registers
are skipped (they need a hand-written source).

usage: auto8051.py <bank> [--names a,b] [--jobs 4] [--import]
"""
import json, re, sys, pathlib, argparse
from concurrent.futures import ThreadPoolExecutor
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import extract_func, diff8051, autoc

ROOT = pathlib.Path(__file__).resolve().parent.parent
_BANK = {}

def helper_addrs(bank):
    """addresses (4 hex digits) of the Keil run-time helpers found by tools/keil_helpers.py"""
    hp = ROOT / "symbols" / f"{bank}.helpers.json"
    return set(json.loads(hp.read_text()).keys()) if hp.exists() else set()

def real_8051_function(bank, f):
    """Ghidra's 8051 function table contains fragments (seeded LCALL targets that fall through).
    Keep only ranges that end in RET (0x22), RETI (0x32) or a tail LJMP (0x02 xx xx)."""
    if bank not in _BANK: _BANK[bank] = (ROOT / "parts" / f"{bank}.bin").read_bytes()
    b = _BANK[bank][f["start"]:f["end"]]
    return len(b) >= 3 and (b[-1] in (0x22, 0x32) or b[-3] == 0x02)

TYPES = {"undefined": "unsigned char", "undefined1": "unsigned char", "byte": "unsigned char", "uchar": "unsigned char",
         "bool": "unsigned char", "char": "char", "undefined2": "unsigned int", "uint": "unsigned int", "ushort": "unsigned int",
         "word": "unsigned int", "int": "int", "short": "int", "undefined4": "unsigned long", "ulong": "unsigned long",
         "dword": "unsigned long", "long": "long", "void": "void"}
SPACE = {"EXTMEM": "xdata", "INTMEM": "data", "CODE": "code"}

def ctype(t):
    t = t.strip(); ptr = t.count("*"); base = t.replace("*", "").strip()
    if base not in TYPES: return None
    return TYPES[base] + (" xdata *" * ptr if ptr else "")   # Ghidra 8051 pointers are mostly xdata

def retype(src):
    out = src
    for g in sorted(TYPES, key=len, reverse=True):
        out = re.sub(r"\b" + g + r"\b(?!\s*\()", "\x00" + TYPES[g].replace(" ", "\x01"), out)
    return out.replace("\x00", "").replace("\x01", " ")

def prototype(cpu, name):
    try: gc = extract_func.get(cpu, name)[1]
    except Exception: return None
    m = re.match(r"\s*(.+?)\s+(" + re.escape(name) + r")\s*\(([^)]*)\)", gc or "")
    if not m: return f"extern void {name}(void);"
    params = "void" if m.group(3).strip() in ("", "void") else retype(m.group(3))
    return f"extern {retype(m.group(1))} {name}({params});"

def clean(cpu, fn, gc, helpers):
    if not gc or re.search(r"\b(unaff_|in_|extraout_|CONCAT|SUB\d|ZEXT|SEXT|halt_baddata|BANK\d_R\d|R\d\b|\bACC\b|DPTR|DPH|DPL|PSW|SP\b|code\s*\*)", gc):
        return None
    called = set(re.findall(r"\b(FUN_CODE_[0-9a-f]{4})\s*\(", gc)) - {fn}
    if any(c[-4:] in helpers for c in called): return None
    body = retype(gc)
    decls = []
    for name, space, addr in sorted(set(re.findall(r"\b(_?DAT_(EXTMEM|INTMEM|CODE)_([0-9a-f]+))\b", body))):
        decls.append(f"unsigned char {SPACE[space]} {name} _at_ 0x{addr};")
    for c in sorted(called):
        p = prototype(cpu, c)
        if not p: return None
        decls.append(p)
    return "\n".join(decls) + "\n\n" + body

def run(cpu, f, helpers, out):
    fn = f["name"]
    try: gc = extract_func.get(cpu, fn)[1]
    except Exception: return fn, None
    src = clean(cpu, fn, gc, helpers)
    if not src: return fn, None
    p = out / f"{fn}.c"; p.write_text(src)
    r = diff8051.judge(cpu, fn, str(p))
    return fn, (r["score"] if r.get("ok") else -1.0)

def main():
    ap = argparse.ArgumentParser(); ap.add_argument("cpu"); ap.add_argument("--names"); ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--import", dest="do_import", action="store_true"); a = ap.parse_args()
    out = ROOT / "work" / "auto8051" / a.cpu; out.mkdir(parents=True, exist_ok=True)
    scp = ROOT / "work" / "auto8051" / f"{a.cpu}.scores.json"
    helpers = helper_addrs(a.cpu)
    funcs = [f for f in json.loads((ROOT / "symbols" / f"{a.cpu}.functions.json").read_text())["functions"]
             if real_8051_function(a.cpu, f) and f"{f['start']:04x}" not in helpers]
    if a.do_import: return do_import(a.cpu, funcs, json.loads(scp.read_text()), out)
    want = set(a.names.split(",")) if a.names else None
    funcs = [f for f in funcs if not want or f["name"] in want]
    with ThreadPoolExecutor(a.jobs) as ex:
        res = list(ex.map(lambda f: run(a.cpu, f, helpers, out), funcs))
    scores = {fn: {"score": s} for fn, s in res if s is not None and s >= 0}
    scp.write_text(json.dumps(scores, indent=1, sort_keys=True))
    print(a.cpu, f"{len(funcs)} real functions, {sum(1 for _, s in res if s is None)} skipped, "
          f"{sum(1 for _, s in res if s == -1.0)} compile errors, {len(scores)} scored, "
          f"{sum(1 for v in scores.values() if v['score'] >= 100)} match, {sum(1 for v in scores.values() if 90 <= v['score'] < 100)} at 90-99 %")

def do_import(cpu, funcs, scores, out):
    symp = ROOT / "symbols" / f"{cpu}.json"
    sym = json.loads(symp.read_text()) if symp.exists() else {"functions": {}}
    done = {v["name"] for v in sym["functions"].values() if v.get("status") == "matched"}
    byname = {f["name"]: f for f in funcs}; n = 0
    for fn, v in sorted(scores.items()):
        if v["score"] < 100 or fn in done or fn not in byname: continue
        src = (out / f"{fn}.c").read_text()
        r = diff8051.judge(cpu, fn, str(out / f"{fn}.c"))
        if not r.get("match"): print("re-check failed", fn); continue
        (ROOT / "src" / cpu).mkdir(parents=True, exist_ok=True)
        (ROOT / "src" / cpu / f"{fn}.c").write_text(
            f"/* {cpu} {fn} @ 0x{byname[fn]['start']:04x}  MATCH ({r.get('opts')}, autoc)\n"
            " * Mechanical: Ghidra's C cleaned by tools/auto8051.py; Ghidra's symbol names are kept.\n */\n" + src)
        sym["functions"][f"ram:{byname[fn]['start']:04x}"] = \
            {"name": fn, "status": "matched", "by": "autoc", "comment": "mechanical match (tools/auto8051.py); not yet named or documented"}
        if r.get("opts") and r["opts"] != diff8051.CFG["8051"]["c51opts"]: sym["functions"][f"ram:{byname[fn]['start']:04x}"]["c51opts"] = r["opts"]
        n += 1
    symp.write_text(json.dumps(sym, indent=2, sort_keys=True)); print(f"{cpu}: imported {n}")

if __name__ == "__main__":
    main()
