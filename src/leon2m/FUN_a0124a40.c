/* leon2m FUN_a0124a40 @ 0xa0124a40  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(0xFF, 1) equals 1, else 0 (`!((r & 0xff) ^ 1)`).
 */
extern int func_0x4008cd38(int, int); /* 0x4008cd38 */

int FUN_a0124a40(void)
{
    int r = func_0x4008cd38(0xff, 1);
    return !((r & 0xff) ^ 1);
}
