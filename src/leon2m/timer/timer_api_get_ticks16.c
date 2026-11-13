/* timer_api_get_ticks16  (FUN_a0147724)
 *
 * Return the current 16-bit tick count.
 * Returns: tick count
 * Name basis: proven - forwards to timer_get_ticks16
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147724 @ 0xa0147724, flags -mcpu=v8 -O2 -g.
 * Source form: the routine keeps the two unused parameters of the decompiled form; the callee is declared
 * without a prototype and its int result is returned as unsigned short.
 */
extern int timer_get_ticks16();

/* Return the low 16 bits of the tick count (a plain forward to timer_get_ticks16). The arguments are not used. */
unsigned short timer_api_get_ticks16(unsigned int unused_1,unsigned int unused_2)

{
  return timer_get_ticks16();
}
