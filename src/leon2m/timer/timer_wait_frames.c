/* timer_wait_frames  (FUN_a0121bcc)
 *
 * Wait for up to ten frame periods at a given refresh rate.
 * Name basis: proven - N * 10000 / rate + 1 ms for 20..365 Hz, else N * 20 ms
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121bcc, flags -mcpu=v8 -O3 -g.
 * The two timer routines are declared under their ROM address names (func_0x4008d588, func_0x4008d594). The wait
 * loop body is a single nop.
 */
extern unsigned short timer_get_ticks16(void);                 /* = timer_get_ticks16: ms tick counter now */
extern unsigned short timer_ticks_since(unsigned short);       /* = timer_ticks_since: ms elapsed since start */

/* The longest wait, in frames, and the refresh rates (tenths of a hertz) the frame length is computed for. */
#define MAX_FRAMES      10
#define RATE_MIN        200     /* 20.0 Hz */
#define RATE_MAX        3650    /* 365.0 Hz */
#define FALLBACK_TICKS_PER_FRAME 20

/*
 * Busy-wait for 'frames' frame periods (at most MAX_FRAMES) of a picture refreshed at 'rate' tenths of a hertz.
 * For a rate from RATE_MIN to RATE_MAX the wait is frames * 10000 / rate + 1 ticks (10000 / rate is one frame
 * period in milliseconds); for any other rate it is frames * FALLBACK_TICKS_PER_FRAME ticks. Called by the display
 * timing code (for example panel_output_setup_channel_timing, pq_block_read_reg89_pair_average and panel_correct_clock_second_step).
 */
void timer_wait_frames(unsigned char frames, unsigned short rate)
{
    unsigned short ticks, start;
    if (frames > MAX_FRAMES) frames = MAX_FRAMES;
    if (rate >= RATE_MIN && rate <= RATE_MAX) ticks = (unsigned int)(frames * 10000) / rate + 1;
    else ticks = frames * FALLBACK_TICKS_PER_FRAME;
    start = timer_get_ticks16();
    while (timer_ticks_since(start) < ticks) __asm__ volatile ("nop");
}
