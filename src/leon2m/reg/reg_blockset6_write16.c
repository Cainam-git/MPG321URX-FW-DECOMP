/* reg_blockset6_write16  (FUN_a00f18d4)
 *
 * Write a 16-bit register pair of a block of the sixth block set.
 * Name basis: descriptive - bases in RAM at 0xA8026A7A; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f18d4 @ 0xa00f18d4, flags -mcpu=v8 -O3 -g.
 * Source form: old-style (K&R) parameter declarations. The promoted reg and value arguments are copied at
 * entry and zero-extended at each use; a prototype gives an and-mask instead. Same form as
 * reg_blockset5_write16, but with the other table and no range check.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of two 16-bit block bases reg_blockset6_bases; each word holds one byte of the register. A 16-bit
 * value lies in registers n (low byte) and n + 1 (high byte).
 */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))

#define BLOCKSET6_ALL_BLOCKS 2  /* block argument: both blocks */
extern unsigned short reg_blockset6_bases[2];

/*
 * Write the 16-bit 'value' to the register pair 'reg' (low byte) and 'reg' + 1 (high byte) of block 'block'.
 * Block number 2 writes blocks 0 and 1. Any other number indexes the base table directly, without a range
 * test. Nothing calls it.
 */
void reg_blockset6_write16(block, reg, value)
unsigned char block;
unsigned short reg;
unsigned short value;
{
    unsigned char i;
    unsigned int address;

    if (block == BLOCKSET6_ALL_BLOCKS) {
        for (i = 0; i <= 1; i++) {
            address = reg_blockset6_bases[i] + reg;
            BLOCK_REG(address) = value & 0xff;
            BLOCK_REG(address + 1) = value >> 8;
        }
    } else {
        address = reg_blockset6_bases[block] + reg;
        BLOCK_REG(address) = value & 0xff;
        BLOCK_REG(address + 1) = value >> 8;
    }
}
