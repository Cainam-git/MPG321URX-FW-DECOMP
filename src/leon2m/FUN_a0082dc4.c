/* leon2m FUN_a0082dc4 @ 0xa0082dc4-0xa0082ec4 (64 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a00830f4. Reads three bytes of the record at 0xa802d290: n = +0x37,
 * h = +0x38, and +0x39; order = (byte +0x39 - 1) / n + 1 (u8). x = FUN_a0145660(idx, 8), b = FUN_a0145660(idx,
 * 0xf); prints "VideoWall V num %d order %d\n" (ROM 0xfeeb8) with (h, order).
 * half = (x / h) >> 1 (u16), rr = |x - 2 * half * h| (u8), cnt = 2 * half; when order <= rr / 2: rr = 2 * order - 2,
 * cnt += 2. Writes *pres = cnt * (order - 1) + rr + b and *pcnt = cnt (u16).
 * Source form: the doubled half count is computed twice, once into the u16 local w for the distance and once by
 * 'cnt <<= 1' (two separate 'add' instructions).
 */
struct R290 { unsigned char p000[0x37]; unsigned char b037; unsigned char b038; unsigned char b039; };

extern struct R290 DAT_a802d290;
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern int FUN_a00df170(const char *fmt, ...);
extern int abs(int);
extern const char s_000feeb8[];

void FUN_a0082dc4(unsigned char idx, unsigned short *pcnt, unsigned short *pres)
{
    unsigned char n = DAT_a802d290.b037;
    unsigned char h = DAT_a802d290.b038;
    unsigned char order;
    unsigned char rr;
    unsigned short w;
    unsigned short x;
    unsigned short b;
    unsigned short cnt;
    int d;

    order = (DAT_a802d290.b039 - 1) / n + 1;
    x = FUN_a0145660(idx, 8);
    b = FUN_a0145660(idx, 0xf);
    FUN_a00df170(s_000feeb8, h, order);
    cnt = (unsigned int)(x / h) >> 1;
    w = cnt << 1;
    d = abs(x - w * h);
    rr = d;
    cnt <<= 1;
    if (order <= rr >> 1) {
        rr = order * 2 - 2;
        cnt += 2;
    }
    *pres = cnt * (order - 1) + rr + b;
    *pcnt = cnt;
}
