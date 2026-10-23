/* leon2m FUN_a0105910 @ 0xa0105910-0xa0105a3c (75 words).
 * For block blk 0..3: writes b, a, c, d, e and f with FUN_a00f2488 to the registers 0x64, 0x68, 0x66, 0x62, 0xa0
 * and 0xbe of the block. Then, when register 0x5b (FUN_a00f25f8) is not above b + d, writes b + d + 0x10 to it;
 * when register 0x5e is not above a + c, writes a + c + 0x10 to it (tail call). Called from FUN_a013d918.
 */
extern void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short FUN_a00f25f8(unsigned char blk, unsigned char reg);

void FUN_a0105910(unsigned char blk, unsigned short a, unsigned short b, unsigned short c, unsigned short d,
                  unsigned short e, unsigned char f)
{
    if (blk > 3)
        return;
    FUN_a00f2488(blk, 0x64, b);
    FUN_a00f2488(blk, 0x68, a);
    FUN_a00f2488(blk, 0x66, c);
    FUN_a00f2488(blk, 0x62, d);
    FUN_a00f2488(blk, 0xa0, e);
    FUN_a00f2488(blk, 0xbe, f);
    if (FUN_a00f25f8(blk, 0x5b) <= b + d)
        FUN_a00f2488(blk, 0x5b, b + d + 0x10);
    if (FUN_a00f25f8(blk, 0x5e) <= a + c)
        FUN_a00f2488(blk, 0x5e, a + c + 0x10);
}
