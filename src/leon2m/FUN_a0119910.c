/* leon2m FUN_a0119910 @ 0xa0119910 (-mcpu=v8 -O3 -g)
 * Writes the low byte of v to register DAT_a8027aa8[blk] + 0x83 and bits 8..15 of v to register
 * DAT_a8027aa8[blk] + 0xd3 of the word-spaced register family at 0xCF000000 + 4 * n (blk > 1 is treated as 0,
 * as in FUN_a011919c). No direct caller; FUN_a011a060 contains the same code inline.
 * Source form: one inlined byte-write helper per register, each with its own blk clamp (the two clamps are
 * merged by the compiler).
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
static void wr8(unsigned char blk, unsigned int reg, unsigned char v)
{
    if (blk > 1)
        blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}
void FUN_a0119910(unsigned int blk, int v)
{
    wr8(blk, 0x83, v & 0xff);
    wr8(blk, 0xd3, (v >> 8) & 0xff);
}
