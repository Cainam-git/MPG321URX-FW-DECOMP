#!/usr/bin/env python3
"""Compare leon2m functions between FW.021 and FW.012 with addresses masked.

Each instruction is normalised: call displacements, sethi immediates and the %lo immediates of instructions whose
base register was last set by a sethi (inside the same function) are masked; branch displacements are kept
(relative). A FW.021 function is looked up in FW.012 by its normalised word sequence. Prints, per function:
SAME (found identically), or the closest FW.012 counterpart (same start of function) and the differing words.
usage: fwdiff.py FUN_a01038c0 [FUN_... ...]   |   fwdiff.py --all [--changed]   (all leon2m functions; --leon2s for the small chip)"""
import json, pathlib, struct, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
A = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()
B = (ROOT / "firmware/MSI_MPG321URX_V012_91A5.bin").read_bytes()
CPU = "leon2s" if "--leon2s" in sys.argv else "leon2m"
LO, HI = (0x50000, 0xd0000) if CPU == "leon2s" else (0xa8000, 0x2a0000)
VA2FILE = (0xa0060000 - 0x50000) if CPU == "leon2s" else (0xa0000000 - 0xa8000)   # listing address - file offset
FS = {f["name"]: f for f in json.loads((ROOT / f"symbols/{CPU}.functions.json").read_text())["functions"]}

def norm(img, lo, hi):
    out = []; sethi = set()
    for off in range(lo, min(hi, len(img) - 3), 4):
        w = struct.unpack_from(">I", img, off)[0]; op = w >> 30
        if w & 0xffffe000 == 0x9de3a000: sethi = set()          # save: new frame
        elif w in (0x81c3e008, 0x81c7e008): sethi = {r for r in sethi if r >= 16}   # ret/retl: %o/%g die, %l/%i live on in other paths
        if op == 1: out.append(0x40000000); continue           # call
        if op == 0 and (w >> 22) & 7 == 4:                     # sethi
            sethi.add((w >> 25) & 31); out.append(w & 0xffc00000); continue
        if op in (2, 3) and (w >> 13) & 1 and ((w >> 14) & 31) in sethi:
            out.append(w & ~0x1fff); continue                  # %lo of a sethi base
        out.append(w)
    return out

def find(seq, hay):
    key = struct.pack(f">{len(seq)}I", *seq); h = struct.pack(f">{len(hay)}I", *hay)
    i = h.find(key)
    while i != -1 and i % 4: i = h.find(key, i + 1)
    return -1 if i == -1 else i // 4

NB = norm(B, LO, HI)

def compare(fn):
    f = FS[fn]; off = f["start"] - VA2FILE
    na = norm(A, off, off + f["size"])
    i = find(na, NB)
    if i >= 0: return "SAME", hex(LO + 4 * i), []
    for n in (16, 8, 4):                                       # anchor on the first n words, then diff
        j = find(na[:n], NB)
        if j >= 0:
            nb = NB[j:j + len(na)]
            d = [(k * 4, na[k], nb[k]) for k in range(min(len(na), len(nb))) if na[k] != nb[k]]
            return "CHANGED", hex(LO + 4 * j), d
    for k in range(0, max(len(na) - 6, 1), 2):                 # anchor anywhere inside: 6-word windows
        j = find(na[k:k + 6], NB)
        if j >= 0 and j >= k:
            j -= k
            nb = NB[j:j + len(na)]
            d = [(k * 4, na[k], nb[k]) for k in range(min(len(na), len(nb))) if na[k] != nb[k]]
            return "CHANGED", hex(LO + 4 * j), d
    return "NOT FOUND", None, []

if __name__ == "__main__":
    names = sorted(FS) if "--all" in sys.argv else [a for a in sys.argv[1:] if not a.startswith("--")]
    for fn in names:
        st, at, d = compare(fn)
        if "--changed" in sys.argv and st == "SAME": continue
        print(f"{fn} {FS[fn]['size']}B: {st} {at or ''} {len(d)} differing words" + "".join(f"\n   +{o:#x}: 021 {x:08x} 012 {y:08x}" for o, x, y in d[:8]))


def show(fn, at12, size12=None):
    """aligned diff of the two versions' disassembly (addresses masked), for reading what changed"""
    import difflib, re, subprocess, tempfile
    f = FS[fn]; o21 = f["start"] - VA2FILE; o12 = int(at12, 16)
    od = str(sorted((ROOT / "toolchains").glob("sparc-elf-4.4.2/bin/*objdump"))[0])
    def dis(img, off, n, vma):
        with tempfile.NamedTemporaryFile(suffix=".bin") as t:
            t.write(img[off:off + n]); t.flush()
            out = subprocess.run([od, "-D", "-EB", "-b", "binary", "-m", "sparc", f"--adjust-vma={vma:#x}", t.name],
                                 capture_output=True, text=True).stdout.splitlines()
        rows = []
        for l in out:
            m = re.match(r"\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(.*)", l)
            if not m: continue
            ins = re.sub(r"!.*", "", m[2]).strip()
            ins = re.sub(r"(call|sethi)\s+\S+", r"\1 X", ins)
            ins = re.sub(r"(b\w*|be,a|bne,a)\s+0x[0-9a-f]+", r"\1 L", ins)
            rows.append(ins)
        return rows
    a = dis(A, o21, f["size"], f["start"]); b = dis(B, o12, size12 or f["size"] + 64, 0)
    for l in difflib.unified_diff(b, a, "FW.012", "FW.021", n=2, lineterm=""): print(l)
