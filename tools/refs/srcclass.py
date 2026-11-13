#!/usr/bin/env python3
"""Classify the address-looking numbers in the C source (srclit.py output): 'address' when the code uses the number
as an address (pointer cast, or an argument position / statement that takes an address), else 'number'.
usage: srcclass.py leon2m|leon2s [--export]   (--export writes symbols/<section>.srcaddr.json)"""
import json, pathlib, re, sys, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]; sec = sys.argv[1]
sys.path.insert(0, str(ROOT / "tools")); import srcpath
p = ROOT / f"work/refs/{sec}.srclit.json"; L = json.loads(p.read_text())
# callee -> argument positions that take an address (from the callees' matched sources)
ADDR_ARGS = {"FUN_a00df170": {0}, "func_0x0007f170": {0}, "FUN_a01577f4": {1}, "FUN_a013c910": {0, 1}, "FUN_a00a3844": {0},
             "func_0x4008a880": {2}, "FUN_a015bf7c": {1}, "FUN_a0101704": {0}, "FUN_a00f87b0": {0},
             "FUN_a00fc30c": {0}, "FUN_a01461dc": {1}, "FUN_a01461a8": {0}, "FUN_a015ea08": {0}, "FUN_a015ea68": {0}, "func_0x4008c25c": {0, 1}}
MANUAL_ADDR = {("FUN_a015b558", 0xfb5c4), ("FUN_a015c1b4", 0x1a84f4)}     # (label of the file, value)
def callee_arg(t, lit):
    i = t.lower().find(lit)
    if i < 0: return None
    depth = 0; k = i - 1; arg = 0
    while k >= 0:
        c = t[k]
        if c == ")": depth += 1
        elif c == "(":
            if depth == 0:
                m = re.search(r"([A-Za-z_]\w*)\s*$", t[:k]); return (m.group(1) if m else "?", arg)
            depth -= 1
        elif c == "," and depth == 0: arg += 1
        k -= 1
    return None
for e in L:
    ca = callee_arg(e["text"], "0x%x" % e["value"])
    if e.get("asm"): e["status"], e["why"] = "address", "high part of an address in the assembly source (sethi operand in the processor's own range)"
    elif e["cast"]: e["status"], e["why"] = "address", "pointer cast"
    elif ca and ca[0] in ADDR_ARGS and ca[1] in ADDR_ARGS[ca[0]]: e["status"], e["why"] = "address", f"argument {ca[1]} of {ca[0]}"
    elif (srcpath.label_of(sec, srcpath.src_dir(sec) / e["file"]), e["value"]) in MANUAL_ADDR: e["status"], e["why"] = "address", "stored or returned as an address (hand ruling)"
    elif e["kind"] in ("ram", "code", "code+0xF10000", "startup"): e["status"], e["why"] = "address", "32-bit pattern of the processor's own memory range"
    else: e["status"], e["why"] = "number", "mask, limit or arithmetic constant"
p.write_text(json.dumps(L, indent=0))
if "--export" in sys.argv:        # the address literals, one per line, for the repository
    rows = [{"file": e["file"], "line": e["line"], "value": e["value"], "kind": e["kind"], "why": e["why"]} for e in L if e["status"] == "address"]
    (ROOT / f"symbols/{sec}.srcaddr.json").write_text('{"section":"%s","addresses":%d,"plain_numbers":%d,"literals":[\n' % (sec, len(rows), len(L) - len(rows))
        + ",\n".join(json.dumps(r, separators=(",", ":")) for r in rows) + "\n]}\n")
c = collections.Counter((e["status"], e["kind"]) for e in L)
print(sec, dict(c), "| addresses:", sum(1 for e in L if e["status"] == "address"), "numbers:", sum(1 for e in L if e["status"] == "number"))
