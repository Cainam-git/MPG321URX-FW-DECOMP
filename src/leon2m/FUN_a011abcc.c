/* FUN_a011abcc: n == 0 clears bits 0-1 of register base + 0x90 of block blk and writes 0 to base + 0x95;
 * n != 0 sets bits 0-1 of base + 0x90 and writes the byte n * 0x55 to base + 0x95 (second register family:
 * register n at 0xcf000000 + 4 * n, base = halfword table 0xa8027aa8[blk]; the bit helper FUN_a01191fc has no
 * block check, the byte write treats blk > 1 as 0). Caller: FUN_a014654c.
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

static void wr8(unsigned char blk, unsigned char reg, unsigned char v)
{
    if (blk > 1) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

void FUN_a011abcc(unsigned char n, unsigned char blk)
{
    if (n == 0) {
        FUN_a01191fc(blk, 0x90, 3, 0);
        wr8(blk, 0x95, 0);
    } else {
        FUN_a01191fc(blk, 0x90, 3, 1);
        wr8(blk, 0x95, n * 0x55);
    }
}
