/* leon2m FUN_a0123590 @ 0xa0123590  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 if the low byte of FUN_a00f2e30(param_1 & 0xff, 0xcc) is zero, else 0. The `== 0` compiles to the
 * SPARC idiom cmp %g0, x / subx %g0, -1, %i0 (1 minus the carry). Only one parameter is used; %i1 is never read.
 */
extern int FUN_a00f2e30(int, int);

int FUN_a0123590(int param_1)
{
    int result = FUN_a00f2e30(param_1 & 0xff, 0xcc);
    return (result & 0xff) == 0;
}
