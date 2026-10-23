/* 8051_bank1 FUN_CODE_0016 @ 0x0016  OPTIMIZE(7,SPEED)
 * Sets bit 6 of XDATA 0xF0E5, then clears it. Same code as FUN_CODE_18d6 with other addresses and constants.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5;

void FUN_CODE_0016(void)
{
    DAT_EXTMEM_f0e5 |= 0x40;
    DAT_EXTMEM_f0e5 &= 0xbf;
}
