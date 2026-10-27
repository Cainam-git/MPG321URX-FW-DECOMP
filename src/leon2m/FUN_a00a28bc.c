/* FUN_a00a28bc (leon2m 0xa00a28bc-0xa00a2928, 108 bytes), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a01461dc(1, table, 0) for the five halfword tables DAT_a8024194, DAT_a8024170, DAT_a8024104,
 * DAT_a80240ec and DAT_a80240e0 in that order (the last as a tail call). Called by FUN_a008a4a8, FUN_a008ce90,
 * FUN_a008d2f8, FUN_a00b50d8.
 */
extern unsigned short DAT_a8024194[], DAT_a8024170[], DAT_a8024104[], DAT_a80240ec[], DAT_a80240e0[];
extern void FUN_a01461dc(int, unsigned short *, int);

void FUN_a00a28bc(void)
{
    FUN_a01461dc(1, DAT_a8024194, 0);
    FUN_a01461dc(1, DAT_a8024170, 0);
    FUN_a01461dc(1, DAT_a8024104, 0);
    FUN_a01461dc(1, DAT_a80240ec, 0);
    FUN_a01461dc(1, DAT_a80240e0, 0);
}
