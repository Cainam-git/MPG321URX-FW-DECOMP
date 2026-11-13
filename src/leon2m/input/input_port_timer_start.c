/* input_port_timer_start  (FUN_a013b754)
 *
 * Update the nine port timers and start one of them with a time value.
 * Name basis: proven - nine 16-bit down-counters at 0xA802CBBE, reduced by the ticks passed since the last
 *   call
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b754 @ 0xa013b754, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the loop is written as do/while with the increment and the end test
 * repeated in both arms and a goto to the final store; the timer table is a separate array label that is indexed
 * with a 16-bit stride. The return value of timer_get_ticks16 is taken as int and narrowed. The routine is void
 * (the incoming first argument is not returned).
 */

extern unsigned short input_port_timers_ticks;      /* tick count at the last update */
extern int timer_get_ticks16();
extern unsigned short ARR_a802cbbe[];               /* the nine port timers, in ticks */

#define PORT_TIMER_COUNT 9

/*
 * Bring the nine port timers up to date and then set one of them.
 *
 *   timer_index  which timer to set (0..8)
 *   ticks        the new value, in ticks
 *
 * Every timer is first counted down by the ticks that have passed since the last update (and stops at 0), the
 * same as input_port_timers_update does.
 */
void input_port_timer_start(int timer_index, int ticks)
{
    unsigned short now;
    unsigned short last;
    unsigned short elapsed;
    unsigned char idx;
    int i;
    unsigned short remaining;

    now = (unsigned short)timer_get_ticks16();
    last = input_port_timers_ticks;
    input_port_timers_ticks = now;
    elapsed = (unsigned short)(now - last);

    idx = 0;
    do {
        i = idx;
        remaining = ARR_a802cbbe[i];
        if (remaining < elapsed) {
            idx++;
            ARR_a802cbbe[i] = 0;
            if (idx > PORT_TIMER_COUNT - 1) goto done;
        } else {
            idx++;
            ARR_a802cbbe[i] = remaining - elapsed;
            if (idx > PORT_TIMER_COUNT - 1) goto done;
        }
    } while (idx <= PORT_TIMER_COUNT - 1);
done:
    ARR_a802cbbe[timer_index] = (unsigned short)ticks;
}
