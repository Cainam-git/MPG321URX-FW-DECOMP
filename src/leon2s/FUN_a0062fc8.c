/* FUN_a0062fc8 (leon2s 0xa0062fc8-0xa006370c, 1860 bytes), flags -mcpu=v8 -Os -g.
 * Copies the record *src to DAT_a8078aa0 and raises clk to at least 1000. Stores the largest of the record
 * halfwords +0x82, +0x84, +0x86 in DAT_a8076684 and calls FUN_a006250c(). DAT_a8076680 = DAT_a8076684 * 10 when
 * DAT_a8076684 and byte DAT_a8078a69 are non-zero, else DAT_a8078a6c * 10; DAT_a807667c = the larger of
 * DAT_a8076680 and clk (0 becomes 1). d = 25600000 / DAT_a807667c is halved up to three times while above 0xfff
 * (sh = number of halvings), then limited to 0xfff. Register 0xd0013fdc is read with FUN_a0061528, changed with
 * FUN_a0061a6c(&t, 0x19, 0x18, 0) and written back with FUN_a0061534. A non-zero record byte +0x58 sets byte +1
 * to 1; when byte DAT_a8078a68 is non-zero or byte +1 is 0, calls FUN_a00627a8(clk, DAT_a8076680, DAT_a8078a6c,
 * DAT_a8078a64, &DAT_a8078aa0); then calls FUN_a00629fc(&DAT_a8078aa0). DAT_a8078a60 = 0x10000000 / (0x1000 -
 * h2) and DAT_a8078a5c = (h4 << 10) / h2 (h4 << 10 when h2 is 0), signed, with h2/h4 the record halfwords +2/+4.
 * DAT_a807cd6c points to one of nine 65-halfword tables picked by byte +0x58 + 1 (10 down to 3; else
 * DAT_a00657d8). With n = (h2 >> 4) >> sh, DAT_a8078a5c <<= sh, the 257-word table DAT_a8076278 is
 * built: entry 0 = FUN_a0062b64(8) >> (11 - sh) when n is 0, else DAT_a8078a5c; entries 1..n+1 =
 * DAT_a8078a5c; every 4th entry from n+1 below 0x100 >> sh and every entry after the last of those =
 * (FUN_a0062b64((i << 4) << sh) >> (12 - sh)) / (i << sh); the entries from 0x100 >> sh to 0x100 = 0x400 << sh
 * (entry 0x100 = 0x400 when sh is 0). The three entries between each pair of 4th entries from n+1 are filled
 * with ((previous << 8) + e + 0x80) >> 8 upwards (or - e when the upper entry is smaller), e = |difference| << 6.
 * When the low byte of FUN_a0062f3c(1) is non-zero: 0xd0013f60 gets FUN_a0061a6c(&t, 0, 0, 1) and
 * (&t, 0x10, 8, 0); for i = 0..0xff it gets (&t, 0x10, 8, i) followed by a write of entry i to 0xd0013f68;
 * 0xd0013f60 gets (&t, 0, 0, 0); 0xd0013f6c gets (&t, 0xf, 0, entry 0x100), then (&t, 0x1f, 0x1e, 3) and
 * (&t, 0x1f, 0x1e, 0); FUN_a0062b94() is called; 0xd0013f50 gets (&t, 0xb, 0, d) and (&t, 0x1f, 0x1f, 1); returns
 * 1. Each register is read with FUN_a0061528 into t and written with FUN_a0061534. Otherwise returns 0.
 * The record copy is a structure assignment that GCC emits as a call of the firmware memcpy FUN_a00b15d8
 * (declared with that link name). FUN_a00627a8 takes the record address as a fifth parameter.
 * Source form: the stride 4 of the interpolation is a variable step (tab[i] and tab[i - step] load through one
 * pointer); the table choice lists x == 2 explicitly with the default's table; the interpolation loop sits
 * inside its own entry test with j = n + 1 set after it. The upward fill loop has an index k and a separate
 * counter m running from -4 while m < -1: GCC reverses that counter into a count-down from 3 tested against
 * zero, while the downward fill's counter (bound 4) becomes a count-down from 2 tested for >= 0.
 * volatile only on the hardware registers.
 */
