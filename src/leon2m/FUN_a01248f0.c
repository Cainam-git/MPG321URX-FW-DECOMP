/* leon2m FUN_a01248f0 @ 0xa01248f0  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(0xD, 0x80) is zero, else 0. GCC 3.4 emits `return (x & 0xff) ==
 * 0;` as and / cmp %g0, %o0 / subx %g0, -1, %i0.
 */
extern int func_0x4008cd38(int, int); /* 0x4008cd38 */

int FUN_a01248f0(void)
{
    int uVar1;
    uVar1 = func_0x4008cd38(0xd, 0x80);
    return (uVar1 & 0xff) == 0;
}
