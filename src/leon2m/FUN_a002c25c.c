/* leon2m FUN_a002c25c @ 0xa002c25c (RAM copy, run-time address 0x4008c25c)
 * Reg_Write32(addr, value): store the 32-bit value at addr (one st, then retl). Counterpart of Reg_Read32
 * FUN_a002c250. Used by MailBox_Write FUN_a002c5f8 for every word written into a mailbox portal.
 */
void FUN_a002c25c(unsigned int addr, unsigned int value)
{
    *(volatile unsigned int *)addr = value;
}
