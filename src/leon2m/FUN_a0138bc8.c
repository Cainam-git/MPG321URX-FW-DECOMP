/* leon2m FUN_a0138bc8 @ 0xa0138bc8 (-mcpu=v8 -O2 -g)
 * Sends {p1, p2, 0, 0} with FUN_a01370dc(0x86, 4, buf, 0) (4-byte stack buffer).
 */
extern int FUN_a01370dc();

void FUN_a0138bc8(unsigned char param_1, unsigned char param_2)
{
    unsigned char local_10[4] = {param_1, param_2};
    FUN_a01370dc(0x86, 4, local_10, 0);
}