struct Cal {
    unsigned char b0, b1;
    unsigned short h2, h4;
    unsigned char p6[0x58 - 6];
    unsigned char b58;
    unsigned char p59[0x82 - 0x59];
    unsigned short h82, h84, h86, h88;
};
extern struct Cal DAT_a8078aa0;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern unsigned int DAT_a8076684, DAT_a8076680, DAT_a807667c;
extern unsigned int DAT_a8078a6c, DAT_a8078a64, DAT_a8078a60, DAT_a8078a5c;
extern unsigned char DAT_a8078a69, DAT_a8078a68;
extern unsigned int DAT_a8076278[];
extern unsigned short (*DAT_a807cd6c)[65];
extern unsigned short DAT_a0063960[][65], DAT_a0063ef6[][65], DAT_a006440a[][65], DAT_a006489c[][65];
extern unsigned short DAT_a0064cac[][65], DAT_a006503a[][65], DAT_a0065346[][65], DAT_a00655d0[][65];
extern unsigned short DAT_a00657d8[][65];
extern unsigned int FUN_a0061528(volatile unsigned int *);
extern void FUN_a0061534(volatile unsigned int *, unsigned int);
extern void FUN_a0061a6c(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a0062b64(unsigned int);
extern int FUN_a0062f3c(unsigned char);
extern void FUN_a0062b94(void);
extern void FUN_a006250c(void);
extern void FUN_a00627a8(unsigned int, unsigned int, unsigned int, unsigned int, struct Cal *);
extern void FUN_a00629fc(struct Cal *);

#define REG(a) ((volatile unsigned int *)(a))

unsigned char FUN_a0062fc8(unsigned int clk, struct Cal *src)
{
    unsigned int t;
    unsigned int u;
    unsigned int d;
    unsigned char sh;
    unsigned short n;
    unsigned short last;
    unsigned int i, j;
    int k;
    int m;
    unsigned int a, b, e;
    int r;
    int x;
    int step;

    DAT_a8078aa0 = *src;
    if (clk < 1000)
        clk = 1000;
    DAT_a8076684 = DAT_a8078aa0.h82 > DAT_a8078aa0.h84 ? DAT_a8078aa0.h82 : DAT_a8078aa0.h84;
    step = 4;
    DAT_a8076684 = DAT_a8078aa0.h86 > DAT_a8076684 ? DAT_a8078aa0.h86 : DAT_a8076684;
    FUN_a006250c();
    if (DAT_a8076684 == 0) {
        DAT_a8076680 = DAT_a8078a6c * 10;
    } else {
        DAT_a8076680 = DAT_a8078a69 ? DAT_a8076684 * 10 : DAT_a8078a6c * 10;
    }
    DAT_a807667c = DAT_a8076680 >= clk ? DAT_a8076680 : clk;
    u = DAT_a807667c;
    if (u == 0)
        u = 1;
    DAT_a807667c = u;
    d = 25600000 / u;
    sh = 0;
    if (d > 0xfff) {
        d >>= 1;
        sh = 1;
        if (d > 0xfff) {
            d >>= 1;
            sh = 2;
            if (d > 0xfff) {
                d >>= 1;
                sh = 3;
                if (d > 0xfff)
                    d = 0xfff;
            }
        }
    }
    t = FUN_a0061528(REG(0xd0013fdc));
    FUN_a0061a6c(&t, 0x19, 0x18, 0);
    FUN_a0061534(REG(0xd0013fdc), t);
    if (DAT_a8078aa0.b58 != 0)
        DAT_a8078aa0.b1 = 1;
    if (DAT_a8078a68 != 0 || DAT_a8078aa0.b1 == 0)
        FUN_a00627a8(clk, DAT_a8076680, DAT_a8078a6c, DAT_a8078a64, &DAT_a8078aa0);
    FUN_a00629fc(&DAT_a8078aa0);
    DAT_a8078a60 = 0x10000000 / (int)(0x1000 - DAT_a8078aa0.h2);
    if (DAT_a8078aa0.h2 == 0)
        DAT_a8078a5c = (unsigned int)DAT_a8078aa0.h4 << 10;
    else
        DAT_a8078a5c = (int)(DAT_a8078aa0.h4 << 10) / (int)DAT_a8078aa0.h2;
    x = DAT_a8078aa0.b58 + 1;
    if (x == 10)
        DAT_a807cd6c = DAT_a0063960;
    else if (x == 9)
        DAT_a807cd6c = DAT_a0063ef6;
    else if (x == 8)
        DAT_a807cd6c = DAT_a006440a;
    else if (x == 7)
        DAT_a807cd6c = DAT_a006489c;
    else if (x == 6)
        DAT_a807cd6c = DAT_a0064cac;
    else if (x == 5)
        DAT_a807cd6c = DAT_a006503a;
    else if (x == 4)
        DAT_a807cd6c = DAT_a0065346;
    else if (x == 3)
        DAT_a807cd6c = DAT_a00655d0;
    else if (x == 2)
        DAT_a807cd6c = DAT_a00657d8;
    else
        DAT_a807cd6c = DAT_a00657d8;
    n = (int)(DAT_a8078aa0.h2 >> 4) >> sh;
    DAT_a8078a5c <<= sh;
    last = 0;
    if (n == 0)
        DAT_a8076278[0] = FUN_a0062b64(8) >> (11 - sh);
    else
        DAT_a8076278[0] = DAT_a8078a5c;
    for (i = 1; i <= n + 1; i++)
        DAT_a8076278[i] = DAT_a8078a5c;
    for (i = n + 1; i < (0x100 >> sh); i += step) {
        DAT_a8076278[i] = (FUN_a0062b64((i << 4) << sh) >> (12 - sh)) / (i << sh);
        last = i;
    }
    for (i = last + 1; i < (0x100 >> sh); i++)
        DAT_a8076278[i] = (FUN_a0062b64((i << 4) << sh) >> (12 - sh)) / (i << sh);
    if (sh == 0)
        DAT_a8076278[0x100] = 0x400;
    else
        for (i = 0x100 >> sh; i <= 0x100; i++)
            DAT_a8076278[i] = 0x400 << sh;
    i = n + step + 1;
    if (i <= 0x100) {
        j = n + 1;
        for (; i <= 0x100; i += step, j += step) {
            a = DAT_a8076278[i];
            b = DAT_a8076278[i - step];
            if (a >= b) {
                e = (a - b) << 6;
                for (k = 1, m = -4; m < -1; m++, k++)
                    DAT_a8076278[j + k] = ((DAT_a8076278[j + k - 1] << 8) + e + 0x80) >> 8;
            } else {
                e = (b - a) << 6;
                for (k = 1; k < 4; k++)
                    DAT_a8076278[i + k - step] = ((DAT_a8076278[i + k - step - 1] << 8) - e + 0x80) >> 8;
            }
        }
    }

    r = 0;
    if ((unsigned char)FUN_a0062f3c(1)) {
        t = FUN_a0061528(REG(0xd0013f60));
        FUN_a0061a6c(&t, 0, 0, 1);
        FUN_a0061a6c(&t, 0x10, 8, 0);
        FUN_a0061534(REG(0xd0013f60), t);
        for (i = 0; i <= 0xff; i++) {
            FUN_a0061a6c(&t, 0x10, 8, i);
            FUN_a0061534(REG(0xd0013f60), t);
            FUN_a0061534(REG(0xd0013f68), DAT_a8076278[i]);
        }
        t = FUN_a0061528(REG(0xd0013f60));
        FUN_a0061a6c(&t, 0, 0, 0);
        FUN_a0061534(REG(0xd0013f60), t);
        t = FUN_a0061528(REG(0xd0013f6c));
        FUN_a0061a6c(&t, 0xf, 0, DAT_a8076278[0x100]);
        FUN_a0061534(REG(0xd0013f6c), t);
        t = FUN_a0061528(REG(0xd0013f6c));
        FUN_a0061a6c(&t, 0x1f, 0x1e, 3);
        FUN_a0061534(REG(0xd0013f6c), t);
        FUN_a0061a6c(&t, 0x1f, 0x1e, 0);
        FUN_a0061534(REG(0xd0013f6c), t);
        r = 1;
        FUN_a0062b94();
        t = FUN_a0061528(REG(0xd0013f50));
        FUN_a0061a6c(&t, 0xb, 0, d);
        FUN_a0061a6c(&t, 0x1f, 0x1f, 1);
        FUN_a0061534(REG(0xd0013f50), t);
    }
    return r;
}
