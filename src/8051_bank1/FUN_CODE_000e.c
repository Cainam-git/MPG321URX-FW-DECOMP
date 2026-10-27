/* 8051_bank1 FUN_CODE_000e @ 0x000e (5 bytes, between the interrupt vectors at 0x000B and 0x0013)
 * Returns the IDATA byte 0x49 (MOV R0,#49H / MOV A,@R0 / MOV R7,A / RET). FUN_CODE_0006 at 0x0006 is the same
 * reader for the IDATA byte 0x47. No LCALL or LJMP to this address occurs in the bank-1 image.
 */
extern unsigned char idata DAT_INTMEM_49;

unsigned char FUN_CODE_000e(void)
{
    return DAT_INTMEM_49;
}
