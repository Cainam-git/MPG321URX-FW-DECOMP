/* leon2s FUN_a008db90 @ 0xa008db90  MATCH (-mcpu=v8 -Os -g)
 * Calls FUN_a00a80cc(param_1, 1, 0x7F, 1, flag) with flag = 1 when param_2 is non-zero and 0 otherwise, written as
 * an if / else with two calls.
 */
extern int FUN_a00a80cc();

void FUN_a008db90(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a80cc(param_1, 1, 0x7f, 1, 1);
    else
        FUN_a00a80cc(param_1, 1, 0x7f, 1, 0);
    return;
}
