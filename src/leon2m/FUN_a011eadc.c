/* FUN_a011eadc: initialises both blocks (blk 2) of the register family with block bases DAT_001a2fb0[2]
 * (register n at 0xcf000000 + 4 * n): registers base + 0x12..0x1d from the 12-byte table DAT_001a2fc8,
 * base + 0x38..0x3f from the 8-byte table DAT_001a2fc0, base + 0x48..0x4f from the 8-byte table DAT_001a2fb8,
 * then fixed values: 0 = 0x40, 1 = 0x80, 0xc = 0xcc, 0xd..0xf = 0, 0x20/0x21 = 0, 0x22 = 0xc4, 0x23 = 7,
 * 0x2c = 0x23, 0x2d = 0x44, 0x55 = 0x10, 0x56 = 0, 0x58 = 4, 0x59 = 0. Every write sets bits 0-1 of register
 * 0xcf011428 first. Caller: FUN_a01423dc. The byte write helper is the static helper of FUN_a011fcac.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short DAT_001a2fb0[2];

extern const unsigned char DAT_001a2fc8[12];
extern const unsigned char DAT_001a2fc0[8];
extern const unsigned char DAT_001a2fb8[8];

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

void FUN_a011eadc(void)
{
    unsigned char i;

    for (i = 0; i < 12; i++)
        wr8(2, 0x12 + i, DAT_001a2fc8[i]);
    for (i = 0; i < 8; i++)
        wr8(2, 0x38 + i, DAT_001a2fc0[i]);
    for (i = 0; i < 8; i++)
        wr8(2, 0x48 + i, DAT_001a2fb8[i]);
    wr8(2, 0x0, 0x40);
    wr8(2, 0x1, 0x80);
    wr8(2, 0xc, 0xcc);
    wr8(2, 0xd, 0x0);
    wr8(2, 0xe, 0x0);
    wr8(2, 0xf, 0x0);
    wr8(2, 0x20, 0x0);
    wr8(2, 0x21, 0x0);
    wr8(2, 0x22, 0xc4);
    wr8(2, 0x23, 0x7);
    wr8(2, 0x2c, 0x23);
    wr8(2, 0x2d, 0x44);
    wr8(2, 0x55, 0x10);
    wr8(2, 0x56, 0x0);
    wr8(2, 0x58, 0x4);
    wr8(2, 0x59, 0x0);
}
