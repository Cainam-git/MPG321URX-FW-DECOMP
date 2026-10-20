/* leon2m FUN_a0125a60 @ 0xa0125a60 (-mcpu=v8 -O2 -g)
 * Returns 1 if the low byte of func_0x4008cd38(7, 8) equals 1, else 0. Written as ((r & 0xff) ^ 1) == 0; the `==
 * 0` compiles to cmp %g0, x / subx %g0, -1, %i0 (1 minus the carry set by the cmp). No parameters.
 */
extern int func_0x4008cd38(int, int); /* 0x4008cd38 */

int FUN_a0125a60(void)
{
    int r;
    r = func_0x4008cd38(7, 8);
    return ((r & 0xff) ^ 1) == 0;
}
