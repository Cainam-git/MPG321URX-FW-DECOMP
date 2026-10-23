/* FUN_a008a590 (leon2s 0xa008a590-0xa008a6f4, 356 bytes), flags -mcpu=v8 -Os -g.
 * Writes seven groups to the hardware registers 0xcf00f680..0xcf00f6b0 through the inline helper wr(a, b, c):
 * 0xcf00f680 = a, 0xcf00f684 = 0x20, 0xcf00f688 = 0x18, 0xcf00f68c = 0xfe, 0xcf00f690 = b, 0xcf00f694 = c,
 * 0xcf00f698 = 0, 0xcf00f69c = 0, 0xcf00f6b0 = 0x80. The (a, b, c) groups are (8, 3, 0), (4, 0x1f, 0x29),
 * (8, 0, 0), (4, 4, 8), (0x30, 0x13, 0), (0x70, 0, 3) and (0, 1, 0). volatile only on the hardware registers.
 */
#define R(a) (*(volatile unsigned int *)(a))

static inline void wr(unsigned int a, unsigned int b, unsigned int c)
{
    R(0xcf00f680) = a;
    R(0xcf00f684) = 0x20;
    R(0xcf00f688) = 0x18;
    R(0xcf00f68c) = 0xfe;
    R(0xcf00f690) = b;
    R(0xcf00f694) = c;
    R(0xcf00f698) = 0;
    R(0xcf00f69c) = 0;
    R(0xcf00f6b0) = 0x80;
}

void FUN_a008a590(void)
{
    wr(8, 3, 0);
    wr(4, 0x1f, 0x29);
    wr(8, 0, 0);
    wr(4, 4, 8);
    wr(0x30, 0x13, 0);
    wr(0x70, 0, 3);
    wr(0, 1, 0);
}
