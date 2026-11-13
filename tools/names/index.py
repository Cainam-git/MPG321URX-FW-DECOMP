#!/usr/bin/env python3
"""Writes the readable index of the function names of a section, docs/names/<section>.md, and of its data names,
docs/names/<section>-data.md (when symbols/<section>.data.json exists).

One table per subject (the name prefix), in address order: name, label, what the function does, and the basis
of the name. usage: python3 -I tools/names/index.py <section>
"""
import collections, json, pathlib, re, sys

R = pathlib.Path(__file__).resolve().parents[2]
TITLE = {"leon2m": "Main processor (leon2m)", "leon2s": "Input processor (leon2s)", "8051_bank0": "8051 boot loader (bank 0)",
         "8051_bank1": "8051 main application (bank 1)", "8051_bank2": "8051 update agent (bank 2)",
         "tensilica": "Tensilica program (dimming processor)"}
SUBJECT = [
    ("startup", "Start-up"), ("trap", "Traps and crash handling"), ("irq", "Interrupts"), ("timer", "Timers and delays"),
    ("sys", "System control: channels, modes, configuration"), ("input", "Video inputs: detection, measurement, routing"),
    ("hdmi", "HDMI"), ("dp", "DisplayPort"), ("hdcp", "Copy protection (HDCP)"), ("edid", "EDID"),
    ("ddc", "DDC/CI and the service tool"), ("panel", "Panel: timing, output, power, PWM"), ("oled", "OLED panel care"),
    ("pq", "Picture: colour, gamma, windows"), ("hdr", "HDR"), ("osd", "On-screen menu"), ("font", "Menu fonts"),
    ("audio", "Sound"), ("ldc", "Dimming processor and its hardware block"), ("ipc", "Messages between the processors"),
    ("nvram", "Saved settings"), ("flash", "Flash memory"), ("fwupd", "Firmware update"), ("power", "Power states"),
    ("gpio", "Pins"), ("i2c", "I2C"), ("uart", "Serial ports"), ("usb", "USB"), ("reg", "Register access"),
    ("dbg", "Debug facilities"), ("lib", "Library routines"),
]


def label_address(label):
    """the address in a data label: its first part that is a hexadecimal number (DAT_a8024004, DAT_EXTMEM_0640,
    BITS_20_3, and labels with a word behind the address such as DAT_a8024004_vactive)"""
    for part in label.split("_"):
        try:
            if part: return int(part, 16)
        except ValueError: pass
    raise ValueError(f"no address in the label {label}")


def natural(name):
    """sort key: by name without regard to case, numbers inside a name by value (part2 before part10)"""
    return [int(t) if t.isdigit() else t for t in re.split(r"(\d+)", name.lower())]


def cell(s):
    return s.replace("|", "\\|").replace("\n", " ")


def folder_guide(sec, total, files, order):
    """src/<section>/README.md: which subject folder holds what (not for the Tensilica program, whose folder has a
    page of its own)"""
    if sec == "tensilica" or not files: return
    count = collections.Counter(pathlib.Path(v).parent.name for v in files.values())
    module = " (a few files hold a Keil module of several functions)" if sec.startswith("8051") else ""
    out = [f"# {TITLE.get(sec, sec)}: the source folders", "",
           f"The source of this program: {len(files):,} files, one per function{module}, each named after its function and "
           "sorted into a folder for its subject. The first line of every file gives the function's name and its "
           "label (its address in the firmware).", "",
           "| Folder | Subject | Files |", "|---|---|---:|"]
    out += [f"| [`{k}/`]({k}/) | [{t}](../../docs/names/{sec}.md#{k}) | {count[k]:,} |" for k, t in order if count[k]]
    out += ["", f"The [index page](../../docs/names/{sec}.md) lists every function of the program with a one-line "
            f"description ({total:,} entries, with the jump tables, library members and entry points that have no "
            "file of their own); the subject in the table above links to its part of that page. "
            "[Function names](../../docs/NAMES.md) describes how the names were given, and "
            "[How the firmware works: a guided tour](../../docs/TOUR.md) says what the programs do.", ""]
    (R / "src" / sec / "README.md").write_text("\n".join(out))


