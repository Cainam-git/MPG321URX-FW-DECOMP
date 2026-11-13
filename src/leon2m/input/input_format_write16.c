/* input_format_write16  (FUN_a00f1ed8)
 *
 * Write a 16-bit register pair of one input format block, or of all eight.
 * Name basis: derived - block base addresses from the ROM table at 0x19A30C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1ed8 @ 0xa00f1ed8, flags -mcpu=v8 -O3 -g.
 */

extern unsigned short input_format_reg_bases[8];

/*
 * Write a 16-bit value to input format block blk: the low byte to register reg, the high byte to
 * register reg + 1. A block number above 7 writes it to all eight blocks.
 */
void input_format_write16(unsigned char blk, unsigned char reg, unsigned short val)
{
    unsigned char i;
    unsigned int reg_address;
    if (blk > 7) {
        for (i = 0; i <= 7; i++) {
            reg_address = input_format_reg_bases[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = (unsigned char)val;
            *(volatile unsigned int *)(0xcf000000 | ((reg_address + 1) << 2)) = val >> 8;
        }
    } else {
        reg_address = input_format_reg_bases[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = (unsigned char)val;
        *(volatile unsigned int *)(0xcf000000 | ((reg_address + 1) << 2)) = val >> 8;
    }
}
