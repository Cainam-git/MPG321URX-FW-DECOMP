/* FUN_a011cca0: sets (on != 0) or clears bit 0 of register base + 0x80 of block blk of the second
 * register family (register n at 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk], no block
 * check) through FUN_a01191fc, called with a constant set argument in each arm. Callers: FUN_a0146dc0.
 * FUN_a01191fc is defined here because GCC inlines it at -O3.
 */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = RB(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    RB(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

void FUN_a011cca0(unsigned char blk, unsigned char on)
{
    if (on)
        FUN_a01191fc(blk, 0x80, 1, 1);
    else
        FUN_a01191fc(blk, 0x80, 1, 0);
}
