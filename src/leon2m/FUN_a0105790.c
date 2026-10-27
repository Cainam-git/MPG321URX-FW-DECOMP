/* leon2m FUN_a0105790 @ 0xa0105790-0xa0105910 (384 bytes), flags -mcpu=v8 -O3 -g.
 * Returns at once unless bit 0 of FUN_a00f2254(ch, 0x88) is set. d = FUN_a00f25f8(ch, 0x5e); for ch < 4,
 * b = DAT_a802d680 byte +0x15 + ch and h = halfword +0x1a + 2 * ch, else both 0; t = b * r->h8 + h * 8.
 * q = (64-bit) t * (c.d18 / 1000000) / div (both divisions through __udivdi3, FUN_a0155208), low 32 bits kept.
 * n = q / d for ch 1, else q / d + 1; n is raised to at least 3 for ch 0 and to at least 2 otherwise.
 * Then FUN_a00f2488(ch, 0x62, n), FUN_a00f2488(ch, 0x6f, n) and FUN_a00f2488(ch, 0xbe, 1) (tail call).
 * Called by FUN_a01312d4, which passes the 40-byte record c by value (a pointer to a stack copy).
 * Source form: FUN_a00f25f8 declared with an int result (d is extended where it is used); h is an unsigned int
 * (the lduh value is shifted without a new extension); n is an unsigned short.
 */
struct OutCfg { unsigned char p00[0x15]; unsigned char lvl[4]; unsigned char p19; unsigned short rate[4]; };
struct Rec { unsigned char p0[8]; unsigned short h8; };
struct Clk { unsigned long long d0, d8, d10, d18, d20; };
extern struct OutCfg DAT_a802d680;
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern int FUN_a00f25f8(unsigned char blk, unsigned char reg);
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);

void FUN_a0105790(unsigned char ch, unsigned short div, struct Rec *r, struct Clk c)
{
    unsigned short w, d, n;
    unsigned char b;
    unsigned int h;
    unsigned int t, q;

    if (!(FUN_a00f2254(ch, 0x88) & 1))
        return;
    w = r->h8;
    d = FUN_a00f25f8(ch, 0x5e);
    b = 0;
    h = 0;
    if (ch < 4) {
        b = DAT_a802d680.lvl[ch];
        h = DAT_a802d680.rate[ch];
    }
    t = b * w + h * 8;
    q = (unsigned long long)t * (c.d18 / 1000000) / div;
    if (ch == 1)
        n = q / d;
    else
        n = q / d + 1;
    if (ch == 0) {
        if (n < 3)
            n = 3;
    } else {
        if (n < 2)
            n = 2;
    }
    FUN_a00f2488(ch, 0x62, n);
    FUN_a00f2488(ch, 0x6f, n);
    FUN_a00f2488(ch, 0xbe, 1);
}
