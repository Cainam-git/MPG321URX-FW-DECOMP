/* leon2m FUN_a012043c @ 0xa012043c-0xa01205c0 (388 bytes).
 * Block blk of the register family with block bases DAT_001a2fb0[2] (register n at 0xcf000000 + 4 * n; blk > 1
 * is treated as 0); every register read first sets bits 0-1 of register 0xcf011428. Reads register base + 0x50
 * (x) and base + 0x51 (y). If bit 0 of y is set it returns 0. Otherwise it clears both halfwords of
 * DAT_a802d844[blk] (element 0 first) and, for i < (unsigned char)(4 << (x >> 6)), reads register base + 0x57
 * three times (a, b, c) and stores out[i] = (c << 16) | (b << 8) | a; then returns 1. No direct callers found.
 * Source form: the byte read helper rd8 (FUN_a01207ac's helper with the 0xcf011428 write before the clamp) inlined;
 * the count n computed between the two reads; DAT_a802d844 as an array of unsigned short pairs, so the two clears
 * keep their order in the scheduler.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short DAT_001a2fb0[2];
extern unsigned short DAT_a802d844[][2];

static unsigned char rd8(unsigned int blk, unsigned char reg)
{
    R(0xcf011428) |= 3;
    if (blk > 1)
        blk = 0;
    return RB(DAT_001a2fb0[blk] + reg);
}

int FUN_a012043c(unsigned int blk, unsigned int *out)
{
    unsigned char x, y, n, i, a, b, c;

    x = rd8(blk, 0x50);
    n = 4 << (x >> 6);
    y = rd8(blk, 0x51);
    if (y & 1)
        return 0;
    DAT_a802d844[blk][0] = 0;
    DAT_a802d844[blk][1] = 0;
    for (i = 0; i < n; i++) {
        a = rd8(blk, 0x57);
        b = rd8(blk, 0x57);
        c = rd8(blk, 0x57);
        out[i] = (c << 16) | (b << 8) | a;
    }
    return 1;
}
