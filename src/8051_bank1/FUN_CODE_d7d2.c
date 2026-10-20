/* 8051_bank1 FUN_CODE_d7d2 @ 0xd7d2  MATCH (OPTIMIZE(7,SPEED))
 * Returns a 32-bit constant in R4:R7: 0x00B71B00 (12 000 000) if FUN_CODE_df0b returns carry set; otherwise
 * 0x02DC6C00 (48 000 000) if XDATA 0xD511 equals 0x20, else 0x05B8D800 (96 000 000).
 *
 * The constants are written as unsigned long literals; Keil returns them MSB-first in R4:R7, so the target loads
 * R7 with the low byte first.
 */
extern bit FUN_CODE_df0b(void);  // at 0xdf0b

extern unsigned char xdata DAT_EXTMEM_d511 _at_ 0xd511;

unsigned long FUN_CODE_d7d2(void)
{
    if (FUN_CODE_df0b()) {
        return 0x00B71B00UL;
    }
    if (DAT_EXTMEM_d511 == 0x20) {
        return 0x02DC6C00UL;
    }
    return 0x05B8D800UL;
}
