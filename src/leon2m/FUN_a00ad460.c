/* leon2m FUN_a00ad460 @ 0xa00ad460  (-mcpu=v8 -O3 -g)
 * Calls func_0x4008e2a4(), then FUN_a00b32e4(1, 0, c, 7, q, n, 0) for q = 6..0x15 except 5 and 7: q = 6 with c =
 * 0x7C2 and n = 10, the others with c = 0x792 and n = 0xB. Then FUN_a00b3d14(1), FUN_a00b4144(7, 2),
 * func_0x4008e2a4() again, for q = 5..0x14 FUN_a0146b20(0, 0x13, q, 0x13, 0, 0) and FUN_a0146a80(0x13, q, 0x13,
 * 0x792, 0), followed by FUN_a0146b20(0, 0x1C, 0x15, 2, 0, 0), FUN_a0146c40(5, 0, 0), FUN_a00ad1c0(0),
 * FUN_a00a900c(0, 2) and FUN_a00b3860(). Finally DAT_a802d419 = 0xFF and FUN_a00b34d4(0, 4) is tail-called.
 * Callers: FUN_a0098c08, FUN_a009d234, FUN_a009d4e8.
 * Source form: the row-5 and row-7 tests are two nested ifs (with '&&' the two tests are combined into one
 * flag test).
 */
extern unsigned char DAT_a802d419;
extern void func_0x4008e2a4(void);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3d14(unsigned char);
extern void FUN_a00b4144(int, int);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a00ad1c0(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00b3860(void);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a00ad460(void)
{
    unsigned char i;

    func_0x4008e2a4();
    for (i = 6; i <= 0x15; i++) {
        if (i != 5)
            if (i != 7) {
                if (i == 6)
                    FUN_a00b32e4(1, 0, 0x7c2, 7, 6, 10, 0);
                else
                    FUN_a00b32e4(1, 0, 0x792, 7, i, 0xb, 0);
            }
    }
    FUN_a00b3d14(1);
    FUN_a00b4144(7, 2);
    func_0x4008e2a4();
    for (i = 5; i <= 0x14; i++) {
        FUN_a0146b20(0, 0x13, i, 0x13, 0, 0);
        FUN_a0146a80(0x13, i, 0x13, 0x792, 0);
    }
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
    FUN_a00ad1c0(0);
    FUN_a00a900c(0, 2);
    FUN_a00b3860();
    DAT_a802d419 = 0xff;
    FUN_a00b34d4(0, 4);
}
