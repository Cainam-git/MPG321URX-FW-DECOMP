/* leon2m FUN_a00a2c04 @ 0xa00a2c04  MATCH (-mcpu=v8 -O2, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): name arr_125928->DAT_00125928
 */
/* extern array at 0x125928 (DRAM) */
extern unsigned int DAT_00125928[];

unsigned int FUN_a00a2c04(unsigned short param_1)
{
    return DAT_00125928[param_1];
}
