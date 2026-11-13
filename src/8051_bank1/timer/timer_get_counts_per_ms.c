/* timer_get_counts_per_ms  (FUN_CODE_dbf6)
 *
 * Return the timer 0 counts that make one millisecond on this chip.
 * Returns: counts per ms
 * Name basis: derived - 4000 on chip id 0x20 (48 MHz / 12), else 8000 (96 MHz / 12); used to compute the tick
 *   reload
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dbf6 @ 0xdbf6  OPTIMIZE(7,SPEED)
 */
#define CHIP_ID_20 0x20   /* reg_chip_id value of this chip variant */

extern xdata unsigned char reg_chip_id;

/* Return 4000 (0x0FA0) on chip variant 0x20, else 8000 (0x1F40). */
unsigned long timer_get_counts_per_ms(void)
{
    if (reg_chip_id == CHIP_ID_20) {
        return 0x0FA0UL;
    }
    return 0x1F40UL;
}
