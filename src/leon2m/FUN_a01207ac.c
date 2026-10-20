/* leon2m FUN_a01207ac @ 0xa01207ac-0xa01207f4 (18 words).
 * Block blk of the register family with block bases DAT_001a2fb0[2] (register n at 0xcf000000 + 4 * n; blk > 1 is
 * treated as 0): sets bits 0-1 of register 0xcf011428, then returns bit 0 of register base + 0 of that block.
 * Called twice from FUN_a00f42b8 (with 0 and 1). Same register family as FUN_a011ff28 and FUN_a011fd84.
 * Written as a byte read helper rd8(blk, reg) inlined with reg 0: the sum base + reg is an int, so the halfword
 * base is not narrowed again before the shift.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short DAT_001a2fb0[2];

static unsigned char rd8(unsigned int blk, unsigned char reg)
{
    if (blk > 1)
        blk = 0;
    R(0xcf011428) |= 3;
    return RB(DAT_001a2fb0[blk] + reg);
}

unsigned char FUN_a01207ac(unsigned int blk)
{
    return rd8(blk, 0) & 1;
}
