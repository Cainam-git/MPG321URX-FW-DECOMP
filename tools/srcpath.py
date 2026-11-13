#!/usr/bin/env python3
"""Where the source of a routine is, and what the compiler is given with it.

Every routine's source is one file. Its place is recorded in symbols/<section>.files.json
({"<label>": "<path relative to the repository root>"}, written by tools/names/layout.py); a label without an entry
there has its file at src/<section>/<label>.c (or .S, .lib). Every tool that turns a label into a source path, lists
the source files of a section, or turns a source file back into its label goes through this module.

The names a C file uses (tools/names/apply.py) are defined in a side list, symbols/defs/<section>/<label>.h, one
'#define <name> <label>' per name. The list is put in front of the file when it is compiled: GCC gets
'-include <list>' (include()), and the Keil copy is written by keil_copy(), which includes the list on the file's
first line so that every line keeps its number.

usage: srcpath.py <section> <label>       prints the source path and the side list of a label
       srcpath.py <section> --label FILE  prints the label whose source FILE is
"""
import functools, importlib.util, json, os, pathlib, sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
EXTS = (".c", ".S", ".lib")
KEIL_LIST = "names.h"          # name of the side list next to the Keil copy


def src_dir(sec):
    return ROOT / "src" / sec


def manifest_file(sec):
    return ROOT / "symbols" / f"{sec}.files.json"


def _abs(p):
    p = pathlib.Path(p)
    return pathlib.Path(os.path.abspath(p if p.is_absolute() else ROOT / p))


@functools.lru_cache(None)
def _manifest(sec):
    p = manifest_file(sec)
    return json.loads(p.read_text()) if p.exists() else {}


@functools.lru_cache(None)
def _reverse(sec):
    return {_abs(ROOT / v): k for k, v in _manifest(sec).items()}


def reload():
    """forget the manifests read so far (after tools/names/layout.py changed them in the same process)"""
    _manifest.cache_clear(); _reverse.cache_clear()


def manifest(sec):
    """label -> path relative to the repository root, for every file that is not at src/<section>/<label>.<ext>"""
    return dict(_manifest(sec))


def path(sec, label, ext=".c"):
    """the file that holds the source of label with this extension: its manifest entry, else
    src/<section>/<label><ext> (also where a new file is written)"""
    m = _manifest(sec).get(label)
    if m and m.endswith(ext): return ROOT / m
    return src_dir(sec) / f"{label}{ext}"


def find(sec, label, exts=EXTS):
    """the existing source file of label, trying the extensions in order; None when there is none"""
    for e in exts:
        p = path(sec, label, e)
        if p.exists(): return p
    return None


def section_of(p):
    """the section a path under src/ belongs to, else None"""
    a = _abs(p)
    try: parts = a.relative_to(ROOT / "src").parts
    except ValueError: return None
    return parts[0] if len(parts) > 1 else None


def label_of(sec, p):
    """the label whose source file p is: the manifest's reverse map, else the file name without its extension"""
    sec = sec or section_of(p)
    return (_reverse(sec).get(_abs(p)) if sec else None) or pathlib.Path(p).stem


def files(sec, ext=".c"):
    """every source file of the section with this extension, in label order"""
    d = src_dir(sec)
    if not d.exists(): return []
    return sorted(d.rglob("*" + ext), key=lambda p: (label_of(sec, p), str(p)))


def rel(sec, p):
    """the path of a source file relative to src/<section> ('FUN_a00dac38.c', or 'sys/<name>.c' after the layout)"""
    return _abs(p).relative_to(src_dir(sec)).as_posix()


def repo_rel(p):
    return _abs(p).relative_to(ROOT).as_posix()


# side lists of names -------------------------------------------------------------------------------------------

def defs_file(sec, label):
    return ROOT / "symbols" / "defs" / sec / f"{label}.h"


def defs_for(sec, p=None, label=None):
    """the side list that belongs in front of file p: the list of the label p is the source of (a draft outside src/
    uses the list of its file-name label), else the list of label; None when there is none"""
    cands = []
    if p is not None:
        sec = sec or section_of(p)
        r = _reverse(sec).get(_abs(p)) if sec else None
        if r: cands.append(r)
        cands.append(pathlib.Path(p).stem)
    if label: cands.append(label)
    for c in cands:
        h = defs_file(sec, c)
        if h.exists(): return h
    return None


def include(sec, p, label=None):
    """GCC arguments that put the side list of p in front of it: ['-include', <list>] or []"""
    h = defs_for(sec, p, label)
    return ["-include", str(h)] if h else []


def names_text(sec, p, label=None):
    """the side list of p as text ('' when there is none)"""
    h = defs_for(sec, p, label)
    return h.read_text() if h else ""


def keil_copy(sec, p, dst, label=None):
    """write the copy of C file p that the Keil compiler reads to dst. With a side list, the list is written next
    to it (names.h) and '#include "names.h" ' is put in front of the file's first line, which opens the header
    comment, so every line keeps its number in the compiler's messages and listing. Returns the list's text."""
    src = pathlib.Path(p).read_bytes(); dst = pathlib.Path(dst)
    h = defs_for(sec, p, label)
    if h is None:
        dst.write_bytes(src); return ""
    t = h.read_bytes()
    (dst.parent / KEIL_LIST).write_bytes(t)
    inc = b'#include "' + KEIL_LIST.encode() + b'" '
    dst.write_bytes(inc + src if src.startswith(b"/*") else inc.rstrip() + b"\n" + src)
    return t.decode("latin1")


@functools.lru_cache(None)
def _apply():
    spec = importlib.util.spec_from_file_location("names_apply", ROOT / "tools" / "names" / "apply.py")
    m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
    return m


def read_labels(sec, p, label=None):
    """the text of source file p with every name put back to its label and the header as it was before the names
    were applied: the code the way the analysis tools (tools/refs, sigs.py, autoc.py) read it"""
    p = pathlib.Path(p); t = p.read_text(errors="replace")
    if p.suffix != ".c": return t
    a = _apply(); h = defs_for(sec, p, label)
    return a.strip_c(t, a.parse_defs(h.read_text()) if h else None)


if __name__ == "__main__":
    if len(sys.argv) == 4 and sys.argv[2] == "--label":
        print(label_of(sys.argv[1], sys.argv[3]))
    elif len(sys.argv) == 3:
        f = find(sys.argv[1], sys.argv[2]); h = defs_file(sys.argv[1], sys.argv[2])
        print(repo_rel(f) if f else "no source file"); print(repo_rel(h) if h.exists() else "no side list")
    else:
        sys.exit(__doc__)
