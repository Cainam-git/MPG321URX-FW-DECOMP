/* leon2m FUN_a009811c @ 0xa009811c-0xa0098280 (356 bytes), flags -mcpu=v8 -O3 -g.
 * Prints "PBP New Mode" (s_00108130); w = FUN_a014837c(0), h = FUN_a014837c(1). When bit 15 of halfword
 * 0xa802cff4+4 is set: sets its bit 10 and calls FUN_a00808ac(4, 0). Clears word 0xa802afec, calls FUN_a00b5080(),
 * func_0x4008e2a4() twice, FUN_a00a5e68(1); afec = 0x109; FUN_a0146c40(6, 0, 0); FUN_a014667c(6, 0, 0, 0, 0, 2,
 * 0, 0, 0, 0, 0). Byte DAT_a802d290+0x2f and byte 0xa802cff4+0x34 = 2. Halfwords 0xa802cff4+0x36 / +0x38 =
 * DAT_a802d290 halfwords +0x1f0 / +0x1f2 when bit 6 of word +0x1ec is set, else w / 2 and h. Then
 * FUN_a0146870(6, h36, 0, h36 + 4, h38, 0), prints "(x y) %d, %d" (s_00108140) with h36, h38 and calls
 * FUN_a0146c40(6, 1, 0) (tail call).
 * Source form: the 2 for byte +0x2f goes through an int local t (the firmware loads the constant 2 into two
 * registers for the two byte stores).
 */
struct Rcff4 {
    unsigned char pad[4];
    unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10;
    unsigned char pad6[0x34 - 6];
    unsigned char b34, pad35;
    unsigned short h36, h38;
};
struct R290 {
    unsigned char pad0[0x2f];
    unsigned char b2f;
    unsigned char pad30[0x1ec - 0x30];
    unsigned int w1ec;
    unsigned short h1f0, h1f2;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern char s_00108130[];
extern char s_00108140[];
extern int FUN_a00df170();
extern unsigned short FUN_a014837c(int);
extern void FUN_a00808ac(unsigned char, unsigned char);
extern void FUN_a00b5080(void);
extern void func_0x4008e2a4(void);
extern void FUN_a00a5e68(unsigned char on);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014667c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a009811c(void)
{
    unsigned short w, h;
    int t;

    FUN_a00df170(s_00108130);
    w = FUN_a014837c(0);
    h = FUN_a014837c(1);
    if (DAT_a802cff4.b15) {
        DAT_a802cff4.b10 = 1;
        FUN_a00808ac(4, 0);
    }
    _DAT_a802afec = 0;
    FUN_a00b5080();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a00a5e68(1);
    _DAT_a802afec = 0x109;
    FUN_a0146c40(6, 0, 0);
    FUN_a014667c(6, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    t = 2;
    DAT_a802d290.b2f = t;
    DAT_a802cff4.b34 = 2;
    if (DAT_a802d290.w1ec & 0x40) {
        DAT_a802cff4.h36 = DAT_a802d290.h1f0;
        DAT_a802cff4.h38 = DAT_a802d290.h1f2;
    } else {
        DAT_a802cff4.h36 = w / 2;
        DAT_a802cff4.h38 = h;
    }
    FUN_a0146870(6, DAT_a802cff4.h36, 0, (unsigned short)(DAT_a802cff4.h36 + 4), DAT_a802cff4.h38, 0);
    FUN_a00df170(s_00108140, DAT_a802cff4.h36, DAT_a802cff4.h38);
    FUN_a0146c40(6, 1, 0);
}
