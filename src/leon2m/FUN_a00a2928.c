/* FUN_a00a2928 (leon2m 0xa00a2928-0xa00a29a8, 128 bytes), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a01461dc(1, table, 0) for the six halfword tables DAT_a8024188, DAT_a8024170, DAT_a8024110,
 * DAT_a80240a4, DAT_a80240c8 and DAT_a80240bc in that order (the last as a tail call). Called by FUN_a00b50d8.
 * Source form: the form of FUN_a00a28bc.
 */
extern unsigned short DAT_a8024188[], DAT_a8024170[], DAT_a8024110[], DAT_a80240a4[], DAT_a80240c8[], DAT_a80240bc[];
extern void FUN_a01461dc(int, unsigned short *, int);

void FUN_a00a2928(void)
{
    FUN_a01461dc(1, DAT_a8024188, 0);
    FUN_a01461dc(1, DAT_a8024170, 0);
    FUN_a01461dc(1, DAT_a8024110, 0);
    FUN_a01461dc(1, DAT_a80240a4, 0);
    FUN_a01461dc(1, DAT_a80240c8, 0);
    FUN_a01461dc(1, DAT_a80240bc, 0);
}
