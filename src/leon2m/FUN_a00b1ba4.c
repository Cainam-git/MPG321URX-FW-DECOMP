/* leon2m FUN_a00b1ba4 @ 0xa00b1ba4-0xa00b27fc (790 words), flags -mcpu=v8 -O3 -g.
 * Callers: FUN_a0099c64, FUN_a009f184 (two calls), FUN_a00b2d04. Parameters p and mode (bytes).
 * Calls func_0x4008e2a4, FUN_a00b50d8(3), FUN_a00b52f8(0x37, 0x1a, 0x792) and a sequence of FUN_a00b32e4 calls with
 * constant arguments. When the upper halfword of word DAT_a802d290+0x1e4 is 0 it calls FUN_a00b0710(2 or 1, bit 15 of
 * halfword DAT_a802cff4+0x0e), sets or clears bit 15 of halfword +0x18 and x = 0xb or 0x11 (the first values when
 * mode is not 3 or 4 and byte DAT_a802d290+0x1ee is 0), and later passes FUN_a00a3844(DAT_00190184, byte +0x08
 * [+ 0x1d, + 0x3a]) results to FUN_a00a31a4 at x, x + 0xc and 0x24. The loop count n is 9 or 13 from p and mode
 * (p == 0: 9 for mode 4 or 3, else 13; p != 0: 13 for mode 4, 9 for mode 3, else 13). Each iteration i < n sets y, x
 * and c from i, calls FUN_a0146b6c, FUN_a0146a80, FUN_a0146b20 and FUN_a0146b50 for selected values of i and
 * passes FUN_a00a3844(table, i * 29 + byte +0x08 [+ 0x1d / + 0x3a]) to FUN_a00a31a4, the table chosen by
 * p, mode, bytes +0x1e2 / +0x1e3 against halfwords DAT_a802cff4+0x10 / +0x12 and the bytes of word +0x1e4.
 * Ends with FUN_a0146b6c(2, 0), FUN_a0146518(0x32, 0x32, 0), byte DAT_a8025c55 = bit 15 of halfword
 * DAT_a802cff4+0x0e and FUN_a0146dc0(1, 0).
 * Source form: n assigned per p arm by a full mode if-chain in each arm; the loop reuses the pre-loop
 * variable x.
 */
struct Sys {
    unsigned char p00[0x0e];
    unsigned short h0e;
    unsigned short h10, h12;
    unsigned char p14[0x18 - 0x14];
    struct { unsigned short b15 : 1, rest : 15; } h18;
};
struct R290 {
    unsigned char p000[8];
    unsigned char b008;
    unsigned char p009[0x1e2 - 0x09];
    unsigned char b1e2, b1e3;
    union { unsigned int w; unsigned char b[4]; } u1e4;
    unsigned char b1e8[6];
    unsigned char b1ee;
};
extern struct Sys DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern unsigned int DAT_00190184[], DAT_00173998[], DAT_00174bd0[], DAT_00177270[], DAT_001785c0[],
    DAT_00179a14[], DAT_00172590[], DAT_0016e0d0[], DAT_00175de4[], DAT_0016f25c[], DAT_0016f670[];

extern void func_0x4008e2a4(void);
extern void FUN_a00b50d8(unsigned int);
extern void FUN_a00b52f8(int, int, int);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void FUN_a00b0710(unsigned char, unsigned char);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);
extern void FUN_a0146dc0(int, int);

#define T DAT_a802d290
#define SYS DAT_a802cff4

