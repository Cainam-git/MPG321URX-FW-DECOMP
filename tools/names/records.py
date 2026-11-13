#!/usr/bin/env python3
"""Writes docs/RECORDS.md: the named fields of the principal records of the main processor, by offset.

A field is a data name of symbols/leon2m.data.json whose address lies inside a record (the record's name is the
front part of the field's name). usage: python3 -I tools/names/records.py
"""
import json, pathlib

R = pathlib.Path(__file__).resolve().parents[2]
RECORDS = [  # name, address, size, title
    ("user_settings", 0xA802D290, 0x1FC, "User settings record"),
    ("factory_record", 0xA802D274, 0x1C, "Factory record"),
    ("device_settings", 0xA802E1A0, 0x50, "Device settings record"),
    ("part_record", 0xA802E1F0, 0x30, "Part record"),
    ("sys_config", 0xA802E3D0, 0x200, "System configuration record"),
    ("channel_records", 0xA802DF30, 0x78, "Channel record (the first of four)"),
]


def label_address(label):
    """the address in a data label: its first part that is a hexadecimal number (DAT_a8024004, DAT_EXTMEM_0640,
    BITS_20_3, and labels with a word behind the address such as DAT_a8024004_vactive)"""
    for part in label.split("_"):
        try:
            if part: return int(part, 16)
        except ValueError: pass
    raise ValueError(f"no address in the label {label}")


def main():
    data = json.loads((R / "symbols/leon2m.data.json").read_text())["data"]
    out = ["# Record fields", "",
           "The named fields of the principal records of the main processor, by offset. [Data objects](DATA.md) "
           "describes the records, [Function names](NAMES.md) how the names were given. An offset that is missing here "
           "has no name: the code that uses it does not show what it holds, or no function addresses it on its own.", ""]
    for name, base, size, title in RECORDS:
        rows = {}
        for label, d in data.items():
            a = label_address(label)
            if base <= a < base + size and d["name"] != name and not d["name"].endswith("_word"):
                rows.setdefault(a - base, []).append((label, d))
        out += [f"## {title}: `{name}`", "", f"At 0x{base:08X}, 0x{size:X} bytes; {len(rows)} named offsets.", "",
                "| Offset | Name | What it holds | Basis |", "|---|---|---|---|"]
        for off in sorted(rows):
            for label, d in sorted(rows[off], key=lambda x: x[0].startswith("_")):
                out.append(f"| +0x{off:X} | `{d['name']}` | {d['brief'].replace('|', chr(92) + '|')} | {d['basis']} |")
        out.append("")
    (R / "docs/RECORDS.md").write_text("\n".join(out))
    print("docs/RECORDS.md written")


if __name__ == "__main__":
    main()
