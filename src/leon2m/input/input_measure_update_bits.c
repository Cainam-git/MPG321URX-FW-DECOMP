/* input_measure_update_bits  (FUN_a00f2068)
 *
 * Set or clear bits of a register of an input measurement block.
 * Name basis: proven - block base addresses from the ROM table at 0x19A2FC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2068 @ 0xa00f2068, flags -mcpu=v8 -O3 -g.
 */

#define REG(address) (*(volatile unsigned int *)(0xcf000000 | ((address) << 2)))
extern unsigned short input_measure_reg_bases[8];

/*
 * Read-modify-write of register reg of input measurement block blk (0..7), or of all eight blocks when
 * blk is above 7. The bits of mask are set when set is 1 and cleared for any other value of set.
 */
void input_measure_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;
    unsigned char value;
    if (blk > 7)
    {
        for (i = 0; i <= 7; i++)
        {
            value = REG(input_measure_reg_bases[i] + reg);
            if (set == 1) value |= mask; else value &= ~mask;
            REG(input_measure_reg_bases[i] + reg) = (unsigned char)value;
        }
    }
    else
    {
        value = REG(input_measure_reg_bases[blk] + reg);
        if (set == 1) value |= mask; else value &= ~mask;
        REG(input_measure_reg_bases[blk] + reg) = (unsigned char)value;
    }
}
