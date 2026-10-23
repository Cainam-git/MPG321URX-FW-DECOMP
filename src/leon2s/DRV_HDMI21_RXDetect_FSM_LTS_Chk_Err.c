/* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err (leon2s 0xa009ec38-0xa009f5c8, 2448 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Ports 0 and 1 only (p = (u8)port, PHY page ch = 2 / 3); returns 0. Copies the state word DAT_a807d648[p] to
 * word +0x30 of the 0xb0-byte record DAT_a807d680[p] when they differ (print DAT_a0067868 with the function
 * name s_a00b4530, bit 11 of DAT_a8078634). regs = word +0x18 of the 0x34-byte record DAT_a807db00[p].
 * Bits 27..24 of regs word 0x90 zero: clears the four lane fields (bits 27..24 / 31..28 of word 0xa0, 3..0 /
 * 7..4 of word 0xa4), prints s_a006b010, state 7. Otherwise, when bit 5 of regs + 0x80 is set
 * (FUN_a00a7408): the u16 counter DAT_a807908a[p] counts (print s_a006b070 at 0); at 300 it is cleared and
 * either s_a0069ca8 is printed (bit 17 of regs + 0x90 set) or s_a006b098 (p, counter) and state 0.
 * When it is clear: prints s_a006b048 and s_a006b0d0 (field value); a zero field clears the lane fields
 * (print s_a006b0f0, state 7); a value of 7 or more prints s_a006b120, sets every lane field below the lane
 * count (record byte 0) to 0xf, FUN_a00a73ac(5, regs + 0x80), state 3. Below 7: a value different from record
 * byte +2 calls TxFFE_Max_L, stores it there, sets DAT_a80790d8[p] = 1 when FUN_a008d800() <= 0x82, record
 * byte +0x34 = (byte +1 >= 4), FUN_a009ec20(p, value), FUN_a00b1794(1), DRV_HDMI21_Set_PHY(ch, value) and a
 * print. Then r = SR_detect_fail_ch(port) unless DAT_a8079052 is set: r == 0 sets the byte at regs + 0xb1 to
 * 0xff when FUN_a008d800() > 0x82, clears the lane fields, FUN_a00a73ac(5, regs + 0x80), print, state 6 and
 * clears record byte +0x2b; record byte +0x13 == 0 gives state 3; else every lane bit set in r increments the
 * lane counter at record byte +0xf + lane (wrapping to 0 at a multiple of byte +0x13 plus 1) and writes 0xe to
 * its field, with a print per lane, then FUN_a00a73ac(5, regs + 0x80), state 3, DAT_a807906c[p] =
 * FUN_a00b2064() and a print of its difference to DAT_a8079074[p].
 * Source form: as DRV_HDMI21_RXDetect_FSM_LTS_3 (same file, -msoft-float, clear_fields helper with the raw
 * port, record accesses through DAT_a807db00[port & 0xff]); the tests whose short arm comes first in the
 * firmware are written that way round (FUN_a00a7408 == 0, field == 0, value >= 7); state 7 is written in both
 * zero-field arms; the field value is (word & 0xf000000) >> 24; FUN_a009ec20 is called without a prototype
 * (the unsigned int port & 0xff is passed as is; the callee masks its u8 parameters itself).
 */
struct Port {
    volatile unsigned int *regs0;
    unsigned char _04[0x18 - 4];
    volatile unsigned int *regs;
    unsigned char _1c[0x34 - 0x1c];
};
struct Rec {
    unsigned char n;
    unsigned char b1;
    unsigned char rate;
    unsigned char _03[0xc];
    unsigned char ffe[4];
    unsigned char b13;
    unsigned char _14[0x2b - 0x14];
    unsigned char b2b;
    unsigned char _2c[4];
    unsigned int state;
    unsigned char b34;
    unsigned char _35[0xb0 - 0x35];
};

extern struct Port DAT_a807db00[];
extern struct Rec DAT_a807d680[];
extern unsigned int DAT_a807d648[];
extern unsigned char DAT_a80790d8[];
extern unsigned short DAT_a807908a[];
extern unsigned char DAT_a8079052;
extern unsigned int DAT_a807906c[];
extern unsigned int DAT_a8079074[];
extern unsigned int DAT_a8078634;
extern const char DAT_a0067868[], s_a00b4530[], s_a006b010[], s_a006b048[], s_a006b070[], s_a0069ca8[],
    s_a006b098[], s_a006b0d0[], s_a006b0f0[], s_a006b120[], s_a006b158[], s_a006b188[], s_a006b1c0[],
    s_a006b1e0[];

