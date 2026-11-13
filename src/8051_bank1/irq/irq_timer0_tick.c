/* irq_timer0_tick  (FUN_CODE_d103)
 *
 * Count one system tick on the timer 0 interrupt and reload the timer.
 * Name basis: proven - interrupt vector 0x000B (timer 0); 16-bit tick counter in IDATA 0x57
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d103 @ 0xD103..0xD13A (55 bytes)  Byte-exact with OPTIMIZE(8,SPEED).
 * Source form: timer_tick_count is volatile (this interrupt changes it, other code reads it).
 */
sfr TL0 = 0x8A;
sfr TH0 = 0x8C;
sbit TR0 = 0x8C;
extern unsigned char xdata timer_reload_low, timer_reload_high, timer_div10_count;
extern unsigned int volatile idata timer_tick_count;

/*
 * Timer 0 interrupt (vector 0x000B), register bank 2. Reloads TL0 / TH0 from
 * timer_reload_low / timer_reload_high (set by timer_set_clock_rates),
 * starts timer 0 again, adds one to the 16-bit timer_tick_count and steps
 * timer_div10_count through 0..9.
 */
void irq_timer0_tick(void) interrupt 1 using 2
{
    TL0 = timer_reload_low;
    TH0 = timer_reload_high;
    TR0 = 1;
    timer_tick_count++;
    if (++timer_div10_count > 9) timer_div10_count = 0;
}
