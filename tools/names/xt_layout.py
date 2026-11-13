#!/usr/bin/env python3
"""Gives every routine file of the Tensilica program a readable file name in a folder by subject:

    src/tensilica/fn_<address>.S   ->   src/tensilica/<topic>/<name>.S

with <name> and <topic> from symbols/tensilica.names.json, rewrites the .include lines of src/tensilica/tensilica.S
(the include order is the address order of the program and does not change), and records where each file went in
symbols/tensilica.files.json ({"<label>": "<path relative to the repository root>"}). The files are moved with
'git mv'. The other files of the folder (vectors, reset code, literals, data, section table) stay where they are.
Line 1 of every routine file keeps the label: "# <name>  (fn_<address>): ...".

--revert moves every file back to src/tensilica/fn_<address>.S, restores the include lines and deletes the record.

usage: python3 -I tools/names/xt_layout.py [--check | --revert]     (--check: report, change nothing)
       afterwards: python3 -I tools/xtensa_check.py   (must print IDENTICAL)
"""
import json, os, pathlib, re, subprocess, sys

R = pathlib.Path(__file__).resolve().parents[2]
SRC = R / "src" / "tensilica"
MAN = R / "symbols" / "tensilica.files.json"
USABLE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")


def manifest():
    return json.loads(MAN.read_text()) if MAN.exists() else {}


def current():
    """label -> current path relative to src/tensilica, for every routine file"""
    man = manifest(); out = {}
    for label, p in man.items():
        if (R / p).exists(): out[label] = pathlib.Path(p).relative_to("src/tensilica").as_posix()
    for f in SRC.glob("fn_*.S"):
        out.setdefault(f.stem, f.name)
    return out


def move(a, b):
    (R / b).parent.mkdir(parents=True, exist_ok=True)
    r = subprocess.run(["git", "mv", a, b], cwd=R, capture_output=True, text=True)
    if r.returncode:
        if "not under version control" in r.stderr: os.rename(R / a, R / b)
        else: sys.exit(f"git mv {a} {b}: {r.stderr.strip()}")


def main():
    check = "--check" in sys.argv; revert = "--revert" in sys.argv
    names = json.loads((R / "symbols" / "tensilica.names.json").read_text())
    cur = current(); want = {}
    for label, rel in cur.items():
        d = names.get(label)
        if revert or not d or not USABLE.fullmatch(d["name"]): want[label] = f"{label}.S"
        else: want[label] = f"{d.get('topic') or 'misc'}/{d['name']}.S"
    seen = {}
    for label, rel in want.items():
        if rel.lower() in seen: sys.exit(f"two files would be named {rel}: {seen[rel.lower()]}, {label}")
        seen[rel.lower()] = label
    moved = {cur[l]: want[l] for l in cur if cur[l] != want[l]}
    print(f"tensilica: {len(cur)} routine files, {len(moved)} {'would be moved' if check else 'moved'}")
    if check: return
    for a, b in sorted(moved.items()):
        if (SRC / b).exists(): sys.exit(f"src/tensilica/{b} already exists")
        move(f"src/tensilica/{a}", f"src/tensilica/{b}")
    # the include lines: the quoted file name changes, everything else on the line stays
    top = SRC / "tensilica.S"; t = top.read_text()
    def inc(m):
        f = moved.get(m.group(2), m.group(2))
        # a file named after its routine needs no name comment; tools/names/xt_apply.py writes it for fn_<address>.S
        return m.group(1) + f + m.group(3) + ("" if f in moved.values() and not f.startswith("fn_") else m.group(4) or "")
    t2 = re.sub(r'(\.include\t")([^"]+)(")( +# \S+)?$', inc, t, flags=re.M)
    if t2 != t: top.write_text(t2)
    # the function records of the program (symbols/8051_bank3.json) name each routine's file
    rec = R / "symbols" / "8051_bank3.json"
    if rec.exists() and moved:
        r = rec.read_text()
        r2 = re.sub(r"src/tensilica/([A-Za-z0-9_/]+\.S)\b", lambda m: "src/tensilica/" + moved.get(m.group(1), m.group(1)), r)
        if r2 != r: rec.write_text(r2)
    new = {l: f"src/tensilica/{rel}" for l, rel in sorted(want.items()) if rel != f"{l}.S"}
    if new: MAN.write_text(json.dumps(new, indent=1) + "\n")
    elif MAN.exists(): MAN.unlink()
    for d in sorted((p for p in SRC.rglob("*") if p.is_dir()), key=lambda p: -len(p.parts)):
        if not any(d.iterdir()): d.rmdir()


if __name__ == "__main__":
    main()
