/* leon2m FUN_a01422f4 @ 0xa01422f4 (-mcpu=v8 -O2 -g)
 * Returns 1 when param_1 <= 1, else 0. param_1 is unsigned int, which gives the unsigned branch bleu (a signed
 * parameter gives ble); 'mov 1, %o0' sits in the branch delay slot, single return point, 6 instructions.
 */
int FUN_a01422f4(unsigned int param_1)
{
    if (param_1 <= 1)
        return 1;
    return 0;
}
