/* FUN_a011f364: copies a record r { u8 b0, b1; u16 h2; u8 b4, b5; } into block blk of the register family with
 * block bases DAT_001a2fb0[2] (register n at 0xcf000000 + 4 * n; blk 0/1 = that block, 2 = both, other values
 * write nothing): register base + 4 = b0, base + 5 = b1, base + 6 = (b4 & 0xf) << 4 | (b5 & 0xf),
 * base + 7 / 8 = low / high byte of h2 & 0xfff. Each write sets bits 0-1 of register 0xcf011428 first.
 * Caller: FUN_a0142418. The byte and 16-bit write helpers are the static helpers of FUN_a011fcac / FUN_a011fbd8.
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

struct Rec { unsigned char b0, b1; unsigned short h2; unsigned char b4, b5; };

void FUN_a011f364(unsigned int blk, struct Rec *r)
{
    wr8(blk, 4, r->b0);
    wr8(blk, 5, r->b1);
    wr8(blk, 6, ((r->b4 & 0xf) << 4) | (r->b5 & 0xf));
    wr16(blk, 7, r->h2 & 0xfff);
}
