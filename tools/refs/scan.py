#!/usr/bin/env python3
"""Reference scan for a LEON section: every aligned 4-byte word outside the function bodies whose value lies in an
address range of that processor, with the evidence for or against it being an address. See docs/REFERENCES.md.
usage: scan.py leon2m [--write]      (--write: work/refs/<section>.refs.json and .summary.json)"""
import bisect, json, pathlib, re, struct, sys
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import srcpath
FW = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()

class M:   # main processor
    name = "leon2m"
    # (label, file start, file end) of everything this processor owns
    regions = [("startup", 0x0D0000, 0x0D7B44), ("initdata", 0x0EC000, 0x0F2F38), ("edid", 0x118000, 0x120000),
               ("program", 0x120000, 0x206B00), ("rodata", 0x206B00, 0x2101F0), ("fonts", 0x2101F0, 0x275DE8),
               ("texts", 0x275DE8, 0x280000), ("dataimage", 0x280000, 0x2B0652)]
    @staticmethod
    def name2off(a): return a - 0xA0028000 + 0x0D0000 if a < 0xA0030000 else a - 0xA0000000 + 0xA8000
    @staticmethod
    def val2off(v):   # value stored in the firmware -> file offset of its target, or None
        if 0x10000 <= v < 0x1A8654: return v + 0x108000                 # flash window
        if 0xA8024000 <= v < 0xA802AF38: return v - 0xA8024000 + 0x0EC000   # initialised RAM (has a flash image)
        if 0xA802AF38 <= v < 0xA8040000: return -1                        # RAM without image (bss, heap, stack)
        if 0xA0028000 <= v < 0xA002FB44: return v - 0xA0028000 + 0x0D0000
        if 0x40088000 <= v < 0x4008FB44: return v - 0x40088000 + 0x0D0000
        return None

class S:   # input processor: one program image, file 0x050000 (0x54F60 bytes, partition table), runs at 0xA0060000
    name = "leon2s"
    regions = [("program", 0x050000, 0x050000 + 0x54F60), ("initdata", 0x0A6000, 0x0A6000 + 0x27E0),
               ("program2", 0x0B0000, 0x0B0000 + 0x1EEC5)]   # the three partition table entries inside 0x050000..0x0D0000
    @staticmethod
    def name2off(a): return a - 0xA0060000 + 0x050000
    @staticmethod
    def val2off(v):
        if 0xA0060000 <= v < 0xA00B4F60: return v - 0xA0060000 + 0x050000    # first program part
        if 0x9F1B0000 <= v < 0x9F1CEEC8: return v - 0x9F1B0000 + 0x0B0000    # second program part at its run address (the 8051 copies file 0x0B0000 to 0x9F1B0000)
        if 0xA8076000 <= v < 0xA80787E0: return v - 0xA8076000 + 0x0A6000    # start values of the data RAM (image at file 0xA6000: the trap code reads its handler table from RAM 0xA8076040, file 0xA6040)
        if 0xA80787E0 <= v < 0xA8080000: return -1                            # data RAM without image
        return None

def load(sec):
    fl = json.loads((ROOT / f"symbols/{sec.name}.functions.json").read_text())
    fl = fl if isinstance(fl, list) else fl["functions"]
    rng = sorted((sec.name2off(f["start"]), sec.name2off(f["end"]), f["name"]) for f in fl)
    return rng

def main():
    sec = S if sys.argv[1] == 'leon2s' else M
    rng = load(sec); starts = [r[0] for r in rng]; fstart = {r[0]: r[2] for r in rng if not r[2].startswith("switchdata")}
    def infunc(o):
        i = bisect.bisect_right(starts, o) - 1
        return rng[i][2] if i >= 0 and o < rng[i][1] else None
    # data symbols the source names (DAT_xxxxxxxx etc.): object starts the code uses directly
    syms = set()
    for p in srcpath.files(sec.name, ".c"):       # the code with its names put back to labels
        for m in re.finditer(r"\b(?:DAT|PTR|ARR|s|u)_([0-9a-fA-F]{8})\b", srcpath.read_labels(sec.name, p)):
            syms.add(int(m.group(1), 16))
    symoff = set()
    for a in syms:
        o = sec.val2off(a)
        if o is None and sec is M and 0xA0030000 <= a < 0xA0200000: o = a - 0xA0000000 + 0xA8000
        if o and o > 0: symoff.add(o)
    out = []
    for label, a, b in sec.regions:
        for o in range(a, b - 3, 4):
            fn = infunc(o)
            if fn and not fn.startswith("switchdata"): continue
            v = struct.unpack(">I", FW[o:o + 4])[0]
            t = sec.val2off(v)
            if t is None: continue
            ev = []; kind = "unknown"; name = None
            if fn: ev.append("jumptable:" + fn)
            if t == -1: kind = "ram"
            else:
                if t in fstart: ev.append("funcstart"); kind = "function"; name = fstart[t]
                elif infunc(t): kind = "code-inside"; name = infunc(t)
                elif t in symoff: ev.append("symbol"); kind = "data"
                else:
                    # start of a text? (previous byte 0 or target at a 4-byte boundary, printable run of >= 4)
                    s = FW[t:t + 4]
                    if len(s) == 4 and all(32 <= c < 127 or c in (10, 13) for c in s) and (FW[t - 1] == 0 or t % 4 == 0): kind = "string"
                    else: kind = "data"
            out.append({"off": o, "region": label, "width": 4, "value": v,
                        "target": {"kind": kind, "name": name, "off": None if t == -1 else t}, "evidence": ev, "status": "doubtful"})
    # runs: consecutive candidates 4 bytes apart
    byoff = {e["off"]: e for e in out}
    for e in out:
        n = 1; o = e["off"]
        while o - 4 in byoff: o -= 4; n += 1
        o = e["off"]
        while o + 4 in byoff: o += 4; n += 1
        e["run"] = n
    import collections
    c = collections.Counter((e["region"], e["target"]["kind"], "run>=4" if e["run"] >= 4 else "run<4") for e in out)
    for k, n in sorted(c.items()): print(f"{k[0]:10s} {k[1]:12s} {k[2]:7s} {n:6d}")
    print("candidates", len(out))
    if "--write" in sys.argv:
        (ROOT / f"work/refs/{sec.name}.cand.json").write_text(json.dumps(out))
        (ROOT / f"work/refs/{sec.name}.summary.json").write_text(json.dumps({"candidates": len(out), "sure": 0, "doubtful": len(out), "number": 0, "note": "first count, nothing classified yet"}))
main()
