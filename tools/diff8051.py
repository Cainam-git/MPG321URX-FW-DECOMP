#!/usr/bin/env python3
"""Judge for the 8051 side. Compile with Keil C51 (eval, under Wine), read the
OMF51 object directly, mask every byte a linker fixup would patch (addresses of
other functions, globals, strings), and compare the remaining bytes with the
firmware bank at the function's address. MATCH = same length and every
non-fixup byte identical. The readable diff pairs Keil's listing with the
firmware disassembly from Ghidra.

Usage: diff8051.py <bank> <function> <file.c> [--quiet]
   bank = 8051_bank0..3, function = name in symbols/<bank>.functions.json
Keil options come from tools/config.json ("8051": {"c51opts": "..."}).

Judge extensions:
 - common-entry block in front (Keil OPTIMIZE(8) "reuse of common entry code"): when the function's code segment
   starts with 'FUNCTION L?nnnn' rows that fall into it (entry_block()), the unit is [block start .. function end]:
   block start = function start - block length, and it must be a function boundary in functions.json (an entry
   starts or ends there), so a shorter/longer compiled block cannot pass. Block + function bytes are compared as one
   piece and exact8051 fills the block's fixups too (names that are LARGE/DATA/BIT locals of the calling function
   resolve through that function's SYMBOLS entry). result["span"] / ["block"] tell accept8051 what was judged.
 - SPAN_END: judged end overrides for C functions that functions.json still splits (merge pending in
   symbols/<bank>.merges.json, which only takes effect after a Ghidra re-analysis, tools/reanalyze8051.sh).
"""
import json, os, pathlib, re, struct, subprocess, sys, tempfile, shutil, threading, time
ROOT = pathlib.Path(__file__).resolve().parent.parent
CFG = json.loads((ROOT / "tools" / "config.json").read_text())
KEIL = ROOT / CFG["8051"]["keil_bin"]
ENV = dict(os.environ, WINEPREFIX=str(ROOT / CFG["8051"]["wineprefix"]), WINEDEBUG="-all")
# Judged end (exclusive) per function where one C function is still two functions.json entries. The merge lives
# here until merges.json is updated and Ghidra re-run (tools/reanalyze8051.sh).
#  FUN_CODE_0b0d + FUN_CODE_1397 = one C function 0x0B0D..0x147A (1397 has no caller, entered only by LJMP
#  from 0b0d at 0x1190 / 0x1394, ends in LJMP ?C?LSTXDATA). Pending merges.json: "0x0b0d": "0x147a", drop "0x1397".
SPAN_END = {("8051_bank1", "FUN_CODE_0b0d"): 0x147A,
            # (xref scan: nothing else enters these ranges; pieces 13c8/13eb/140a/140d and 2342/272d are
            # reached only by LJMPs from inside): FUN_CODE_1000 = 0x1000..0x1E55, FUN_CODE_1e55 = 0x1E55..0x2B74
            ("8051_bank2", "FUN_CODE_1000"): 0x1E55, ("8051_bank2", "FUN_CODE_1e55"): 0x2B74,
            # (49-way command switch, case code split over functions.json pieces 236e, 275e, 279f;
            # 0x27B5 is a separate helper with many callers): FUN_CODE_224f = 0x224F..0x27B5
            ("8051_bank1", "FUN_CODE_224f"): 0x27B5}
ROW = r"^([0-9A-F]{4}) ([0-9A-F]+)?\s+(?:([ERF])\s+)?(.*)$"
# Stand-in entries (like SPAN_END, until Ghidra is re-run). Real C functions that
# functions.json does not name: 72b0 and df50 are named there after their common-entry block (72a5 = 0x72a5..0x7677,
# df44 = 0xdf44..0xdf76), 573b is a gap (only SUB_CODE_573b; LCALL target from 5c20 at 0x5d77).
# Pending: real entries in functions.json via Ghidra (tools/reanalyze8051.sh), then drop these.
EXTRA_FUNCS = {"8051_bank2": {"FUN_CODE_72b0": (0x72B0, 0x7677), "FUN_CODE_df50": (0xDF50, 0xDF76),
                              "FUN_CODE_573b": (0x573B, 0x5C20)}}

