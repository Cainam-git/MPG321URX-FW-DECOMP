/* leon2m FUN_a00a900c @ 0xa00a900c-0xa00a93bc (944 bytes), flags -mcpu=v8 -O3 -g. About 150 call sites.
 * row = sel * 2 - 9 for sel > 6, else sel * 2 + 5. Values for mode 1: c1 = 0x392, c2 = 0x742, c3 = 0x589a; for any
 * other mode: c1 = 0xb92, c2 = 0x7c2, c3 = 0x5b9a. func_0x4008e2a4(). mode 0: FUN_a0146c40(6, 0, 0),
 * FUN_a014667c(6, 0, 0, 0, 0, 0xc, 0, 0, 0, 0, 0), FUN_a0146870(6, 0x1c8, row * 36 + 0x16, 0x38f, row * 36 + 0x55, 0),
 * FUN_a0146c40(6, 1, 0). Otherwise FUN_a0146c40(6, 0, 0) unless FUN_a0090fcc() (read again for each test) is in
 * 30..34 or 35..37; FUN_a0146a80(0x14, row, 0x11, c1, 0) and (0x14, row + 1, 0x11, c2, 0); for mode 1
 * FUN_a0146a80(0x22, row + 1, 3, 0x342, 0) and, when the byte DAT_a802b08f is not 3, 5, 6 or 8,
 * FUN_a0146b20(0, 0x22, row + 1, 3, 0, 0); FUN_a0146a80(0x14, row + 2, 0x11, c1, 0). Then mode 1:
 * FUN_a00b3ed0(1, 0x13, row, 0x13), FUN_a00b32e4(0, 1, c3, 0x13, row, 3, 0xa6), FUN_a0146b20(0, 0x14, row, 0x11,
 * 0x30, 0), FUN_a0146b20(0, 0x14, row + 2, 0x11, 0x31, 0), FUN_a00b32e4(0, 1, c3, 0x25, row, 3, 0xa9),
 * FUN_a0146c40(1, 1, 0), FUN_a0146c40(2, 1, 0); other modes: FUN_a0146b20 with 0x32 / 0x33 for row / row + 2 and
 * the two FUN_a00b32e4 calls.
 * Source form: the values are set in three arms (mode 1, mode 0, other) whose last two bodies are identical
 * (register choice); the DAT_a802b08f 6 / 8 / mode tests are nested ifs (branches), the 3 / 5 tests one &&.
 */
extern unsigned char DAT_a802b08f;
extern void func_0x4008e2a4(void);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014667c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a900c(unsigned char sel, unsigned char mode)
{
    unsigned char row;
    unsigned short c1, c2, c3;

    if (sel > 6)
        row = sel * 2 - 9;
    else
        row = sel * 2 + 5;
    if (mode == 1) {
        c3 = 0x589a;
        c1 = 0x392;
        c2 = 0x742;
    } else if (mode == 0) {
        c3 = 0x5b9a;
        c1 = 0xb92;
        c2 = 0x7c2;
    } else {
        c3 = 0x5b9a;
        c1 = 0xb92;
        c2 = 0x7c2;
    }
    func_0x4008e2a4();
    if (mode == 0) {
        FUN_a0146c40(6, 0, 0);
        FUN_a014667c(6, 0, 0, 0, 0, 0xc, 0, 0, 0, 0, 0);
        FUN_a0146870(6, 0x1c8, row * 36 + 0x16, 0x38f, row * 36 + 0x55, 0);
        FUN_a0146c40(6, 1, 0);
        return;
    }
    if ((FUN_a0090fcc() < 30 || FUN_a0090fcc() > 34) && (FUN_a0090fcc() < 35 || FUN_a0090fcc() > 37))
        FUN_a0146c40(6, 0, 0);
    FUN_a0146a80(0x14, row, 0x11, c1, 0);
    FUN_a0146a80(0x14, row + 1, 0x11, c2, 0);
    if (mode == 1)
        FUN_a0146a80(0x22, row + 1, 3, 0x342, 0);
    if (DAT_a802b08f != 3 && DAT_a802b08f != 5)
        if (DAT_a802b08f != 6)
            if (DAT_a802b08f != 8)
                if (mode == 1)
                    FUN_a0146b20(0, 0x22, row + 1, 3, 0, 0);
    FUN_a0146a80(0x14, row + 2, 0x11, c1, 0);
    if (mode == 1) {
        FUN_a00b3ed0(1, 0x13, row, 0x13);
        FUN_a00b32e4(0, 1, c3, 0x13, row, 3, 0xa6);
        FUN_a0146b20(0, 0x14, row, 0x11, 0x30, 0);
        FUN_a0146b20(0, 0x14, row + 2, 0x11, 0x31, 0);
        FUN_a00b32e4(0, 1, c3, 0x25, row, 3, 0xa9);
        FUN_a0146c40(1, 1, 0);
        FUN_a0146c40(2, 1, 0);
    } else {
        FUN_a0146b20(0, 0x14, row, 0x11, 0x32, 0);
        FUN_a0146b20(0, 0x14, row + 2, 0x11, 0x33, 0);
        FUN_a00b32e4(0, 1, c3, 0x13, row, 3, 0xa6);
        FUN_a00b32e4(0, 1, c3, 0x25, row, 3, 0xa9);
    }
}
