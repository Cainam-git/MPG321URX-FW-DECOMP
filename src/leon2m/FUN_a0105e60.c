/* leon2m FUN_a0105e60 @ 0xa0105e60-0xa01061c0 (216 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u16 w, u16 h, u16 f). Reads hardware register 0xCF01166C (value discarded). Searches the 8 18-byte rows
 * of the table at 0x19A640 for the first row i with (u16)(row.h6 - w) < row.h6 / 10, (u16)(row.he - h) <
 * row.he / 10 and row.h10 - f + 9 <= 18 (unsigned); none found prints s_0019a8c0 ("drv_Set3DDEISC no match
 * timing\n") and uses row 2. Prints s_0019a8e8 ("index=%x %d %d\n") with i, w, h. n = row.h0 rounded up to a
 * multiple of 8; w2 = w, halved when w > 0x780. Then writes block 5 through FUN_a00f2298 (byte) and FUN_a00f2488
 * (halfword): 0x25 = 0x1a, 0x18 = h, 0x1a = w, 0x24 = 0, 0x54 = 0, 0x5b = row.h8, 0xbe = row.ha, 0x5e = n,
 * 0xa0 = row.h2, 0x62 = row.hc, 0x64 = h, 0x66 = row.h4, 0x68 = w2, 0x6e = 7, 0x6f = row.hc, 0x71 = h,
 * 0x73 = row.h4, 0x75 = w2, 0x79 = n, then fixed bytes to 0x55, 0x88, 0x90, 0x95, 0x50, 0x7d, 0x4b, 0x61, 0xa4,
 * 0x86, 0x8d, 0x59.
 * Source form: the row.h0 reads index the table directly, the row pointer is taken again before the 0x5b write;
 *   row.hc and row.h4 are read once into locals; w is copied to an unsigned int for the print and the 0x1a write
 *   and to a separate halfword w2 for the halving. The 0xCF01166C read is volatile (hardware register).
 */
struct Tm { unsigned short h0, h2, h4, h6, h8, ha, hc, he, h10; };
extern const struct Tm DAT_0019a640[];
extern const char s_0019a8c0[], s_0019a8e8[];
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);

#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a0105e60(unsigned short w, unsigned short h, unsigned short f)
{
    unsigned char i;
    unsigned short n;
    unsigned int v;
    unsigned short w2;
    const struct Tm *t;
    unsigned short c, e;

    REG(0xcf01166c);
    for (i = 0; i < 8; i++) {
        t = &DAT_0019a640[i];
        if ((unsigned short)(t->h6 - w) < t->h6 / 10 && (unsigned short)(t->he - h) < t->he / 10 &&
            (unsigned int)(t->h10 - f + 9) <= 18)
            break;
    }
    if (i == 8) {
        FUN_a00df170(s_0019a8c0);
        i = 2;
    }
    v = w;
    FUN_a00df170(s_0019a8e8, i, v, h);
    n = DAT_0019a640[i].h0 >> 3;
    if (DAT_0019a640[i].h0 & 7)
        n++;
    n <<= 3;
    w2 = w;
    if (v > 0x780)
        w2 >>= 1;
    FUN_a00f2298(5, 0x25, 0x1a);
    FUN_a00f2488(5, 0x18, h);
    FUN_a00f2488(5, 0x1a, v);
    FUN_a00f2298(5, 0x24, 0);
    FUN_a00f2298(5, 0x54, 0);
    t = &DAT_0019a640[i];
    FUN_a00f2488(5, 0x5b, t->h8);
    FUN_a00f2488(5, 0xbe, t->ha);
    FUN_a00f2488(5, 0x5e, n);
    FUN_a00f2488(5, 0xa0, t->h2);
    c = t->hc;
    FUN_a00f2488(5, 0x62, c);
    FUN_a00f2488(5, 100, h);
    e = t->h4;
    FUN_a00f2488(5, 0x66, e);
    FUN_a00f2488(5, 0x68, w2);
    FUN_a00f2298(5, 0x6e, 7);
    FUN_a00f2488(5, 0x6f, c);
    FUN_a00f2488(5, 0x71, h);
    FUN_a00f2488(5, 0x73, e);
    FUN_a00f2488(5, 0x75, w2);
    FUN_a00f2488(5, 0x79, n);
    FUN_a00f2298(5, 0x55, 0);
    FUN_a00f2298(5, 0x88, 2);
    FUN_a00f2298(5, 0x90, 0);
    FUN_a00f2298(5, 0x95, 0x40);
    FUN_a00f2298(5, 0x50, 0xc1);
    FUN_a00f2298(5, 0x7d, 200);
    FUN_a00f2298(5, 0x4b, 8);
    FUN_a00f2298(5, 0x61, 0x2e);
    FUN_a00f2298(5, 0xa4, 0);
    FUN_a00f2298(5, 0x86, 0x84);
    FUN_a00f2298(5, 0x8d, 0x20);
    FUN_a00f2298(5, 0x59, 0x83);
}
