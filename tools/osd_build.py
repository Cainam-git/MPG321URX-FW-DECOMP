#!/usr/bin/env python3
"""Build the bytes of the on-screen menu's fonts and texts from their source (src/osd/).

Usage: python3 tools/osd_build.py [--src DIR] [--out FILE] [--map FILE]

  --src DIR    source tree (default src/osd)
  --out FILE   write the built menu area to FILE (default work/osd/osd_area.bin): the bytes of flash
               0x2101F0-0x29FF4F (0x8FD60 bytes), the fonts area followed by the text area
  --map FILE   also write the address of every text, table, font table and block to FILE

The build reads nothing but the source tree: not the firmware. The format of the source files and the
rules below are described in docs/OSD-TEXT.md.

  - Fonts area (flash 0x2101F0-0x275DE7): every glyph table, width table, glyph block and raw run is put at
    the address written in its file. Those addresses are used by the program code or by records outside the
    menu area, so they cannot move. The space between them is zero fill. A font with more characters than
    fit before the next table, or a glyph block whose packed size is not the size in its record, stops the
    build with a message.
  - Text area (flash 0x275DE8-0x29FF4F): the items of texts/layout.txt are placed in that order. A table or
    raw run keeps its address, and so does a text marked "fixed". Every other text follows the item before
    it on the next multiple of 8, with zero fill. The tables are filled in with the new addresses of their
    texts. A text that no longer fits before the next fixed item stops the build with a message.

Exit status 0 when the build succeeds, 2 when the source has an error.
"""
import os, re, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WINDOW = 0x108000
AREA_LO, TEXT_LO, AREA_HI = 0x2101F0, 0x275DE8, 0x29FF50
ROWS = 36
CELL = ROWS * 3
FONT_CODES = list(range(0xF0, 0xFF))


class SourceError(Exception):
    pass


def cpu(flash):
    return flash - WINDOW


def align8(x):
    return (x + 7) & ~7


def shown(path):
    """A path as messages show it: relative to the repository when it lies inside it."""
    path = os.path.abspath(path)
    return os.path.relpath(path, REPO) if path.startswith(REPO + os.sep) else path


def lines_of(path):
    """(line number, text) of every line that is not empty and not a comment. A comment line starts with "# "
    (a picture row has no space, so it can start with "#"); strip_comment drops a comment at the end of a
    header line."""
    out = []
    for n, line in enumerate(open(path, encoding='utf-8'), 1):
        line = line.rstrip('\n')
        stripped = line.strip()
        if not stripped or stripped == '#' or stripped.startswith('# '):
            continue
        out.append((n, line))
    return out


def strip_comment(line):
    i = line.find('   #')
    return line[:i].rstrip() if i >= 0 else line.rstrip()


def unquote(s, where):
    """The inside of a quoted text: returns a list of items, each a character (str) or a code (int)."""
    out = []
    i = 0
    while i < len(s):
        c = s[i]
        if c == '\\':
            if i + 1 >= len(s):
                raise SourceError('%s: a backslash at the end of the text' % where)
            out.append(s[i + 1])
            i += 2
        elif c == '{':
            j = s.find('}', i)
            if j < 0 or not re.fullmatch(r'[0-9A-Fa-f]{2}', s[i + 1:j]):
                raise SourceError('%s: "{" must be followed by two hexadecimal digits and "}"' % where)
            out.append(int(s[i + 1:j], 16))
            i = j + 1
        elif c == '"':
            raise SourceError('%s: a quote inside the text must be written \\"' % where)
        else:
            out.append(c)
            i += 1
    return out


def split_quoted(rest, where):
    """'"text" more' -> ('text', 'more')."""
    rest = rest.lstrip()
    if not rest.startswith('"'):
        raise SourceError('%s: a quoted text is expected' % where)
    i = 1
    while i < len(rest):
        if rest[i] == '\\':
            i += 2
            continue
        if rest[i] == '"':
            return rest[1:i], rest[i + 1:].strip()
        i += 1
    raise SourceError('%s: the closing quote is missing' % where)


# ---------------------------------------------------------------------------------------------------------
# Fonts

