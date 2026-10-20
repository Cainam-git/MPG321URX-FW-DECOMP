#!/usr/bin/env python3
"""Every C string literal in a source must exist (NUL-terminated) in that core's firmware image.
The checker ignores what addresses point to, so an invented log string would otherwise pass.
usage: strcheck.py <cpu> [file...]   (no files: all of src/<cpu>)   exit 1 if any literal is missing"""
import sys, re, pathlib, ast
ROOT = pathlib.Path(__file__).resolve().parent.parent
def literals(src):
    src = re.sub(r"//[^\n]*|/\*.*?\*/", "", src, flags=re.S)
    src = re.sub(r"__asm__\s*(?:volatile\s*)?\([^;]*\)", "", src)   # instruction text, not data
    out = []
    for m in re.finditer(r'((?:"(?:[^"\\\n]|\\.)*"\s*)+)', src):
        if re.search(r"#\s*include", src[max(0, m.start() - 20):m.start()]): continue
        parts = re.findall(r'"((?:[^"\\\n]|\\.)*)"', m.group(1))
        s = b""
        for p in parts:   # C escapes, incl. \x1b before a non-hex char
            p = re.sub(r"\\x([0-9a-fA-F]{1,2})", lambda h: "\\x%02x" % int(h.group(1), 16), p)
            s += ast.literal_eval('b"' + p.replace('"', '\\"') + '"') if p.isascii() else p.encode("latin1")
        out.append(s)
    return out
def missing(cpu, path):
    img = (ROOT / "parts" / f"{cpu}.bin").read_bytes()
    return [s for s in literals(pathlib.Path(path).read_text()) if s + b"\0" not in img]
if __name__ == "__main__":
    cpu = sys.argv[1]; files = sys.argv[2:] or sorted(str(p) for p in (ROOT / "src" / cpu).glob("*.c"))
    bad = 0
    for f in files:
        for s in missing(cpu, f):
            bad += 1; print(f"{pathlib.Path(f).name}: literal not in firmware: {s[:70]!r}")
    print(f"{cpu}: {len(files)} files, {bad} invented literals"); sys.exit(1 if bad else 0)
