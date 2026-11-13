/* timer_set_crystal_rates  (FUN_CODE_daad)
 *
 * Load the timer reload and serial speed used on the crystal clock.
 * Name basis: derived - timer 0 reload 0xFC18 and 4800 baud; called on power off, power saving and the crystal
 *   clock switch
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_daad @ 0xdaad..0xdac8 (27 B)
 * Options: OPTIMIZE(8,SPEED). The call to uart_set_baud_rate is a tail jump.
 */
extern unsigned char xdata timer_reload_low, timer_reload_high;
extern void uart_set_baud_rate(unsigned char a, unsigned long b) large;

/* Set the timer 0 reload to 0xFC18, then set the serial speed to 4800
 * (first argument 1). Callers: power_setup_power_saving, power_off_sequence, sys_switch_to_crystal_clock. */
void timer_set_crystal_rates(void)
{
    timer_reload_low = 0x18;
    timer_reload_high = 0xfc;
    uart_set_baud_rate(1, 4800);
}
