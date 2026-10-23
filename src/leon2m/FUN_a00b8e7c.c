/* leon2m FUN_a00b8e7c @ 0xa00b8e7c-0xa00b9750 (2260 bytes), called by FUN_a009b59c, FUN_a00a0508, FUN_a00a0780,
 * FUN_a00a09f8 and FUN_a00a0c70.
 * T = DAT_a802d290, e = T.a18a[page] (byte 0xa802d41a + page), c56 = byte 0xa8025c56.
 * Set-up: FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0), byte 0xa802b08f = 0x24, FUN_a0146dc0(0, 1), bit 15 of
 * 0xa802d032 cleared, func_0x4008e2a4() twice, FUN_a00b50d8(2), FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0),
 * FUN_a0146648(0, 0, 0, 0, 0), FUN_a014613c(0x16, 0x11, 0), FUN_a0146518(T.b00d, T.b00e, 0),
 * FUN_a0146ab0(0x792, 0), FUN_a0146108(0), FUN_a014654c(0x678, 0x57c, 0), FUN_a00a5908(0, 0, 2), FUN_a00a788c(e),
 * FUN_a0146b6c(2, 0), FUN_a0146b50(0x60, 0), FUN_a00a31a4(0, 3, 1, 0x10, FUN_a00a3844(DAT_001935bc,
 * e * 29 + T.b008), 0). x = T.b008 when it is 0, 6, 7 or 10, else 1. For e 7 / 8 / 10 FUN_a00a4a30 gets bit 12 of
 * T+0xa8 / bit 22 of T+0xac / T.b04a.
 * By e: 1: c56 = T.b009, FUN_a00a45c0(5, 8, T.b009, 0xc), FUN_a0146b50(0x6f, 0), FUN_a0146b6c(2, 0), buf = T.b009 formatted
 *   with the string at 0x1981d0 (FUN_a01577f4), buf[0] = index of the first zero byte among buf[0..3] - 1 (3 when
 *   none), FUN_a00a31a4(0, 0xa, 6, 3, buf, 0); 2: c56 = T.b182, byte 0xa8025c55 = bit 11 of T+0xa8, that bit
 *   cleared, FUN_a00dbcf0() when it was set, FUN_a00b8ca8(T.b182 >> 2), FUN_a00ad86c(T.b182 & 3, 1); 7 / 8 / 10:
 *   c56 = the same bit or byte as above, FUN_a0146b6c(2, 0), FUN_a00a31a4(0, 3, 8, 3, FUN_a00a3844(DAT_00193248, x),
 *   0) and (0, 0x10, 8, 3, .. x + 29 ..); 4: c56 = T.b1a0, FUN_a00b89c4(T.b1a0 >> 2), FUN_a00ad86c(T.b1a0 & 3, 1);
 *   3: FUN_a0090fa0(0xfc), c56 = T.b18f = T.b190, FUN_a00adaf4(), FUN_a00ad86c(T.b18f & 3, 1); 9: c56 = T.b15b,
 *   FUN_a00ad970(T.b15b >> 2), FUN_a00ad86c(T.b15b & 3, 1); 5, 6, 11: rows i (0..3 of DAT_00196b24 with index i,
 *   0..2 of DAT_00196678 / DAT_001909ec with index i * 29 + T.b008) to FUN_a00a31a4(0, 6, i * 2 + 5, 0xa, .., 0),
 *   then with v = c56 = FUN_a01445fc(T.b01e) / T.b01f / T.b17c: FUN_a00ad86c(v, 1), FUN_a00ad86c(v, 0),
 *   k = v (minus 4 when above 3), FUN_a0146b20(0, j + 4, k * 2 + 5, 1, j + 0x1c, 0) for j = 0, 1; e 5 and 6 also
 *   set T.b1a3 (to T.b01e / T.b01f).
 * End: FUN_a0146b50(0x92, 0), FUN_a0146b6c(0, 0), FUN_a0146a80(6, 0xf, 6, 0x592, 0), FUN_a0146a80(0xf, 0xf, 6,
 * 0x592, 0), then FUN_a00a31a4(0, 6, 0xf, 1, ..) and (0, 0xf, 0xf, 1, ..) with FUN_a00a3844(DAT_001928b0, n) for
 * n = T.b008 + 0x3a / + 0x91 (e 7, 8, 10), + 0x57 / + 0x91 (e 1), else T.b008 / + 0x74.
 * Source form: every chain test reads T.a18a[page] (CSE reuses the load for ten tests and reloads it for the
 * eleventh, as in the firmware); bit 11 of T+0xa8 is a bit-field; the sprintf argument is read before the
 * FUN_a0146b50 / FUN_a0146b6c calls.
 * Compiler aids: __builtin_expect(.., 0) on the byte 0xa8025c55 test and on the e == 9 test (no instructions; they
 * change the predicted probabilities that decide the block order).
 */
