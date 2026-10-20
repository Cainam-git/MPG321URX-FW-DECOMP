/* leon2m FUN_a013353c @ 0xa013353c  MATCH (-mcpu=v8 -O2 -g)
 * Reads one 32-bit word from mailbox portal 0, offset 0xC (MailBox_Read func_0x4008c4d0(0, 0xC, &w, 1), w
 * zero-initialized) and returns bits 23..16 of it. (w >> 16) & 0xFF compiles to ldub [%fp-11], byte 1 of the
 * big-endian word at %fp-12.
 */
extern int func_0x4008c4d0();

int FUN_a013353c(void)
{
    unsigned int local_c;

    local_c = 0;
    func_0x4008c4d0(0, 0xc, &local_c, 1);
    return (local_c >> 16) & 0xff;
}
