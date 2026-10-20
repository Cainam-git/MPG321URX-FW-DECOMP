/* FUN_a011a574: copies a 5-byte setting record p into block blk of the second register family (register n at
 * 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk]). Register base + 0xab = p[1]; p[0] bits 0, 1
 * and 2 set or clear bits 7, 0 and 1 of base + 0xaa, p[0] bit 3 sets or clears bit 2 of base + 0xcf
 * (FUN_a01191fc, no block check); bits 4-5 of p[2] are ORed into bits 5-6 of base + 0xaa; base + 0xad =
 * p[2] & 7, base + 0xae = p[3], base + 0xaf = p[4] (byte writes that treat blk > 1 as 0).
 * Caller: FUN_a014667c. The helpers are defined here because GCC inlines them at -O3. Each p[0] bit is tested
 * with an if/else that calls FUN_a01191fc with a constant set argument; bit 7 is the char constant (char)0x80.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

static void wr8(unsigned char blk, unsigned char reg, unsigned char v)
{
    if (blk > 1) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

void FUN_a011a574(unsigned char *p, unsigned char blk)
{
    wr8(blk, 0xab, p[1]);
    if (p[0] & 1)
        FUN_a01191fc(blk, 0xaa, (char)0x80, 1);
    else
        FUN_a01191fc(blk, 0xaa, (char)0x80, 0);
    if (p[0] & 2)
        FUN_a01191fc(blk, 0xaa, 1, 1);
    else
        FUN_a01191fc(blk, 0xaa, 1, 0);
    if (p[0] & 4)
        FUN_a01191fc(blk, 0xaa, 2, 1);
    else
        FUN_a01191fc(blk, 0xaa, 2, 0);
    if (p[0] & 8)
        FUN_a01191fc(blk, 0xcf, 4, 1);
    else
        FUN_a01191fc(blk, 0xcf, 4, 0);
    FUN_a01191fc(blk, 0xaa, (p[2] & 0x30) << 1, 1);
    wr8(blk, 0xad, p[2] & 7);
    wr8(blk, 0xae, p[3]);
    wr8(blk, 0xaf, p[4]);
}
