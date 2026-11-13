#!/usr/bin/env python3
"""Classify the candidates of work/refs/<section>.cand.json (scan.py) by evidence; writes <section>.refs.json and
<section>.summary.json. Rules are listed in RULES below; every rule that settles an entry adds its name to the
entry's evidence. usage: classify.py leon2m [--stats]"""
import json, pathlib, struct, sys, collections, bisect
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools")); import srcpath
FW = (ROOT / "firmware/MSI_MPG321URX_V021_7F69.bin").read_bytes()
sec = sys.argv[1]
C = json.loads((ROOT / f"work/refs/{sec}.cand.json").read_text())
by = {e["off"]: e for e in C}
def settle(e, status, why):
    if e["status"] == "doubtful": e["status"] = status
    elif e["status"] != status: e.setdefault("conflict", []).append(why)
    if why not in e["evidence"]: e["evidence"].append(why)
# runs of consecutive candidates in one region
offs = sorted(by); runs = []; i = 0
while i < len(offs):
    j = i
    while j + 1 < len(offs) and offs[j + 1] == offs[j] + 4 and by[offs[j + 1]]["region"] == by[offs[i]]["region"]: j += 1
    runs.append([by[o] for o in offs[i:j + 1]]); i = j + 1
def textstart(t):          # target is a menu text: a length byte L, L bytes without a zero, zero padding to the next word
    if t is None or t <= 0: return False
    L = FW[t]
    if L == 0 or 0 in FW[t + 1:t + 1 + L]: return False
    end = t + 1 + L
    return not any(FW[end:(end + 3) & ~3])
for run in runs:
    # R1 jump tables of matched functions (each entry proven by the function's exact check, tools/acctable.py)
    for e in run:
        if any(x.startswith("jumptable:") for x in e["evidence"]): settle(e, "sure", "R1-jumptable")
    # R2 text tables: at least 8 consecutive entries that each point at a length-prefixed menu text
    if run[0]["region"] in ("texts", "dataimage"):
        k = 0
        while k < len(run):
            m = k
            while m < len(run) and textstart(run[m]["target"]["off"]): m += 1
            if m - k >= 8:
                for e in run[k:m]: settle(e, "sure", "R2-texttable"); e["target"]["kind"] = "string"
            k = max(m, k + 1)
    # R2b members of a text table whose text contains zero bytes (font-coded characters): the run is a text table
    # (>= 8 entries, >= 80 % settled by R2) and this entry points into the text areas at a length byte with zero padding
    if run[0]["region"] in ("texts", "dataimage") and len(run) >= 8:
        ok = sum(1 for e in run if "R2-texttable" in e["evidence"])
        if ok >= 0.8 * len(run):
            for e in run:
                t = e["target"]["off"]
                if e["status"] == "doubtful" and t and 0x275DE8 <= t < 0x2B0652 and FW[t] >= 1:
                    end = t + 1 + FW[t]
                    if not any(FW[end:(end + 3) & ~3]): settle(e, "sure", "R2b-texttable-member"); e["target"]["kind"] = "string"
    # R3 function tables: at least 3 consecutive entries that are exact function starts
    k = 0
    while k < len(run):
        m = k
        while m < len(run) and "funcstart" in run[m]["evidence"]: m += 1
        if m - k >= 3:
            for e in run[k:m]: settle(e, "sure", "R3-functiontable")
        k = max(m, k + 1)
# R6 jump tables stored outside their function: at least 8 consecutive entries that all point into one function
for run in runs:
    k = 0
    while k < len(run):
        m = k; nm = run[k]["target"]["name"] if run[k]["target"]["kind"] == "code-inside" else None
        while nm and m < len(run) and run[m]["target"]["kind"] == "code-inside" and run[m]["target"]["name"] == nm: m += 1
        if nm and m - k >= 8 and run[k]["region"] in ("program", "startup") and len({e["value"] for e in run[k:m]}) >= 3 \
           and all(e["value"] % 4 == 0 for e in run[k:m]):
            for e in run[k:m]: settle(e, "sure", "R6-jumptable-into:" + nm)
        k = max(m, k + 1)
# R3s function-pointer fields of a record table: at least 4 exact function starts at one constant spacing (8..64 bytes)
fs = sorted(e["off"] for e in C if "funcstart" in e["evidence"] and e["region"] != "fonts"); fset = set(fs)
for stride in range(8, 68, 4):
    for o in fs:
        if o - stride in fset: continue
        chain = [o]
        while chain[-1] + stride in fset: chain.append(chain[-1] + stride)
        if len(chain) >= 4:
            for x in chain: settle(by[x], "sure", "R3s-functionfield/%d" % stride)
