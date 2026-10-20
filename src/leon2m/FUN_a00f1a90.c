/* leon2m FUN_a00f1a90 @ 0xa00f1a90  8-bit register read, 0x19A31C block table (hand)
 * Returns the low byte of register reg of block blk, where block bases are the 16-bit words of the table at
 * 0x0019A31C and the register lives at 0xCF000000 + 4 * (base + reg); block numbers 8 and up read block 0
 * (branchless: blk & -(blk < 8)). Counterpart of FUN_a00f2254 for the 0x19A2EC table. Used by the display set-up
 * FUN_a01038c0 and the FUN_a00f3c18 / FUN_a00f3f64 / FUN_a00f40e4 group.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_0019a31c[8];
unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg)
{
    if (blk >= 8) blk = 0;
    return R(DAT_0019a31c[blk] + reg);
}
