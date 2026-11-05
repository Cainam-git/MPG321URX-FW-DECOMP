/* FUN_a010eca8 (leon2m 0xa010eca8-0xa010ed50, 168 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d7c4 (c = 1), DAT_a802d784 (c = 2) or DAT_a802d744 (other c);
 * d = (int)((u16 s+0xe - 1) * u16 s+0xc * (byte s+0x24 >> 3)) / 32 (signed); sets bit 1 of byte +0x3e of s;
 * writes word +4 of s + (d | 0x10000000) to word 9 of register block DAT_0019aed8[c] and word +8 of s +
 * (d | 0x10000000) to word 9 of DAT_0019aecc[c]. No direct callers found. It lies before FUN_a010ed50.
 * Source form: a switch selecting the structure pointer (as FUN_a010ed50); each sum is computed into its own
 * int local before its store, with the structure word as the first operand.
 */
struct Ctx {
    unsigned int w0, w4, w8;
    unsigned short wc, we;
    unsigned char p10[0x24 - 0x10];
    unsigned char bpp;
    unsigned char p25[0x3e - 0x25];
    unsigned char b3e, p3f;
};
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];

void FUN_a010eca8(unsigned char c)
{
    struct Ctx *s;
    int d, a, b;

    switch (c) {
    case 1:
        s = &DAT_a802d7c4;
        break;
    case 2:
        s = &DAT_a802d784;
        break;
    default:
        s = &DAT_a802d744;
        break;
    }
    d = (int)((s->we - 1) * s->wc * (s->bpp >> 3)) / 32;
    s->b3e |= 2;
    a = s->w4 + (d | 0x10000000);
    DAT_0019aed8[c][9] = a;
    b = s->w8 + (d | 0x10000000);
    DAT_0019aecc[c][9] = b;
}
