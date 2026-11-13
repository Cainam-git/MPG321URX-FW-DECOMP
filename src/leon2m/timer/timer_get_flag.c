/* timer_get_flag  (FUN_a00dedb0)
 *
 * Return the timer flag byte.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802B0BD; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dedb0 @ 0xa00dedb0, flags -mcpu=v8 -O2 -g (leaf routine).
 * Source form: a direct read of the extern byte.
 */
extern unsigned char timer_flag;

/*
 * Return the byte timer_flag. timer_tick_isr sets it to 1 every 128 ticks while the 128-tick counter is
 * enabled. Nothing calls this routine.
 */
unsigned char timer_get_flag(void)
{
    return timer_flag;
}
