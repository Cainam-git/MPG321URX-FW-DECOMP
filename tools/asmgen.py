#!/usr/bin/env python3
"""Assembly-source pass for routines that were hand-written assembly in the original.

Only functions using instructions C cannot express (%psr, %wim, %tbr, %asr, rett, ta, lda/sta,
flush) qualify, plus everything in the 4 KB trap table at the image base (256 fixed 16-byte
slots, assembly by definition): window overflow/underflow handlers, start-up code.
The disassembly becomes a .S file (internal branch targets as labels, calls as symbols),
is assembled with the BCC assembler and judged like C. Matches go to src/<cpu>/<fn>.S
with status matched, by "asm".   usage: asmgen.py <cpu> [--import]
"""
import json, re, subprocess, sys, pathlib, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import diff
AS = str(ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-as")
BASE = {"leon2s": 0xA0060000, "leon2m": 0xA0028000}
MARK = re.compile(r"%psr|%wim|%tbr|%asr|\brett\b|\bta\b|\blda\b|\bsta\b|\bflush\b")
BR = re.compile(r"^(b\w*|fb\w*|cb\w*|call)(,a)?$")

def gen(cpu, fn, text):
    rows = []
    for ln in text.splitlines()[1:]:
        m = re.match(r"^([0-9a-f]+):\s+((?:[0-9a-f]{2} ){4})\s*(.*)$", ln)
        if not m: return None
        ins = m.group(3).split("!")[0].strip()
        w = int(m.group(2).replace(" ", ""), 16)
        # format 2/3 instruction with the immediate bit set but a zero offset: objdump prints "[ %rX ]" / "%rX" for
        # both encodings; write "+ 0" so the assembler picks the immediate form like the original
        if (w >> 30) in (2, 3) and (w >> 13) & 1 and (w & 0x1FFF) == 0:
            ins = re.sub(r"\[ (%\w+) \]", r"[ \1 + 0 ]", ins)
            if re.match(r"^(jmp|jmpl|rett|flush)\s+%\w+$", ins): ins += " + 0"
        rows.append((int(m.group(1), 16), ins))
    if not rows: return None
    addrs = {a for a, _ in rows}; labels = set(); out = []
    for a, ins in rows:
        parts = ins.split(None, 1); op = parts[0] if parts else ""
        if BR.match(op) and len(parts) == 2 and re.fullmatch(r"0x[0-9a-f]+", parts[1].strip()):
            t = int(parts[1], 16)
            if t in addrs: labels.add(t); ins = f"{op} .L{t:08x}"
            elif op == "call": ins = f"call FUN_{t:08x}"
            else: ins = f"{op} ext_{t:08x}"
        if op == "clr" and len(parts) == 2 and parts[1].strip().startswith("%"):   # objdump's clr is the immediate form
            ins = f"or %g0, 0, {parts[1].strip()}"
        if op in ("unimp", ".word") or "<unknown>" in ins or "(bad)" in ins: return None
        out.append((a, ins))
    body = "".join((f".L{a:08x}:\n" if a in labels else "") + f"\t{ins}\n" for a, ins in out)
    return (f"\t.section \".text\"\n\t.align 4\n\t.global {fn}\n\t.type {fn}, #function\n{fn}:\n"
            + body + f"\t.size {fn}, .-{fn}\n")

def main():
    cpu = sys.argv[1]; do_import = "--import" in sys.argv
    symp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(symp.read_text())
    done = {v["name"] for v in sym["functions"].values() if v.get("status") == "matched"}
    funcs = {f["name"]: f for f in json.loads((ROOT / "symbols" / f"{cpu}.functions.json").read_text())["functions"]}
    n = ok = 0; fails = []
    for sp in sorted((ROOT / "asm" / cpu).glob("*.s")):
        fn = sp.stem; text = sp.read_text()
        if fn not in funcs: continue   # stale listing of a function removed by a list repair
        in_trap_table = funcs[fn]["start"] < BASE[cpu] + 0x1000   # SPARC trap table: 256 x 16-byte asm slots
        if fn in done or not (MARK.search(text) or in_trap_table): continue
        n += 1
        src = gen(cpu, fn, text)
        if not src: fails.append((fn, "cannot convert")); continue
        with tempfile.TemporaryDirectory() as td:
            s = pathlib.Path(td) / "a.S"; o = pathlib.Path(td) / "a.o"; s.write_text(src)
            r = subprocess.run([AS, "-Av8", str(s), "-o", str(o)], capture_output=True, text=True)
            if r.returncode: fails.append((fn, r.stderr.strip().splitlines()[-1][:120])); continue
            try: res = diff.compare(cpu, fn, str(o))
            except BaseException as e: fails.append((fn, f"judge: {e}")[:2]); continue
        if not res[6]: fails.append((fn, f"{res[5]:.1f}%")); continue
        ok += 1
        if do_import:
            f = funcs[fn]
            (ROOT / "src" / cpu / f"{fn}.S").write_text(
                f"! {cpu} {fn} @ 0x{f['start']:08x}  MATCH (sparc-elf-as -Av8, asm)\n"
                "! Hand-written assembly in the original: uses instructions C cannot express\n"
                "! (processor state / trap registers). Reproduced from the disassembly; not yet commented.\n" + src)
            sym["functions"][f"ram:{f['start']:08x}"] = {"name": fn, "status": "matched", "by": "asm",
                                                        "comment": "hand-written assembly (privileged instructions); reproduced from disassembly"}
    if do_import: symp.write_text(json.dumps(sym, indent=2, sort_keys=True))
    print(f"{cpu}: {n} asm-only routines, {ok} reproduce exactly" + (" (imported)" if do_import else ""))
    for fn, why in fails[:6]: print("  ", fn, why)

if __name__ == "__main__":
    main()
