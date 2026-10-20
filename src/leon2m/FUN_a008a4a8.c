/* leon2m FUN_a008a4a8 @ 0xa008a4a8 (-mcpu=v8 -O2 -g)
 * Fixed sequence of calls (FUN_a0146dc0, FUN_a0146298, FUN_a0146354, FUN_a0146194 ->
 * FUN_a0146370, FUN_a00a28bc, FUN_a0146c40, FUN_a014613c, FUN_a0146518, FUN_a0146ab0, three func_0x4008e2a4),
 * then a tail call FUN_a0146108(0, param_2, ..., param_6) that passes the incoming arguments on with param_1
 * replaced by 0. Source forms: the callees whose results are unused are declared void, which gives the firmware's
 * argument set-up for the two FUN_a0146dc0(0, 0) calls (clr %o0 before the call, clr %o1 in the delay slot); the
 * assignment param_1 = 0 before the FUN_a00a28bc call produces the firmware's clr %i0.
 */
extern void FUN_a0146dc0(int, int);                 /* 0xa0146dc0 */
extern void FUN_a0146298(int, int);                 /* 0xa0146298 */
extern void FUN_a0146354(int, int, int);            /* 0xa0146354 */
extern int FUN_a0146194(int, int);                  /* 0xa0146194 */
extern void FUN_a0146370(int, int, int);            /* 0xa0146370 */
extern void FUN_a00a28bc(void);                     /* 0xa00a28bc */
extern void FUN_a0146c40(int, int, int);            /* 0xa0146c40 */
extern void FUN_a014613c(int, int, int);            /* 0xa014613c */
extern void FUN_a0146518(int, int, int);            /* 0xa0146518 */
extern void FUN_a0146ab0(int, int);                 /* 0xa0146ab0 */
extern void func_0x4008e2a4(void);                  /* 0x4008e2a4 */
extern void FUN_a0146108(int, int, int, int, int, int); /* 0xa0146108 */

void FUN_a008a4a8(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int uVar1;

    FUN_a0146dc0(0, 0);
    FUN_a0146298(4, 0);
    FUN_a0146354(0x18, 0x24, 0);
    uVar1 = FUN_a0146194(0x18, 0x25);
    FUN_a0146370(0, (unsigned short)uVar1, 0);
    param_1 = 0;
    FUN_a00a28bc();
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    FUN_a014613c(0x18, 0x25, 0);
    FUN_a0146518(1, 0x62, 0);
    FUN_a0146ab0(0x790, 0);
    func_0x4008e2a4();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a0146108(param_1, param_2, param_3, param_4, param_5, param_6);
}
