/* input_capture_update_bits  (FUN_a00f1b5c)
 *
 * Set or clear bits of a register of one input capture block, or of all eight.
 * Name basis: proven - block base addresses from the ROM table at 0x19A31C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f1b5c @ 0xa00f1b5c, flags -mcpu=v8 -O3 -g.
 */

#define REG(address) (*(volatile unsigned int *)(0xcf000000 | ((address) << 2)))
extern unsigned short input_capture_reg_bases[8];

/*
 * Read-modify-write of register reg of input capture block blk (0..7), or of all eight blocks when blk is
 * above 7. The bits of mask are set when set is 1 and cleared for any other value of set.
 */
void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;
    unsigned char value;
    if (blk > 7)
    {
        for (i = 0; i <= 7; i++)
        {
            value = REG(input_capture_reg_bases[i] + reg);
            if (set == 1) value |= mask; else value &= ~mask;
            REG(input_capture_reg_bases[i] + reg) = (unsigned char)value;
        }
    }
    else
    {
        value = REG(input_capture_reg_bases[blk] + reg);
        if (set == 1) value |= mask; else value &= ~mask;
        REG(input_capture_reg_bases[blk] + reg) = (unsigned char)value;
    }
}
