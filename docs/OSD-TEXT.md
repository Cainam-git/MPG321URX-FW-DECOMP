# Menu fonts and texts

How the firmware stores the fonts and texts of the on-screen menu, and how `src/osd/` keeps them as editable
source.

The menu area is flash 0x2101F0–0x29FF4F (main-processor address 0x1081F0–0x197F4F). It lies in the code window
of the main processor, which reads it in place: main-processor address = flash offset − 0x108000.

| Part | Flash | Contents |
|---|---|---|
| Fonts area | 0x2101F0–0x275DE7 | 15 fonts (a glyph table and a width table each), 21 glyph blocks and 2 lookup blocks |
| Text area | 0x275DE8–0x29FF4F | 82 tables of text addresses (10,085 entries) and 5,744 texts in 29 languages |

The text area runs on past flash 0x280000: one text starts at 0x27FFE8 and ends at 0x28002E, and the tables and
texts go on to 0x29FF4F. After it come other data of the main program (`osd_protect_icon_cells` at 0x29FF50,
format texts, the panel mode table).

## Building and checking

```
python3 -I tools/osd_check.py
```

builds the menu area from `src/osd/` and compares it with the firmware:

```
IDENTICAL: 0 of 458256 bytes differ (flash 0x2101F0-0x27FFFF, fonts and texts up to flash 0x280000)
IDENTICAL: 0 of 589152 bytes differ (flash 0x2101F0-0x29FF4F, all fonts and texts)
```

| Tool | What it does |
|---|---|
| `tools/osd_build.py` | Builds the 589,152 bytes of the menu area from `src/osd/` alone and writes them to a file (default `work/osd/osd_area.bin`); `--map FILE` lists the address of every item. |
| `tools/osd_check.py` | Runs the build and compares the result with the firmware; prints each differing byte with the item it is in. |
| `tools/osd_gen.py` | Writes `src/osd/` from the firmware, or from a built menu area (`--image FILE`). `tools/osd_charmap.txt` gives it the character of each glyph. |

The files in `src/osd/` are the master copy. `osd_gen.py` records how they were made; run on the firmware it writes
the same files again.

`tools/rebuild.py` builds the menu area as one of its entries (`src/osd`), so a changed text or glyph is in the
rebuilt firmware file, and the report counts the area as built from source.

## The source files

```
src/osd/
  fonts/font_f0.txt … font_fe.txt    one file per font
  fonts/blocks/*.txt                 one file per glyph block or lookup block
  fonts/raw.txt                      bytes of the fonts area that are no font and no block (none)
  texts/00_traditional_chinese.txt … 28_slovak.txt
                                     the texts used by one language only
  texts/common.txt                   texts used by several languages, or by tables that are not one text per language
  texts/unreferenced.txt             the 300 texts no table points at
  texts/tables.txt                   the 82 tables, entry by entry
  texts/layout.txt                   the order of the text area
  texts/raw.txt                      bytes of the text area that are no table and no text (none)
```

Lines starting with `# ` are comments.

### Font files

```
font F0
glyphs 0x125928
widths 0x12E2F8
rows 36
columns 32

char 41 width 19 is "A"
................................
...                                (36 rows of '#' and '.')
```

The header gives the font code, the two table addresses (main-processor addresses) and the number of picture
columns written per row (bits further right are 0). Each character block gives its code, its width and, where
known, the Unicode character it shows (`is "A"`); then 36 rows. `width F0 29` lines give width-table entries
without a picture. The `is` characters are the source's character map: the build uses them to turn the texts
into codes.

### Text files

```
# osd_oled_care_choice_texts[30] (item 1, english)
16df60.30 "ON"
```

A text line is an id, then the text in quotes. The id is the first table entry that points at the text: table
address (main-processor address, hexadecimal) and entry number; texts without a table are numbered
`unref.001` … `unref.300`. The comment lines above list the table entries that point at the text.

Inside the quotes:

