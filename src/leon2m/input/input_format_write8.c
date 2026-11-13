/* input_format_write8  (FUN_a00f1e50)
 *
 * Write an 8-bit register of one input format block, or of all eight.
 * Name basis: derived - block base addresses from the ROM table at 0x19A30C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1e50 @ 0xa00f1e50, flags -mcpu=v8 -O3 -g.
 * Source form: the all-blocks case is a do-while loop.
 */

extern unsigned short input_format_reg_bases[8];

/*
 * Write val to register reg of input format block blk (0..7); a block number above 7 writes it to the
 * same register of all eight blocks. Addressing as in input_format_read8.
 */
void input_format_write8(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    unsigned int reg_address;

    if ((unsigned int)blk > 7U) {
        i = 0;
        do {
            reg_address = input_format_reg_bases[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = val;
            i++;
        } while (i <= 7);
    } else {
        reg_address = input_format_reg_bases[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = val;
    }
}
