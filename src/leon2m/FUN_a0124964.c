/* leon2m FUN_a0124964 @ 0xa0124964 (-mcpu=v8 -O2 -g)
 * Returns 1 if the low byte of func_0x4008cd38(10, 4) equals 1, else 0. Written as ((r & 0xff) ^ 1) == 0: the and
 * result goes to %g1, the xor follows, and the `== 0` compiles to cmp %g0, x / subx %g0, -1, %i0 (1 minus the
 * carry). No parameters.
 */
/* extern declarations */
extern int func_0x4008cd38(int, int); /* 0x4008cd38 */

int FUN_a0124964(void)
{
    int r = func_0x4008cd38(10, 4);
    return ((r & 0xff) ^ 1) == 0;
}
