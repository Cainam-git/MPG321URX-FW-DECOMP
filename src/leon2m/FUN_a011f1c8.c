/* FUN_a011f1c8: on != 0: sets bit 0 of register base + 0 of block blk of the register family with block bases
 * DAT_001a2fb0[2] (register n at 0xcf000000 + 4 * n; blk 0/1 = that block, 2 = both, other values write nothing)
 * and calls FUN_a00f1b5c(b2, 3, 0x80, 1). on == 0: clears that bit and calls FUN_a00f1b5c(b2, 3, 0x80, x) with
 * x = 1 when bits 0-2 of register 0xcf020114 equal 5, else 0. The bit helper sets bits 0-1 of register 0xcf011428
 * first. Callers: FUN_a0142418.
 * Exact form: the on != 0 arm first; the bit helper is static and inlined at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short DAT_001a2fb0[2];

extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

static void bits(unsigned int blk, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;

    R(0xcf011428) |= 3;
    if (blk == 2) {
        for (i = 0; i < 2; i++) {
            if (set)
                RB(DAT_001a2fb0[i] + reg) = (unsigned char)(RB(DAT_001a2fb0[i] + reg) | mask);
            else
                RB(DAT_001a2fb0[i] + reg) = (unsigned char)(RB(DAT_001a2fb0[i] + reg) & ~mask);
        }
    } else if (blk < 2) {
        if (set)
            RB(DAT_001a2fb0[blk] + reg) = (unsigned char)(RB(DAT_001a2fb0[blk] + reg) | mask);
        else
            RB(DAT_001a2fb0[blk] + reg) = (unsigned char)(RB(DAT_001a2fb0[blk] + reg) & ~mask);
    }
}

void FUN_a011f1c8(unsigned int blk, unsigned char b2, unsigned char on)
{
    if (on) {
        bits(blk, 0, 1, 1);
        FUN_a00f1b5c(b2, 3, 0x80, 1);
    } else {
        bits(blk, 0, 1, 0);
        if ((R(0xcf020114) & 7) != 5)
            FUN_a00f1b5c(b2, 3, 0x80, 0);
        else
            FUN_a00f1b5c(b2, 3, 0x80, 1);
    }
}