def main():
    sec = sys.argv[1]
    names = json.loads((R / "symbols" / f"{sec}.names.json").read_text())
    by = collections.defaultdict(list)
    for label, d in names.items():
        by[d["topic"]].append((label, d))
    basis = collections.Counter(d["basis"] for d in names.values())
    mf = R / "symbols" / f"{sec}.files.json"
    files = json.loads(mf.read_text()) if mf.exists() else {}        # label -> path of its source file
    out = [f"# Function names: {TITLE.get(sec, sec)}", "",
           f"{len(names):,} entries from `symbols/{sec}.names.json`, grouped by subject and listed by name; the label of each entry gives its address. "
           "[Function names](../NAMES.md) describes how the names were given and what the *basis* column means. "
           f"A name with a link has a source file of its own, in the folder of its subject (`src/{sec}/<subject>/`); "
           "the other entries are jump tables, library members and entry points inside another function's file.", "",
           "| Basis | Entries |", "|---|---:|"]
    out += [f"| {b} | {basis[b]:,} |" for b in ("proven", "derived", "descriptive")]
    out += ["", "## Subjects", ""]
    order = [(k, t) for k, t in SUBJECT if k in by] + [(k, k) for k in sorted(by) if k not in dict(SUBJECT)]
    out += [f"- [{t}](#{k}) ({len(by[k]):,})" for k, t in order]
    for k, t in order:
        out += ["", f'<a id="{k}"></a>', f"## {t}", "", "| Name | Label | What it does | Basis |", "|---|---|---|---|"]
        out += [(f"| [`{d['name']}`](../../{files[label]}) " if label in files else f"| `{d['name']}` ")
                + f"| `{label}` | {cell(d['brief'])} | {d['basis']} |" for label, d in sorted(by[k], key=lambda x: natural(x[1]["name"]))]
    folder_guide(sec, len(names), files, order)
    p = R / "docs" / "names" / f"{sec}.md"
    p.parent.mkdir(exist_ok=True)
    p.write_text("\n".join(out) + "\n")
    print(f"{p.relative_to(R)}: {len(names)} entries, {len(order)} subjects")
    data_index(sec)


def kind(sec, label):
    """Where a data label lives, from its form and address."""
    if sec == "tensilica":
        if label.startswith("ro_"): return "Read-only data (rodata.S)"
        if label.startswith("data_"): return "Initialised data (data.S)"
        return "RAM without initial values (plain addresses in the code)"
    if label.startswith("BITS_"): return "Bit variables"
    if "INTMEM" in label: return "Internal RAM"
    if "CODE" in label: return "Constant tables in code memory"
    a = label_address(label)
    if "EXTMEM" in label: return "RAM" if 0xA000 <= a < 0xB000 or a < 0x1000 else "Hardware registers and chip memory"
    if 0xA8000000 <= a < 0xA9000000: return "RAM"
    if a < 0x00300000 or 0xA0000000 <= a < 0xA8000000 or 0x9F1B0000 <= a < 0x9F1D0000: return "Constant data in the program"
    return "Hardware registers"


def data_index(sec):
    f = R / "symbols" / f"{sec}.data.json"
    if not f.exists(): return
    data = json.loads(f.read_text())["data"]
    by = collections.defaultdict(list)
    for label, d in data.items(): by[kind(sec, label)].append((label, d))
    basis = collections.Counter(d["basis"] for d in data.values())
    how = ("(RAM addresses). The labelled ones are renamed in the assembly source by `tools/names/xt_apply.py`; addresses that the code "
           "writes as plain numbers have no label, and their names are used only in the comments. "
           if sec == "tensilica" else
           "The source uses the names through the `#define` lists (see "
           "[Function names](../NAMES.md#names-in-the-source)); [Data objects](../DATA.md) describes the principal records. ")
    out = [f"# Data names: {TITLE.get(sec, sec)}", "",
           f"{len(data):,} entries from `symbols/{sec}.data.json`, in address order" + (" " if sec == "tensilica" else ". ") + how +
           "The *basis* column has the same meaning as for the function names.", "",
           "| Basis | Entries |", "|---|---:|"]
    out += [f"| {b} | {basis[b]:,} |" for b in ("proven", "derived", "descriptive")]
    for k in sorted(by):
        rows = sorted(by[k], key=lambda x: (label_address(x[0]), x[0]))
        out += ["", f"## {k}", "", "| Name | Label | What it holds | Basis |", "|---|---|---|---|"]
        out += [f"| `{d['name']}` | `{label}` | {cell(d['brief'])} | {d['basis']} |" for label, d in rows]
    p = R / "docs" / "names" / f"{sec}-data.md"
    p.write_text("\n".join(out) + "\n")
    print(f"{p.relative_to(R)}: {len(data)} entries")


if __name__ == "__main__":
    main()