# R4 menu font tables (leon2m): the font area 0x2101F0..0x275DE8 holds 30 tables that the source names (DAT_001081f0
# ... DAT_0016dd20; one lookup routine each, 0xa00a285c..0xa00a2e74) and one stretch of picture data
# 0x21D658..0x22D928 (pointed to by the records at file 0xEC0A0). The lookup routines return a table word or byte
# as a value: words are pixel rows that FUN_a00a31a4 shifts and ORs into the line buffer, bytes are widths.
# So a word inside a font table is a plain number.
# R9 a value that points into a function body but is not a multiple of 4 cannot be a code address.
if sec == "leon2m":
    for e in C:
        if e["region"] == "fonts" and not (0x21D658 <= e["off"] < 0x22D928): settle(e, "number", "R4-fonttable")
for e in C:
    if e["target"]["kind"] == "code-inside" and e["value"] % 4: settle(e, "number", "R9-unaligned-code-address")
# R5 EDID blocks: a fixed standard format without addresses
for e in C:
    if e["region"] == "edid": settle(e, "number", "R5-edid-format")
# RV version comparison (tools/refs/vmap.py): a stored address moves with its target between firmware versions, a
# plain number stays. Votes per older version: "addr" = the old word equals value + (shift of the target);
# "num" = the old word is unchanged although the target moved. Settled only when the votes do not contradict.
RAMLOADED = {"leon2m initdata", "leon2s part2"}
VFILES = {"V020": "MSI_MPG321URX_V020_95AB.bin", "V016": "MSI_MPG321URX_V016_C6FB.bin", "V012": "MSI_MPG321URX_V012_91A5.bin"}
if (ROOT / "tools/refs/vmap.py").exists() and "--novmap" not in sys.argv:
    sys.path.insert(0, str(ROOT / "tools/refs")); import vmap, bisect
    sa = {}
    for ver, fn in VFILES.items():
        try: vm = vmap.load(ver)
        except Exception as ex: print("vmap", ver, "not usable:", ex); continue
        old = (ROOT / "firmware" / fn).read_bytes()
        sa[ver] = [x[0] for x in vm.segs]
        for e in C:
            t = e["target"]["off"]
            if t is None: continue
            o2 = vm.map(e["off"]); t2 = vm.map(t)
            if o2 is None or t2 is None or o2 + 4 > len(old): continue
            v2 = struct.unpack(">I", old[o2:o2 + 4])[0]
            # RAM-loaded regions (start values): the stored value counts from the region start, and the region itself
            # sits at another file offset in the older versions; flash-window values count from the window start
            corr = 0
            for r in vm.regions:
                name, alo, ahi, blo, bhi = r[:5]
                if alo <= t < ahi and name in RAMLOADED: corr = blo - alo
            d = (t2 - t) - corr
            if d != 0 and v2 == e["value"] + d: e.setdefault("votes", []).append("addr:" + ver)
            elif d != 0 and v2 == e["value"]:
                # "unchanged although the target moved" only counts when the word sits in a long identical block
                # (>= 64 bytes): short identical stretches inside a changed table can be paired by coincidence
                # (file 0xEC5E4: a table of equal-sized routines, shifted by one routine in V012)
                i = bisect.bisect_right(sa[ver], e["off"]) - 1
                long_ = i >= 0 and vm.segs[i][3] == "S" and vm.segs[i][2] >= 64 and e["off"] < vm.segs[i][0] + vm.segs[i][2]
                # ... and not when the word is part of an evenly spaced table (three neighbours with one constant,
                # non-zero step): such a table looks identical to itself at a shifted position (file 0x176C44: a jump
                # table stepping by 8 was paired two entries off in V020)
                def val(o): return by[o]["value"] if o in by else None
                o = e["off"]; w = [val(o - 8), val(o - 4), e["value"], val(o + 4), val(o + 8)]
                ap = any(None not in w[k:k + 3] and w[k + 1] - w[k] == w[k + 2] - w[k + 1] != 0 for k in range(3))
                e.setdefault("votes", []).append(("num:" if long_ and not ap else "numweak:") + ver)
            elif d == 0 and v2 == e["value"]: e.setdefault("votes", []).append("same:" + ver)
            else: e.setdefault("votes", []).append("other:" + ver)
            continue
            if t2 != t and v2 == e["value"] + (t2 - t): e.setdefault("votes", []).append("addr:" + ver)
            elif t2 != t and v2 == e["value"]: e.setdefault("votes", []).append("num:" + ver)
            elif t2 == t and v2 == e["value"]: e.setdefault("votes", []).append("same:" + ver)
            else: e.setdefault("votes", []).append("other:" + ver)
    for e in C:
        v = e.get("votes", []); a = [x for x in v if x.startswith("addr:")]; n = [x for x in v if x.startswith("num:")]
        if a: settle(e, "sure", "RV-" + ",".join(a))          # an exact move with the target is decisive
        elif n:
            if e["status"] == "sure": e.setdefault("conflict", []).append("RV-" + ",".join(n) + " against the rule evidence")
            else: settle(e, "number", "RV-" + ",".join(n))
