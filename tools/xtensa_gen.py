#!/usr/bin/env python3
"""Generate the assembly source tree of the Tensilica program (flash bank 3) from the firmware.

Usage: python3 tools/xtensa_gen.py [--out DIR] [--ranges FILE.json] [--tmp DIR]

The files in src/tensilica/ are the master copy. This script only exists to regenerate them from
firmware/MSI_MPG321URX_V021_7F69.bin (for example after a change to the layout rules below); running it
overwrites every generated file in the output directory (default src/tensilica). Check the result with
tools/xtensa_check.py.

How the program is decoded (Espressif xtensa-esp32-elf binutils, see docs/TOOLCHAINS.md):
  1. Recursive descent from the reset code (0x400), the vector slots, the two handler addresses that the
     reset code writes to EXCSAVE3 and EXCSAVE5, every call target and branch target, and every word in
     the data part whose value is an address in the code part.
  2. Every 4-byte aligned `entry` instruction that is still not reached starts a further function.
  3. The remaining non-zero bytes in the code part are decoded linearly (instructions after an
     unconditional jump or return); they must end exactly at the next decoded instruction.
Every byte of the code part is then an instruction, a literal word read by l32r, or zero fill.
"""
import json, os, re, struct, subprocess, sys, tempfile, textwrap
from collections import defaultdict

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TC = REPO + '/toolchains/xtensa-esp32-elf/bin/xtensa-esp32-elf-'
FW = REPO + '/firmware/MSI_MPG321URX_V021_7F69.bin'
FW_REL = 'firmware/MSI_MPG321URX_V021_7F69.bin'
OFF, SIZE, BASE = 0x30000, 0xD8DC, 0x40000000
CODE_START, CODE_END = 0x800, 0xAC38          # program code (image offsets)
SECTAB = 0xAC38                                # section table, 16 records of 12 bytes
LINE = re.compile(r'^\s*([0-9a-f]+):\t([0-9a-f ]+?)\s*\t(\S+)\s*(.*)$')
PCREL = {'j', 'call0', 'call4', 'call8', 'call12', 'l32r', 'loop', 'loopnez', 'loopgtz'}
ENDS = {'j', 'jx', 'ret', 'ret.n', 'retw', 'retw.n', 'rfe', 'rfi', 'rfwo', 'rfwu', 'rfde', 'rfue',
        'rfdo', 'rfdd', 'rfme', 'ill', 'ill.n'}

# Vector slots (offsets from VECBASE; the reset code writes 0x40000000 to VECBASE). The window vectors
# are at fixed offsets in the Xtensa ISA; the other slots follow the usual Xtensa LX layout, which is a
# core configuration choice. The note says what the instructions in the slot use.
VECTORS = [
    (0x000, 'window overflow 4', 's32e/rfwo'),
    (0x040, 'window underflow 4', 'l32e/rfwu'),
    (0x080, 'window overflow 8', 's32e/rfwo'),
    (0x0C0, 'window underflow 8', 'l32e/rfwu'),
    (0x100, 'window overflow 12', 's32e/rfwo'),
    (0x140, 'window underflow 12', 'l32e/rfwu'),
    (0x180, 'level-2 interrupt', 'break 1, 2, then a jump to itself'),
    (0x1C0, 'level-3 interrupt', 'jumps to the address in EXCSAVE3'),
    (0x200, 'level-4 interrupt', 'break 1, 2, then a jump to itself'),
    (0x240, 'level-5 interrupt', 'jumps to the address in EXCSAVE5'),
    (0x280, 'debug exception', 'a jump to itself'),
    (0x2C0, 'NMI (level 7)', 'rfi 7'),
    (0x300, 'kernel exception', 'break 1, 0, then a jump to itself'),
    (0x340, 'user exception', 'jumps through a table indexed by EXCCAUSE'),
    (0x380, 'offset 0x380', 'zero bytes only'),
    (0x3C0, 'double exception', 'break 1, 4, then a jump to itself'),
]
# code addresses that are entered without a call: (offset, how it is entered)
EXTRA_ENTRIES = {
    0xA680: 'entered from the level-3 vector (0x400001c0) by jx through EXCSAVE3, which the reset code '
            'sets from lit_40000424',
    0xA74C: 'entered from the level-5 vector (0x40000240) by jx through EXCSAVE5, which the reset code '
            'sets from lit_40000430',
}

EXC_ENTRIES = 6
out_dir = REPO + '/src/tensilica'


def run(cmd):
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit('failed: ' + ' '.join(cmd))
    return r.stdout


def is_pcrel(m):
    return m in PCREL or (m.startswith('b') and m not in ('break', 'break.n'))


def A(off):
    return BASE + off


# ---------------------------------------------------------------- decoding

