"""Mechanical repair of near-miss sources (tools/near.py records): the shape already matches and the byte judge
(tools/exact.py) names the first wrong word. Each round decodes the compiled and the firmware word and edits the C:
  * ldub/lduh at +3/+2 of a 4-byte global  -> the global IS a byte/halfword: narrow its declared type
  * [reg + %g0] in the firmware, [reg + 0] compiled -> the global sits at a 1 KB-aligned address: access it
    through a cast constant address (#define) so gcc emits the register form
  * sethi / %lo / load offset differ -> the global's address is wrong: rename DAT_old to DAT_new everywhere
  * plain immediate differs -> replace the C literal that produced it
  * call displacement differs -> rename the callee to the function really called
  * an outside name whose declaration carries an address -> rename it to DAT_/FUN_<address>
  * a string literal missing from the firmware -> the closest firmware string with the same start
Every edit is kept only when the byte judge's first wrong word moves forward; a match is filed on master
(src/<cpu>/<fn>.c + symbols) like every other match, with by="near".
Usage: nearfix.py [--cpu c] [--names a,b] [--dry]"""
import argparse, difflib, json, pathlib, re, subprocess, sys, tempfile, time
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff, exact, autoc
GCC = ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc"
OBJDUMP = ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-objdump"
NM = ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-nm"
LD_OPS = {0: ("ld", 4), 1: ("ldub", 1), 2: ("lduh", 2), 4: ("st", 4), 5: ("stb", 1), 6: ("sth", 2), 9: ("ldsb", 1), 10: ("ldsh", 2)}
NARROW = {1: "unsigned char", 2: "unsigned short"}


def dec(w):
    op = w >> 30
    if op == 0 and (w >> 22) & 7 == 4: return {"k": "sethi", "rd": (w >> 25) & 31, "imm": w & 0x3fffff}
    if op == 1: return {"k": "call", "disp": (w & 0x3fffffff) - (0x40000000 if w & 0x20000000 else 0)}
    if op in (2, 3):
        s = w & 0x1fff; s -= 0x2000 if s & 0x1000 else 0
        return {"k": "ldst" if op == 3 else "arith", "rd": (w >> 25) & 31, "op3": (w >> 19) & 63, "rs1": (w >> 14) & 31,
                "i": (w >> 13) & 1, "imm": s, "rs2": w & 31}
    return {"k": "other"}


def compile_(cpu, src, flags, td):
    o = td / "x.o"
    r = subprocess.run([str(GCC), *flags.split(), "-w", "-c", str(src), "-o", str(o)], capture_output=True, text=True)
    return (o if r.returncode == 0 else None), r.stderr.strip().splitlines()[-1:] 


def reloc_at(obj, fn, at, lo):
    """symbol name of the relocation that patches the word at firmware address `at` (None if none)"""
    m = re.search(r"^([0-9a-f]+)(?: [0-9a-f]+)? [Tt] " + re.escape(fn) + "$", subprocess.run([str(NM), "-S", str(obj)], capture_output=True, text=True).stdout, re.M)
    off = int(m[1], 16) if m else 0
    want = at - (lo - off)
    for o, typ, tgt in re.findall(r"^([0-9a-f]+)\s+R_SPARC_(\w+)\s+(\S+)", subprocess.run([str(OBJDUMP), "-r", "-j", ".text", str(obj)], capture_output=True, text=True).stdout, re.M):
        if int(o, 16) == want: return tgt.partition("+")[0], typ
    return None, None


def sym_addr(name):
    a = exact.addr_of.__wrapped__ if hasattr(exact.addr_of, "__wrapped__") else None
    h = re.fullmatch(r"_?(?:FUN|DAT|PTR|LAB|ARR|ext|func_0x|s|u)_?([0-9a-fA-F]{8})(?:_\w+)?", name)
    return int(h[1], 16) if h else None


def rename(c, old, new):
    return re.sub(r"\b" + re.escape(old) + r"\b", new, c)


def decl_type(c, name):
    m = re.search(r"extern\s+((?:(?:const|volatile|unsigned|signed|struct\s+\w+|\w+)\s+)+?)\**\s*" + re.escape(name) + r"\s*(\[[^\]]*\])*\s*;", c)
    return m


def judge(cpu, fn, src, flags, td):
    o, err = compile_(cpu, src, flags, td)
    if not o: return None, "compile error: " + " ".join(err)[:120], None
    try: res = diff.compare(cpu, fn, str(o))
    except BaseException as e: return None, f"judge error: {e}"[:120], None
    if res[6]: return o, None, 100.0
    reason = diff.last_reason if (res[5] >= 99 and diff.last_reason) else f"shape {res[5]:.1f}%"   # a 99 % shape with no byte verdict is still a shape miss
    return o, reason, res[5]


