/* leon2s LINK_STANDBY @ 0xa006d7bc-0xa006e0e4 (2344 bytes, 586 words), flags -mcpu=v8 -Os -g.
 * BYTE-EXACT: jf 100.00 match=True, rawcmp_l2s.py 0/586 mismatches.
 *
 * What it does: one pass of the HDMI receiver link state machine for one port. Only caller FUN_a006fa28 runs it for
 * port 0 with the 20-byte port record 0xa807a824 and for port 1 with 0xa807a838 (the records FUN_a006fbac sends to
 * the Big chip). Ports > 1: nothing. f = FUN_a008f4d0(port) (= port == 1) indexes the 24-byte link table 0xa807cc64.
 * Every pass first copies record halfword +0x12 bit 7 into link-table byte +6.  rec[0] = state:
 *   1 power off: if power flag 0xa8078878[port] == 1: TMDS_PowerOff(f, 0), flag = 0. (stays 1)
 *   2 power on: if the flag == 0: TMDS_PowerOn(f), flag = 1. Then state 3.
 *   3 LINK_STANDBY: waits for FUN_a0074c48(f) == 1 (link-table byte +1 == 1). Then: RX set-up calls, capture
 *     Htotal/Vtotal/HDE/VDE/clock into rec +2/+4/+6/+8/+0xa, time stamp 0xa8078870[port], "go to LINK_STABLE",
 *     clear the packet flag bytes (FUN_a008faa0/FUN_a008fa78), state 4.
 *   4 LINK_STABLE: link-table byte +1 == 0 -> state 3 ("1 go to LINK_STANDBY"). Else after > 200 ticks since the
 *     stamp: clear 0xa8078c08, re-read colour depth (+0x12 byte), colour space (+0xc) and the 5 timing values,
 *     FUN_a006d61c (status bits); any of HDE/VDE/Htotal/Vtotal == 0 -> state 3 ("3 go to ..."), link-table +1 = 0.
 *     Otherwise it waits while <= 0xf9 ticks AND (RX reg 0x45 & 7) != 4 (FUN_a008fe10); when either ends:
 *     FUN_a008fa00, FUN_a008fa30 (RX status regs 0x72/0x73/0x74/0x84 written 0xff = latched bits cleared),
 *     packet flags cleared, FUN_a0091204, FUN_a0077e68(f, 0), guess counter 0xa8078880[port] = 0, RX state
 *     ARR_a807d3e4[port] +0xa8 = now, state 5 ("go to LINK_READY"), the 9 values logged, rec[0xf] = 1 (publish),
 *     FUN_a008fe6c(port, 0), FUN_a008fdc8, FUN_a00914fc (bit <port> of 0xcf03c890 cleared). FUN_a0079054(port, 0)
 *     ends every > 200-tick pass that did not wait. If the state is now 3: with the "only guess scramble" flag
 *     (FUN_a007517c(f) = 0xa8078978[f]) it logs "fail, back to origin flow", FUN_a0077e68(f, 0); else the counter
 *     0xa8078880[port] counts up and at 2 it logs "start only guess scramble", FUN_a0077e68(f, 1), counter 0.
 *   5 LINK_READY (link up, timing stable): FIRST FUN_a00908d0(port), the RX interrupt poll (see below). Then:
 *     link-table +1 == 0 -> state 3; colour space FUN_a00901a0 != rec[0xc] -> store it, state 4 with the stamp set
 *     to now - 200 (state 4 re-reads on its next pass); else it reads the timing again (Htotal read twice with
 *     FUN_a00b1794(1) between when it changed) and, unless FUN_a008fff0(port) (port 1 and 0xa8078c08 set), flags a
 *     mode change for |HDE - old| > 2, |VDE - old| > 1, HDE == 0x1fff, VDE == 0, |Htotal - old| > 16. FUN_a006d61c;
 *     if any of HDE/VDE/Htotal/Vtotal differs from the record all 5 values are stored (log "ModeChange" if
 *     flagged). RX state +0xac set (FUN_a00908d0's "scramble abnormal" flag) -> cleared, also a mode change.
 *     Mode change -> link-table +1 = 0, state 3. Still state 5: FUN_a006d61c again, RX reg 5 bit 4 cleared when
 *     set, FUN_a0079054(port, 0). Left state 5: "TMDSLinkUnstableTask", FUN_a006d548 (RX reg 5 bit 4 set).
 * End of every pass: left state 5 in this pass -> rec[0x10] = 1, log "ucLINKStatus". rec[0xd] or rec[0xe]
 * changed since the pass start -> rec[0xf] = 1 (publish); a change in rec[0xd] bits 0x4c also sets rec[0x10].
 *
 * When the restart flag latches (code facts): the flag is RX state +0xa6, written ONLY by FUN_a00908d0, which
 * runs only here in state 5, at the start of the pass: +0xa6 = 0, then 1 if RX reg 0x72 bit 7 or reg 0x73 bit 6 was
 * latched (written back to clear). The state 4 -> 5 step clears those registers with 0xff, so the first state-5
 * pass sees only bits latched after the LINK_READY step. FUN_a006d61c copies +0xa6 into rec byte 0xe bit 6 (in the
 * timing branch and at the end of a pass that stays in 5); a changed byte 0xe sets rec[0xf] at the end of the pass,
 * so the Big chip gets bit 6 = 1 exactly for state-5 passes with one of the two bits latched, and 0 again on the
 * next state-5 pass without them. Outside state 5 +0xa6 keeps its last value (state 4 still copies it).
 * State 5 compares only HDE, VDE and Htotal; Vtotal and the clock are captured and
 * re-stored but never compared, so a refresh-rate offset alone does not make this function leave LINK_READY.
 *
 * Aids / layout facts: the saved old timing is a stack struct {HDE, VDE, Htotal, Vtotal, clock} (fw stores all 4
 * compared fields, Vtotal too although it is never read back: a struct in memory; the 5th field is not written, and
 * a 10-byte struct gives the fw frame of 128 bytes; 8 bytes give 120). Levers: every use written with the u8
 * parameter (no local copy), the state-5 tail written 'if (rec->b0 != 5)' first, 'chg = 1' before the scramble
 * log, the start-of-pass reads in the order b0, bd, be. No volatile, no asm.
 */
