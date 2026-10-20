/* leon2m FUN_a0138674 @ 0xa0138674 (-mcpu=v8 -O2 -g)
 * Sends command 0x93 with the 4-byte buffer {param_1, low byte of param_2, high byte of param_2, 0}:
 * FUN_a01370dc(0x93, 4, buf, 0).
 */
extern int FUN_a01370dc();

void FUN_a0138674(unsigned char param_1, unsigned short param_2)
{
    unsigned char local_10[4] = {param_1, (unsigned char)param_2, (unsigned char)(param_2 >> 8)};
    FUN_a01370dc(0x93, 4, local_10, 0);
}
