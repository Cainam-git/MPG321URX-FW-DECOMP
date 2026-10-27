/* leon2m FUN_a00b5d10 @ 0xa00b5d10-0xa00b60cc (956 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a0091648 and
 * FUN_a009eb38. T = DAT_a802d290.
 * Same set-up sequence as FUN_a00b8e7c: FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0), byte 0xa802b08f = 0x24,
 * FUN_a0146dc0(0, 1), bit 15 of 0xa802d032 cleared, func_0x4008e2a4() twice, FUN_a00b50d8(2), FUN_a0146dc0(0, 0),
 * FUN_a0146c40(8, 0, 0), FUN_a0146648(0, 0, 0, 0, 0), FUN_a014613c(0x16, 0x11, 0), FUN_a0146518(T.b00d, T.b00e, 0),
 * FUN_a0146ab0(0x792, 0), FUN_a0146108(0); then FUN_a014654c(0x780 - v * 11, 0x57c, 0) with v = FUN_a01198a0(0)
 * as a byte, FUN_a00a5908(0, 0, 2), FUN_a00a788c(5), FUN_a0146b6c(2, 0), FUN_a0146b50(0x60, 0),
 * FUN_a0146a80(3, 1, 0x10, 0x592, 0), FUN_a00a31a4(0, 3, 1, 0x10, FUN_a00a3844(DAT_001935bc, T.b008 + 0x91), 0).
 * Then FUN_a0146ab0(0x792, 0) before each of two loops i = 0, 1: FUN_a0146b20(1, i + 10, 3, 1, i + 0x16, 0) and
 * FUN_a0146b20(1, i + 10, 0xd, 1, i + 0x18, 0); rows i = 0..3 of DAT_00196b24 to FUN_a00a31a4(0, 6, i * 2 + 5,
 * 0xa, .., 0); FUN_a00ad86c(FUN_a01445fc(T.b01e), 1) and (.., 0); k = FUN_a01445fc(T.b01e) (minus 4 when above 3),
 * FUN_a0146b20(0, j + 4, k * 2 + 5, 1, j + 0x1c, 0) for j = 0, 1; T.b1a3 = T.b01e; FUN_a0146b6c(0, 0),
 * FUN_a0146a80(6, 0xf, 6, 0x592, 0), FUN_a0146a80(0xf, 0xf, 6, 0x592, 0), and FUN_a00a31a4(0, 6, 0xf, 1, ..) and
 * (0, 0xf, 0xf, 1, ..) with FUN_a00a3844(DAT_001928b0, T.b008) and (.., T.b008 + 0x74).
 * Source form: the two i + 10 loops compare with a limit variable n = 2 (cmp 2; bcs), the others with constants;
 * prototypes and record layout as in FUN_a00b8e7c.
 */
struct Sys {
    unsigned char p00[0x3e];
    struct { unsigned short b15 : 1, rest : 15; } h3e;
};
struct R290 {
    unsigned char p000[8];
    unsigned char b008;
    unsigned char p009[0x0d - 0x09];
    unsigned char b00d, b00e;
    unsigned char p00f[0x1e - 0x0f];
    unsigned char b01e;
    unsigned char p01f[0x1a3 - 0x1f];
    unsigned char b1a3;
};
extern struct Sys DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08f;
extern unsigned int DAT_001935bc[], DAT_00196b24[], DAT_001928b0[];

extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void func_0x4008e2a4(void);
extern void FUN_a00b50d8(unsigned int);
extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146108(int);
extern int FUN_a01198a0(int);
extern void FUN_a014654c(int, int, int);
extern void FUN_a00a5908(int, int, int);
extern void FUN_a00a788c(unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

#define T DAT_a802d290

void FUN_a00b5d10(void)
{
    unsigned char i, k, n;
    unsigned char v;

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
    v = FUN_a01198a0(0);
    FUN_a014654c((unsigned short)(0x780 - v * 11), 0x57c, 0);
    FUN_a00a5908(0, 0, 2);
    FUN_a00a788c(5);
    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x60, 0);
    FUN_a0146a80(3, 1, 0x10, 0x592, 0);
    FUN_a00a31a4(0, 3, 1, 0x10, FUN_a00a3844(DAT_001935bc, T.b008 + 0x91), 0);
    FUN_a0146ab0(0x792, 0);
    n = 2;
    for (i = 0; i < n; i++)
        FUN_a0146b20(1, i + 10, 3, 1, i + 0x16, 0);
    FUN_a0146ab0(0x792, 0);
    for (i = 0; i < n; i++)
        FUN_a0146b20(1, i + 10, 0xd, 1, i + 0x18, 0);
    for (i = 0; i <= 3; i++)
        FUN_a00a31a4(0, 6, i * 2 + 5, 0xa, FUN_a00a3844(DAT_00196b24, i), 0);
    FUN_a00ad86c(FUN_a01445fc(T.b01e), 1);
    FUN_a00ad86c(FUN_a01445fc(T.b01e), 0);
    k = FUN_a01445fc(T.b01e);
    if (k > 3)
        k -= 4;
    for (i = 0; i <= 1; i++)
        FUN_a0146b20(0, i + 4, k * 2 + 5, 1, i + 0x1c, 0);
    T.b1a3 = T.b01e;
    FUN_a0146b6c(0, 0);
    FUN_a0146a80(6, 0xf, 6, 0x592, 0);
    FUN_a0146a80(0xf, 0xf, 6, 0x592, 0);
    FUN_a00a31a4(0, 6, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008), 0);
    FUN_a00a31a4(0, 0xf, 0xf, 1, FUN_a00a3844(DAT_001928b0, T.b008 + 0x74), 0);
}
