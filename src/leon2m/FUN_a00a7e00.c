/* leon2m FUN_a00a7e00 @ 0xa00a7e00-0xa00a813c (207 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a00912ac,
 * FUN_a009145c.
 * Parameter m. row = m * 2 - 9 for m > 6, else m * 2 + 5. Calls FUN_a0146c40(1, 0, 0), FUN_a0146c40(2, 0, 0), ROM
 * func_0x4008e2a4() and FUN_a0146a80(1, row, 1, 0x792, 0). For m 0, 6 and 7: FUN_a0146a80(2, y, 3, 0x629a, 0),
 * FUN_a00b32e4(1, 0, 0x792, 1, y, 1, 0) and FUN_a00b32e4(1, 0, 0x792, 5, y, 0xd, 0) for y = row and row + 2.
 * Otherwise: m 1 / 8 call FUN_a00b32e4(1, 1, 0x629a, 2, row, 3, 0x4f / 0x76) and the two row calls, then
 * FUN_a00b32e4(1, 0, 0x792, 1, row + 2, 0x11, 0); other m call FUN_a00b32e4(1, 0, 0x792, 1, row / row + 2, 0x11,
 * 0); m 5 adds FUN_a00b32e4(1, 1, 0x629a, 2, row + 2, 3, 100); c becomes 0x659a (else 0x629a). Ends with
 * FUN_a00b32e4(1, 0, 0x792, 1, row + 1, 1, 0), FUN_a0146a80(2, row + 1, 3, c, 0), FUN_a0146a80(5, row + 1, 0xd,
 * 0x792, 0) and FUN_a0146b20(0, 0x11, row + 1, 1, 0, 0).
 * Source form: c is assigned after the row selection; the 1/8 test is written 'm != 1 && m != 8' with that arm
 * second; in the m != 0/6/7 branch row + 2 goes through the unsigned char local y, elsewhere it is passed as
 * row + 2 (converted to each parameter type at the call).
 */
extern void FUN_a0146c40(unsigned char, unsigned char, unsigned char);
extern void func_0x4008e2a4(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);

void FUN_a00a7e00(unsigned char m)
{
    unsigned char row;
    unsigned short c;
    unsigned char y;

    if (m > 6)
        row = m * 2 - 9;
    else
        row = m * 2 + 5;
    c = 0x629a;
    FUN_a0146c40(1, 0, 0);
    FUN_a0146c40(2, 0, 0);
    func_0x4008e2a4();
    FUN_a0146a80(1, row, 1, 0x792, 0);
    if ((unsigned char)(m - 6) < 2 || m == 0) {
        FUN_a0146a80(2, row, 3, 0x629a, 0);
        FUN_a00b32e4(1, 0, 0x792, 1, row, 1, 0);
        FUN_a00b32e4(1, 0, 0x792, 5, row, 0xd, 0);
        FUN_a0146a80(2, row + 2, 3, 0x629a, 0);
        FUN_a00b32e4(1, 0, 0x792, 1, row + 2, 1, 0);
        FUN_a00b32e4(1, 0, 0x792, 5, row + 2, 0xd, 0);
    } else {
        if (m != 1 && m != 8) {
            FUN_a00b32e4(1, 0, 0x792, 1, row, 0x11, 0);
            y = row + 2;
            FUN_a00b32e4(1, 0, 0x792, 1, y, 0x11, 0);
        } else {
            if (m == 8)
                FUN_a00b32e4(1, 1, 0x629a, 2, row, 3, 0x76);
            else if (m == 1)
                FUN_a00b32e4(1, 1, 0x629a, 2, row, 3, 0x4f);
            FUN_a00b32e4(1, 0, 0x792, 1, row, 1, 0);
            FUN_a00b32e4(1, 0, 0x792, 5, row, 0xd, 0);
            y = row + 2;
            FUN_a00b32e4(1, 0, 0x792, 1, y, 0x11, 0);
        }
        if (m == 5)
            FUN_a00b32e4(1, 1, 0x629a, 2, y, 3, 100);
        c = 0x659a;
    }
    FUN_a00b32e4(1, 0, 0x792, 1, row + 1, 1, 0);
    FUN_a0146a80(2, row + 1, 3, c, 0);
    FUN_a0146a80(5, row + 1, 0xd, 0x792, 0);
    FUN_a0146b20(0, 0x11, row + 1, 1, 0, 0);
}
