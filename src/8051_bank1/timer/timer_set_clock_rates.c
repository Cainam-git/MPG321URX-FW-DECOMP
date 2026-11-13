/* timer_set_clock_rates  (FUN_CODE_cd07)
 *
 * Set the tick timer reload and serial port 1 rate for the current clock.
 * Name basis: derived - Timer 0 reload from the clock variant (0x0FA0 / 0x1F40) to 0xA772/0xA773,
 *   uart_set_baud_rate(1, 4800); counterpart timer_set_crystal_rates
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cd07 @ 0xcd07..0xcd4b (68 B)  Byte-exact with OPTIMIZE(8,SPEED) over 0xCD07..0xCD4B.
 * Source form: the difference is held in a 32-bit local and computed twice; a direct
 * 'timer_reload_low = 0x10000 - timer_get_counts_per_ms();' is narrowed by Keil to CPL / INC on the low byte. The
 * high byte is the 32-bit division by 256 (?C?ULDIV). uart_set_baud_rate is a LARGE function: R7 = first
 * parameter, the 32-bit second parameter goes to its XDATA block at 0xA4BA; it is reached with a tail jump.
 */
extern unsigned char xdata timer_reload_low, timer_reload_high;
extern unsigned long timer_get_counts_per_ms(void);
extern void uart_set_baud_rate(unsigned char port, unsigned long baud) large;

/*
 * Compute the Timer 0 reload value, 0x10000 - timer_get_counts_per_ms(), and
 * store its low byte in timer_reload_low and its high byte in
 * timer_reload_high (timer_apply_clock_rates loads them into TL0 / TH0 and
 * irq_timer0_tick reloads them on every tick). Then set the rate of serial
 * port 1 to 4800. Callers: the code at 0xB0FF, timer_apply_clock_rates and
 * the code at 0xD987.
 */
void timer_set_clock_rates(void)
{
    unsigned long reload;

    reload = 0x10000 - timer_get_counts_per_ms();
    timer_reload_low = reload;
    reload = 0x10000 - timer_get_counts_per_ms();
    timer_reload_high = reload / 256;
    uart_set_baud_rate(1, 4800);
}
