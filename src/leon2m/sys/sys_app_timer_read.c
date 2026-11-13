/* sys_app_timer_read  (FUN_a0086a3c)
 *
 * Age all 23 application timers and return the time left on timer id.
 *   id: timer number 0..22
 * Returns: ms left, 0 = expired
 * Name basis: proven - header: APP timer read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0086a3c @ 0xa0086a3c, flags -mcpu=v8 -O3 -g
 * APP timer read: ages all 23 u16 down-counters app_timers[] by the ms elapsed since the last
 * tick snapshot app_timers_snapshot (timer_api_get_ticks16 = ms tick), counters below the elapsed time become 0;
 * returns counter 'id' (0 = expired). Same ageing loop as sys_app_timer_start (timer start).
 */
extern unsigned short timer_api_get_ticks16();
extern unsigned short app_timers_snapshot;
extern unsigned short app_timers[];

#define APP_TIMER_COUNT 23              /* number of application timers */

/*
 * Age all application timers and return the time left on timer id.
 *
 *   id   timer number 0..22
 *
 * Returns the time left in milliseconds; 0 means the timer has expired. The ageing is the same as in
 * sys_app_timer_start: each timer loses the ticks since app_timers_snapshot, and one with less left becomes 0.
 */
unsigned short sys_app_timer_read(int id)
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
    return app_timers[id];
}
