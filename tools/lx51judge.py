#!/usr/bin/env python3
"""Judge an 8051 function the way the update agent (bank 2) was built: Keil C51 with OBJECTADVANCED, then the LX51
linker with linker code packing (LJMP/LCALL -> AJMP/ACALL/SJMP, tail jumps into the following function removed).
The eval LX51 only places code below 0x800, so the function is linked at its offset inside its 2 KB page. External
code targets inside the same 2 KB page are mapped into that window; others keep their real address. Bytes that
depend on DATA / XDATA / BIT placement are found by linking twice with shifted data stand-ins and are masked.
usage: lx51judge.py <bank> <fn> <file.c> ["<c51 options>"]"""
import json, pathlib, re, shutil, subprocess, sys, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff8051
K, E = diff8051.KEIL, diff8051.ENV


def run(t, *a):
    r = subprocess.run(["wine", str(K / a[0])] + list(a[1:]), cwd=t, env=E, capture_output=True, text=True, timeout=300)
    return r.stdout + r.stderr


def stand_ins(names, page, shift, fixed={}):
    """AX51 source defining every unresolved external: FUN_CODE_xxxx at its address (mapped into the 2 KB window when
    it lies in the function's page), named data at its address + shift, anything else at a shifted dummy."""
    out = ["$NOMOD51", "NAME STUB", "PUBLIC " + ", ".join(names)]
    for i, (n, cls) in enumerate(sorted(names.items())):
        m = re.search(r"([0-9A-Fa-f]{4})$", n)
        if cls == "CODE":
            a = fixed.get(n, int(m[1], 16) if m else 0x7000 + 3 * i)
            if a & ~0x7FF == page: a &= 0x7FF
            out.append(f"{n} CODE 0{a:04X}H")
        elif cls == "BIT":
            out.append(f"{n} BIT 0{(0x10 + i + shift) & 0x7F:02X}H")
        elif cls in ("DATA", "IDATA"):
            out.append(f"{n} DATA 0{(0x30 + i + shift) & 0x7F:02X}H")
        else:
            a = (int(m[1], 16) if m else 0x6000 + 0x10 * i) + (0x101 * shift if not m else 0)
            out.append(f"{n} XDATA 0{a & 0xFFFF:04X}H")
    return "\n".join(out + ["END"]) + "\n"


def link(t, obj_seg, off, names, page, shift, fixed={}):
    (t / "STUB.A51").write_text(stand_ins(names, page, shift, fixed))
    run(t, "AX51.exe", "STUB.A51")
    for p in t.iterdir():
        if p.name.lower().startswith("out"): p.unlink()
    log = run(t, "LX51.exe", "u.obj,STUB.obj", "TO", "out", f"SEGMENTS({obj_seg}(C:0x{off:X}))",
              f"CLASSES(XDATA(X:0x{0x100 + 0x101 * shift:X}-X:0xFFFF))")
    run(t, "Ohx51.exe", "out")
    hx = [p for p in t.iterdir() if p.name.lower() == "out.hex"]
    if not hx: return None, log
    img = {}
    for ln in hx[0].read_text().splitlines():
        n, a, ty = int(ln[1:3], 16), int(ln[3:7], 16), int(ln[7:9], 16)
        if ty == 0:
            for k in range(n): img[a + k] = int(ln[9 + 2 * k:11 + 2 * k], 16)
    return img, log


def judge(bank, fn, cfile, opts="OPTIMIZE(8,SPEED) LARGE"):
    fs = {f["name"]: f for f in json.loads((ROOT / "symbols" / f"{bank}.functions.json").read_text())["functions"]}
    f = fs[fn]; start, size = f["start"], f["size"]; page, off = start & ~0x7FF, start & 0x7FF
    fw = (ROOT / "parts" / f"{bank}.bin").read_bytes()[start:start + size]
    t = pathlib.Path(tempfile.mkdtemp(prefix="lx51j_")); shutil.copy(cfile, t / "u.c")
    orc = ROOT / "symbols" / f"{bank}.orc"
    if orc.exists(): shutil.copy(orc, t / "R.ORC")
    log = run(t, "C51.exe", "u.c", opts + " OBJECTADVANCED SYMBOLS CODE")
    if not any(p.name.lower() == "u.obj" for p in t.iterdir()): return {"ok": False, "error": log[-600:]}
    lst = next(p for p in t.iterdir() if p.suffix.upper() == ".LST").read_text(errors="replace")
    cls = {m[1]: m[2] for m in re.finditer(r"^(\S+?) ?[ .]*EXTERN\s+(\w+)", lst, re.M)}
    first = run(t, "LX51.exe", "u.obj", "TO", "out")
    names = {}
    libs = json.loads((ROOT / "symbols" / f"{bank}.libs.json").read_text()) if (ROOT / "symbols" / f"{bank}.libs.json").exists() else {}
    for n in sorted(set(re.findall(r"SYMBOL:\s+(\S+)", first))):
        if n.startswith("?C?"):
            names[n] = "CODE"
        elif n.endswith("?BIT"): names[n] = "BIT"
        elif n.endswith("?BYTE"): names[n] = "XDATA" if "LARGE" in opts.upper() else "DATA"
        else: names[n] = cls.get(n, cls.get(n.upper(), "CODE" if "FUN" in n.upper() else "XDATA"))
    lib_names = {n: libs[n] for n in names if n.startswith("?C?") and n in libs}
    seg = next((s for s in re.findall(r"\?PR\?_?\w+\?U", lst) if s.upper().endswith(fn.upper() + "?U")), None)
    seg = seg or (f"?PR?_{fn.upper()}?U" if f"_{fn}" in lst or f"_{fn.upper()}" in lst else f"?PR?{fn.upper()}?U")
    imgs = []
    for shift in (0, 1):
        img, lg = link(t, seg, off, names, page, shift, lib_names)
        if img is None: return {"ok": False, "error": "link failed\n" + lg[-800:]}
        imgs.append(img)
    a0 = off
    got = [imgs[0].get(a0 + i) for i in range(size)]
    alt = [imgs[1].get(a0 + i) for i in range(size)]
    mask = [got[i] != alt[i] for i in range(size)]
    same = sum(1 for i in range(size) if mask[i] or got[i] == fw[i])
    end = imgs[0].get(a0 + size)
    return {"ok": True, "score": 100.0 * same / size, "match": same == size, "masked": sum(mask), "start": start,
            "masked_at": [i for i in range(size) if mask[i]],
            "first_diff": next((i for i in range(size) if not mask[i] and got[i] != fw[i]), -1),
            "compiled": bytes(b if b is not None else 0 for b in got).hex(), "target": fw.hex(), "tmp": str(t)}


if __name__ == "__main__":
    bank, fn, cfile = sys.argv[1:4]
    r = judge(bank, fn, cfile, *(sys.argv[4:5] or []))
    if not r.get("ok"): sys.exit(r.get("error"))
    print(f"{fn}: {r['score']:.1f}% {'MATCH' if r['match'] else 'no match'} (masked {r['masked']} data-address bytes, first diff {r['first_diff']})")
