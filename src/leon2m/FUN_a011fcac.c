/* FUN_a011fcac: writes bit 5 of register base + 0x48 with b (bits 0-4 and 6-7 kept) in block blk of a register
 * family whose block bases are the halfword table DAT_001a2fb0[2] (register n at 0xcf000000 + 4 * n).
 * blk 0/1 writes that block, blk 2 writes both blocks, other blk values write nothing; the old value is read from
 * block blk (blk > 1 read as block 0). Both the read and the write helper first set bits 0-1 of register
 * 0xcf011428. Caller: FUN_a0142418. The helpers are static and inlined by GCC at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short DAT_001a2fb0[2];

static unsigned char rd8(unsigned int blk, unsigned char reg)
{
    R(0xcf011428) |= 3;
    if (blk > 1)
        blk = 0;
    return RB(DAT_001a2fb0[blk] + reg);
}

static void wr8(unsigned int blk, unsigned char reg, unsigned char v)
{
    unsigned char i;

    R(0xcf011428) |= 3;
    if (blk == 2) {
        for (i = 0; i < 2; i++)
            RB(DAT_001a2fb0[i] + reg) = v;
    } else if (blk < 2) {
        RB(DAT_001a2fb0[blk] + reg) = v;
    }
}

void FUN_a011fcac(unsigned int blk, unsigned char b)
{
    wr8(blk, 0x48, (rd8(blk, 0x48) & 0xdf) | (b << 5));
}
