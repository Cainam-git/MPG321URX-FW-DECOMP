/* FUN_a0062bac (leon2s 0xa0062bac-0xa0062f3c, 912 bytes), flags -mcpu=v8 -Os -g. void (p1, p2, out).
 * v = p2 * 500 / p1. When byte DAT_a8078a5b is 1, the 0x9a-byte table DAT_9f1b0700 is copied to DAT_a80761d0 with
 * FUN_a00b15d8. DAT_a80761d0 holds 22-byte rows {x, y, f[9]} (halfwords); idx is the first i < 6 with
 * v < row[i + 1].x, else 5. For a value a of row idx and b of row idx + 1 (x values xlo, xhi) the result is a when
 * xhi == xlo, a + (b - a) * (v - xlo) / (xhi - xlo) when b > a, else a - (a - b) * (v - xlo) / (xhi - xlo).
 * DAT_a807cd6c = DAT_a0063960; record DAT_a8078aa0: byte +0x58 = 9, +2 = the result y for the y values, +4 = y * p2 / p1,
 * halfwords +0x5a.. = the 9 results for the f values, then 0x400 up to index 19. DAT_a8078a60 = 0x10000000 /
 * (0x1000 - y) and DAT_a8078a5c = (+4 << 10), divided by y when y is not 0 (signed divisions).
 * With n = y >> 4: out[0] = FUN_a0062b64(8) >> 11 when n is 0, else DAT_a8078a5c; out[1..n + 1] = DAT_a8078a5c;
 * out[i] = (FUN_a0062b64(i * 16) >> 12) / i for i = n + 1..0xff, then (with k the last such i, 0 if none) the
 * low 16 bits of that value / i for i = k + 1..0xff; out[0x100] = 0x400.
 * Source forms: the interpolation is a static inline helper used twice; the y block reads a, b, then the two x
 * values; the search limit is the variable k (6), later reused for the last index; k = 0 is set before n.
 */
struct Row {
    unsigned short x;
    unsigned short y;
    unsigned short f[9];
};
struct Cal {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned char pad6[0x52];
    unsigned char n;
    unsigned char pad59;
    unsigned short w[20];
};
extern unsigned char DAT_a8078a5b;
extern struct Row DAT_a80761d0[];
extern const struct Row DAT_9f1b0700[];
extern struct Cal DAT_a8078aa0;
extern unsigned short (*DAT_a807cd6c)[65];
extern unsigned short DAT_a0063960[][65];
extern int DAT_a8078a60;
extern int DAT_a8078a5c;
extern void *FUN_a00b15d8(void *, const void *, unsigned int);
extern unsigned int FUN_a0062b64(unsigned int);

static __inline__ unsigned int interp(unsigned int a, unsigned int b, unsigned int v, unsigned int xlo, unsigned int xhi)
{
    if (xhi == xlo)
        return a;
    if (b > a)
        return (b - a) * (v - xlo) / (xhi - xlo) + a;
    return a - (a - b) * (v - xlo) / (xhi - xlo);
}

void FUN_a0062bac(unsigned int p1, unsigned int p2, unsigned short *out)
{
    unsigned int v;
    unsigned int i;
    unsigned int idx;
    unsigned int xlo, xhi, a, b, y;
    unsigned short n, k;

    v = p2 * 500 / p1;
    idx = 5;
    k = 6;
    if (DAT_a8078a5b == 1)
        FUN_a00b15d8(DAT_a80761d0, DAT_9f1b0700, 0x9a);
    for (i = 0; i < k; i++) {
        if (v < DAT_a80761d0[i + 1].x) {
            idx = i;
            break;
        }
    }
    a = DAT_a80761d0[idx].y;
    b = DAT_a80761d0[idx + 1].y;
    xlo = DAT_a80761d0[idx].x;
    xhi = DAT_a80761d0[idx + 1].x;
    y = interp(a, b, v, xlo, xhi);
    DAT_a807cd6c = DAT_a0063960;
    DAT_a8078aa0.n = 9;
    DAT_a8078aa0.h2 = y;
    DAT_a8078aa0.h4 = y * p2 / p1;
    for (i = 0; i < DAT_a8078aa0.n; i++)
        DAT_a8078aa0.w[i] = interp(DAT_a80761d0[idx].f[i], DAT_a80761d0[idx + 1].f[i], v, xlo, xhi);
    for (; i < 20; i++)
        DAT_a8078aa0.w[i] = 0x400;
    DAT_a8078a60 = 0x10000000 / (int)(0x1000 - DAT_a8078aa0.h2);
    if (DAT_a8078aa0.h2 == 0)
        DAT_a8078a5c = DAT_a8078aa0.h4 << 10;
    else
        DAT_a8078a5c = (int)(DAT_a8078aa0.h4 << 10) / (int)DAT_a8078aa0.h2;
    k = 0;
    n = DAT_a8078aa0.h2 >> 4;
    if (n == 0)
        out[0] = FUN_a0062b64(8) >> 11;
    else
        out[0] = DAT_a8078a5c;
    for (i = 1; i <= n + 1; i++)
        out[i] = DAT_a8078a5c;
    for (i = n + 1; i <= 0xff; i++) {
        out[i] = (FUN_a0062b64(i * 16) >> 12) / i;
        k = i;
    }
    for (i = k + 1; i <= 0xff; i++)
        out[i] = (unsigned short)(FUN_a0062b64(i * 16) >> 12) / i;
    out[0x100] = 0x400;
}