def decode(d, img, points):
    """objdump the code part, restarting the decode at every offset in points."""
    open(d + '/img.bin', 'wb').write(img)
    pts = sorted(p for p in set(points) | {0} if p < CODE_END) + [CODE_END]
    w = ['.section .text']
    for a, b in zip(pts, pts[1:]):
        w.append('S_%05x:' % a)
        w.append('.incbin "%s/img.bin", %d, %d' % (d, a, b - a))
    open(d + '/wrap.s', 'w').write('\n'.join(w) + '\n')
    run([TC + 'as', '-o', d + '/wrap.o', d + '/wrap.s'])
    out = run([TC + 'objdump', '-d', '-z', d + '/wrap.o'])
    dec = {}
    for ln in out.splitlines():
        m = LINE.match(ln)
        if not m:
            continue
        a = int(m.group(1), 16)
        n = len(m.group(2).replace(' ', '')) // 2
        mn = m.group(3)
        ops = re.sub(r'\s*<[^>]*>$', '', m.group(4).strip())
        tgt = None
        if is_pcrel(mn):
            mt = re.search(r'(?:0x)?([0-9a-f]+)$', ops)
            if mt:
                tgt = int(mt.group(1), 16)
                if tgt >= 0x80000000:
                    tgt -= 0x100000000
        dec[a] = (mn, ops, n, tgt)
    return dec


def walk(dec, entries, img):
    visited, need = {}, set()
    work = list(entries)
    while work:
        a = work.pop()
        while 0 <= a < CODE_END and a not in visited:
            if a not in dec or dec[a][0] == '.byte':
                need.add(a)
                break
            mn, ops, n, tgt = dec[a]
            visited[a] = dec[a]
            nxt = a + n
            if mn.startswith('call') and not mn.startswith('callx'):
                work.append(tgt)
                if img[nxt:nxt + 3] == b'\0\0\0':
                    break          # zero bytes follow the call: not decoded as code
            elif tgt is not None and mn != 'l32r':
                work.append(tgt)
            if mn in ENDS:
                break
            a = nxt
    return visited, need


def overlaps(visited):
    owner, bad = {}, []
    for a, v in sorted(visited.items()):
        for k in range(a, a + v[2]):
            if k in owner:
                bad.append((owner[k], a))
            owner[k] = a
    return bad


def solve(d, img, entries, points=()):
    points = set(entries) | set(points)
    for _ in range(60):
        dec = decode(d, img, points)
        vis, need = walk(dec, entries, img)
        if not need:
            return dec, vis, points
        points |= need
    raise SystemExit('decode does not converge')


def data_code_pointers(img, regions):
    out = []
    for lo, hi in regions:
        for p in range(lo, hi - 3, 4):
            v = struct.unpack_from('<I', img, p)[0]
            if BASE <= v < BASE + CODE_END:
                out.append((p, v - BASE))
    return out


def full_decode(d, img, data_regions):
    entries = {0x400} | set(EXTRA_ENTRIES)
    entries |= {v for v, _, _ in VECTORS if any(img[v:v + 0x40])}
    dec, vis, pts = solve(d, img, entries)
    # words in the data part that hold code addresses
    cands = {t for _, t in data_code_pointers(img, data_regions)}
    dec2, vis2, pts2 = solve(d, img, entries | cands, pts)
    if overlaps(vis2):
        raise SystemExit('code pointers from data overlap: %r' % overlaps(vis2)[:5])
    entries |= cands
    dec, vis, pts = dec2, vis2, pts2
    # 4-aligned entry instructions not reached yet
    for _ in range(30):
        cov = set()
        for a, v in vis.items():
            cov.update(range(a, a + v[2]))
        more = {i for i in range(CODE_START, CODE_END, 4)
                if img[i] == 0x36 and img[i + 1] & 0xf == 1 and i not in cov}
        if not more:
            break
        e2 = entries | more
        dec2, vis2, pts2 = solve(d, img, e2, pts)
        if overlaps(vis2):
            # some of them lie inside instructions of the others: take the lowest only
            e2 = entries | {min(more)}
            dec2, vis2, pts2 = solve(d, img, e2, pts)
        entries, dec, vis, pts = e2, dec2, vis2, pts2
    return dec, vis, pts, entries


def in_code_literals(vis):
    return {v[3] for v in vis.values() if v[0] == 'l32r' and v[3] is not None and 0 <= v[3] < CODE_END}


def dead_code(d, img, vis, pts, lits):
    """Decode the non-zero bytes that are not reached, linearly; they must end on a boundary."""
    cov = bytearray(CODE_END)
    for a, v in vis.items():
        cov[a:a + v[2]] = b'\1' * v[2]
    for l in lits:
        cov[l:l + 4] = b'\1\1\1\1'
    runs, k = [], 0
    while k < CODE_END:
        if cov[k] or not img[k]:
            k += 1
            continue
        s = k
        while k < CODE_END and not cov[k]:
            k += 1
        e = k
        while e > s and not img[e - 1]:
            e -= 1
        runs.append((s, e))
    dec = decode(d, img, set(pts) | {s for s, _ in runs} | set(lits) | {l + 4 for l in lits})
    dead = {}
    for s, e in runs:
        a = s
        while a < e:
            if a not in dec or dec[a][0] == '.byte':
                raise SystemExit('cannot decode unreached bytes at 0x%x' % a)
            dead[a] = dec[a]
            a += dec[a][2]
        if a != e and cov[a] == 0 and any(img[e:a]):
            raise SystemExit('unreached bytes at 0x%x-0x%x do not end on a boundary' % (s, e))
        if a > e and (a > CODE_END or cov[e:a].count(1)):
            raise SystemExit('unreached decode at 0x%x runs into decoded code' % s)
    return dead


# ---------------------------------------------------------------- helpers for text

def cstr(bs):
    out = []
    for b in bs:
        c = chr(b)
        if c == '"':
            out.append('\\"')
        elif c == '\\':
            out.append('\\\\')
        elif c == '\n':
            out.append('\\n')
        elif c == '\r':
            out.append('\\r')
        elif c == '\t':
            out.append('\\t')
        elif 0x20 <= b < 0x7f:
            out.append(c)
        else:
            out.append('\\%03o' % b)
    return ''.join(out)


