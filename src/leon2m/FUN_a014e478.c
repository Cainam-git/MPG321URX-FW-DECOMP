/* leon2m FUN_a014e478 @ 0xa014e478  MATCH (-mcpu=v8 -O2 -g)
 * This function takes a byte value `param_1`, then calls `FUN_a0125230` with arguments 0 through 7 until the low byte of the result matches `param_1 & 0xff`. It returns the index of the first match, or 8 if no match is found within 8 attempts. The main uncertainty is whether GCC 3.
 */
extern int FUN_a0125230(int a0); /* 0xa0125230 */

int FUN_a014e478(unsigned int param_1)
{
    unsigned char l1;
    unsigned char l0;
    int i0;

    l1 = param_1 & 0xff;
    l0 = 0;
    i0 = 0;
    do {
        if ((FUN_a0125230(i0) & 0xff) == l1)
            break;
        l0++;
        i0 = l0;
    } while (l0 < 8);
    return i0;
}
