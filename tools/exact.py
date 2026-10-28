"""Exact-bytes judge: link one compiled object at its function's real address and compare the bytes with the firmware.

diff.py compares instruction shapes with addresses masked; that let through wrong byte offsets, wrong constants,
reg+%g0 vs +0 encodings and invented outside names. diff.compare() calls exact() on every shape match, so every
tool (permute, permuter, verify, relink, ...) only calls a function matched when its bytes are the firmware's.
exact(cpu, fn, obj) -> None if exact, else a short reason (also usable as feedback for hand work).
"""
import functools, pathlib, re, subprocess, tempfile, threading
ROOT = pathlib.Path(__file__).resolve().parent.parent
BIN = ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-"
BASE = {"leon2s": 0xA0060000, "leon2m": 0xA0028000}


def run(*a):
    return subprocess.run([str(x) for x in a], capture_output=True, text=True)


def tool(name):
    return str(BIN) + name


@functools.lru_cache(None)
def part(cpu):
    return (ROOT / "parts" / f"{cpu}.bin").read_bytes()


@functools.lru_cache(None)
def funcs(cpu):
    """name -> (start, end) for every function of the core, from the disassembly headers."""
    m = {}
    for s in (ROOT / "asm" / cpu).glob("*.s"):
        h = re.match(r"# \S+ (\S+) 0x([0-9a-f]+)-0x([0-9a-f]+)", s.open().readline())
        if h: m[h[1]] = (int(h[2], 16), int(h[3], 16))
    return m


@functools.lru_cache(None)
def starts(cpu):
    return sorted(a for a, _ in funcs(cpu).values())


@functools.lru_cache(None)
def lib_syms(cpu):
    """toolchain library symbols matched in the firmware (src/<cpu>/<fn>.lib: '<archive> <member> <symbol>'),
    so compiler-generated calls such as __udivdi3 resolve to their real address"""
    out = {}
    for p in (ROOT / "src" / cpu).glob("*.lib"):
        f = p.read_text().split("\n", 1)[0].split()
        if len(f) == 3 and p.stem in funcs(cpu): out[f[2]] = funcs(cpu)[p.stem][0]
    return out


def addr_of(cpu, sym):
    if sym in funcs(cpu): return funcs(cpu)[sym][0]
    if sym in lib_syms(cpu): return lib_syms(cpu)[sym]
    h = re.fullmatch(r"_?(?:FUN|DAT|PTR|LAB|ARR|ext|func_0x|s|u)_?([0-9a-fA-F]{8})(?:_\w+)?", sym)
    return int(h[1], 16) if h else None


def solve_undefined(cpu, obj, text_lo):
    """Hypotheses for the object's undefined names, read back from the firmware words its relocations patch
    (call displacement, sethi/or halves, 32-bit words). The byte comparison afterwards validates them."""
    img, base = part(cpu), BASE[cpu]; bits = {}
    for o, typ, tgt in re.findall(r"^([0-9a-f]+)\s+R_SPARC_(\w+)\s+(\S+)", run(tool("objdump"), "-r", "-j", ".text", obj).stdout, re.M):
        name, _, add = tgt.partition("+")
        if name == ".text": continue
        at = text_lo + int(o, 16); p = at - base
        if p < 0 or p + 4 > len(img): continue
        w = int.from_bytes(img[p:p + 4], "big")
        if typ == "WDISP30": v, m = at + ((w & 0x3fffffff) - (0x40000000 if w & 0x20000000 else 0)) * 4, 0xffffffff
        elif typ == "HI22": v, m = (w & 0x3fffff) << 10, 0xfffffc00
        elif typ == "LO10": v, m = w & 0x3ff, 0x3ff
        elif typ == "32": v, m = w, 0xffffffff
        else: continue
        k = (name, int(add, 16) if add else 0); ov, om = bits.get(k, (0, 0))
        bits[k] = (ov | (v & m & ~om), om | m)
    out = {}
    for (name, add), (v, m) in sorted(bits.items(), key=lambda kv: -bin(kv[1][1]).count("1")):
        out.setdefault(name, (v - add) & 0xffffffff)   # partial masks: the low bits are a guess the bytes will check
    return out


