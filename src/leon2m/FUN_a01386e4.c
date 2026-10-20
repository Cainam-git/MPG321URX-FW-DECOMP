/* leon2m FUN_a01386e4 @ 0xa01386e4  MATCH (-mcpu=v8 -O2 -g)
 * Zeroes a 12-byte local buffer (a 64-bit store for the first 8 bytes, a word store for the last 4) and calls
 * FUN_a01370dc(0x73, 0xC, buf, 0). The function takes no arguments (%i0 / %i1 are not used) and returns nothing.
 */
extern int FUN_a01370dc();

void FUN_a01386e4(void)
{
    unsigned int local_18[3] = {0, 0, 0};
    FUN_a01370dc(0x73, 0xc, local_18, 0);
}
