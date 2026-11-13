/* input_block_read_reg48_word  (FUN_a0123184)
 *
 * Return the 16-bit value of registers 0x48/0x49 of an input block, times 8.
 * Returns: value
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123184 @ 0xa0123184, flags -mcpu=v8 -O3 -g.
 * Source form: the low register is read into a local first (the firmware reads it first).
 */
extern const unsigned short input_block_reg_bases[];

/*
 * Read the register pair 0x48/0x49 of input block 0 or 1 and return it as a 16-bit value shifted left by 3: register
 * 0x48 is the high byte, register 0x49 the low byte. The registers lie at 0xCF000000 + 4 * index,
 * where the index is the base input_block_reg_bases[blk] plus 0x48 or 0x49.
 *
 *   blk  0 or 1 (a larger value is taken as 0)
 *
 * No routine in the image calls it.
 */
unsigned short input_block_read_reg48_word(unsigned char blk)
{
    unsigned int base, low;
    unsigned short value;

    if (blk > 1)
        blk = 0;
    base = input_block_reg_bases[blk];
    low = *(volatile unsigned int *)(0xcf000000 | ((base + 0x49) << 2));
    value = (*(volatile unsigned int *)(0xcf000000 | ((base + 0x48) << 2)) << 8) | (low & 0xff);
    return value << 3;
}
