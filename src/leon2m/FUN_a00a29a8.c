/* leon2m FUN_a00a29a8 @ 0xa00a29a8-0xa00a2a38 (36 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00b50d8.
 * Calls FUN_a01461dc(1, rec, k) for the records 0xa8024188, 0xa802417c, 0xa8024170 (k 0), 0xa8024170 (k 1),
 * 0xa8024164, 0xa80240a4 and, as a tail call, 0xa80240bc (k 0).
 */
extern unsigned short DAT_a8024188[], DAT_a802417c[], DAT_a8024170[], DAT_a8024164[], DAT_a80240a4[],
    DAT_a80240bc[];
extern void FUN_a01461dc(int, unsigned short *, int);

void FUN_a00a29a8(void)
{
    FUN_a01461dc(1, DAT_a8024188, 0);
    FUN_a01461dc(1, DAT_a802417c, 0);
    FUN_a01461dc(1, DAT_a8024170, 0);
    FUN_a01461dc(1, DAT_a8024170, 1);
    FUN_a01461dc(1, DAT_a8024164, 0);
    FUN_a01461dc(1, DAT_a80240a4, 0);
    FUN_a01461dc(1, DAT_a80240bc, 0);
}
