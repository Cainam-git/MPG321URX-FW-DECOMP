/* input_port_timers_update  (FUN_a013b7e0)
 *
 * Count the nine port timers down by the ticks that have passed.
 * Name basis: proven - same update as input_port_timer_start without starting one; called from the main-loop
 *   task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b7e0 @ 0xa013b7e0, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the new time is the return value of timer_get_ticks16 declared as
 * unsigned short; the nine timers are updated in a for loop with an unsigned char counter.
 */

extern unsigned short input_port_timers_ticks;      /* tick count at the last update */
extern unsigned short ARR_a802cbbe[];               /* the nine port timers, in ticks */
extern unsigned short timer_get_ticks16(void);

#define PORT_TIMER_COUNT 9

/*
 * Count the nine port timers down by the ticks that have passed since the last update, stopping at 0, and
 * return the value of one of them.
 *
 *   timer_index  which timer to return (0..8)
 *
 * Called from sys_main_loop_periodic_task.
 */
unsigned short input_port_timers_update(int timer_index)
{
    unsigned short now = timer_get_ticks16();
    unsigned short elapsed = now - input_port_timers_ticks;
    unsigned char i;

    input_port_timers_ticks = now;
    for (i = 0; i <= PORT_TIMER_COUNT - 1; i++) {
        if (ARR_a802cbbe[i] < elapsed)
            ARR_a802cbbe[i] = 0;
        else
            ARR_a802cbbe[i] -= elapsed;
    }
    return ARR_a802cbbe[timer_index];
}
