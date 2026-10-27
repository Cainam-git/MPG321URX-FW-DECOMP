/* leon2s FRL_PLL @ 0xa0096538-0xa00967ec, -mcpu=v8 -Os -g.
 * void (port, rate). p = low byte of port, sel = 3 for p 1, else 2. rate above 0x3bb: DAT_a80790a8[p] = 1 and
 * FUN_a009645c(p, rate in 941..979); otherwise DAT_a80790a8[p] = 0 and FUN_a009645c(p, rate in 470..490).
 * FUN_a00964d0(p, 4, 2, 0x117) when rate >> DAT_a80790a8[p] is at most 0x31f, else (p, 5, 2, 0x100). With
 * DAT_a80790a8[p] set: FUN_a00a73ac / FUN_a00a73d4 bit steps 0xc, 0xd, 0xf on word 2 and 8 on word 1 of the
 * register block r0 of the 0x34-byte record DAT_a807db00[p], with a FUN_a00b1794(1) wait. Halfwords +8 and +0xa
 * of the 0x18-byte record ARR_a807cc64[sel] = rate; prints "Port%c FRL_PLL Target %dM, FRL Rate %d,
 * 2PortMode=%d" with (u16)rate, byte +1 of ARR_a807d680[p] and DAT_a80790a8[p]. rate != 0: word 0x58 of the
 * block r18 = ((0x3c00000 / rate) << 9) | 0x1c, bit 8 pulsed, low byte = 4. rate <= 0x32: fixed values into
 * the fields of words 0x44, 0x4c, 0x40 of r18, FUN_a00a73d4(0xe, r18) and the top byte of word 4 = 0x39.
 * Source forms: each rate-range arm holds its own store and call; the +0xa halfword is stored first.
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned char _04[0x14];
    volatile unsigned int *r18;
    unsigned char _1c[0x34 - 0x1c];
};
struct sel_rec {
    unsigned char _0[8];
    unsigned short h8;
    unsigned short ha;
    unsigned char _c[0x18 - 0xc];
};
struct scdc_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0xb0 - 2];
};
extern struct port_rec DAT_a807db00[];
extern struct sel_rec ARR_a807cc64[];
extern struct scdc_rec ARR_a807d680[];
extern unsigned char DAT_a80790a8[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a009645c(unsigned char, unsigned char);
extern void FUN_a00964d0(unsigned char, unsigned int, unsigned int, unsigned int);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern void FUN_a00b1794(unsigned short);

void FRL_PLL(unsigned int arg, unsigned int rate)
{
    unsigned char p = arg;
    unsigned char sel = 2;
    volatile unsigned int *r;

    if (p == 1)
        sel = 3;
    if (rate > 0x3bb) {
        DAT_a80790a8[p] = 1;
        if (rate - 941 <= 0x26)
            FUN_a009645c(p, 1);
        else
            FUN_a009645c(p, 0);
    } else if (rate - 470 <= 0x14) {
        DAT_a80790a8[p] = 0;
        FUN_a009645c(p, 1);
    } else {
        DAT_a80790a8[p] = 0;
        FUN_a009645c(p, 0);
    }
    if ((rate >> DAT_a80790a8[p]) <= 0x31f)
        FUN_a00964d0(p, 4, 2, 0x117);
    else
        FUN_a00964d0(p, 5, 2, 0x100);
    if (DAT_a80790a8[p] != 0) {
        FUN_a00a73ac(0xc, DAT_a807db00[p].r0 + 2);
        FUN_a00a73d4(0xd, DAT_a807db00[p].r0 + 2);
        FUN_a00a73ac(0xf, DAT_a807db00[p].r0 + 2);
        FUN_a00a73ac(8, DAT_a807db00[p].r0 + 1);
        FUN_a00b1794(1);
        FUN_a00a73d4(8, DAT_a807db00[p].r0 + 1);
    }
    ARR_a807cc64[sel].ha = rate;
    ARR_a807cc64[sel].h8 = rate;
    FUN_a0073044("Port%c FRL_PLL Target %dM, FRL Rate %d, 2PortMode=%d\n", (char)(arg + 'A'), (unsigned short)rate,
                 ARR_a807d680[p].b1, DAT_a80790a8[p]);
    if (rate != 0) {
        DAT_a807db00[p].r18[0x58 / 4] = ((0x3c00000 / rate) << 9) | 0x1c;
        FUN_a00a73ac(8, DAT_a807db00[p].r18 + 0x16);
        FUN_a00a73d4(8, DAT_a807db00[p].r18 + 0x16);
        DAT_a807db00[p].r18[0x58 / 4] = (DAT_a807db00[p].r18[0x58 / 4] & ~0xff) | 4;
    }
    if (rate <= 0x32) {
        r = DAT_a807db00[p].r18;
        r[0x44 / 4] = (r[0x44 / 4] & 0xffffff) | 0xb8000000;
        r[0x4c / 4] = (r[0x4c / 4] & 0xffff0000) | 0x40;
        r[0x40 / 4] = (r[0x40 / 4] & 0xff0000ff) | 0x20000;
        r[0x40 / 4] &= 0xffffff;
        r[0x44 / 4] = (r[0x44 / 4] & ~0xff) | 0x70;
        FUN_a00a73d4(0xe, r);
        DAT_a807db00[p].r18[1] = (DAT_a807db00[p].r18[1] & 0xffff) | 0x39000000;
    }
}
