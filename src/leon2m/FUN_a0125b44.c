/* leon2m FUN_a0125b44 @ 0xa0125b44  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(2, 8) is 1, else 0. The parameters a and b are unused.
 */
extern int func_0x4008cd38(int a, int b); /* at 0x4008cd38 */

int FUN_a0125b44(int a, int b)
{
    int x = func_0x4008cd38(2, 8);
    int t = x & 0xff;
    int y = t ^ 1;
    return y == 0;
}
