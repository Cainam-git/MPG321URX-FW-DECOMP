#!/usr/bin/env python3
"""build work/refs/8051_bank<b>.refs.json + .summary.json for one 8051 bank.
usage: python3 -I tools/refs/8051/refs.py <bank>
Rules (docs/REFERENCES.md has the reasoning):
 C1 MOV DPTR,#v whose first DPTR use is MOVC A,@A+DPTR / JMP @A+DPTR / LCALL ?C?LLDCODE -> CODE address, sure
 C2 MOV DPTR,#v with another use: listed only when the source names v as CODE (sure) or v starts a string/table of
    this bank's data regions (doubtful)
 C3 generic pointer R3:R2:R1 = #FF:#hi:#lo (Keil memory type FF = CODE) -> sure when the source names it or it is
    inside a Keil library module, else doubtful
 C4 register pair immediates (R6:R7, R4:R5, R2:R3) naming a CODE address in the source -> sure; hitting a string
    or table start without source support -> doubtful
 C5 DPH/DPL built from ADD/ADDC/MOV immediates and then read with MOVC -> sure (split constant)
 C6 Keil ?C?CCASE inline tables (format of the library routine: hi, lo, value ... 00 00, default) -> sure
 C7 JMP @A+DPTR jump tables (LJMP/AJMP entries at the MOV DPTR target) -> sure
 D* data regions: vectors, ?C_INITSEG records, partition table (bank 0), pointer tables in CODE (per bank, below)
"""
import json, pathlib, re, sys
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import d51, gaps, initseg, scan, srclit  # noqa: E402
import srcpath  # noqa: E402  (tools/, put on the path by d51)

ROOT = d51.ROOT
OUT = ROOT / "work" / "refs"


class Bank:
    def __init__(s, b):
        s.b = b; s.base = b * 0x10000; s.bk = d51.bank_bytes(b)
        s.fn = d51.funcs(b)
        s.code = [(a, e, n) for a, e, n, k in s.fn if k == "code"]
        s.starts = {a: n for a, e, n in s.code}
        s.sym = {v["name"]: v for v in d51.syms(b).values()}
        s.lits = srclit.lits(b)
        s.libfn = {srcpath.label_of(f"8051_bank{b}", p) for p in srcpath.files(f"8051_bank{b}", ".lib")}
        s.regions = gaps.regions(b)
        s.strings = {}
        s.datastart = set()
        for a, e in s.regions:
            for k, x, y in gaps.pieces(s.bk, a, e):
                if k == "str": s.strings[x] = s.bk[x:y - 1].decode("latin1")
                if k in ("str", "bytes"): s.datastart.add(x)
        for a, e, n, k in s.fn:
            if k == "data": s.regions.append((a, e))
        s.entries = []

    def in_region(s, v):
        return any(a <= v < e for a, e in s.regions)

    def owner(s, v):
        for a, e, n in s.code:
            if a <= v < e: return n
        return None

    def target(s, v):
        if v in s.starts: return {"kind": "function", "name": s.starts[v], "off": s.base + v}
        if v in s.strings: return {"kind": "string", "name": None, "off": s.base + v}
        if s.in_region(v): return {"kind": "data", "name": None, "off": s.base + v}
        o = s.owner(v)
        if o: return {"kind": "code-inside", "name": o, "off": s.base + v}
        return {"kind": "unknown", "name": None, "off": s.base + v if v < 0x10000 else None}

    def info(s, f):
        if f in s.lits: return s.lits[f]
        e = s.sym.get(f, {})
        for k in ("module", "of"):
            if e.get(k) in s.lits: return s.lits[e[k]]
        m = re.search(r"compiling (src/8051_bank\d/\S+?\.c)", e.get("comment", ""))   # the module file of a block
        if m and srcpath.label_of(None, ROOT / m.group(1)) in s.lits: return s.lits[srcpath.label_of(None, ROOT / m.group(1))]
        return None

    def region_of(s, v):
        for a, e in s.regions:
            if a <= v < e: return (a, e)
        return None

    def smatch(s, inf, v):
        """source evidence for v; a DAT_CODE_x+off match only counts when v lies in the same data region as x"""
        r = srclit.match(inf, v)
        if r and "+0x" in r:
            base = int(r.split("+0x")[0][9:], 16)
            rg = s.region_of(base)
            if rg is None or not (rg[0] <= v < rg[1]): return None
        return r

    def islib(s, f):
        return f in s.libfn

    def add(s, off, width, value, target, evidence, status, note=None, **kw):
        d = {"off": s.base + off, "width": width, "value": value, "target": target, "evidence": evidence,
             "status": status}
        if note: d["note"] = note
        d.update(kw)
        s.entries.append(d)


