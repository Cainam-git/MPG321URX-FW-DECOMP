/* input_unit_read8  (FUN_a00f2e30)
 *
 * Read an 8-bit register of a receiver unit.
 * Returns: byte
 * Name basis: derived - block base addresses from the ROM table at 0x19A2E0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2e30 @ 0xa00f2e30, flags -mcpu=v8 -O3 -g.
 */

extern unsigned short input_unit_reg_bases[2];

/*
 * Read register reg of receiver unit blk (0 or 1). The register is the word at
 * 0xCF000000 | ((input_unit_reg_bases[blk] + reg) << 2) and holds one byte.
 * A unit number of 2 or more reads unit 0.
 */
unsigned char input_unit_read8(unsigned char blk, unsigned char reg)
{
    if (blk >= 2) blk = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((input_unit_reg_bases[blk] + reg) << 2));
}
