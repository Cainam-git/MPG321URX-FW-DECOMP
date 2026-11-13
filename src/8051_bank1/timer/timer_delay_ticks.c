/* timer_delay_ticks  (FUN_CODE_d44e)
 *
 * Wait the given number of system ticks.
 *   ticks_minus_one
 * Name basis: proven - busy-waits on the timer 0 tick counter
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d44e @ 0xd44e  Options: OPTIMIZE(8,SPEED).
 * Source form: the parameter and the start tick are DATA locals (SMALL model overlay), so the parameter is
 * incremented in place rather than copied.
 */
extern unsigned char xdata DAT_EXTMEM_f00a;
unsigned int timer_get_ticks(void);

/*
 * Busy-wait for ticks_minus_one + 1 system ticks (timer_get_ticks counts them). Every pass of the wait loop writes
 * 0x55 to XDATA 0xF00A (the same write is made in uart_flush_tx_queue_port2 and uart_putchar; its purpose is not shown).
 * On entry the parameter is the tick count minus one; the routine increments it once and keeps using it as the
 * tick count.
 */
void timer_delay_ticks(unsigned int ticks_minus_one)
{
    unsigned int start;

    ticks_minus_one++;
    start = timer_get_ticks();
    while (timer_get_ticks() - start < ticks_minus_one) DAT_EXTMEM_f00a = 0x55;
}
