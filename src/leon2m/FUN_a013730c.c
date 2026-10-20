/* leon2m FUN_a013730c @ 0xa013730c (-mcpu=v8 -O2 -g)
 * Sends command 0x81 with a 12-byte zeroed buffer whose first byte is param_1: FUN_a01370dc(0x81, 0xc, buf, 0).
 * The initializer compiles to a std (two words) plus a word store; the byte store through the (unsigned char *)
 * cast then overwrites the first byte with stb, as in the target.
 */
extern int FUN_a01370dc();

void FUN_a013730c(unsigned char param_1)
{
    unsigned int local_18[3] = {0, 0, 0};
    ((unsigned char *)local_18)[0] = param_1;
    FUN_a01370dc(0x81, 0xc, local_18, 0);
}
