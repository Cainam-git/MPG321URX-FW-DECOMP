/* timer_api_sleep_ticks  (FUN_a01437dc)
 *
 * Wait for a number of ticks.
 * Name basis: proven - forwards to timer_sleep_ticks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01437dc @ 0xa01437dc, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype; the parameter is an unsigned short.
 */
extern int timer_sleep_ticks();

/* Wait for the given number of ticks (a plain forward to timer_sleep_ticks). */
void timer_api_sleep_ticks(unsigned short ticks)

{
  timer_sleep_ticks(ticks);
  return;
}
