#!/usr/bin/env python3
"""Puts the routine names of symbols/tensilica.names.json, and the data names of symbols/tensilica.data.json,
into the assembly source of the Tensilica program (src/tensilica/).

The assembly source has no preprocessor, so the names are real symbol names: this script renames the labels
fn_<address>, data_<address> and ro_<address> in every file of src/tensilica/. The bytes of the program do not
change (check with tools/xtensa_check.py). In detail:

1. Line 1 of each routine file fn_<address>.S becomes

       # <name>  (fn_<address>): <address range, file offsets, number of instructions>

   and a line "# Name basis: <proven | derived | descriptive> - <the evidence>" follows it.
2. Each definition keeps its label in a comment:  <name>:  # fn_<address>   (data: <name> = ...  # data_<address>).
3. The labels are replaced by the names everywhere else: in the code (calls, .type and .size directives, .word
   entries of the literal, data and jump tables) and in the comments ("Called from:", "Calls:", "used by:" lists,
   the descriptions). The lists are wrapped again at 110 characters, and the comment of an instruction line stays
   in column 41. Texts in double quotes are not touched.
4. The .include lines of tensilica.S keep the file names and get the routine's name as a comment.

The routine files are named after their routines and sorted into subject folders by tools/names/xt_layout.py
(src/tensilica/<topic>/<name>.S, recorded in symbols/tensilica.files.json); a routine is found by its address from
line 1 of its file. Before that step the file names are the labels (fn_<address>.S).
Data addresses that the code writes as plain numbers (RAM without initial values) have no label; their names
are listed in the table and in docs/names/tensilica-data.md, but nothing in the source is renamed for them.

The script first undoes its own earlier changes, so it can be run again after names change; running it twice
changes nothing. --remove only undoes them: every name becomes its label again (also where a comment uses a name
by itself), the "Name basis" lines and the name comments are removed.

usage: python3 -I tools/names/xt_apply.py [--remove | --check]      (--check: report, change nothing)
"""
import json, pathlib, re, sys, textwrap

R = pathlib.Path(__file__).resolve().parents[2]
SRC = R / "src" / "tensilica"
WIDTH = 110
LISTS = ("Called from", "Calls", "Addresses loaded", "used by")
STR_CODE = re.compile(r'"(?:[^"\\\n]|\\.)*"')
STR_COMMENT = re.compile(r'"[^"\n]*"|(?<!\w)\'[^\'\n]*\'(?!\w)')
LABEL_FORM = re.compile(r"(?:fn_4000[0-9a-f]{4}|(?:data|ro)_3ffe[0-9a-f]{4})")


def tables():
    names = {k: v for k, v in json.loads((R / "symbols" / "tensilica.names.json").read_text()).items()}
    m = {k: v["name"] for k, v in names.items()}
    df = R / "symbols" / "tensilica.data.json"
    if df.exists():
        m.update({k: v["name"] for k, v in json.loads(df.read_text())["data"].items() if LABEL_FORM.fullmatch(k)})
    rev = {}
    for k, v in m.items():
        if v in rev or LABEL_FORM.fullmatch(v): sys.exit(f"name {v} is not unique or has the form of a label")
        rev[v] = k
    return names, m, rev


def token_re(words, labels):
    alt = "|".join(sorted(map(re.escape, words), key=len, reverse=True))
    return re.compile(r"\b(?:%s)\b%s" % (alt, r"(?!\.S\b)" if labels else ""))


def replace(text, tok, mapping, protect):
    """Replace the tokens of text outside the protected spans (texts in quotes)."""
    out, pos = [], 0
    for m in protect.finditer(text):
        out.append(tok.sub(lambda x: mapping[x.group(0)], text[pos:m.start()])); out.append(m.group(0)); pos = m.end()
    out.append(tok.sub(lambda x: mapping[x.group(0)], text[pos:]))
    return "".join(out)


def comment_start(line):
    """Index of the '#' that starts the comment of an assembly line (outside strings), or -1."""
    q = False; i = 0
    while i < len(line):
        c = line[i]
        if q and c == "\\": i += 2; continue
        if c == '"': q = not q
        elif c == "#" and not q: return i
        i += 1
    return -1


def col(code, comment, width=40):
    n = len(code.expandtabs(8))
    return code + (" " * (width - n) if n < width else " ") + "# " + comment


def wrap_list(prefix, items, width=WIDTH):   # the wrapping of tools/xtensa_gen.py
    lines, cur = [], prefix
    for i, it in enumerate(items):
        piece = it + (", " if i < len(items) - 1 else "")
        if len(cur) + len(piece) > width and cur.strip() != prefix.strip():
            lines.append(cur.rstrip()); cur = "#" + " " * (len(prefix) - 1) + piece
        else:
            cur += piece
    lines.append(cur.rstrip())
    return lines


