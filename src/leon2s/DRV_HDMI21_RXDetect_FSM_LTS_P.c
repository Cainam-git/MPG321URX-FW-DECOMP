/* leon2s DRV_HDMI21_RXDetect_FSM_LTS_P @ 0xa009ae98-0xa009b5f4 (-mcpu=v8 -Os -g)
 * Link-training state P for port p = port & 0xff (channel 2 for port 0, 3 for port 1, other ports return 0).
 * On entry to the state (word p of DAT_a807d648 differs from +0x30 of record p of DAT_a807d680) copies the state
 * into the record, clears +0x38/+0x39, sets up the port registers and FUN_a00a7488(ch, 0x2e70, ...) with the
 * mask chosen by the record's mode byte (3 or other), pulses bit 8 of regs0+4 around FUN_a00b1794(1) and clears
 * the counters DAT_a8079082[p] and DAT_a8079080[p].
 * Leaves for state 3 when FUN_a008d800() > 0x82 and byte 1 of regs+0xb0 is not 0xff (then sets it to 0xff), or
 * when bits 24-27 of regs+0x90 differ from the record's rate byte. While FUN_a00a7408(5, regs+0x80) is nonzero,
 * counts DAT_a8079082[p] up to 300 and then checks FUN_a00a7408(0x11, regs+0x90).
 * With DAT_a8079052 == 0, compares bits 24-27 of FUN_a00a7314(ch, 0x2e60) with 7 (mode 3) or 0xf (mode 4). On a
 * hit, prints the error count of regs+0x38 and the sum of the four CED counters; unless that count is 0x8000 or
 * DAT_a8079080[p] > 5, it sets the low halves of regs+0x34/+0x38, selects state 6 and counts DAT_a8079080[p] up;
 * otherwise it records the time in DAT_a807906c[p], prints the time since DAT_a8079074[p], calls FUN_a007ab94(ch)
 * and goes to state 9 after the CED IQ scan (rate 5 or 6) or to state 8 after DRV_HDMI21_ReStart_AEQ2(ch, 0, 1, 0).
 * On a miss, every third call resets the PHY CDR and selects state 3 when FUN_a008d800() <= 0x82 and
 * SR_detect_fail_ch(p) is nonzero. With DAT_a8079052 != 0, goes straight to state 9. Returns 0.
 * Source form: the regs+0xb0 read sits in 'do { } while (once)' with once = 0, a no-code aid (the loop compiles
 * to nothing) that keeps the read before the state store. The timestamp is stored with a chained assignment, and
 * the state-6 store is written as *(DAT_a807d648 + port) = 6, which places the counter increment as in the
 * firmware.
 */
struct Port {
    volatile unsigned int *regs0;
    unsigned char _04[0x18 - 4];
    volatile unsigned int *regs;
    unsigned char _1c[4];
    volatile unsigned int *ced;
    unsigned char _24[0x34 - 0x24];
};
struct Rec {
    unsigned char n;
    unsigned char b1;
    unsigned char rate;
    unsigned char _03[0x2b - 3];
    unsigned char b2b;
    unsigned char b2c;
    unsigned char _2d[3];
    unsigned int state;
    unsigned char _34[3];
    unsigned char b37;
    unsigned char b38;
    unsigned char b39;
    unsigned char _3a[0xb0 - 0x3a];
};

extern struct Port DAT_a807db00[];
extern struct Rec DAT_a807d680[];
extern unsigned int DAT_a807d648[];
extern unsigned short DAT_a8079082[];
extern unsigned char DAT_a8079080[];
extern unsigned char DAT_a8079052;
extern unsigned int DAT_a807906c[];
extern unsigned int DAT_a8079074[];
extern unsigned int DAT_a8078634;
extern const char DAT_a0067868[], s_a00b43b0[], s_a006a368[], s_a006a3a0[], s_a006a3c8[], s_a006a3f0[],
    s_a006a408[], s_a006a420[], s_a006a440[], s_a006a460[], s_a006a480[], s_a006a4a0[], s_a006a4c0[],
    s_a006a508[], s_a006a528[], DAT_a006a548[], s_a006a578[];

extern unsigned char FUN_a008d800(void);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void FUN_a00b1794(unsigned short);
extern void DRV_HDMI21_PHY_PICDR_Reset(unsigned char);
extern unsigned char SR_detect_fail_ch(unsigned int);extern unsigned int FUN_a00b2064(void);
extern void FUN_a007ab94(unsigned char);
extern void DRV_HDMI21_IQ_Scan_byCED(unsigned char);
extern void FUN_a00798fc(unsigned char);
extern void FUN_a00799b8(unsigned char);
extern void DRV_HDMI21_ReStart_AEQ2(unsigned char, int, int, int);

