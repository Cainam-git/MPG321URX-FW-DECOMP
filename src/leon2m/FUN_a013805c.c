/* leon2m FUN_a013805c @ 0xa013805c (-mcpu=v8 -O2 -g)
 * Sends {p1, p2, 0, 0} with FUN_a01370dc(0x47, 4, buf, 1) (4-byte stack buffer).
 */
extern int FUN_a01370dc();

void FUN_a013805c(unsigned char param_1, unsigned char param_2)
{
    unsigned char local[4] = {param_1, param_2};
    FUN_a01370dc(0x47, 4, local, 1);
}
