/* hdr_is_update_due  (FUN_a00d3670)
 *
 * Return whether more than 200 ticks have passed since the last curve update.
 * Returns: 0 or 1
 * Name basis: derived - tick difference against the stamp, with wrap
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d3670 @ 0xa00d3670-0xa00d36a4 (13 words), flags -mcpu=v8 -Os -g.
 * Source form: the form of timer_stamp_older_than_50 (the stamp is read before the call, the limit is a local unsigned int).
 * The comparison is d >= 0xc9, which gives the compare and subtract-with-carry the firmware uses.
 */
extern unsigned int hdr_last_update_ticks;
extern unsigned int timer_get_ticks(void);

#define UPDATE_TICKS_LIMIT 0xc9         /* "more than 200 ticks" is written as at least 201 */

/*
 * Return 1 when more than 200 ticks have passed since hdr_last_update_ticks, else 0. When the tick count has
 * wrapped (now below the stamp) the difference is one less than the plain subtraction. hdr_task stamps
 * hdr_last_update_ticks whenever the source reports HDR, and calls this routine, its only caller, when it does
 * not.
 */
int hdr_is_update_due(void)
{
    unsigned int stamp = hdr_last_update_ticks;
    unsigned int now = timer_get_ticks();
    unsigned int elapsed;
    unsigned int limit = UPDATE_TICKS_LIMIT;

    if (now >= stamp)
        elapsed = now - stamp;
    else
        elapsed = now - stamp - 1;
    return elapsed >= limit;
}
