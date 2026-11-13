/* timer_get_tick_count  (FUN_a002cfac)
 *
 * Return the 32-bit tick counter.
 * Returns: ticks since start-up
 * Note: Word 0xA802B0C8, incremented by timer_tick_isr; nothing calls this getter.
 * Name basis: proven - timer_tick_isr increments 0xA802B0C4.count = 0xA802B0C8
 *
 * Matching notes
 * --------------
 * FUN_a002cfac (leon2m 0xa002cfac-0xa002cfb8, 12 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a direct read of the extern word (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned int timer_tick_record_count;   /* tick_count (+4) of timer_tick_record */

/*
 * Return the 32-bit tick counter that timer_tick_isr counts up on every tick. Nothing in the image refers to
 * this routine (no call, branch, sethi/or constant or address word); timer_get_ticks16 returns its low half.
 */
unsigned int timer_get_tick_count(void)
{
    return timer_tick_record_count;
}
