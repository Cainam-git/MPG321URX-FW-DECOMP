/* leon2m FUN_a0125a88 @ 0xa0125a88 (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(0xB, 2) is zero, else 0 (and / cmp %g0, %o0 / subx %g0, -1, %i0).
 * The function reads no parameters.
 */
/* extern at 0x4008cd38 */
extern int func_0x4008cd38(int, int);

int FUN_a0125a88(void)
{
    int r = func_0x4008cd38(0xb, 2);
    return (r & 0xff) == 0;
}
