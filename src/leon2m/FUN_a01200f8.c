/* FUN_a01200f8: two 16-bit writes to block blk of the register family with block bases DAT_001a2fb0[2] (register n
 * at 0xcf000000 + 4 * n; blk 0/1 = that block, 2 = both blocks, other values write nothing): registers base + 0x42 /
 * 0x43 = low / high byte of a, then base + 0x44 / 0x45 = low / high byte of b. Each write sets bits 0-1 of register
 * 0xcf011428 first. Callers: FUN_a0142518 (two calls).
 * Source form: the 16-bit write helper of FUN_a011fbd8 / FUN_a011ff28, inlined at -O3; a and b are unsigned short
 * parameters (an unsigned int b moves the high-byte shift of the second write).
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short DAT_001a2fb0[2];

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

void FUN_a01200f8(unsigned int blk, unsigned short a, unsigned short b)
{
    wr16(blk, 0x42, a);
    wr16(blk, 0x44, b);
}