# R11/R12 (input processor only): its addresses are full 32-bit patterns 0xA006....-0xA00D.... (or 0xF10000 above).
# R11: such a value that points exactly at the start of a text of at least 2 characters outside the function bodies
# (the byte before it is the previous text's end, printable up to its own end). R12: such a value that is exactly a function start.
if sec == "leon2s":
    def text_at(t):          # a complete text: starts after a 0 byte, printable up to its own 0 byte (1..200 characters)
        if not t or t <= 0 or FW[t - 1] != 0: return False
        end = FW.find(b"\0", t, t + 201)
        return end > t + 1 and all(32 <= c < 127 or c in (9, 10, 13, 27) for c in FW[t:end])
    for e in C:
        if "funcstart" in e["evidence"]: settle(e, "sure", "R12-functionaddress")
        elif e["target"]["kind"] != "code-inside" and e["target"]["off"] and text_at(e["target"]["off"]):
            settle(e, "sure", "R11-textaddress"); e["target"]["kind"] = "string"
# R10 self-reference: a word in the start values whose value is its own load address or within 16 bytes of it
# (list heads that point at themselves, e.g. the memory allocator's bin table at file 0xF2AC0): an address.
if sec == "leon2m":
    for e in C:
        if e["region"] == "initdata" and abs(e["value"] - (e["off"] - 0x0EC000 + 0xA8024000)) <= 16: settle(e, "sure", "R10-selfreference")
# R4b menu picture data (leon2m): the 12-byte records in the start values (file 0xEC0A4.., struct {length, kind,
# word, address}) are passed by FUN_a01461dc to FUN_a011c4cc, which writes <length> bytes from <address> one by one
# to a display register (run-length decoded when the caller asks for it). The same record type also loads the start-up logo
# data in the read-only area (records at file 0xEC054..0xEC098). 21 records tile 0x21D658..0x22D734 without holes
# (only alignment padding of at most 7 bytes between them). A word inside such a byte stream is a plain number.
if sec == "leon2m":
    spans = []
    for e in C:
        t = e["target"]["off"]
        if e["region"] == "initdata" and 0x0EC04C <= e["off"] < 0x0EC1A4 and e["status"] == "sure" and t and FW[e["off"] - 6] <= 3 and FW[e["off"] - 5] == 0:
            spans.append((t, t + struct.unpack(">H", FW[e["off"] - 8:e["off"] - 6])[0]))
    for e in C:
        if e["status"] == "doubtful" and any(a <= e["off"] and e["off"] + 4 <= b for a, b in spans): settle(e, "number", "R4b-picturedata")