extern unsigned char FUN_a008d800(void);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void TxFFE_Max_L(unsigned int);
extern void FUN_a009ec20();
extern void FUN_a00b1794(unsigned short);
extern void DRV_HDMI21_Set_PHY(unsigned char, unsigned char);
extern unsigned char SR_detect_fail_ch(unsigned char);
extern unsigned int FUN_a00b2064(void);

static inline void clear_fields(unsigned int port)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (i == 0)
            DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0xf0ffffff;
        else if (i == 1)
            DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0x0fffffff;
        else if (i == 2)
            DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf;
        else if (i == 3)
            DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf0;
    }
}

int DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err(unsigned int port)
{
    unsigned char p = port;
    unsigned char ch;
    unsigned char i;
    unsigned char r;

    if (p == 0)
        ch = 2;
    else if (p == 1)
        ch = 3;
    else
        return 0;
    if (DAT_a807d648[p] != DAT_a807d680[p].state) {
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(DAT_a0067868, s_a00b4530);
        DAT_a807d680[p].state = DAT_a807d648[p];
    }
    if (((DAT_a807db00[p].regs[0x90 / 4] >> 24) & 0xf) == 0) {
        clear_fields(port);
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4(s_a006b010);
        DAT_a807d648[port & 0xff] = 7;
        return 0;
    } else {
        if (FUN_a00a7408(5, DAT_a807db00[p].regs + 0x80 / 4) == 0) {
            if (DAT_a8078634 & 0x800)
                FUN_a00734c4(s_a006b048);
        } else {
            if (DAT_a807908a[p] == 0 && (DAT_a8078634 & 0x800))
                FUN_a00734c4(s_a006b070);
            if (++DAT_a807908a[p] >= 300) {
                DAT_a807908a[p] = 0;
                if (FUN_a00a7408(0x11, DAT_a807db00[p].regs + 0x90 / 4)) {
                    FUN_a00734c4(s_a0069ca8);
                } else {
                    if (DAT_a8078634 & 0x800)
                        FUN_a0073044(s_a006b098, p, DAT_a807908a[p]);
                    DAT_a807d648[p] = 0;
                }
            }
            return 0;
        }
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(s_a006b0d0, (DAT_a807db00[p].regs[0x90 / 4] >> 24) & 0xf);
        if ((DAT_a807db00[port & 0xff].regs[0x90 / 4] & 0xf000000) == 0) {
            clear_fields(port);
            if (DAT_a8078634 & 0x800)
                FUN_a00734c4(s_a006b0f0);
            DAT_a807d648[port & 0xff] = 7;
            return 0;
        } else {
            if (((DAT_a807db00[port & 0xff].regs[0x90 / 4] & 0xf000000) >> 24) >= 7) {
                if (DAT_a8078634 & 0x800)
                    FUN_a00734c4(s_a006b120);
                for (i = 0; i < DAT_a807d680[port & 0xff].n; i++) {
                    if (i == 0)
                        DAT_a807db00[port & 0xff].regs[0xa0 / 4] = (DAT_a807db00[port & 0xff].regs[0xa0 / 4] & 0xf0ffffff) | 0xf000000;
                    else if (i == 1)
                        DAT_a807db00[port & 0xff].regs[0xa0 / 4] = (DAT_a807db00[port & 0xff].regs[0xa0 / 4] & 0x0fffffff) | 0xf0000000;
                    else if (i == 2)
                        DAT_a807db00[port & 0xff].regs[0xa4 / 4] = (DAT_a807db00[port & 0xff].regs[0xa4 / 4] & ~0xf) | 0xf;
                    else if (i == 3)
                        DAT_a807db00[port & 0xff].regs[0xa4 / 4] = (DAT_a807db00[port & 0xff].regs[0xa4 / 4] & ~0xf0) | 0xf0;
                }
                FUN_a00a73ac(5, DAT_a807db00[port & 0xff].regs + 0x80 / 4);
                DAT_a807d648[port & 0xff] = 3;
            } else {
                if (((DAT_a807db00[port & 0xff].regs[0x90 / 4] & 0xf000000) >> 24) != DAT_a807d680[port & 0xff].rate) {
                    TxFFE_Max_L(port & 0xff);
                    DAT_a807d680[port & 0xff].rate = (DAT_a807db00[port & 0xff].regs[0x90 / 4] & 0xf000000) >> 24;
                    if (FUN_a008d800() <= 0x82)
                        DAT_a80790d8[port & 0xff] = 1;
                    if (DAT_a807d680[port & 0xff].b1 >= 4)
                        DAT_a807d680[port & 0xff].b34 = 1;
                    else
                        DAT_a807d680[port & 0xff].b34 = 0;
                    FUN_a009ec20(port & 0xff, DAT_a807d680[port & 0xff].rate);
                    FUN_a00b1794(1);
                    DRV_HDMI21_Set_PHY(ch, DAT_a807d680[port & 0xff].rate);
                    if (DAT_a8078634 & 0x800)
                        FUN_a0073044(s_a006b158, DAT_a807d680[port & 0xff].rate);
                }
                r = 0;
                if (DAT_a8079052 == 0)
                    r = SR_detect_fail_ch(port);
                if (r == 0) {
                    if (FUN_a008d800() > 0x82)
                        DAT_a807db00[port & 0xff].regs[0xb0 / 4] = (DAT_a807db00[port & 0xff].regs[0xb0 / 4] & 0xffff00ff) | 0xff00;
                    for (i = 0; i < 4; i++) {
                        if (i == 0)
                            DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0xf0ffffff;
                        else if (i == 1)
                            DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0x0fffffff;
                        else if (i == 2)
                            DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf;
                        else if (i == 3)
                            DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf0;
                    }
                    FUN_a00a73ac(5, DAT_a807db00[port & 0xff].regs + 0x80 / 4);
                    if (DAT_a8078634 & 0x800)
                        FUN_a0073044(s_a006b188, DAT_a807d680[port & 0xff].rate);
                    DAT_a807d648[port & 0xff] = 6;
                    DAT_a807d680[port & 0xff].b2b = 0;
                } else if (DAT_a807d680[port & 0xff].b13 == 0) {
                    DAT_a807d648[port & 0xff] = 3;
                } else {
                    for (i = 0; i < DAT_a807d680[port & 0xff].n; i++) {
                        if ((r >> i) & 1) {
                            DAT_a807d680[port & 0xff].ffe[i]++;
                            if (i == 0)
                                DAT_a807db00[port & 0xff].regs[0xa0 / 4] = (DAT_a807db00[port & 0xff].regs[0xa0 / 4] & 0xf0ffffff) | 0xe000000;
                            else if (i == 1)
                                DAT_a807db00[port & 0xff].regs[0xa0 / 4] = (DAT_a807db00[port & 0xff].regs[0xa0 / 4] & 0x0fffffff) | 0xe0000000;
                            else if (i == 2)
                                DAT_a807db00[port & 0xff].regs[0xa4 / 4] = (DAT_a807db00[port & 0xff].regs[0xa4 / 4] & ~0xf) | 0xe;
                            else if (i == 3)
                                DAT_a807db00[port & 0xff].regs[0xa4 / 4] = (DAT_a807db00[port & 0xff].regs[0xa4 / 4] & ~0xf0) | 0xe0;
                            if (DAT_a807d680[port & 0xff].ffe[i] % (DAT_a807d680[port & 0xff].b13 + 1) == 0)
                                DAT_a807d680[port & 0xff].ffe[i] = 0;
                        }
                        if (DAT_a8078634 & 0x800)
                            FUN_a0073044(s_a006b1c0, i, DAT_a807d680[port & 0xff].ffe[i]);
                    }
                    FUN_a00a73ac(5, DAT_a807db00[port & 0xff].regs + 0x80 / 4);
                    DAT_a807d648[port & 0xff] = 3;
                    DAT_a807906c[port & 0xff] = FUN_a00b2064();
                    FUN_a0073044(s_a006b1e0, DAT_a807906c[port & 0xff] - DAT_a8079074[port & 0xff]);
                }
            }
            return 0;
        }
    }
}
