/* leon2s FUN_a0094308 @ 0xa0094308  MATCH (-mcpu=v8 -Os -g)
 * Calls FUN_a00a80cc(param_1, 0, 0xD, 4, flag) with flag = 1 when param_2 is non-zero, else 0. The call is written
 * in both arms of the if/else, as in FUN_a008e054.
 */
extern int FUN_a00a80cc();

void FUN_a0094308(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a80cc(param_1, 0, 0xd, 4, 1);
    else
        FUN_a00a80cc(param_1, 0, 0xd, 4, 0);
    return;
}
