/* leon2m FUN_a013a750 @ 0xa013a750
 * Tensilica mailbox command word 0x40000001 (fixed, no argument): posts it into mailbox portal 2 (0xB7091000) at
 * offset 0x20. Same shape as FUN_a0139b90: read the slot (MailBox_Read, func_0x4008c4d0), while it is non-zero wait
 * func_0x4008d1a0(1) and re-read, at most 100 times; write only if the slot became 0 (MailBox_Write,
 * func_0x4008c5f8), else nothing is sent. Callers: FUN_a015266c+0x250.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(int ms);
void FUN_a013a750(void)
{
    unsigned int v = 0xffffffff;
    int n = 100;
    func_0x4008c4d0(2, 0x20, &v, 1);
    while (v != 0) { n--; func_0x4008d1a0(1); func_0x4008c4d0(2, 0x20, &v, 1); if (n == 0) break; }
    if (v == 0) { v = 0x40000001; func_0x4008c5f8(2, 0x20, &v, 1); }
}
