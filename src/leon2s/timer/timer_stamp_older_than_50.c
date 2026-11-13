/* timer_stamp_older_than_50  (FUN_a008f990)
 *
 * Return whether more than 50 ticks passed since a time stamp.
 *   stamp: time stamp
 * Returns: 1 when elapsed
 * Name basis: proven - now - t0 >= 0x33 with wrap handling
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f990 @ 0xa008f990-0xa008f9c0 (12 words), flags -mcpu=v8 -Os -g.
 * Source form: the elapsed time is set in both arms of an if/else on now >= stamp. The limit 0x33 is a local: as
 * a literal the compare becomes "d > 0x32" with a branch, and with the constant known only after cse it stays
 * an unsigned >= and gives the firmware's 'cmp; subx %g0, -1'.
 */
extern unsigned int timer_get_ticks(void);

/*
 * Return 1 when at least 0x33 (51) ticks have passed since a time stamp, else 0.
 *   stamp: tick count taken earlier from timer_get_ticks
 * The elapsed time is now - stamp, less 1 more when now is below stamp (the counter wrapped).
 */
int timer_stamp_older_than_50(unsigned int stamp)
{
    unsigned int now = timer_get_ticks();
    unsigned int elapsed;
    unsigned int limit = 0x33;

    if (now >= stamp)
        elapsed = now - stamp;
    else
        elapsed = now - stamp - 1;
    return elapsed >= limit;
}
