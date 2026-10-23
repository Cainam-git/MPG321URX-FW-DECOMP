/* leon2s FUN_a00add0c @ 0xa00add0c (-mcpu=v8 -Os -g)
 * Calls FUN_a00a6c98(p1, 3, 0x20, 1) when p2 != 0, otherwise FUN_a00a6c98(p1, 3, 0x20, 0). Same code as
 * FUN_a0087d50 with other constants.
 */
extern int FUN_a00a6c98();

void FUN_a00add0c(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a6c98(param_1, 0x3, 0x20, 1);
    else
        FUN_a00a6c98(param_1, 0x3, 0x20, 0);
    return;
}
