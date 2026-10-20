/* leon2m FUN_a014fd34 @ 0xa014fd34  MATCH (-mcpu=v8 -O2, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): already exact
 */
extern unsigned char DAT_a802cc86;
extern void FUN_a011e8fc(int, int); /* 0xa011e8fc */

void FUN_a014fd34(unsigned int param_1)
{
    if (DAT_a802cc86 & 1)
        FUN_a011e8fc(0x10, param_1 & 0xff);
    if (DAT_a802cc86 & 2)
        FUN_a011e8fc(0x11, param_1 & 0xff);
    if (DAT_a802cc86 & 4)
        FUN_a011e8fc(0x12, param_1 & 0xff);
    if (DAT_a802cc86 & 8)
        FUN_a011e8fc(0x13, param_1 & 0xff);
    if (DAT_a802cc86 & 0x10)
        FUN_a011e8fc(0x14, param_1 & 0xff);
    if (DAT_a802cc86 & 0x20)
        FUN_a011e8fc(0x15, param_1 & 0xff);
    if (DAT_a802cc86 & 0x40)
        FUN_a011e8fc(0x16, param_1 & 0xff);
    if (DAT_a802cc86 & 0x80)
        FUN_a011e8fc(0x17, param_1 & 0xff);
}
