#!/usr/bin/env python3
"""Mechanical first pass: clean Ghidra's C for every function, compile it, judge it. Fully mechanical.

Fills in string literals from the image, declares globals with the width the assembly
uses, maps Ghidra's type names to C. Matches are written to work/autoc/<cpu>/<fn>.c,
all scores to work/autoc/<cpu>.scores.json (best starting points for further work).

usage: autoc.py <cpu> [--max-bytes N] [--names a,b]
"""
import json, re, subprocess, sys, pathlib, argparse
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import extract_func, diff

ROOT = pathlib.Path(__file__).resolve().parent.parent
BASE = {"leon2s": 0xA0060000, "leon2m": 0xA0028000}
CFG = json.loads((ROOT / "tools" / "config.json").read_text())

PRELUDE = """typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define CONCAT11(a, b) ((unsigned short)(((unsigned)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT13(a, b) (((unsigned)(a) << 24) | ((unsigned)(b) & 0xffffff))
#define CONCAT21(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define CONCAT22(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define SUB41(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define SUB42(x, c) ((unsigned short)((unsigned)(x) >> ((c) * 8)))
#define SUB43(x, c) (((unsigned)(x) >> ((c) * 8)) & 0xffffff)
#define SUB21(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define ZEXT14(x) ((unsigned)(unsigned char)(x))
#define ZEXT24(x) ((unsigned)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define SEXT14(x) ((int)(signed char)(x))
#define SEXT24(x) ((int)(short)(x))
#define SEXT12(x) ((short)(signed char)(x))
"""
WIDTH = {"ld": "unsigned int", "st": "unsigned int", "ldub": "unsigned char", "stb": "unsigned char",
         "ldsb": "signed char", "lduh": "unsigned short", "sth": "unsigned short", "ldsh": "short"}
KEYWORDS = {"if", "while", "for", "return", "switch", "sizeof", "do", "else", "case"}

def cstring(img, base, addr):
    off = addr - base
    if not 0 <= off < len(img): return None
    end = img.find(b"\0", off)
    if end < 0 or end - off > 400: return None
    s = img[off:end]
    return '"' + "".join(chr(c) if 32 <= c < 127 and chr(c) not in '"\\' else f"\\{c:03o}" for c in s) + '"'

_NAMES = {}
def _names(cpu):
    if cpu not in _NAMES:
        _NAMES[cpu] = {f["name"] for f in json.loads((ROOT / "symbols" / f"{cpu}.functions.json").read_text())["functions"]}
    return _NAMES[cpu]

_SIGS = {}
def signatures(cpu):
    """exact prototypes of functions already matched on master (src/<cpu>/*.c)"""
    if cpu not in _SIGS:
        sig = {}
        for p in (ROOT / "src" / cpu).glob("*.c"):
            t = p.read_text(); name = p.stem
            m = re.search(r"^([A-Za-z_][\w \*]*?)\s+" + re.escape(name) + r"\s*\(([^)]*)\)\s*\n?\s*\{", t, re.M)
            if m and not m.group(1).startswith(("extern", "return", "typedef")):
                params = re.sub(r"\s+", " ", m.group(2)).strip()
                sig[name] = f"extern {m.group(1).strip()} {name}({params or 'void'});"
        _SIGS[cpu] = sig
    return _SIGS[cpu]

def drop_phantom_args(gc):
    """Ghidra guesses callees take 6 args and fills the unset ones with in_oN: drop trailing ones"""
    prev = None
    while prev != gc:
        prev = gc
        gc = re.sub(r",\s*in_o\d+\s*\)", ")", gc)
        gc = re.sub(r"\(\s*in_o\d+\s*\)", "()", gc)
    for v in set(re.findall(r"^\s+\w+ (in_o\d+);$", gc, re.M)):
        if len(re.findall(r"\b" + v + r"\b", gc)) == 1:
            gc = re.sub(r"^\s+\w+ " + v + r";\n", "", gc, flags=re.M)
    return gc

SIZE = {"byte": 1, "undefined1": 1, "char": 1, "uchar": 1, "bool": 1, "undefined": 1, "ushort": 2, "short": 2,
        "undefined2": 2, "word": 2, "uint": 4, "int": 4, "undefined4": 4, "dword": 4, "ulong": 4}