LAST = (b"", b"")
RUNTIME = {"leon2m": 0xA0060000}
LINK_SHIFTS = {"leon2s": [0xF10000]}   # leon2s code linked 0xF10000 above where it is loaded (jump tables)   # leon2m code runs 0xA0060000 below the listing addresses (jump-table words prove it)
# except the boot piece, the RAM copy of flash 0xD0000 that runs AT its listing address
# 0xA0028000..0xA002FB43 (FUN_CODE_0b0d copies 0x7B44 bytes; reset jmp 0xA0029000 is absolute)
BOOT_PIECE = {"leon2m": (0xA0028000, 0xA002FB44)}
def shift(cpu, addr):
    lo, hi = BOOT_PIECE.get(cpu, (0, 0))
    return 0 if lo <= addr < hi else RUNTIME[cpu]


def jump_tables(cpu, obj, off, got, want, text_lo, found=None):
    """gcc 3.4 here puts a switch's jump table in .text in front of the function; the firmware keeps its tables
    elsewhere. Exact proof without moving the table: (1) every byte equals the firmware except the sethi/or
    immediates that hold the table address, (2) those immediates in the firmware name one table address T, and
    (3) the firmware table at T holds, entry for entry, the built table's targets at their run-time addresses.
    Returns None when proven, '' when the object has no jump table, else a reason. found: a list that receives,
    when proven, each table's firmware address and its entries (tools/acctable.py records the tables as matched).
    leon2s: part of the program was linked 0xF10000 above its load address (docs/STATUS.md); its tables hold
    addresses of that link, so the shift 0xF10000 is also tried there, under the same entry-for-entry proof."""
    if cpu not in RUNTIME and cpu not in LINK_SHIFTS: return ""
    rel = [(int(o, 16), ty, int(t or "0", 16)) for o, ty, t in re.findall(
        r"^([0-9a-f]+)\s+R_SPARC_(\w+)\s+\.text(?:\+0x([0-9a-f]+))?\s*$", run(tool("objdump"), "-r", "-j", ".text", obj).stdout, re.M)]
    table = sorted((o, t) for o, ty, t in rel if ty == "32" and o < off)
    refs = [(o - off, ty, t) for o, ty, t in rel if ty in ("HI22", "LO10") and o >= off and t < off]
    if not table or not refs: return ""
    g, w = bytearray(got), bytearray(want); addr = {}
    for p, ty, k in refs:
        if p + 4 > len(w): return "jump table reference outside the function"
        fw = int.from_bytes(w[p:p + 4], "big"); mask = 0x3fffff if ty == "HI22" else 0x3ff
        hi_, lo_ = addr.get(k, (None, None))
        addr[k] = ((fw & mask) << 10, lo_) if ty == "HI22" else (hi_, fw & mask)
        for b in (g, w):
            v = int.from_bytes(b[p:p + 4], "big") & ~mask; b[p:p + 4] = v.to_bytes(4, "big")
    if g != w: return "bytes differ outside the jump-table address"
    base = BASE[cpu]; img = part(cpu)
    why = None
    for sh in ([shift(cpu, text_lo)] if cpu in RUNTIME else LINK_SHIFTS[cpu]):
        why = None; tabs = []
        for k, (hi_, lo_) in addr.items():
            if hi_ is None or lo_ is None: return "jump table address not built by a sethi/or pair"
            t = hi_ | lo_
            nxt = min([kk for kk in addr if kk > k] + [off]); ents = [x for o, x in table if k <= o < nxt]
            at = t + sh - base
            if at < 0 or at + 4 * len(ents) > len(img): why = f"jump table at 0x{t:x} is outside the image"; break
            bad = [i for i, x in enumerate(ents)
                   if int.from_bytes(img[at + 4 * i:at + 4 * i + 4], "big") != (text_lo + x - sh) & 0xffffffff]
            if bad: why = f"jump table entry {bad[0]} at 0x{t + 4 * bad[0]:x} differs"; break
            tabs.append((at + base, [(text_lo + x - sh) & 0xffffffff for x in ents]))
        if why is None: break
    if why: return why
    if found is not None: found.extend(tabs)
    return None


