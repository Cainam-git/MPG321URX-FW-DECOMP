#!/usr/bin/env python3
"""Puts the function names of symbols/<section>.names.json, and the data names of symbols/<section>.data.json,
into the source files of a section.

For every C source file of a label (tools/srcpath.py says where it is) this script

1. writes the name and description of the function at the top of the file's header comment:

       /* <name>  (<label>)
        *
        * <what the function does>
        * Returns: ...                (when recorded)
        * Note: ...                   (when recorded)
        * Name basis: <proven | derived | descriptive> - <the evidence>
        *
        * Matching notes
        * --------------
        * <the header the file had before: flags, data layouts, source forms>
        */

2. writes one line per function label that the code uses, and one per data label that has a name in
   symbols/<section>.data.json,

       #define <name> <label>

   into the file's side list symbols/defs/<section>/<label>.h. The build tools put that list in front of the file
   when they compile it (tools/srcpath.py: GCC '-include', the Keil copy includes it on its first line);

3. replaces the labels in the code by the names.

The compiler still sees the labels, because its preprocessor puts them back before anything is compiled, so
the build stays byte-exact and the checking tools keep linking by label. Comments and string literals are
not touched. A label keeps its place in the code when its name is already used for something else in that
file, and in the 8051 sections when the name is longer than 31 characters (the 8051 compiler tells identifiers
apart by their first 32 characters). Assembly files (.S) only get the header lines and a list of the labels they use.

The script undoes its own earlier changes before it applies the current names, so it can be run again after
names change. With --remove it only undoes them (names out of the code, side lists deleted). With --infile it
writes each list into the file itself, below the header comment, between the lines
"/* Names used in this file; ... */" and "/* End of names. */", and deletes the side lists (the earlier form);
a later run without --infile moves the lists back out.

usage: python3 -I tools/names/apply.py <section> [--check] [--infile | --remove]   (--check: report, change nothing)
"""
import json, pathlib, re, sys, textwrap

R = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(R / "tools"))
import srcpath
MARK = "Matching notes"
BEGIN = "/* Names used in this file; the label behind each name is what the checking tools link by. */"
SIDE = ("/* Names used in the source of {label}; the label behind each name is what the checking tools link by.\n"
        "   Written by tools/names/apply.py; the build puts this list in front of the file when it compiles it. */")
BEGIN_OLD = "/* Names of the routines this file refers to; the label is what the checking tools link by. */"
DATA = "/* Stored data. */"
END = "/* End of names. */"
WIDTH = 108
LABEL = re.compile(r"\b(?:thunk_)?FUN_(?:CODE_[0-9a-f]{4}|[0-9a-f]{8})\b")
IDENT = re.compile(r"[A-Za-z_]\w*")
RESERVED = set("""auto break case char const continue default do double else enum extern float for goto if inline int
long register restrict return short signed sizeof static struct switch typedef union unsigned void volatile while
asm typeof main errno NULL true false""".split())


def block(d, label):
    """The lines of the name block, without comment decoration."""
    out = [f"{d['name']}  ({label})", ""]
    out += textwrap.wrap(d["brief"], WIDTH)
    for p in d.get("params") or []:
        name, meaning = p["name"], p["meaning"].strip()
        if meaning.lower().startswith(name.lower() + ":"): meaning = meaning[len(name) + 1:].strip()
        if not meaning or meaning.lower().replace("_", " ") == name.lower().replace("_", " "):
            out.append("  " + name); continue           # a note that only repeats the name is left out
        out += textwrap.wrap(f"{name}: {meaning}", WIDTH, initial_indent="  ", subsequent_indent="      ")
    if d.get("returns"):
        out += textwrap.wrap("Returns: " + d["returns"], WIDTH, subsequent_indent="  ")
    if d.get("notes"):
        out += textwrap.wrap("Note: " + d["notes"], WIDTH, subsequent_indent="  ")
    out += textwrap.wrap(f"Name basis: {d['basis']} - {d['evidence']}", WIDTH, subsequent_indent="  ")
    return out


def pieces(text):
    """Splits C text into (is_code, part) pieces; comments, string and character literals are not code."""
    out = []; i = 0; n = len(text); start = 0
    while i < n:
        c = text[i]; two = text[i:i + 2]
        if two == "/*":
            j = text.find("*/", i + 2); j = n if j < 0 else j + 2
        elif two == "//":
            j = text.find("\n", i); j = n if j < 0 else j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
        else:
            i += 1; continue
        if i > start: out.append((True, text[start:i]))
        out.append((False, text[i:j])); i = start = j
    if start < n: out.append((True, text[start:]))
    return out


def sub_code(text, fn):
    return "".join(fn(p) if code else p for code, p in pieces(text))


def parse_defs(text):
    """name -> label from the '#define <name> <label>' lines of a list"""
    return {m.group(1): m.group(2) for m in re.finditer(r"^#define (\w+) +(\w+)$", text, re.M)}


