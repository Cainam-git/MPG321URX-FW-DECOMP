/* leon2s FUN_a008fe6c @ 0xa008fe6c (-mcpu=v8 -Os -g)
 * Calls FUN_a00a67b8(param_1, 0xB5, 4, 1) when param_2 != 0 ('btst 0xff'), else FUN_a00a67b8(param_1, 0xB5, 4, 0).
 */
extern int FUN_a00a67b8();

void FUN_a008fe6c(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a67b8(param_1, 0xb5, 4, 1);
    else
        FUN_a00a67b8(param_1, 0xb5, 4, 0);
    return;
}
