#!/usr/bin/env python3
"""Generate the source of the on-screen menu's fonts and texts (src/osd/) from the firmware.

Usage: python3 tools/osd_gen.py [--image FILE] [--out DIR] [--quiet]

  --image FILE  read the menu area from FILE instead of the firmware: either a whole firmware file, or the
                output of tools/osd_build.py (the bytes of flash 0x2101F0-0x29FF4F). Everything outside the
                menu area (the glyph block records in the main processor's start values) is still read from
                firmware/MSI_MPG321URX_V021_7F69.bin.
  --out DIR     write the source tree to DIR (default src/osd); files in DIR that this script does not write
                are left alone
  --quiet       print nothing but errors

The files in src/osd/ are the master copy; this script records how they were made and can make them again,
for example to check a build (read the built bytes back with --image and compare the two trees). Running it
on the firmware writes the same files again, apart from README.md, which it does not touch.

What the script reads besides the menu area:
  symbols/leon2m.refs.json   the stored addresses: which words of the text area are text addresses, and the
                             records in the start values that point at glyph blocks
  symbols/leon2m.data.json   names of tables
  symbols/leon2m.numsym.json and the C and assembly source in src/leon2m/: every address of the menu area
                             that the program code uses (those items must keep their place)
  tools/osd_charmap.txt      the Unicode character of each glyph, where it is known

The menu area (flash 0x2101F0-0x29FF4F, main-processor address = flash offset - 0x108000):
  fonts area  flash 0x2101F0-0x275DE7: 15 fonts (glyph table and width table each) and 23 glyph blocks
  text area   flash 0x275DE8-0x29FF4F: tables of text addresses and the texts
The format of every part is described in docs/OSD-TEXT.md.
"""
import json, os, re, struct, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FW = REPO + '/firmware/MSI_MPG321URX_V021_7F69.bin'
WINDOW = 0x108000                      # flash offset of main-processor address 0
AREA_LO, TEXT_LO, AREA_HI = 0x2101F0, 0x275DE8, 0x29FF50   # flash offsets
ROWS = 36                              # rows of a glyph (cell height of the main menu layer)
CELL = ROWS * 3                        # bytes of one cell picture in a glyph block (24 pixels per row)
START_VALUES_FLASH, START_VALUES_RAM = 0xEC000, 0xA8024000
FONT_CODES = list(range(0xF0, 0xFF))
LANG_COUNT = 29
# Language index (user settings byte +8) -> file name of its texts. The language is named by its entry in
# osd_language_texts, the list the menu shows; see docs/OSD-TEXT.md for how each was read.
LANGUAGES = [
    '00_traditional_chinese', '01_english', '02_french', '03_german', '04_italian', '05_spanish', '06_korean',
    '07_japanese', '08_russian', '09_portuguese', '10_simplified_chinese', '11_thai', '12_indonesian',
    '13_hindi', '14_turkish', '15_persian', '16_vietnamese', '17_hebrew', '18_bengali', '19_arabic',
    '20_danish', '21_dutch', '22_finnish', '23_norwegian', '24_polish', '25_swedish', '26_czech',
    '27_hungarian', '28_slovak',
]
LANGUAGE_TABLE = 0x18D3D4              # osd_language_texts: entry i is the name of language i


def cpu(flash):
    return flash - WINDOW


def align8(x):
    return (x + 7) & ~7


def load_image(path):
    fw = bytearray(open(FW, 'rb').read())
    if path:
        data = open(path, 'rb').read()
        if len(data) == len(fw):
            fw[AREA_LO:AREA_HI] = data[AREA_LO:AREA_HI]
        elif len(data) == AREA_HI - AREA_LO:
            fw[AREA_LO:AREA_HI] = data
        else:
            sys.exit('%s: %d bytes; expected a firmware file or %d bytes of the menu area'
                     % (path, len(data), AREA_HI - AREA_LO))
    return bytes(fw)


def word(img, off):
    return struct.unpack('>I', img[off:off + 4])[0]


# ---------------------------------------------------------------------------------------------------------
# What the rest of the firmware knows about the menu area