def strip_c(text, side=None):
    """Returns the file as it was before this script touched it. side: the names of the file's side list
    (name -> label), when the list is kept outside the file."""
    defs = dict(side or {})
    begin = BEGIN if BEGIN in text else BEGIN_OLD
    if begin in text and END in text:
        a = text.index("\n" + begin); b = text.index(END) + len(END)
        defs.update(parse_defs(text[a:b]))
        text = text[:a] + text[b:]
    if defs:
        pat = re.compile(r"\b(" + "|".join(sorted(map(re.escape, defs), key=len, reverse=True)) + r")\b")
        head_end = text.index("*/") + 2 if text.lstrip().startswith("/*") else 0
        text = text[:head_end] + sub_code(text[head_end:], lambda p: pat.sub(lambda m: defs[m.group(1)], p))
    body = text.lstrip()
    if body.startswith("/*"):
        end = body.index("*/"); old = body[2:end]
        if "\n * " + MARK + "\n" in old:
            rest = old.split("\n * " + MARK + "\n", 1)[1].split("\n", 1)
            notes = rest[1] if len(rest) > 1 else ""
            first, _, more = notes.partition("\n")
            first = first[3:] if first.startswith(" * ") else first.lstrip(" *")
            text = text[: len(text) - len(body)] + "/* " + first + ("\n" + more if more else "") + body[end:]
    return text


def apply_c(text, label, names, maxlen=255, data=None, side=None, infile=True):
    """The file with the names applied. infile: the list goes into the file (returns the text); else it goes into
    the side list (returns (text, list text or None)). side: the names of the file's present side list."""
    if not infile:
        new = apply_c(text, label, names, maxlen, data, side)
        if BEGIN not in new: return new, None
        a = new.index("\n" + BEGIN); b = new.index(END) + len(END)
        return new[:a] + new[b:], SIDE.format(label=label) + new[a + 1 + len(BEGIN):b] + "\n"
    data = data or {}
    text = strip_c(text, side)
    d = names[label]
    body = text.lstrip(); lead = text[: len(text) - len(body)]
    if body.startswith("/*"):
        end = body.index("*/"); old = body[2:end]
        first, _, more = old.partition("\n")
        notes = (" * " + first.strip() + "\n" if first.strip() else "") + more
        head = "/* " + "".join((" * " if i else "") + l + "\n" for i, l in enumerate(block(d, label))).replace(" * \n", " *\n")
        head += " *\n * " + MARK + "\n * " + "-" * len(MARK) + "\n" + notes
        code = body[end + 2:]; head += "*/"
    else:
        head = "/* " + "".join((" * " if i else "") + l + "\n" for i, l in enumerate(block(d, label))).replace(" * \n", " *\n") + " */"
        code = "\n" + body
        lead = lead + ""
    code_text = "".join(p for c, p in pieces(code) if c)
    idents = set(IDENT.findall(code_text))
    # automatic labels, and other labels of the table where the code calls or declares them as a function
    used = sorted(t for t in idents if t in names and (LABEL.fullmatch(t) or re.search(r"\b" + re.escape(t) + r"\s*\(", code_text)))
    table = {}
    for lab in used:
        nm = names[lab]["name"]
        if nm != lab and IDENT.fullmatch(nm) and nm not in RESERVED and nm not in idents and len(nm) <= maxlen \
                and nm not in table.values():
            table[lab] = nm
    dtable = {}
    for lab in sorted(t for t in idents if t in data):
        nm = data[lab]["name"]
        if IDENT.fullmatch(nm) and nm not in RESERVED and nm not in idents and len(nm) <= maxlen and nm not in table.values() and nm not in dtable.values():
            dtable[lab] = nm
    if table or dtable:
        w = max(len(n) for n in list(table.values()) + list(dtable.values()))
        sect = BEGIN + "\n" + "".join(f"#define {n.ljust(w)} {l}\n" for l, n in sorted(table.items(), key=lambda x: x[1]))
        if dtable: sect += DATA + "\n" + "".join(f"#define {n.ljust(w)} {l}\n" for l, n in sorted(dtable.items(), key=lambda x: x[1]))
        sect += END; table = dict(table, **dtable)
        pat = re.compile(r"\b(" + "|".join(sorted(map(re.escape, table), key=len, reverse=True)) + r")\b")
        code = sub_code(code, lambda p: pat.sub(lambda m: table[m.group(1)], p))
        return lead + head + "\n" + sect + code
    return lead + head + code


def strip_s(text):
    src = text.split("\n"); n = 0
    while n < len(src) and src[n].startswith("!"): n += 1
    old = src[:n]
    for i, l in enumerate(old):
        if l.strip() == "! " + MARK and i + 1 < len(old):
            return "\n".join(old[i + 2:] + src[n:])
    return text


