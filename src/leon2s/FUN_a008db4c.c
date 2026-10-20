/* leon2s FUN_a008db4c @ 0xa008db4c  MATCH (-mcpu=v8 -Os -g)
 * Calls FUN_a00a80cc(port, 1, 8, 8, 1) when param_2 is non-zero, else FUN_a00a80cc(port, 1, 8, 8, 0), as a tail
 * call; no return value. Both parameters are bytes (btst 0xff, %o1 and and %o0, 0xff, %g1 in the target).
 */
extern int FUN_a00a80cc();

void FUN_a008db4c(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a80cc(param_1, 1, 8, 8, 1);
    else
        FUN_a00a80cc(param_1, 1, 8, 8, 0);
    return;
}
