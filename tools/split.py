#!/usr/bin/env python3
"""Split MSI_MPG321URX_V021_7F69.bin into its per-core components.

Layout derived by inspection (see docs/MAP.md). Usage:
    split.py <firmware.bin> <outdir>
"""
import hashlib, pathlib, sys

EXPECTED_SHA256 = "4934abd71dff21492dda3b2dd630f3539ba1d6639de88f2f3684fd03d59f019e"

# name, file offset, length, ghidra language, load address, note
PARTS = [
    ("8051_bank0",  0x000000, 0x008000, "8051:BE:16:default", "CODE:0x0000",
     "8051 boot/ISP bank, 32 KiB, reset vector LJMP 0x13F7"),
    ("8051_bank1",  0x010000, 0x010000, "8051:BE:16:default", "CODE:0x0000",
     "8051 application bank 1, full 64 KiB, reset LJMP 0xA627"),
    ("8051_bank2",  0x020000, 0x010000, "8051:BE:16:default", "CODE:0x0000",
     "8051 application bank 2, full 64 KiB, reset LJMP 0xD426"),
    ("8051_bank3",  0x030000, 0x010000, "8051:BE:16:default", "CODE:0x0000",
     "8051 bank 3: mostly tables, build date 'Nov 10 2025' at +0xB2C4"),
    ("leon2s",      0x050000, 0x080000, "sparc:BE:32:default", "0xA0060000",
     "LEON2 sub core ('NT68500 Leon2S'), trap table at base, reset handler +0x2C0"),
    ("leon2m",      0x0D0000, 0x140000, "sparc:BE:32:default", "0xA0028000",
     "LEON2 main core ('NT68500 Leon2M'), code to 0x206B00, panel/EDID tables inside"),
    ("osd_data",    0x210000, 0x070000, None, "0xA0168000",
     "OSD menus, fonts, multilingual strings (consumed by leon2m)"),
    ("leon2m_data", 0x280000, 0x030652, None, "0xA01D8000",
     "leon2m .data image (version strings, SWVERSION); copied to DRAM at run time, DRAM address unresolved"),
]

def main(src, outdir):
    data = pathlib.Path(src).read_bytes()
    got = hashlib.sha256(data).hexdigest()
    if got != EXPECTED_SHA256:
        print(f"warning: sha256 {got} != expected {EXPECTED_SHA256}", file=sys.stderr)
    out = pathlib.Path(outdir); out.mkdir(parents=True, exist_ok=True)
    for name, off, ln, lang, base, note in PARTS:
        chunk = data[off:off+ln]
        (out / f"{name}.bin").write_bytes(chunk)
        print(f"{name:12s} file 0x{off:06X}+0x{ln:06X} -> {base or '-':12s} {lang or 'data'}  # {note}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(sys.argv[1], sys.argv[2])
