/* leon2m FUN_a011919c @ 0xa011919c  16-bit write into register block 0 or 1 of a second register family
 * (-mcpu=v8 -O3 -g).
 * blk > 1 is treated as 0. Block base = halfword table in RAM at 0xA8027AA8 (two entries, register numbers);
 * the value goes to register (base + reg) as its low byte and to (base + reg + 1) as its high byte; registers are
 * word-spaced at 0xCF000000 + 4 * n (same addressing as the 0x19A2EC family, FUN_a00f2488).
 * Callers: output timing apply FUN_a01023f4 (reg 0x62 = row +0x30 + +0x32, both blocks) and FRCConfigPostFRC
 * FUN_a0107e44 (reg 0x44). Written as an inlined 16-bit write helper: that is what gives the original its
 * register order (plain inline code allocates differently).
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }
void FUN_a011919c(unsigned char blk, unsigned char reg, unsigned short v)
{
    if (blk > 1) blk = 0;
    wr16(DAT_a8027aa8[blk] + reg, v);
}
