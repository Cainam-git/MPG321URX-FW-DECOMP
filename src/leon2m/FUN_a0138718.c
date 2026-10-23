/* leon2m FUN_a0138718 @ 0xa0138718 (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x72, 0xc, buf, 0) with a 12-byte local buffer of zeros. Same code as FUN_a01386e4 with other
 * constants.
 */
extern int FUN_a01370dc();

void FUN_a0138718(void)
{
    unsigned int local_18[3] = {0, 0, 0};
    FUN_a01370dc(0x72, 0xc, local_18, 0);
}
