/* sys_get_cpu_clock_hz  (FUN_CODE_d7d2)
 *
 * Return the current 8051 clock frequency in hertz.
 * Returns: clock in Hz
 * Name basis: derived - 12 MHz on the crystal (bit 0x0E), else 48 MHz (chip id 0x20) or 96 MHz; used to set
 *   the baud rates
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d7d2 @ 0xd7d2  OPTIMIZE(8,SPEED)
 * Source form: the constants are unsigned long literals; Keil returns them MSB-first in R4:R7, so the target
 * loads R7 with the low byte first.
 */
#define CHIP_ID_20      0x20
#define CPU_HZ_CRYSTAL  0x00B71B00UL  /* 12 000 000 */
#define CPU_HZ_CHIP_20  0x02DC6C00UL  /* 48 000 000 */
#define CPU_HZ_OTHER    0x05B8D800UL  /* 96 000 000 */

extern bit sys_is_on_crystal_clock(void);  /* at 0xdf0b */

extern unsigned char xdata reg_chip_id _at_ 0xd511;

/*
 * Return the clock frequency of the 8051 in hertz: 12 MHz while it runs on the crystal clock, otherwise 48 MHz on
 * chip id 0x20 and 96 MHz on the other chips.
 */
unsigned long sys_get_cpu_clock_hz(void)
{
    if (sys_is_on_crystal_clock()) {
        return CPU_HZ_CRYSTAL;
    }
    if (reg_chip_id == CHIP_ID_20) {
        return CPU_HZ_CHIP_20;
    }
    return CPU_HZ_OTHER;
}
