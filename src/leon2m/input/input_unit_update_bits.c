/* input_unit_update_bits  (FUN_a00f2ca8)
 *
 * Set or clear bits of a register of one receiver unit, or of both.
 * Name basis: derived - block base addresses from the ROM table at 0x19A2E0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2ca8 @ 0xa00f2ca8, flags -mcpu=v8 -O3 -g.
 */

#define REG(address) (*(volatile unsigned int *)(0xcf000000 | ((address) << 2)))
extern unsigned short input_unit_reg_bases[2];

/*
 * Read-modify-write of register reg of receiver unit blk (0 or 1), or of both units when blk is above 1.
 * The bits of mask are set when set is 1 and cleared for any other value of set.
 */
void input_unit_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;
    unsigned char value;
    if (blk > 1)
    {
        for (i = 0; i <= 1; i++)
        {
            value = REG(input_unit_reg_bases[i] + reg);
            if (set == 1) value |= mask; else value &= ~mask;
            REG(input_unit_reg_bases[i] + reg) = (unsigned char)value;
        }
    }
    else
    {
        value = REG(input_unit_reg_bases[blk] + reg);
        if (set == 1) value |= mask; else value &= ~mask;
        REG(input_unit_reg_bases[blk] + reg) = (unsigned char)value;
    }
}
