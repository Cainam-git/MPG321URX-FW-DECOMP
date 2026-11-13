/* sys_switch_to_crystal_clock  (FUN_CODE_d5c8)
 *
 * Switch the 8051 back to the crystal clock and slow timer rates.
 * Name basis: derived - clock unit regs 0xD904..0xD929 then the fixed slow timer reload; called when activity
 *   ends
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d5c8 @ 0xd5c8  OPTIMIZE(8,SPEED)
 */
#define CHIP_ID_20 0x20  /* chip variant that keeps only bit 0 of the register at XDATA 0xD904 */

extern xdata unsigned char DAT_EXTMEM_d929;
extern xdata unsigned char DAT_EXTMEM_d90b;
extern xdata unsigned char reg_chip_id;
extern xdata unsigned char DAT_EXTMEM_d904;
extern xdata unsigned char DAT_EXTMEM_d90c;

void timer_set_crystal_rates(void);  /* at 0xdaad */

/*
 * Switch the 8051 to the crystal clock: write 0x71 to XDATA 0xD929, clear bit 7 of 0xD90B, keep bit 0 of 0xD904
 * (chip id 0x20) or its low nibble (other chips), set bit 0 of 0xD90C, then load the timer and serial rates for
 * the crystal clock (timer_set_crystal_rates). The meaning of the four registers is not shown.
 */
void sys_switch_to_crystal_clock(void)
{
    DAT_EXTMEM_d929 = 0x71;
    DAT_EXTMEM_d90b = DAT_EXTMEM_d90b & 0x7f;
    if (reg_chip_id == CHIP_ID_20) {
        DAT_EXTMEM_d904 = DAT_EXTMEM_d904 & 0x01;
    } else {
        DAT_EXTMEM_d904 = DAT_EXTMEM_d904 & 0x0f;
    }
    DAT_EXTMEM_d90c = DAT_EXTMEM_d90c | 0x01;
    timer_set_crystal_rates();
}