def read_font(path):
    rel = shown(path)
    head = {}
    chars = []          # [code, width, char or None, [row strings]]
    extra = []          # [code, width]
    cur = None
    for n, line in lines_of(path):
        where = '%s line %d' % (rel, n)
        if cur is not None and len(cur[3]) < ROWS and re.fullmatch(r'[#.]+', line):
            cur[3].append(line)
            continue
        if cur is not None and len(cur[3]) < ROWS:
            raise SourceError('%s: character %02X has %d picture rows, %d expected' % (where, cur[0], len(cur[3]), ROWS))
        m = re.match(r'char ([0-9A-Fa-f]{2}) width (\d+)(?: is (.*))?$', line)
        if m:
            ch = None
            if m.group(3) is not None:
                inner, more = split_quoted(m.group(3), where)
                items = unquote(inner, where)
                if more or len(items) != 1 or not isinstance(items[0], str):
                    raise SourceError('%s: "is" must be followed by one quoted character' % where)
                ch = items[0]
            cur = [int(m.group(1), 16), int(m.group(2)), ch, []]
            chars.append(cur)
            continue
        m = re.match(r'width ([0-9A-Fa-f]{2}) (\d+)$', strip_comment(line))
        if m:
            extra.append([int(m.group(1), 16), int(m.group(2))])
            cur = None
            continue
        m = re.match(r'(font|glyphs|widths|rows|columns) (\S+)$', strip_comment(line))
        if m and cur is None:
            head[m.group(1)] = int(m.group(2), 16 if m.group(1) == 'font' else 0)
            continue
        raise SourceError('%s: not understood: %s' % (where, line[:60]))
    if cur is not None and len(cur[3]) < ROWS:
        raise SourceError('%s: character %02X has %d picture rows, %d expected' % (rel, cur[0], len(cur[3]), ROWS))
    for k in ('font', 'glyphs', 'widths', 'rows', 'columns'):
        if k not in head:
            raise SourceError('%s: the header line "%s" is missing' % (rel, k))
    if head['rows'] != ROWS:
        raise SourceError('%s: rows must be %d' % (rel, ROWS))
    cols = head['columns']
    for i, c in enumerate(chars):
        if c[0] != i:
            raise SourceError('%s: character %02X out of order (expected %02X); codes run from 00 without gaps'
                              % (rel, c[0], i))
        if not 0 < c[1] < 256:
            raise SourceError('%s: character %02X: width %d outside 1..255' % (rel, c[0], c[1]))
        for r in c[3]:
            if len(r) != cols:
                raise SourceError('%s: character %02X: a picture row of %d columns, %d expected' % (rel, c[0], len(r), cols))
    for i, e in enumerate(extra):
        if e[0] != len(chars) + i:
            raise SourceError('%s: width entry %02X out of order' % (rel, e[0]))
    head['chars'] = chars
    head['extra'] = extra
    head['path'] = rel
    return head


def font_bytes(font):
    cols = font['columns']
    g = bytearray()
    for code, width, ch, rows in font['chars']:
        for r in rows:
            v = int(r.replace('#', '1').replace('.', '0'), 2) << (32 - cols)
            g += v.to_bytes(4, 'big')
    w = bytes(c[1] for c in font['chars']) + bytes(e[1] for e in font['extra'])
    return bytes(g), w


def charmaps(fonts):
    """Per font code: character -> code, from the "is" of every character."""
    maps = {f: {} for f in FONT_CODES}
    for f, font in fonts.items():
        for code, width, ch, rows in font['chars']:
            if ch is None:
                continue
            if ch in maps[f]:
                raise SourceError('%s: character %r is given to %02X and %02X' % (font['path'], ch, maps[f][ch], code))
            if 0xF0 <= code <= 0xFE:
                raise SourceError('%s: code %02X switches the font and cannot be a character' % (font['path'], code))
            maps[f][ch] = code
    return maps


# ---------------------------------------------------------------------------------------------------------
# Glyph blocks

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


