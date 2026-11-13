/* reg_blockset6_read8  (FUN_a00f1690)
 *
 * Read an 8-bit register of a block of the sixth block set.
 * Returns: byte
 * Name basis: descriptive - two blocks, bases in RAM at 0xA8026A7A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1690 @ 0xa00f1690, flags -mcpu=v8 -O3 -g.
 * Source form: the register is read through a volatile word pointer and the low byte is returned.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of two 16-bit block bases reg_blockset6_bases; each word holds one byte of the register. A 16-bit
 * value lies in registers n (low byte) and n + 1 (high byte).
 */

extern unsigned short reg_blockset6_bases[2];     /* block bases */

/* Return the byte register 'reg' of block 'block'. A block number of 2 or more reads block 0. */
unsigned char reg_blockset6_read8(unsigned char block, unsigned short reg)
{
    if (block >= 2) block = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((reg_blockset6_bases[block] + reg) << 2));
}