def code_rules(B):
    cand, probs = scan.run(B.b)
    ins, tabs, _ = d51.sweep(B.b)
    gp_offs = set()
    copy = d51.libs(B.b).get("?C?COPY")
    pos = {x[0]: i for i, x in enumerate(ins)}

    def copy_after(pc):
        """'?C?COPY' when the generic pointer at pc is the source of a ?C?COPY call within the next 8 instructions"""
        i = pos.get(pc)
        if i is None or copy is None: return None
        for j in range(i + 1, min(i + 9, len(ins))):
            if ins[j][2] in ("LCALL", "LJMP") and ins[j][3][0][1] == copy: return "?C?COPY"
            if ins[j][2] in ("LCALL", "LJMP", "RET"): return None
        return None
    seen_val = {}
    for o in cand:
        f = o["func"]; inf = B.info(f); lib = B.islib(f)
        if o["kind"] == "dptr":
            v = o["value"]
            if o["use"] in ("movc", "jmp@a+dptr", "lib:?C?LLDCODE"):
                ev = ["codeuse:%s" % f, "dptr-" + o["use"]]
                sm = B.smatch(inf, v)
                if sm: ev.append("src:" + sm)
                if lib: ev.append("keil-lib")
                B.add(o["off"], 2, v, B.target(v), ev, "sure", region="code", insn="MOV DPTR,#0x%04X" % v)
            else:
                sm = B.smatch(inf, v)
                if sm and o["use"] != "movx":
                    B.add(o["off"], 2, v, B.target(v), ["codeuse:%s" % f, "src:" + sm, "dptr-" + str(o["use"])], "sure",
                          region="code", insn="MOV DPTR,#0x%04X" % v)
                elif v in B.datastart and o["use"] != "movx":
                    B.add(o["off"], 2, v, B.target(v), ["dptr-" + str(o["use"])], "doubtful",
                          note="value starts a data piece of this bank but the source of %s does not name it" % f,
                          region="code", insn="MOV DPTR,#0x%04X" % v)
        elif o["kind"] == "gptr":
            gp_offs.update((o["off_hi"], o["off_lo"]))
            if o["type"] != 0xFF: continue
            v = o["value"]; sm = B.smatch(inf, v)
            ev = ["codeuse:%s" % f, "gptr-type:FF"]
            if sm: ev.append("src:" + sm)
            if lib: ev.append("keil-lib")
            cp = copy_after(o["pc"])
            if cp: ev.append("keil-copy:" + cp)
            st = "sure" if (sm or lib or cp) else "doubtful"
            B.add(o["off_hi"], 2, v, B.target(v), ev, st, split={"type": B.base + o["off_type"], "hi": B.base + o["off_hi"],
                  "lo": B.base + o["off_lo"]}, region="code", insn="MOV R3,#0FFH / MOV R2,#%02XH / MOV R1,#%02XH" % (v >> 8, v & 0xFF),
                  note=None if st == "sure" else "R3 = 0xFF could also be a char argument; the source does not name this address")
        elif o["kind"] == "pair":
            if o["off_hi"] in gp_offs or o["off_lo"] in gp_offs: continue
            v = o["value"]; sm = B.smatch(inf, v)
            if sm:
                B.add(o["off_hi"], 2, v, B.target(v), ["codeuse:%s" % f, "src:" + sm, "regpair:" + o["regs"]], "sure",
                      split={"hi": B.base + o["off_hi"], "lo": B.base + o["off_lo"]}, region="code")
            elif v in B.datastart and v >= 0x100:
                B.add(o["off_hi"], 2, v, B.target(v), ["regpair:" + o["regs"]], "doubtful",
                      split={"hi": B.base + o["off_hi"], "lo": B.base + o["off_lo"]}, region="code",
                      note="register pair value starts a data piece of this bank; the source of %s does not name it" % f)
        elif o["kind"] == "ccase":
            for eo, a, val in o["entries"]:
                B.add(eo, 2, a, B.target(a), ["codeuse:%s" % f, "keil-ccase"], "sure", region="code-table",
                      note="?C?CCASE entry (case value 0x%02X)" % val)
            B.add(o["default_off"], 2, o["default"], B.target(o["default"]), ["codeuse:%s" % f, "keil-ccase"], "sure",
                  region="code-table", note="?C?CCASE default address")

    # C8 constant pointer stored byte by byte into XDATA: MOV A,#x / MOVX @DPTR,A (/ INC DPTR) ... (LARGE-model
    # parameters and pointer variables); 3 bytes FF,hi,lo = generic CODE pointer; 2 bytes = memory-specific pointer
    i = 0
    while i < len(ins):
        seq = []; j = i
        while j + 1 < len(ins):
            pj, lj, mj, oj, fj = ins[j]; pk, lk, mk, ok, fk = ins[j + 1]
            if mj == "MOV" and oj[0] == "A" and oj[1].startswith("#") and mk == "MOVX" and ok[0] == "@DPTR" and fj == fk:
                seq.append((pj + 1, int(oj[1][1:-1], 16), fj)); j += 2
                if j < len(ins) and ins[j][2] == "INC" and ins[j][3][0] == "DPTR": j += 1; continue
                break
            if mj == "CLR" and oj[0] == "A" and mk == "MOVX" and ok[0] == "@DPTR" and fj == fk:
                seq.append((None, 0, fj)); j += 2
                if j < len(ins) and ins[j][2] == "INC" and ins[j][3][0] == "DPTR": j += 1; continue
                break
            break
        if len(seq) >= 2:
            f = seq[0][2]; inf = B.info(f)
            for k in range(len(seq) - 1):
                t3 = seq[k:k + 3]
                if len(t3) == 3 and t3[0][1] == 0xFF and t3[1][0] and t3[2][0] is not None:
                    v = (t3[1][1] << 8) | t3[2][1]; sm = B.smatch(inf, v)
                    ev = ["codeuse:%s" % f, "xstore-gptr-type:FF"] + (["src:" + sm] if sm else [])
                    B.add(t3[1][0], 2, v, B.target(v), ev, "sure" if sm else "doubtful", region="code",
                          split={"type": B.base + t3[0][0], "hi": B.base + t3[1][0], "lo": B.base + (t3[2][0] or 0)},
                          note=None if sm else "FF,hi,lo stored to XDATA; the source does not name this address")
                    break
            else:
                for k in range(len(seq) - 1):
                    if seq[k][0] is None: continue
                    v = (seq[k][1] << 8) | seq[k + 1][1]; sm = B.smatch(inf, v)
                    if sm and (k == 0 or seq[k - 1][1] != 0xFF):
                        B.add(seq[k][0], 2, v, B.target(v), ["codeuse:%s" % f, "xstore-word", "src:" + sm], "sure",
                              region="code", split={"hi": B.base + seq[k][0], "lo": B.base + (seq[k + 1][0] or 0)})
            i = j
        else:
            i += 1
    # ?C?LSTK* inline long constants: listed when they are LEON-side addresses (0x9F.. RAM windows / 0xA0.. code)
    for f, call, at, v in d51.INLINE:
        if v >> 24 in (0x9F, 0xA0, 0xA8) and v & 0xFFFF == 0 and (v >> 16) & 0xFF not in (0x00, 0x02, 0x10, 0x12):
            B.add(at, 4, v, {"kind": "ram", "name": "LEON-side 0x%08X" % v, "off": None}, ["codeuse:%s" % f, "keil-lstk-inline"],
                  "sure", region="code-inline", fixed=True,
                  note="long constant after LCALL ?C?LSTK* (inline data); LEON-side load window, independent of the 8051 layout")

    # C3b R3 = #FF with R2/R1 set BEFORE it (reverse order, Keil library) or computed (ADD A,#lo / MOV R1,A ;
    # MOV A,#hi + ADDC / MOV R2,A): generic CODE pointer base
    for o in cand:
        if o["kind"] != "r3only" or o["type"] != 0xFF: continue
        f = o["func"]; i = pos[o["pc"]]; got = {}
        for j in range(i - 1, max(i - 8, -1), -1):
            pj, lj, mj, oj, fj = ins[j]
            if fj != f or mj in ("LCALL", "LJMP", "SJMP", "RET", "AJMP", "ACALL"): break
            if mj == "MOV" and oj[0] in ("R1", "R2") and oj[0] not in got:
                if oj[1].startswith("#"): got[oj[0]] = (pj + 1, int(oj[1][1:-1], 16), "MOV %s,#imm" % oj[0])
                elif oj[1] == "A":
                    for k in range(j - 1, max(j - 4, -1), -1):
                        pk, lk, mk, ok, fk = ins[k]
                        if ok and ok[0] == "A" and len(ok) > 1 and ok[1].startswith("#") and mk in ("MOV", "ADD", "ADDC"):
                            got[oj[0]] = (pk + 1, int(ok[1][1:-1], 16), "%s A,#imm" % mk); break
        if len(got) == 2:
            v = (got["R2"][1] << 8) | got["R1"][1]; inf = B.info(f); sm = B.smatch(inf, v); lib = B.islib(f)
            ev = ["codeuse:%s" % f, "gptr-type:FF"] + (["src:" + sm] if sm else []) + (["keil-lib"] if lib else [])
            B.add(got["R2"][0], 2, v, B.target(v), ev, "sure" if sm or lib else "doubtful", region="code",
                  split={"type": B.base + o["pc"] + 1, "hi": B.base + got["R2"][0], "lo": B.base + got["R1"][0]},
                  note="generic CODE pointer, R2/R1 loaded before R3 (%s / %s)" % (got["R2"][2], got["R1"][2]))
    # C5 split constants and C7 jump tables
    idx = {x[0]: i for i, x in enumerate(ins)}
    for i, (pc, ln, m, ops, f) in enumerate(ins):
        if m == "JMP":
            # table at the DPTR value: consecutive LJMP/AJMP instructions
            for j in range(i - 1, max(i - 14, -1), -1):
                pj, lj, mj, oj, fj = ins[j]
                if mj == "MOV" and oj[0] == "DPTR":
                    t = int(oj[1][1:-1], 16); k = idx.get(t)
                    n = 0
                    while k is not None and k < len(ins) and ins[k][2] in ("LJMP", "AJMP") and ins[k][4] == f:
                        pk, lk, mk, ok, fk = ins[k]
                        tv = ok[0][1]
                        if mk == "LJMP":
                            B.add(pk + 1, 2, tv, B.target(tv), ["codeuse:%s" % f, "jumptable"], "sure", region="code-table",
                                  note="JMP @A+DPTR table 0x%04X entry %d (LJMP)" % (t, n))
                        else:
                            B.add(pk, 2, tv, B.target(tv), ["codeuse:%s" % f, "jumptable"], "sure", region="code-table",
                                  note="JMP @A+DPTR table 0x%04X entry %d (AJMP: 11-bit target in opcode bits 7..5 + next byte)" % (t, n))
                        n += 1; k += 1
                    break
        lld = d51.libs(B.b).get("?C?LLDCODE")
        if m == "MOVC" and ops[1] == "@A+DPTR" or m == "JMP" or (m in ("LCALL", "LJMP") and lld is not None and ops[0][1] == lld):
            hi = lo = None; dptr = None
            for j in range(i - 1, max(i - 14, -1), -1):
                pj, lj, mj, oj, fj = ins[j]
                if fj != f: break
                if mj == "MOV" and oj[0] == "DPTR": dptr = j; break
                if mj in ("LCALL", "ACALL", "RET", "SJMP", "LJMP", "AJMP"): break
                if mj == "MOV" and oj[0] == "083H" and hi is None: hi = j
                if mj == "MOV" and oj[0] == "082H" and lo is None: lo = j
            if dptr is not None or hi is None: continue
            parts = {}
            for nm, j in (("hi", hi), ("lo", lo)):
                if j is None: continue
                pj, lj, mj, oj, fj = ins[j]
                if oj[1].startswith("#"): parts[nm] = (pj + 2, int(oj[1][1:-1], 16), "MOV %s" % oj[0]); continue
                if oj[1] != "A": continue
                for k in range(j - 1, max(j - 6, -1), -1):
                    pk, lk, mk, ok, fk = ins[k]
                    if mk in ("ADD", "ADDC", "MOV", "ORL") and ok[0] == "A" and ok[1].startswith("#"):
                        parts[nm] = (pk + 1, int(ok[1][1:-1], 16), mk); break
                    if mk in ("LCALL", "SJMP", "LJMP"): break
            if "hi" in parts:
                hv = parts["hi"][1]; lv = parts.get("lo", (None, 0))[1]
                v = (hv << 8) | lv
                inf = B.info(f); sm = B.smatch(inf, v)
                ev = ["codeuse:%s" % f, "split-dptr-" + ({"MOVC": "movc", "JMP": "jmp"}.get(m, "lldcode"))]
                if sm: ev.append("src:" + sm)
                B.add(parts["hi"][0], 2, v, B.target(v), ev, "sure" if sm or B.islib(f) else "doubtful", region="code",
                      split={"hi": B.base + parts["hi"][0], "lo": (B.base + parts["lo"][0]) if "lo" in parts else None},
                      note="DPTR built from immediates (%s high 0x%02X%s) then read as CODE; base about 0x%04X" % (
                          parts["hi"][2], hv, (", %s low 0x%02X" % (parts["lo"][2], lv)) if "lo" in parts else "", v))
    return probs