def apply_s(text, label, names):
    text = strip_s(text)
    lines = block(names[label], label)
    used = sorted(set(IDENT.findall(text)) - {label})
    legend = [f"{l} = {names[l]['name']}" for l in used if l in names and names[l]["name"] != l]
    if legend:
        lines += ["", "Labels used below:"] + ["  " + x for x in legend]
    head = [("! " + l).rstrip() for l in lines] + ["!", "! " + MARK, "! " + "-" * len(MARK)]
    return "\n".join(head) + "\n" + text


def norm(text):
    """A header that began with an empty first line comes back with its text on the first line."""
    return re.sub(r"^/\*\n \* ", "/* ", text.lstrip(), count=1)


def address_labels(sec, names):
    """FUN_<address> spellings of a function that are not its key in the table, with the function's entry: the
    address of a function whose key is its original name (MAILBOX_DUMP is also called as FUN_a0072b04), and the
    second address under which the code of another program part calls it (see tools/refs/aliases.py: in leon2m the
    start-up code at 0xA0028000 is called as 0x40088000 + offset from the main program and the main program as its
    listing address - 0xA0060000 from the start-up code; in leon2s the first and the third program part call each
    other 0xF10000 apart)."""
    ff = R / "symbols" / f"{sec}.functions.json"
    if not sec.startswith("leon") or not ff.exists(): return {}
    out = {}
    for f in json.loads(ff.read_text())["functions"]:
        key, s = f["name"], f["start"]
        if key not in names: continue
        forms = [s]
        if sec == "leon2m":
            if 0xA0028000 <= s < 0xA002FB44: forms.append(s - 0xA0028000 + 0x40088000)
            if 0xA0060000 <= s < 0xA0060000 + 0x1A8654: forms.append(s - 0xA0060000)
        else:
            if 0xA0060000 <= s < 0xA00E0000: forms.append(s + 0xF10000)
            if 0xA00C0000 <= s < 0xA00DEEC8: forms.append(s - 0xF10000)
        for a in forms:
            lab = "FUN_%08x" % a
            if lab not in names: out.setdefault(lab, names[key])
    return out


def main():
    sec = sys.argv[1]; check = "--check" in sys.argv; remove = "--remove" in sys.argv; infile = "--infile" in sys.argv
    if remove and infile: sys.exit("--remove and --infile exclude each other")
    names = json.loads((R / "symbols" / f"{sec}.names.json").read_text())
    dfile = R / "symbols" / f"{sec}.data.json"
    data = json.loads(dfile.read_text())["data"] if dfile.exists() else {}
    # names that carry an address (func_0x<address>, symbols/<section>.aliases.json) take the name of the function
    # they stand for
    afile = R / "symbols" / f"{sec}.aliases.json"
    full = dict(names)
    if afile.exists():
        for a in json.loads(afile.read_text())["names"]:
            if a["stands_for"] in names and a["name"] not in full: full[a["name"]] = names[a["stands_for"]]
    for lab, d in address_labels(sec, names).items(): full.setdefault(lab, d)
    changed = nofile = bad = 0; seen = set()
    for label in names:
        p = srcpath.find(sec, label, (".c", ".S"))
        if p is None:
            nofile += 1; continue                        # jump tables and library members have no source file
        text = p.read_text(); asm = p.suffix == ".S"
        h = srcpath.defs_file(sec, label); old_list = h.read_text() if h.exists() else None; seen.add(h)
        side = parse_defs(old_list) if old_list else None
        base = strip_s(text) if asm else strip_c(text, side)
        new_list = None
        if remove: new = base
        elif asm: new = apply_s(text, label, names)
        elif infile: new = apply_c(text, label, full, 31 if sec.startswith("8051") else 255, data, side)
        else: new, new_list = apply_c(text, label, full, 31 if sec.startswith("8051") else 255, data, side, infile=False)
        if not remove and norm(strip_s(new) if asm else strip_c(new, parse_defs(new_list) if new_list else None)) != norm(base):
            bad += 1; print("not reversible, left unchanged:", srcpath.repo_rel(p)); continue
        if new != text or new_list != old_list:
            changed += 1
            if not check:
                p.write_text(new)
                if new_list is not None: h.parent.mkdir(parents=True, exist_ok=True); h.write_text(new_list)
                elif old_list is not None: h.unlink()
            elif changed <= 20: print("would change:", srcpath.repo_rel(p))
    d = srcpath.defs_file(sec, "x").parent      # side lists of labels that have no source file (any more)
    stale = sorted(set(d.glob("*.h")) - seen) if d.exists() else []
    for h in stale:
        if not check: h.unlink()
        else: print("would delete:", srcpath.repo_rel(h))
    if not check and d.exists() and not any(d.iterdir()): d.rmdir()
    if not check and d.parent.exists() and not any(d.parent.iterdir()): d.parent.rmdir()
    print(f"{sec}: {len(names)} names, {changed} files {'would change' if check else 'changed'}, "
          f"{nofile} names without a source file, {bad} files skipped"
          + (f", {len(stale)} side lists without a source file {'would be' if check else ''} deleted" if stale else ""))


if __name__ == "__main__":
    main()