def code_addresses():
    """Main-processor addresses inside the menu area that the program code uses, with the files using them."""
    found = {}
    pat = re.compile(r'\b[A-Za-z]+_00([0-9a-f]{6})\b')
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import srcpath                      # where each function's source file is; read_labels puts the labels back
    for path in srcpath.files('leon2m', '.c') + srcpath.files('leon2m', '.S'):
        name = srcpath.label_of('leon2m', path) + path.suffix
        text = srcpath.read_labels('leon2m', path)
        for m in pat.finditer(text):
            a = int(m.group(1), 16)
            if cpu(AREA_LO) <= a < cpu(AREA_HI):
                found.setdefault(a, set()).add(name)
        # A symbol plus a constant: the address used is the sum (one case, osd_draw_scope_ratio_choices).
        for m in re.finditer(r'\b[A-Za-z]+_00([0-9a-f]{6})\s*\+\s*(0x[0-9a-f]+)\b', text):
            a = int(m.group(1), 16) + int(m.group(2), 16)
            if cpu(AREA_LO) <= a < cpu(AREA_HI):
                found.setdefault(a, set()).add(name)
        for m in re.finditer(r'#define\s+\w+_OFFSET\s+(0x[0-9a-f]+)', text):
            for b in re.finditer(r'\b[A-Za-z]+_00([0-9a-f]{6})\s*\+\s*\w+_OFFSET', text):
                a = int(b.group(1), 16) + int(m.group(1), 16)
                if cpu(AREA_LO) <= a < cpu(AREA_HI):
                    found.setdefault(a, set()).add(name)
    numsym = json.load(open(REPO + '/symbols/leon2m.numsym.json'))
    for fn, pairs in numsym.items():
        for _, sym in pairs:
            a = int(sym.split('_')[1], 16)
            if cpu(AREA_LO) <= a < cpu(AREA_HI):
                found.setdefault(a, set()).add(fn + '.c')
    return found


def data_names():
    d = json.load(open(REPO + '/symbols/leon2m.data.json'))['data']
    names = {}
    for label, v in d.items():
        m = re.match(r'[A-Za-z]+_([0-9a-f]{8})$', label)
        if m:
            names[int(m.group(1), 16)] = v['name']
    return names


def stored_refs():
    d = json.load(open(REPO + '/symbols/leon2m.refs.json'))
    return d['refs']


# ---------------------------------------------------------------------------------------------------------
# Character maps

def load_charmap():
    """tools/osd_charmap.txt: lines 'F0 41 ABC' (font, first code, the characters of that code and the codes
    after it; U+FFFD skips a code) or 'F0 20 U+0020' (one character by its number)."""
    cmap = {f: {} for f in FONT_CODES}
    path = REPO + '/tools/osd_charmap.txt'
    for n, line in enumerate(open(path, encoding='utf-8'), 1):
        line = line.rstrip('\n')
        if not line or line.startswith('#'):
            continue
        f, code, chars = line.split(' ', 2)
        if chars.startswith('U+'):
            chars = chr(int(chars[2:], 16))
        f = int(f, 16)
        code = int(code, 16)
        for i, ch in enumerate(chars):
            if ch == '�':
                continue
            if ch in cmap[f].values():
                sys.exit('osd_charmap.txt line %d: character %r given twice for font %02X' % (n, ch, f))
            if code + i in cmap[f] or 0xF0 <= code + i <= 0xFE:
                sys.exit('osd_charmap.txt line %d: code %02X given twice or a font code' % (n, code + i))
            cmap[f][code + i] = ch
    return cmap


SPECIAL = {'"': '\\"', '\\': '\\\\', '{': '\\{', '}': '\\}'}


def decode_text(body, cmap):
    """Text bytes (without the length byte) -> the source form. The text starts in font 0xF0."""
    out = []
    font = 0xF0
    for b in body:
        if 0xF0 <= b <= 0xFE:
            font = b
            out.append('{%02X}' % b)
            continue
        ch = cmap[font].get(b)
        if ch is None or ch < ' ':
            out.append('{%02X}' % b)
        else:
            out.append(SPECIAL.get(ch, ch))
    return '"' + ''.join(out) + '"'


