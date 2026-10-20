/* leon2m FUN_a00f1b5c @ 0xa00f1b5c  read-modify-write of one register in one or all eight register blocks (hand;
 * BYTE-EXACT at -mcpu=v8 -O3 -g, rawcmp 0 mismatches). blk > 7 = all blocks 0..7 (block bases DAT_0019a31c);
 * register address 0xCF000000 + 4 * (base + reg); set == 1 ORs mask in, else clears it; the low byte is written back.
 * Family with FUN_a00f2068, FUN_a00f232c, FUN_a00f2ca8, FUN_a010d914: all parameters and the value are unsigned char. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_0019a31c[8];
void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;
    unsigned char v;
    if (blk > 7)
    {
        for (i = 0; i <= 7; i++)
        {
            v = R(DAT_0019a31c[i] + reg);
            if (set == 1) v |= mask; else v &= ~mask;
            R(DAT_0019a31c[i] + reg) = (unsigned char)v;
        }
    }
    else
    {
        v = R(DAT_0019a31c[blk] + reg);
        if (set == 1) v |= mask; else v &= ~mask;
        R(DAT_0019a31c[blk] + reg) = (unsigned char)v;
    }
}
