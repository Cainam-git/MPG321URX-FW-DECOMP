/* leon2s FUN_a008df40 @ 0xa008df40 (-mcpu=v8 -Os -g)
 * This function checks if `param_2` is non-zero. If it is, it calls FUN_a00a8054 with (param_1, 1, 9, 0x43). If param_2 is zero, it calls with (param_1, 1, 9, 0x42). The function returns nothing (void). The structure matches the similar finished functions shown in the examples - it's a simple if/else with a call in each branch, both with the same first three arguments but different last constant. The `btst 0xff` in the assembly corresponds to testing the full byte value of `param_2`, which is naturally what the C comparison `param_2 != 0` does for an `unsigned char` parameter.
 */
extern int FUN_a00a8054();

void FUN_a008df40(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a8054(param_1, 1, 9, 0x43);
    else
        FUN_a00a8054(param_1, 1, 9, 0x42);
    return;
}
