#!/usr/bin/env python3
"""Accept hand-finished work/autoc functions: mark score 100, import via autoc, record <by> as the finisher.
usage: accept.py <cpu> <by> <fn> [note]"""
import json, sys, subprocess, pathlib
ROOT = pathlib.Path(__file__).resolve().parent.parent
cpu, by, fn = sys.argv[1:4]; note = sys.argv[4] if len(sys.argv) > 4 else ""
scp = ROOT / "work/autoc" / f"{cpu}.scores.json"; s = json.loads(scp.read_text()); s[fn]["score"] = 100.0
scp.write_text(json.dumps(s, indent=1, sort_keys=True))
subprocess.run([sys.executable, "-I", str(ROOT / "tools/autoc.py"), cpu, "--import"], check=True)
sp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(sp.read_text())
for v in sym["functions"].values():
    if v["name"] == fn and v.get("status") == "matched":
        v["by"] = f"autoc+{by}"; v["comment"] = (note or v["comment"])
sp.write_text(json.dumps(sym, indent=2, sort_keys=True))
import re
src = ROOT / "src" / cpu / f"{fn}.c"; t = src.read_text()
if t.startswith("/*") and note:
    first = t.splitlines()[0].replace(", autoc)", f", autoc + {by})")
    body = "\n".join(" * " + l.rstrip() for l in re.findall(r".{1,92}(?:\s|$)", f"Finished by {by} from mechanical Ghidra C. {note}"))
    t = first + "\n" + body + "\n * Still needs a real name and proper types.\n */" + t[t.index("*/") + 2:]
src.write_text(t)
