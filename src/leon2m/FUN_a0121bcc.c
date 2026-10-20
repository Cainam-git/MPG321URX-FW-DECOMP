/* leon2m FUN_a0121bcc @ 0xa0121bcc  (-mcpu=v8 -O3 -g)
 *
 * Busy-waits for 'frames' frame periods (at most 10) of a picture whose refresh rate is 'rate' in tenths of Hz.
 *   rate 20.0..365.0 Hz (200..3650): frames * 10000 / rate + 1 ticks (10000 / rate = one frame period in ms)
 *   any other rate:                  frames * 20 ticks (20 ms per frame)
 * The ticks are the 16-bit counter read by func_0x4008d588 (= FUN_a002d588, returns 0xA802B0CA) and compared by
 * func_0x4008d594 (= FUN_a002d594, counter minus start). The frame arithmetic makes one tick = 1 ms.
 * Callers: the display timing code (FUN_a01038c0 five times, FUN_a00ef1b0, ...) waits for frames this way.
 */
extern unsigned short func_0x4008d588(void);                 /* = FUN_a002d588: ms tick counter now */
extern unsigned short func_0x4008d594(unsigned short);       /* = FUN_a002d594: ms elapsed since start */

void FUN_a0121bcc(unsigned char frames, unsigned short rate)
{
    unsigned short ticks, start;
    if (frames > 10) frames = 10;
    if (rate >= 200 && rate <= 3650) ticks = (unsigned int)(frames * 10000) / rate + 1;
    else ticks = frames * 20;
    start = func_0x4008d588();
    while (func_0x4008d594(start) < ticks) __asm__ volatile ("nop");
}
