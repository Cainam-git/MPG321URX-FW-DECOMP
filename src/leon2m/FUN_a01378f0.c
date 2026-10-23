/* leon2m FUN_a01378f0 @ 0xa01378f0 (-mcpu=v8 -O2 -g)
 * Sends {p1, p2, 0, 0} with FUN_a01370dc(0x11, 2, buf, 0) (4-byte stack buffer).
 */
extern int FUN_a01370dc();

void FUN_a01378f0(unsigned char param_1, unsigned char param_2)
{
    unsigned char local_10[4] = {param_1, param_2};
    FUN_a01370dc(0x11, 2, local_10, 0);
}