def read_block(path):
    rel = shown(path)
    head = {'cuts': [], 'joins': []}
    data = bytearray()
    fmt = None
    cell = None
    for n, line in lines_of(path):
        where = '%s line %d' % (rel, n)
        s = strip_comment(line)
        if fmt == 'cells' and re.fullmatch(r'[#.]{24}', s):
            if cell is None or cell >= ROWS:
                raise SourceError('%s: picture row outside a cell' % where)
            v = int(s.replace('#', '1').replace('.', '0'), 2)
            data += bytes([v & 0xFF, v >> 8 & 0xFF, v >> 16])
            cell += 1
            continue
        if fmt == 'bytes' and re.fullmatch(r'[0-9a-f]{2}( [0-9a-f]{2})*', s):
            data += bytes.fromhex(s)
            continue
        m = re.match(r'cell (\d+)$', s)
        if m and fmt == 'cells':
            if cell is not None and cell != ROWS:
                raise SourceError('%s: the cell before has %d rows, %d expected' % (where, cell, ROWS))
            if int(m.group(1)) * CELL != len(data):
                raise SourceError('%s: cell %s out of order' % (where, m.group(1)))
            cell = 0
            continue
        m = re.match(r'(block|data|record|packed|kind|size|format|cuts|joins) ?(.*)$', s)
        if m:
            k, v = m.group(1), m.group(2)
            if k in ('cuts', 'joins'):
                head[k] = [int(x) for x in v.split()]
            elif k in ('block', 'format'):
                head[k] = v
                if k == 'format':
                    fmt = v
            else:
                head[k] = int(v, 0)
            continue
        raise SourceError('%s: not understood: %s' % (where, line[:60]))
    if fmt == 'cells' and cell is not None and cell != ROWS:
        raise SourceError('%s: the last cell has %d rows, %d expected' % (rel, cell, ROWS))
    if 'packed' in head:
        b = rle_encode(bytes(data), head['cuts'], head['joins'])
        if len(b) != head['packed']:
            raise SourceError('%s: packs to %d bytes, but its record (RAM 0x%08X, outside the menu area) gives %d; '
                              'the packed size cannot change' % (rel, len(b), head['record'], head['packed']))
    else:
        b = bytes(data)
        if len(b) != head['size']:
            raise SourceError('%s: %d bytes, but its record (RAM 0x%08X, outside the menu area) gives %d'
                              % (rel, len(b), head['record'], head['size']))
    return head['data'], b, rel


def read_raw(path):
    out = []
    rel = shown(path)
    for n, line in lines_of(path):
        m = re.match(r'raw (?:0x)?([0-9A-Fa-f]+) ((?:[0-9a-f]{2} ?)+)$', line.strip())
        if not m:
            raise SourceError('%s line %d: not understood' % (rel, n))
        out.append((int(m.group(1), 16), bytes.fromhex(m.group(2)), '%s line %d' % (rel, n)))
    return out


def build_fonts(src, area, amap):
    fonts = {}
    for f in FONT_CODES:
        fonts[f] = read_font('%s/fonts/font_%02x.txt' % (src, f))
        if fonts[f]['font'] != f:
            raise SourceError('%s: font %02X expected' % (fonts[f]['path'], f))
    pieces = []
    for f, font in fonts.items():
        g, w = font_bytes(font)
        pieces.append((font['glyphs'], g, '%s (glyph table)' % font['path']))
        pieces.append((font['widths'], w, '%s (width table)' % font['path']))
    bdir = src + '/fonts/blocks'
    for name in sorted(os.listdir(bdir)):
        if name.endswith('.txt'):
            a, b, rel = read_block(bdir + '/' + name)
            pieces.append((a, b, rel))
    for a, b, where in read_raw(src + '/fonts/raw.txt'):
        pieces.append((a, b, where))
    place(pieces, cpu(AREA_LO), cpu(TEXT_LO), area, amap)
    return fonts


def place(pieces, lo, hi, area, amap):
    pieces.sort(key=lambda p: p[0])
    end, last = lo, None
    for a, b, what in pieces:
        if a < end:
            raise SourceError('%s at 0x%06X overlaps %s, which ends at 0x%06X (%d bytes too many)'
                              % (what, a, last, end, end - a))
        if a + len(b) > hi:
            raise SourceError('%s runs past the end of its area (0x%06X)' % (what, hi))
        area[a - cpu(AREA_LO):a - cpu(AREA_LO) + len(b)] = b
        amap.append((a, len(b), what))
        end, last = a + len(b), what


# ---------------------------------------------------------------------------------------------------------
# Texts

