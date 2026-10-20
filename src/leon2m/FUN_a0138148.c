/* leon2m FUN_a0138148 @ 0xa0138148 (-mcpu=v8 -O2 -g)
 * Builds a 4-byte buffer {param_1, 0, 0, 0} (stb of the byte parameter), prints the string at 0x1A55C0 (debug
 * printf FUN_a00df170) and calls FUN_a01370dc(0x60, 4, buffer, 0).
 */
extern int FUN_a00df170();
extern int FUN_a01370dc();

void FUN_a0138148(unsigned char param_1)
{
    unsigned char local_10[4] = {param_1};
    FUN_a00df170(0x1a55c0);
    FUN_a01370dc(0x60, 4, local_10, 0);
}
