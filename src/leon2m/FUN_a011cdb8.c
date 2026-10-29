/* leon2m FUN_a011cdb8 @ 0xa011cdb8-0xa011ce6c (180 bytes), flags -mcpu=v8 -O3 -g.
 * Register n of block blk is the word at 0xcf000000 + 4 * n, block base = halfword DAT_a8027aa8[blk]; the register
 * used is base + 0xa0. en == 0: bit 6 of that register is cleared (read-modify-write as FUN_a01191fc(blk, 0xa0,
 * 0x40, 0), no range check on blk). Otherwise the low byte of (r & 0xe0) | (a << 2 | b) | 0x40 is written, where r
 * is the register read with blk above 1 counting as 0 (both the read and the write clamp blk).
 * Source form: FUN_a01191fc (the matched routine at 0xa01191fc) and the rd8/wr8 helpers of FUN_a011cae0 (rd clamps
 * with "if (blk > 1) blk = 0", wr with a separate k) are defined static in this file and inlined; a << 2 | b is
 * computed into a local before the en test and the written value is one expression.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

static void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

static unsigned char rd8(unsigned char blk, unsigned char reg)
{
    if (blk > 1)
        blk = 0;
    return R(DAT_a8027aa8[blk] + reg);
}

static void wr8(unsigned char blk, unsigned char reg, unsigned char v)
{
    unsigned char k = blk;

    if (blk > 1)
        k = 0;
    R(DAT_a8027aa8[k] + reg) = v;
}

void FUN_a011cdb8(unsigned char en, unsigned int a, unsigned int b, unsigned char blk)
{
    unsigned int v = a << 2 | b;

    if (en == 0)
        FUN_a01191fc(blk, 0xa0, 0x40, 0);
    else
        wr8(blk, 0xa0, (rd8(blk, 0xa0) & 0xe0) | v | 0x40);
}