def funclist(bank):
    """functions.json entries of bank plus the EXTRA_FUNCS stand-ins (a stand-in never replaces a real entry)"""
    fs = json.loads((ROOT / "symbols" / f"{bank}.functions.json").read_text())["functions"]
    have = {f["name"] for f in fs}
    return fs + [{"name": n, "start": a, "end": b, "size": b - a} for n, (a, b) in EXTRA_FUNCS.get(bank, {}).items() if n not in have]

def c51(src_dir, name, opts):
    try:
        r = subprocess.run(["wine", str(KEIL / "C51.exe"), name + ".c", opts + " CODE"], cwd=src_dir,
                           env=ENV, capture_output=True, text=True, timeout=300)
    except subprocess.TimeoutExpired:   # a hung wine/C51 run counts as a failed compile, it must not kill the caller
        return "*** ERROR: C51 timed out after 300 s"
    return r.stdout + r.stderr

def omf51_segments(obj):
    """Return {segment_name: (bytes, set_of_fixup_offsets)} for code segments."""
    d = pathlib.Path(obj).read_bytes()
    i, segs, names, last = 0, {}, {}, None
    while i + 3 <= len(d):
        t = d[i]; ln = struct.unpack_from("<H", d, i + 1)[0]; body = d[i + 3:i + 3 + ln - 1]; i += 3 + ln
        if t == 0x0E:                                  # segment definitions
            j = 0
            while j < len(body):
                sid, info, rtyp = body[j], body[j + 1], body[j + 2]; base, size = struct.unpack_from("<HH", body, j + 3)
                nl = body[j + 7]; nm = body[j + 8:j + 8 + nl].decode("latin1"); j += 8 + nl
                names[sid] = nm; segs.setdefault(nm, [bytearray(size), set()])
        elif t == 0x06:                                # content
            sid = body[0]; off = struct.unpack_from("<H", body, 1)[0]; data = body[3:]
            nm = names.get(sid, f"seg{sid}")
            seg = segs.setdefault(nm, [bytearray(), set()])
            if len(seg[0]) < off + len(data): seg[0].extend(b"\0" * (off + len(data) - len(seg[0])))
            seg[0][off:off + len(data)] = data; last = (nm, off)
        elif t == 0x16 and last:                       # fixups for the last content record
            nm, off = last; j = 0
            while j + 7 <= len(body):
                refloc = struct.unpack_from("<H", body, j)[0]; reftyp = body[j + 2]; j += 7
                width = 2 if reftyp in (4, 5) else 1    # 4 = word, 5 = inblock (2 bytes), others 1 byte
                for k in range(width): segs[nm][1].add(off + refloc + k)
    return segs

def keil_listing(lst_path, fn):
    """Return (listing_lines, code_bytes, fixup_offsets) for one function from Keil's LST.
    Keil flags relocatable operands with R (same module) or E (external); those operand
    bytes are what the linker patches, so they are masked in the comparison."""
    txt = pathlib.Path(lst_path).read_text(errors="replace")
    m = re.search(r"; FUNCTION (?:_\?|\?|_)?%s \(BEGIN\)(.*?); FUNCTION (?:_\?|\?|_)?%s \(END\)" % (re.escape(fn), re.escape(fn)), txt, re.S)  # _ = register params, _? / ? = reentrant
    if not m: return [], b"", set()
    out, code, fx = [], bytearray(), set()
    for ln in m.group(1).splitlines():
        r = re.match(r"^([0-9A-F]{4}) ([0-9A-F]+)?\s+(?:([ERF])\s+)?(.*)$", ln)
        if not r: continue
        off, hx, flag, asm = int(r.group(1), 16), r.group(2), r.group(3), r.group(4).strip()
        if hx:
            b = bytes.fromhex(hx)
            if len(code) < off: code.extend(b"\0" * (off - len(code)))
            code[off:off + len(b)] = b
            if flag in ("E", "R", "F"):
                for k in range(1, len(b)): fx.add(off + k)
            out.append(f"{r.group(1)}  {hx:<8} {asm}")
        elif asm: out.append(f"{r.group(1)}  {'':<8} {asm}")
    return out, bytes(code), fx

