/* input_unit_write8  (FUN_a00f2c20)
 *
 * Write an 8-bit register of one receiver unit, or of both.
 * Name basis: derived - block base addresses from the ROM table at 0x19A2E0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2c20 @ 0xa00f2c20, flags -mcpu=v8 -O3 -g.
 * Source form: the both-units case is a do-while loop.
 */

extern unsigned short input_unit_reg_bases[2];

/*
 * Write val to register reg of receiver unit blk (0 or 1); a unit number above 1 writes it to the same
 * register of both units. Register n of a unit is the word at 0xCF000000 | ((input_unit_reg_bases[blk] + n)
 * << 2) and holds one byte.
 */
void input_unit_write8(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    unsigned int reg_address;

    if ((unsigned int)blk > 1U) {
        i = 0;
        do {
            reg_address = input_unit_reg_bases[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = val;
            i++;
        } while (i <= 1);
    } else {
        reg_address = input_unit_reg_bases[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (reg_address << 2)) = val;
    }
}
