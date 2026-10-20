/* leon2s FUN_a008e054 @ 0xa008e054 (-mcpu=v8 -Os -g)
 * Calls FUN_a00a80cc(param_1, 1, 7, 0x80, flag) with flag = 1 when param_2 is non-zero, else 0. The call is written
 * in both arms of the if/else; the firmware loads mov 1, %o1 on both paths.
 */
extern int FUN_a00a80cc();

void FUN_a008e054(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a80cc(param_1, 1, 7, 0x80, 1);
    else
        FUN_a00a80cc(param_1, 1, 7, 0x80, 0);
    return;
}
