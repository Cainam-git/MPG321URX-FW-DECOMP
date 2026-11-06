#!/usr/bin/env python3
"""Onboarding pack for one open LEON function: everything known about it, in one printout.

Usage: brief.py <cpu> <function> [--drafts N] [--flags "-mcpu=v8 -O3 -g"] [--no-score]

Prints, in this order:
  1. the function: address range, size, status, claim owner
  2. address neighbours (four on each side): size, status, compiler flags from the matched source's header; the
     flags most of the matched neighbours use are taken as the function's flags unless --flags is given
  3. the claim's STUCK note (work/claims/<function>/STUCK; the last 30 lines)
  4. existing drafts: .c files under work/ that define the function, newest first (search output directories count
     with their two newest files only, all temporary directories of one parent as one directory, tools/mutsearch.py build directories not at all), plus BASE.c of the claim and the last three drafts the STUCK note names; the newest
     --drafts N (default 8) are compiled (two at a time, nice -n 10) and scored: diff score, register-exact rows
     (tools/regions.py) and store/call sequence SAME/DIFF (tools/stseq.py)
  5. matched siblings: matched functions sharing firmware addresses or odd constants with this one, its matched
     callers and callees, with each one's 'Source form' header lines (or the first header lines when it has none)
  6. ACCEPT lines of the board (work/board/BOARD.md) that name the function, a sibling, a neighbour, a caller or a
     callee
  7. where the checklist and the shared tools are
--no-score lists the drafts without compiling them.
"""
import argparse, collections, concurrent.futures as cf, glob, json, os, pathlib, re, subprocess, sys, tempfile, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import diff, regions, stseq

ROOT = pathlib.Path(__file__).resolve().parent.parent
FLAGS = re.compile(r'(?<![\w-])((?:-mcpu=\S+|-O[0-3s]|-g|-msoft-float)(?:\s+(?:-mcpu=\S+|-O[0-3s]|-g|-msoft-float))*)')


def head_flags(path):
    try:
        with open(path, errors="replace") as f: h = f.read(600)
    except OSError: return None
    m = FLAGS.search(h.split("*/")[0])
    return m.group(1).replace(",", "").strip() if m else None


def source_form(path, width=200):
    try: txt = open(path, errors="replace").read(6000).split("*/")[0]
    except OSError: return []
    out, cur = [], None
    for ln in txt.splitlines():
        s = ln.strip().lstrip("/*").strip()
        if s.startswith("Source form") or s.startswith("Compiler aids"):
            if cur: out.append(cur)
            cur = s
        elif cur is not None and s and not re.match(r'^[A-Z][\w ]{2,30}:', s): cur += " " + s
        elif cur is not None:
            out.append(cur); cur = None
    if cur: out.append(cur)
    out = [x[:width] for x in out if x.startswith("Source form")]
    if not out:   # older headers: the first description line
        d = [ln.strip().lstrip("/*").strip() for ln in txt.splitlines()[1:3]]
        out = [("(header) " + " ".join(x for x in d if x))[:width]] if any(d) else []
    return out


def addr_tokens(text):
    t = set(re.findall(r'!\s*(0x[0-9a-f]+)', text)) | set(re.findall(r'%hi\((0x[0-9a-f]+)\)', text))
    t |= set(re.findall(r'(?:mov|or|and|cmp|add|sub|sll|srl)\s+%?\w*,?\s*(0x[0-9a-f]{3,})', text))
    return {x for x in t if int(x, 16) >= 0x1000 and not re.match(r'0xa0[0-9a-f]{6}$', x)}


