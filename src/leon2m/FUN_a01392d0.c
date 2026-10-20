/* leon2m FUN_a01392d0 @ 0xa01392d0 (-mcpu=v8 -O2 -g)
 * Stores the byte param_1 on the stack and calls FUN_a01370dc(0x30, 1, &param_1, 0). The function is void; no
 * value is set in %i0 before 'ret; restore'.
 */
extern int FUN_a01370dc();

void FUN_a01392d0(unsigned char param_1)
{
    FUN_a01370dc(0x30, 1, &param_1, 0);
    return 0;
}
