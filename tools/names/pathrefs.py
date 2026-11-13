#!/usr/bin/env python3
"""After tools/names/layout.py and xt_layout.py moved the source files: corrects the places that MENTION a source file
by its old name, in the comments of the source files and in the hand-written pages.

  src/<section>/<label>.<ext>     ->  the file's place of today (symbols/<section>.files.json)
  <label>.<ext> by itself         ->  <topic>/<name>.<ext> in a source file of the same section,
                                      the full path src/<section>/<topic>/<name>.<ext> in a page

A mention whose file cannot be found is listed and left as it is. Only text is changed: in C files the comments, in
assembly files the text behind the comment sign, in pages everything.

usage: python3 -I tools/names/pathrefs.py [--check]        (--check: report, change nothing)
"""
import json, pathlib, re, sys

R = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(R / "tools" / "names"))
import apply as AP

SECS = ["leon2m", "leon2s", "8051_bank0", "8051_bank1", "8051_bank2", "tensilica"]
PAGES = ["README.md", "firmware/README.md", "src/tensilica/README.md", "tools/README.md"]
FULL = re.compile(r"src/(leon2m|leon2s|8051_bank[0-2]|tensilica)/([A-Za-z0-9_/]+)\.(c|S|lib)\b")
BARE = re.compile(r"(?<![\w/])((?:thunk_)?FUN_(?:CODE_[0-9a-f]{4}|[0-9a-f]{8})|fn_4000[0-9a-f]{4})\.(c|S|lib)\b")


def main():
    check = "--check" in sys.argv
    man = {}
    for s in SECS:
        p = R / "symbols" / f"{s}.files.json"
        man[s] = json.loads(p.read_text()) if p.exists() else {}
    count = [0]; lost = []

    def fixer(sec, page):
        def full(m):
            if (R / m.group(0)).exists(): return m.group(0)
            new = man[m.group(1)].get(m.group(2).rsplit("/", 1)[-1])
            if new and new.endswith("." + m.group(3)): count[0] += 1; return new
            lost.append(m.group(0)); return m.group(0)
        def bare(m):
            secs = [sec] if sec else [s for s in SECS if m.group(1) in man[s]]
            new = man[secs[0]].get(m.group(1)) if len(secs) == 1 else None
            if not new or not new.endswith("." + m.group(2)):
                if not (sec and (R / "src" / sec / m.group(0)).exists()): lost.append(m.group(0))
                return m.group(0)
            count[0] += 1
            return new if page else new[len(f"src/{secs[0]}/"):]
        return lambda t: BARE.sub(bare, FULL.sub(full, t))

    changed = 0
    def put(p, new):
        nonlocal changed
        if new != p.read_text():
            changed += 1
            if not check: p.write_text(new)

    for sec in SECS:
        fx = fixer(sec, False)
        for p in sorted((R / "src" / sec).rglob("*.c")):
            put(p, "".join(x if code or not x.startswith(("/*", "//")) else fx(x) for code, x in AP.pieces(p.read_text())))
        mark = "#" if sec == "tensilica" else "!"
        for p in sorted((R / "src" / sec).rglob("*.S")):
            out = []
            for l in p.read_text().split("\n"):
                i = l.find(mark)
                if l.lstrip().startswith(".include"): i = l.find(mark, l.rfind('"'))     # never the included file name
                out.append(l if i < 0 else l[:i] + fx(l[i:]))
            put(p, "\n".join(out))
    fx = fixer(None, True)
    for p in [R / x for x in PAGES] + sorted((R / "docs").glob("*.md")):
        if p.exists(): put(p, fx(p.read_text()))
    print(f"{count[0]} mentions {'would be' if check else ''} corrected in {changed} files; {len(lost)} not found")
    for x in sorted(set(lost)): print("  not found:", x)


if __name__ == "__main__":
    main()
