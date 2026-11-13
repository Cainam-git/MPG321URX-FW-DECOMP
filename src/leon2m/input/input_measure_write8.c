/* input_measure_write8  (FUN_a00f1fe0)
 *
 * Write an 8-bit register of one input measurement block, or of all eight.
 * Name basis: proven - block base addresses from the ROM table at 0x19A2FC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1fe0 @ 0xa00f1fe0, flags -mcpu=v8 -O3 -g.
 * Source form: the all-blocks case is a do-while loop.
 */

extern unsigned short input_measure_reg_bases[8];

/*
 * Write val to register reg of input measurement block blk (0..7); a block number above 7 writes it to
 * the same register of all eight blocks. Addressing as in input_measure_read8.
 */
void input_measure_write8(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    unsigned int reg_address;

    if ((unsigned int)blk > 7U) {
        i = 0;
        do {
            reg_address = input_measure_reg_bases[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = val;
            i++;
        } while (i <= 7);
    } else {
        reg_address = input_measure_reg_bases[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = val;
    }
}
