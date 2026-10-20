/* leon2m FUN_a002c250 @ 0xa002c250 (RAM copy, run-time address 0x4008c250)
 * Reg_Read32(addr): return the 32-bit word at addr (one ld). Used by MailBox_Read FUN_a002c4d0 and the
 * FUN_a0029994 family.
 */
unsigned int FUN_a002c250(unsigned int addr)
{
    return *(volatile unsigned int *)addr;
}
