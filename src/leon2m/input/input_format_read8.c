/* input_format_read8  (FUN_a00f1e0c)
 *
 * Read an 8-bit register of an input format block.
 * Returns: byte
 * Name basis: derived - block base addresses from the ROM table at 0x19A30C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1e0c @ 0xa00f1e0c, flags -mcpu=v8 -O3 -g.
 */

extern unsigned short input_format_reg_bases[8];

/*
 * Read register reg of input format block blk (0..7). The register is the word at
 * 0xCF000000 | ((input_format_reg_bases[blk] + reg) << 2) and holds one byte.
 * A block number of 8 or more reads block 0.
 */
unsigned char input_format_read8(unsigned char blk, unsigned char reg)
{
    if (blk >= 8) blk = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((input_format_reg_bases[blk] + reg) << 2));
}
