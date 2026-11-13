/* panel_calc_clock_percent  (FUN_a01083fc)
 *
 * Compute a pixel clock as a percentage of 2407 MHz, plus 1.
 * Returns: percent
 * Name basis: descriptive - floating-point computation; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01083fc, flags -mcpu=v8 -O3 -g -msoft-float. The soft-float flag is needed: plain -O3 -g gives
 * different code. The float helpers it calls (FUN_a0155xxx) are the compiler's soft-float library.
 * Source form: float arithmetic; 'v = 100' stands before the first test; the print takes the format and the value.
 */
extern void dbg_printf(char *, unsigned int);

#define DCLK_FULL_LIMIT 2408000000u     /* at or below this the result is 100 */
#define DCLK_BASE       2407000000.0f   /* the clock that counts as 100 percent above the limit */

/*
 * Print "FRC_AutoFrameDown dclk =%ld" with the value at *dclk, then return
 *   100                                    when it is below 2408000000,
 *   100                                    when it equals 2408000000,
 *   (dclk / 2407000000 * 100) + 1          when it is above (float arithmetic, result truncated).
 * Nothing calls this routine directly.
 */
unsigned short panel_calc_clock_percent(unsigned int *dclk)
{
  unsigned int value;
  unsigned int percent;

  dbg_printf("FRC_AutoFrameDown dclk =%ld\r\n", *dclk);
  value = *dclk;
  percent = 100;
  if (value < DCLK_FULL_LIMIT)
    return 100;
  if (value > DCLK_FULL_LIMIT)
    percent = (unsigned int)((float)value / DCLK_BASE * 100.0f) + 1;
  return percent;
}