def linked_tables(cpu, obj, off, text, text_lo):
    """Jump tables the link placed in front of the function at the firmware's own table address (gcc 3.4 puts a
    switch's table in .text before its function; where the firmware has it there too, the link reproduces it): the
    runs of R_SPARC_32 words before the function whose linked values equal the firmware words at that address.
    Returns [(firmware address, [entry values])] for runs that equal the firmware entirely."""
    words = sorted(int(o, 16) for o in re.findall(r"^([0-9a-f]+)\s+R_SPARC_32\s+\.text(?:\+0x[0-9a-f]+)?\s*$",
                   run(tool("objdump"), "-r", "-j", ".text", obj).stdout, re.M) if int(o, 16) < off)
    runs = []
    for o in words:
        if runs and runs[-1][-1] + 4 == o: runs[-1].append(o)
        else: runs.append([o])
    base = BASE[cpu]; img = part(cpu); out = []
    for r in runs:
        vals = [int.from_bytes(text[o:o + 4], "big") for o in r]
        at = text_lo + r[0] - base
        if at < 0 or at + 4 * len(r) > len(img): continue
        if all(int.from_bytes(img[at + 4 * i:at + 4 * i + 4], "big") == v for i, v in enumerate(vals)):
            out.append((text_lo + r[0], vals))
    return out


def code_addresses(cpu, obj, elf, off, got, want, text_lo):
    """Library members that take the address of one of their own functions (sethi/or of a name defined in their
    .text, e.g. fflush passing itself to _fwalk): the firmware holds the run-time address, the link gives the listing
    address. Each such field is taken from the firmware when it equals the linked address minus the run-time shift."""
    if cpu not in RUNTIME: return got
    sh = shift(cpu, text_lo)
    own = {n: int(v, 16) for v, t, n in re.findall(r"^([0-9a-f]+) ([Tt]) (\S+)$", run(tool("nm"), elf).stdout, re.M)}
    g = bytearray(got)
    for o, ty, name, add in re.findall(r"^([0-9a-f]+)\s+R_SPARC_(HI22|LO10)\s+([^\s+.][^\s+]*)(?:\+0x([0-9a-f]+))?\s*$",
                                       run(tool("objdump"), "-r", "-j", ".text", obj).stdout, re.M):
        if name not in own: continue
        p = int(o, 16) - off
        if not 0 <= p < len(g) - 3: continue
        a = (own[name] + int(add or "0", 16) - sh) & 0xffffffff
        mask, val = (0x3fffff, a >> 10) if ty == "HI22" else (0x3ff, a & 0x3ff)
        fw = int.from_bytes(want[p:p + 4], "big"); cw = int.from_bytes(g[p:p + 4], "big")
        if fw & ~mask == cw & ~mask and fw & mask == val: g[p:p + 4] = want[p:p + 4]
    return bytes(g)