def rewrite_arrays(body):
    """Ghidra folds global arrays into constants: *(T *)(i * 4 + -0x57f829b8) is ARR_a807d648[i]"""
    decls = {}
    def name(c, t):
        addr = (-int(c[1:], 16)) & 0xFFFFFFFF if c.startswith("-") else int(c, 16)
        n = f"ARR_{addr:08x}"
        decls.setdefault(n, t)
        return n
    def scaled(m):
        t, e, sc, c = m.group(1), m.group(2), m.group(3), m.group(4)
        if SIZE.get(t) != int(sc, 0) or e.count("(") != e.count(")"): return m.group(0)
        return f"{name(c, t)}[{e}]"
    body = re.sub(r"\*\((\w+) \*\)\((.+?) \* (\d+) \+ (-0x5[0-9a-f]{7}|0xa[0-9a-f]{7})\)", scaled, body)
    def plain(m):
        t, e, c = m.group(1), m.group(2), m.group(3)
        if e.count("(") != e.count(")") or t not in SIZE: return m.group(0)
        if SIZE[t] == 1: return f"{name(c, t)}[{e}]"
        n = name(c, "byte"); decls[n] = "byte"
        return f"*({t} *)({e} + (int){n})"
    body = re.sub(r"\*\((\w+) \*\)\(([^;]+?) \+ (-0x5[0-9a-f]{7}|0xa[0-9a-f]{7})\)", plain, body)
    return body, [f"extern {t} {n}[];" for n, t in sorted(decls.items())]

def sign_casts(gc):
    """Ghidra writes sign extension as (int)(x * 0x1000000) >> 0x18: that is (char)(x)"""
    gc = re.sub(r"\(int\)\(\(([^()]+)\) \* 0x1000000\) >> 0x18", r"(char)(\1)", gc)
    gc = re.sub(r"\(int\)\(([\w.]+) \* 0x1000000\) >> 0x18", r"(char)(\1)", gc)
    gc = re.sub(r"\(int\)\(\(([^()]+)\) \* 0x10000\) >> 0x10", r"(short)(\1)", gc)
    gc = re.sub(r"\(int\)\(([\w.]+) \* 0x10000\) >> 0x10", r"(short)(\1)", gc)
    return gc

def drop_concat44_returns(body):
    """return CONCAT44(junk, val); -> return val;  (the junk is a leftover register in Ghidra's 64-bit
    return guess; keeping it costs a clr/or pair because gcc 3.4 doesn't fold the 64-bit OR)"""
    out, i = [], 0
    for m in re.finditer(r"\breturn\s+CONCAT44\(", body):
        if m.start() < i: continue
        depth, j, comma = 1, m.end(), None
        while j < len(body) and depth:
            c = body[j]
            if c == "(": depth += 1
            elif c == ")": depth -= 1
            elif c == "," and depth == 1 and comma is None: comma = j
            j += 1
        if depth or comma is None or not re.match(r"\s*;", body[j:]): continue
        out.append(body[i:m.start()] + "return " + body[comma + 1:j - 1].strip())
        i = j
    return "".join(out) + body[i:]

