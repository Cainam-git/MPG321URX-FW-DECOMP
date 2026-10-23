/* leon2m FUN_a0098c08 @ 0xa0098c08-0xa0098d4c (81 words).
 * FUN_a00a93bc((word 0xa802afec - 0x92) % 7). When byte DAT_a802d290+8 differs from byte 0xa8025c56, copies
 * 0xa8025c56 into it, calls FUN_a00a8c88(), then FUN_a00a87cc(n) with n = 4 for the value 0x1c, else 3 above
 * 0x14, 2 above 0xd, 1 above 6 and 0 otherwise, and FUN_a00ad460(). Then with b = byte DAT_a802d290+8:
 * FUN_a00a9650(b % 7, 0), FUN_a00a813c(1, b % 7, 1); stores 0x2a to word 0xa802afec and calls
 * FUN_a00a900c(0, 1) (tail call).
 * Source form: one FUN_a00a87cc call per arm of the if chain (GCC merges them into one call).
 */
struct D290 {
    unsigned char p000[8];
    unsigned char b008;
};
extern struct D290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a8c88(void);
extern void FUN_a00a87cc(unsigned char);
extern void FUN_a00ad460(void);

void FUN_a0098c08(void)
{
    FUN_a00a93bc((_DAT_a802afec - 0x92) % 7);
    if (DAT_a802d290.b008 != DAT_a8025c56) {
        DAT_a802d290.b008 = DAT_a8025c56;
        FUN_a00a8c88();
        if (DAT_a802d290.b008 == 0x1c)
            FUN_a00a87cc(4);
        else if (DAT_a802d290.b008 > 0x14)
            FUN_a00a87cc(3);
        else if (DAT_a802d290.b008 > 0xd)
            FUN_a00a87cc(2);
        else if (DAT_a802d290.b008 > 6)
            FUN_a00a87cc(1);
        else
            FUN_a00a87cc(0);
        FUN_a00ad460();
    }
    FUN_a00a9650(DAT_a802d290.b008 % 7, 0);
    FUN_a00a813c(1, DAT_a802d290.b008 % 7, 1);
    _DAT_a802afec = 0x2a;
    FUN_a00a900c(0, 1);
}
