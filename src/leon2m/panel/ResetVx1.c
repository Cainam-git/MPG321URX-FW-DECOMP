/* ResetVx1  (FUN_a0122d0c)
 *
 * Reset the V-by-One link with a one-millisecond pulse.
 * Name basis: proven - prints 'ResetVx1' (original name); pulse on 0xCF00EB44
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0122d0c @ 0xa0122d0c, flags -mcpu=v8 -O3 -g
 */
#define reg_panel_vx1_reset (*(volatile unsigned int *)0xcf00eb44)
extern int dbg_printf();                 /* formatted output (vsnprintf) */
extern void timer_sleep_ticks(int ms);       /* delay */

#define VX1_RESET_PULSE_MS 1

/* Print "ResetVx1", then pulse register 0xCF00EB44: write 1, wait one millisecond, write 0. */
void ResetVx1(void)
{
  dbg_printf("\033[1;31mResetVx1\r\n\033[m");
  reg_panel_vx1_reset = 1;
  timer_sleep_ticks(VX1_RESET_PULSE_MS);
  reg_panel_vx1_reset = 0;
}
