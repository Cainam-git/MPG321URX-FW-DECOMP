/* reg_blockset5_write16  (FUN_a00f1298)
 *
 * Write a 16-bit register pair of a block of the fifth block set.
 * Name basis: descriptive - bases in RAM at 0xA8026A7E; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1298 @ 0xa00f1298, flags -mcpu=v8 -O3 -g.
 * Source form: the low byte is written as (unsigned char)value and the high byte as value >> 8, both through
 * the BLOCK_REG macro (a volatile word access); the address is held in an unsigned int.
 */

/*
 * Register n of block b of this set is the 32-bit word at 0xCF000000 | ((base[b] + n) << 2), where base is the
 * table of 16-bit block bases reg_blockset5_bases; each word holds one byte of the register. A 16-bit value
 * lies in registers n (low byte) and n + 1 (high byte).
 */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))

#define BLOCKSET5_ALL_BLOCKS 4  /* block argument: every block except block 3 */
extern unsigned short reg_blockset5_bases[4];

/*
 * Write the 16-bit 'value' to the register pair 'reg' (low byte) and 'reg' + 1 (high byte) of block 'block'.
 * Block number 4 writes blocks 0, 1 and 2 (not block 3); a number above 4 writes nothing. Nothing calls it.
 */
void reg_blockset5_write16(unsigned char block, unsigned short reg, unsigned short value)
{
    unsigned char i;
    unsigned int address;

    if (block == BLOCKSET5_ALL_BLOCKS) {
        for (i = 0; i <= 3; i++) {
            if (i != 3) {
                address = reg_blockset5_bases[i] + reg;
                BLOCK_REG(address) = (unsigned char)value;
                BLOCK_REG(address + 1) = value >> 8;
            }
        }
    } else if (block <= 3) {
        address = reg_blockset5_bases[block] + reg;
        BLOCK_REG(address) = (unsigned char)value;
        BLOCK_REG(address + 1) = value >> 8;
    }
}