void FUN_a00b1ba4(unsigned char p, unsigned char mode)
{
    unsigned char x, n, i, y, c;

    func_0x4008e2a4();
    FUN_a00b50d8(3);
    FUN_a00b52f8(0x37, 0x1a, 0x792);
    FUN_a00b32e4(1, 1, 0x8a2, 0, 0, 1, 1);
    FUN_a00b32e4(1, 1, 0x8a2, 0x36, 0x19, 1, 4);
    FUN_a00b32e4(1, 0, 0x8a2, 1, 0, 7, 5);
    FUN_a00b32e4(1, 0, 0x8a2, 5, 0x19, 0x31, 6);
    FUN_a00b32e4(0, 0, 0x8a2, 0, 1, 0x17, 7);
    FUN_a00b32e4(0, 0, 0x8a2, 0x36, 3, 0x16, 8);
    FUN_a00b32e4(1, 1, 0x12aa, 6, 0, 1, 0x72);
    FUN_a00b32e4(1, 1, 0xa89a, 0x2f, 1, 1, 0x73);
    FUN_a00b32e4(1, 1, 0xa89a, 1, 0x17, 1, 0x74);
    FUN_a00b32e4(1, 1, 0x592, 3, 1, 2, 0x26);
    FUN_a00b32e4(1, 1, 0x592, 6, 0x18, 1, 0x2a);
    FUN_a00b32e4(1, 1, 0x592, 0x33, 0x18, 1, 0x2b);
    FUN_a00b32e4(1, 1, 0x592, 0x34, 0x17, 2, 0x2c);
    FUN_a00b32e4(1, 1, 0x592, 0x34, 0x18, 2, 0x2e);
    FUN_a00b32e4(1, 1, 0x9aae, 8, 0, 3, 0x20);
    FUN_a00b32e4(1, 0, 0x9aae, 0xb, 0, 0x21, 0x23);
    FUN_a00b32e4(1, 1, 0x9aae, 0x2c, 0, 2, 0x35);
    FUN_a00b32e4(1, 1, 0x9aae, 0x2e, 0, 1, 0x38);
    FUN_a00b32e4(1, 1, 0xd6aa, 0x2f, 0, 4, 0x88);
    FUN_a00b32e4(1, 1, 0xd79a, 0x30, 1, 2, 0x8c);
    FUN_a00b32e4(1, 1, 0xa29a, 0x33, 0, 3, 0x7a);
    FUN_a00b32e4(1, 1, 0xaaaa, 0x36, 0, 1, 0x7d);
    FUN_a00b32e4(1, 1, 0x9aaa, 0x32, 1, 5, 0x7e);
    FUN_a00b32e4(1, 1, 0x9aaa, 0x32, 2, 5, 0x83);
    FUN_a00b32e4(1, 1, 0x9faa, 0, 0x18, 1, 0x8e);
    FUN_a00b32e4(1, 1, 0x9faa, 2, 0x18, 2, 0x8f);
    FUN_a00b32e4(1, 1, 0x9faa, 0, 0x19, 5, 0x91);
    FUN_a00b32e4(1, 1, 0x3392, 2, 0x17, 2, 0x30);
    FUN_a00b32e4(1, 1, 0x3392, 1, 0x18, 1, 0x32);
    FUN_a00b32e4(1, 1, 0x3092, 4, 0x17, 3, 0x33);
    FUN_a00b32e4(1, 1, 0x3092, 4, 0x18, 2, 0x36);
    x = 0;
    if (!(T.u1e4.w & 0xffff0000)) {
        if ((unsigned char)(mode - 3) > 1 && T.b1ee == 0) {
            FUN_a00b0710(2, SYS.h0e >> 15);
            SYS.h18.b15 = 1;
            x = 0xb;
        } else {
            FUN_a00b0710(1, SYS.h0e >> 15);
            SYS.h18.b15 = 0;
            x = 0x11;
        }
    }
    FUN_a0146b50(0x5e, 0);
    FUN_a0146b6c(2, 0);
    FUN_a00b32e4(1, 1, 0x792, 0x14, 1, 0xf, 0x40);
    FUN_a00b32e4(1, 1, 0x792, 0x14, 2, 0xf, 0x4f);
    if (!(T.u1e4.w & 0xffff0000)) {
        FUN_a00a31a4(0, x, 0x17, 8, FUN_a00a3844(DAT_00190184, T.b008), 0);
        FUN_a00a31a4(0, x + 0xc, 0x17, 8, FUN_a00a3844(DAT_00190184, T.b008 + 0x1d), 0);
        if ((unsigned char)(mode - 3) > 1 && T.b1ee == 0)
            FUN_a00a31a4(0, 0x24, 0x17, 8, FUN_a00a3844(DAT_00190184, T.b008 + 0x3a), 0);
    }
    if (mode == 3)
        FUN_a0146a80(0x1d, 0x17, 8, 0x2c2, 0);
    FUN_a0146a80(4, 7, 0x32, 0x592, 0);
    if (p == 0) {
        if (mode == 4)
            n = 9;
        else if (mode == 3)
            n = 9;
        else
            n = 13;
    } else {
        if (mode == 4)
            n = 13;
        else if (mode == 3)
            n = 9;
        else
            n = 13;
    }
    for (i = 0; i < n; i++) {
        if (i <= 1) {
            FUN_a0146b6c(2, 0);
            y = i + 4;
        } else {
            if (i == 2)
                y = 7;
            else if ((unsigned char)(i - 3) <= 1)
                y = i * 2 + 3;
            else
                y = i + 8;
            FUN_a0146b6c(0, 0);
        }
        c = 0x2b;
        if (i <= 1) {
            x = 3;
            c = 0x30;
        } else
            x = (i == 2) ? 4 : 5;
        if ((unsigned char)(i - 3) < 3 || i == 7 || i == 9 || i == 11) {
            FUN_a0146a80(4, y, 1, 0xe96, 0);
            if (i != 11 || T.b1ee != 1)
                FUN_a0146b20(0, 4, y, 1, 1, 0);
        }
        if (i > 3) {
            if (i == 4)
                FUN_a0146b50(0x10d, 0);
            FUN_a0146a80(5, y, 0x2b, 0x796, 0);
        }
        if (p == 0) {
            if (mode == 4) {
                if (T.u1e4.b[0] == 1)
                    FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_00173998, i * 29 + T.b008), 0);
                else
                    FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_00174bd0, i * 29 + T.b008), 0);
            } else if (T.b1e2 == SYS.h10 && T.u1e4.b[2] == 1) {
                if (T.b1ee == 0 && i > 8) {
                    if (i == 9)
                        FUN_a0146b50(0x201, 0);
                    FUN_a0146a80(x, y, c, 0x793, 0);
                    FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_00177270, i * 29 + T.b008 + 0x3a), 0);
                } else if (i <= 10)
                    FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_00177270, i * 29 + T.b008), 0);
            } else if (mode == 3)
                FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_001785c0, i * 29 + T.b008), 0);
            else {
                if (i > 8) {
                    if (i == 9)
                        FUN_a0146b50(0x201, 0);
                    FUN_a0146a80(x, y, c, 0x793, 0);
                }
                FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_00179a14, i * 29 + T.b008 + 0x1d), 0);
            }
        } else {
            if (mode == 4) {
                if (T.u1e4.b[1] == 1)
                    FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_00172590, i * 29 + T.b008), 0);
                else
                    FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_0016e0d0, i * 29 + T.b008), 0);
            } else if (T.b1e3 == SYS.h12 && T.u1e4.b[3] == 1)
                FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_00175de4, i * 29 + T.b008), 0);
            else if (mode == 3)
                FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_0016f25c, i * 29 + T.b008), 0);
            else
                FUN_a00a31a4(0, x, y, c, FUN_a00a3844(DAT_0016f670, i * 29 + T.b008 + 0x1d), 0);
        }
    }
    FUN_a0146b6c(2, 0);
    FUN_a0146518(0x32, 0x32, 0);
    DAT_a8025c55 = SYS.h0e >> 15;
    FUN_a0146dc0(1, 0);
}
