/* startup_is_slow_clock  (FUN_CODE_18bb)
 *
 * Test whether the clock variant register reads 0x20 (the slower clock: uart_init then uses 48 MHz).
 * Returns: 1 when the register reads 0x20, else 0
 * Name basis: derived - XDATA 0xD511 == 0x20; uart_init loads the baud timer for 48 MHz on 1 and for 96 MHz on
 *   0
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the result goes through bit 0x20.1 (cleared, then set on a match) and is returned in the carry
 * flag; the exact build depends on it.
 */
unsigned char bdata _bdata_20 _at_ 0x20;
sbit is_variant_20 = _bdata_20 ^ 1;                 /* bit 0x20.1, returned in the carry flag */
unsigned char volatile xdata reg_sys_clock_variant _at_ 0xd511;

#define CLOCK_VARIANT_20    0x20

/* startup_is_slow_clock
 *
 * Returns 1 when XDATA 0xD511 (reg_sys_clock_variant) reads 0x20, else 0.  The boot loader only reads that
 * register.  Callers: uart_init (48 MHz on 1, 96 MHz on 0), startup_find_marker_index (which table it
 * searches), startup_get_clock_variant and startup_is_slow_clock_long.
 */
bit startup_is_slow_clock(void)
{
    is_variant_20 = 0;
    if (reg_sys_clock_variant == CLOCK_VARIANT_20) {
        is_variant_20 = 1;
    }
    return is_variant_20;
}