def encode_text(items, maps, where):
    out = bytearray()
    font = 0xF0
    for it in items:
        if isinstance(it, int):
            out.append(it)
            if 0xF0 <= it <= 0xFE:
                font = it
            continue
        code = maps[font].get(it)
        if code is None:
            has = ['%02X' % f for f in FONT_CODES if it in maps[f]]
            raise SourceError('%s: character %r is not in font %02X%s' % (
                where, it, font, (' (it is in font %s; switch with {%s})' % (', '.join(has), has[0])) if has else ''))
        out.append(code)
    if len(out) > 255:
        raise SourceError('%s: %d bytes; a text holds at most 255 (one length byte)' % (where, len(out)))
    return bytes(out)


def read_texts(src, maps):
    texts = {}
    tdir = src + '/texts'
    for name in sorted(os.listdir(tdir)):
        if not name.endswith('.txt') or name in ('layout.txt', 'tables.txt', 'raw.txt'):
            continue
        rel = shown(tdir + '/' + name)
        for n, line in lines_of(tdir + '/' + name):
            where = '%s line %d' % (rel, n)
            m = re.match(r'(\S+) (.*)$', line)
            if not m:
                raise SourceError('%s: not understood' % where)
            tid = m.group(1)
            inner, more = split_quoted(m.group(2), where)
            hidden = b''
            if more:
                h = re.fullmatch(r'hidden ((?:[0-9a-f]{2} ?)+)', more)
                if not h:
                    raise SourceError('%s: after the text only "hidden <bytes>" may follow' % where)
                hidden = bytes.fromhex(h.group(1))
                if 0 in hidden:
                    raise SourceError('%s: hidden bytes cannot be 00' % where)
            body = encode_text(unquote(inner, where), maps, where)
            if tid in texts:
                raise SourceError('%s: text %s is defined twice (also %s)' % (where, tid, texts[tid][2]))
            texts[tid] = (bytes([len(body)]) + body + hidden, len(body), where)
    return texts


def read_tables(src):
    tables = []
    path = src + '/texts/tables.txt'
    rel = shown(path)
    for n, line in lines_of(path):
        where = '%s line %d' % (rel, n)
        m = re.match(r'table ([0-9a-f]{6}) (\d+)', line)
        if m:
            tables.append([int(m.group(1), 16), int(m.group(2)), [], where])
            continue
        m = re.match(r'\s+(\d+) (\S+)$', line)
        if m and tables:
            if int(m.group(1)) != len(tables[-1][2]):
                raise SourceError('%s: entry %s out of order' % (where, m.group(1)))
            tables[-1][2].append(m.group(2))
            continue
        raise SourceError('%s: not understood' % where)
    for t in tables:
        if len(t[2]) != t[1]:
            raise SourceError('%s: %d entries listed, %d given in the header (a table cannot change size: the '
                              'program reads it by fixed offsets)' % (t[3], len(t[2]), t[1]))
    return {t[0]: t for t in tables}


