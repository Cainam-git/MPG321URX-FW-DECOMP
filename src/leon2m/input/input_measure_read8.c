/* input_measure_read8  (FUN_a00f1f9c)
 *
 * Read an 8-bit register of an input measurement block.
 * Returns: byte
 * Name basis: proven - block base addresses from the ROM table at 0x19A2FC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1f9c @ 0xa00f1f9c, flags -mcpu=v8 -O3 -g.
 */

extern unsigned short input_measure_reg_bases[8];

/*
 * Read register reg of input measurement block blk (0..7). The register is the word at
 * 0xCF000000 | ((input_measure_reg_bases[blk] + reg) << 2) and holds one byte.
 * A block number of 8 or more reads block 0.
 */
unsigned char input_measure_read8(unsigned char blk, unsigned char reg)
{
    if (blk >= 8) blk = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((input_measure_reg_bases[blk] + reg) << 2));
}
