/* startup_get_clock_variant  (FUN_CODE_18c9)
 *
 * Return 0 for the clock variant 0x20, else 1.
 * Returns: 0 or 1
 * Name basis: derived - the main routine writes the result times 4 to the SPI bus mode register
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(7,SPEED) REGFILE(R.ORC).
 * Source form: result starts at 1 and the first arm counts it down ("result--") while the second stores 1 again;
 * the exact build depends on that form.
 */
bit startup_is_slow_clock(void);

/* startup_get_clock_variant
 *
 * Returns 0 when reg_sys_clock_variant reads 0x20, else 1.  Only caller: startup_boot_main, which writes the
 * result times 4 into reg_flash_spi_mode: the two-bit field in bits 2..3 (the bus-mode bits the flash routines
 * keep) becomes 0 or 1.
 */
unsigned char startup_get_clock_variant(void)
{
    unsigned char result = 1;
    if (startup_is_slow_clock()) {
        result--;       /* variant 0x20 -> 0 */
    } else {
        result = 1;
    }
    return result;
}
