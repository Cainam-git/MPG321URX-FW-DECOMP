#!/usr/bin/env python3
"""Gives every source file of a section a readable file name in a folder by subject:

    src/<section>/<label>.<ext>   ->   src/<section>/<topic>/<name>.<ext>

with <name> and <topic> from symbols/<section>.names.json, and records where each file went in
symbols/<section>.files.json ({"<label>": "<path relative to the repository root>"}), which tools/srcpath.py reads.
The files are moved with 'git mv', so their history follows them. A file that holds several routines (a Keil module
of the 8051 programs) is named after the routine whose label named the file. C, assembly (.S) and library (.lib)
files are moved; other files (the 8051 start-up templates in startup/) stay where they are.

A name that two files of the section would share (letters compared without case), or that is not usable as a file
name (only letters, digits and '_', not starting with a digit), gets the address of its label as a suffix:
<name>_<address> ('.udiv' becomes 'udiv_a0156a6c'). The side lists of names (symbols/defs/) are kept by label and
do not move.

Paths that symbols/<section>.json records in its comments ("emitted by compiling src/...") are rewritten to the new
places, and for the two LEON sections the list of address numbers in the source (symbols/<section>.srcaddr.json,
which records file paths and line numbers) is made again with tools/refs/srclit.py and srcclass.py --export.

The script can be run again after names change: it moves only the files whose place differs from the one their
name gives. --revert moves every file back to src/<section>/<label>.<ext> and deletes the manifest.

usage: python3 -I tools/names/layout.py <section> [--check | --revert]   (--check: report, change nothing)
"""
import collections, json, os, pathlib, re, subprocess, sys

R = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(R / "tools"))
import srcpath

USABLE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
EXTS = (".c", ".S", ".lib")


def address(label):
    """the address part of a label: FUN_a00dac38 -> a00dac38, FUN_CODE_7b5a -> 7b5a"""
    return label.rsplit("_", 1)[-1]


def targets(sec, names, files):
    """label -> (path relative to the repository root, suffixed); files: label -> current path"""
    want = {}
    for label, p in files.items():
        d = names.get(label)
        if not d: continue                     # a file without a name stays where it is
        topic = d.get("topic") or "misc"
        want[label] = [topic, d["name"], USABLE.fullmatch(d["name"]) is None, p.suffix]
    count = collections.Counter(nm.lower() for _, nm, bad, _ in want.values() if not bad)
    out = {}
    for label, (topic, nm, bad, ext) in want.items():
        suffixed = bad or count[nm.lower()] > 1
        if suffixed: nm = (re.sub(r"[^A-Za-z0-9_]", "", nm).lstrip("0123456789") or "routine") + "_" + address(label)
        out[label] = (f"src/{sec}/{topic}/{nm}{ext}", suffixed)
    taken = collections.Counter(v.lower() for v, _ in out.values())
    clash = [v for v, n in taken.items() if n > 1]
    if clash: sys.exit(f"{sec}: file names still collide after the suffix: {clash[:5]}")
    return out


def move(a, b):
    """git mv a b (relative to the repository root); a file that git does not track is renamed"""
    (R / b).parent.mkdir(parents=True, exist_ok=True)
    r = subprocess.run(["git", "mv", a, b], cwd=R, capture_output=True, text=True)
    if r.returncode:
        if "not under version control" in r.stderr: os.rename(R / a, R / b)
        else: sys.exit(f"git mv {a} {b}: {r.stderr.strip()}")


def rewrite_records(sec, moved):
    """rewrite the source paths that symbols/<section>.json records (moved: old -> new, relative to the root)"""
    p = R / "symbols" / f"{sec}.json"
    if not p.exists() or not moved: return 0
    t = p.read_text(); n = [0]
    pat = re.compile(r"src/" + re.escape(sec) + r"/[A-Za-z0-9_./]+?\.(?:c|S|lib)\b")
    def sub(m):
        if m.group(0) in moved: n[0] += 1; return moved[m.group(0)]
        return m.group(0)
    t2 = pat.sub(sub, t)
    if t2 != t: p.write_text(t2)
    return n[0]


def remake_srcaddr(sec):
    """symbols/<section>.srcaddr.json records file paths and line numbers: make it again (LEON sections)"""
    if not (R / "symbols" / f"{sec}.srcaddr.json").exists(): return
    (R / "work" / "refs").mkdir(parents=True, exist_ok=True)
    for cmd in (["tools/refs/srclit.py", sec], ["tools/refs/srcclass.py", sec, "--export"]):
        r = subprocess.run([sys.executable, "-I", *cmd], cwd=R, capture_output=True, text=True)
        if r.returncode: sys.exit(f"{' '.join(cmd)}: {r.stderr.strip()[-300:]}")
    print(f"{sec}: symbols/{sec}.srcaddr.json made again")


def prune(sec):
    """remove the topic folders that the moves left empty"""
    for d in sorted((p for p in srcpath.src_dir(sec).rglob("*") if p.is_dir()), key=lambda p: -len(p.parts)):
        if not any(d.iterdir()): d.rmdir()


def main():
    if len(sys.argv) < 2 or sys.argv[1].startswith("-"): sys.exit(__doc__)
    sec = sys.argv[1]; check = "--check" in sys.argv; revert = "--revert" in sys.argv
    names = json.loads((R / "symbols" / f"{sec}.names.json").read_text())
    man = srcpath.manifest(sec)
    files = {}                                    # label -> current path of its source file
    for p in [p for e in EXTS for p in srcpath.files(sec, e)]:
        label = srcpath.label_of(sec, p)
        if label in files: sys.exit(f"{sec}: two source files for {label}: {files[label]}, {p}")
        files[label] = p
    if revert:
        plan = {l: (f"src/{sec}/{l}{files[l].suffix}", False) for l in man if l in files}
    else:
        plan = targets(sec, names, files)
    moved = {}
    for label, (dst, _) in sorted(plan.items()):
        src = srcpath.repo_rel(files[label])
        if src == dst: continue
        if (R / dst).exists(): sys.exit(f"{sec}: {dst} already exists (for {label})")
        moved[src] = dst
        if not check: move(src, dst)
    new = {} if revert else {l: d for l, (d, _) in plan.items() if d != f"src/{sec}/{l}{files[l].suffix}"}
    suffixed = sorted(l for l, (_, s) in plan.items() if s) if not revert else []
    stay = sorted(l for l in files if l not in plan)
    print(f"{sec}: {len(files)} source files, {len(moved)} {'would be moved' if check else 'moved'}, "
          f"{len(stay)} without a name stay where they are" + (f", {len(suffixed)} names with an address suffix" if not revert else ""))
    for l in suffixed: print(f"  suffix: {l} -> {plan[l][0]}")
    if check: return
    mf = srcpath.manifest_file(sec)
    if new:
        mf.write_text(json.dumps(dict(sorted(new.items())), indent=1) + "\n")
    elif mf.exists():
        r = subprocess.run(["git", "rm", "-q", "--cached", "--ignore-unmatch", mf.relative_to(R).as_posix()], cwd=R)
        mf.unlink()
    srcpath.reload()
    n = rewrite_records(sec, moved)
    if n: print(f"{sec}: {n} source paths in symbols/{sec}.json rewritten")
    prune(sec)
    if moved: remake_srcaddr(sec)


if __name__ == "__main__":
    main()
