/* FUN_a0062a34 (leon2s 0xa0062a34-0xa0062b64, 304 bytes, leaf), flags -mcpu=v8 -Os -g.
 * x = (v - halfword +2 of DAT_a8078aa0) * DAT_a8078a60; idx = x >> 21; frac = (x >> 9) & 0xfff;
 * n = byte +0x58 of DAT_a8078aa0 + 1. Sums, for i = 1 .. n, the value t = (T[r][c] * (0x1000 - frac) +
 * T[r][c'] * frac) >> 6 weighted as (t * w[i - 1]) >> 4, where T is the table of 65-entry halfword rows at
 * the pointer DAT_a807cd6c and w the halfwords from +0x5a of DAT_a8078aa0. For idx > 0x3f the row is n - i and
 * the columns 128 - idx and 127 - idx; otherwise the row is i and the columns idx and idx + 1.
 * Returns the sum >> 8.
 * Source form: t is a separate local; idx is written as (x >> 9) >> 12 before x itself is shifted by 9.
 */
struct Cal {
    unsigned short h0;
    unsigned short h2;
    unsigned char pad4[0x54];
    unsigned char n;
    unsigned char pad59;
    unsigned short w[8];
};
extern struct Cal DAT_a8078aa0;
extern unsigned int DAT_a8078a60;
extern unsigned short (*DAT_a807cd6c)[65];

unsigned int FUN_a0062a34(unsigned int v)
{
    unsigned int x;
    unsigned int idx;
    unsigned int frac;
    unsigned int n;
    unsigned int i;
    unsigned int sum = 0;
    unsigned int t;

    x = (v - DAT_a8078aa0.h2) * DAT_a8078a60;
    n = DAT_a8078aa0.n + 1;
    idx = (x >> 9) >> 12;
    x >>= 9;
    frac = x & 0xfff;
    if (idx > 0x3f) {
        for (i = 1; i <= n; i++) {
            t = (DAT_a807cd6c[n - i][128 - idx] * (0x1000 - frac) + DAT_a807cd6c[n - i][127 - idx] * frac) >> 6;
            sum += t * DAT_a8078aa0.w[i - 1]  >> 4;
        }
    } else {
        for (i = 1; i <= n; i++) {
            t = (DAT_a807cd6c[i][idx] * (0x1000 - frac) + DAT_a807cd6c[i][idx + 1] * frac) >> 6;
            sum += t * DAT_a8078aa0.w[i - 1] >> 4;
        }
    }
    return sum >> 8;
}