def first_bad(reason):
    m = re.match(r"bytes differ at 0x([0-9a-f]+): compiled ([0-9a-f]{8}) vs firmware ([0-9a-f]{8})", reason or "")
    return (int(m[1], 16), int(m[2], 16), int(m[3], 16)) if m else None


def fw_strings(cpu):
    img = exact.part(cpu)
    return [s.decode("latin1") for s in re.findall(rb"[\x20-\x7e\t\n\r]{4,}", img)]


def propose(cpu, fn, c, obj, reason, lo):
    """yield (label, new_c) candidates for the first wrong word"""
    m = re.match(r"outside name '([^']+)'", reason or "")
    if m:
        name = m[1]
        d = re.search(r"(?:^|\n)[^\n]*\b" + re.escape(name) + r"\b[^\n]*", c)
        line = d.group(0) if d else ""
        h = re.search(r"0x([0-9a-fA-F]{6,8})", line) or re.search(r"_([0-9a-fA-F]{6,8})\b", name)
        if h:
            a = int(h[1], 16)
            kind = "FUN" if re.search(re.escape(name) + r"\s*\(", line) and "extern" in line and ("(" in line.split(name)[1][:1]) else "DAT"
            yield f"name {name}->{kind}_{a:08x}", rename(c, name, f"{kind}_{a:08x}")
        return
    if (reason or "").startswith("its constant data"):
        fws = fw_strings(cpu)
        for lit in sorted(set(re.findall(r'"((?:[^"\\]|\\.)*)"', c)), key=len, reverse=True):
            raw = lit.encode().decode("unicode_escape", errors="ignore")
            if raw.encode("latin1", errors="ignore") + b"\0" in exact.part(cpu): continue   # with its terminator: trailing spaces/newlines count
            head = re.split(r"[%\\\n]", raw)[0][:10]
            cands = [s for s in fws if head and head in s]
            best = sorted(cands, key=lambda s: -difflib.SequenceMatcher(None, raw, s).ratio())[:3]
            for s in best:
                # keep the firmware's text exactly, re-escaped for C
                esc = s.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t")
                yield f"string {lit[:20]!r}->{esc[:20]!r}", c.replace('"' + lit + '"', '"' + esc + '"')
        return
    fb = first_bad(reason)
    if not fb: return
    at, x, y = fb; X, Y = dec(x), dec(y)
    sym, typ = reloc_at(obj, fn, at, lo)
    if X["k"] == "ldst" and Y["k"] == "ldst" and X["op3"] == Y["op3"] and X["rd"] == Y["rd"] and X["rs1"] == Y["rs1"]:
        width = LD_OPS.get(X["op3"], ("?", 0))[1]
        if X["i"] == 1 and Y["i"] == 0 and Y["rs2"] == 0 and sym:
            a = sym_addr(sym); d = decl_type(c, sym)
            if a is not None and d:
                t = d[1].strip()
                yield f"{sym} via cast address", c.replace(d.group(0), f"#define {sym} (*({t} *)0x{a:08x})")
        elif X["i"] == 1 and Y["i"] == 1 and sym:
            a = sym_addr(sym); delta = Y["imm"] - X["imm"]
            if a is not None:
                if width in NARROW and delta == -(4 - width):
                    d = decl_type(c, sym)
                    if d: yield f"{sym} is {NARROW[width]}", c.replace(d.group(0), d.group(0).replace(d[1], NARROW[width] + " "))
                yield f"{sym}->{sym[:4]}{a + delta:08x}", rename(c, sym, f"{sym[:4]}{a + delta:08x}")
        elif X["i"] == 1 and Y["i"] == 1 and not sym:
            yield from literal_swaps(c, X["imm"], Y["imm"])
    elif X["k"] == "sethi" and Y["k"] == "sethi" and sym and typ == "HI22":
        a = sym_addr(sym)
        if a is not None:
            new = (Y["imm"] << 10) | (a & 0x3ff)
            yield f"{sym}->{sym[:4]}{new:08x}", rename(c, sym, f"{sym[:4]}{new:08x}")
    elif X["k"] == "sethi" and Y["k"] == "sethi" and not sym:
        yield from literal_swaps(c, X["imm"] << 10, Y["imm"] << 10, hi=True)
    elif X["k"] == "arith" and Y["k"] == "arith" and X["op3"] == Y["op3"] and X["rd"] == Y["rd"] and X["rs1"] == Y["rs1"] and X["i"] == Y["i"] == 1:
        if sym and typ == "LO10":
            a = sym_addr(sym)
            if a is not None:
                new = (a & ~0x3ff) | (Y["imm"] & 0x3ff)
                yield f"{sym}->{sym[:4]}{new:08x}", rename(c, sym, f"{sym[:4]}{new:08x}")
        elif not sym:
            yield from literal_swaps(c, X["imm"], Y["imm"])
    elif X["k"] == "call" and Y["k"] == "call" and sym:
        tgt = at + Y["disp"] * 4
        yield f"{sym}->FUN_{tgt:08x}", rename(c, sym, f"FUN_{tgt:08x}")


