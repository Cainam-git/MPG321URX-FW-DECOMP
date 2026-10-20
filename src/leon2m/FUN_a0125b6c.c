/* leon2m FUN_a0125b6c @ 0xa0125b6c (-mcpu=v8 -O2 -g)
 * Returns 1 if the low byte of func_0x4008cd38(0xff, 1) equals 1, else 0. Written as ((r & 0xff) ^ 1) == 0; the
 * `== 0` compiles to cmp %g0, x / subx %g0, -1, %i0 (1 minus the carry set by the cmp). No parameters.
 */
/* extern function at 0x4008cd38 */
extern int func_0x4008cd38(int, int);

int FUN_a0125b6c(void)
{
    return ((func_0x4008cd38(0xff, 1) & 0xff) ^ 1) == 0;
}
