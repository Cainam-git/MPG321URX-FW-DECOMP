/* 8051_bank1 FUN_CODE_de5b @ 0xde5b  MATCH (OPTIMIZE(7,SPEED))
 * Returns 0 (CLR C) when XDATA 0xA35F == 1, otherwise 1 (SETB C). The 'bit' return type returns the result in the
 * carry flag.
 */
extern unsigned char xdata DAT_EXTMEM_a35f;

bit FUN_CODE_de5b(void)
{
    if (DAT_EXTMEM_a35f == 0x01)
    {
        return 0;  // CLR CY, RET
    }
    return 1;      // SETB CY, RET
}
