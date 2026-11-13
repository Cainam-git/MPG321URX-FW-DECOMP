/* input_block_read_reg40_word  (FUN_a01231e4)
 *
 * Return the 16-bit value of registers 0x40/0x41 of an input block.
 * Returns: value
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01231e4 @ 0xa01231e4, flags -mcpu=v8 -O3 -g.
 * Source form: the low register is read into a local first (the firmware reads it first).
 */
extern const unsigned short input_block_reg_bases[];

/*
 * Read the register pair 0x40/0x41 of input block 0 or 1 and return it as a 16-bit value: register
 * 0x40 is the high byte, register 0x41 the low byte. The registers lie at 0xCF000000 + 4 * index,
 * where the index is the base input_block_reg_bases[blk] plus 0x40 or 0x41.
 *
 *   blk  0 or 1 (a larger value is taken as 0)
 *
 * No routine in the image calls it.
 */
unsigned short input_block_read_reg40_word(unsigned char blk)
{
    unsigned int base, low;
    unsigned short value;

    if (blk > 1)
        blk = 0;
    base = input_block_reg_bases[blk];
    low = *(volatile unsigned int *)(0xcf000000 | ((base + 0x41) << 2));
    value = (*(volatile unsigned int *)(0xcf000000 | ((base + 0x40) << 2)) << 8) | (low & 0xff);
    return value;
}