struct PortRec {
    unsigned char b0, b1;
    unsigned short h2, h4, h6, h8, ha;
    unsigned char bc, bd, be, bf, b10, b11;
    union { unsigned short h; unsigned char b; } u12;
};
struct LinkInfo { unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8[16]; };   /* 24-byte rows */
struct RxSt { unsigned char b[0xa8]; unsigned int t; unsigned char bac, bad, bae, baf; };
struct Old { unsigned short hde, vde, ht, vt, clk; };

extern struct LinkInfo DAT_a807cc64[];
extern struct RxSt ARR_a807d3e4[];
extern unsigned int DAT_a8078870[];
extern unsigned char DAT_a8078878[];
extern unsigned char DAT_a8078880[];
extern char s_a0065c18[], s_a0065c38[], s_a0065c58[], s_a0065c78[], s_a0065ca8[], s_a0065cc0[], s_a0065cd8[],
    s_a0065cf0[], s_a0065d08[], s_a0065d18[], s_a0065d30[], s_a0065d48[], s_a0065d60[], s_a0065d98[], s_a0065dc0[],
    s_a0065de0[], s_a0065df0[], s_a0065e00[], s_a0065e28[], s_a0065e50[], s_a0065e60[], s_a0065e90[], s_a0065ec0[],
    s_a0065ed8[], s_a0065f00[];

extern void FUN_a006d53c(struct PortRec *, unsigned char);
extern void FUN_a006d548(struct PortRec *, unsigned char);
extern void FUN_a006d61c(struct PortRec *, unsigned int);
extern int FUN_a0073044(char *, ...);
extern unsigned int FUN_a00734c4(char *);
extern unsigned char FUN_a0074c48(unsigned int);
extern void TMDS_PowerOn(unsigned char);
extern void TMDS_PowerOff(unsigned char, unsigned char);
extern unsigned char FUN_a007517c(unsigned int);
extern void FUN_a0077e68(unsigned int, unsigned char);
extern void FUN_a0079054(unsigned char, unsigned char);
extern unsigned char FUN_a008f4d0(unsigned char);
extern void FUN_a008f4ec(unsigned char);
extern void FUN_a008fa00(unsigned char);
extern void FUN_a008fa30(unsigned char);
extern void FUN_a008fa78(unsigned int);
extern void FUN_a008faa0(unsigned int);
extern void FUN_a008facc(unsigned int);
extern unsigned char FUN_a008fb7c(unsigned char);
extern void FUN_a008fdc8(unsigned int);
extern unsigned char FUN_a008fe10(unsigned int);
extern void FUN_a008fe38(unsigned char, unsigned char);
extern void FUN_a008fe6c(unsigned char, unsigned char);
extern unsigned char FUN_a008fff0(unsigned char);
extern unsigned short FUN_a0090010(unsigned int);
extern unsigned short FUN_a0090078(unsigned int);
extern unsigned short FUN_a0090098(unsigned int);
extern unsigned short FUN_a0090100(unsigned int);
extern unsigned char FUN_a00901a0(unsigned char);
extern void FUN_a0090374(unsigned char);
extern void FUN_a00908d0(unsigned char);
extern unsigned short FUN_a00910ec(unsigned char);
extern void FUN_a0091204(unsigned int);
extern void FUN_a00912ec(unsigned char);
extern void FUN_a00914fc(unsigned char);
extern void FUN_a0091520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern void FUN_a00a67b8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b1794(int);
extern unsigned int FUN_a00b2064(void);
extern int abs(int);

