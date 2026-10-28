/*
 * FUN_a00de8ac (leon2s 0xa00de8ac-0xa00dea60, 436 bytes), flags -mcpu=v8 -Os -g.
 * void (struct In *p). Fills the record DAT_a8079538 from p: bytes +0x18, +5, +7, +4 = bytes 0..3 (low to high)
 * of p->w4; halfwords +8..+0x16 = low and high halves of p->w8, wc, w10, w14; word +0x20 = p->w18; word 0 f =
 * ((((w18 >> 8) << w18) * 10 >> 17) * 12) / 10, doubled when bit 7 of w18 is set. With q = f * 100 / 400 (f >
 * 0xa9f) or f * 100 / 340 as a halfword: byte +0x19 = 4 for q <= 400, else 8; byte +0x1a = 3 for f > 0xbb7,
 * else 2. Prints the eight halfwords with s_9f1ceea0 ("DSC_ENC_TIMER_CONFIG %d %d %d %d") in two calls of
 * func_0xa0f83044, calls FUN_a00dcc80, FUN_a00dccd8 and FUN_a00dd488 and sets DAT_a8078b58 = 1.
 * Source forms: the halfword stores are written in field order before the w20 and f stores; bit 7 of w18 is tested
 * as '(signed char)p->w18 < 0' (byte load in the word's alias set).
 * Compiler aid: the 'else if (q != 0)' arm before the final 'else' of the byte +0x19 choice tests a condition that is
 * always true there (q > 400) and both arms store 8, so it emits no instructions; without it the record's address
 * high part and f get each other's registers.
 */
struct G {
    unsigned int f;
    unsigned char b4, b5, b6, b7;
    unsigned short h[8];
    unsigned char b18, b19, b1a, b1b;
    unsigned int w1c;
    unsigned int w20;
};
struct In {
    unsigned int w0;
    unsigned int w4;
    unsigned int w8, wc, w10, w14;
    unsigned int w18;
};
extern struct G DAT_a8079538;
extern unsigned char DAT_a8078b58;
extern const char s_9f1ceea0[];
extern int func_0xa0f83044(const char *, ...);
extern void FUN_a00dcc80(void);
extern void FUN_a00dccd8(void);
extern void FUN_a00dd488(void);

void FUN_a00de8ac(struct In *p)
{
    unsigned int f;
    unsigned short q;

    DAT_a8079538.b18 = p->w4;
    DAT_a8079538.b5 = p->w4 >> 8;
    DAT_a8079538.b7 = p->w4 >> 16;
    DAT_a8079538.b4 = p->w4 >> 24;
    DAT_a8079538.h[0] = p->w8;
    DAT_a8079538.h[1] = p->w8 >> 16;
    DAT_a8079538.h[2] = p->wc;
    DAT_a8079538.h[3] = p->wc >> 16;
    DAT_a8079538.h[4] = p->w10;
    DAT_a8079538.h[5] = p->w10 >> 16;
    DAT_a8079538.h[6] = p->w14;
    DAT_a8079538.h[7] = p->w14 >> 16;
    DAT_a8079538.w20 = p->w18;
    f = ((((p->w18 >> 8) << p->w18) * 10 >> 17) * 12) / 10;
    DAT_a8079538.f = f;
    if ((signed char)p->w18 < 0)
        DAT_a8079538.f = f * 2;
    if (DAT_a8079538.f > 0xa9f)
        q = DAT_a8079538.f * 100 / 400;
    else
        q = DAT_a8079538.f * 100 / 340;
    if (q <= 400)
        DAT_a8079538.b19 = 4;
    else if (q != 0)
        DAT_a8079538.b19 = 8;
    else
        DAT_a8079538.b19 = 8;
    if (DAT_a8079538.f > 0xbb7)
        DAT_a8079538.b1a = 3;
    else
        DAT_a8079538.b1a = 2;
    func_0xa0f83044(s_9f1ceea0, DAT_a8079538.h[0], DAT_a8079538.h[1], DAT_a8079538.h[2], DAT_a8079538.h[3]);
    func_0xa0f83044(s_9f1ceea0, DAT_a8079538.h[4], DAT_a8079538.h[5], DAT_a8079538.h[6], DAT_a8079538.h[7]);
    FUN_a00dcc80();
    FUN_a00dccd8();
    FUN_a00dd488();
    DAT_a8078b58 = 1;
}
