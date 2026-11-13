/* timer_sleep_ticks  (FUN_a002d1a0)
 *
 * Wait n + 1 timer ticks; warn once when the tick interrupt seems stopped.
 *   ticks: ticks to wait minus one
 * Note: Spins on the countdown 0xA802B0C0 decremented by timer_tick_isr; never returns if the tick interrupt
 *   is off.
 * Name basis: proven - text '**Warning!! Sleep is stopped! Please check ISR!!**'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002d1a0 @ 0xa002d1a0, flags -mcpu=v8 -O3 -g.
 * Source form: timer_sleep_countdown is volatile (read again in every pass); dbg_printf is declared without
 * a prototype.
 */
extern unsigned int sys_clock_hz;
extern volatile unsigned int timer_sleep_countdown;
extern unsigned int timer_sleep_watch_count;
extern int dbg_printf();

#define WATCH_DIVIDER 100               /* passes of the wait loop before the warning: sys_clock_hz / 100 */

/*
 * Busy-wait for timer ticks: timer_sleep_countdown gets ticks + 1 (16 bits) and timer_tick_isr counts it
 * down once per tick; the routine returns when it reaches 0. Called from all over the program.
 *
 *   ticks   ticks to wait; the countdown starts at ticks + 1
 *
 * A pass counter starts at sys_clock_hz / 100. When it runs out while the countdown still holds its start
 * value (no tick has come), "Sleep is stopped! Please check ISR" is printed; the wait goes on regardless, so
 * without the tick interrupt it never ends.
 */
void timer_sleep_ticks(int ticks)
{
  unsigned short start_count;

  start_count = ticks + 1U & 0xffff;
  timer_sleep_watch_count = sys_clock_hz / WATCH_DIVIDER;
  timer_sleep_countdown = start_count;
  while (timer_sleep_countdown != 0) {
    timer_sleep_watch_count = timer_sleep_watch_count - 1;
    if ((timer_sleep_watch_count == 0) && (start_count == timer_sleep_countdown)) {
      dbg_printf("**Warning!! Sleep is stopped! Please check ISR!!**\r\n");
    }
  }
}