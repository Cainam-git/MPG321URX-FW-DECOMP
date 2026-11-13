/* timer_raise_128_tick_flag  (FUN_a002d138)
 *
 * Set the flag byte timer_tick_isr raises every 128 ticks when enabled.
 * Note: Byte 0xA802B0BD; nothing calls it.
 * Name basis: descriptive - timer_tick_isr sets the same byte
 *
 * Matching notes
 * --------------
 * FUN_a002d138 (leon2m 0xa002d138-0xa002d148, 16 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a direct store of a constant to the extern byte (the store sits in the retl delay slot).
 */
extern unsigned char timer_flag;

/*
 * Set timer_flag by hand, the byte timer_tick_isr sets every 128 ticks while timer_128_tick_enable is set.
 * Nothing in the image refers to this routine (no call, branch, sethi/or constant or address word).
 */
void timer_raise_128_tick_flag(void)
{
    timer_flag = 1;
}
