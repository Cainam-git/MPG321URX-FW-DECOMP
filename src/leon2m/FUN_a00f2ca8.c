/* leon2m FUN_a00f2ca8 @ 0xa00f2ca8  read-modify-write of one register in one or both of two register blocks
 * -mcpu=v8 -O3 -g, ). blk > 1 = both blocks 0..1 (block bases DAT_0019a2e0).
 * register address 0xCF000000 + 4 * (base + reg); set == 1 ORs mask in, else clears it; the low byte is written back.
 * Family with FUN_a00f2068, FUN_a00f2ca8, FUN_a00f2ca8, FUN_a010d914: all parameters and the value are unsigned char. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_0019a2e0[2];
void FUN_a00f2ca8(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;
    unsigned char v;
    if (blk > 1)
    {
        for (i = 0; i <= 1; i++)
        {
            v = R(DAT_0019a2e0[i] + reg);
            if (set == 1) v |= mask; else v &= ~mask;
            R(DAT_0019a2e0[i] + reg) = (unsigned char)v;
        }
    }
    else
    {
        v = R(DAT_0019a2e0[blk] + reg);
        if (set == 1) v |= mask; else v &= ~mask;
        R(DAT_0019a2e0[blk] + reg) = (unsigned char)v;
    }
}