def main():
    ap = argparse.ArgumentParser(usage=__doc__.split("\n\n")[1])
    ap.add_argument("cpu"); ap.add_argument("fn"); ap.add_argument("--drafts", type=int, default=8)
    ap.add_argument("--flags"); ap.add_argument("--no-score", action="store_true")
    a = ap.parse_args(); cpu, fn = a.cpu, a.fn
    os.chdir(ROOT)
    funcs = json.load(open(f"symbols/{cpu}.functions.json"))["functions"]
    status = {v["name"]: v for v in json.load(open(f"symbols/{cpu}.json"))["functions"].values()}
    funcs = sorted(funcs, key=lambda x: x["start"])
    idx = next((i for i, x in enumerate(funcs) if x["name"] == fn), None)
    if idx is None: raise SystemExit(f"{fn} is not in symbols/{cpu}.functions.json")
    me = funcs[idx]
    claim = ROOT / "work/claims" / fn
    owner = (claim / "owner").read_text().strip() if (claim / "owner").exists() else "-"
    st = status.get(fn, {}).get("status", "open")
    print(f"== {fn} ({cpu}) 0x{me['start']:08x}-0x{me['end']:08x}, {me['size']} bytes ({me['size'] // 4} insns), "
          f"status {st}, owner {owner}")

    # 2. neighbours
    print("\n== address neighbours")
    fl = collections.Counter(); neigh = []
    for x in funcs[max(0, idx - 4):idx + 5]:
        n = x["name"]; src = ROOT / "src" / cpu / f"{n}.c"
        f = head_flags(src) if src.exists() else None
        f = f or status.get(n, {}).get("cflags")
        if n != fn and f and src.exists(): fl[f] += 1
        if n != fn: neigh.append(n)
        print(f"  {'>' if n == fn else ' '} {n:28s} 0x{x['start']:08x} {x['size']:6d} B  "
              f"{status.get(n, {}).get('status', 'open'):8s} {f or ''}")
    flags = a.flags or (fl.most_common(1)[0][0] if fl else "-mcpu=v8 -O3 -g")
    print(f"  flags used below: {flags}" + ("" if a.flags else " (most common among the matched neighbours)"))

    # 3. STUCK
    stuck = claim / "STUCK"
    named = []
    if stuck.exists():
        lines = stuck.read_text(errors="replace").splitlines()
        print(f"\n== {stuck.relative_to(ROOT)} ({len(lines)} lines; last 30)")
        for ln in lines[-30:]: print("  " + ln[:220])
        named = [p for p in re.findall(r'(work/[\w./-]+\.c)\b', stuck.read_text(errors="replace")) if (ROOT / p).exists()]
    else: print("\n== no STUCK note")

    # 4. drafts
    print("\n== drafts")
    r = subprocess.run(["grep", "-rlE", "--include=*.c", r"^[A-Za-z].*\b" + fn + r"\s*\([^;]*$", "work/"],
                       capture_output=True, text=True)
    cand = [p for p in r.stdout.split() if (not p.startswith("work/claims/") or p.endswith("BASE.c"))
            and "/build." not in p]
    bydir = collections.defaultdict(list)
    for p in cand:
        d = re.sub(r'/tmp[._]?[A-Za-z0-9_]{6,}(/.*)?$', '/tmp*', os.path.dirname(p))   # mkdtemp dirs: one group
        try: bydir[d].append((os.path.getmtime(p), p))
        except OSError: pass
    keep = []
    for d, l in bydir.items():
        l.sort(reverse=True); keep += l[:2]
    keep.sort(reverse=True)
    named = list(dict.fromkeys(reversed(named)))[:3]   # the three drafts the STUCK note names last
    extra = ([str((claim / "BASE.c").relative_to(ROOT))] if (claim / "BASE.c").exists() else []) + named
    pick = []
    for p in extra + [p for _, p in keep]:
        if p not in pick: pick.append(p)
    print(f"  {len(cand)} files define {fn} in {len(bydir)} directories; scoring {min(len(pick), a.drafts)}")
    pick = pick[:a.drafts]
    tdir = tempfile.TemporaryDirectory(); td = tdir.name

    def score(k_p):
        k, p = k_p
        f = flags if a.flags else (head_flags(p) or flags)
        o = os.path.join(td, f"d{k}.o")
        if not regions.build(p, o, f, cpu): return p, f, None
        try:
            ev = regions.evaluate(cpu, fn, o)
            s = "SAME" if stseq.same(cpu, fn, o, calls=True) else "DIFF"
            return p, f, (ev["score"], ev["exact"], ev["n_fw"], s, ev["match"])
        except (SystemExit, Exception) as e: return p, f, str(e)[:60]
    res = []
    if a.no_score or not pick: res = [(p, flags, None) for p in pick]
    else:
        with cf.ThreadPoolExecutor(2) as ex: res = list(ex.map(score, enumerate(pick)))
    res.sort(key=lambda x: (x[2][4], x[2][0], x[2][1]) if isinstance(x[2], tuple) else (False, -2, 0), reverse=True)
    best = max((x for x in res if isinstance(x[2], tuple)), key=lambda x: (x[2][4], x[2][0], x[2][1]), default=None)
    for p, f, s in res:
        mt = time.strftime("%m-%d %H:%M", time.localtime(os.path.getmtime(p)))
        if isinstance(s, tuple):
            print(f"  {'*' if best and p == best[0] else ' '} {s[0]:6.2f} exact {s[1]:4d}/{s[2]:<4d} stores {s[3]} "
                  f"{'MATCH ' if s[4] else ''}{mt} {p} [{f}]")
        else: print(f"    {'compile error' if s is None and not a.no_score else (s or '')} {mt} {p}")
    tdir.cleanup()

    # 5. siblings
    print("\n== matched siblings (shared addresses / constants)")
    mine_txt = (ROOT / "asm" / cpu / f"{fn}.s").read_text()
    mine = addr_tokens(mine_txt)
    lo, hi = me["start"], me["end"]
    callees = {int(x, 16) for x in re.findall(r'\bcall\s+0x([0-9a-f]+)', mine_txt)}
    start_of = {x["start"]: x["name"] for x in funcs}
    sc = collections.Counter(); why = {}; callers = []
    for path in glob.glob(f"asm/{cpu}/*.s"):
        n = os.path.basename(path)[:-2]
        if n == fn: continue
        txt = open(path, errors="replace").read()
        if f"0x{lo:08x}" in txt and re.search(r'\bcall\s+0x%08x\b' % lo, txt): callers.append(n)
        if status.get(n, {}).get("status") != "matched" or not (ROOT / "src" / cpu / f"{n}.c").exists(): continue
        c = mine & addr_tokens(txt)
        if c: sc[n] = len(c); why[n] = c
    fam = set(neigh)
    for n, k in sc.most_common(10):
        fam.add(n)
        print(f"  {k:3d} {n}: {' '.join(sorted(why[n]))[:110]}")
        for s in source_form(ROOT / "src" / cpu / f"{n}.c"): print("        " + s)
    rel = [("caller", n) for n in sorted(callers)] + [("callee", start_of[c]) for c in sorted(callees) if c in start_of]
    if rel:
        print("\n== callers and callees")
        for kind, n in rel:
            fam.add(n); m = status.get(n, {}).get("status", "open")
            print(f"  {kind} {n} ({m})")
            if m == "matched":
                for s in source_form(ROOT / "src" / cpu / f"{n}.c")[:2]: print("        " + s)

    # 6. board
    board = ROOT / "work/board/BOARD.md"
    if board.exists():
        names = fam | {fn}
        hits = [ln for ln in board.read_text(errors="replace").splitlines()
                if " ACCEPT " in ln and any(n in ln for n in names)]
        print(f"\n== board ACCEPT lines for the function and its family ({len(hits)}; last 8)")
        for ln in hits[-8:]: print("  " + ln[:260])

    # 7. pointers
    print("""
== next
  checklist: docs/MATCHING-TRICKS.md, section 'First 15 minutes on a SPARC function' (run it in order)
  idioms: work/lead/IDIOMS.md; rules: work/lead/BRIEF-leon2m.md
  tools: tools/regions.py (per-region exact rows, stack slots), tools/stseq.py (store order),
         tools/mutsearch.py (natural-mutation search), tools/lsim.py (local-alloc model), tools/diff.py""")


if __name__ == "__main__":
    main()
