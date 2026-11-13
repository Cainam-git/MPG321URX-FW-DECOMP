# Menu fonts and texts: source

The fonts and texts of the on-screen menu as text files: flash 0x2101F0-0x29FF4F of
`firmware/MSI_MPG321URX_V021_7F69.bin` (main-processor address 0x1081F0-0x197F4F). Built from these files, the
area is the same 589,152 bytes as the firmware.

## Building and checking

```
python3 -I tools/osd_check.py
```

builds the area and compares it with the firmware; `tools/osd_build.py --out FILE` writes the built bytes to a file.

## Files

| Folder or file | Contents |
|---|---|
| `fonts/font_f0.txt` ... `font_fe.txt` | The 15 fonts: per character its code, width, Unicode character where known, and 36 rows of `#` and `.` |
| `fonts/blocks/` | The 21 run-length packed glyph blocks of the menu layouts and the 2 lookup blocks |
| `texts/00_traditional_chinese.txt` ... `28_slovak.txt` | The texts of each language |
| `texts/common.txt` | Texts used by more than one language, or by tables that are not one text per language |
| `texts/unreferenced.txt` | Texts no table points at |
| `texts/tables.txt` | The tables of text addresses |
| `texts/layout.txt` | The order of the text area |
| `fonts/raw.txt`, `texts/raw.txt` | Bytes that are none of the above (there are none) |

The formats, the languages, how to change a text or a glyph, and the limits are described in
[Menu fonts and texts](../../docs/OSD-TEXT.md).

## Regenerating

`tools/osd_gen.py` generated these files from the firmware. They are the master copy: edit them directly.
Running the generator again overwrites every file except this README, and turns the texts back into those of
FW.021.
