/* timer_tick_isr  (FUN_a00618d8)
 *
 * Advance the tick count, slow-tick flags and the 16 software timers on each timer interrupt.
 * Note: Sets flags every 5, 50 and 500 ticks and calls two optional tick hooks.
 * Name basis: proven - interrupt-4 source handler (table 0xA80787A8); counts down the 16 task records also
 *   read by the deferred-call loop
 *
 * Matching notes
 * --------------
 * FUN_a00618d8 (leon2s 0xa00618d8-0xa0061a6c, 404 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the sleep down counter is declared volatile: the firmware reads it again for the decrement, which GCC only
 *    does for a volatile access;
 *  - in the task loop the one-shot arm (periodic == 0) comes first.
 */
/* One software timer, 24 bytes (sys_task_run_pending calls fn of every timer marked pending). */
struct Task {
    unsigned int periodic;      /* non-zero: reload count from period when it expires; zero: one shot */
    unsigned char active;       /* counting only while non-zero */
    unsigned char pending;      /* set to 1 when count reached 0 */
    unsigned char _6[2];
    unsigned int period;        /* ticks; 0 = the timer does not count */
    unsigned int count;         /* ticks left */
    unsigned int enabled;       /* counting only while non-zero */
    void (*fn)(void);
};
/* timer_tick_record: three words (+0 w0, +4 tick count, +8 w8), the two tick hooks, the 16 timers. */
struct Timers {
    unsigned int w0;
    unsigned int tick;
    unsigned int w8;
    void (*cb[2])(int);
    struct Task task[16];
};
extern struct Timers timer_tick_record;
extern volatile unsigned int timer_sleep_countdown;
extern unsigned int timer_tick_isr_count;
extern unsigned char timer_task_pending_flag;
extern unsigned char timer_div5_flag;
extern unsigned char timer_div50_flag;
extern unsigned char timer_div500_flag;
extern unsigned int timer_div5_count;
extern unsigned int timer_div50_count;
extern unsigned int timer_div500_count;
extern unsigned int timer_tick_count_second;

/*
 * Timer interrupt handler, one call per tick. In this order it: sets timer_task_pending_flag (sys_task_run_pending
 * clears it); counts timer_sleep_countdown down towards 0; advances three dividers that raise a flag every 5, 50
 * and 500 ticks (the flags are cleared by their users, not here); increments the tick count in
 * timer_tick_record and timer_tick_count_second; steps the 16 software timers; calls the two optional tick hooks
 * with argument 0; and counts the interrupt in timer_tick_isr_count.
 * A timer counts down only while enabled, active and its period is non-zero. At 0 it is marked pending (sys_task_run_pending
 * runs its routine later) and then either reloaded with its period (periodic) or made
 * inactive (one shot).
 */
void timer_tick_isr(void)
{
    int i;
    unsigned char j;
    struct Task *t;

    timer_task_pending_flag = 1;
    if (timer_sleep_countdown != 0)
        timer_sleep_countdown--;
    if (++timer_div5_count > 4) {
        timer_div5_flag = 1;
        timer_div5_count = 0;
    }
    if (++timer_div50_count > 0x31) {
        timer_div50_flag = 1;
        timer_div50_count = 0;
    }
    if (++timer_div500_count > 499) {
        timer_div500_flag = 1;
        timer_div500_count = 0;
    }
    timer_tick_record.tick++;
    timer_tick_count_second++;
    for (i = 0; i < 16; i++) {
        t = &timer_tick_record.task[i];
        if (t->enabled != 0 && t->active != 0 && t->period != 0) {
            if (--t->count == 0) {
                t->pending = 1;
                if (t->periodic == 0)
                    t->active = 0;
                else
                    t->count = t->period;
            }
        }
    }
    for (j = 0; j < 2; j++)
        if (timer_tick_record.cb[j] != 0)
            timer_tick_record.cb[j](0);
    timer_tick_isr_count++;
}
