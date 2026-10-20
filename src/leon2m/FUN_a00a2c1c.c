/* leon2m FUN_a00a2c1c @ 0xa00a2c1c  MATCH (-mcpu=v8 -O2, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): name arr_12e2f8->DAT_0012e2f8
 */
extern unsigned char DAT_0012e2f8[]; /* 0x12e2f8 */

unsigned char FUN_a00a2c1c(unsigned short param_1)
{
    return DAT_0012e2f8[param_1];
}
