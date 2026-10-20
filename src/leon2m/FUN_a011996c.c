/* FUN_a011996c: returns bit 0 of register base + 0x80 of block blk of the second register family
 * (register n at 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk]); blk > 1 is treated as 0.
 * Callers: FUN_a012a774, FUN_a0146dfc, FUN_a0152fac, FUN_a0153018.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

unsigned int FUN_a011996c(unsigned char blk)
{
    if (blk > 1) blk = 0;
    return R(DAT_a8027aa8[blk] + 0x80) & 1;
}