| Written | Byte |
|---|---|
| a character | its code in the current font (the `is` character of a glyph) |
| `{F0}` … `{FE}` | font switch |
| `{XX}` | the code XX (two hexadecimal digits) in the current font, for a glyph without a character |
| `\"`, `\\`, `\{`, `\}` | the characters `"`, `\`, `{`, `}` |

The text starts in font 0xF0; a character must exist in the current font. The length byte is computed. A line can
end with `hidden` and hexadecimal bytes (see [Text format](#text-format)).

1,529 of the 2,417 glyphs have a character in `tools/osd_charmap.txt`: the Latin, Cyrillic, Chinese, Japanese,
Korean, Vietnamese and Hebrew letters, and the Latin letters and digits of the other fonts. Where one picture fits
two characters (ニ and 二, I and l, a Latin and a Cyrillic letter of the same shape) the texts that use the code
decided. Where two codes of one font show the same character, one of them is written as `{XX}`. The syllables of
Thai, Devanagari and Bengali, the joined forms of the Arabic script and the Hebrew letters with vowel points are
written as `{XX}`.

### Tables and layout

`tables.txt` lists each table: `table <address> <entries> <name>`, then one line per entry with the id of its text.

`layout.txt` lists the text area in order. `table` and `raw` lines keep their address. A `text` line places a text
on the next multiple of 8 after the item before it; `text <id> fixed <address>` keeps its address. `gap n` would put
n zero bytes before the next text (the firmware needs none).

### Glyph block files

The header repeats the record (`data`, `record`, `packed` or `size`, `kind`) and the packing places (`cuts`,
`joins`). Kind 0 blocks are written as cell pictures of 24 × 36 (`format cells`), all others as bytes, 27 per line
(`format bytes`).

## Changing a text or a glyph

1. Edit the text in its language file (or a glyph's rows or width in its font file).
2. Run `python3 -I tools/osd_check.py`. It builds the area and lists the bytes that now differ from FW.021;
   `python3 -I tools/osd_build.py --out FILE` writes the built area (flash 0x2101F0–0x29FF4F) to a file.
3. To see the result as source again: `python3 -I tools/osd_gen.py --image FILE --out DIR`. For an edited tree this
   gives the same files back.
4. To get a firmware file with the change: run
   `python3 -I tools/split.py firmware/MSI_MPG321URX_V021_7F69.bin parts` once, then
   `python3 -I tools/rebuild.py FILE --sections osd`, where FILE is the firmware file to write. No compiler runs: only the menu area is built, and every
   other byte comes from the original file. The tool reports `src/osd` as not exact and the file as different from
   the original, which is what a change looks like, and prints the file name sum that belongs in the file's name
   (`MSI_MPG321URX_V021_XXXX.bin`).
5. Compare the file with the original: only bytes of the menu area (file offsets 0x2101F0 to 0x29FF4F) may
   differ. Of the steps in [Modifying the firmware](MODIFYING.md#building-a-modified-file), the ones about naming
   the file and about a second check apply; the ones about changed instructions do not. No firmware file with
   changed texts or glyphs has been run on a monitor.

A text in `texts/common.txt` is used by more than one language or table: a change there shows in all of them.

When a text changes length, the texts after it, up to the next table, move, and the tables get their new
addresses. When the texts between two tables no longer fit, the build stops with a message such as:

```
error: src/osd/texts/layout.txt line 1403: table 1821d4 must stay at 0x1821D4, but the texts before it end at
0x1821E4: text unref.152 (src/osd/texts/unreferenced.txt line 306) and the texts before it need 16 bytes less
(or move a text behind a later fixed item)
```

Room can be made by shortening another text between the same two tables, or by moving a `text` line in
`layout.txt` to a part of the area with room (the build's `--map` file shows where the zero fill is).
A character that the current font does not have stops the build with the fonts that do have it.

Checked edits (each built, read back with `osd_gen.py --image` and compared with the edited tree: the same files):

| Edit | Result |
|---|---|
| None | 0 bytes differ |
| An English text 9 characters shorter (`1814d8.1`) | The texts after it move up; the table entries follow (46 bytes differ) |
| An English text 1 character longer (`1819cc.1`, within its zero fill) | 3 bytes differ |
| A German text 15 characters shorter and an English text 7 longer between the same tables (`181058.3`, `181058.1`) | The English text moves from 0x1814A0 to 0x181498 (124 bytes differ) |
| An English text 23 characters longer (`1819cc.1`) | Refused: no room before table 0x1821D4 |
| One row of glyph 0x41 of font 0xF0 filled | 3 bytes differ |

### Limits

- No font can get more characters, no glyph block can change its packed size, and the tables keep their place and
  their number of entries: these addresses and sizes are stored outside the menu area (see
  [where addresses are stored](#where-addresses-into-the-menu-area-are-stored)).
- A text holds at most 255 bytes.
- A text can only use characters of the fonts. Adding a character means replacing an unused glyph of the font.
- The layout of kind 1 and kind 3 glyph blocks and of the lookup blocks is not shown by the code; they are kept as
  bytes.
- 888 glyphs have no Unicode character in the source (syllables and joined forms, glyphs of the same picture, and
  the 32 glyphs of font 0xFD); texts that use them show `{XX}`.

## Fonts

### Font format

A font is two tables:

- **Glyph table:** 36 words of 32 bits per character, one word per row, top row first. Bit 31 is the leftmost
  pixel. The character with code *c* starts at word 36 × *c*.
- **Width table:** one byte per character: how far the next character starts, in pixels.

A menu cell is 24 pixels wide and 36 rows high (`osd_set_cell_size_mode` mode 4, used for the main menu layer).
`osd_draw_text` (`FUN_a00a31a4`) does not use one cell per character: it adds up the widths, shifts each glyph's
rows to the position reached and ORs them into a buffer of cell pictures, which it sends to the layer's memory
(`osd_ram_write_words24` sends bits 15–8, 23–16 and 31–24 of each row, in that order; bits 7–0 are not sent). The
ink of a glyph can therefore reach past its width into the next character, and a glyph can be up to 32 pixels
wide.

The codes 0xF0–0xFE in a text select the font (`font_get_glyph_column` (`FUN_a00a2eec`) and
`font_get_glyph_width` (`FUN_a00a3024`), one lookup function per font). There is no end marker in a font and no
check of the code: a code beyond the last character reads the bytes after the table.

### The 15 fonts

| Font | Characters | Glyph table (flash) | Width table (flash) | Widths | Used by languages | Characters named in the source |
|---|---:|---|---|---|---|---:|
| 0xF0 | 245 | 0x22D928 | 0x2362F8 | 4–29 | every text starts in it: Latin and Cyrillic letters | 239 |
| 0xF1 | 240 | 0x2423FC | 0x24AB00 | 6–30 | 7 Japanese | 236 |
| 0xF2 | 240 | 0x24ABF0 | 0x2532F0 (241 entries) | 8–29 | 6 Korean | 224 |
| 0xF3 | 239 | 0x2551F0 | 0x25D860 | 7–31 | 10 Simplified Chinese | 237 |
| 0xF4 | 240 | 0x25F878 | 0x267F78 | 9–31 | 0 Traditional Chinese | 237 |
| 0xF5 | 197 | 0x268068 | 0x26EF38 | 8–32 | 11 Thai | 11 |
| 0xF6 | 240 | 0x238DE0 | 0x2414E0 | 8–32 | 13 Hindi | 8 |
| 0xF7 | 194 | 0x26F000 | 0x275D20 | 5–32 | 16 Vietnamese; further characters of 0, 2, 3, 6, 9, 13, 14 and 20–28 (Latin letters, quote marks, Korean and Devanagari syllables) | 147 |
| 0xF8 | 42 | 0x2363F0 | 0x237B90 | 8–24 | 17 Hebrew | 37 |
| 0xF9 | 208 | 0x216088 | 0x21D588 | 4–32 | 18 Bengali | 12 |
| 0xFA | 167 | 0x2101F0 | 0x215FE0 | 4–32 | 15 Persian, 19 Arabic | 10 |
| 0xFB | 55 | 0x25D950 | 0x25F840 | 28–29 | 0 Traditional Chinese (more characters) | 54 |
| 0xFC | 53 | 0x2533E8 | 0x2551B8 | 29 | 10 Simplified Chinese (more characters) | 53 |
| 0xFD | 32 | 0x237BC0 | 0x238DC0 | 14–32 | 13 Hindi (more syllables) | 0 |
| 0xFE | 25 | 0x2415EC | 0x2415D0 | 17–29 | 7 Japanese (more characters) | 24 |

2,417 glyphs in all. The languages column gives the languages whose texts use the font; a few single texts of
other languages switch to it as well. Fonts 0xF1–0xFA also hold the Latin letters and digits their texts mix in
(OSD, PIP/PBP, numbers). Thai, Devanagari, Bengali and the Arabic script are stored as whole syllables or joined
letter forms: one glyph can show several Unicode characters. The width table of font 0xF2 has one entry more than
the font has glyphs.

The 30 table addresses are written in the program code (one lookup function per table, for example
`font_get_glyph_column_code_f0` (`FUN_a00a2c04`) reads `font_glyph_columns_f0` at 0x125928).

## Glyph blocks

Pictures of whole cells (frames, icons, digits of the menu layouts) are not drawn from a font. They lie in the fonts
area between font 0xF9 and font 0xF0 (flash 0x21D658–0x22D927) and are sent unchanged to a menu layer's memory.

Each block has a record of 12 bytes in the main processor's start values (`font_glyph_block_0` … `_20` at RAM
0xA80240A4–0xA802419B, flash 0xEC0A4): packed size (16 bits), kind (8 bits), destination address in the layer
memory (32 bits) and the address of the data (32 bits). `osd_api_write_packed_block` turns the kind into a command
(0 → 0xA0, 1 → 0xB0, 2 → 0xC0, 3 → 0xC1) and `osd_ram_write_packed_block` sends the data. The functions
`font_load_layout0_glyphs` … `font_load_crosshair_icon6` choose the blocks for each menu layout.

| Kind | Command | Blocks | Contents |
|---|---|---|---|
| 0 | 0xA0 | 9–20 | Cell pictures in the format of a text cell: 36 rows of 3 bytes, bytes in the order pixels 16–23, 8–15, 0–7, the leftmost pixel of each byte in its bit 7. The same command and byte order are used for the cells of a text (`osd_ram_write_words24`). |
| 1 | 0xB0 | 0, 3, 4, 6, 7, 8 | Bytes for another part of the layer memory; the code does not show their layout. |
| 3 | 0xC1 | 1, 2, 5 | Bytes for another part of the layer memory; the code does not show their layout. |

All 21 blocks are run-length packed (every caller passes 1 as the first argument): a byte 0x00 or 0xFF is followed
by a repeat count (0 means 256); every other byte stands for itself. The stored data uses runs of at most 255 and
ends a run at every multiple of 108 bytes (one cell picture) and at further places. The source keeps those places
(`cuts`, and `joins` where a run goes on past a cell boundary), so that packing the unpacked bytes again gives the
same bytes.

Two more records of 8 bytes (`osd_layer1_lookup_block` at 0xA80241A0, `osd_layer0_lookup_block` at 0xA80241A8:
size, destination, data address) point at 52 and 436 plain bytes at flash 0x22D738 and 0x22D770, sent with
command 0xD0 by `osd_load_layer_lookup_tables`.

## Texts

### Text format

A text is a length byte *n* followed by *n* bytes. Each byte is a character code of the current font or, from 0xF0
to 0xFE, a switch to that font. Every text starts in font 0xF0. There are no other control bytes: no line breaks (a
text of several rows is several texts) and no end marker. The menu draws a text with `osd_draw_text`, which reads
exactly *n* bytes.

- **Hidden bytes.** 37 texts have bytes after their *n* bytes that are not zero, for example a final full stop
  that the length byte leaves out. They are never drawn. The source keeps them as `hidden` bytes.
- **Alignment.** Every text starts on a multiple of 8; the bytes up to the next item are zero.

### Tables of text addresses

The menu finds a text through a table of 4-byte text addresses. `osd_get_text` (`FUN_a00a3844`) returns entry
*index* of a table. For a translated text the index is item × 29 + language, where the language is byte +8 of
the user settings (`user_settings`). The function `osd_get_oled_care_text` (`FUN_a00ac138`), for example, reads
`osd_oled_care_choice_texts[i * 29 + language]`.

- 82 tables, 10,085 entries. 68 of them have a name in `symbols/leon2m.data.json`.
- 69 tables are used by an address in the program code. For 13 tables no address in the code is their start.
- Several entries can point at the same text. Languages without their own translation of an item point at
  another language's text.
- 300 texts are pointed at by no table and no address in the program code: the menu does not draw them.

### Languages

The menu's language list (`osd_language_texts`, drawn by `osd_draw_language_list` (`FUN_a00a87cc`)) gives the
order of the 29 languages. The names below are read from the glyphs of each entry. Persian and Arabic share font
0xFA: the texts of language 15 use the letters پ, چ and گ, which Arabic does not have; the texts of language 19 use
none of them, and use ة 242 times.

| Index | Language | Name in the list | Font of the name |
|---:|---|---|---|
| 0 | Traditional Chinese | 繁體中文 | 0xF4 |
| 1 | English | English | 0xF0 |
| 2 | French | Français | 0xF0 |
| 3 | German | Deutsch | 0xF0 |
| 4 | Italian | Italiano | 0xF0 |
| 5 | Spanish | Español | 0xF0 |
| 6 | Korean | 한국어 | 0xF2 |
| 7 | Japanese | 日本語 | 0xF1 |
| 8 | Russian | Русский | 0xF0 |
| 9 | Portuguese | Português | 0xF0 |
| 10 | Simplified Chinese | 简体中文 | 0xF3 |
| 11 | Thai | ไทย | 0xF5 |
| 12 | Indonesian | Bahasa Indonesia | 0xF0 |
| 13 | Hindi | four Devanagari glyphs, a space, and two glyphs that show हि and न्दी | 0xF6 |
| 14 | Turkish | Türkçe | 0xF0 |
| 15 | Persian | فارسی (stored reversed) | 0xFA |
| 16 | Vietnamese | Tiếng Việt | 0xF7 |
| 17 | Hebrew | עברית (stored reversed) | 0xF8 |
| 18 | Bengali | বাংলা | 0xF9 |
| 19 | Arabic | three glyphs of the Arabic script | 0xFA |
| 20 | Danish | dansk | 0xF0 |
| 21 | Dutch | Dutch | 0xF0 |
| 22 | Finnish | suomi | 0xF0 |
| 23 | Norwegian | norsk | 0xF0 |
| 24 | Polish | język polski | 0xF0 |
| 25 | Swedish | Svenska | 0xF0 |
| 26 | Czech | čeština | 0xF0 |
| 27 | Hungarian | magyar | 0xF0 |
| 28 | Slovak | slovenčina | 0xF0 |

### Right-to-left languages

The texts are drawn left to right, glyph after glyph. Hebrew, Persian and Arabic texts are therefore stored in the
order they appear on the screen: reversed. Example: the language list's Hebrew entry is the glyphs ת, י, then three
pointed letters (ר, ב, ע with vowel points); read right to left this is עברית.

### Texts whose glyphs do not fit

Some texts of the Panel Protect pages use codes that now hold other characters. Examples:

- Japanese: パネル ("panel") is written with code 0xC4 of font 0xF1 for パ, but 0xC4 is 字 and パ is 0xC7; the
  menu draws 字ネル. The same texts use codes 0x37–0x49 of font 0xFB, which has 55 characters (0x00–0x36), so
  those codes read bytes after its glyph table.
- Button names in the texts of several languages are framed with codes of font 0xF7 that show other characters:
  German `{F7}{76}Ausführen{F7}Ş` (0x76 is i, 0x77 is Ş), Dutch `{F7}ŞUitvoeren{F7}3`, Norwegian
  `{F7}ỷUtfør{F7}ı`. The other texts of these languages frame button names with „ ” (0x87, 0x88) or « »
  (0x8F, 0x90).

The source keeps these codes as they are.

## Where addresses into the menu area are stored

| Address of | Stored in | Number | Consequence |
|---|---|---:|---|
| Each glyph table and width table | the program code (`sethi`/`or` in the lookup functions) | 30 | Fixed place; a font cannot get more characters than fit before the next table. |
| Each glyph block and lookup block | the records in the start values (flash 0xEC0A4–0xEC1AF), with the packed size | 23 | Fixed place and fixed packed size. |
| 69 text tables | the program code | 69 | Fixed place; the tables also keep their number of entries (the code indexes them). |
| One text (at 0x18F3F0, entry 20 of `osd_location_texts`) | the program code: `osd_draw_scope_ratio_choices` (`FUN_a00b3238`) uses 0x18F400 + 0x12C, the start of the table at 0x18F52C | 1 | That text keeps its place. |
| Every text | the tables of the text area | 10,085 | The build writes them again from the new layout: texts can move. |

No stored address outside the menu area points into the text area (`symbols/leon2m.refs.json`). The 13 tables
without a code address also keep their place.
