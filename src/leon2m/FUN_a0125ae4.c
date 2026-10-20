/* leon2m FUN_a0125ae4 @ 0xa0125ae4  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(2, 4) equals 1, else 0. GCC computes the result without a
 * branch (cmp followed by subx %g0, -1).
 */
/* extern declarations */
extern int func_0x4008cd38(int, int); /* at 0x4008cd38 */

int FUN_a0125ae4(void)
{
    int r = func_0x4008cd38(2, 4);
    return ((r & 0xff) ^ 1) == 0;
}