def verify_pool(obj, off, size, got, want, pools, img, base):
    """Literal-pool references (R_SPARC_HI22 / LO10 against .rodata.cstN): accept the firmware's address bits when the
    firmware holds the same constant at that address; returns (got with those fields taken from want, reason or None)."""
    secs = {sec: (n, data) for sec, n, data in pools}
    rel = run(tool("readelf"), "-rW", obj).stdout
    sect = None; refs = {}
    for ln in rel.splitlines():
        h = re.search(r"Relocation section '\.rela?(\S+)'", ln)
        if h: sect = h[1]; continue
        r = re.search(r"([0-9a-f]{8})\s+[0-9a-f]{8}\s+(R_SPARC_\w+)\s+[0-9a-f]+\s+\+?(\S+)\s*\+\s*([0-9a-f]+)", ln)
        if not r or sect != ".text" or r[3] not in secs: continue
        pos = int(r[1], 16) - off
        if not 0 <= pos < size: continue
        refs.setdefault((r[3], int(r[4], 16)), []).append((pos, r[2]))
    g = bytearray(got)
    for (sec, add), sites in refs.items():
        n, data = secs[sec]; hi = lo = None
        for pos, typ in sites:
            fw = int.from_bytes(want[pos:pos + 4], "big"); cw = int.from_bytes(got[pos:pos + 4], "big")
            if typ == "R_SPARC_HI22":
                if fw & 0xFFC00000 != cw & 0xFFC00000: return got, f"literal reference at +{pos} has another instruction"
                hi = (fw & 0x3FFFFF) << 10
            elif typ in ("R_SPARC_LO10", "R_SPARC_13"):
                if fw & ~0x1FFF != cw & ~0x1FFF: return got, f"literal reference at +{pos} has another instruction"
                lo = fw & 0x3FF
            else: return got, f"literal reference at +{pos} uses {typ}"
            g[pos:pos + 4] = want[pos:pos + 4]
        if hi is None or lo is None: return got, f"literal {sec}+{add} is not loaded with a sethi/%lo pair"
        a = hi | lo
        val = (data[add:add + n] if n > 0 else data[add:data.index(b"\0", add) + 1] if n < 0
               else data[add:].rstrip(b"\0"))   # n == 0: plain .rodata placed by its references; n < 0: one string
        fw_img = (pathlib.Path(__file__).resolve().parent.parent / "firmware" / "MSI_MPG321URX_V021_7F69.bin").read_bytes()
        # file offsets: Leon2M code addresses its constants at run-time addresses (file = address + 0x108000, the
        # documented string rule); Leon2S at flash addresses (file = address - 0xA0010000)
        fo = a + 0x108000 if a < 0x200000 else a - 0xA0010000
        if fw_img[fo:fo + len(val)] != val:
            return got, f"literal {sec}+{add} ({val.hex()}) is not at the firmware address 0x{hi | lo:x}"
    return bytes(g), None


class _ThreadTables(threading.local):
    """per thread, so a check running in parallel for the same function cannot clear another thread's result"""
    def __init__(self): self.v = {}
    def pop(self, k, d=None): return self.v.pop(k, d)
    def get(self, k, d=None): return self.v.get(k, d)
    def __setitem__(self, k, x): self.v[k] = x
    def __contains__(self, k): return k in self.v


TABLES = _ThreadTables()   # (cpu, fn) -> [(firmware address, [entry values])] of the jump tables proven by the last exact check


