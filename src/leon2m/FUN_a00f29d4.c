/* leon2m FUN_a00f29d4 @ 0xa00f29d4-0xa00f2b48, flags -mcpu=v8 -O3 -g.
 * Callers: FUN_a00ef1b0, FUN_a01042c8, FUN_a01045a0. 24-bit form of src/leon2m/FUN_a00f154c.c.
 * rd24(blk, reg) (static, inlined three times): blk > 7 becomes 0; a = DAT_0019a2ec[blk] + reg; returns
 * (R(a + 2) << 16) | ((R(a + 1) & 0xff) << 8) | (R(a) & 0xff), where R(x) is the word at 0xcf000000 | (x << 2),
 * read in the order a + 2, a + 1, a. The function reads a = rd24(blk, reg), then repeats a = rd24(blk, reg)
 * while a differs from a fresh rd24(blk, reg), at most 5 times, and returns a.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned short DAT_0019a2ec[8];

static unsigned int rd24(unsigned char blk, unsigned char reg)
{
    unsigned int a;

    if (blk > 7)
        blk = 0;
    a = DAT_0019a2ec[blk] + reg;
    return (((R(a + 2) << 8) | (R(a + 1) & 0xff)) << 8) | (R(a) & 0xff);
}

unsigned int FUN_a00f29d4(unsigned char blk, unsigned char reg)
{
    unsigned int a;
    unsigned char n = 0;

    a = rd24(blk, reg);
    for (; a != rd24(blk, reg) && n < 5; n++)
        a = rd24(blk, reg);
    return a;
}
