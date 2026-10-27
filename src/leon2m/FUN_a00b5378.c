/* leon2m FUN_a00b5378 @ 0xa00b5378 (-mcpu=v8 -O3 -g). Called by FUN_a00911a0, FUN_a0094438 and FUN_a00b1004.
 * Fixed call sequence: the body of FUN_a00b5080 (FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0), byte 0xa802b08f = 0x24,
 * FUN_a0146dc0(0, 1), clears bit 15 of halfword 0xa802d032), func_0x4008e2a4() twice, FUN_a00b50d8(0), the body of
 * FUN_a00b52f8(0x3c, 0x17, 0x792), FUN_a014654c((FUN_a014837c(0) - 1440) / 2, 0x4a4, 0), then FUN_a0146a80 /
 * FUN_a0146b20 calls (rows 1..0x15 in a loop with columns 0 and 0x3b), FUN_a00a550c(), 33 FUN_a00b32e4 calls with
 * fixed arguments, FUN_a00a7aec(0), FUN_a00b3d14(0), byte 0xa802d419 = 0xff, FUN_a00ab4bc(), FUN_a0146b50(0x1e5, 0),
 * FUN_a0146b6c(2, 0), FUN_a0146a80(0x37, 9, 4, 0x596, 0), FUN_a00a31a4(0, 0x37, 9, 4, FUN_a00a3844(0x1928b0,
 * byte 0xa802d298 + 0xae), 0), FUN_a00b34d4(0, 1), FUN_a00a9468(2, 5), (0, 0), (1, 2), FUN_a00b3860() and clears
 * byte 0xa802d433.
 * Source form: FUN_a00b5080 and FUN_a00b52f8 (the routines just before this one) are copied here as static
 * functions and inlined; the bytes of 0xa802d290 are indexed from one array symbol (one base register).
 */
