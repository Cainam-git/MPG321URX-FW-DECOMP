/* leon2m FUN_a01384e4 @ 0xa01384e4  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a01384ac: same code, constants swapped; byte-exact.
 */
extern void FUN_a01370dc();
extern int FUN_a0137344();

void FUN_a01384e4(unsigned char param_1, unsigned char param_2)
{
    unsigned char buf[4] = {param_1, param_2};
    FUN_a01370dc(0x22, 4, buf, 0);
    FUN_a0137344(1);
}
