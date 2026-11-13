/* timer_ticks_since  (FUN_a002d594)
 *
 * Return the ticks elapsed since the 16-bit time stamp t0.
 *   start_stamp: start time from timer_get_ticks16
 * Returns: elapsed ticks, 16 bits
 * Name basis: proven - paired with timer_get_ticks16 in time-limited waits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002d594 @ 0xa002d594, flags -mcpu=v8 -O3 -g.
 * Source form: the stamp parameter is a signed short.
 */
extern unsigned short timer_tick_record_count_low16;   /* low half of tick_count (+6 of timer_tick_record) */

/*
 * Return the ticks passed since 'start_stamp', a value from timer_get_ticks16. The difference is taken in
 * 16 bits, so it stays right across a wrap of the counter. Used together with timer_get_ticks16 in the
 * time-limited waits.
 */
unsigned short timer_ticks_since(short start_stamp)
{
  return timer_tick_record_count_low16 - start_stamp;
}