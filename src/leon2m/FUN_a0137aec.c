/* leon2m FUN_a0137aec @ 0xa0137aec (-mcpu=v8 -O2 -g)
 * Sends {p1, p2, 0, 0} with FUN_a01370dc(0x24, 4, buf, 1) (4-byte stack buffer). Called by FUN_a012b328.
 */
extern int FUN_a01370dc();

void FUN_a0137aec(unsigned char param_1, unsigned char param_2)
{
    unsigned char local_10[4] = {param_1, param_2};
    FUN_a01370dc(0x24, 4, local_10, 1);
}