# ---------------------------------------------------------------------------------------------------------
# Fonts area

def font_tables(names):
    """Per font code: (glyph table address, width table address), from the data names."""
    by_name = {v: k for k, v in names.items()}
    fonts = {}
    for f in FONT_CODES:
        fonts[f] = (by_name['font_glyph_columns_%02x' % f], by_name['font_glyph_widths_%02x' % f])
    return fonts


def glyph_block_records(fw, names):
    """The records in the start values that describe the glyph blocks and the two lookup blocks."""
    recs = []
    for ram, name in sorted(names.items()):
        if name.startswith('font_glyph_block_'):
            off = ram - START_VALUES_RAM + START_VALUES_FLASH
            count, kind, _, dest, data = struct.unpack('>HBBII', fw[off:off + 12])
            recs.append(dict(name=name, ram=ram, flash=off, count=count, kind=kind, dest=dest, data=data,
                             packed=True))
        elif name in ('osd_layer0_lookup_block', 'osd_layer1_lookup_block'):
            off = ram - START_VALUES_RAM + START_VALUES_FLASH
            count, dest, data = struct.unpack('>HHI', fw[off:off + 8])
            recs.append(dict(name=name, ram=ram, flash=off, count=count, kind=None, dest=dest, data=data,
                             packed=False))
    # Records 4, 7, 10..15 have no data name of their own: they lie between the named ones, 12 bytes apart.
    have = {r['ram'] for r in recs}
    first = min(r['ram'] for r in recs if r['packed'])
    for i in range(21):
        ram = first + 12 * i
        if ram not in have:
            off = ram - START_VALUES_RAM + START_VALUES_FLASH
            count, kind, _, dest, data = struct.unpack('>HBBII', fw[off:off + 12])
            recs.append(dict(name='font_glyph_block_%d' % i, ram=ram, flash=off, count=count, kind=kind,
                             dest=dest, data=data, packed=True))
    return sorted(recs, key=lambda r: r['data'])


def rle_decode(b):
    out = bytearray()
    runs = []                 # decoded position at which each stored run ends
    i = 0
    while i < len(b):
        v = b[i]
        if v in (0, 0xFF):
            n = b[i + 1] or 256
            out += bytes([v]) * n
            runs.append(len(out))
            i += 2
        else:
            out.append(v)
            i += 1
    return bytes(out), runs


def rle_encode(d, cuts=(), joins=()):
    """Runs of 0x00 or 0xFF become (value, count). A run stops after 255 bytes, at every multiple of 108
    (one cell picture) unless that position is in joins, and at every position in cuts."""
    cuts, joins = set(cuts), set(joins)
    out = bytearray()
    i = 0
    while i < len(d):
        v = d[i]
        if v in (0, 0xFF):
            j = i + 1
            while (j < len(d) and d[j] == v and j - i < 255 and j not in cuts
                   and (j % CELL or j in joins)):
                j += 1
            out += bytes([v, j - i])
            i = j
        else:
            out.append(v)
            i += 1
    return bytes(out)


def packing_hints(d, packed):
    """The cuts and joins that make rle_encode give exactly the stored bytes."""
    _, stored = rle_decode(packed)
    stored = set(stored)
    default = set(rle_decode(rle_encode(d))[1])
    cuts, joins = [], []
    for it in range(64):
        e = rle_encode(d, cuts, joins)
        if e == packed:
            return cuts, joins
        mine = set(rle_decode(e)[1])
        extra = sorted(mine - stored)       # runs I end that the stored data does not end
        missing = sorted(stored - mine)     # runs the stored data ends that I do not
        if missing and (not extra or missing[0] < extra[0]):
            cuts.append(missing[0])
        elif extra:
            joins.append(extra[0])
        else:
            break
    raise SystemExit('cannot reproduce the packing of a glyph block')


def picture_rows(bits, width):
    return ''.join('#' if bits >> (width - 1 - i) & 1 else '.' for i in range(width))


