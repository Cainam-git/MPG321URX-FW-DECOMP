/* input_capture_read8  (FUN_a00f1a90)
 *
 * Read an 8-bit register of an input capture block.
 * Returns: byte
 * Name basis: proven - block base addresses from the ROM table at 0x19A31C; blocks 0..7; other numbers read
 *   block 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1a90 @ 0xa00f1a90, flags -mcpu=v8 -O3 -g.
 */

#define REG(address) (*(volatile unsigned int *)(0xcf000000 | ((address) << 2)))
extern unsigned short input_capture_reg_bases[8];

/*
 * Read register reg of input capture block blk (0..7). The register is the word at
 * 0xCF000000 | ((input_capture_reg_bases[blk] + reg) << 2) and holds one byte.
 * A block number of 8 or more reads block 0.
 */
unsigned char input_capture_read8(unsigned char blk, unsigned char reg)
{
    if (blk >= 8) blk = 0;
    return REG(input_capture_reg_bases[blk] + reg);
}