def literal_swaps(c, xv, yv, hi=False):
    """replace one C literal that equals xv (any spelling) by yv; one candidate per occurrence"""
    for m in list(re.finditer(r"(?<![\w.])(-?)(0[xX][0-9a-fA-F]+|\d+)(?![\w.])", c)):
        v = int(m[2], 0) * (-1 if m[1] else 1)
        if hi:
            if (v >> 10) & 0x3fffff != (xv >> 10) & 0x3fffff: continue
            nv = (v & 0x3ff) | yv
        else:
            if v != xv and (v & 0xffffffff) != (xv & 0xffffffff): continue
            nv = yv if m[1] or (yv < 0 and not m[2].lower().startswith("0x")) else (yv & 0xffffffff)
        rep = (f"0x{nv & 0xffffffff:x}" if m[2].lower().startswith("0x") else str(nv))
        yield f"literal {m.group(0)}->{rep}", c[:m.start()] + rep + c[m.end():]


def file_match(cpu, fn, c, flags, fixes, size, dry):
    key = f"{exact.funcs(cpu)[fn][0]:08x}"
    header = (f"/* {cpu} {fn} @ 0x{key}  MATCH ({flags}, gcc 3.4.4, near)\n * near-miss repaired mechanically (tools/nearfix.py): "
              + "; ".join(fixes)[:500] + "\n */\n")
    if dry: print("  DRY: would file", fn); return
    out = ROOT / "src" / cpu / f"{fn}.c"; out.write_text(header + c)
    symp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(symp.read_text())
    sym["functions"][f"ram:{key}"] = {"name": fn, "status": "matched", "by": "near", "comment": "near-miss repaired: " + "; ".join(fixes)[:300]}
    if flags != autoc.CFG[cpu]["cflags"]: sym["functions"][f"ram:{key}"]["cflags"] = flags
    symp.write_text(json.dumps(sym, indent=2, sort_keys=True))
    subprocess.run(["git", "add", str(out.relative_to(ROOT)), str(symp.relative_to(ROOT))], cwd=ROOT)
    subprocess.run(["git", "commit", "-q", "-m", f"{cpu}: match {fn} (near, {size} bytes)"], cwd=ROOT)


def run_one(cpu, fn, rec, dry):
    c0 = pathlib.Path(rec["src"]).read_text(); flags = rec["flags"]; lo = exact.funcs(cpu)[fn][0]
    with tempfile.TemporaryDirectory() as td:
        td = pathlib.Path(td); src = td / f"{fn}.c"
        c = c0; fixes = []
        for _round in range(8):
            src.write_text(c)
            obj, reason, score = judge(cpu, fn, src, flags, td)
            if reason is None:
                (ROOT / "work/near" / cpu / f"{fn}.c").write_text(c)
                file_match(cpu, fn, c, flags, fixes or ["already exact"], rec.get("size"), dry)
                return "MATCH", fixes
            if obj is None or reason.startswith("shape"): return reason, fixes
            cur = first_bad(reason); progressed = False
            for label, c2 in propose(cpu, fn, c, obj, reason, lo):
                if c2 == c: continue
                src.write_text(c2)
                obj2, reason2, score2 = judge(cpu, fn, src, flags, td)
                if obj2 is None: continue
                if reason2 is None: c = c2; fixes.append(label); progressed = True; break
                if reason2.startswith("shape"): continue
                nb = first_bad(reason2)
                if (cur and nb and nb[0] > cur[0]) or (cur is None and nb is not None) or (reason2 != reason and not nb and not cur):
                    c = c2; fixes.append(label); progressed = True; break
            if not progressed: return reason, fixes
        return "rounds exhausted", fixes


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("--cpu", default=""); ap.add_argument("--names", default=""); ap.add_argument("--dry", action="store_true")
    a = ap.parse_args(); want = set(a.names.split(",")) if a.names else None
    n = m = 0
    for cpu in ([a.cpu] if a.cpu else ["leon2s", "leon2m"]):
        sym = json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())["functions"]
        matched = {v["name"] for v in sym.values() if v.get("status") == "matched"}
        for p in sorted((ROOT / "work/near" / cpu).glob("*.json")):
            fn = p.stem
            if want and fn not in want: continue
            if fn in matched: continue
            rec = json.loads(p.read_text())
            if rec.get("score", 0) < 99 and not want: continue
            n += 1
            res, fixes = run_one(cpu, fn, rec, a.dry)
            if res == "MATCH": m += 1
            print(f"{cpu} {fn} {rec.get('size')}B: {res[:80]}" + (f"  <- {'; '.join(fixes)}" if fixes else ""))
    print(f"\n{m} of {n} repaired")


if __name__ == "__main__": main()