# R14 (leon2m) byte and halfword tables: the entry lies in an object that the matched source declares only as an
# array or scalar of char / short (every declaration of that symbol in src/, no pointer, int or struct), between
# that symbol and the next object start (next symbol named in the source or next target of a settled address).
# The rule only applies when every use in the source indexes the object directly; an object that is passed to a
# function or whose address is taken can be read as words elsewhere and is left to the other rules.
if sec == "leon2m":
    import re
    decl = collections.defaultdict(set)
    for pth in srcpath.files(sec, ".c"):            # the code with its names put back to labels
        txt = re.sub(r"/\*.*?\*/", "", srcpath.read_labels(sec, pth), flags=re.S)
        for line in txt.splitlines():
            for m in re.finditer(r"\b_?(?:DAT|PTR|ARR|s|u)_([0-9a-fA-F]{8})\b", line):
                a = int(m.group(1), 16)
                if 0xA8024000 <= a < 0xA802AF38: o = a - 0xA8024000 + 0x0EC000
                elif a < 0x1A8654: o = a + 0x108000
                else: continue
                if re.match(r"\s*(extern|static|const)\b", line): decl[o].add(" ".join(line.split()))
                else: decl[o].add("")           # symbol used, declaration elsewhere
    bounds = sorted(set(decl) | {e["target"]["off"] for e in C if e["status"] == "sure" and e["target"]["off"]})
    handed_on = set()          # symbols that the source also uses other than by a constant or variable index (passed to a
    for pth in srcpath.files(sec, ".c"):            # function, address taken, pointer arithmetic): R14 does not apply
        txt = re.sub(r"/\*.*?\*/", "", srcpath.read_labels(sec, pth), flags=re.S)
        for line in txt.splitlines():
            if re.match(r"\s*(extern|static|const)\b", line) and not re.search(r"[=(]", line): continue
            for m in re.finditer(r"\b_?(?:DAT|PTR|ARR|s|u)_([0-9a-fA-F]{8})\b(\s*\[)?", line):
                if not m.group(2):
                    a = int(m.group(1), 16)
                    handed_on.add(a - 0xA8024000 + 0x0EC000 if 0xA8024000 <= a < 0xA802AF38 else a + 0x108000)
    def narrow(ds):
        ds = [d for d in ds if d]
        return bool(ds) and all(re.match(r"(extern|static|const|volatile|unsigned|signed|char|short|\s)+[\w\s,\[\]]*;", d)
                                and not re.search(r"\bint\b|\blong\b|\*|struct|union|float|\(", d) for d in ds)
    for e in C:
        if e["status"] != "doubtful": continue
        i = bisect.bisect_right(bounds, e["off"]) - 1
        if i >= 0 and bounds[i] in decl and bounds[i] not in handed_on and narrow(decl[bounds[i]]): settle(e, "number", "R14-byte-or-halfword-table:%#x" % bounds[i])
# M hand rulings (symbols/<section>.refs-manual.json: file offset -> [status, evidence]); only for entries no rule settles
mp = ROOT / f"symbols/{sec}.refs-manual.json"
if mp.exists():
    for k, (stt, why) in json.loads(mp.read_text()).items():
        if "-" in k:               # a range "0xA-0xB": every still unsettled entry inside it
            a, b = (int(x, 16) for x in k.split("-"))
            for e in C:
                if a <= e["off"] < b and e["status"] == "doubtful": settle(e, stt, why)
            continue
        e = by[int(k, 16)]
        if e["status"] == "doubtful": settle(e, stt, why)
        elif e["status"] != stt: e.setdefault("conflict", []).append("hand ruling says " + stt)
c = collections.Counter((e["region"], e["status"]) for e in C)
if "--stats" in sys.argv:
    for k, n in sorted(c.items()): print(f"{k[0]:10s} {k[1]:9s} {n:6d}")
s = collections.Counter(e["status"] for e in C)
(ROOT / f"work/refs/{sec}.refs.json").write_text(json.dumps(C))
if "--export" in sys.argv:        # the settled addresses, one per line, for the repository
    rows = [{"off": e["off"], "width": e["width"], "value": e["value"], "target": e["target"]["off"], "kind": e["target"]["kind"],
             "name": e["target"]["name"], "evidence": [x.split(":")[0] if x.startswith("RV-") else x for x in e["evidence"] if x[:1] in "RM"]}
            for e in sorted(C, key=lambda e: e["off"]) if e["status"] == "sure"]
    assert not any(e["status"] == "doubtful" for e in C), "open entries: settle them before exporting"
    und = [{"off": e["off"], "width": e["width"], "value": e["value"], "why": [x for x in e["evidence"] if x.startswith("M-")][0]}
           for e in sorted(C, key=lambda e: e["off"]) if e["status"] == "undecided"]
    (ROOT / f"symbols/{sec}.refs.json").write_text('{"section":"%s","candidates":%d,"addresses":%d,"plain_numbers":%d,"undecided":%s,"refs":[\n'
        % (sec, len(C), s["sure"], s["number"], json.dumps(und, separators=(",", ":")))
        + ",\n".join(json.dumps(r, separators=(",", ":")) for r in rows) + "\n]}\n")
(ROOT / f"work/refs/{sec}.summary.json").write_text(json.dumps({"candidates": len(C), "sure": s["sure"], "doubtful": s["doubtful"], "number": s["number"], "note": "rules R1 R2 R2b R3 R3s R4 R5 R6 R9 RV; version comparison not applied yet"}))
print(dict(s), "conflicts", sum(1 for e in C if e.get("conflict")))