def entry_block(txt, fn):
    """Keil common-entry block(s) at the start of fn's own code segment: the 'FUNCTION L?nnnn (BEGIN)' rows right in
    front of fn's BEGIN (no END line in between), with offsets 0 .. len-1, fn's first row at offset len.
    Returns (block_text, listing_lines, code, fixup_offsets) or None when fn's segment does not start with one."""
    lines = txt.splitlines()
    i = next((k for k, ln in enumerate(lines) if re.search(r"; FUNCTION (?:_\?|\?|_)?%s \(BEGIN\)" % re.escape(fn), ln)), None)
    if i is None: return None
    first, j = None, i - 1
    while j >= 0:
        if "; FUNCTION" in lines[j]:
            if not re.match(r"\s*; FUNCTION L\?\d+ \(BEGIN\)", lines[j]): break
            first = j
        j -= 1
    if first is None: return None
    fo = next((int(r[1], 16) for r in (re.match(ROW, ln) for ln in lines[i + 1:]) if r and r[2]), None)
    out, code, fx = [], bytearray(), set()
    for ln in lines[first + 1:i]:
        r = re.match(ROW, ln)
        if not r: continue
        if r[2]:
            off, b = int(r[1], 16), bytes.fromhex(r[2])
            if len(code) < off: code.extend(b"\0" * (off - len(code)))
            code[off:off + len(b)] = b
            if r[3]: fx.update(off + k for k in range(1, len(b)))
            out.append(f"{r[1]}  {r[2]:<8} {r[4].strip()}")
        elif r[4].strip(): out.append(f"{r[1]}  {'':<8} {r[4].strip()}")
    if not code or fo != len(code): return None   # the block must fill the segment exactly up to fn's first row
    return "\n".join(lines[first + 1:i]), out, bytes(code), fx

def _clean_old_k51():
    """remove this user's leftover k51_ judge work dirs in the temp dir that are older than 10 min"""
    import os
    now = time.time()
    try:
        ents = list(os.scandir(tempfile.gettempdir()))
    except OSError:
        return
    for e in ents:
        try:
            if e.name.startswith("k51_") and len(e.name) == 12 and e.is_dir(follow_symlinks=False) \
               and e.stat(follow_symlinks=False).st_uid == os.getuid() and now - e.stat(follow_symlinks=False).st_mtime > 600:
                shutil.rmtree(e.path, ignore_errors=True)
        except OSError:
            pass

def _nopage(txt):
    """drop Keil listing page breaks (form feed + "C51 COMPILER ... PAGE n" + the repeated NAME/==== column header):
    a page break inside the SYMBOLS list would otherwise end a PROC entry early"""
    txt = re.sub(r"^\f?\s*C51 COMPILER V[^\n]*PAGE\s+\d+[^\n]*\n", "", txt, flags=re.M)
    return re.sub(r"^NAME\s+CLASS\s+MSPACE\s+TYPE\s+OFFSET\s+SIZE[^\n]*\n(?:=+[ =]*\n)?", "", txt, flags=re.M)

def _module_autos(txt):
    """{function: {local: (mspace, offset)}} from the SYMBOLS listing (AUTO entries under each PROC)"""
    res = {}
    txt = _nopage(txt)
    for m in re.finditer(r"^[_?]*(\w+?) ?[ .]*(?:PUBLIC|LOCAL|STATIC)\s+CODE\s+PROC.*?$(.*?)(?=^\S|\Z)", txt, re.M | re.S):
        res[m[1]] = {a[1]: (a[2], int(a[3], 16)) for a in re.finditer(r"^\s+(\w+)[ .]*AUTO\s+(\w+)\s+\S+\s+([0-9A-F]{4})H", m[2], re.M)}
    return res

