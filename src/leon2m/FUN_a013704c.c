/* leon2m FUN_a013704c @ 0xa013704c  MATCH (-mcpu=v8 -O2 -g)
 * Reads one 32-bit word from mailbox portal 1, offset 0xC (MailBox_Read func_0x4008c4d0(1, 0xC, &w, 1), w
 * zero-initialized) and returns bit 27 of it as 0 or 1. The local is an unsigned int (clr / ld of 4 bytes). The
 * function takes no arguments (%i0 / %i1 are not used).
 */
extern int func_0x4008c4d0();

int FUN_a013704c(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return (local_c >> 27) & 1;
}
