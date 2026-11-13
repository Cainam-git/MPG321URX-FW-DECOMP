/* reg_blockset7_read8  (FUN_a00f19a4)
 *
 * Read an 8-bit register of a block of the seventh block set.
 * Returns: byte
 * Name basis: descriptive - block base addresses from the ROM table at 0x19A2D8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f19a4 @ 0xa00f19a4, flags -mcpu=v8 -O3 -g.
 * Source form: a leaf routine; the register is read through a volatile word pointer and the low byte is returned.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is
 * the table of 32-bit block bases reg_blockset7_bases (in read-only data); each word holds one byte of the
 * register. The block number is not range-checked.
 */
extern const unsigned int reg_blockset7_bases[];

/* Return the byte register 'reg' of block 'block'. Nothing calls it. */
unsigned char reg_blockset7_read8(unsigned char block, unsigned short reg)
{
    return *(volatile unsigned int *)(0xcf000000 | ((reg_blockset7_bases[block] + reg) << 2));
}
