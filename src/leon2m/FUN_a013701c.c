/* leon2m FUN_a013701c @ 0xa013701c  MATCH (-mcpu=v8 -O2 -g)
 * Reads one 32-bit word from mailbox portal 1, offset 0xC (MailBox_Read func_0x4008c4d0(1, 0xC, &w, 1), w
 * zero-initialized) and returns bit 26 of it as 0 or 1. The function takes no arguments (%i0 is not used).
 */
extern int func_0x4008c4d0();

int FUN_a013701c(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return (local_c >> 0x1a) & 1;
}