def ghidra_listing(bank, start, end):
    out = []
    for ln in (ROOT / "decomp" / f"{bank}.lst").read_text(errors="replace").splitlines():
        r = re.match(r"^CODE:CODE:([0-9a-f]{4})\s+([0-9a-f]+)\s+(\S+)\s*(.*)$", ln)
        if r and start <= int(r.group(1), 16) < end:
            out.append(f"{r.group(1).upper()}  {r.group(2).upper():<8} {r.group(3)} {r.group(4).strip()}")
    return out

def _libs_load(lib):
    """symbols/<bank>.libs.json, read safely while other judges running in parallel may be replacing it"""
    for _ in range(50):
        try: return json.loads(lib.read_text()) if lib.exists() else {}
        except (json.JSONDecodeError, OSError): time.sleep(0.05)
    return json.loads(lib.read_text())

def _libs_save(lib, libs):
    """merge with what is on disk now and replace the file atomically (first recorded value wins)"""
    cur = _libs_load(lib); cur.update({k: v for k, v in libs.items() if k not in cur})
    tmp = lib.with_name(f".{lib.name}.{os.getpid()}.{threading.get_ident()}.tmp")
    tmp.write_text(json.dumps(cur, indent=2, sort_keys=True)); os.replace(tmp, lib); libs.update(cur)

def common_block_at(txt, label, bank, addr):
    """addr when the listing block containing label ('; FUNCTION L?nnnn (BEGIN)' .. next FUNCTION line) sits at addr in
    the firmware with every non-fixup byte equal (fixup operands only checked for their opcode byte)"""
    lines = txt.splitlines()
    for i, ln in enumerate(lines):
        m = re.match(r"\s*; FUNCTION (L\?\d+) \(BEGIN\)", ln)
        if not m: continue
        rows, labels, j = [], {m[1]: 0}, i + 1
        while j < len(lines) and "; FUNCTION" not in lines[j]:
            r = re.match(r"^([0-9A-F]{4}) ([0-9A-F]+)?\s+(?:([ERF])\s+)?(.*)$", lines[j])
            if r:
                if r[2]: rows.append((int(r[1], 16), bytes.fromhex(r[2]), bool(r[3])))
                elif r[4].strip().endswith(":"): labels[r[4].strip()[:-1]] = int(r[1], 16)
            j += 1
        if label not in labels: continue
        base = addr - labels[label]
        img = (ROOT / "parts" / f"{bank}.bin").read_bytes()
        for o, b, fx in rows:
            want = img[base + o:base + o + len(b)]
            if (fx and want[:1] != b[:1]) or (not fx and want != b): return None
        return addr
    return None

def common_entry(txt, label, bank):
    """Address of a label inside a Keil common-entry block ('; FUNCTION L?nnnn (BEGIN)' up to the next FUNCTION
    line, which must be the callee the block falls into): callee start (functions.json) - block length + offset.
    None when the block is missing or its non-fixup bytes differ from the firmware at that address."""
    lines = txt.splitlines()
    for i, ln in enumerate(lines):
        m = re.match(r"\s*; FUNCTION (L\?\d+) \(BEGIN\)", ln)
        if not m: continue
        rows, labels, j = [], {m[1]: 0}, i + 1
        while j < len(lines) and "; FUNCTION" not in lines[j]:
            r = re.match(r"^([0-9A-F]{4}) ([0-9A-F]+)?\s+(?:([ERF])\s+)?(.*)$", lines[j])
            if r:
                if r[2]: rows.append((int(r[1], 16), bytes.fromhex(r[2]), bool(r[3])))
                elif r[4].strip().endswith(":"): labels[r[4].strip()[:-1]] = int(r[1], 16)
            j += 1
        if label not in labels or j >= len(lines): continue
        nx = re.match(r"\s*; FUNCTION _?(\w+) \(BEGIN\)", lines[j])
        if not nx: return None
        funcs = {f["name"]: f for f in funclist(bank)}
        if nx[1] not in funcs: return None
        size = max(o + len(b) for o, b, _ in rows) if rows else 0
        base = funcs[nx[1]]["start"] - size
        img = (ROOT / "parts" / f"{bank}.bin").read_bytes()
        for o, b, fx in rows:
            want = img[base + o:base + o + len(b)]
            if (fx and want[0] != b[0]) or (not fx and want != b): return None
        return base + labels[label]
    return None