def gen_fonts(fw, names, cmap, out, log):
    fonts = font_tables(names)
    recs = glyph_block_records(fw, names)
    starts = sorted([a for p in fonts.values() for a in p] + [r['data'] for r in recs] + [cpu(TEXT_LO)])
    covered = []
    os.makedirs(out + '/fonts', exist_ok=True)
    total = 0
    for f in FONT_CODES:
        gaddr, waddr = fonts[f]
        gend = min(s for s in starts if s > gaddr)
        wend = min(s for s in starts if s > waddr)
        nglyph = (gend - gaddr) // (ROWS * 4)
        wb = fw[waddr + WINDOW:wend + WINDOW]
        nwidth = len(wb.rstrip(b'\0'))
        nwidth = max(nwidth, nglyph)
        covered += [(gaddr, gaddr + nglyph * ROWS * 4), (waddr, waddr + nwidth)]
        glyphs = []
        maxcol = 0
        for ch in range(nglyph):
            rows = [word(fw, gaddr + WINDOW + (ch * ROWS + r) * 4) for r in range(ROWS)]
            for v in rows:
                if v:
                    maxcol = max(maxcol, 32 - ((v & -v).bit_length() - 1))
            glyphs.append(rows)
        for code, c in cmap[f].items():
            if code >= nglyph:
                raise SystemExit('osd_charmap.txt: font %02X has no character %02X' % (f, code))
            if c == ' ' and any(glyphs[code]):
                raise SystemExit('osd_charmap.txt: font %02X character %02X is not blank' % (f, code))
        cols = max(maxcol, max(wb[:nwidth]))
        cols = min(32, cols)
        total += nglyph
        lines = []
        lines.append('# Menu font 0x%02X: %d characters of %d rows. Written by tools/osd_gen.py; see docs/OSD-TEXT.md.' % (f, nglyph, ROWS))
        lines.append('# Glyph table %s at 0x%06X (flash 0x%06X), width table %s at 0x%06X (flash 0x%06X).'
                     % (names[gaddr], gaddr, gaddr + WINDOW, names[waddr], waddr, waddr + WINDOW))
        lines.append('# Both addresses are written in the program code, so both tables keep their place: the number')
        lines.append('# of characters cannot grow. Each picture row is one 32-bit word of the glyph table; the first')
        lines.append('# column is bit 31. Columns not shown are 0.')
        lines.append('font %02X' % f)
        lines.append('glyphs 0x%06X' % gaddr)
        lines.append('widths 0x%06X' % waddr)
        lines.append('rows %d' % ROWS)
        lines.append('columns %d' % cols)
        lines.append('')
        for ch, rows in enumerate(glyphs):
            c = cmap[f].get(ch)
            head = 'char %02X width %d' % (ch, wb[ch])
            if c is not None:
                head += ' is "%s"' % SPECIAL.get(c, c) if c >= ' ' else ''
                if c == ' ':
                    head = 'char %02X width %d is " "' % (ch, wb[ch])
            lines.append(head)
            for v in rows:
                if v & ((1 << (32 - cols)) - 1):
                    raise SystemExit('font %02X char %02X: ink beyond column %d' % (f, ch, cols))
                lines.append(picture_rows(v >> (32 - cols), cols))
            lines.append('')
        for ch in range(nglyph, nwidth):
            lines.append('width %02X %d   # an entry of the width table without a picture' % (ch, wb[ch]))
        if nwidth > nglyph:
            lines.append('')
        open(out + '/fonts/font_%02x.txt' % f, 'w', encoding='utf-8').write('\n'.join(lines).rstrip('\n') + '\n')

    # Glyph blocks
    os.makedirs(out + '/fonts/blocks', exist_ok=True)
    order = []
    for r in recs:
        data = fw[r['data'] + WINDOW:r['data'] + WINDOW + r['count']]
        covered.append((r['data'], r['data'] + r['count']))
        lines = []
        if r['packed']:
            d, _ = rle_decode(data)
            cuts, joins = packing_hints(d, data)
            command = {0: 0xA0, 1: 0xB0, 2: 0xC0, 3: 0xC1}[r['kind']]
            lines.append('# Glyph block %s, written by tools/osd_gen.py; see docs/OSD-TEXT.md.' % r['name'])
            lines.append('# Its record (%s, RAM 0x%08X, flash 0x%05X in the start values) holds the packed size, the'
                         % (r['name'], r['ram'], r['flash']))
            lines.append('# kind, the destination address in the menu layer memory and the address of the data. The record')
            lines.append('# lies outside the menu area, so the data keeps its address and its packed size (%d bytes).' % r['count'])
            lines.append('# The data is sent run-length packed (osd_ram_write_packed_block): a 0x00 or 0xFF byte is')
            lines.append('# followed by a repeat count. The build packs the bytes below again.')
            lines.append('block %s' % r['name'])
            lines.append('data 0x%06X' % r['data'])
            lines.append('record 0x%08X' % r['ram'])
            lines.append('packed %d' % r['count'])
            lines.append('kind %d   # command 0x%02X, destination 0x%X' % (r['kind'], command, r['dest']))
            if cuts:
                lines.append('cuts ' + ' '.join('%d' % c for c in cuts) + '   # runs that also end here')
            if joins:
                lines.append('joins ' + ' '.join('%d' % c for c in joins) + '   # runs that go on past this cell boundary')
            lines.append('')
            if r['kind'] == 0 and len(d) % CELL == 0:
                lines.append('# %d cell pictures of 24 x %d pixels. A row is 3 bytes in the order they are sent: pixels' % (len(d) // CELL, ROWS))
                lines.append('# 16-23, 8-15, 0-7 (the same order osd_ram_write_words24 sends the cells of a text).')
                lines.append('format cells')
                lines.append('')
                for c in range(len(d) // CELL):
                    lines.append('cell %d' % c)
                    for row in range(ROWS):
                        b = d[c * CELL + row * 3:c * CELL + row * 3 + 3]
                        lines.append(picture_rows(b[2] << 16 | b[1] << 8 | b[0], 24))
                    lines.append('')
            else:
                lines.append('# %d bytes after unpacking, %d per line. The layout of this kind of block in the layer memory is'
                             % (len(d), 27))
                lines.append('# not shown by the code, so the bytes are given as they are sent.')
                lines.append('format bytes')
                for i in range(0, len(d), 27):
                    lines.append(d[i:i + 27].hex(' '))
                lines.append('')
        else:
            lines.append('# Lookup block %s, written by tools/osd_gen.py; see docs/OSD-TEXT.md.' % r['name'])
            lines.append('# Its record (RAM 0x%08X, flash 0x%05X in the start values) holds the size, the destination address'
                         % (r['ram'], r['flash']))
            lines.append('# 0x%X and the data address; osd_load_layer_lookup_tables sends the bytes unpacked with command 0xD0.'
                         % r['dest'])
            lines.append('# The record lies outside the menu area: the data keeps its address and its size.')
            lines.append('block %s' % r['name'])
            lines.append('data 0x%06X' % r['data'])
            lines.append('record 0x%08X' % r['ram'])
            lines.append('size %d' % r['count'])
            lines.append('format bytes')
            for i in range(0, len(data), 27):
                lines.append(data[i:i + 27].hex(' '))
            lines.append('')
        order.append(r['name'])
        open(out + '/fonts/blocks/%s.txt' % r['name'], 'w', encoding='utf-8').write('\n'.join(lines).rstrip('\n') + '\n')

    # Anything else in the fonts area: zero fill or raw bytes.
    covered.sort()
    raws = []
    p = cpu(AREA_LO)
    for a, b in covered + [(cpu(TEXT_LO), cpu(TEXT_LO))]:
        if a < p:
            raise SystemExit('fonts area: overlap at 0x%06X' % a)
        g = fw[p + WINDOW:a + WINDOW]
        if any(g):
            raws.append((p, g))
        p = b
    lines = ['# Bytes of the fonts area (flash 0x2101F0-0x275DE7) that belong to no font and no block.',
             '# Written by tools/osd_gen.py. Everything else between the tables is zero fill.', '']
    for a, g in raws:
        lines.append('raw 0x%06X %s' % (a, g.hex(' ')))
    open(out + '/fonts/raw.txt', 'w').write('\n'.join(lines) + '\n')
    log('fonts: %d fonts, %d glyphs, %d glyph blocks and lookup blocks, %d raw runs (%d bytes)'
        % (len(FONT_CODES), total, len(recs), len(raws), sum(len(g) for _, g in raws)))


# ---------------------------------------------------------------------------------------------------------
# Text area

def gen_texts(fw, names, cmap, out, log):
    refs = stored_refs()
    lo, hi = cpu(TEXT_LO), cpu(AREA_HI)
    words = sorted(r['off'] - WINDOW for r in refs if TEXT_LO <= r['off'] < AREA_HI)
    outside = [r for r in refs if TEXT_LO <= r['target'] < AREA_HI and not TEXT_LO <= r['off'] < AREA_HI]
    if outside:
        raise SystemExit('stored addresses outside the text area point into it; not handled')
    code = {a: u for a, u in code_addresses().items() if lo <= a < hi}
    # Tables: runs of consecutive text-address words, split where the program code uses an address.
    tables = []
    for w in words:
        if tables and tables[-1][1] == w and w not in code:
            tables[-1][1] = w + 4
        else:
            tables.append([w, w + 4])
    table_at = {t[0]: t for t in tables}
    texts = {}
    refs_of = {}
    for t0, t1 in tables:
        for i, w in enumerate(range(t0, t1, 4)):
            a = word(fw, w + WINDOW)
            if not lo <= a < hi:
                raise SystemExit('table 0x%06X entry %d: 0x%06X is outside the text area' % (t0, i, a))
            texts.setdefault(a, None)
            refs_of.setdefault(a, []).append((t0, i))
    # Walk the area in address order. Items: ('table', addr) ('text', addr, length, tail) ('gap', n) ('raw', addr, bytes)
    known = sorted([(t[0], 'table') for t in tables] + [(a, 'text') for a in texts])
    items = []
    unref = []
    pos = lo
    k = 0

    def body_end(a):
        return a + 1 + fw[a + WINDOW]

    def scan_gap(p, limit, after_text):
        """Bytes between the end of an item and the next known item: hidden tail, unreferenced texts, zeros."""
        found = []
        tail = b''
        if after_text:
            q = p
            while q < limit and fw[q + WINDOW] != 0:
                q += 1
            tail = fw[p + WINDOW:q + WINDOW]
            p = q
        while True:
            q = p
            while q < limit and fw[q + WINDOW] == 0:
                q += 1
            if q >= limit:
                break
            if q % 8 == 0 and body_end(q) <= limit:
                e = body_end(q)
                t = e
                while t < limit and fw[t + WINDOW] != 0:
                    t += 1
                found.append((q, fw[q + WINDOW + 1:e + WINDOW], fw[e + WINDOW:t + WINDOW]))
                p = t
            else:
                found.append((q, None, None))
                break
        return tail, found

    seq = []          # (addr, kind, data...) in address order, with their original addresses
    for idx, (a, kind) in enumerate(known):
        nxt = known[idx + 1][0] if idx + 1 < len(known) else hi
        if kind == 'table':
            t0, t1 = table_at[a]
            seq.append(('table', a, (t1 - t0) // 4))
            end = t1
            tail, found = scan_gap(end, nxt, False)
        else:
            e = body_end(a)
            if e > nxt:
                raise SystemExit('text 0x%06X runs into the next item at 0x%06X' % (a, nxt))
            tail, found = scan_gap(e, nxt, True)
            seq.append(('text', a, fw[a + WINDOW + 1:e + WINDOW], tail))
            end = e + len(tail)
        for q, body, ttail in found:
            if body is None:
                seq.append(('raw', q, fw[q + WINDOW:nxt + WINDOW].rstrip(b'\0')))
                break
            seq.append(('text', q, body, ttail))
            unref.append(q)
    # Ids: a text is named after the first table entry that points at it; unreferenced texts are numbered.
    tid = {}
    for a, lst in sorted(refs_of.items()):
        t0, i = min(lst)
        tid[a] = '%06x.%d' % (t0, i)
    for n, a in enumerate(sorted(unref), 1):
        tid[a] = 'unref.%03d' % n
    fixed_text = {}
    for a in code:
        if a in table_at:
            continue
        hit = [s for s in seq if s[0] == 'text' and s[1] <= a < s[1] + 1 + len(s[2]) + len(s[3])]
        if hit:
            fixed_text[hit[0][1]] = a
        elif not any(s[0] == 'raw' and s[1] <= a < s[1] + len(s[2]) for s in seq):
            raise SystemExit('the code uses 0x%06X, which is no table, text or raw data' % a)

    # Layout: emulate the build's placement and add gaps where the original does not follow its rule.
    layout = []
    cursor = lo
    for s in seq:
        kind, a = s[0], s[1]
        if kind in ('table', 'raw') or (kind == 'text' and a in fixed_text):
            if a < cursor:
                raise SystemExit('overlap at 0x%06X' % a)
            cursor = a
        else:
            if align8(cursor) != a:
                if a < cursor:
                    raise SystemExit('text 0x%06X overlaps the item before it' % a)
                # zero bytes until the text, then the text without alignment
                layout.append('gap %d' % (a - cursor))
                cursor = a
                if a % 8:
                    raise SystemExit('text 0x%06X is not 8-aligned' % a)
            cursor = a
        if kind == 'table':
            layout.append('table %06x' % a)
            cursor = a + 4 * s[2]
        elif kind == 'raw':
            layout.append('raw %06x' % a)
            cursor = a + len(s[2])
        else:
            if a in fixed_text:
                layout.append('text %s fixed 0x%06X   # the code uses 0x%06X' % (tid[a], a, fixed_text[a]))
            else:
                layout.append('text %s' % tid[a])
            cursor = a + 1 + len(s[2]) + len(s[3])
    if cursor > hi:
        raise SystemExit('text area overflows')

    # Which file holds a text: the language of all its table entries when that is one language.
    def entry_note(t0, i):
        n = (table_at[t0][1] - t0) // 4
        nm = names.get(t0, 'table_%06x' % t0)
        if n % LANG_COUNT == 0:
            return '%s[%d] (item %d, %s)' % (nm, i, i // LANG_COUNT, LANGUAGES[i % LANG_COUNT][3:])
        return '%s[%d]' % (nm, i)

    files = {}
    for s in seq:
        if s[0] != 'text':
            continue
        a = s[1]
        lst = sorted(refs_of.get(a, []))
        langs = set()
        for t0, i in lst:
            n = (table_at[t0][1] - t0) // 4
            langs.add(i % LANG_COUNT if n % LANG_COUNT == 0 else None)
        if not lst:
            fname = 'unreferenced'
        elif len(langs) == 1 and None not in langs:
            fname = LANGUAGES[langs.pop()]
        else:
            fname = 'common'
        line = '%s %s' % (tid[a], decode_text(s[2], cmap))
        if s[3]:
            line += ' hidden %s' % s[3].hex(' ')
        notes = [entry_note(t0, i) for t0, i in lst]
        files.setdefault(fname, []).append((notes, line))
    os.makedirs(out + '/texts', exist_ok=True)
    heads = {
        'common': 'Texts used by tables that are not one text per language, or by more than one language.',
        'unreferenced': 'Texts that no table and no address in the program code points at: the menu does not draw them.',
    }
    for fname, entries in files.items():
        if fname in heads:
            head = heads[fname]
        else:
            i = int(fname[:2])
            a = word(fw, LANGUAGE_TABLE + 4 * i + WINDOW)
            name = decode_text(fw[a + WINDOW + 1:a + WINDOW + 1 + fw[a + WINDOW]], cmap)
            head = 'Texts of language %d, named %s in the language list, used by no other language.' % (i, name)
        lines = ['# ' + head, '# Written by tools/osd_gen.py; the format is described in docs/OSD-TEXT.md.', '']
        for notes, line in entries:
            for nt in notes[:6]:
                lines.append('# ' + nt)
            if len(notes) > 6:
                lines.append('# ... and %d more entries' % (len(notes) - 6))
            lines.append(line)
            lines.append('')
        open(out + '/texts/%s.txt' % fname, 'w', encoding='utf-8').write('\n'.join(lines).rstrip('\n') + '\n')
    for stale in os.listdir(out + '/texts'):
        if stale.endswith('.txt') and stale[:-4] not in files and stale[:-4] not in ('layout', 'tables', 'raw'):
            os.remove(out + '/texts/' + stale)

    # Tables
    lines = ['# The tables of text addresses, in address order. Written by tools/osd_gen.py; see docs/OSD-TEXT.md.',
             '# Every table keeps its address (the program code uses it). An entry names the text it points at.',
             '# In a table of 29 x n entries, entry item * 29 + language is the text of that item in that language.', '']
    for t0, t1 in tables:
        n = (t1 - t0) // 4
        users = sorted(code.get(t0, []))
        nm = names.get(t0)
        head = 'table %06x %d' % (t0, n)
        if nm:
            head += ' %s' % nm
        lines.append(head)
        if users:
            fnames = json.load(open(REPO + '/symbols/leon2m.names.json'))
            lines.append('# used by ' + ', '.join('%s (%s)' % (fnames.get(u.rsplit('.', 1)[0], {}).get('name', '?'),
                                                              u.rsplit('.', 1)[0]) for u in users))
        else:
            lines.append('# no address written in the program code is the start of this table; it keeps its place all the same')
        for i, w in enumerate(range(t0, t1, 4)):
            lines.append('  %d %s' % (i, tid[word(fw, w + WINDOW)]))
        lines.append('')
    open(out + '/texts/tables.txt', 'w').write('\n'.join(lines).rstrip('\n') + '\n')

    # Raw data and layout
    lines = ['# Bytes of the text area that are neither table nor text. Written by tools/osd_gen.py.', '']
    for s in seq:
        if s[0] == 'raw':
            lines.append('raw %06x %s' % (s[1], s[2].hex(' ')))
    open(out + '/texts/raw.txt', 'w').write('\n'.join(lines).rstrip('\n') + '\n')
    lines = ['# The order of the text area, flash 0x275DE8-0x29FF4F (main-processor address 0x16DDE8-0x197F4F).',
             '# Written by tools/osd_gen.py; see docs/OSD-TEXT.md. A table or raw line keeps its address, a text',
             '# follows the item before it on the next multiple of 8 (zero fill), "gap n" puts n zero bytes first.',
             '# A text marked "fixed" keeps its address too: the program code uses an address inside it.',
             'start 0x%06X' % lo, ''] + layout + ['', 'end 0x%06X' % hi]
    open(out + '/texts/layout.txt', 'w').write('\n'.join(lines) + '\n')
    nfiles = len(files)
    log('texts: %d tables (%d entries), %d texts (%d unreferenced), %d with hidden bytes, %d raw runs, %d gaps, %d files'
        % (len(tables), len(words), sum(1 for s in seq if s[0] == 'text'), len(unref),
           sum(1 for s in seq if s[0] == 'text' and s[3]), sum(1 for s in seq if s[0] == 'raw'),
           sum(1 for x in layout if x.startswith('gap')), nfiles))


def main():
    args = sys.argv[1:]
    image = args[args.index('--image') + 1] if '--image' in args else None
    out = os.path.abspath(args[args.index('--out') + 1]) if '--out' in args else REPO + '/src/osd'
    quiet = '--quiet' in args
    log = (lambda s: None) if quiet else print
    fw = load_image(image)
    names = data_names()
    cmap = load_charmap()
    os.makedirs(out, exist_ok=True)
    gen_fonts(fw, names, cmap, out, log)
    gen_texts(fw, names, cmap, out, log)


if __name__ == '__main__':
    main()
