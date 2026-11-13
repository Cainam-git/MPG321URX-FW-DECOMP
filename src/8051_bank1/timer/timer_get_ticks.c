/* timer_get_ticks  (FUN_CODE_d94a)
 *
 * Return a consistent copy of the 16-bit system tick counter.
 * Returns: tick count
 * Name basis: proven - re-reads the tick counter written by irq_timer0_tick until two reads agree
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d94a @ 0xd94a  Options: OPTIMIZE(8,SPEED).
 * volatile is real on the tick counter: it is read again for the compare (XRL A,@R0). The copy is not volatile:
 * Keil keeps it in R6:R7 for the compare and the return. Without the return value (void forms) or with the copy
 * volatile Keil keeps the counter in R6:R7 instead (45..61 %).
 */
extern unsigned int volatile idata timer_tick_count;
extern unsigned int idata timer_tick_copy;

/*
 * Return the 16-bit system tick count. The 8051 reads the two bytes one by one, so the counter is copied until
 * the copy equals the counter again.
 */
unsigned int timer_get_ticks(void)
{
    do timer_tick_copy = timer_tick_count; while (timer_tick_copy != timer_tick_count);
    return timer_tick_copy;
}
