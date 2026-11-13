/* timer_tick_isr  (FUN_a002cfb8)
 *
 * Count one timer tick: sleep countdown, 5/50/500-tick flags, tick counter, hook.
 * Note: Installed by timer_init as a level-4 interrupt source handler; all timer_sleep waits depend on it.
 * Name basis: proven - header: timer tick interrupt handler for timer 0xC00A0000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002cfb8 @ 0xa002cfb8..0xa002d10c (85 words), flags -mcpu=v8 -O3 -g.
 * Source form: only timer_sleep_countdown is volatile, as in timer_sleep_ticks (the firmware loads it twice
 * here, which a non-volatile object would not).
 */
/* The timer record at timer_tick_record (same layout as in timer_init); only +4 and hook 0 are used here. */
struct timer_record {
    unsigned char initialised;          /* 1 once timer_init has run */
    unsigned char pad[3];
    unsigned int tick_count;            /* +4: counted here */
    unsigned int word_0x8;
    void (*hooks[5])(int);              /* +0x0c: hook words; hook 0 is called here with 0 */
};
extern unsigned char timer_tick_flag, timer_div5_flag, timer_div50_flag, timer_div500_flag;
extern unsigned int timer_div5_count, timer_div50_count, timer_div500_count, timer_isr_count_since_init;
extern volatile unsigned int timer_sleep_countdown;
extern unsigned char timer_128_tick_enable, timer_flag;
extern unsigned int timer_128_tick_counter, timer_isr_count;
extern struct timer_record timer_tick_record;

/* Each divider counts 0..LAST, then raises its flag and starts again at 0. */
#define DIV5_LAST     4                 /* every 5th tick */
#define DIV50_LAST    0x31              /* every 50th tick */
#define DIV500_LAST   0x1f3             /* every 500th tick */
#define DIV128_LAST   0x7f              /* every 128th tick, only while timer_128_tick_enable is set */

/*
 * Timer tick interrupt: interrupt level 4, source 0, registered by timer_init. It has no loop and never
 * waits.
 *
 * Sets timer_tick_flag, counts timer_sleep_countdown down to 0 (timer_sleep_ticks spins on it, so every
 * timer_sleep_ticks wait needs this routine running), raises the 5-, 50- and 500-tick flags and, when enabled,
 * timer_flag every 128 ticks, counts timer_isr_count_since_init, the record's tick_count and timer_isr_count,
 * and calls hook 0 of the record with 0 when it is set.
 */
void timer_tick_isr(void)
{
    timer_tick_flag = 1;
    if (timer_sleep_countdown != 0)
        timer_sleep_countdown = timer_sleep_countdown - 1;
    if (++timer_div5_count > DIV5_LAST) {
        timer_div5_flag = 1;
        timer_div5_count = 0;
    }
    if (++timer_div50_count > DIV50_LAST) {
        timer_div50_flag = 1;
        timer_div50_count = 0;
    }
    if (++timer_div500_count > DIV500_LAST) {
        timer_div500_flag = 1;
        timer_div500_count = 0;
    }
    if (timer_128_tick_enable != 0) {
        if (++timer_128_tick_counter > DIV128_LAST) {
            timer_flag = 1;
            timer_128_tick_counter = 0;
        }
    }
    timer_isr_count_since_init++;
    timer_tick_record.tick_count++;
    if (timer_tick_record.hooks[0] != 0)
        timer_tick_record.hooks[0](0);
    timer_isr_count++;
}