def clean(cpu, fn, gc, asm, img, arrays=True):
    gc = sign_casts(drop_phantom_args(gc))
    gc, arr_decls = rewrite_arrays(gc) if arrays else (gc, [])
    if re.search(r"\b(unaff_|in_[a-z]|extraout_|CONCAT(?!44|11|12|13|21|22|31)\d\d\(|SUB(?!41|42|43|21)\d\d|ZEXT(?!14|24|12)\d\d|SEXT(?!14|24|12)\d\d|halt_baddata)", gc):
        return None
    body = gc
    m = re.match(r"\s*undefined8\s+", body)
    if m:   # Ghidra's 64-bit return guess (CONCAT44 of a leftover register): the real return is the low word
        body = "int " + body[m.end():]
    body = drop_concat44_returns(body)
    widths = {}
    for mm in re.finditer(r"^\S+:\s+(?:[0-9a-f]{2} ){4}\s*(\w+)\s.*!\s*0x([0-9a-f]{8})", asm, re.M):
        widths.setdefault(int(mm.group(2), 16), WIDTH.get(mm.group(1), "unsigned int"))
    decls = []
    def strrep(mm):
        lit = cstring(img, BASE[cpu], int(mm.group(1), 16))
        return lit if lit else mm.group(0)
    body = re.sub(r"\bs_[^\s,();]*?_([0-9a-f]{8})\b", strrep, body)
    if re.search(r"\bs_[^\s,();]*_[0-9a-f]{8}\b", body): return None
    for name in sorted(set(re.findall(r"\b_?(?:DAT|PTR_DAT|PTR)_[0-9a-f]{8}\b", body))):
        addr = int(name[-8:], 16)
        t = widths.get(addr, "unsigned int")
        if re.search(r"\(\*" + name + r"\)\s*\(", body): decls.append(f"extern code *{name};"); continue   # function pointer
        decls.append(f"extern {'volatile ' if addr >= 0xC0000000 else ''}{t} {name};")
    ram = {"u": "unsigned int", "b": "unsigned char", "c": "char", "s": "short", "i": "int", "p": "unsigned int", "us": "unsigned short"}
    for pre, name in sorted(set(re.findall(r"\b((?:us|[ubcsip]))(Ram[0-9a-f]{8})\b", body))):
        decls.append(f"extern {ram[pre]} {pre}{name};")
    for name in sorted(set(re.findall(r"\b(FUN_[0-9a-f]{8})\b(?!\s*\()", body)) - {fn}):
        decls.append(f"extern int {name}();")
    for name in sorted(set(re.findall(r"\b([A-Za-z_]\w*)\s*\(", body)) - KEYWORDS - {fn, "code"} - set(re.findall(r"#define (\w+)\(", PRELUDE))):
        sig = signatures(cpu).get(name)
        if sig:   # exact prototype only when every call here passes that many args; else keep just the return type
            want = 0 if sig.endswith("(void);") else sig.count(",") + 1
            calls = [a for a in re.findall(r"\b" + name + r"\s*\(([^;]*?)\)\s*;", body)]
            if not calls or any((0 if not c.strip() else c.count(",") + 1) != want for c in calls):
                sig = sig[:sig.index("(")] + "();"
        decls.append(sig or f"extern int {name}();")
    decls += arr_decls
    known = _names(cpu)   # function names used as values (callbacks, pointers)
    for name in sorted(set(re.findall(r"\b([A-Za-z_]\w*)\b(?!\s*\()", body)) & known - {fn}):
        if not any(d.endswith(f" {name}();") or f" {name}(" in d for d in decls): decls.append(f"extern int {name}();")
    return PRELUDE + "\n".join(decls) + "\n\n" + body

def flag_sets(cpu):
    return [CFG[cpu]["cflags"]] + CFG[cpu].get("alt_cflags", [])

def judge_flags(cpu, fn, src, tmp, flags):
    c = tmp / f"{fn}.c"; o = tmp / f"{fn}.o"; c.write_text(src)
    r = subprocess.run([str(ROOT / "toolchains" / "sparc-elf-3.4.4" / "bin" / "sparc-elf-gcc"), *flags.split(),
                        "-w", "-c", str(c), "-o", str(o)], capture_output=True, text=True)
    if r.returncode: return -1.0
    try: return diff.compare(cpu, fn, str(o))[5]
    except BaseException: return -1.0

LAST_FLAGS = {}
def judge(cpu, fn, src, tmp):
    """best score over the core's flag sets; the winning flags are left in LAST_FLAGS[fn]"""
    best, bf = -1.0, CFG[cpu]["cflags"]
    for fl in flag_sets(cpu):
        s = judge_flags(cpu, fn, src, tmp, fl)
        if s > best: best, bf = s, fl
        if best >= 100: break
    LAST_FLAGS[fn] = bf
    return best

