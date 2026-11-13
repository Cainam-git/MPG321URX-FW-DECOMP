/* sys_app_ticks_since  (FUN_a0086ac8)
 *
 * Return the milliseconds elapsed since t0.
 *   t0: start time
 * Returns: elapsed ms, 16 bits
 * Note: Nothing calls it directly.
 * Name basis: derived - code: ms tick minus t0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0086ac8 @ 0xa0086ac8-0xa0086ae8 (8 words), flags -mcpu=v8 -O3 -g.
 * Code facts: returns (u16)(timer_api_get_ticks16() - t0): elapsed ticks since t0 (timer_api_get_ticks16 returns a u16, its asm
 * ends in srl 16). One parameter, subtracted with 'sub %o0, %i0'. Aids: none.
 */
extern unsigned short timer_api_get_ticks16(void);

/*
 * Return the ticks that passed since the tick count t0, as a 16-bit value (the tick count is 16 bits wide and
 * wraps around).
 */
unsigned short sys_app_ticks_since(unsigned int t0)
{
    return timer_api_get_ticks16() - t0;
}
