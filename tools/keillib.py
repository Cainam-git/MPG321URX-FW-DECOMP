#!/usr/bin/env python3
"""Keil C51 run-time library routines inside the helper chip (8051): identified from the toolchain's own .LIB
files, so they need no decompiling. Keil's OMF51 variant: 0x02 module header, 0x07 content [blk, seg, off16,
data], 0x09 fixups (8-byte entries: refloc16, type, blk, id16, off16), 0x17 public names [blk, seg, info, off16, 0,
name], 0x0F segment definitions. Fixup bytes are wildcards; a segment whose remaining bytes appear in a bank
names every public routine inside it. Import: src/<bank>/<fn>.lib = "<LIB> <module> <symbol>", status matched.
A piece of a segment that Ghidra split off at an internal entry point is filed the same way with symbol "@<seg>+<offset>".
usage: keillib.py [--dry]          check(bank, fn, lib, module, symbol) is used by verify.py
"""
import functools, json, pathlib, re, struct, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
LIBDIR = ROOT / "toolchains/keil-prefix/drive_c/Keil_v5/C51/LIB"
BANKS = ("8051_bank0", "8051_bank1", "8051_bank2")


@functools.lru_cache(None)
def modules(lib):
    d = (LIBDIR / lib).read_bytes(); i = 0; mods = []; cur = None; last = None
    while i + 3 <= len(d):
        t = d[i]; ln = struct.unpack_from("<H", d, i + 1)[0]; body = d[i + 3:i + 3 + ln - 1]; i += 3 + ln
        if t == 0x02: cur = {"name": body[1:1 + body[0]].decode("latin1"), "segs": {}, "fix": set(), "pub": []}; mods.append(cur); last = None
        elif cur is None: continue
        elif t == 0x07:
            sid = body[1]; off = struct.unpack_from("<H", body, 2)[0]; data = body[4:]; seg = cur["segs"].setdefault(sid, bytearray())
            if len(seg) < off + len(data): seg.extend(b"\0" * (off + len(data) - len(seg)))
            seg[off:off + len(data)] = data; last = (sid, off)
        elif t == 0x09 and last:
            for j in range(0, len(body) - 7, 8):
                refloc, typ = struct.unpack_from("<HB", body, j)
                for k in range(2 if typ in (4, 5) else 1): cur["fix"].add((last[0], last[1] + refloc + k))
        elif t == 0x17:
            j = 0
            while j + 7 <= len(body):
                sid = body[j + 1]; off = struct.unpack_from("<H", body, j + 3)[0]; nl = body[j + 6]
                nm = body[j + 7:j + 7 + nl].decode("latin1"); j += 7 + nl
                if nm: cur["pub"].append((sid, off, nm))
    return mods


def pattern(m, sid):
    code = m["segs"][sid]; plain = sum(1 for k in range(len(code)) if (sid, k) not in m["fix"])
    if len(code) < 8 or plain < 8 or plain < 0.6 * len(code): return None
    return b"".join(b"." if (sid, k) in m["fix"] else re.escape(bytes([c])) for k, c in enumerate(code))


@functools.lru_cache(None)
def bank(b): return (ROOT / "parts" / f"{b}.bin").read_bytes()


def segment(b, fn, lib, module, symbol):
    """(module record, segment id, segment start address in the bank) for fn's library entry, else a reason"""
    fs = {f["name"]: f for f in json.loads((ROOT / "symbols" / f"{b}.functions.json").read_text())["functions"]}
    if fn not in fs: return f"{fn} not in the function list"
    for m in modules(lib):
        if m["name"] != module: continue
        if symbol.startswith("@"):   # a piece inside a library segment (internal entry point Ghidra split off): "@<seg>+<offset>"
            sid, off = map(int, symbol[1:].split("+"))
            if fs[fn]["end"] - (fs[fn]["start"] - off) > len(m["segs"][sid]): return f"{fn} reaches past the end of {module}"
            return m, sid, fs[fn]["start"] - off
        for sid, off, nm in m["pub"]:
            if nm == symbol: return m, sid, fs[fn]["start"] - off
        return f"{symbol} not public in {module}"
    return f"module {module} not in {lib}"


def check(b, fn, lib, module, symbol):
    """None when the library routine's masked bytes sit at fn's address in the bank, else a reason."""
    seg = segment(b, fn, lib, module, symbol)
    if isinstance(seg, str): return seg
    m, sid, start = seg; pat = pattern(m, sid)
    if not pat: return "segment too short to identify"
    if start >= 0 and re.match(pat, bank(b)[start:], re.S): return None
    return f"{module} bytes not around 0x{start:04x}" if symbol.startswith("@") else f"{symbol} bytes not at 0x{start:04x}"


def scan():
    starts = {b: {f["start"]: f["name"] for f in json.loads((ROOT / "symbols" / f"{b}.functions.json").read_text())["functions"]} for b in BANKS}
    ends = {b: json.loads((ROOT / "symbols" / f"{b}.functions.json").read_text())["functions"] for b in BANKS}
    found = {}; inner = []
    for lib in sorted(p.name for p in LIBDIR.glob("C51*.LIB")):
        for m in modules(lib):
            for sid in m["segs"]:
                pat = pattern(m, sid)
                if not pat: continue
                for b in BANKS:
                    for mm in re.finditer(pat, bank(b), re.S):
                        for s2, off, nm in m["pub"]:
                            fn = starts[b].get(mm.start() + off) if s2 == sid else None
                            if fn: found.setdefault((b, fn), (lib, m["name"], nm, len(m["segs"][sid])))
                        inner.append((b, mm.start(), mm.end(), lib, m["name"], sid))
    # pieces of a library segment that are not at a public name: Ghidra split an internal entry point off as its own
    # function (38 in the three banks). Kept only when the piece lies wholly inside the matched segment.
    for b, s0, e0, lib, mod, sid in inner:
        for f in ends[b]:
            if s0 < f["start"] and f["end"] <= e0: found.setdefault((b, f["name"]), (lib, mod, f"@{sid}+{f['start'] - s0}", e0 - s0))
    return found


def main():
    dry = "--dry" in sys.argv; found = scan(); done = 0; rows = []
    for b in BANKS:
        sp = ROOT / "symbols" / f"{b}.json"; sym = json.loads(sp.read_text())
        fs = {f["name"]: f for f in json.loads((ROOT / "symbols" / f"{b}.functions.json").read_text())["functions"]}
        for (b2, fn), (lib, module, symbol, size) in sorted(found.items()):
            if b2 != b: continue
            key = f"CODE:{fs[fn]['start']:04x}"
            if sym["functions"].get(key, {}).get("status") == "matched": continue
            rows.append((b, fn, symbol, lib, module)); done += 1
            if dry: continue
            what = (f"piece of Keil C51 library routine {module} (internal entry point, segment {symbol[1:]})" if symbol.startswith("@")
                    else f"Keil C51 run-time library routine {symbol}")
            (ROOT / "src" / b / f"{fn}.lib").write_text(f"{lib} {module} {symbol}\n# {b} {fn}: {what} ({lib}:{module}); "
                                                         f"linked from the library, nothing to decompile.\n")
            sym["functions"][key] = {"name": fn, "status": "matched", "by": "keil-lib", "lib": f"{lib}:{module}", "symbol": symbol,
                                     "comment": f"{what} ({lib}:{module})"}
        if not dry: sp.write_text(json.dumps(sym, indent=2, sort_keys=True))
    print(f"8051: {done} library routines {'would be ' if dry else ''}imported")
    for r in rows: print("  ", *r)


if __name__ == "__main__": main()
