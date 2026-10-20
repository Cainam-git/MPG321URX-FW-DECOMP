/* leon2m FUN_a013782c @ 0xa013782c (-mcpu=v8 -O2 -g)
 * Sends command 0xF3 with the two byte parameters as 2 data bytes, FUN_a01370dc(0xf3, 2, buf, 0), then calls
 * FUN_a0137344(1). Both call results are discarded; no return value. Same shape as FUN_a0138180 and FUN_a0138674
 * with other constants.
 */
extern void FUN_a01370dc();
extern int FUN_a0137344();

void FUN_a013782c(unsigned char param_1, unsigned char param_2)
{
    unsigned char local[4] = {param_1, param_2};
    FUN_a01370dc(0xf3, 2, local, 0);
    FUN_a0137344(1);
}