int DRV_HDMI21_RXDetect_FSM_LTS_P(unsigned int port)
{
    int once = 0;
    unsigned char p = port;
    unsigned char ch;
    unsigned char ok;
    unsigned int t;

    ch = 2;
    ok = 0;
    if (p != 0) {
        if (p == 1)
            ch = 3;
        else
            return 0;
    }
    if (DAT_a807d648[p] != DAT_a807d680[p].state) {
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(DAT_a0067868, s_a00b43b0);
        DAT_a807d680[p].state = DAT_a807d648[p];
        DAT_a807d680[p].b38 = 0;
        DAT_a807d680[p].b39 = 0;
        FUN_a00a73ac(0xb, DAT_a807db00[p].regs0 + 8 / 4);
        FUN_a00a73ac(0xd, DAT_a807db00[p].regs);
        DAT_a807db00[p].regs[0x60 / 4] = 1;
        if (DAT_a807d680[p].n == 3) {
            FUN_a00a73d4(8, DAT_a807db00[p].regs);
            FUN_a00a7488(ch, 0x2e70, 0xffffffff, 0xc000);
        } else {
            FUN_a00a73ac(8, DAT_a807db00[p].regs);
            FUN_a00a7488(ch, 0x2e70, 0xffff3fff, 0);
        }
        FUN_a00a73ac(8, DAT_a807db00[p].regs0 + 4 / 4);
        FUN_a00b1794(1);
        FUN_a00a73d4(8, DAT_a807db00[p].regs0 + 4 / 4);
        DAT_a8079082[p] = 0;
        DAT_a8079080[p] = 0;
    }
    if (FUN_a008d800() > 0x82 && ((DAT_a807db00[port & 0xff].regs[0xb0 / 4] >> 8) & 0xff) != 0xff) {
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4(s_a006a368);
        do {
            t = (DAT_a807db00[port & 0xff].regs[0xb0 / 4] & 0xffff00ff) | 0xff00;
        } while (once);
        DAT_a807d648[port & 0xff] = 3;
        DAT_a807db00[port & 0xff].regs[0xb0 / 4] = t;
        return 0;
    }
    if (((DAT_a807db00[port & 0xff].regs[0x90 / 4] >> 24) & 0xf) != DAT_a807d680[port & 0xff].rate) {
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4(s_a006a3a0);
        DAT_a807d648[port & 0xff] = 3;
        if (FUN_a008d800() > 0x82)
            DAT_a807db00[port & 0xff].regs[0xb0 / 4] = (DAT_a807db00[port & 0xff].regs[0xb0 / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }
    if (FUN_a00a7408(5, DAT_a807db00[port & 0xff].regs + 0x80 / 4) == 0) {
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4(s_a006a3c8);
    } else {
        if (DAT_a8079082[port & 0xff] == 0 && (DAT_a8078634 & 0x800))
            FUN_a00734c4(s_a006a3f0);
        if (++DAT_a8079082[port & 0xff] >= 300) {
            DAT_a8079082[port & 0xff] = 0;
            if (FUN_a00a7408(0x11, DAT_a807db00[port & 0xff].regs + 0x90 / 4)) {
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006a408);
            } else {
                if (DAT_a8078634 & 0x800)
                    FUN_a0073044(s_a006a420, port & 0xff, DAT_a8079082[port & 0xff]);
            }
        }
        return 0;
    }
    if (DAT_a8079052 == 0) {
        if (DAT_a807d680[port & 0xff].n == 3) {
            if (((FUN_a00a7314(ch, 0x2e60) >> 24) & 0xf) == 7) {
                ok = 1;
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006a440);
            } else {
                ok = 0;
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006a460);
            }
        } else if (DAT_a807d680[port & 0xff].n == 4) {
            if (((FUN_a00a7314(ch, 0x2e60) >> 24) & 0xf) == 0xf) {
                ok = 1;
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006a480);
            } else {
                ok = 0;
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006a4a0);
            }
        }
        if (ok) {
            if (DAT_a8078634 & 0x800)
                FUN_a0073044(s_a006a4c0, DAT_a807db00[port & 0xff].regs[0x38 / 4] & 0xffff,
                             (DAT_a807db00[port & 0xff].ced[0] & 0x7fff) + (DAT_a807db00[port & 0xff].ced[1] & 0x7fff)
                             + (DAT_a807db00[port & 0xff].ced[2] & 0x7fff) + (DAT_a807db00[port & 0xff].ced[3] & 0x7fff));
            port &= 0xff;
            if ((DAT_a807db00[port].regs[0x38 / 4] & 0xffff) == 0x8000 || DAT_a8079080[port] > 5) {
                FUN_a00a73ac(4, DAT_a807db00[port].regs + 0x80 / 4);
                FUN_a00a73d4(0x15, DAT_a807db00[port].regs0 + 4 / 4);
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006a508);
            } else {
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006a528);
                DAT_a807db00[port].regs[0x34 / 4] |= 0xffff;
                DAT_a807db00[port].regs[0x38 / 4] |= 0xffff;
                *(DAT_a807d648 + port) = 6;
                DAT_a8079080[port]++;                return 0;
            }
            DAT_a8079080[port] = 0;
            t = DAT_a807906c[port] = FUN_a00b2064();
            DAT_a807d680[port].b37 = 0;
            FUN_a0073044(DAT_a006a548, t - DAT_a8079074[port], DAT_a8079074[port], t);
            FUN_a007ab94(ch);
            if ((unsigned char)(DAT_a807d680[port].rate - 5) <= 1) {
                DRV_HDMI21_IQ_Scan_byCED(ch);
                FUN_a00798fc(ch);
                FUN_a00b1794(1);
                FUN_a00799b8(ch);
                DAT_a807d648[port] = 9;
                DAT_a807d680[port].b2c = 0;
            } else {
                DRV_HDMI21_ReStart_AEQ2(ch, 0, 1, 0);
                DAT_a807d648[port] = 8;
            }
        } else {
            if (++DAT_a807d680[port & 0xff].b2b == 3) {
                DAT_a807d680[port & 0xff].b2b = 0;
                DRV_HDMI21_PHY_PICDR_Reset(ch);
                if (FUN_a008d800() <= 0x82 && SR_detect_fail_ch(port & 0xff))
                    DAT_a807d648[port & 0xff] = 3;
            }
        }
    } else {
        FUN_a00a73ac(4, DAT_a807db00[port & 0xff].regs + 0x80 / 4);
        DAT_a807d648[port & 0xff] = 9;
        DAT_a807d680[port & 0xff].b2c = 0;
        FUN_a00734c4(s_a006a578);
    }
    return 0;
}
