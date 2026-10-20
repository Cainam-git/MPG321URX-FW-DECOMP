/* leon2s FUN_a00b1508 @ 0xa00b1508 (-mcpu=v8 -Os -g)
 * Copies param_3 32-bit words from param_2 to param_1. The while loop with i < param_3 gives the target's cmp/bcc
 * at the top and cmp/bcs at the bottom.
 */
void FUN_a00b1508(int *param_1, int *param_2, unsigned int param_3)
{
    unsigned int i = 0;
    while (i < param_3) {
        param_1[i] = param_2[i];
        i++;
    }
}
