/* leon2m FUN_a0125b94 @ 0xa0125b94 (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(2, 1) is 1, else 0, branch-free: 'cmp %g0, %o0' sets the carry
 * for a nonzero value, and 'subx %g0, -1, %i0' yields 1 - carry. Frame: 'save %sp, -104, %sp'.
 */
/* extern declarations */
extern int func_0x4008cd38(int, int); /* at 0x4008cd38 */

int FUN_a0125b94(void)
{
    int r = func_0x4008cd38(2, 1);
    int t = (r & 0xff) ^ 1;
    return t == 0;
}
