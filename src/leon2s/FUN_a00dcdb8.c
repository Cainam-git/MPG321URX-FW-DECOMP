/* FUN_a00dcdb8 (leon2s 0xa00dcdb8-0xa00dd154, 924 bytes), flags -mcpu=v8 -Os -g.
 * void (unsigned int port); called by FUN_a00dd37c. w = bits 16..25 of 0xc0110004; byte +7 of DAT_a8079538
 * selects the divisor div (0, 3 or 4: 24 / (w >> 4); 1: 16 / (w >> 5) rounded up; others: 12 / (w >> 5) rounded up),
 * as in FUN_a00dd154. Clears 0xc0118000. Low byte of port <= 1: r = 4, factors 2 and 1; otherwise x = low nibble of
 * func_0xa0fb78b4(0, 3), s = low byte of func_0xa0f99e4c(0), r = 3, factors from s and x as in FUN_a00dd154, and
 * 0xc0118000 = x << 4 | s | 0x100. Then writes 0xc0120914 = 0x12000210, 0xc0120918 = 0xffff0000 and, each after an
 * AND of the register with 0xffff or 0, 0xc012091c..0xc012092c from the halfwords +8..+0x16 of DAT_a8079538 divided
 * by div and mul and multiplied by mul2 (high half) and the low halfword values; 0xc0120948 = h8 >> 2,
 * 0xc0120978 = 0, 0xc0122010 = h8 >> 3.
 * Source form: every value read or computed into a local before the register writes, in the order h8 (t),
 * the 0x920 high quotient (unsigned int q), the 0x91c quotient (unsigned int q0), the 0x928 quotient (unsigned
 * short q3), the 0x924 low quotient (unsigned short v, reused for the 0xc0122010 value), h14 and h12 (unsigned
 * short); h14 is read once and used in 0x920 and in the 0x924 sum; each register is written as 'R &= keep' then
 * the value composed at its write.
 */
struct Rec538 {
    unsigned char _0[7];
    unsigned char b7;
    unsigned short h8;
    unsigned short ha;
    unsigned short hc;
    unsigned short he;
    unsigned short h10;
    unsigned short h12;
    unsigned short h14;
    unsigned short h16;
};
extern struct Rec538 DAT_a8079538;
extern unsigned int func_0xa0fb78b4(unsigned int, unsigned int);
extern unsigned int func_0xa0f99e4c(unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00dcdb8(unsigned int port)
{
    unsigned char cf, div, mul = 0, mul2 = 1, x, s, r;
    unsigned short w, t, v, lo3, h14;
    unsigned int q;
    unsigned int q0;
    unsigned short q3;

    cf = DAT_a8079538.b7;
    w = (R(0xc0110004) >> 16) & 0x3ff;
    if (cf == 0 || cf == 3 || cf == 4)
        div = 24 / (w >> 4);
    else if (cf == 1) {
        w >>= 5;
        div = (16 % w == 0) ? 16 / w : 16 / w + 1;
    } else {
        w >>= 5;
        div = (12 % w == 0) ? 12 / w : 12 / w + 1;
    }
    R(0xc0118000) = 0;
    if ((port & 0xff) <= 1) {
        r = 4;
        mul = 2;
        mul2 = 1;
    } else {
        x = func_0xa0fb78b4(0, 3) & 0xf;
        s = func_0xa0f99e4c(0);
        r = 3;
        if (s == 1) {
            if (x == 4) {
                mul = 4;
                mul2 = 1;
            }
        } else if (x == 4) {
            mul = 2;
            mul2 = 1;
        } else if (x == 2) {
            mul = 4;
            mul2 = 3;
        } else if (x == 1) {
            mul = 2;
            mul2 = 3;
        }
        R(0xc0118000) = (x << 4) | s | 0x100;
    }
    t = DAT_a8079538.h8;
    q = DAT_a8079538.hc / div / mul * mul2;
    q0 = t / div / mul * mul2;
    q3 = DAT_a8079538.ha / div / mul * mul2;
    v = (DAT_a8079538.he + DAT_a8079538.hc) / div / mul * mul2;
    h14 = DAT_a8079538.h14;
    lo3 = DAT_a8079538.h12;
    R(0xc0120914) = 0x12000210;
    R(0xc0120918) = 0xffff0000;
    R(0xc012091c) &= 0xffff;
    R(0xc012091c) = (q0 << 16) | 0xffff;
    R(0xc0120920) &= 0;
    R(0xc0120920) = (q << 16) | h14;
    R(0xc0120924) &= 0;
    R(0xc0120924) = v | ((unsigned int)((unsigned short)(DAT_a8079538.h16 + h14) + r) << 16);
    R(0xc0120928) &= 0;
    R(0xc0120928) = q3 | ((unsigned int)q3 << 16);
    R(0xc012092c) &= 0;
    R(0xc012092c) = lo3;
    t >>= 2;
    v = t >> 1;
    R(0xc0120948) = t;
    R(0xc0120978) = 0;
    R(0xc0122010) = v;
}