def exact(cpu, fn, obj, sym=None, solve=False, split_pools=False, placed=None):
    """None when the object gives the firmware's exact bytes for fn at its real address, else a reason.
    sym: the function's name inside the object when it differs (library members); solve: derive the addresses
    of undefined names from the firmware instead of requiring Ghidra names (library members only).
    placed: a dict that receives the linked bytes for tools/rebuild.py: "lo" (address), "raw" (the bytes as linked,
    from the last link tried) and, when exact, "final" (raw with the address fields this judge proved taken from the
    firmware: jump-table and literal-pool addresses, a library member's own code addresses)."""
    if cpu not in BASE: return None
    TABLES.pop((cpu, fn), None)
    if fn not in funcs(cpu): return f"{fn} has no disassembly header"
    lo, hi = funcs(cpu)[fn]; base = BASE[cpu]; img = part(cpu); sym = sym or fn
    m = re.search(r"^([0-9a-f]+)(?: ([0-9a-f]+))? [Tt] " + re.escape(sym) + "$", run(tool("nm"), "-S", obj).stdout, re.M)
    if not m: return f"{sym} not found in the object"
    off = int(m[1], 16); text_lo = lo - off   # the function need not be first in its object's .text
    size = int(m[2], 16) if m[2] else hi - lo   # no size recorded (hand-written members): Ghidra's length
    solved = solve_undefined(cpu, obj, text_lo) if solve else {}
    if solve:   # library member: a section is also placed by the names it defines that the relocations reach
        secs = dict(re.findall(r"^\s*\[\s*(\d+)\]\s+(\S+)", run(tool("readelf"), "-SW", obj).stdout, re.M))
        at = {}
        for val, ndx, name in re.findall(r"^\s*\d+:\s+([0-9a-f]+)\s+\d+\s+\w+\s+\w+\s+\w+\s+(\d+)\s+(\S+)\s*$",
                                         run(tool("readelf"), "-sW", obj).stdout, re.M):
            sec = secs.get(ndx)
            if sec and sec != ".text" and name in solved: at.setdefault(sec, set()).add(solved[name] - int(val, 16))
        for sec, a in at.items():
            if len(a) > 1: return f"the names defined in {sec} give different firmware addresses for it"
            solved.setdefault(sec, a.pop())
    defs = []
    for name in run(tool("nm"), "-u", obj).stdout.split():
        if name == "U": continue
        a = solved.get(name)
        if a is None: a = addr_of(cpu, name)
        if a is None:
            return (f"outside name '{name}' is not a firmware address: declare it by its Ghidra name "
                    f"(FUN_xxxxxxxx / DAT_xxxxxxxx) so the real address is used")
        defs += ["--defsym", f"{name}=0x{a:x}"]
    with tempfile.TemporaryDirectory() as td:
        td = pathlib.Path(td)
        place = []; pools = []; merged = False
        for sec, ssz in re.findall(r"\]\s+(\.\S+)\s+\w+\s+\w+\s+\w+\s+(\w+)\s+\w+\s+\S*A", run(tool("readelf"), "-SW", obj).stdout):
            if sec == ".text" or int(ssz, 16) == 0: continue
            merge = re.match(r"\.rodata\.(cst|str)", sec); merged = merged or bool(merge)
            if sec in solved and not (split_pools and merge):   # library member: its relocations say where the
                # firmware keeps this section (second try: mergeable constants and strings checked per reference)
                place.append((sec, [solved[sec] - base])); continue
            if not sec.startswith(".rodata"):
                return f"defines its own variables ({sec}); use the firmware's globals (extern DAT_xxxxxxxx) instead"
            b = td / "sec.bin"; run(tool("objcopy"), "-O", "binary", "-j", sec, obj, b)
            mc = re.match(r"\.rodata\.cst(4|8|16)$", sec)
            # the section's alignment padding is not in the firmware; but a mergeable cstN pool has fixed-size entries
            # whose trailing zero bytes are data (stripping them cut the double 0.5 = 3fe00000 00000000 to 3fe0 00,
            # which then matched at a wrong place, e.g. in FUN_a0120c90)
            data = b.read_bytes() if mc else b.read_bytes().rstrip(b"\0") + b"\0"
            hits = [] if split_pools and merge else [m.start() for m in re.finditer(re.escape(data), img)][:4]
            if not hits and not merge and sec == ".rodata":   # plain .rodata (e.g. the initialiser of a local array) is
                # not a string: the firmware need not have a 0 after it; try the section exactly as compiled
                data = b.read_bytes()
                hits = [m.start() for m in re.finditer(re.escape(data), img)][:4]
            if not hits and mc:   # a mergeable literal pool; the original link merged each entry with other
                # objects' constants, so its entries need not be adjacent: place it outside the image and check every
                # literal reference against the firmware's own address bits (verify_pool below)
                pools.append((sec, int(mc[1]), b.read_bytes())); place.append((sec, [len(img) + 0x10000 + 0x1000 * len(pools)])); continue   # own slot per pool, so two pools never overlap
            if not hits and (cpu == "leon2m" or (split_pools and merge)):   # leon2s: only on the per-reference retry,
                # for a string or constant pool whose entries the original link merged with another file's identical
                # literals (the same text written in two source files, one copy in the firmware)
                # leon2m: a unit's .rodata/.rodata.str* in the Big chip DATA area (file =
                # address + 0x108000, outside parts/leon2m.bin): place it outside the image and check every literal reference
                # against the firmware bytes at its own address bits (verify_pool, n = 0 = rest of the section)
                # (n = -1: a mergeable string section, each string checked on its own)
                pools.append((sec, -1 if split_pools and merge else 0, b.read_bytes()))
                place.append((sec, [len(img) + 0x10000 + 0x1000 * len(pools)])); continue
            if not hits and merge and not split_pools:   # merged pool not found in one piece: check it per reference
                return exact(cpu, fn, obj, sym, solve, True, placed)
            if not hits: return f"its constant data/strings ({len(data)} bytes) are not in the firmware in this order"
            place.append((sec, hits))

        def tries(i=0, cur=()):
            if i == len(place): yield cur; return
            for h in place[i][1]: yield from tries(i + 1, cur + (f"  {place[i][0]} 0x{base + h:x} : {{ *({place[i][0]}) }}",))
        last = "link failed"
        for t in tries():
            ld, elf, out = td / "x.ld", td / "x.elf", td / "x.bin"
            ld.write_text("SECTIONS {\n" + f"  .text 0x{text_lo:x} : {{ *(.text) }}\n" + "\n".join(t) + "\n}\n")   # no constructor tables
            r = run(tool("ld"), "-N", "-e", "0", "-T", ld, *defs, obj, "-o", elf)
            if r.returncode: last = "link failed: " + (r.stderr.strip().splitlines() or [""])[-1][:120]; continue
            sz = re.search(r"^([0-9a-f]+)(?: [0-9a-f]+)? [Tt] " + re.escape(sym) + "$", run(tool("nm"), "-S", elf).stdout, re.M)
            if not sz or int(sz[1], 16) != lo: last = f"{fn} not placed at 0x{lo:x}"; continue
            run(tool("objcopy"), "-O", "binary", "-j", ".text", elf, out)
            got = out.read_bytes()[off:off + size]
            if placed is not None: placed.clear(); placed.update(lo=lo, raw=bytes(got))
            nxt = next((a for a in starts(cpu) if a > lo), base + len(img))
            want = img[lo - base:lo - base + len(got)]   # Ghidra often ends a function early: the bytes decide
            global LAST; LAST = (bytes(got), bytes(want))   # for byte-similarity reports (tools/bytesim)
            if got != want and len(got) == len(want) and pools:
                got, why = verify_pool(obj, off, size, got, want, pools, img, base)
                if why: last = why; continue
                LAST = (bytes(got), bytes(want))
            if got != want and len(got) == len(want) and solve:
                got = code_addresses(cpu, obj, elf, off, got, want, text_lo)
            if got != want and len(got) == len(want):
                tabs = []
                why = jump_tables(cpu, obj, off, got, want, text_lo, tabs)
                if why is None: got = want; TABLES[(cpu, fn)] = tabs
                elif why: last = why; continue
            if got == want and lo + len(got) <= max(nxt, hi):
                if (cpu, fn) not in TABLES and off:
                    TABLES[(cpu, fn)] = linked_tables(cpu, obj, off, out.read_bytes(), text_lo)
                if placed is not None: placed["final"] = bytes(got); placed["tables"] = TABLES.get((cpu, fn), [])
                return None
            if got == want: last = f"runs into the next function at 0x{nxt:x}"; continue
            k = next(i for i in range(min(len(got), len(want))) if got[i] != want[i]) & ~3
            last = (f"bytes differ at 0x{lo + k:x}: compiled {got[k:k+4].hex()} vs firmware {want[k:k+4].hex()} "
                    f"(same instruction shape: check the exact address/offset/constant there)")
        if not split_pools and (merged or any(re.match(r"\.rodata\.(cst|str)", s_) for s_ in solved)):
            # the original link may have spread the literal pool among other objects' constants, or the pool's bytes
            # also occur by chance elsewhere in the image: check every literal reference at its own address instead
            return exact(cpu, fn, obj, sym, solve, True, placed) and last
        return last
