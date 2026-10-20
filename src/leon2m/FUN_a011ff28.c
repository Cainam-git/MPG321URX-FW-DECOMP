/* FUN_a011ff28: writes the u16 v to registers base + 0x40 / 0x41 (low / high byte) and v >> 2 to registers
 * base + 0x53 / 0x54 of block blk of the register family with block bases DAT_001a2fb0[2] (register n at
 * 0xcf000000 + 4 * n; blk 0/1 = that block, 2 = both blocks, other values write nothing). Each write sets bits
 * 0-1 of register 0xcf011428 first. Callers: FUN_a00f42b8, FUN_a0142518.
 * The 16-bit write helper is the static helper of FUN_a011fbd8, inlined at -O3.
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

void FUN_a011ff28(unsigned int blk, unsigned short v)
{
    wr16(blk, 0x40, v);
    wr16(blk, 0x53, v >> 2);
}
