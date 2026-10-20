/* leon2m FUN_a012493c @ 0xa012493c (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(9, 0x10) is 1, else 0, branch-free: 'cmp %g0, x' sets the carry
 * for a nonzero x, and 'subx %g0, -1, %i0' yields 1 - carry.
 */
extern int func_0x4008cd38(int, int); /* at 0x4008cd38 */

int FUN_a012493c(void)
{
    int x = func_0x4008cd38(9, 0x10);
    return ((x & 0xff) ^ 1) == 0;
}
