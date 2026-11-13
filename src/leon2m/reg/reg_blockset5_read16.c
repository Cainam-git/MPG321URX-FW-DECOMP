/* reg_blockset5_read16  (FUN_a00f14e4)
 *
 * Read a 16-bit register pair of a block of the fifth block set.
 * Returns: value
 * Name basis: descriptive - bases in RAM at 0xA8026A7E; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f14e4 @ 0xa00f14e4, flags -mcpu=v8 -O3 -g.
 * Source form: the low byte is read first into its own local; the high word is shifted left by 8 without a mask.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of 16-bit block bases reg_blockset5_bases; each word holds one byte of the register. A 16-bit value
 * lies in registers n (low byte) and n + 1 (high byte).
 */

extern unsigned short reg_blockset5_bases[];

/*
 * Return the 16-bit value of the register pair 'reg' (low byte) and 'reg' + 1 (high byte) of block 'block'.
 * A block number above 3 reads block 0. Nothing calls it.
 */
unsigned short reg_blockset5_read16(unsigned char block, unsigned short reg)
{
    unsigned int index, low_word;

    if (block > 3)
        block = 0;
    index = reg_blockset5_bases[block] + reg;
    low_word = *(volatile unsigned int *)(0xcf000000 | (index << 2));
    return (*(volatile unsigned int *)(0xcf000000 | ((index + 1) << 2)) << 8) | (low_word & 0xff);
}
