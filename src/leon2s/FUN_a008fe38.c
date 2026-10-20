/* leon2s FUN_a008fe38 @ 0xa008fe38  MATCH (-mcpu=v8 -Os -g)
 * This function selects between two configuration values (6 or 9) based on a flag parameter, and passes both to a register-writing routine. The main uncertainty is whether the second `mov 0x135, %o1` in the else branch (which appears redundant) will be optimized away by the compiler or kept as in the target — but since the similar finished functions show the same pattern (each branch calls with the same second argument), this should match.
 */
extern void FUN_a00a65c4(unsigned int param_1, unsigned short param_2, unsigned int param_3);

void FUN_a008fe38(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a65c4(param_1, 0x135, 6);
    else
        FUN_a00a65c4(param_1, 0x135, 9);
}
