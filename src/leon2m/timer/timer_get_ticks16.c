/* timer_get_ticks16  (FUN_a002d588)
 *
 * Return the low 16 bits of the tick counter.
 * Returns: ticks, 16 bits
 * Note: Halfword 0xA802B0CA = low half of the tick counter word.
 * Name basis: proven - 0xA802B0CA is the low half of the counter timer_tick_isr increments
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002d588 @ 0xa002d588, flags -mcpu=v8 -O2 -g (the section default). A leaf routine without a
 * register window.
 */
extern unsigned short timer_tick_record_count_low16;   /* low half of tick_count (+6 of timer_tick_record) */

/*
 * Return the low 16 bits of the tick counter as a time stamp; timer_ticks_since gives the ticks passed since
 * such a stamp. Used by the time-limited waits of many routines.
 */
unsigned short timer_get_ticks16(void)
{
  return timer_tick_record_count_low16;
}