/* 8051_bank1 FUN_CODE_0006 @ 0x0006 (5 bytes, between the interrupt vectors at 0x0003 and 0x000B)
 * Returns the IDATA byte 0x47 (MOV R0,#47H / MOV A,@R0 / MOV R7,A / RET). FUN_CODE_000e at 0x000e is the same
 * reader for the IDATA byte 0x49. No LCALL or LJMP to this address occurs in the bank-1 image.
 */
extern unsigned char idata DAT_INTMEM_47;

unsigned char FUN_CODE_0006(void)
{
    return DAT_INTMEM_47;
}
