/* leon2s FUN_a006fd04 @ 0xa006fd04  MATCH (-mcpu=v8 -Os -g)
 * Returns 0 unless byte 3 of param_1 is 0x55. Otherwise XORs the first param_2 32-bit
 * words of the buffer, each folded with itself shifted right by 8, 16 and 24, and returns 1 when the low byte of
 * the result is 0, else 0. A single raw index masked at each use ('idx & 0xff') produces the
 * 'and %o3, 0xff, %g1' at the loop head; a separate pre-masked index gives 'clr %g1'.
 */
int FUN_a006fd04(unsigned char *param_1, unsigned char param_2)
{
    unsigned int acc = 0;

    if (param_1[3] == 0x55) {
        unsigned int count = param_2 & 0xff;
        unsigned int idx = 0;

        if (count != 0) {
            do {
                unsigned int val = *(unsigned int *)(param_1 + (idx & 0xff) * 4);
                idx++;
                acc = val ^ acc ^ (val >> 8) ^ (val >> 16) ^ (val >> 24);
            } while ((idx & 0xff) < count);
        }

        return (acc & 0xff) == 0;
    }

    return 0;
}
