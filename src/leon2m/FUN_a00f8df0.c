/* leon2m FUN_a00f8df0 @ 0xa00f8df0  MATCH (-mcpu=v8 -O2 -g)
 * Returns FUN_a00f1ce4(param_1 & 0xFF, 0x10) & 0x7FF ('and %o0, 0x7ff, %i0'). param_2 is unused.
 */
extern int FUN_a00f1ce4(int a, int b); /* at 0xa00f1ce4 */

int FUN_a00f8df0(int param_1, int param_2)
{
    int tmp = param_1 & 0xff;
    int result = FUN_a00f1ce4(tmp, 0x10);
    return result & 0x7ff;
}
