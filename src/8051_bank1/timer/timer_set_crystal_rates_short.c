/* timer_set_crystal_rates_short  (FUN_CODE_dac8)
 *
 * Load a shorter timer reload and the crystal-clock serial speed.
 * Note: Not called anywhere.
 * Name basis: descriptive - same as timer_set_crystal_rates with reload 0xFF06; no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dac8 @ 0xdac8..0xdae3 (27 B)
 * Options: OPTIMIZE(8,SPEED). The call to uart_set_baud_rate is a tail jump.
 */
extern unsigned char xdata timer_reload_low, timer_reload_high;
extern void uart_set_baud_rate(unsigned char a, unsigned long b) large;

/* Same as timer_set_crystal_rates but with the timer 0 reload 0xFF06.
 * Nothing in the bank calls it. */
void timer_set_crystal_rates_short(void)
{
    timer_reload_low = 0x06;
    timer_reload_high = 0xff;
    uart_set_baud_rate(1, 4800);
}