def printable(b):
    return 0x20 <= b < 0x7f or b in (9, 10, 13)


def col(line, comment, width=40):
    n = len(line.expandtabs(8))
    return line + (' ' * (width - n) if n < width else ' ') + '# ' + comment


def wrap_list(prefix, items, width=110):
    lines, cur = [], prefix
    for i, it in enumerate(items):
        piece = it + (', ' if i < len(items) - 1 else '')
        if len(cur) + len(piece) > width and cur.strip() != prefix.strip():
            lines.append(cur.rstrip())
            cur = '#' + ' ' * (len(prefix) - 1) + piece
        else:
            cur += piece
    lines.append(cur.rstrip())
    return lines


# ---------------------------------------------------------------- the generator

class Gen:
    def __init__(self, img, d):
        self.img, self.d = img, d
        self.sec = []
        for p in range(SECTAB, SECTAB + 0xC0, 12):
            self.sec.append(struct.unpack_from('<III', img, p))
        # copied regions: (prefix, flash offset, end offset, ram start)
        names = {}
        self.regions = []
        for ra, rb, src in self.sec:
            if rb > ra:
                off = src - BASE
                pre = {0: 'ro', 1: 'lit', 2: 'data'}[len(self.regions)]
                self.regions.append((pre, off, off + (rb - ra), ra))
        assert [r[1] for r in self.regions] == [0xACF8, 0xC768, 0xD088], self.regions
        self.data_regions = [(r[1], r[2]) for r in self.regions]

    # name of a RAM address in a copied region, and the image offset it is copied from
    def ram(self, v):
        for pre, lo, hi, ra in self.regions:
            if ra <= v < ra + (hi - lo):
                return '%s_%08x' % (pre, v), lo + (v - ra), pre
        for pre, lo, hi, ra in self.regions:
            if v == ra + (hi - lo):
                return '%s_%08x' % (pre, v), hi, pre
        return None, None, None

    def run(self):
        img = self.img
        dec, vis, pts, entries = full_decode(self.d, img, self.data_regions)
        lits = in_code_literals(vis)
        dead = dead_code(self.d, img, vis, pts, lits)
        self.vis, self.dead, self.lits = vis, dead, lits
        self.insn = dict(vis)
        self.insn.update(dead)
        if overlaps(self.insn):
            raise SystemExit('overlap %r' % overlaps(self.insn)[:5])
        calls = defaultdict(set)      # target -> call sites
        for a, v in self.insn.items():
            if v[0] in ('call0', 'call4', 'call8', 'call12'):
                calls[v[3]].add(a)
        self.calls = calls
        # function starts in the program code
        starts = {CODE_START} | set(EXTRA_ENTRIES)
        # 4-aligned entry instructions start functions, unless the instruction before them runs into
        # them (fall-through) and nothing calls them or stores their address
        ends_at = {a + v[2]: v for a, v in self.insn.items()}
        dptr = {t for _, t in data_code_pointers(img, self.data_regions)}
        self.fallthrough_entries = set()
        for a, v in vis.items():
            if v[0] == 'entry' and a % 4 == 0 and a >= CODE_START:
                prev = ends_at.get(a)
                if prev and prev[0] not in ENDS and a not in calls and a not in dptr:
                    self.fallthrough_entries.add(a)
                else:
                    starts.add(a)
        starts |= {t for t in calls if t >= CODE_START}
        # the user exception vector loads the table address from its literal word (l32r) and jumps
        # through entry EXCCAUSE of it (causes 6 and up use entry 0): those targets start handlers
        uv = [a for a in sorted(self.insn) if 0x340 <= a < 0x380 and self.insn[a][0] == 'l32r']
        assert len(uv) == 1 and any(self.insn[a][0] == 'bgeui' and self.insn[a][1].endswith(', 6, ' +
                                    '%x' % self.insn[a][3]) for a in self.insn if 0x340 <= a < 0x380)
        tab = struct.unpack_from('<I', img, self.insn[uv[0]][3])[0]
        self.exc_table = self.ram(tab)[1]
        self.exc_handlers = set()
        for k in range(EXC_ENTRIES):
            t = struct.unpack_from('<I', img, self.exc_table + 4 * k)[0] - BASE
            self.exc_handlers.add(t)
            if t >= CODE_START:
                starts.add(t)
        self.starts = sorted(starts)
        self.labels = {}
        for s in self.starts:
            self.labels[s] = 'fn_%08x' % A(s)
        for t in self.exc_handlers:
            self.labels[t] = 'fn_%08x' % A(t)
        for v, _, _ in VECTORS:
            if v in self.insn:
                self.labels.setdefault(v, 'vec_%08x' % A(v))
        self.labels[0] = 'vec_base'
        self.labels[0x400] = 'reset_%08x' % A(0x400)
        for a, v in self.insn.items():
            if v[3] is not None and v[0] != 'l32r' and 0 <= v[3] < CODE_END:
                self.labels.setdefault(v[3], '.L%08x' % A(v[3]))
        for l in lits:
            self.labels[l] = 'lit_%08x' % A(l)
        for p, t in data_code_pointers(img, self.data_regions):
            if t in self.insn:
                self.labels.setdefault(t, '.L%08x' % A(t))
        # references into the copied regions: name -> set of referencing places
        self.ramrefs = defaultdict(set)     # image offset of the label -> name
        self.refby = defaultdict(set)       # label name -> referencing description
        for a, v in self.insn.items():
            if v[0] == 'l32r' and v[3] < 0:
                nm, off, pre = self.ram(A(v[3]) & 0xffffffff)
                if nm is None:
                    raise SystemExit('l32r at 0x%x loads from 0x%08x outside the copies' % (a, A(v[3])))
                self.ramrefs[off] = nm
        self.word_syms = {}
        for p in list(range(0xACF8, 0xD8DC - 3, 4)) + sorted(lits):
            if any(lo <= p < hi for lo, hi in self.data_regions) or p in lits:
                v = struct.unpack_from('<I', img, p)[0]
                s = self.value_sym(v)
                if s:
                    self.word_syms[p] = s
        self.owner = self.make_owner()
        self.write_all()

    def value_sym(self, v):
        if BASE <= v < BASE + CODE_END:
            t = v - BASE
            if t in self.labels and not self.labels[t].startswith('lit_'):
                return self.labels[t]
            return None
        if v == BASE + SECTAB:
            return 'section_table'
        nm, off, pre = self.ram(v)
        if nm:
            self.ramrefs[off] = nm
            return nm
        return None

    def make_owner(self):
        """image offset -> unit name, for cross-references"""
        own = {}
        for a in self.insn:
            if a >= CODE_START:
                i = max(i for i, s in enumerate(self.starts) if s <= a)
                own[a] = self.labels[self.starts[i]]
            elif a >= 0x400:
                own[a] = 'reset_40000400'
            else:
                own[a] = self.vector_of(a)
        return own

    def vector_of(self, a):
        if 0x10 <= a < 0x40 or 0x50 <= a < 0x80:     # fn_40000010 in the window 4 slots
            return self.labels[0x10]
        return 'vec_%08x' % A(a & ~0x3f) if a & ~0x3f else 'vec_base'

    # ---------------- code emission
    def ins_text(self, a, v):
        mn, ops, n, tgt = v
        cm = '%08x' % A(a)
        if tgt is not None:
            if mn == 'l32r':
                if tgt < 0:
                    nm, off, pre = self.ram(A(tgt) & 0xffffffff)
                    w = struct.unpack_from('<I', self.img, off)[0]
                    sym = self.word_syms.get(off)
                    cm += '  = ' + (sym if sym else '0x%08x' % w)
                    txt = self.text_at(sym)
                    if txt:
                        cm += ' ' + txt
                else:
                    nm = self.labels[tgt]
                    w = struct.unpack_from('<I', self.img, tgt)[0]
                    cm += '  = ' + (self.word_syms.get(tgt) or '0x%08x' % w)
            else:
                nm = self.labels.get(tgt) if 0 <= tgt < CODE_END else None
                if nm is None:
                    raise SystemExit('no label for target 0x%x at 0x%x' % (tgt, a))
            ops = re.sub(r'(?:0x)?[0-9a-f]+$', nm, ops)
        line = '\t%s\t%s' % (mn, ops) if ops else '\t%s' % mn
        return col(line, cm)

    def text_at(self, sym):
        """the string at a ro_ label, shortened, or None"""
        if not sym or not sym.startswith('ro_'):
            return None
        nm, off, pre = self.ram(int(sym[3:], 16))
        e = off
        while e < len(self.img) and printable(self.img[e]) and e - off < 200:
            e += 1
        if e - off >= 3 and self.img[e] == 0:
            s = cstr(self.img[off:e])
            return '"%s"' % (s if len(s) <= 60 else s[:57] + '...')
        return None

    def emit_code(self, lo, hi, org_points=(), first_label=True, end_org=False):
        """lines for image range [lo, hi): instructions, literal words, zero gaps. org_points: offset ->
        lines (with an .org) placed before it; end_org: the caller places an .org at hi."""
        out = []
        a = lo
        org_points = dict(org_points)
        while a < hi:
            if a in org_points:
                out.extend(org_points.pop(a))
            if a in self.labels and (a != lo or first_label):
                out.append('%s:' % self.labels[a])
            if a in self.insn:
                out.append(self.ins_text(a, self.insn[a]))
                a += self.insn[a][2]
            elif a in self.lits:
                v = struct.unpack_from('<I', self.img, a)[0]
                out.append(col('\t.word\t%s' % (self.word_syms.get(a) or '0x%08x' % v), '%08x' % A(a)))
                a += 4
            else:
                s = a
                while a < hi and a not in self.insn and a not in self.lits and a not in org_points:
                    if self.img[a]:
                        raise SystemExit('non-zero byte 0x%x left at 0x%x' % (self.img[a], a))
                    a += 1
                if a in org_points or (a == hi and end_org):
                    continue           # the .org line covers it
                n = a - s
                if a % 4 == 0 and n < 4:
                    out.append(col('\t.balign\t4, 0', '%d zero byte%s up to the 4-byte boundary 0x%08x'
                                   % (n, 's' if n > 1 else '', A(a))))
                else:
                    out.append(col('\t.space\t%d, 0' % n, '%d zero bytes, 0x%08x-0x%08x' % (n, A(s), A(a) - 1)))
        return out

    # ---------------- per-function header
    def fn_info(self, lo, hi):
        img = self.img
        ins = [(a, self.insn[a]) for a in sorted(self.insn) if lo <= a < hi]
        calls, xcalls, sregs, strs, consts, syms = [], 0, [], [], [], []
        for a, v in ins:
            mn = v[0]
            if mn in ('call0', 'call4', 'call8', 'call12'):
                nm = self.labels[v[3]]
                if nm not in calls:
                    calls.append(nm)
            elif mn.startswith('callx'):
                xcalls += 1
            elif mn.startswith(('rsr.', 'wsr.', 'xsr.')):
                r = mn.split('.', 1)[1]
                if r not in sregs:
                    sregs.append(r)
            elif mn == 'l32r':
                if v[3] < 0:
                    nm, off, pre = self.ram(A(v[3]) & 0xffffffff)
                else:
                    off = v[3]
                w = struct.unpack_from('<I', img, off)[0]
                sym = self.word_syms.get(off)
                t = self.text_at(sym)
                if t:
                    if t not in strs:
                        strs.append(t)
                elif sym:
                    if sym not in syms:
                        syms.append(sym)
                elif '0x%08x' % w not in consts:
                    consts.append('0x%08x' % w)
        return ins, calls, xcalls, sregs, strs, consts, syms

    def callers(self, t):
        cs = sorted({self.owner[a] for a in self.calls.get(t, ())})
        refs = sorted('0x%08x' % A(p) for p, v in self.word_syms.items()
                      if v == self.labels.get(t))
        return cs, refs

    def header(self, name, lo, hi, end_used, what=None):
        ins, calls, xcalls, sregs, strs, consts, syms = self.fn_info(lo, hi)
        h = ['# %s: 0x%08x-0x%08x (firmware file offset 0x%05x-0x%05x), %d instructions'
             % (name, A(lo), A(end_used) - 1, OFF + lo, OFF + end_used - 1, len(ins))]
        if what:
            h += textwrap.wrap(what, 108, initial_indent='# ', subsequent_indent='# ')
        t = lo
        cs, refs = self.callers(t)
        if cs:
            h += wrap_list('# Called from: ', cs)
        if refs:
            h += wrap_list('# Address stored in the words at: ', refs)
        if not cs and not refs and not what:
            h.append('# No call instruction targets it and no 4-byte aligned word in the program holds its address.')
        if calls:
            h += wrap_list('# Calls: ', calls)
        if xcalls:
            h.append('# Indirect calls (callx): %d' % xcalls)
        if strs:
            h += wrap_list('# Text loaded: ', strs)
        if syms:
            h += wrap_list('# Addresses loaded: ', syms)
        if consts:
            h += wrap_list('# Other literal values: ', consts)
        if sregs:
            h += wrap_list('# Special registers: ', sregs)
        nd = sum(1 for a, _ in ins if a in self.dead)
        if nd:
            h.append('# %d instruction%s after an unconditional jump or return: no branch, jump, call or '
                     'stored address leads to %s.' % (nd, 's' if nd > 1 else '', 'them' if nd > 1 else 'it'))
        return h

    # ---------------- files
    def write(self, name, lines):
        open(os.path.join(out_dir, name), 'w').write('\n'.join(lines).rstrip('\n') + '\n')

    def write_all(self):
        os.makedirs(out_dir, exist_ok=True)
        self.ranges = []
        incs = []
        incs.append(self.write_vectors())
        incs.append(self.write_reset())
        bounds = self.starts + [CODE_END]
        self.prev_end = CODE_START
        for s, e in zip(self.starts, bounds[1:]):
            incs.append(self.write_fn(s, e))
        incs.append(self.write_sectab())
        incs += self.write_data()
        self.write_master(incs)
        self.ranges.sort(key=lambda r: int(r['start'], 16))

    def write_vectors(self):
        lines = ['# vectors: 0x40000000-0x400003ff (firmware file offset 0x30000-0x303ff)',
                 '# The reset code writes 0x40000000 (vec_base) to VECBASE. Each vector slot is 0x40 bytes and is',
                 '# placed with .org; the bytes between the instructions are zero. Slot names: the window vectors',
                 '# are at fixed offsets in the Xtensa ISA, the others follow the usual Xtensa LX layout (a core',
                 '# configuration choice); the note after each name says what the slot\'s instructions do.',
                 '# fn_40000010 is entered through the exception-cause table at ro_3ffe19fc (entry 5); it is placed',
                 '# in the free space of the window overflow 4 and underflow 4 slots.']
        slots = []
        for v, nm, note in VECTORS:
            hdr = ['', '# ---- 0x%08x  %s: %s' % (A(v), nm, note)]
            if v:
                hdr.append('\t.org\t0x%03x, 0' % v)
            slots.append((v, hdr))
        # handler at 0x10 and the in-code literal 0x338 come from the generic emitter
        body = self.emit_code(0, 0x400, slots, end_org=True)
        lines += body
        lines.append('\t.org\t0x400, 0')
        self.write('vectors.S', lines)
        self.ranges.append({'name': 'vectors', 'start': '0x%08x' % A(0), 'end': '0x%08x' % A(0x400),
                            'kind': 'code', 'file': 'src/tensilica/vectors.S'})
        return 'vectors.S'

    def write_reset(self):
        cs = sorted(self.labels[t] for a in range(0x400, 0x540) if a in self.insn
                    for t in [self.insn[a][3]] if self.insn[a][0].startswith('call') and t is not None)
        ins = [a for a in self.insn if 0x400 <= a < 0x800]
        lines = ['# reset_40000400: 0x40000400-0x400007ff (firmware file offset 0x30400-0x307ff), %d instructions'
                 % len(ins),
                 '# Jumps over its own literal words (lit_40000404-lit_40000434). Writes INTENABLE, VECBASE',
                 '# (lit_40000408), ATOMCTL and PS (rsil 1); writes the instruction and data TLB entries (witlb,',
                 '# wdtlb) from the nibbles of lit_4000040c; calls (callx0) the address in lit_40000418 when it is',
                 '# not 0; copies the regions listed in section_table to RAM; sets WINDOWSTART, WINDOWBASE and',
                 '# EXCSAVE2-EXCSAVE5 (the EXCSAVE4 and EXCSAVE5 values are also stored at data_3ffe2a70 and',
                 '# data_3ffe2be0); then calls (call0) ' + ', '.join(cs) + '.',
                 '# The bytes after the call up to 0x40000800 are zero.', '']
        lines += self.emit_code(0x400, 0x800, end_org=True)
        lines.append('\t.org\t0x800, 0')
        self.write('reset.S', lines)
        self.ranges.append({'name': 'reset_40000400', 'start': '0x40000400', 'end': '0x40000800',
                            'kind': 'code', 'file': 'src/tensilica/reset.S'})
        return 'reset.S'

    def write_fn(self, s, e):
        name = self.labels[s]
        used = max(a + self.insn[a][2] for a in self.insn if s <= a < e)
        if any(self.img[used:e]):
            raise SystemExit('non-zero bytes after %s' % name)
        what = None
        if s in EXTRA_ENTRIES:
            what = 'Entered without a call: ' + EXTRA_ENTRIES[s] + '.'
        elif s in self.exc_handlers:
            what = 'Entered without a call: by jx from the user exception vector (0x40000340), through ' \
                   'the exception-cause table at ro_3ffe19fc.'
        elif s == CODE_START:
            what = 'Called with call0 from the reset code; it does not start with entry.'
        h = self.header(name, s, e, used, what)
        gap = s - self.prev_end
        if gap < 4:
            pad = col('\t.balign\t4, 0', 'functions start on a 4-byte boundary; any gap is zero bytes')
        else:
            pad = col('\t.space\t%d, 0' % gap, '%d zero bytes after the previous function, 0x%08x-0x%08x'
                      % (gap, A(self.prev_end), A(s) - 1))
        padn = s - self.prev_end
        self.prev_end = used
        lines = h + ['', pad, '\t.type\t%s, @function' % name, '%s:' % name]
        # trailing zero bytes are covered by the .balign of the next file (or the end of the code)
        lines += self.emit_code(s, used, first_label=False)
        lines.append('\t.size\t%s, . - %s' % (name, name))
        fname = '%s.S' % name
        self.write(fname, lines)
        self.ranges.append({'name': name, 'start': '0x%08x' % A(s), 'end': '0x%08x' % A(used),
                            'kind': 'code', 'file': 'src/tensilica/' + fname, 'zero_fill_before': padn})
        if used != e and e == CODE_END:
            self.tail_pad = (used, e)
        return fname

    def write_sectab(self):
        lines = ['# section_table: 0x4000ac38-0x4000acf7 (firmware file offset 0x3ac38-0x3acf7)',
                 '# 16 records of three words: RAM start, RAM end, flash source. The reset code (reset_40000400)',
                 '# reads it from lit_4000041c and copies each record\'s source to RAM start..RAM end; a record',
                 '# with RAM start, RAM end and source all 0 ends the table. Three records have data: read-only',
                 '# data, the literal words of the program code and the initialised data.', '']
        pad = getattr(self, 'tail_pad', None)
        if pad:
            n = pad[1] - pad[0]
            lines.append(col('\t.balign\t4, 0' if n < 4 else '\t.space\t%d, 0' % n,
                             '%d zero bytes after the last function' % n))
        lines.append('section_table:')
        regname = {0xACF8: ('rodata_start', 'rodata_end'), 0xC768: ('literals_start', 'literals_end'),
                   0xD088: ('data_start', 'data_end')}
        ramname = {0xACF8: 'RODATA_RAM', 0xC768: 'LITERALS_RAM', 0xD088: 'DATA_RAM'}
        for i, (ra, rb, src) in enumerate(self.sec):
            p = SECTAB + 12 * i
            off = src - BASE
            if rb > ra:
                st, en = regname[off]
                w = '%s, %s + (%s - %s), %s' % (ramname[off], ramname[off], en, st, st)
            else:
                lab = {0xACF8: 'rodata_start', 0xC768: 'literals_start', 0xD084: 'literals_end',
                       0xD8DC: 'image_end'}.get(off)
                w = '0x%08x, 0x%08x, %s' % (ra, rb, lab if lab else ('0x%08x' % src if src else '0'))
                if src == 0 and ra == rb == 0:
                    w = '0, 0, 0'
            lines.append(col('\t.word\t' + w, '%08x' % A(p)))
        self.write('section_table.S', lines)
        self.ranges.append({'name': 'section_table', 'start': '0x4000ac38', 'end': '0x4000acf8',
                            'kind': 'data', 'file': 'src/tensilica/section_table.S'})
        return 'section_table.S'

    # ---------------- data regions
    def refs_to(self, off):
        """who refers to the label at this image offset: functions loading it, data words holding it"""
        nm = self.ramrefs.get(off)
        res = set()
        for a, v in self.insn.items():
            if v[0] == 'l32r' and v[3] is not None:
                o = v[3] if v[3] >= 0 else self.ram(A(v[3]) & 0xffffffff)[1]
                if o == off:
                    res.add(self.owner[a])
                elif self.word_syms.get(o) == nm and nm:
                    res.add(self.owner[a])
        for p, s in self.word_syms.items():
            if s == nm and nm and not (0xC768 <= p < 0xD084):
                res.add('word at 0x%08x' % A(p))
        return sorted(res)

    def emit_region(self, pre, lo, hi, ram):
        img = self.img
        labels = {o: n for o, n in self.ramrefs.items() if lo <= o <= hi and n.startswith(pre + '_')}
        cuts = sorted(set(labels) | {lo, hi})
        out = []
        delta = {'ro': 'rodata_start', 'lit': 'literals_start', 'data': 'data_start'}[pre]
        ramc = {'ro': 'RODATA_RAM', 'lit': 'LITERALS_RAM', 'data': 'DATA_RAM'}[pre]
        for i, a in enumerate(cuts):
            if a in labels:
                rf = self.refs_to(a) if pre != 'lit' else []
                if rf:
                    out.append('')
                    out += wrap_list('# used by: ', rf)
                out.append('%s = . - %s + %s' % (labels[a], delta, ramc))
            if a >= hi:
                break
            b = cuts[i + 1]
            out += self.emit_chunk(a, b, pre)
        return out

    def emit_chunk(self, a, b, pre):
        img = self.img
        out = []
        # text: printable run of 3+ with a letter, NUL, then zero padding
        p = a
        seg = []
        ok = True
        while p < b:
            q = p
            while q < b and printable(img[q]):
                q += 1
            s = img[p:q]
            if q < b and img[q] == 0 and len(s) >= 2:
                seg.append(('str', p, q + 1))
                p = q + 1
                z = p
                while z < b and img[z] == 0 and (z % 4 or z == p and False):
                    z += 1
                if z > p:
                    seg.append(('pad', p, z))
                p = z
                continue
            if q == p and all(x == 0 for x in img[p:b]) and seg:
                seg.append(('zero', p, b))
                p = b
                continue
            ok = False
            break
        if ok and seg:
            for k, s, e in seg:
                if k == 'str':
                    out.append(col('\t.asciz\t"%s"' % cstr(img[s:e - 1]), '%08x' % A(s))) \
                        if len(cstr(img[s:e - 1])) < 60 else out.extend(self.long_str(s, e))
                elif k == 'pad':
                    n = e - s
                    if e % 4 == 0:
                        out.append(col('\t.balign\t4, 0', 'zero bytes up to the 4-byte boundary'))
                    else:
                        out.append('\t.byte\t' + ', '.join(['0'] * n))
                else:
                    out.append(col('\t.space\t%d, 0' % (e - s), '%08x' % A(s)))
            return out
        # words (and bytes at unaligned ends); text at 4-byte aligned places
        p = a
        if p % 4:
            n = min(4 - p % 4, b - p)
            out.append(col('\t.byte\t' + ', '.join('0x%02x' % x for x in img[p:p + n]), '%08x' % A(p)))
            p += n
        while p + 4 <= b:
            q = p
            while q < b and printable(img[q]):
                q += 1
            if not self.word_syms.get(p) and (q - p >= 2 and q < b and img[q] == 0 or
                                               q - p >= 4 and q == b):
                nul = q < b and img[q] == 0
                t = cstr(img[p:q])
                out.append(col('\t%s\t"%s"' % ('.asciz' if nul else '.ascii', t), '%08x' % A(p)))
                p = q + (1 if nul else 0)
                z = p
                while z < b and z % 4 and img[z] == 0:
                    z += 1
                if z > p and z % 4 == 0:
                    out.append(col('\t.balign\t4, 0', 'zero bytes up to the 4-byte boundary'))
                    p = z
                elif p % 4:
                    n = min(4 - p % 4, b - p)
                    out.append(col('\t.byte\t' + ', '.join('0x%02x' % x for x in img[p:p + n]), '%08x' % A(p)))
                    p += n
                continue
            # run of zero words
            z = p
            while z + 4 <= b and img[z:z + 4] == b'\0\0\0\0':
                z += 4
            if z - p >= 16:
                out.append(col('\t.space\t%d, 0' % (z - p), '%08x' % A(p)))
                p = z
                continue
            vals = []
            q = p
            while q + 4 <= b and len(vals) < 4:
                v = struct.unpack_from('<I', img, q)[0]
                s = self.word_syms.get(q)
                if s and vals:
                    break
                vals.append(s or '0x%08x' % v)
                q += 4
                if s:
                    break
                if q + 16 <= b and img[q:q + 16] == bytes(16):
                    break
            out.append(col('\t.word\t' + ', '.join(vals), '%08x' % A(p)))
            p = q
        if p < b:
            out.append(col('\t.byte\t' + ', '.join('0x%02x' % x for x in img[p:b]), '%08x' % A(p)))
        return out

    def long_str(self, s, e):
        """a long string, split after \\n or every 60 characters; .ascii pieces, the last .asciz"""
        img = self.img
        parts, p = [], s
        while p < e - 1:
            q = p
            while q < e - 1 and q - p < 48 and img[q] != 10:
                q += 1
            if q < e - 1 and img[q] == 10:
                q += 1
            parts.append((p, q))
            p = q
        out = []
        for i, (p, q) in enumerate(parts):
            d = '.asciz' if i == len(parts) - 1 else '.ascii'
            out.append(col('\t%s\t"%s"' % (d, cstr(img[p:q])), '%08x' % A(p)))
        return out

    def write_data(self):
        files = []
        info = {
            'ro': ('rodata.S', 'rodata', 'Read-only data', 'RODATA_RAM'),
            'lit': ('literals.S', 'literals', 'Literal words of the program code (read with l32r)', 'LITERALS_RAM'),
            'data': ('data.S', 'data', 'Initialised data', 'DATA_RAM'),
        }
        for pre, lo, hi, ram in self.regions:
            fname, start, title, ramc = info[pre]
            lines = ['# %s: 0x%08x-0x%08x (firmware file offset 0x%05x-0x%05x)'
                     % (title, A(lo), A(hi) - 1, OFF + lo, OFF + hi - 1),
                     '# The reset code copies this region to RAM 0x%08x-0x%08x (section_table); the code uses the'
                     % (ram, ram + hi - lo - 1),
                     '# RAM addresses. Each label %s_XXXXXXXX is the RAM address of the byte that follows it.' % pre]
            if pre == 'ro':
                lines += ['# Text is written as .ascii/.asciz, tables of code addresses as .word with labels, other',
                          '# data as .word in hex.']
            if pre == 'lit':
                lines += ['# The literal word for each l32r of the program code; the l32r names its word by the',
                          '# RAM address (lit_XXXXXXXX). Code addresses are written as labels, RAM addresses of',
                          '# copied data as ro_/data_ names.']
            lines += ['', '%s_start:' % start]
            if pre == 'lit':
                lines += self.emit_literals(lo, hi)
            else:
                lines += self.emit_region(pre, lo, hi, ram)
            lines.append('%s_end:' % start)
            if pre == 'lit':
                n = 0xD088 - hi
                lines += ['', col('\t.space\t%d, 0' % n, '%d zero bytes, 0x%08x-0x%08x' % (n, A(hi), A(0xD088) - 1))]
            if pre == 'data':
                lines.append('image_end:')
            self.write(fname, lines)
            files.append(fname)
            self.ranges.append({'name': start, 'start': '0x%08x' % A(lo), 'end': '0x%08x' % A(hi),
                                'kind': 'data', 'file': 'src/tensilica/' + fname})
        return files

    def emit_literals(self, lo, hi):
        out = []
        img = self.img
        users = defaultdict(set)
        for a, v in self.insn.items():
            if v[0] == 'l32r' and v[3] < 0:
                users[self.ram(A(v[3]) & 0xffffffff)[1]].add(self.owner[a])
        lastu = None
        for p in range(lo, hi, 4):
            if p in self.ramrefs:
                u = sorted(users.get(p, ()))
                if u and u != lastu:
                    out += wrap_list('# used by: ', u)
                lastu = u
                out.append('%s = . - literals_start + LITERALS_RAM' % self.ramrefs[p])
            v = struct.unpack_from('<I', img, p)[0]
            s = self.word_syms.get(p)
            cm = '%08x' % A(p)
            t = self.text_at(s)
            if t:
                cm += ' ' + t
            out.append(col('\t.word\t%s' % (s or '0x%08x' % v), cm))
        return out

    def write_master(self, incs):
        lines = [
            '# Tensilica program of the MSI MPG321URX firmware FW.021: flash bank 3, firmware file offset',
            '# 0x30000-0x3d8db (0xd8dc bytes), runs at 0x40000000.',
            '#',
            '# Assembly source; the files are included in address order and assemble to the same bytes as the',
            '# firmware. Build and compare: python3 tools/xtensa_check.py (see README.md in this directory).',
            '',
            '\t.section .text',
            '\t.begin\tno-transform',
            '',
            '# RAM addresses that the reset code copies the data regions to (section_table)',
            '\t.set\tRODATA_RAM, 0x%08x' % self.regions[0][3],
            '\t.set\tLITERALS_RAM, 0x%08x' % self.regions[1][3],
            '\t.set\tDATA_RAM, 0x%08x' % self.regions[2][3],
            '',
        ]
        for f in incs:
            lines.append('\t.include\t"%s"' % f)
        lines += ['', '\t.end\tno-transform']
        self.write('tensilica.S', lines)


def main():
    global out_dir
    args = sys.argv[1:]
    if '--out' in args:
        out_dir = os.path.abspath(args[args.index('--out') + 1])
    ranges = args[args.index('--ranges') + 1] if '--ranges' in args else None
    d = args[args.index('--tmp') + 1] if '--tmp' in args else tempfile.mkdtemp()
    img = open(FW, 'rb').read()[OFF:OFF + SIZE]
    g = Gen(img, d)
    g.run()
    print('functions: %d, instructions: %d (%d not reached by any branch), files: %d'
          % (len(g.starts), len(g.insn), len(g.dead), len(g.ranges) + 1))
    if ranges:
        json.dump(g.ranges, open(ranges, 'w'), indent=1)
        print('ranges:', ranges)


if __name__ == '__main__':
    main()
