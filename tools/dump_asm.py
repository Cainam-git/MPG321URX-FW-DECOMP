#!/usr/bin/env python3
"""Write the target assembly of every function of a SPARC core to asm/<cpu>/<name>.s

Runs objdump once over the raw image at its load address and cuts the output
using the function table Ghidra exported (symbols/<cpu>.functions.json).
Usage: dump_asm.py <leon2m|leon2s>
"""
import json, os, pathlib, re, subprocess, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
BASES = {"leon2s": 0xA0060000, "leon2m": 0xA0028000}

def objdump():
    cfg = json.loads((ROOT / "tools" / "config.json").read_text())
    c = cfg.get("leon2s") or next(iter(cfg.values()))
    return str(ROOT / c["toolchain"]) + "/" + c["prefix"] + "objdump"

def main(cpu):
    base = BASES[cpu]
    out = subprocess.run([objdump(), "-b", "binary", "-EB", "-m", "sparc", "--adjust-vma", hex(base), "-D",
                          str(ROOT / "parts" / f"{cpu}.bin")], capture_output=True, text=True, check=True).stdout
    lines = {}
    for ln in out.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f ]{8,})\s*(.*)$', ln)
        if m: lines[int(m.group(1), 16)] = (m.group(2).strip(), m.group(3).strip())
    funcs = json.loads((ROOT / "symbols" / f"{cpu}.functions.json").read_text())["functions"]
    d = ROOT / "asm" / cpu; d.mkdir(parents=True, exist_ok=True)
    n = 0
    for f in funcs:
        name = f["name"]
        with open(d / f"{name}.s", "w") as w:
            w.write(f"# {cpu} {name} 0x{f['start']:08x}-0x{f['end']:08x} ({f['size']} bytes)\n")
            for a in range(f["start"], f["end"], 4):
                if a in lines:
                    w.write(f"{a:08x}:  {lines[a][0]:<12s} {lines[a][1]}\n")
        n += 1
    print(f"{n} functions -> {d}")

if __name__ == "__main__":
    main(sys.argv[1])
