/* osd_set_seconds_countdown  (FUN_a0090f94)
 *
 * Set the menu's one-second countdown.
 *   seconds
 * Note: Halfword 0xA802AFF2, counted down every 1000 ms by the menu timer handler.
 * Name basis: derived - counted down each second in osd_run_periodic_task, which acts when it reaches 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0090f94, flags -mcpu=v8 -O2 -g.
 */

extern unsigned short osd_seconds_countdown;

/* Store the value of the menu's one-second countdown. */
void osd_set_seconds_countdown(unsigned short seconds)

{
  osd_seconds_countdown = seconds;
  return;
}
