/* reg_blockset7_update_bits  (FUN_a00f1a18)
 *
 * Set or clear bits of a register of a block of the seventh block set.
 * Name basis: descriptive - block base addresses from the ROM table at 0x19A2D8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1a18 @ 0xa00f1a18, flags -mcpu=v8 -O3 -g.
 * Source form: the value read is held in an unsigned int and written back as (unsigned char); the read and
 * the write each index the base table again.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is
 * the table of 32-bit block bases reg_blockset7_bases (in read-only data); each word holds one byte of the
 * register. The block number is not range-checked.
 */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))
extern unsigned int reg_blockset7_bases[];

/*
 * Set (set == 1) or clear (any other value) the bits of 'mask' in the byte register 'reg' of block 'block'.
 * Nothing calls it. The same read-modify-write body, once per block, is in input_capture_update_bits,
 * input_measure_update_bits, pq_block_update_bits and input_unit_update_bits.
 */
void reg_blockset7_update_bits(unsigned char block, unsigned short reg, unsigned int mask, unsigned char set)
{
    unsigned int value = BLOCK_REG(reg_blockset7_bases[block] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    BLOCK_REG(reg_blockset7_bases[block] + reg) = (unsigned char)value;
}
