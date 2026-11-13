/* reg_blockset6_write8  (FUN_a00f16d8)
 *
 * Write an 8-bit register of a block of the sixth block set.
 * Name basis: descriptive - bases in RAM at 0xA8026A7A; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f16d8 @ 0xa00f16d8, flags -mcpu=v8 -O3 -g.
 * Source form: the register is written through a volatile word pointer; the block number is not range-checked
 * in the single-block branch.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of two 16-bit block bases reg_blockset6_bases; each word holds one byte of the register. A 16-bit
 * value lies in registers n (low byte) and n + 1 (high byte).
 */

#define BLOCKSET6_ALL_BLOCKS 2  /* block argument: both blocks */
extern unsigned short reg_blockset6_bases[];

/*
 * Write 'value' to the byte register 'reg' of block 'block'. Block number 2 writes blocks 0 and 1. Any other
 * number indexes the base table directly, without a range test. Nothing calls it.
 */
void reg_blockset6_write8(unsigned char block, unsigned short reg, unsigned char value)
{
    unsigned char i;

    if (block == BLOCKSET6_ALL_BLOCKS) {
        for (i = 0; i < 2; i++)
            *(volatile unsigned int *)(0xcf000000 | ((reg_blockset6_bases[i] + reg) << 2)) = value;
    } else
        *(volatile unsigned int *)(0xcf000000 | ((reg_blockset6_bases[block] + reg) << 2)) = value;
}
