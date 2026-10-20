/* leon2m FUN_a013a85c @ 0xa013a85c
 * Returns byte 1 (bits 16..23) of the Tensilica mailbox word at portal 2 (0xB7091000) offset 0x4C.
 * Reads one 32-bit word with MailBox_Read (func_0x4008c4d0 = RAM alias of FUN_a002c4d0) into a local cleared to 0
 * first. Callers: none found by xref (jump table or pointer).
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170();
unsigned char FUN_a013a85c(void)
{
    unsigned int v = 0;
    func_0x4008c4d0(2, 0x4c, &v, 1);
    return (unsigned char)(v >> 16);
}
