/* 8051_bank1 FUN_CODE_defa @ 0xdefa (unlisted code found in a gap of the function table).
 * Returns the IDATA byte 0x4B (MOV R0,#4BH; MOV A,@R0; MOV R7,A). No LCALL/LJMP/ACALL caller in the image.
 */
extern unsigned char idata DAT_INTMEM_4b;
unsigned char FUN_CODE_defa(void)
{
    return DAT_INTMEM_4b;
}
