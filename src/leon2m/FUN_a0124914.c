/* leon2m FUN_a0124914 @ 0xa0124914  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(9, 4) equals 1, else 0. Masking into the separate variable t
 * produces the firmware's two-register sequence (and ..., %g1 / xor %g1, 1, ...).
 */
/* extern function at 0x4008cd38 */
extern int func_0x4008cd38(int a, int b);

int FUN_a0124914(void)
{
    unsigned int x = func_0x4008cd38(9, 4);
    unsigned int t = x & 0xff;
    return (t ^ 1) == 0;
}
