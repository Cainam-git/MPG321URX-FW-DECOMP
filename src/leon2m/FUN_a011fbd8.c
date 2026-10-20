/* FUN_a011fbd8: writes the 16-bit value (v & 0xfff) | 0x4000 to registers base + 0x36 (low byte) and
 * base + 0x37 (high byte) of block blk of the register family with block bases DAT_001a2fb0[2] (register n at
 * 0xcf000000 + 4 * n): blk 0/1 writes that block, blk 2 writes both blocks, other values write nothing.
 * Bits 0-1 of register 0xcf011428 are set first. Caller: FUN_a0142418.
 * The write is a static 16-bit helper (same shape as the byte helper of FUN_a011fcac), inlined by GCC at -O3.
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

void FUN_a011fbd8(unsigned int blk, unsigned int v)
{
    wr16(blk, 0x36, (v & 0xfff) | 0x4000);
}
