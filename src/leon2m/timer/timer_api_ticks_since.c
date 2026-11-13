/* timer_api_ticks_since  (FUN_a0147740)
 *
 * Return the ticks passed since an earlier tick count.
 * Returns: elapsed ticks
 * Name basis: proven - forwards to timer_ticks_since
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147740 @ 0xa0147740, flags -mcpu=v8 -O3 -g.
 * Source form: the routine keeps the unused second parameter of the decompiled form; the first parameter is
 * masked with 0xffff in place before the call; the callee is declared without a prototype.
 */
extern int timer_ticks_since();

/*
 * Return the number of ticks that have passed since the 16-bit tick count `earlier` (a plain forward to
 * timer_ticks_since). The second argument is not used.
 */
unsigned short timer_api_ticks_since(unsigned short earlier,unsigned int unused)

{
  earlier = earlier & 0xffff;
  return timer_ticks_since(earlier);
}
