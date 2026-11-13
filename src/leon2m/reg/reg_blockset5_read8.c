/* reg_blockset5_read8  (FUN_a00f11ac)
 *
 * Read an 8-bit register of a block of the fifth block set.
 * Returns: byte
 * Name basis: descriptive - four blocks, bases in RAM at 0xA8026A7E; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f11ac @ 0xa00f11ac, flags -mcpu=v8 -O3 -g.
 * Source form: the register is read through a volatile word pointer and the low byte is returned.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of 16-bit block bases reg_blockset5_bases; each word holds one byte of the register. A 16-bit value
 * lies in registers n (low byte) and n + 1 (high byte).
 */

#define BLOCKSET5_BLOCKS 4      /* blocks 0..3 */
extern unsigned short reg_blockset5_bases[];

/*
 * Return the byte register 'reg' of block 'block'. A block number above 3 reads block 0. Nothing calls it.
 */
unsigned char reg_blockset5_read8(unsigned char block, unsigned short reg)
{
    if (block > 3)
        block = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((reg_blockset5_bases[block] + reg) << 2));
}
