/* power_set_wakeup_timer  (FUN_CODE_c830)
 *
 * Start the wake-up timer with a time in seconds.
 *   seconds: time
 * Name basis: proven - command 0x1C prints 'setWakeupTimer %04x'; prints 'wakeup timer setup'; 0xA62A = t *
 *   1000 counted down by power_check_wakeup_timer
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c830 @ 0xc830 (79 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Source form: the store and the multiplication are two statements (the firmware writes the long, reads it back
 * and writes it again); printf is reached with a tail jump.
 */
extern unsigned long xdata power_wakeup_timer_remaining;
extern unsigned int xdata power_wakeup_timer_ticks;
extern unsigned int timer_get_ticks(void);
extern void lib_printf517(void *fmt, ...) large;   /* printf */

/*
 * Start the wake-up timer: the remaining time is seconds * 1000 (counted
 * down by power_check_wakeup_timer), the current tick count is remembered,
 * and the value is printed. Only caller: command 0x1C of the command switch
 * (its own text: "setWakeupTimer %04x").
 */
void power_set_wakeup_timer(unsigned int seconds)
{
    power_wakeup_timer_remaining = seconds;
    power_wakeup_timer_remaining = power_wakeup_timer_remaining * 1000;
    power_wakeup_timer_ticks = timer_get_ticks();
    lib_printf517((void code *)0x991d /* "wakeup timer setup %08lx\r\n" */, power_wakeup_timer_remaining);
}
