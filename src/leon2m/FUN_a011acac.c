/* FUN_a011acac: writes a 3-bit count field in block blk of the second register family (register n at
 * 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk]); companion of FUN_a011a848.
 * n == 0xff: nothing is written. n is limited to 8. Bits 0-2 of register base + 0xa1 become 0 (n == 0) or
 * n - 1 (read and write through byte helpers that treat blk > 1 as 0); bits 4-5 of base + 0xcf are then cleared
 * (n == 0) or set (FUN_a01191fc, no block check). Callers: FUN_a014654c, FUN_a014a388.
 * The helpers are defined here because GCC inlines them at -O3.
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

void FUN_a011acac(unsigned char n, unsigned char blk)
{
    unsigned char v;

    if (n == 0xff)
        return;
    if (n > 8)
        n = 8;
    v = rd8(blk, 0xa1) & 0xf8;
    if (n == 0) {
        wr8(blk, 0xa1, v);
        FUN_a01191fc(blk, 0xcf, 0x30, 0);
    } else {
        wr8(blk, 0xa1, v | (n - 1));
        FUN_a01191fc(blk, 0xcf, 0x30, 1);
    }
}
