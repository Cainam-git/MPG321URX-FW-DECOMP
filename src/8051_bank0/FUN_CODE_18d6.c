/* 8051_bank0 FUN_CODE_18d6 @ 0x18d6  MATCH (OPTIMIZE(7,SPEED))
 * Sets bit 6 of XDATA 0xF0E5, then clears it. The variable is volatile: the target reads the register again (a
 * second MOVX A,@DPTR) between the OR store and the AND; without volatile Keil keeps the value in A.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5;

void FUN_CODE_18d6(void)
{
    DAT_EXTMEM_f0e5 |= 0x40;
    DAT_EXTMEM_f0e5 &= 0xbf;
}
