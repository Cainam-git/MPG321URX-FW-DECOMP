/* ldc_hw_pulse_reset  (FUN_a00fc1a0)
 *
 * Set bit 29 of the grid block's control register, wait timer_sleep_ticks(5), restore the old value.
 * Note: timer_sleep_ticks(5) loads its countdown with 6.
 * Name basis: descriptive - 0xD0040000: value read, written with bit 29 set, timer_sleep_ticks(5), first value
 *   written back
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc1a0, flags -mcpu=v8 -O3 -g.
 * The wait routine is declared here under its ROM address name FUN_4008d1a0 (variadic int-returning).
 */

/* Bit 29 of the control register at 0xD0040000. */
#define LDC_CTRL_PULSE_BIT 0x20000000

extern int timer_sleep_ticks(int, ...);      /* timer_sleep_ticks */

/*
 * Write the control register back with bit 29 set, wait with timer_sleep_ticks(5), then write the value that was
 * read first. Called by ldc_hw_api_pulse_reset.
 */
void ldc_hw_pulse_reset(void)
{
    unsigned int saved_ctrl;
    volatile unsigned int *ctrl_reg = (volatile unsigned int *)0xd0040000;

    saved_ctrl = *ctrl_reg;
    *ctrl_reg = saved_ctrl | LDC_CTRL_PULSE_BIT;
    timer_sleep_ticks(5);
    *ctrl_reg = saved_ctrl;
}
