/* leon2m FUN_a0137fa0 @ 0xa0137fa0 (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x43, 4, buf, 0) with the local bytes buf = {p1, 0, 0, 0}. Same code as FUN_a01381c4 with
 * other constants.
 * See FUN_a01381c4 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern int FUN_a01370dc();

void FUN_a0137fa0(unsigned char param_1)
{
    unsigned char local_10[4] = {param_1};
    FUN_a01370dc(0x43, 4, local_10, 0);
}