def build_texts(src, maps, area, amap, textmap):
    texts = read_texts(src, maps)
    tables = read_tables(src)
    raws = {a: (b, w) for a, b, w in read_raw(src + '/texts/raw.txt')}
    path = src + '/texts/layout.txt'
    rel = shown(path)
    lo = hi = None
    seq = []
    for n, line in lines_of(path):
        where = '%s line %d' % (rel, n)
        s = strip_comment(line).split()
        if s[0] == 'start':
            lo = int(s[1], 0)
        elif s[0] == 'end':
            hi = int(s[1], 0)
        elif s[0] == 'table' and len(s) == 2:
            seq.append(('table', int(s[1], 16), where))
        elif s[0] == 'raw' and len(s) == 2:
            seq.append(('raw', int(s[1], 16), where))
        elif s[0] == 'gap' and len(s) == 2:
            seq.append(('gap', int(s[1]), where))
        elif s[0] == 'text' and len(s) == 2:
            seq.append(('text', s[1], where, None))
        elif s[0] == 'text' and len(s) == 4 and s[2] == 'fixed':
            seq.append(('text', s[1], where, int(s[3], 0)))
        else:
            raise SourceError('%s: not understood' % where)
    if lo != cpu(TEXT_LO) or hi != cpu(AREA_HI):
        raise SourceError('%s: start and end must be 0x%06X and 0x%06X' % (rel, cpu(TEXT_LO), cpu(AREA_HI)))
    used = set()
    addr = {}
    cursor = lo
    last = 'the start of the text area'
    out = []            # (address, bytes, what)

    def fixed_at(a, what, where):
        nonlocal cursor
        if cursor > a:
            raise SourceError('%s: %s must stay at 0x%06X, but the texts before it end at 0x%06X: %s and the texts '
                              'before it need %d bytes less (or move a text behind a later fixed item)'
                              % (where, what, a, cursor, last, cursor - a))
        cursor = a

    for item in seq:
        kind, where = item[0], item[2]
        if kind == 'table':
            a = item[1]
            if a not in tables:
                raise SourceError('%s: table %06x is not in tables.txt' % (where, a))
            fixed_at(a, 'table %06x' % a, where)
            out.append((a, None, 'table %06x' % a))
            cursor = a + 4 * tables[a][1]
            last = 'table %06x' % a
        elif kind == 'raw':
            a = item[1]
            if a not in raws:
                raise SourceError('%s: raw %06x is not in texts/raw.txt' % (where, a))
            fixed_at(a, 'raw data %06x' % a, where)
            out.append((a, raws[a][0], 'raw %06x' % a))
            cursor = a + len(raws[a][0])
            last = 'raw %06x' % a
        elif kind == 'gap':
            cursor += item[1]
        else:
            tid = item[1]
            if tid not in texts:
                raise SourceError('%s: text %s is not defined in any text file' % (where, tid))
            if tid in used:
                raise SourceError('%s: text %s is placed twice' % (where, tid))
            used.add(tid)
            b, length, defined = texts[tid]
            if item[3] is not None:
                fixed_at(item[3], 'text %s (marked fixed)' % tid, where)
            else:
                cursor = align8(cursor)
            addr[tid] = cursor
            out.append((cursor, b, 'text %s' % tid))
            textmap.append((cursor, tid, defined))
            cursor += len(b)
            last = 'text %s (%s)' % (tid, defined)
    if cursor > hi:
        raise SourceError('the text area ends at 0x%06X, but its items need up to 0x%06X: %s and the texts before '
                          'it need %d bytes less' % (hi, cursor, last, cursor - hi))
    missing = sorted(set(texts) - used)
    if missing:
        raise SourceError('text %s (%s) is not placed in texts/layout.txt' % (missing[0], texts[missing[0]][2]))
    placed_tables = {a for a, b, w in out if b is None}
    for a, t in tables.items():
        if a not in placed_tables:
            raise SourceError('%s: table %06x is not placed in texts/layout.txt' % (t[3], a))
    for a, b, what in out:
        if b is None:
            t = tables[a]
            words = bytearray()
            for i, tid in enumerate(t[2]):
                if tid not in addr:
                    raise SourceError('%s: entry %d names text %s, which does not exist' % (t[3], i, tid))
                words += addr[tid].to_bytes(4, 'big')
            b = bytes(words)
        area[a - cpu(AREA_LO):a - cpu(AREA_LO) + len(b)] = b
        amap.append((a, len(b), what))


def build(src):
    """Returns (menu area bytes, address map, text map). Raises SourceError."""
    area = bytearray(AREA_HI - AREA_LO)
    amap, textmap = [], []
    fonts = build_fonts(src, area, amap)
    maps = charmaps(fonts)
    build_texts(src, maps, area, amap, textmap)
    return bytes(area), amap, textmap


def main():
    args = sys.argv[1:]
    src = os.path.abspath(args[args.index('--src') + 1]) if '--src' in args else REPO + '/src/osd'
    out = args[args.index('--out') + 1] if '--out' in args else REPO + '/work/osd/osd_area.bin'
    mapf = args[args.index('--map') + 1] if '--map' in args else None
    try:
        area, amap, textmap = build(src)
    except SourceError as e:
        print('error: %s' % e)
        sys.exit(2)
    os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
    open(out, 'wb').write(area)
    if mapf:
        with open(mapf, 'w') as f:
            for a, n, what in sorted(amap):
                f.write('0x%06X flash 0x%06X %6d  %s\n' % (a, a + WINDOW, n, what))
    print('built %d bytes (flash 0x%06X-0x%06X) into %s' % (len(area), AREA_LO, AREA_HI - 1, out))


if __name__ == '__main__':
    main()
