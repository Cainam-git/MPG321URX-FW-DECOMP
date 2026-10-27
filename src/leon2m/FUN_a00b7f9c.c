/* leon2m FUN_a00b7f9c @ 0xa00b7f9c-0xa00b83e4 (1096 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a0085984,
 * FUN_a00b83e4, FUN_a00b848c, FUN_a00b8668, FUN_a00b867c, FUN_a00b8774, FUN_a00b87d4. T = DAT_a802d290.
 * Start as in FUN_a00b8e7c: FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0), byte 0xa802b08f = 0x24, FUN_a0146dc0(0, 1),
 * bit 15 of 0xa802d032 cleared, func_0x4008e2a4(). page 0x11: FUN_a00b50d8(4) and the set-up calls with
 * FUN_a014613c(8, 3, 0), then FUN_a0146518(0x63, 0x62, 0); other pages: FUN_a00b50d8(3), the set-up calls with
 * FUN_a014613c(0xe, 5, 0) and FUN_a00a5714(0, 0), then FUN_a0146518(0x32, 0x32, 0). Then FUN_a0146b50(100, 0),
 * FUN_a0146b6c(2, 0), FUN_a0146ab0(0x792, 0), byte 0xa802b08f = page, and by page (jump table 0x11..0x1e):
 *  - 0x11: FUN_a0146ab0(0x970a, 0), FUN_a0146b20(1, j, i, 1, i * 8 + j, 0) for i = 0..2, j = 0..7,
 *    FUN_a014654c(0xe10, 0x48, 0);
 *  - 0x15: FUN_a0146518(0x32, 0x32, 0);
 *  - 0x17, 0x18: FUN_a00a31a4(1, 1, 2, 0xc, FUN_a00a3844(DAT_00192d8c, T.b008), 0);
 *  - 0x19: row 1 from DAT_00196b24 with FUN_a01445fc(T.b01e), or of T.b020 when T.b01f and byte 0xa802cff5 are
 *    both non-zero, then row 3 from DAT_00193008 with T.b008;
 *  - 0x1b: row 2 from DAT_00193008 with T.b008;
 *  - 0x1e: when bit 20 of word T+0xac is set, T.b01f is 0, FUN_a01445fc(FUN_a014448c(0)) is 0 and FUN_a0083d80()
 *    is not 0xff: row 1 from DAT_00196b24 with FUN_a01445fc(FUN_a014448c(0)) and row 3 from DAT_00192860 with
 *    FUN_a0083d80(); otherwise row 2 from DAT_00196b24 with FUN_a01445fc(FUN_a014448c(0)).
 * ("row r from table X with n" = FUN_a00a31a4(1, 1, r, 0xc, FUN_a00a3844(X, n), 0).) Ends with FUN_a0146dc0(1, 0).
 * Source form: in case 0x19 each arm has its own complete calls (the firmware keeps three copies of the row-1
 * call; a shared call or a ?: argument gives another argument order).
 */
struct Sys {
    unsigned char p00;
    unsigned char b01;
    unsigned char p02[0x3e - 2];
    struct { unsigned short b15 : 1, rest : 15; } h3e;
};
struct R290 {
    unsigned char p000[8];
    unsigned char b008;
    unsigned char p009[0x0d - 0x09];
    unsigned char b00d, b00e;
    unsigned char p00f[0x1e - 0x0f];
    unsigned char b01e, b01f, b020;
    unsigned char p021[0xac - 0x21];
    unsigned int w0ac;
};
extern struct Sys DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08f;
extern unsigned int DAT_00192d8c[], DAT_00193008[], DAT_00196b24[], DAT_00192860[];

extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void func_0x4008e2a4(void);
extern void FUN_a00b50d8(unsigned int);
extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146108(int);
extern void FUN_a00a5714(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a014654c(int, int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014448c(int);
extern unsigned char FUN_a0083d80(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

#define T DAT_a802d290

void FUN_a00b7f9c(unsigned char page)
{
    int a, b;
    unsigned char i, j;

    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    DAT_a802b08f = 0x24;
    FUN_a0146dc0(0, 1);
    DAT_a802cff4.h3e.b15 = 0;
    func_0x4008e2a4();
    if (page == 0x11) {
        FUN_a00b50d8(4);
        FUN_a0146dc0(0, 0);
        FUN_a0146c40(8, 0, 0);
        FUN_a0146648(0, 0, 0, 0, 0);
        FUN_a014613c(8, 3, 0);
        FUN_a0146518(T.b00d, T.b00e, 0);
        FUN_a0146ab0(0x792, 0);
        FUN_a0146108(0);
        a = 0x63;
        b = 0x62;
    } else {
        FUN_a00b50d8(3);
        FUN_a0146dc0(0, 0);
        FUN_a0146c40(8, 0, 0);
        FUN_a0146648(0, 0, 0, 0, 0);
        FUN_a014613c(0xe, 5, 0);
        FUN_a0146518(T.b00d, T.b00e, 0);
        FUN_a0146ab0(0x792, 0);
        FUN_a0146108(0);
        FUN_a00a5714(0, 0);
        a = 0x32;
        b = 0x32;
    }
    FUN_a0146518(a, b, 0);
    FUN_a0146b50(100, 0);
    FUN_a0146b6c(2, 0);
    FUN_a0146ab0(0x792, 0);
    DAT_a802b08f = page;
    switch (page) {
    case 0x11:
        FUN_a0146ab0(0x970a, 0);
        for (i = 0; i <= 2; i++)
            for (j = 0; j <= 7; j++)
                FUN_a0146b20(1, j, i, 1, i * 8 + j, 0);
        FUN_a014654c(0xe10, 0x48, 0);
        break;
    case 0x15:
        FUN_a0146518(0x32, 0x32, 0);
        break;
    case 0x17:
    case 0x18:
        FUN_a00a31a4(1, 1, 2, 0xc, FUN_a00a3844(DAT_00192d8c, T.b008), 0);
        break;
    case 0x19:
        if (T.b01f == 0) {
            FUN_a00a31a4(1, 1, 1, 0xc, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(T.b01e)), 0);
            FUN_a00a31a4(1, 1, 3, 0xc, FUN_a00a3844(DAT_00193008, T.b008), 0);
        } else {
            if (DAT_a802cff4.b01 == 0)
                FUN_a00a31a4(1, 1, 1, 0xc, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(T.b01e)), 0);
            else
                FUN_a00a31a4(1, 1, 1, 0xc, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(T.b020)), 0);
            FUN_a00a31a4(1, 1, 3, 0xc, FUN_a00a3844(DAT_00193008, T.b008), 0);
        }
        break;
    case 0x1b:
        FUN_a00a31a4(1, 1, 2, 0xc, FUN_a00a3844(DAT_00193008, T.b008), 0);
        break;
    case 0x1e:
        if ((T.w0ac & 0x100000) && T.b01f == 0 && FUN_a01445fc(FUN_a014448c(0)) == 0 && FUN_a0083d80() != 0xff) {
            FUN_a00a31a4(1, 1, 1, 0xc, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(FUN_a014448c(0))), 0);
            FUN_a00a31a4(1, 1, 3, 0xc, FUN_a00a3844(DAT_00192860, FUN_a0083d80()), 0);
        } else {
            FUN_a00a31a4(1, 1, 2, 0xc, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(FUN_a014448c(0))), 0);
        }
        break;
    }
    FUN_a0146dc0(1, 0);
}
