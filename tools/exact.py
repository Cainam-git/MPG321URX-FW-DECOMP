"""Exact-bytes judge: link one compiled object at its function's real address and compare the bytes with the firmware.

diff.py compares instruction shapes with addresses masked; that let through wrong byte offsets, wrong constants,
reg+%g0 vs +0 encodings and invented outside names. diff.compare() calls exact() on every shape match, so every
tool (permute, permuter, verify, relink, ...) only calls a function matched when its bytes are the firmware's.
exact(cpu, fn, obj) -> None if exact, else a short reason (also usable as feedback for hand work).
"""
import functools, pathlib, re, subprocess, tempfile
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
RUNTIME = {"leon2m": 0xA0060000}   # leon2m code runs 0xA0060000 below the listing addresses (jump-table words prove it)
# except the boot piece, the RAM copy of flash 0xD0000 that runs AT its listing address
# 0xA0028000..0xA002FB43 (FUN_CODE_0b0d copies 0x7B44 bytes; reset jmp 0xA0029000 is absolute)
BOOT_PIECE = {"leon2m": (0xA0028000, 0xA002FB44)}
def shift(cpu, addr):
    lo, hi = BOOT_PIECE.get(cpu, (0, 0))
    return 0 if lo <= addr < hi else RUNTIME[cpu]


def jump_tables(cpu, obj, off, got, want, text_lo):
    """gcc 3.4 here puts a switch's jump table in .text in front of the function; the firmware keeps its tables
    elsewhere. Exact proof without moving the table: (1) every byte equals the firmware except the sethi/or
    immediates that hold the table address, (2) those immediates in the firmware name one table address T, and
    (3) the firmware table at T holds, entry for entry, the built table's targets at their run-time addresses.
    Returns None when proven, '' when the object has no jump table, else a reason."""
    if cpu not in RUNTIME: return ""
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
    for k, (hi_, lo_) in addr.items():
        if hi_ is None or lo_ is None: return "jump table address not built by a sethi/or pair"
        t = hi_ | lo_
        nxt = min([kk for kk in addr if kk > k] + [off]); ents = [x for o, x in table if k <= o < nxt]
        sh = shift(cpu, text_lo)
        at = t + sh - base
        if at < 0 or at + 4 * len(ents) > len(img): return f"jump table at 0x{t:x} is outside the image"
        for i, x in enumerate(ents):
            if int.from_bytes(img[at + 4 * i:at + 4 * i + 4], "big") != (text_lo + x - sh) & 0xffffffff:
                return f"jump table entry {i} at 0x{t + 4 * i:x} differs"
    return None


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


def exact(cpu, fn, obj, sym=None, solve=False, split_pools=False):
    """None when the object gives the firmware's exact bytes for fn at its real address, else a reason.
    sym: the function's name inside the object when it differs (library members); solve: derive the addresses
    of undefined names from the firmware instead of requiring Ghidra names (library members only)."""
    if cpu not in BASE: return None
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
        place = []; pools = []
        for sec, ssz in re.findall(r"\]\s+(\.\S+)\s+\w+\s+\w+\s+\w+\s+(\w+)\s+\w+\s+\S*A", run(tool("readelf"), "-SW", obj).stdout):
            if sec == ".text" or int(ssz, 16) == 0: continue
            merge = re.match(r"\.rodata\.(cst|str)", sec)
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
            if not hits and mc:   # a mergeable literal pool; the original link merged each entry with other
                # objects' constants, so its entries need not be adjacent: place it outside the image and check every
                # literal reference against the firmware's own address bits (verify_pool below)
                pools.append((sec, int(mc[1]), b.read_bytes())); place.append((sec, [len(img) + 0x10000 + 0x1000 * len(pools)])); continue   # own slot per pool, so two pools never overlap
            if not hits and cpu == "leon2m":   # a unit's .rodata/.rodata.str* in the Big chip DATA area (file =
                # address + 0x108000, outside parts/leon2m.bin): place it outside the image and check every literal reference
                # against the firmware bytes at its own address bits (verify_pool, n = 0 = rest of the section)
                # (n = -1: a mergeable string section, each string checked on its own)
                pools.append((sec, -1 if split_pools and merge else 0, b.read_bytes()))
                place.append((sec, [len(img) + 0x10000 + 0x1000 * len(pools)])); continue
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
            nxt = next((a for a in starts(cpu) if a > lo), base + len(img))
            want = img[lo - base:lo - base + len(got)]   # Ghidra often ends a function early: the bytes decide
            global LAST; LAST = (bytes(got), bytes(want))   # for byte-similarity reports (tools/bytesim)
            if got != want and len(got) == len(want) and pools:
                got, why = verify_pool(obj, off, size, got, want, pools, img, base)
                if why: last = why; continue
                LAST = (bytes(got), bytes(want))
            if got != want and len(got) == len(want):
                why = jump_tables(cpu, obj, off, got, want, text_lo)
                if why is None: got = want
                elif why: last = why; continue
            if got == want and lo + len(got) <= max(nxt, hi): return None
            if got == want: last = f"runs into the next function at 0x{nxt:x}"; continue
            k = next(i for i in range(min(len(got), len(want))) if got[i] != want[i]) & ~3
            last = (f"bytes differ at 0x{lo + k:x}: compiled {got[k:k+4].hex()} vs firmware {want[k:k+4].hex()} "
                    f"(same instruction shape: check the exact address/offset/constant there)")
        if solve and not split_pools and any(re.match(r"\.rodata\.(cst|str)", s_) for s_ in solved):
            # the original link may have spread a member's literal pool among other objects' constants
            return exact(cpu, fn, obj, sym, solve, True) and last
        return last
