/* sys_app_timer_start  (FUN_a00869b0)
 *
 * Age all 23 application timers, then start timer id with ms.
 *   id: timer number 0..22
 *   ms: time in ms
 * Note: Down-counters at 0xA802AF6A, last snapshot 0xA802AF68.
 * Name basis: proven - header: APP timer start
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00869b0 @ 0xa00869b0, flags -mcpu=v8 -O3 -g
 * APP timer start: ages all 23 u16 down-counters app_timers[] by the ms elapsed since the last
 * tick snapshot app_timers_snapshot (timer_api_get_ticks16 = ms tick), counters below the elapsed time become 0;
 * then sets counter 'id' to 'ms'.
 */
extern unsigned short timer_api_get_ticks16();
extern unsigned short app_timers_snapshot;
extern unsigned short app_timers[];

#define APP_TIMER_COUNT 23              /* number of application timers */

/*
 * Age all application timers, then start timer id with the time ms.
 *
 *   id   timer number 0..22
 *   ms   time in milliseconds
 *
 * The timers are down-counters that are only brought up to date when this routine or sys_app_timer_read runs:
 * each one loses the ticks that passed since app_timers_snapshot, and a timer with less left than that becomes 0.
 */
void sys_app_timer_start(int id, int ms)
{
    unsigned short now = timer_api_get_ticks16();
    unsigned short elapsed = now - app_timers_snapshot;
    unsigned char i;

    app_timers_snapshot = now;
    for (i = 0; i < APP_TIMER_COUNT; i++) {
        if (app_timers[i] < elapsed)
            app_timers[i] = 0;
        else
            app_timers[i] -= elapsed;
    }
    app_timers[id] = ms;
}
