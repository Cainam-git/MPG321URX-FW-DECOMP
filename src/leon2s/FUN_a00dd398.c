/* FUN_a00dd398 (leon2s 0xa00dd398-0xa00dd488, 240 bytes), flags -mcpu=v8 -Os -g.
 * void (unsigned int *p). Writes the low byte of p[5] to byte +0x18 and bits 8..15 of p[5] to byte +5 of
 * DAT_a8079538. For each word p[1]..p[4] it stores two halfwords: (bits 8..15 << 8) + bits 0..7 at +8, +0xc,
 * +0x10, +0x14 and (bits 24..31 << 8) + bits 16..23 at +0xa, +0xe, +0x12, +0x16. Ends with a tail call of
 * func_0xa0f83044(s_9f1cecd0).
 * Source form: one unsigned int temporary t holds the upper byte of every halfword before the shift
 * ('t = (w >> 8) & 0xff; h = (t << 8) + (w & 0xff);'); the reuse keeps the per-word load order.
 */
struct Rec538 {
    unsigned char _0[5];
    unsigned char b5;
    unsigned char _6[2];
    unsigned short h8, ha, hc, he, h10, h12, h14, h16;
    unsigned char b18;
};
extern struct Rec538 DAT_a8079538;
extern const char s_9f1cecd0[];
extern int func_0xa0f83044(const char *, ...);

#define B0(w) ((w) >> 24)
#define B1(w) (((w) >> 16) & 0xff)
#define B2(w) (((w) >> 8) & 0xff)
#define B3(w) ((w) & 0xff)

void FUN_a00dd398(unsigned int *p)
{
    unsigned int t;

    DAT_a8079538.b18 = p[5];
    DAT_a8079538.b5 = p[5] >> 8;
    t = B2(p[1]);
    DAT_a8079538.h8 = (t << 8) + B3(p[1]);
    t = B0(p[1]);
    DAT_a8079538.ha = (t << 8) + B1(p[1]);
    t = B2(p[2]);
    DAT_a8079538.hc = (t << 8) + B3(p[2]);
    t = B0(p[2]);
    DAT_a8079538.he = (t << 8) + B1(p[2]);
    t = B2(p[3]);
    DAT_a8079538.h10 = (t << 8) + B3(p[3]);
    t = B0(p[3]);
    DAT_a8079538.h12 = (t << 8) + B1(p[3]);
    t = B2(p[4]);
    DAT_a8079538.h14 = (t << 8) + B3(p[4]);
    t = B0(p[4]);
    DAT_a8079538.h16 = (t << 8) + B1(p[4]);
    func_0xa0f83044(s_9f1cecd0);
}