def vectors(B):
    """reset LJMP at 0 and interrupt vector LJMPs (bank 1)"""
    for a, e, n, k in B.fn:
        if a < 0x30 and k == "code" and B.bk[a] == 0x02 and e - a == 3:
            v = (B.bk[a + 1] << 8) | B.bk[a + 2]
            what = "reset vector" if a == 0 else "interrupt vector %d" % ((a - 3) // 8)
            B.add(a + 1, 2, v, B.target(v), ["vector"], "sure", region="vector", note="%s: LJMP 0x%04X" % (what, v))


def initrecs(B):
    recs, end = initseg.decode(B.b)
    for r in recs:
        if r["addr_off"] is None: continue
        B.add(r["addr_off"], r["addr_w"], r["addr"], {"kind": "ram", "name": "%s 0x%04X" % (r["type"], r["addr"]), "off": None},
              ["keil-initseg"], "sure", region="initseg",
              note="?C_INITSEG record at CODE 0x%04X: %d byte(s) for %s 0x%04X" % (r["at"], r["n"], r["type"], r["addr"]))
    return recs


def summary(B, note):
    from collections import Counter
    c = Counter(e["status"] for e in B.entries)
    s = {"candidates": len(B.entries), "sure": c["sure"], "doubtful": c["doubtful"], "number": c["number"], "note": note}
    (OUT / f"8051_bank{B.b}.summary.json").write_text(json.dumps(s, indent=1) + "\n")
    return s


def write(B):
    B.entries.sort(key=lambda e: (e["off"], e["width"]))
    out = []
    for e in B.entries:   # one entry per field; repeated finds add their evidence
        if out and out[-1]["off"] == e["off"] and out[-1]["width"] == e["width"]:
            for x in e["evidence"]:
                if x not in out[-1]["evidence"]: out[-1]["evidence"].append(x)
            if e["status"] == "sure": out[-1]["status"] = "sure"
            continue
        out.append(e)
    B.entries[:] = out
    (OUT / f"8051_bank{B.b}.refs.json").write_text(json.dumps(B.entries, indent=0) + "\n")
    if "--export" in sys.argv:        # the settled list, one entry per line, for the repository
        assert not any(e["status"] == "doubtful" for e in B.entries), "open entries: settle them before exporting"
        rows = [e for e in sorted(B.entries, key=lambda e: e["off"]) if e["status"] == "sure"]
        (ROOT / "symbols" / f"8051_bank{B.b}.refs.json").write_text(
            '{"section":"8051_bank%d","addresses":%d,"plain_numbers":%d,"refs":[\n' % (B.b, len(rows), len(B.entries) - len(rows))
            + ",\n".join(json.dumps(r, separators=(",", ":")) for r in rows) + "\n]}\n")


if __name__ == "__main__":
    b = int(sys.argv[1])
    B = Bank(b)
    probs = code_rules(B)
    vectors(B)
    initrecs(B)
    extra = HERE / f"extra_{b}.py"   # hand-checked data-region rules per bank
    if extra.exists():
        ns = {"B": B, "d51": d51}
        exec(compile(extra.read_text(), str(extra), "exec"), ns)
    write(B)
    from collections import Counter
    fx = sum(1 for e in B.entries if e.get("fixed"))
    reg = Counter(e.get("region") for e in B.entries)
    print(summary(B, "(tools/refs/8051/refs.py + extra_%d.py): CODE-address constants in code (DPTR/MOVC, generic pointers, "
                     "split DPH/DPL, XDATA-stored pointers), ?C?CCASE and JMP @A+DPTR tables, vectors, ?C_INITSEG record "
                     "addresses (XDATA/IDATA RAM), data-region tables; %d entries are fixed (hardware / LEON-side, do not move); "
                     "regions %s; target kind 'length' = partition lengths" % (b, fx, dict(reg))))
