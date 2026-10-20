/* leon2m FUN_a0125e38 @ 0xa0125e38  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 if the low byte of func_0x4008cd38(13, 16) equals 1, else 0. No parameters (%i0/%i1 are not read after
 * the save).
 *
 * Required form: (x & 0xff) ^ 1 in a named intermediate, so the and result stays in %g1 instead of overwriting
 * %o0, and the comparison returned directly, which gives cmp %g0, t / subx %g0, -1, %i0 instead of a clr/or
 * sequence.
 */
extern int func_0x4008cd38(int, int); /* at 0x4008cd38 */

int FUN_a0125e38(void)
{
    int x = func_0x4008cd38(0xd, 0x10);
    int t = (x & 0xff) ^ 1;
    return t == 0;
}
