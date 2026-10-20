/* leon2m FUN_a01376ec @ 0xa01376ec
 * Returns 1 when (mask & low byte of the Small chip mailbox word at portal 1 (0x9F130100) offset 0x0C) != 0, else 0.
 * Reads one 32-bit word with MailBox_Read (func_0x4008c4d0 = RAM alias of FUN_a002c4d0) into a local cleared to 0
 * first. Callers: none found by xref (jump table or pointer).
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170();
unsigned char FUN_a01376ec(unsigned char mask)
{
    unsigned int v = 0;
    func_0x4008c4d0(1, 0xc, &v, 1);
    return (unsigned char)(mask & v) != 0;
}
