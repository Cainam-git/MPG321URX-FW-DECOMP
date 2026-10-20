/* FUN_a011fd84: block blk of the register family with block bases DAT_001a2fb0[2] (register n at
 * 0xcf000000 + 4 * n; blk 0/1 = that block, 2 = both blocks, other values write nothing): register base + 0x24 =
 * byte of (a & ~1) | (b << 1) | 4, then registers base + 0x25 / 0x26 = low / high byte of c & 0xfff. Each write
 * helper sets bits 0-1 of register 0xcf011428 first. Callers: FUN_a01423dc.
 * The byte and 16-bit write helpers are the static helpers of FUN_a011fcac / FUN_a011fbd8, inlined at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short DAT_001a2fb0[2];

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

static void wr16(unsigned int blk, unsigned char reg, unsigned short v)
{
    unsigned char i;

    R(0xcf011428) |= 3;
    if (blk == 2) {
        for (i = 0; i < 2; i++) {
            RB(DAT_001a2fb0[i] + reg) = (unsigned char)v;
            RB(DAT_001a2fb0[i] + reg + 1) = (unsigned char)(v >> 8);
        }
    } else if (blk < 2) {
        RB(DAT_001a2fb0[blk] + reg) = (unsigned char)v;
        RB(DAT_001a2fb0[blk] + reg + 1) = (unsigned char)(v >> 8);
    }
}

void FUN_a011fd84(unsigned int blk, unsigned int a, unsigned int b, unsigned int c)
{
    wr8(blk, 0x24, (a & ~1) | (b << 1) | 4);
    wr16(blk, 0x25, c & 0xfff);
}
