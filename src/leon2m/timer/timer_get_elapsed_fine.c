/* timer_get_elapsed_fine  (FUN_a00dec90)
 *
 * Return the time passed since a tick count, in fine units.
 * Returns: elapsed time
 * Name basis: derived - ticks times 10000 plus timer 0's value minus the record's word at +8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dec90 @ 0xa00dec90, flags -mcpu=v8 -O3 -g.
 * Source form: the "record not initialised" case jumps with 'goto none' over the computation to a single
 * 'return 0' at the end of the function (the firmware places the "one less" arm out of line after the return).
 */

/* Timer 0 register read here (timer_init writes its reload value to the same address). */
#define TIMER0_REG 0xc00a0000
#define TIMER_UNITS_PER_TICK 10000

/* The timer record at timer_tick_record; the other timer routines use the same layout. */
struct timer_record {
    unsigned char initialised;          /* 1 once timer_init has run */
    unsigned char pad[3];
    unsigned int tick_count;            /* +4: counted by timer_tick_isr */
    unsigned int word_0x8;
    unsigned int hooks[5];              /* +0x0c: hook words; hook 0 is called by timer_tick_isr */
    unsigned int word_0x20;
    unsigned int word_0x24;
};
extern struct timer_record timer_tick_record;
extern unsigned int reg_read32(unsigned int);

/*
 * Return the time since the tick count 'start_tick', as whole ticks times 10000 plus the difference between
 * the current value of timer 0 and the record's word at +8. Returns 0 while the timer record is not
 * initialised. Nothing calls it.
 *
 *   start_tick  tick count to measure from
 *
 * When the record's tick count is not above start_tick, one tick less is counted.
 */
int timer_get_elapsed_fine(unsigned int start_tick)
{
    unsigned int timer_value = reg_read32(TIMER0_REG);
    unsigned int ticks;

    if (timer_tick_record.initialised == 0)
        goto none;
    if (timer_tick_record.tick_count > start_tick)
        ticks = timer_tick_record.tick_count - start_tick;
    else
        ticks = timer_tick_record.tick_count - start_tick - 1;
    return ticks * TIMER_UNITS_PER_TICK + (timer_value - timer_tick_record.word_0x8);
none:
    return 0;
}