struct Rcff4 { unsigned char pad[0x3e]; unsigned short b15 : 1, rest : 15; };
extern struct Rcff4 DAT_a802cff4;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_001928b0[];
extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(int, int, int);
extern void FUN_a0146ab0(int, int);
extern int FUN_a0146108(int);
extern void func_0x4008e2a4(void);
extern void FUN_a00b50d8(unsigned int);
extern unsigned short FUN_a014837c(int);
extern void FUN_a014654c(unsigned short, unsigned short, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00a550c(void);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void FUN_a00a7aec(unsigned char);
extern void FUN_a00b3d14(unsigned char);
extern void FUN_a00ab4bc(void);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b3860(void);

static void layout_reset(void)
{
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    DAT_a802b08f = 0x24;
    FUN_a0146dc0(0, 1);
    DAT_a802cff4.b15 = 0;
}

static int layout_init(int param_1, int param_2, int param_3)
{
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    FUN_a0146648(0, 0, 0, 0, 0);
    FUN_a014613c((unsigned short)param_1, param_2 & 0xff, 0);
    FUN_a0146518(DAT_a802d290[0xd], DAT_a802d290[0xe], 0);
    FUN_a0146ab0((unsigned short)param_3, 0);
    return FUN_a0146108(0);
}

void FUN_a00b5378(void)
{
    unsigned char i;
    unsigned short y;

    layout_reset();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a00b50d8(0);
    layout_init(0x3c, 0x17, 0x792);
    FUN_a014654c((FUN_a014837c(0) - 1440) / 2, 0x4a4, 0);
    FUN_a0146a80(0, 0, 0x3c, 0x8a2, 0);
    FUN_a0146b20(0, 0, 0, 1, 0xb, 0);
    FUN_a0146b20(0, 1, 0, 0x3a, 0xc, 0);
    FUN_a0146b20(0, 0x3b, 0, 1, 0xd, 0);
    for (i = 0; i <= 0x14; i++) {
        y = i + 1;
        FUN_a0146a80(0, y, 1, 0x8a2, 0);
        FUN_a0146a80(0x3b, y, 1, 0x8a2, 0);
        FUN_a0146b20(0, 0, y, 1, 0xe, 0);
        FUN_a0146b20(0, 0x3b, y, 1, 0xf, 0);
    }
    FUN_a0146a80(0, 0x16, 0x3c, 0x8a2, 0);
    FUN_a0146b20(0, 0, 0x16, 1, 0x10, 0);
    FUN_a0146b20(0, 1, 0x16, 0x3a, 0x11, 0);
    FUN_a0146b20(0, 0x3b, 0x16, 1, 0x12, 0);
    FUN_a00a550c();
    FUN_a0146a80(0, 3, 0x11, 0x14aa, 0);
    FUN_a0146b20(0, 0, 3, 1, 0x23, 0);
    FUN_a0146b20(0, 1, 3, 1, 0x24, 0);
    FUN_a0146b20(0, 2, 3, 9, 0x25, 0);
    FUN_a0146b20(0, 0xb, 3, 1, 0x26, 0);
    FUN_a0146b20(0, 0xc, 3, 1, 0x27, 0);
    FUN_a0146b20(0, 0xd, 3, 1, 0x28, 0);
    FUN_a0146b20(0, 0xe, 3, 3, 0x29, 0);
    FUN_a0146a80(0x11, 3, 0x2b, 0x179e, 0);
    FUN_a00b32e4(1, 1, 0x179e, 0x11, 3, 4, 1);
    FUN_a0146b20(0, 0x15, 3, 2, 5, 0);
    FUN_a0146b20(0, 0x17, 3, 1, 6, 0);
    FUN_a0146b20(0, 0x18, 3, 10, 7, 0);
    FUN_a0146b20(0, 0x22, 3, 1, 8, 0);
    FUN_a0146b20(0, 0x23, 3, 1, 9, 0);
    FUN_a0146b20(0, 0x24, 3, 10, 10, 0);
    FUN_a0146b20(0, 0x2e, 3, 1, 0xb, 0);
    FUN_a0146b20(0, 0x2f, 3, 3, 0xc, 0);
    FUN_a00b32e4(1, 1, 0x179e, 0x32, 3, 10, 0xd);
    FUN_a00b32e4(0, 1, 0x992, 0x16, 1, 2, 0x24);
    FUN_a00b32e4(0, 1, 0x992, 0x21, 1, 2, 0x24);
    FUN_a00b32e4(0, 1, 0x992, 0x28, 1, 2, 0x24);
    FUN_a00b32e4(0, 1, 0x992, 0x35, 1, 2, 0x24);
    FUN_a00b32e4(0, 0, 0x992, 0x35, 4, 0x12, 0x26);
    FUN_a00b32e4(0, 0, 0x992, 0x35, 0x16, 1, 0x27);
    FUN_a00b32e4(1, 1, 0x21aa, 10, 0, 5, 0x2a);
    FUN_a00b32e4(1, 1, 0x3092, 9, 1, 2, 0x13);
    FUN_a00b32e4(1, 0, 0x21aa, 0xb, 1, 1, 0x2f);
    FUN_a00b32e4(1, 1, 0x3392, 0xc, 1, 2, 0x15);
    FUN_a00b32e4(1, 0, 0x3092, 0x3a, 2, 1, 0x17);
    FUN_a00b32e4(0, 1, 0x21aa, 0x3b, 1, 2, 0x30);
    FUN_a00b32e4(1, 1, 0x3292, 0x38, 4, 2, 0x18);
    FUN_a00b32e4(1, 1, 0x3292, 0x38, 5, 1, 0x1a);
    FUN_a00b32e4(1, 1, 0x249a, 0x3a, 4, 2, 0x32);
    FUN_a00b32e4(1, 1, 0x249a, 0x39, 5, 3, 0x34);
    FUN_a00b32e4(1, 0, 0x3092, 0x24, 0x15, 1, 0x1b);
    FUN_a00b32e4(1, 1, 0x3392, 0x26, 0x15, 2, 0x1c);
    FUN_a00b32e4(1, 1, 0x279a, 0x25, 0x15, 1, 0x37);
    FUN_a00b32e4(1, 1, 0x279a, 0x23, 0x16, 3, 0x38);
    FUN_a00b32e4(1, 1, 0x2aaa, 0x26, 0x16, 1, 0x3b);
    FUN_a00b32e4(1, 1, 0x2d9a, 0x28, 0x15, 2, 0x3c);
    FUN_a00b32e4(1, 1, 0x2d9a, 0x27, 0x16, 3, 0x3e);
    FUN_a00b32e4(1, 1, 0x3292, 0x33, 0x14, 2, 0x1e);
    FUN_a00b32e4(1, 1, 0x3392, 0x30, 0x15, 2, 0x20);
    FUN_a00b32e4(1, 1, 0x3292, 0x33, 0x15, 2, 0x22);
    FUN_a00b32e4(1, 1, 0x249a, 0x35, 0x14, 1, 0x41);
    FUN_a00b32e4(1, 1, 0x249a, 0x32, 0x15, 1, 0x42);
    FUN_a00b32e4(1, 1, 0x249a, 0x35, 0x15, 1, 0x43);
    FUN_a00b32e4(1, 1, 0x249a, 0x2f, 0x16, 5, 0x44);
    FUN_a00a7aec(0);
    FUN_a00b3d14(0);
    DAT_a802d290[0x189] = 0xff;
    FUN_a00ab4bc();
    FUN_a0146b50(0x1e5, 0);
    FUN_a0146b6c(2, 0);
    FUN_a0146a80(0x37, 9, 4, 0x596, 0);
    FUN_a00a31a4(0, 0x37, 9, 4, FUN_a00a3844(DAT_001928b0, DAT_a802d290[8] + 0xae), 0);
    FUN_a00b34d4(0, 1);
    FUN_a00a9468(2, 5);
    FUN_a00a9468(0, 0);
    FUN_a00a9468(1, 2);
    FUN_a00b3860();
    DAT_a802d290[0x1a3] = 0;
}
