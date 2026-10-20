/* leon2m FUN_a014fbf0 @ 0xa014fbf0 (-mcpu=v8 -O2)
 * Twin of FUN_a014fd34: same code, other constants.
 */
extern unsigned char DAT_a802cc86;
extern void FUN_a011e794(int, int); /* 0xa011e794 */

void FUN_a014fbf0(unsigned int param_1)
{
    if (DAT_a802cc86 & 1)
        FUN_a011e794(0x10, param_1 & 0xff);
    if (DAT_a802cc86 & 2)
        FUN_a011e794(0x11, param_1 & 0xff);
    if (DAT_a802cc86 & 4)
        FUN_a011e794(0x12, param_1 & 0xff);
    if (DAT_a802cc86 & 8)
        FUN_a011e794(0x13, param_1 & 0xff);
    if (DAT_a802cc86 & 0x10)
        FUN_a011e794(0x14, param_1 & 0xff);
    if (DAT_a802cc86 & 0x20)
        FUN_a011e794(0x15, param_1 & 0xff);
    if (DAT_a802cc86 & 0x40)
        FUN_a011e794(0x16, param_1 & 0xff);
    if (DAT_a802cc86 & 0x80)
        FUN_a011e794(0x17, param_1 & 0xff);
}