def exact8051(lst_path, fn, start, code, target, bank, block=None, fn_off=0):
    """Fill every operand the linker would patch (Keil flags E/R/F in the listing) with its real value and compare
    all bytes with the firmware. Outside names must carry their address (FUN_CODE_xxxx, DAT_EXTMEM_xxxx, ...);
    own labels resolve inside the function placed at its real address. None = exact, else a short reason.
    block = entry_block() text when fn's segment starts with a common-entry block: start is then the block's address,
    fn begins at start + fn_off, and the block rows are filled too."""
    txt = pathlib.Path(lst_path).read_text(errors="replace")
    m = re.search(r"; FUNCTION (?:_\?|\?|_)?%s \(BEGIN\)(.*?); FUNCTION (?:_\?|\?|_)?%s \(END\)" % (re.escape(fn), re.escape(fn)), txt, re.S)  # _ = register params, _? / ? = reentrant
    brows = [r for r in (re.match(ROW, ln) for ln in (block or "").splitlines()) if r]
    rows = [re.match(r"^([0-9A-F]{4}) ([0-9A-F]+)?\s+(?:([ERF])\s+)?(.*)$", ln) for ln in m.group(1).splitlines()] if m else []
    rows = brows + [r for r in rows if r]
    others = {k: v for k, v in _module_autos(txt).items() if k != fn} if brows else {}
    def owner(nm):   # block rows: the one other function of the module that has nm as a local (the block's caller)
        hit = [k for k, v in others.items() if nm in v]
        return hit[0] if len(hit) == 1 else None
    # LARGE model: parameters and locals live in the function's own XDATA block; the SYMBOLS listing gives each one's
    # offset (AUTO XDATA ... OFFSET). The block's base is recorded on first use (symbols/<bank>.libs.json,
    # "?<fn>?XD"), every later use must agree with base + offset.
    autos = {}
    sm = re.search(r"^_?%s ?[ .]*PUBLIC\s+CODE\s+PROC.*?$(.*?)(?=^\S|\Z)" % re.escape(fn), _nopage(txt), re.M | re.S)
    if sm:
        for a in re.finditer(r"^\s+(\w+)[ .]*AUTO\s+XDATA\s+\S+\s+([0-9A-F]{4})H", sm.group(1), re.M):
            autos[a[1]] = int(a[2], 16)
    labels = {r[4].strip()[:-1].upper(): int(r[1], 16) for r in rows if not r[2] and r[4].strip().endswith(":")}
    code = bytearray(code)
    for _pass in (0, 1):   # pass 0 learns addresses from LOW / plain uses, pass 1 also fills HIGH bytes
        for r in rows:
            if not (r[2] and r[3]): continue
            off, op, asm = int(r[1], 16), bytes.fromhex(r[2]), r[4].strip()
            if len(op) in (2, 3) and op[0] not in (0x02, 0x12, 0x90) and (op[0] & 0x1F) not in (0x01, 0x11):
                # small model: direct DATA / BIT operand bytes (MOV dir,..., MOV dir,#imm, ORL dir,#, JB bit,...). Each name
                # maps to one byte in text order (0x85 MOV dst,src stores src first). Names with an address suffix resolve to
                # it; others (Keil ?_FN?BYTE parameter blocks, overlaid locals) record their address on first use in
                # symbols/<bank>.libs.json and must agree afterwards.
                ops = asm.split(None, 1)[1] if " " in asm else ""
                parts = [x.strip() for x in re.split(r",(?![^(]*\))", ops)]
                parts = [x for x in parts if x.upper() not in ("A", "C", "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "@R0", "@R1", "DPTR", "@DPTR", "AB")]
                if len(op) == 3 and op[0] not in (0x75, 0x85) and len(parts) == 2: parts = parts[:1]   # dir,rel / bit,rel: last byte is a jump
                pos = [off + 1] if len(op) == 2 else ([off + 2, off + 1] if op[0] == 0x85 else [off + 1, off + 2])
                lib = ROOT / "symbols" / f"{bank}.libs.json"; libs = _libs_load(lib)
                for part, ps in zip(parts, pos):
                    q = re.sub(r"\b[0-9][0-9A-Fa-f]*H\b", "", part)
                    nm = [n for n in re.findall(r"[?A-Za-z_][\w?]*", q) if n not in ("A", "C", "LOW", "HIGH", "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "DPTR")]
                    if not nm: continue
                    if len(nm) != 1: return f"cannot resolve operand of '{asm}'"
                    nm = nm[0]; pl = re.search(r"\+\s*(0x[0-9A-Fa-f]+|[0-9A-F]+H|\d+)", part); po = 0
                    if pl: po = int(pl[1][:-1], 16) if pl[1].endswith("H") else int(pl[1], 0)
                    h = re.search(r"_([0-9A-Fa-f]{4})$", nm)
                    if nm.upper() in labels: v = start + labels[nm.upper()]
                    elif h: v = int(h[1], 16)
                    elif nm in autos or (r in brows and owner(nm) and others[owner(nm)][nm][0] == "XDATA"):
                        # LARGE-model local / parameter: 16-bit XDATA address = block base + offset (block rows: caller's)
                        ow = fn if nm in autos else owner(nm); key = f"?{ow}?XD"
                        if key not in libs:
                            if _pass == 0: continue
                            return f"LARGE local {nm}: block base unknown"
                        v = libs[key] + (autos[nm] if nm in autos else others[ow][nm][1])
                    else:
                        ow = owner(nm) if (r in brows and nm not in autos and owner(nm)) else fn   # block rows: caller's local
                        key = "data:" + nm if re.fullmatch(r"\?_?\w+\?BYTE", nm) else f"data:{ow}:{nm}"   # locals: per function
                        if key not in libs and "HIGH" in part.upper():
                            if _pass == 0: continue    # learn it from its LOW use first
                        if key not in libs and ps < len(target):
                            libs[key] = target[ps] - po; _libs_save(lib, libs)
                        v = libs.get(key, -1000)
                    v += po
                    code[ps] = ((v >> 8) if "HIGH" in part.upper() else v) & 0xFF
                continue
            names = [n for n in re.findall(r"[?A-Za-z_][\w?]*", re.sub(r"\+\s*(0x[0-9A-Fa-f]+|[0-9A-F]+H|\d+)", "", re.sub(r"\b[0-9][0-9A-Fa-f]*H\b", "", asm.split(None, 1)[1]) if " " in asm else "")) if n not in ("A", "DPTR", "LOW", "HIGH", "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "C")]
            if len(names) != 1: return f"cannot resolve operand of '{asm}'"
            nm = names[0]; h = re.search(r"_([0-9A-Fa-f]{4})$", nm)
            if nm.upper() in labels: v = start + labels[nm.upper()]
            elif nm.upper() == fn.upper(): v = start + fn_off
            elif h: v = int(h[1], 16)
            elif re.fullmatch(r"L\?\d+", nm) and len(op) == 3:   # Keil "reuse of common entry code" (OPTIMIZE >= 8):
                # parameter set-up shared by several calls is emitted as a block "FUNCTION L?nnnn" in front of the callee
                # it falls into; it sits right before that callee in the firmware, and its non-fixup bytes must agree
                v = common_entry(txt, nm, bank)
                if v is None:   # OPTIMIZE(9) common block subroutine (ends in RET, placed anywhere in the module): take
                    # the address the original calls and require the whole block to sit there in the firmware
                    v = common_block_at(txt, nm, bank, (target[off + 1] << 8) | target[off + 2]) if off + 2 < len(target) else None
                if v is None: return f"common block {nm}: not found or its bytes differ from the firmware"
            elif nm.startswith("?C?") and len(op) == 3:   # Keil run-time library routine: one fixed address per bank
                # first use in a bank records where the firmware has it (symbols/<bank>.libs.json); later uses must agree
                lib = ROOT / "symbols" / f"{bank}.libs.json"; libs = _libs_load(lib)
                if nm not in libs and off + 2 < len(target):
                    libs[nm] = (target[off + 1] << 8) | target[off + 2]; _libs_save(lib, libs)
                v = libs.get(nm, -1)
            elif re.fullmatch(r"\?_\w+\?BYTE", nm) and len(op) == 3:   # parameter block of a large/varargs function (e.g.
                # printf's ?_FUN_CODE_2820?BYTE in XDATA): the linker gave it one address; first use records it, later must agree
                pl = re.search(r"\+\s*(0x[0-9A-Fa-f]+|[0-9A-F]+H|\d+)", asm); po = 0
                if pl: po = int(pl[1][:-1], 16) if pl[1].endswith("H") else int(pl[1], 0)
                lib = ROOT / "symbols" / f"{bank}.libs.json"; libs = _libs_load(lib)
                if nm not in libs and off + 2 < len(target):
                    libs[nm] = ((target[off + 1] << 8) | target[off + 2]) - po; _libs_save(lib, libs)
                v = libs.get(nm, -1)
            elif len(op) == 3 and (nm in autos or (r in brows and owner(nm) and others[owner(nm)][nm][0] == "XDATA")):
                # LARGE-model parameter / local of this function (see autos above); in a common-entry block: of its caller
                ow = fn if nm in autos else owner(nm); ao = autos[nm] if nm in autos else others[ow][nm][1]
                pl = re.search(r"\+\s*(0x[0-9A-Fa-f]+|[0-9A-F]+H|\d+)", asm); po = 0
                if pl: po = int(pl[1][:-1], 16) if pl[1].endswith("H") else int(pl[1], 0)
                lib = ROOT / "symbols" / f"{bank}.libs.json"; libs = _libs_load(lib)
                key = f"?{ow}?XD"
                if key not in libs and off + 2 < len(target):
                    libs[key] = ((target[off + 1] << 8) | target[off + 2]) - po - ao; _libs_save(lib, libs)
                v = libs.get(key, -1) + ao
            else: return f"outside name '{nm}' is not a firmware address: use its Ghidra name (FUN_CODE_xxxx / DAT_EXTMEM_xxxx)"
            plus = re.search(r"\+\s*(0x[0-9A-Fa-f]+|[0-9A-F]+H|\d+)", asm)
            if plus:
                t = plus[1]; v += int(t[:-1], 16) if t.endswith("H") else int(t, 0)
            if "LOW" in asm.upper(): code[off + len(op) - 1] = v & 0xFF
            elif "HIGH" in asm.upper(): code[off + len(op) - 1] = (v >> 8) & 0xFF
            elif len(op) == 2 and op[0] & 0x1F in (0x01, 0x11):                  # AJMP/ACALL: 11-bit in-block address
                code[off] = (op[0] & 0x1F) | ((v >> 3) & 0xE0); code[off + 1] = v & 0xFF
            elif len(op) == 3: code[off + 1:off + 3] = bytes([(v >> 8) & 0xFF, v & 0xFF])   # LCALL/LJMP/MOV DPTR,#
            else: return f"operand form of '{asm}' not handled yet"
    if bytes(code) == target: return None
    k = next((n for n in range(min(len(code), len(target))) if code[n] != target[n]), min(len(code), len(target)))
    return f"linked at 0x{start:04x} the bytes differ at +{k}: compiled {bytes(code[k:k+3]).hex()} vs firmware {target[k:k+3].hex()}"

def judge(bank, fn, cfile, opts=None):
    """best over the configured option sets unless opts is given; result["opts"] says which"""
    if opts is None:
        best = None
        for o in [CFG["8051"]["c51opts"]] + CFG["8051"].get("alt_c51opts", []):
            r = judge(bank, fn, cfile, o); r["opts"] = o
            if best is None or (r.get("ok") and r.get("score", 0) > best.get("score", 0)): best = r
            if best.get("match"): break
        return best
    funcs = {f["name"]: f for f in funclist(bank)}
    if fn not in funcs:   # name dropped by a list repair (merged/cut): a stale candidate list, not a crash
        return {"ok": False, "error": f"{fn} is no longer in the function list of {bank}", "score": 0.0}
    f = funcs[fn]; start, end = f["start"], SPAN_END.get((bank, fn), f["end"])
    target = (ROOT / "parts" / f"{bank}.bin").read_bytes()[start:end]
    _clean_old_k51()
    tmp = pathlib.Path(tempfile.mkdtemp(prefix="k51_")); shutil.copy(cfile, tmp / "u.c")
    orc = ROOT / "symbols" / f"{bank}.orc"   # register-usage file rebuilt from the firmware (tools/regfile8051.py)
    if orc.exists(): shutil.copy(orc, tmp / "R.ORC")
    copts = opts or CFG["8051"]["c51opts"]
    if "LARGE" in copts.upper() and "SYMBOLS" not in copts.upper(): copts += " SYMBOLS"   # listing of local offsets
    log = c51(tmp, "u", copts)
    if not (tmp / "u.OBJ").exists():
        return {"ok": False, "error": log[-2000:], "score": 0.0}
    klines, b, fx = keil_listing(tmp / "u.LST", fn)
    if not b:
        return {"ok": False, "error": f"function {fn} not found in the compiled module\n" + log[-1500:], "score": 0.0}
    fstart, blk, why = start, None, None
    eb = entry_block((tmp / "u.LST").read_text(errors="replace"), fn)
    if eb:   # common-entry block in front of fn in its own segment: judge [block start .. end] at the block's address
        btxt, bl, bb, bfx = eb; bs = start - len(bb)
        if not any(x["start"] == bs or x["end"] == bs for x in funcs.values()):
            why = f"common-entry block start 0x{bs:04x} (fn - {len(bb)}) is not a function boundary in functions.json"
        blk = (bs, start); b = bb + b[len(bb):]; fx = fx | bfx; klines = bl + klines
        start = bs; target = (ROOT / "parts" / f"{bank}.bin").read_bytes()[start:end]
    n = max(len(b), len(target)); same = 0; marks = []
    for i in range(n):
        if i < len(b) and i < len(target) and (i in fx or b[i] == target[i]): same += 1; marks.append(" ")
        else: marks.append("*")
    match = len(b) == len(target) and same == n
    reason = exact8051(tmp / "u.LST", fn, start, b, target, bank, eb[0] if eb else None, fstart - start) if match and fx else None
    reason = why or reason
    if reason: match = False; same = min(same, n - 1)
    return {"ok": True, "match": match, "score": 100.0 * same / n, "len_target": len(target), "len_compiled": len(b),
            "span": (start, end), "block": blk,
            "fixups": sorted(fx), "keil": klines, "ghidra": ghidra_listing(bank, start, end),
            "target_hex": target.hex(), "compiled_hex": bytes(b).hex(), "marks": "".join(marks), "log": log[-1500:], "exact": reason}

def render(fn, r):
    if not r["ok"]: return f"{fn}: compile failed\n{r['error']}"
    w = 46
    lines = [f"{'TARGET (firmware)':<{w}} | COMPILED (Keil)"]
    for i in range(max(len(r["ghidra"]), len(r["keil"]))):
        l = r["ghidra"][i] if i < len(r["ghidra"]) else ""
        c = r["keil"][i] if i < len(r["keil"]) else ""
        lines.append(f"{l:<{w}} | {c}")
    lines.append(f"\nbytes target   : {r['target_hex']}\nbytes compiled : {r['compiled_hex']}\n"
                 f"differ at      : {''.join('^' if m == '*' else ' ' for m in r['marks'])}  (fixup bytes are ignored)")
    lines.append(f"\n{fn}: {r['len_compiled']} vs {r['len_target']} bytes, {r['score']:.1f}%  " + ("MATCH" if r["match"] else "no match"))
    return "\n".join(lines)

if __name__ == "__main__":
    bank, fn, cfile = sys.argv[1], sys.argv[2], sys.argv[3]
    r = judge(bank, fn, cfile)
    txt = render(fn, r)
    print(txt.splitlines()[-1] if "--quiet" in sys.argv else txt)
