/* leon2m FUN_a0123574 @ 0xa0123574 (-mcpu=v8 -O2 -g)
 * Returns FUN_a00f2e30(param_1 & 0xFF, 0x10) & 0xF. The function takes one argument and returns int.
 */
extern int FUN_a00f2e30(int, int); /* at 0xa00f2e30 */

int FUN_a0123574(int param_1)
{
    param_1 &= 0xff;
    return FUN_a00f2e30(param_1, 0x10) & 0xf;
}
