/* FUN_a011a848: writes a 3-bit count field in block blk of the second register family (register n at
 * 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk]). n == 0xff: nothing is written. n is
 * limited to 8. n == 0: clears bits 3-5 of register base + 0xa1 and bit 4 of base + 0xaa (FUN_a01191fc).
 * n 1..8: bits 3-5 of base + 0xa1 = n - 1 (read and write through byte helpers that treat blk > 1 as 0),
 * then bit 4 of base + 0xaa is set. Callers: FUN_a01469e0, FUN_a014a388.
 * The helpers are defined here because GCC inlines them at -O3 (each repeats its block check).
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

static unsigned char rd8(unsigned char blk, unsigned char reg)
{
    if (blk > 1) blk = 0;
    return R(DAT_a8027aa8[blk] + reg);
}

static void wr8(unsigned char blk, unsigned char reg, unsigned char v)
{
    if (blk > 1) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

void FUN_a011a848(unsigned char n, unsigned char blk)
{
    if (n == 0xff)
        return;
    if (n > 8)
        n = 8;
    if (n == 0) {
        FUN_a01191fc(blk, 0xa1, 0x38, 0);
        FUN_a01191fc(blk, 0xaa, 0x10, 0);
    } else {
        wr8(blk, 0xa1, (rd8(blk, 0xa1) & 0xc7) | ((n - 1) << 3));
        FUN_a01191fc(blk, 0xaa, 0x10, 1);
    }
}