def import_matches(cpu):
    """re-verify every 100 % result and add it to src/<cpu>/ and symbols/<cpu>.json"""
    import strcheck
    img_bytes = (ROOT / "parts" / f"{cpu}.bin").read_bytes()
    scores = json.loads((ROOT / "work" / "autoc" / f"{cpu}.scores.json").read_text())
    symp = ROOT / "symbols" / f"{cpu}.json"
    sym = json.loads(symp.read_text()) if symp.exists() else {"functions": {}}
    done = {v["name"] for v in sym["functions"].values() if v.get("status") == "matched"}
    fs = {f["name"]: f for f in json.loads((ROOT / "symbols" / f"{cpu}.functions.json").read_text())["functions"]}
    tmp = ROOT / "work" / "autoc" / "tmp"; n = 0
    for fn, v in sorted(scores.items()):
        if v["score"] < 100 or fn in done: continue
        src = (ROOT / "work" / "autoc" / cpu / f"{fn}.c").read_text()
        if judge(cpu, fn, src, tmp) < 100: print("re-check failed", fn); continue
        bad = [x for x in strcheck.literals(src) if x + b"\0" not in img_bytes]
        if bad: print("string not in firmware, not imported:", fn, bad[0][:60]); continue   # matching code, invented text
        f = fs[fn]; fl = LAST_FLAGS.get(fn, CFG[cpu]["cflags"])
        (ROOT / "src" / cpu).mkdir(parents=True, exist_ok=True)
        (ROOT / "src" / cpu / f"{fn}.c").write_text(
            f"/* {cpu} {fn} @ 0x{f['start']:08x}  MATCH ({fl}, gcc 3.4.4, autoc)\n"
            " * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.\n */\n" + src)
        sym["functions"][f"ram:{f['start']:08x}"] = {"name": fn, "status": "matched", "by": "autoc",
                                                    "comment": "mechanical match (tools/autoc.py); not yet named or documented"}
        if fl != CFG[cpu]["cflags"]: sym["functions"][f"ram:{f['start']:08x}"]["cflags"] = fl
        n += 1
    symp.write_text(json.dumps(sym, indent=2, sort_keys=True))
    print(f"{cpu}: imported {n}")

def main():
    ap = argparse.ArgumentParser(); ap.add_argument("cpu"); ap.add_argument("--max-bytes", type=int, default=100000)
    ap.add_argument("--names"); ap.add_argument("--import", dest="do_import", action="store_true",
                                                help="only import the 100 %% results of the last run")
    a = ap.parse_args()
    if a.do_import: return import_matches(a.cpu)
    img = (ROOT / "parts" / f"{a.cpu}.bin").read_bytes()
    out = ROOT / "work" / "autoc" / a.cpu; out.mkdir(parents=True, exist_ok=True)
    tmp = ROOT / "work" / "autoc" / "tmp"; tmp.mkdir(exist_ok=True)
    funcs = json.loads((ROOT / "symbols" / f"{a.cpu}.functions.json").read_text())["functions"]
    want = set(a.names.split(",")) if a.names else None
    scp = ROOT / "work" / "autoc" / f"{a.cpu}.scores.json"
    old = json.loads(scp.read_text()) if scp.exists() else {}
    scores = dict(old); stats = {"skipped": 0, "compile_error": 0, "scored": 0, "match": 0}   # keep every earlier entry: hand/permuter drafts of functions this pass skips must survive (otherwise a better hand draft can be lost)
    for f in funcs:
        fn = f["name"]
        if f["size"] > a.max_bytes or (want and fn not in want): continue
        sp = ROOT / "asm" / a.cpu / f"{fn}.s"
        if not sp.exists(): continue
        try: gc = extract_func.get(a.cpu, fn)[1]
        except Exception: gc = None
        src = clean(a.cpu, fn, gc, sp.read_text(), img) if gc else None
        if not src: stats["skipped"] += 1; continue
        s = judge(a.cpu, fn, src, tmp)
        alt = clean(a.cpu, fn, gc, sp.read_text(), img, arrays=False)
        if alt != src:   # the array rewrite helps some functions and hurts others: keep the better
            s2 = judge(a.cpu, fn, alt, tmp)
            if s2 > s: src, s = alt, s2
        if s < 0: stats["compile_error"] += 1; continue
        stats["scored"] += 1
        if old.get(fn, {}).get("score", -1) >= s and (out / f"{fn}.c").exists():   # keep an earlier/permuted better version
            scores[fn] = old[fn]; s = old[fn]["score"]
        else:
            scores[fn] = {"score": s, "size": f["size"]}; (out / f"{fn}.c").write_text(src)
            if LAST_FLAGS.get(fn, CFG[a.cpu]["cflags"]) != CFG[a.cpu]["cflags"]: scores[fn]["cflags"] = LAST_FLAGS[fn]
        if s >= 100: stats["match"] += 1
    (ROOT / "work" / "autoc" / f"{a.cpu}.scores.json").write_text(json.dumps(scores, indent=1, sort_keys=True))
    hist = {b: sum(1 for v in scores.values() if b <= v["score"] < b + 10 or (b == 90 and v["score"] >= 90)) for b in range(0, 100, 10)}
    print(a.cpu, stats, "by 10%:", hist)

if __name__ == "__main__":
    main()