void LINK_STANDBY(struct PortRec *rec, unsigned char port)
{
    unsigned char f = FUN_a008f4d0(port);
    unsigned char os = rec->b0, od = rec->bd, oe = rec->be;
    unsigned short hde, vde, ht, vt, clk;
    unsigned char chg;
    struct Old old;

    if (port > 1)
        return;
    DAT_a807cc64[f].b6 = (rec->u12.h >> 7) & 1;
    switch (rec->b0) {
    case 1:
        if (DAT_a8078878[port] == 1) {
            TMDS_PowerOff(f, 0);
            DAT_a8078878[port] = 0;
        }
        break;
    case 2:
        if (DAT_a8078878[port] == 0) {
            TMDS_PowerOn(f);
            DAT_a8078878[port] = 1;
        }
        FUN_a006d53c(rec, 3);
        break;
    case 3:
        if (FUN_a0074c48(f) == 1) {
            FUN_a008f4ec(port);
            FUN_a0091520(port);
            FUN_a008fe38(port, 1);
            FUN_a008fe6c(port, 1);
            rec->h2 = FUN_a0090098(port);
            rec->h4 = FUN_a0090100(port);
            rec->h6 = FUN_a0090010(port);
            rec->h8 = FUN_a0090078(port);
            rec->ha = FUN_a00910ec(port);
            DAT_a8078870[port] = FUN_a00b2064();
            FUN_a0073044(s_a0065c18, port);
            FUN_a008faa0(port);
            FUN_a008fa78(port);
            FUN_a006d53c(rec, 4);
        }
        break;
    case 4:
        if (!FUN_a0074c48(f)) {
            FUN_a006d53c(rec, 3);
            FUN_a0073044(s_a0065c38, port);
        } else if (FUN_a00b2064() - DAT_a8078870[port] > 200) {
            FUN_a0090374(port);
            rec->u12.b = FUN_a008fb7c(port);
            FUN_a008facc(port);
            FUN_a00912ec(port);
            rec->h2 = FUN_a0090098(port);
            rec->h4 = FUN_a0090100(port);
            rec->h6 = FUN_a0090010(port);
            rec->h8 = FUN_a0090078(port);
            rec->ha = FUN_a00910ec(port);
            rec->bc = FUN_a00901a0(port);
            FUN_a00901a0(port);
            FUN_a006d61c(rec, port);
            if (rec->h6 == 0 || rec->h8 == 0 || rec->h2 == 0 || rec->h4 == 0) {
                FUN_a006d53c(rec, 3);
                FUN_a0073044(s_a0065c58, port);
                DAT_a807cc64[f].b1 = 0;
            } else {
                if (FUN_a00b2064() - DAT_a8078870[port] <= 0xf9 && FUN_a008fe10(port) == 1)
                    break;
                FUN_a008fa00(port);
                FUN_a008fa30(port);
                FUN_a008faa0(port);
                FUN_a008fa78(port);
                FUN_a0091204(port);
                FUN_a0077e68(f, 0);
                DAT_a8078880[port] = 0;
                ARR_a807d3e4[port].t = FUN_a00b2064();
                FUN_a006d53c(rec, 5);
                FUN_a0073044(s_a0065c78, port, rec->ha);
                FUN_a0073044(s_a0065ca8, rec->h2);
                FUN_a0073044(s_a0065cc0, rec->h4);
                FUN_a0073044(s_a0065cd8, rec->h6);
                FUN_a0073044(s_a0065cf0, rec->h8);
                FUN_a0073044(s_a0065d08, rec->ha);
                FUN_a0073044(s_a0065d18, rec->bc);
                FUN_a0073044(s_a0065d30, rec->u12.b);
                FUN_a0073044(s_a0065d48, rec->bd);
                rec->bf = 1;
                FUN_a008fe6c(port, 0);
                FUN_a008fdc8(port);
                FUN_a00914fc(port);
            }
            FUN_a0079054(port, 0);
        }
        if (rec->b0 == 3) {
            unsigned char g = f;
            if (FUN_a007517c(g)) {
                FUN_a0073044(s_a0065d60, port);
                FUN_a0077e68(g, 0);
            } else if (++DAT_a8078880[port] > 1) {
                FUN_a0073044(s_a0065d98, port);
                FUN_a0077e68(g, 1);
                DAT_a8078880[port] = 0;
            }
        }
        break;
    case 5:
        FUN_a00908d0(port);
        if (!FUN_a0074c48(f)) {
            FUN_a0073044(s_a0065dc0, 1);
            FUN_a006d53c(rec, 3);
        } else if (FUN_a00901a0(port) != rec->bc) {
            FUN_a0073044(s_a0065dc0, 3);
            rec->bc = FUN_a00901a0(port);
            FUN_a006d53c(rec, 4);
            DAT_a8078870[port] = FUN_a00b2064() - 200;
        } else {
            old.ht = rec->h2;
            old.vt = rec->h4;
            old.hde = rec->h6;
            old.vde = rec->h8;
            hde = FUN_a0090010(port);
            vde = FUN_a0090078(port);
            ht = FUN_a0090098(port);
            vt = FUN_a0090100(port);
            clk = FUN_a00910ec(port);
            chg = 0;
            if (ht != old.ht) {
                FUN_a00b1794(1);
                ht = FUN_a0090098(port);
            }
            if (!FUN_a008fff0(port)) {
                if (abs(hde - old.hde) > 2) {
                    FUN_a0073044(s_a0065de0, hde, old.hde);
                    chg = 1;
                }
                if (abs(vde - old.vde) > 1) {
                    FUN_a0073044(s_a0065df0, vde, old.vde);
                    chg = 1;
                }
                if (hde == 0x1fff) {
                    FUN_a00734c4(s_a0065e00);
                    chg = 1;
                }
                if (vde == 0) {
                    FUN_a00734c4(s_a0065e28);
                    chg = 1;
                }
                if (abs(ht - old.ht) > 0x10) {
                    FUN_a0073044(s_a0065e50, ht, old.ht);
                    chg = 1;
                }
            }
            FUN_a006d61c(rec, port);
            if (rec->h6 != hde || rec->h8 != vde || rec->h2 != ht || rec->h4 != vt) {
                rec->h6 = hde;
                rec->h8 = vde;
                rec->h2 = ht;
                rec->h4 = vt;
                rec->ha = clk;
                if (chg)
                    FUN_a0073044(s_a0065e60, port);
            }
            if (ARR_a807d3e4[port].bac) {
                ARR_a807d3e4[port].bac = 0;
                chg = 1;
                FUN_a0073044(s_a0065e90, port);
            }
            if (chg) {
                FUN_a0073044(s_a0065dc0, 4);
                DAT_a807cc64[f].b1 = 0;
                FUN_a006d53c(rec, 3);
            }
        }
        if (rec->b0 != 5) {
            FUN_a00734c4(s_a0065ec0);
            FUN_a006d548(rec, port);
        } else {
            FUN_a006d61c(rec, port);
            if (FUN_a00a657c(port, 5) & 0x10)
                FUN_a00a67b8(port, 5, 0x10, 0);
            FUN_a0079054(port, 0);
        }
        break;
    }
    if (rec->b0 != 5 && os == 5) {
        rec->b10 = 1;
        FUN_a0073044(s_a0065ed8, port, rec->b0);
    }
    if (rec->bd != od || rec->be != oe) {
        rec->bf = 1;
        if ((rec->bd & 0x4c) != (od & 0x4c))
            rec->b10 = 1;
        FUN_a0073044(s_a0065f00, port, rec->bd, rec->be);
    }
}
