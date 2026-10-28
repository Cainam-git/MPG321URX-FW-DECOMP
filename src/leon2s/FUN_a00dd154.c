/* FUN_a00dd154 (leon2s 0xa00dd154-0xa00dd37c, 552 bytes), flags -mcpu=v8 -Os -g.
 * void (unsigned int port). Prints s_9f1ceca0 ("input DSC Encoder's deepcolor = %d") with byte +4 of
 * DAT_a8079538 through func_0xa0f83044. w = bits 16..25 of 0xc0110004; byte +7 of DAT_a8079538 selects the
 * divisor: 0, 3 or 4: 24 / (w >> 4); 1: 16 / (w >> 5) rounded up; others: 12 / (w >> 5) rounded up.
 * Low byte of port <= 1: factors 2 and 1. Otherwise, with x = low nibble of func_0xa0fb78b4(0, 3):
 * func_0xa0f99e4c(0) low byte 1: 4 and 1; x 4: 2 and 1; x 2: 4 and 3; x 1: 2 and 3; others: 0 and 1.
 * Word +0x20: shift = bits 0..1, plus 1 when bit 7 is set; value = bits 8..15 + (bits 16..23 << 8) +
 * (bits 24..31 << 16); r = (value << shift) / divisor / (factor 1 * factor 2).
 * Clears bit 7 of 0xcf014100, writes the low byte of r >> 1, r >> 9 and r >> 17 to 0xcf014104, 0xcf014108
 * and 0xcf01410c, then sets bit 7 of 0xcf014114.
 * Source form: the word +0x20 is read into its own variable t; its three upper bytes go into unsigned int
 * locals a, b and c before the sum a + (b << 8) + (c << 16).
 */
struct Rec538 {
    unsigned char _0[4];
    unsigned char deepcolor;
    unsigned char _5[2];
    unsigned char b7;
    unsigned char _8[0x18];
    unsigned int w20;
};
extern struct Rec538 DAT_a8079538;
extern const char s_9f1ceca0[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned int func_0xa0fb78b4(unsigned int, unsigned int);
extern unsigned int func_0xa0f99e4c(unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00dd154(unsigned int port)
{
    unsigned char cf, div, mul = 0, mul2 = 1, x, sh;
    unsigned short w;
    int q, num;
    unsigned int v, t, r;
    unsigned int a, b, c;

    cf = DAT_a8079538.b7;
    func_0xa0f83044(s_9f1ceca0, DAT_a8079538.deepcolor);
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
    if ((port & 0xff) <= 1) {
        mul = 2;
        mul2 = 1;
    } else {
        x = func_0xa0fb78b4(0, 3) & 0xf;
        if ((func_0xa0f99e4c(0) & 0xff) == 1) {
            mul = 4;
            mul2 = 1;
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
    }
    t = DAT_a8079538.w20;
    sh = t & 3;
    if (t & 0x80)
        sh++;
    a = (t >> 8) & 0xff;
    b = (t >> 16) & 0xff;
    c = t >> 24;
    v = a + (b << 8) + (c << 16);
    r = (v << sh) / div / (mul * mul2);
    R(0xcf014100) &= ~0x80;
    v = r >> 1;
    R(0xcf014104) = v & 0xff;
    R(0xcf014108) = (r >> 9) & 0xff;
    R(0xcf01410c) = (r >> 17) & 0xff;
    R(0xcf014114) |= 0x80;
}
