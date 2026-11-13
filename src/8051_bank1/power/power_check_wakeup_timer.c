/* power_check_wakeup_timer  (FUN_CODE_9caa)
 *
 * Count down the wake-up timer and report when it has run out.
 * Returns: 1 when it expired
 * Name basis: proven - prints 'Wakeup by timer %08lx %04x'; 0x03E7FC18 = off; set by power_set_wakeup_timer
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9caa @ 0x9caa..0x9d75 (203 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE local: elapsed at XDATA 0xA473; now stays in R6:R7. The constant store is ?C?LSTKXDATA with the 4-byte
 * constant inline after the LCALL.
 */
extern unsigned long xdata power_wakeup_timer_remaining;
extern unsigned int xdata power_wakeup_timer_ticks;
extern unsigned int timer_get_ticks(void);
extern void lib_printf517(void *fmt, ...) large;

#define WAKEUP_TIMER_OFF  0x03e7fc18  /* = 65535 * 1000: no wake-up time set */

/*
 * power_check_wakeup_timer - count the wake-up timer down by the ticks since the last call (timer_get_ticks).
 * Returns 1 once when the remaining time runs out: it prints "Wakeup by timer %08lx %04x" and switches the timer
 * off. Returns 0 while the timer is off or still running.
 * power_set_wakeup_timer loads the timer with its argument * 1000.
 * Only caller: sys_main, which takes a 1 as wake-up reason WAKE_TIMER (0x0C).
 */
unsigned char power_check_wakeup_timer(void)
{
    unsigned int elapsed;
    unsigned int now;

    if (power_wakeup_timer_remaining == WAKEUP_TIMER_OFF)
        return 0;
    now = timer_get_ticks();
    elapsed = now - power_wakeup_timer_ticks;
    power_wakeup_timer_ticks = now;
    if (power_wakeup_timer_remaining < elapsed) {
        lib_printf517((void code *)0x9938, power_wakeup_timer_remaining, elapsed);   /* "Wakeup by timer %08lx %04x\r\n" */
        power_wakeup_timer_remaining = WAKEUP_TIMER_OFF;
        return 1;
    }
    power_wakeup_timer_remaining -= elapsed;
    return 0;
}
