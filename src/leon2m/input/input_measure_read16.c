/* input_measure_read16  (FUN_a00f21f0)
 *
 * Read a 16-bit register pair of an input measurement block.
 * Returns: value
 * Name basis: proven - block base addresses from the ROM table at 0x19A2FC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f21f0 @ 0xa00f21f0, flags -mcpu=v8 -O3 -g.
 */

extern unsigned short input_measure_reg_bases[8];

/*
 * Read a 16-bit value from input measurement block blk: the low byte from register reg, the high byte
 * from register reg + 1. A block number of 8 or more reads block 0.
 */
unsigned short input_measure_read16(unsigned char blk, unsigned char reg)
{
    unsigned int low, high, reg_address;
    if (blk >= 8) blk = 0;
    reg_address = input_measure_reg_bases[blk] + reg;
    low = *(volatile unsigned int *)(0xcf000000 | (reg_address << 2));
    high = *(volatile unsigned int *)(0xcf000000 | ((reg_address + 1) << 2));
    return (high << 8) | (low & 0xff);
}
