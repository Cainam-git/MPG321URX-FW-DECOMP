/* FUN_a010f65c (leon2m 0xa010f65c-0xa010f724, 200 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d804 (c = 1) or DAT_a802d704; computes d = (int)((we - 1) * wc * (bpp >> 3)) / 32 from the
 * halfwords +0xe, +0xc and the byte +0x24 of s; sets bit 1 of byte +0x3e; writes s->w4 + (d | 0x80000000) and s->w8
 * + (d | 0x80000000) to the word registers 0xd0032280/0xd003a280 (c = 0) or 0xd0032284/0xd003a284. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010f50c and
 * FUN_a010f724. Source form: the offset d is an int local; the | 0x80000000 is written in each register expression.
 */
struct Ctx {
    unsigned int w0, w4, w8;
    unsigned short wc, we;
    unsigned char p10[0x24 - 0x10];
    unsigned char bpp;
    unsigned char p25[0x3e - 0x25];
    unsigned char b3e, p3f;
};
extern struct Ctx DAT_a802d704, DAT_a802d804;

void FUN_a010f65c(unsigned char c)
{
    struct Ctx *s = &DAT_a802d704;
    int d;

    if (c == 1)
        s = &DAT_a802d804;
    d = (int)((s->we - 1) * s->wc * (s->bpp >> 3)) / 32;
    s->b3e |= 2;
    if (c == 0) {
        *(volatile unsigned int *)0xd0032280 = s->w4 + (d | 0x80000000);
        *(volatile unsigned int *)0xd003a280 = s->w8 + (d | 0x80000000);
    } else {
        *(volatile unsigned int *)0xd0032284 = s->w4 + (d | 0x80000000);
        *(volatile unsigned int *)0xd003a284 = s->w8 + (d | 0x80000000);
    }
}
