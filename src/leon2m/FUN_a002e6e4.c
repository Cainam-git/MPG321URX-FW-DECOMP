/* leon2m FUN_a002e6e4 @ 0xa002e6e4-0xa002e764 (32 words).
 * For v < 8: register 0xa5 of register block blk (block 0 when blk >= 2; address 0xcf000000 + 4 * (base + 0xa5)
 * with the block bases at 0xa8027aa8) = (its value & 0xf8) | v. Larger v do nothing.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

static unsigned char rd(unsigned char blk, unsigned char reg)
{
    if (blk >= 2) blk = 0;
    return R(DAT_a8027aa8[blk] + reg);
}

static void wr(unsigned char blk, unsigned char reg, unsigned char val)
{
    if (blk >= 2) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = val;
}

void FUN_a002e6e4(unsigned int v, unsigned char blk)
{
    if (v < 8)
        wr(blk, 0xa5, (rd(blk, 0xa5) & 0xf8) | v);
}
