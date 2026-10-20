/* leon2m FUN_a00f2e30 @ 0xa00f2e30 (-mcpu=v8 -O3 -g)
 * Reads one 8-bit register: the low byte of the 32-bit word at 0xCF000000 + 4 * (DAT_0019a2e0[blk] + reg).
 * Block numbers 2 and up read block 0. Same form as FUN_a00f2254 (register addressing described there); the
 * table DAT_0019a2e0 holds 2 unsigned short block bases.
 */
extern unsigned short DAT_0019a2e0[2];

unsigned char FUN_a00f2e30(unsigned char blk, unsigned char reg)
{
    if (blk >= 2) blk = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((DAT_0019a2e0[blk] + reg) << 2));
}
