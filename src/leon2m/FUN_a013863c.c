/* leon2m FUN_a013863c @ 0xa013863c (-mcpu=v8 -O2 -g)
 * This should produce `clr` to zero the whole word, then individual `stb` stores for each byte. The initialization `{0,0,0,0}` gives the `clr`, and the separate assignments give the `stb` instructions in order.
 */
extern int FUN_a01370dc();

void FUN_a013863c(unsigned char param_1, unsigned char param_2, unsigned char param_3, unsigned char param_4)
{
    unsigned char buf[4] = {0, 0, 0, 0};
    buf[0] = param_1;
    buf[1] = param_2;
    buf[2] = param_3;
    buf[3] = param_4;
    FUN_a01370dc(0x92, 4, buf, 0);
}
