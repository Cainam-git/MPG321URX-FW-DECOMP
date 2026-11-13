#!/usr/bin/env python3
"""Find toolchain library functions (libc, libm, libgcc, BCC runtime) inside the LEON images.

Each library function's code is taken from the toolchain's own .a archives; words the
linker fills in (relocations) become wildcards. A function whose masked bytes appear in
the image is the library function itself and needs no decompiling.

usage: libmatch.py <cpu> [--min-bytes N]      writes symbols/<cpu>.libmatch.json
"""
import json, re, subprocess, sys, pathlib, argparse

ROOT = pathlib.Path(__file__).resolve().parent.parent
TC = ROOT / "toolchains" / "sparc-elf-3.4.4"
BASE = {"leon2s": 0xA0060000, "leon2m": 0xA0028000}

def lib_functions(archive):
    """yield (archive member, symbol, [(word bytes, masked?)])"""
    out = subprocess.run([str(TC / "bin" / "sparc-elf-objdump"), "-d", "-r", str(archive)],
                         capture_output=True, text=True).stdout
    member = sym = None; words = []; relocs = set()
    def flush():
        if sym and words:
            yield_list.append((member, sym, [(w, a in relocs) for a, w in words]))
    yield_list = []
    for line in out.splitlines():
        m = re.match(r"^(\S+\.o):\s+file format", line)
        if m: flush(); member = m.group(1); sym = None; words = []; relocs = set(); continue
        m = re.match(r"^([0-9a-f]+) <([^>]+)>:$", line)
        if m: flush(); sym = m.group(2); words = []; relocs = set(); continue
        m = re.match(r"^\s+([0-9a-f]+):\s+((?:[0-9a-f]{2} ){4})", line)
        if m and sym: words.append((int(m.group(1), 16), bytes.fromhex(m.group(2).replace(" ", "")))); continue
        m = re.match(r"^\s+([0-9a-f]+): R_SPARC", line)
        if m: relocs.add(int(m.group(1), 16))
    flush()
    return yield_list

def main():
    ap = argparse.ArgumentParser(); ap.add_argument("cpu"); ap.add_argument("--min-bytes", type=int, default=24)
    a = ap.parse_args()
    img = (ROOT / "parts" / f"{a.cpu}.bin").read_bytes(); base = BASE[a.cpu]
    funcs = json.loads((ROOT / "symbols" / f"{a.cpu}.functions.json").read_text())["functions"]
    starts = {f["start"]: f for f in funcs}
    hits = {}
    arcs = (sorted((TC / "sparc-elf" / "lib" / "v8").glob("*.a")) + sorted(TC.glob("lib/gcc/sparc-elf/*/v8/*.a"))
            + sorted((TC / "sparc-elf" / "lib").glob("*.a")) + sorted(TC.glob("lib/gcc/sparc-elf/*/*.a"))      # default multilib
            + sorted((TC / "sparc-elf" / "lib" / "soft").glob("*.a")) + sorted(TC.glob("lib/gcc/sparc-elf/*/soft/*.a")))   # soft-float
    for arc in arcs:
        for member, sym, words in lib_functions(arc):
            if len(words) * 4 < a.min_bytes or sum(m for _, m in words) > len(words) // 2: continue
            pat = re.compile(b"".join(b"...." if m else re.escape(w) for w, m in words), re.S)
            for mt in pat.finditer(img):
                if mt.start() % 4: continue
                addr = base + mt.start()
                hits.setdefault(addr, []).append({"lib": f"{arc.name}:{member}", "name": sym, "size": len(words) * 4})
    res = {f"ram:{addr:08x}": {"candidates": v, "ghidra": starts[addr]["name"] if addr in starts else None,
                               "ghidra_size": starts[addr]["size"] if addr in starts else None}
           for addr, v in sorted(hits.items())}
    (ROOT / "symbols" / f"{a.cpu}.libmatch.json").write_text(json.dumps(res, indent=2))
    named = sum(1 for v in res.values() if v["ghidra"])
    print(f"{a.cpu}: {len(res)} library hits, {named} at a Ghidra function start, "
          f"{sum(v['candidates'][0]['size'] for v in res.values())} bytes")

if __name__ == "__main__":
    main()
