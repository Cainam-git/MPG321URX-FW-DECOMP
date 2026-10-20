/* leon2m FUN_a0138e28 @ 0xa0138e28 (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x76, 4, buffer, 0) with the 4-byte buffer {low byte, high byte, 0, 0} of the 16-bit
 * param_1. The whole buffer is cleared first (clr), then the two bytes are stored.
 */
extern int FUN_a01370dc();

void FUN_a0138e28(unsigned short param_1)
{
    unsigned char local_10[4] = {(unsigned char)param_1, (unsigned char)(param_1 >> 8)};
    FUN_a01370dc(0x76, 4, local_10, 0);
}