def convert(lines, tok, mapping):
    """Replace labels by names (or back) in all lines; lists and instruction comments are laid out again."""
    out, i = [], 0
    while i < len(lines):
        line = lines[i]
        m = re.match(r"# (%s): " % "|".join(LISTS), line)
        if m:
            prefix = m.group(0); j = i + 1
            cont = "#" + " " * (len(prefix) - 1)
            while j < len(lines) and lines[j].startswith(cont) and lines[j][len(cont):len(cont) + 1] not in ("", " "):
                j += 1
            block = lines[i:j]
            items = " ".join([block[0][len(prefix):]] + [b[len(cont):] for b in block[1:]]).split(", ")
            if wrap_list(prefix, items) == block:
                out += wrap_list(prefix, [replace(it, tok, mapping, STR_COMMENT) for it in items]); i = j; continue
        k = comment_start(line)
        code, com = (line, "") if k < 0 else (line[:k], line[k:])
        ncode = replace(code, tok, mapping, STR_CODE)
        ncom = replace(com, tok, mapping, STR_COMMENT)
        if ncode != code and com and code.strip() and line == col(code.rstrip(), com[2:]) and com.startswith("# "):
            out.append(col(ncode.rstrip(), ncom[2:]))
        else:
            out.append(ncode + ncom)
        i += 1
    return out


def strip(text, m, rev):
    """Undo the changes of this script: names back to labels."""
    lines = text.split("\n")
    m1 = re.match(r"# (\S+)  \((fn_4000[0-9a-f]{4})\): (.*)$", lines[0])
    head = None
    if m1 and m.get(m1.group(2)) == m1.group(1):
        head = "# %s: %s" % (m1.group(2), m1.group(3)); lines = lines[1:]
        if lines and lines[0].startswith("# Name basis: "):
            lines = lines[1:]
            while lines and lines[0].startswith("#   "): lines = lines[1:]
    out = []
    for line in lines:
        d = re.match(r"^(\S+)(:| = .*?) +# (\S+)$", line)
        if d and m.get(d.group(3)) == d.group(1):
            out.append(d.group(3) + d.group(2)); continue
        d = re.match(r'^(\t\.include\t"(fn_4000[0-9a-f]{4})\.S") +# (\S+)$', line)
        if d and m.get(d.group(2)) == d.group(3):
            out.append(d.group(1)); continue
        if re.match(r'^\t\.include\t"[^"]+"$', line):          # an include line without a comment stays as it is
            out.append(line); continue
        out.append(None); out.append(line)
    # lines marked None are the ones to convert; definitions and includes are already done
    res, todo = [], []
    it = iter(out)
    for x in it:
        if x is None: todo.append(next(it)); continue
        if todo: res += convert(todo, token_re(rev, False), rev); todo = []
        res.append(x)
    if todo: res += convert(todo, token_re(rev, False), rev)
    return "\n".join(([head] if head else []) + res)


def apply(text, label, names, m):
    lines = text.split("\n")
    head = []
    if label.startswith("fn_") and label in names and lines[0].startswith("# %s: " % label):
        d = names[label]
        head = ["# %s  (%s): %s" % (d["name"], label, lines[0][len(label) + 4:])]
        head += textwrap.wrap("Name basis: %s - %s" % (d["basis"], d["evidence"]), WIDTH - 2,
                              initial_indent="# ", subsequent_indent="#   ", break_on_hyphens=False)
        lines = lines[1:]
    tok = token_re(m, True)
    res, todo = [], []
    for line in lines:
        d = re.match(r"^(%s)(:| = .*)$" % LABEL_FORM.pattern, line)
        if d and d.group(1) in m:
            if todo: res += convert(todo, tok, m); todo = []
            res.append(col(m[d.group(1)] + d.group(2), d.group(1))); continue
        d = re.match(r'^\t\.include\t"(fn_4000[0-9a-f]{4})\.S"$', line)
        if d and d.group(1) in m:
            if todo: res += convert(todo, tok, m); todo = []
            res.append(col(line, m[d.group(1)])); continue
        if re.match(r'^\t\.include\t"[^"]+"$', line):          # a file already named after its routine (xt_layout.py)
            if todo: res += convert(todo, tok, m); todo = []
            res.append(line); continue
        todo.append(line)
    if todo: res += convert(todo, tok, m)
    return "\n".join(head + res)


def main():
    remove = "--remove" in sys.argv; check = "--check" in sys.argv
    names, m, rev = tables()
    changed = 0
    mf = R / "symbols" / "tensilica.files.json"
    where = {str(R / p): l for l, p in json.loads(mf.read_text()).items()} if mf.exists() else {}
    for f in sorted(SRC.rglob("*.S")):
        old = f.read_text()
        new = strip(old, m, rev)
        if not remove: new = apply(new, where.get(str(f), f.stem), names, m)
        if new != old:
            changed += 1
            if not check: f.write_text(new)
    print("%s: %d of %d files %s (%d routine names, %d data names)" % (
        "remove" if remove else "apply", changed, len(list(SRC.rglob("*.S"))),
        "would change" if check else "changed", sum(1 for k in m if k.startswith("fn_")),
        sum(1 for k in m if not k.startswith("fn_"))))


if __name__ == "__main__":
    main()
