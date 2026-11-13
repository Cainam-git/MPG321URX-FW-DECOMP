/* reg_blockset5_update_bits  (FUN_a00f1374)
 *
 * Set or clear bits of a register of a block of the fifth block set.
 * Name basis: descriptive - bases in RAM at 0xA8026A7E; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1374 @ 0xa00f1374, flags -mcpu=v8 -O3 -g.
 * Source form: the value read is held in an unsigned char and written back as (unsigned char); the read and
 * the write each index the base table again.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of 16-bit block bases reg_blockset5_bases; each word holds one byte of the register. A 16-bit value
 * lies in registers n (low byte) and n + 1 (high byte).
 */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))

#define BLOCKSET5_ALL_BLOCKS 4  /* block argument: all four blocks */
extern unsigned short reg_blockset5_bases[4];

/*
 * Set (set == 1) or clear (any other value) the bits of 'mask' in the byte register 'reg' of block 'block'.
 * Block number 4 changes blocks 0 to 3; a number above 4 changes nothing. Nothing calls it.
 */
void reg_blockset5_update_bits(unsigned char block, unsigned short reg, unsigned char mask, unsigned char set)
{
    unsigned char i; unsigned char value;
    if (block == BLOCKSET5_ALL_BLOCKS) {
        for (i = 0; i <= 3; i++) {
            value = BLOCK_REG(reg_blockset5_bases[i] + reg);
            if (set == 1) value |= mask; else value &= ~mask;
            BLOCK_REG(reg_blockset5_bases[i] + reg) = (unsigned char)value;
        }
    } else if (block <= 3) {
        value = BLOCK_REG(reg_blockset5_bases[block] + reg);
        if (set == 1) value |= mask; else value &= ~mask;
        BLOCK_REG(reg_blockset5_bases[block] + reg) = (unsigned char)value;
    }
}