struct Sys {
    unsigned char p00[0x3e];
    struct { unsigned short b15 : 1, rest : 15; } h3e;
};
struct R290 {
    unsigned char p000[8];
    unsigned char b008, b009;
    unsigned char p00a[0x0d - 0x0a];
    unsigned char b00d, b00e;
    unsigned char p00f[0x1e - 0x0f];
    unsigned char b01e, b01f;
    unsigned char p020[0x4a - 0x20];
    unsigned char b04a;
    unsigned char p04b[0xa8 - 0x4b];
    union { unsigned int w; struct { unsigned int hi : 20, b11 : 1, lo : 11; } f; } a8u;
    unsigned int w0ac;
    unsigned char p0b0[0x15b - 0xb0];
    unsigned char b15b;
    unsigned char p15c[0x17c - 0x15c];
    unsigned char b17c;
    unsigned char p17d[0x182 - 0x17d];
    unsigned char b182;
    unsigned char p183[0x18a - 0x183];
    unsigned char a18a[0x18f - 0x18a];
    unsigned char b18f, b190;
    unsigned char p191[0x1a0 - 0x191];
    unsigned char b1a0;
    unsigned char p1a1[0x1a3 - 0x1a1];
    unsigned char b1a3;
};
extern struct Sys DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08f, DAT_a8025c55, DAT_a8025c56;
extern unsigned int DAT_001935bc[], DAT_00193248[], DAT_00196b24[], DAT_00196678[], DAT_001909ec[], DAT_001928b0[];
extern const char s_001981d0[];

extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void func_0x4008e2a4(void);
extern void FUN_a00b50d8(unsigned int);
extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146108(int);
extern void FUN_a014654c(int, int, int);
extern void FUN_a00a5908(int, int, int);
extern void FUN_a00a788c(unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00a4a30(unsigned char);
extern void FUN_a00a45c0(unsigned char, unsigned char, unsigned char, unsigned int);
extern void FUN_a01577f4(unsigned char *, const char *, ...);
extern void FUN_a00dbcf0(void);
extern void FUN_a00b8ca8(unsigned char);
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a00b89c4(unsigned char);
extern void FUN_a0090fa0(int);
extern void FUN_a00adaf4(void);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00ad970(unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

#define T DAT_a802d290

void FUN_a00b8e7c(unsigned char page)
{
    unsigned char x, i, k, n;
    unsigned char buf[8];

    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    DAT_a802b08f = 0x24;
    FUN_a0146dc0(0, 1);
    DAT_a802cff4.h3e.b15 = 0;
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a00b50d8(2);
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    FUN_a0146648(0, 0, 0, 0, 0);
    FUN_a014613c(0x16, 0x11, 0);
    FUN_a0146518(T.b00d, T.b00e, 0);
    FUN_a0146ab0(0x792, 0);
    FUN_a0146108(0);
    FUN_a014654c(0x678, 0x57c, 0);
    FUN_a00a5908(0, 0, 2);
    FUN_a00a788c(T.a18a[page]);
    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x60, 0);
    FUN_a00a31a4(0, 3, 1, 0x10, FUN_a00a3844(DAT_001935bc, T.a18a[page] * 29 + T.b008), 0);
    if (T.b008 == 0 || T.b008 == 6 || T.b008 == 7 || T.b008 == 10)
        x = T.b008;
    else
        x = 1;
    if (T.a18a[page] == 7)
        FUN_a00a4a30((T.a8u.w >> 12) & 1);
    else if (T.a18a[page] == 8)
        FUN_a00a4a30((T.w0ac >> 22) & 1);
    else if (T.a18a[page] == 10)
        FUN_a00a4a30(T.b04a);
    if (T.a18a[page] == 1) {
        DAT_a8025c56 = T.b009;
        FUN_a00a45c0(5, 8, T.b009, 0xc);
        n = T.b009;
        FUN_a0146b50(0x6f, 0);
        FUN_a0146b6c(2, 0);
        FUN_a01577f4(buf, s_001981d0, n);
        for (n = 0; n < 4; n++)
            if (buf[n] == 0)
                break;
        buf[0] = n - 1;
        FUN_a00a31a4(0, 0xa, 6, 3, (unsigned int)buf, 0);
    } else if (T.a18a[page] == 2) {
        DAT_a8025c56 = T.b182;
        DAT_a8025c55 = T.a8u.f.b11;
        T.a8u.f.b11 = 0;
        if (__builtin_expect(DAT_a8025c55, 0))
            FUN_a00dbcf0();
        FUN_a00b8ca8(T.b182 >> 2);
        FUN_a00ad86c(T.b182 & 3, 1);
    } else if (T.a18a[page] == 7) {
        DAT_a8025c56 = (T.a8u.w >> 12) & 1;
        FUN_a0146b6c(2, 0);
        FUN_a00a31a4(0, 3, 8, 3, FUN_a00a3844(DAT_00193248, x), 0);
        FUN_a00a31a4(0, 0x10, 8, 3, FUN_a00a3844(DAT_00193248, x + 29), 0);
    } else if (T.a18a[page] == 8) {
        DAT_a8025c56 = (T.w0ac >> 22) & 1;
        FUN_a0146b6c(2, 0);
        FUN_a00a31a4(0, 3, 8, 3, FUN_a00a3844(DAT_00193248, x), 0);
        FUN_a00a31a4(0, 0x10, 8, 3, FUN_a00a3844(DAT_00193248, x + 29), 0);
    } else if (T.a18a[page] == 10) {
        DAT_a8025c56 = T.b04a;
        FUN_a0146b6c(2, 0);
        FUN_a00a31a4(0, 3, 8, 3, FUN_a00a3844(DAT_00193248, x), 0);
        FUN_a00a31a4(0, 0x10, 8, 3, FUN_a00a3844(DAT_00193248, x + 29), 0);
    } else if (T.a18a[page] == 4) {
        DAT_a8025c56 = T.b1a0;
        FUN_a00b89c4(T.b1a0 >> 2);
        FUN_a00ad86c(T.b1a0 & 3, 1);
    } else if (T.a18a[page] == 3) {
        FUN_a0090fa0(0xfc);
        DAT_a8025c56 = T.b190;
        T.b18f = T.b190;
        FUN_a00adaf4();
        FUN_a00ad86c(T.b18f & 3, 1);
    } else if (T.a18a[page] == 5) {
        for (i = 0; i <= 3; i++)
            FUN_a00a31a4(0, 6, i * 2 + 5, 0xa, FUN_a00a3844(DAT_00196b24, i), 0);
        DAT_a8025c56 = FUN_a01445fc(T.b01e);
        FUN_a00ad86c(DAT_a8025c56, 1);
        FUN_a00ad86c(DAT_a8025c56, 0);
        k = DAT_a8025c56;
        if (k > 3)
            k -= 4;
        for (i = 0; i <= 1; i++)
            FUN_a0146b20(0, i + 4, k * 2 + 5, 1, i + 0x1c, 0);
        T.b1a3 = T.b01e;
    } else if (T.a18a[page] == 6) {
        DAT_a8025c56 = T.b01f;
        T.b1a3 = T.b01f;
        for (i = 0; i <= 2; i++)
            FUN_a00a31a4(0, 6, i * 2 + 5, 0xa, FUN_a00a3844(DAT_00196678, i * 29 + T.b008), 0);
        FUN_a00ad86c(T.b01f, 1);
        FUN_a00ad86c(T.b01f, 0);
        k = T.b01f;
        if (k > 3)
            k -= 4;
        for (i = 0; i <= 1; i++)
            FUN_a0146b20(0, i + 4, k * 2 + 5, 1, i + 0x1c, 0);
    } else if (__builtin_expect(T.a18a[page] == 9, 0)) {
        DAT_a8025c56 = T.b15b;
        FUN_a00ad970(T.b15b >> 2);
        FUN_a00ad86c(T.b15b & 3, 1);
    } else if (T.a18a[page] == 11) {
        DAT_a8025c56 = T.b17c;
        for (i = 0; i <= 2; i++)
            FUN_a00a31a4(0, 6, i * 2 + 5, 0xa, FUN_a00a3844(DAT_001909ec, i * 29 + T.b008), 0);
        FUN_a00ad86c(T.b17c, 1);
        FUN_a00ad86c(T.b17c, 0);
        k = T.b17c;
        if (k > 3)
            k -= 4;
        for (i = 0; i <= 1; i++)
            FUN_a0146b20(0, i + 4, k * 2 + 5, 1, i + 0x1c, 0);
    }
    FUN_a0146b50(0x92, 0);
    FUN_a0146b6c(0, 0);
    FUN_a0146a80(6, 0xf, 6, 0x592, 0);
    FUN_a0146a80(0xf, 0xf, 6, 0x592, 0);
    if (T.a18a[page] == 7 || T.a18a[page] == 8 || T.a18a[page] == 10) {
        FUN_a00a31a4(0, 6, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008 + 0x3a), 0);
        FUN_a00a31a4(0, 0xf, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008 + 0x91), 0);
    } else if (T.a18a[page] == 1) {
        FUN_a00a31a4(0, 6, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008 + 0x57), 0);
        FUN_a00a31a4(0, 0xf, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008 + 0x91), 0);
    } else {
        FUN_a00a31a4(0, 6, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008), 0);
        FUN_a00a31a4(0, 0xf, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008 + 0x74), 0);
    }
}
