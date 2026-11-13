#!/usr/bin/env python3
"""Second list: addresses written as plain numbers in the C and assembly source of a LEON section (not as FUN_/DAT_
symbols).
usage: srclit.py leon2m|leon2s   -> work/refs/<section>.srclit.json + a summary on stdout"""
import re, pathlib, json, sys, collections
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import srcpath
sec = sys.argv[1]
if sec == "leon2m":
    def kind(v):
        if 0xA8024000 <= v < 0xA8040000: return "ram"
        if 0xA0028000 <= v < 0xA002FB44 or 0x40088000 <= v < 0x4008FB44: return "startup"
        if 0xA0060000 <= v < 0xA0210000: return "ghidra"
        if 0x10000 <= v < 0x1A8654: return "flash"
        return None
else:
    def kind(v):
        if 0xA8076000 <= v < 0xA8080000: return "ram"
        if 0xA0060000 <= v < 0xA00E0000: return "code"
        if 0xA0F70000 <= v < 0xA0FF0000: return "code+0xF10000"
        return None
out = []
for p in srcpath.files(sec, ".c"):       # the files as they are, so that the line numbers are the files' own
    t = p.read_text(errors="replace")
    t2 = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), t, flags=re.S)   # blank comments, keep offsets and lines
    t2 = re.sub(r"//[^\n]*", lambda m: " " * len(m.group(0)), t2)
    for m in re.finditer(r"\b0[xX]([0-9a-fA-F]{5,8})[uUlL]*\b", t2):
        v = int(m.group(1), 16); k = kind(v)
        if not k: continue
        ls = t2.rfind("\n", 0, m.start()) + 1; le = t2.find("\n", m.end()); line = t2[ls:le if le >= 0 else None].strip()
        before = t2[max(0, m.start() - 40):m.start()]
        cast = bool(re.search(r"\*\s*\)\s*\(?\s*$", before))                      # (type *)0x...
        out.append({"file": srcpath.rel(sec, p), "line": t2.count("\n", 0, m.start()) + 1, "value": v, "kind": k, "cast": cast, "text": line[:160]})
# hand-written assembly: sethi %hi(<number>) operands (the low part follows as a plain immediate) and .word values
for p in srcpath.files(sec, ".S"):
    t = p.read_text(errors="replace")
    for i, line in enumerate(t.splitlines(), 1):
        code = line.split("!")[0]
        for m in re.finditer(r"%hi\((0x[0-9a-fA-F]+)\)|\.word\s+(0x[0-9a-fA-F]+)|\bset\s+(0x[0-9a-fA-F]+)", code):
            v = int(next(g for g in m.groups() if g), 16); k = kind(v)
            if k: out.append({"file": srcpath.rel(sec, p), "line": i, "value": v, "kind": k, "cast": False, "asm": True, "text": code.strip()[:160]})
(ROOT / f"work/refs/{sec}.srclit.json").write_text(json.dumps(out, indent=0))
c = collections.Counter((e["kind"], "pointer cast" if e["cast"] else "no cast") for e in out)
for k, n in sorted(c.items()): print(f"{k[0]:16s} {k[1]:12s} {n}")
print("total", len(out), "in", len({e["file"] for e in out}), "files")
