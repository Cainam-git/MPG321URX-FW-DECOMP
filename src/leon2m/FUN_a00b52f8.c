/* leon2m FUN_a00b52f8 @ 0xa00b52f8 (-mcpu=v8 -O2 -g)
 * FUN_a0146dc0(0, 0); FUN_a0146c40(8, 0, 0); FUN_a0146648(0, 0, 0, 0, 0); FUN_a014613c((u16)p1, p2 & 0xff, 0);
 * FUN_a0146518(byte 0xA802D29D, byte 0xA802D29E, 0); FUN_a0146ab0((u16)p3, 0); returns FUN_a0146108(0) (tail call).
 */
extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(int, int, int);
extern void FUN_a0146ab0(int, int);
extern int FUN_a0146108(int);

int FUN_a00b52f8(int param_1, int param_2, int param_3) {
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    FUN_a0146648(0, 0, 0, 0, 0);
    FUN_a014613c((unsigned short)param_1, param_2 & 0xff, 0);
    {
        unsigned char *p = (unsigned char *)0xa802d290;
        FUN_a0146518(p[0xd], p[0xe], 0);
    }
    FUN_a0146ab0((unsigned short)param_3, 0);
    return FUN_a0146108(0);
}
