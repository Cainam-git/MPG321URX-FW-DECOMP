/* leon2m FUN_a00b1004 @ 0xa00b1004-0xa00b1654 (1568 bytes), called by FUN_a009b59c and FUN_a009f42c.
 * FUN_a00b5080(), FUN_a00b5378(), then frame() (func_0x4008e2a4(), for q = 5..0x14 FUN_a0146b20(0, 0x13, q, 0x13,
 * 0, 0) and FUN_a0146a80(0x13, q, 0x13, 0x792, 0), FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0), FUN_a0146c40(5, 0, 0), as in
 * FUN_a00b0034) and FUN_a00a8c88(). Then by page:
 *   0: FUN_a00b4144(1, 1), FUN_a00b4144(1, 2), FUN_a00ad02c(0, 0), FUN_a00b617c(); with b = byte 0xa802d412
 *      (T+0x182): flag != 0: FUN_a00a900c(0, 2), FUN_a00a9650(b, 0), FUN_a00a9650(b, 1), mark(b, 0, 0); flag 0:
 *      FUN_a00a900c(0, 1), FUN_a00a9650(b, 2), mark(b, 0xf, 0x10).
 *   2: FUN_a00b4144(2, 1), FUN_a00b4144(2, 2), FUN_a0146b50(0x92, 0), FUN_a0146b6c(0, 0); for i = 0..2: when
 *      FUN_a00aa520(i) == 0 FUN_a0146a80(0x14, i * 2 + 6, 0xf, 0x292, 0); FUN_a00a31a4(0, 0x14, i * 2 + 6, 1,
 *      FUN_a00a3844(DAT_00188634, i * 29 + byte T+8), 0); FUN_a00b6d58(); FUN_a00b6bec(v / 7) with
 *      v = FUN_a00b6b88(byte T+0x181, 0) (read again for every use); flag != 0: FUN_a00a900c(0, 2),
 *      FUN_a00a9650(v % 7, 0), FUN_a00a9650(v % 7, 1); flag 0: FUN_a00a900c(0, 1), FUN_a00a9650(v % 7, 2),
 *      mark(v % 7, 0xf, 0x10).
 *   7: func_0x4008e2a4(); for q = 5..0x15 FUN_a0146a80(1, q, 0x11, 0x792, 0) and FUN_a0146b20(0, 1, q, 0x11, 0, 0);
 *      cols(1) (the body of FUN_a00a7aec: FUN_a00b32e4 calls for i = 7, 8); FUN_a00b3d14(1), FUN_a00aa83c(0),
 *      FUN_a00ac718(0x35), FUN_a00b4144(8, 1), FUN_a00b4144(8, 2), FUN_a00a900c(1, 1).
 * Every page ends with FUN_a00d4780() and FUN_a0146dc0(1, 0). T = DAT_a802d290. mark(b, c1, c2): y = b * 2 + 6 for
 * b < 7, else b * 2 - 8; FUN_a0146b20(0, 0x28, y, 1, c1, 0) and FUN_a0146b20(0, 0x29, y, 1, c2, 0).
 * Source form: frame(), cols() and mark() are static helpers that GCC inlines; in cols() the two bounds are set in
 * an if/else (the default-then-override form of FUN_a00a7aec gives other registers here).
 */
struct R290 {
    unsigned char p000[8];
    unsigned char b008;
    unsigned char p009[0x181 - 0x09];
    unsigned char b181;
    unsigned char b182;
};
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00188634[];

