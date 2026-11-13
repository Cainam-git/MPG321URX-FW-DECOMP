/* reg_blockset5_write8  (FUN_a00f11f4)
 *
 * Write an 8-bit register of a block of the fifth block set.
 * Name basis: descriptive - bases in RAM at 0xA8026A7E; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f11f4 @ 0xa00f11f4, flags -mcpu=v8 -O3 -g.
 * Source form: the register is written through a volatile word pointer; the "all blocks" loop runs i = 0..3
 * and skips i == 3 with 'continue'.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of 16-bit block bases reg_blockset5_bases; each word holds one byte of the register. A 16-bit value
 * lies in registers n (low byte) and n + 1 (high byte).
 */

#define BLOCKSET5_ALL_BLOCKS 4  /* block argument: every block except block 3 */
extern unsigned short reg_blockset5_bases[];

/*
 * Write 'value' to the byte register 'reg' of block 'block'. Block number 4 writes blocks 0, 1 and 2 (not
 * block 3); a number above 4 writes nothing. Nothing calls it.
 */
void reg_blockset5_write8(unsigned char block, unsigned short reg, unsigned char value)
{
    unsigned char i;

    if (block == BLOCKSET5_ALL_BLOCKS) {
        for (i = 0; i <= 3; i++) {
            if (i == 3)
                continue;
            *(volatile unsigned int *)(0xcf000000 | ((reg_blockset5_bases[i] + reg) << 2)) = value;
        }
    } else if (block <= 3)
        *(volatile unsigned int *)(0xcf000000 | ((reg_blockset5_bases[block] + reg) << 2)) = value;
}
