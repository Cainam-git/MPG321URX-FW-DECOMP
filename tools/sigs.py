#!/usr/bin/env python3
"""Write symbols/<cpu>.sigs.json: exact signatures of every function matched on master,
read from src/<cpu>/*.c, for ImportSymbols.java to apply in Ghidra (better caller C).
usage: sigs.py <cpu>"""
import json, re, sys, pathlib
ROOT = pathlib.Path(__file__).resolve().parent.parent
cpu = sys.argv[1]
funcs = {f["name"]: f for f in json.loads((ROOT / "symbols" / f"{cpu}.functions.json").read_text())["functions"]}
out = {}
for p in sorted((ROOT / "src" / cpu).glob("*.c")):
    name = p.stem; t = re.sub(r"/\*.*?\*/", "", p.read_text(), flags=re.S)
    m = re.search(r"^([A-Za-z_][\w \*]*?)\s+" + re.escape(name) + r"\s*\(([^)]*)\)\s*\{", t, re.M)
    if not m or name not in funcs or m.group(1).startswith(("extern", "typedef", "return")): continue
    params, varargs = [], False
    ps = re.sub(r"\s+", " ", m.group(2)).strip()
    if ps and ps != "void":
        for i, q in enumerate(x.strip() for x in ps.split(",")):
            if q == "...": varargs = True; continue
            qm = re.match(r"(.*?)(\**)\s*(\w+)$", q)
            if not qm: params = None; break
            params.append({"type": (qm.group(1).strip() + " " + qm.group(2)).strip(), "name": qm.group(3)})
    if params is None: continue
    out[f"ram:{funcs[name]['start']:08x}"] = {"return": re.sub(r"\b(static|inline)\b", "", m.group(1)).strip(),
                                            "params": params, "varargs": varargs}
# Ghidra's "undefined8" return guess is wrong on 32-bit SPARC (results come back in %o0 only) and makes
# every caller drop the result: give those functions a 32-bit return, keeping Ghidra's parameters.
sys.path.insert(0, str(ROOT / "tools")); import extract_func
KNOWN = {"void", "int", "uint", "undefined4", "undefined2", "undefined1", "undefined", "byte", "char", "ushort", "short",
         "dword", "word", "bool", "uchar", "ulong", "long", "code"}
fixed = 0
for name, _, body in extract_func.functions(cpu):
    hm = re.match(r"\s*undefined8\s+" + re.escape(name) + r"\s*\(([^)]*)\)", body)
    if not hm or name not in funcs: continue
    key = f"ram:{funcs[name]['start']:08x}"
    if key in out: continue
    params, ok = [], True
    ps = re.sub(r"\s+", " ", hm.group(1)).strip()
    if ps and ps != "void":
        for q in (x.strip() for x in ps.split(",")):
            qm = re.match(r"(\w+)\s*(\**)\s*(\w+)$", q)
            if not qm or qm.group(1) not in KNOWN: ok = False; break
            params.append({"type": (qm.group(1) + " " + qm.group(2)).strip(), "name": qm.group(3)})
    if ok:
        out[key] = {"return": "uint", "params": params, "varargs": False}; fixed += 1
print(f"{cpu}: {fixed} undefined8 returns corrected to 32 bit")
# keep earlier corrections: once applied, Ghidra no longer shows them as undefined8, so they would drop out
prevp = ROOT / "symbols" / f"{cpu}.sigs.json"
if prevp.exists():
    for k, v in json.loads(prevp.read_text())["signatures"].items(): out.setdefault(k, v)
(ROOT / "symbols" / f"{cpu}.sigs.json").write_text(json.dumps({"signatures": out}, indent=1, sort_keys=True))
print(f"{cpu}: {len(out)} signatures")