extern void FUN_a00b5080(void);
extern void FUN_a00b5378(void);
extern void func_0x4008e2a4(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a8c88(void);
extern void FUN_a00b4144(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00b6d58(void);
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern void FUN_a00b6bec(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00ad02c(unsigned char, int);
extern void FUN_a00b617c(void);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void FUN_a00b3d14(unsigned char);
extern void FUN_a00aa83c(unsigned char);
extern void FUN_a00ac718(unsigned int);
extern void FUN_a00d4780(void);
extern void FUN_a0146dc0(int, int);

static void frame(void)
{
    unsigned char i;

    func_0x4008e2a4();
    for (i = 5; i <= 0x14; i++) {
        FUN_a0146b20(0, 0x13, i, 0x13, 0, 0);
        FUN_a0146a80(0x13, i, 0x13, 0x792, 0);
    }
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
}

static void cols(unsigned char p)
{
    unsigned char i, start, end, row;
    unsigned char c = 0;

    if (p == 0) {
        end = 7;
        start = 0;
    } else {
        end = 9;
        start = 7;
    }
    for (i = start; i < end; i++) {
        switch (i) {
        case 0:
            c = 0x49;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            c = i * 3 + 0x52;
            break;
        case 6:
            c = 0x64;
            break;
        case 7:
            c = 0x70;
            break;
        case 8:
            c = 0x7c;
            break;
        }
        row = (i % 7) * 2 + 6;
        if (i == 6 || i == 7 || i == 0) {
            FUN_a00b32e4(1, 1, 0x629a, 2, row - 1, 3, c);
            FUN_a00b32e4(1, 1, 0x629a, 2, row, 3, c + 3);
            FUN_a00b32e4(1, 1, 0x629a, 2, row + 1, 3, c + 6);
        } else {
            FUN_a00b32e4(1, 1, 0x659a, 2, row, 3, c);
        }
    }
}

static void mark(unsigned char b, unsigned char c1, unsigned char c2)
{
    unsigned char y;

    if (b < 7)
        y = b * 2 + 6;
    else
        y = b * 2 - 8;
    FUN_a0146b20(0, 0x28, y, 1, c1, 0);
    FUN_a0146b20(0, 0x29, y, 1, c2, 0);
}

void FUN_a00b1004(unsigned char page, unsigned char flag)
{
    unsigned char i;

    FUN_a00b5080();
    FUN_a00b5378();
    frame();
    FUN_a00a8c88();
    switch (page) {
    case 0:
        FUN_a00b4144(1, 1);
        FUN_a00b4144(1, 2);
        FUN_a00ad02c(0, 0);
        FUN_a00b617c();
        if (flag) {
            FUN_a00a900c(0, 2);
            FUN_a00a9650(DAT_a802d290.b182, 0);
            FUN_a00a9650(DAT_a802d290.b182, 1);
            mark(DAT_a802d290.b182, 0, 0);
        } else {
            FUN_a00a900c(0, 1);
            FUN_a00a9650(DAT_a802d290.b182, 2);
            mark(DAT_a802d290.b182, 0xf, 0x10);
        }
        break;
    case 2:
        FUN_a00b4144(2, 1);
        FUN_a00b4144(2, 2);
        FUN_a0146b50(0x92, 0);
        FUN_a0146b6c(0, 0);
        for (i = 0; i <= 2; i++) {
            if (!FUN_a00aa520(i))
                FUN_a0146a80(0x14, i * 2 + 6, 0xf, 0x292, 0);
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_00188634, i * 29 + DAT_a802d290.b008), 0);
        }
        FUN_a00b6d58();
        FUN_a00b6bec(FUN_a00b6b88(DAT_a802d290.b181, 0) / 7);
        if (flag) {
            FUN_a00a900c(0, 2);
            FUN_a00a9650(FUN_a00b6b88(DAT_a802d290.b181, 0) % 7, 0);
            FUN_a00a9650(FUN_a00b6b88(DAT_a802d290.b181, 0) % 7, 1);
        } else {
            FUN_a00a900c(0, 1);
            FUN_a00a9650(FUN_a00b6b88(DAT_a802d290.b181, 0) % 7, 2);
            mark(FUN_a00b6b88(DAT_a802d290.b181, 0) % 7, 0xf, 0x10);
        }
        break;
    case 7:
        func_0x4008e2a4();
        for (i = 5; i <= 0x15; i++) {
            FUN_a0146a80(1, i, 0x11, 0x792, 0);
            FUN_a0146b20(0, 1, i, 0x11, 0, 0);
        }
        cols(1);
        FUN_a00b3d14(1);
        FUN_a00aa83c(0);
        FUN_a00ac718(0x35);
        FUN_a00b4144(8, 1);
        FUN_a00b4144(8, 2);
        FUN_a00a900c(1, 1);
        break;
    }
    FUN_a00d4780();
    FUN_a0146dc0(1, 0);
}
