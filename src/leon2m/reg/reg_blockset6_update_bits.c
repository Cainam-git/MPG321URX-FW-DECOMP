/* reg_blockset6_update_bits  (FUN_a00f176c)
 *
 * Set or clear bits of a register of a block of the sixth block set.
 * Name basis: descriptive - bases in RAM at 0xA8026A7A; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f176c @ 0xa00f176c, flags -mcpu=v8 -O3 -g.
 * Source form: same body as reg_blockset5_update_bits and pq_block_update_bits, with a plain else for the single block;
 * the value read is held in an unsigned char and written back as (unsigned char).
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of two 16-bit block bases reg_blockset6_bases; each word holds one byte of the register. A 16-bit
 * value lies in registers n (low byte) and n + 1 (high byte).
 */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))

#define BLOCKSET6_ALL_BLOCKS 2  /* block argument: both blocks */
extern unsigned short reg_blockset6_bases[];

/*
 * Set (set == 1) or clear (any other value) the bits of 'mask' in the byte register 'reg' of block 'block'.
 * Block number 2 changes blocks 0 and 1. Any other number indexes the base table directly, without a range
 * test. Nothing calls it.
 */
void reg_blockset6_update_bits(unsigned char block, unsigned short reg, unsigned char mask, unsigned char set)
{
    unsigned char i; unsigned char value;
    if (block == BLOCKSET6_ALL_BLOCKS) {
        for (i = 0; i <= 1; i++) {
            value = BLOCK_REG(reg_blockset6_bases[i] + reg);
            if (set == 1) value |= mask; else value &= ~mask;
            BLOCK_REG(reg_blockset6_bases[i] + reg) = (unsigned char)value;
        }
    } else {
        value = BLOCK_REG(reg_blockset6_bases[block] + reg);
        if (set == 1) value |= mask; else value &= ~mask;
        BLOCK_REG(reg_blockset6_bases[block] + reg) = (unsigned char)value;
    }
}
