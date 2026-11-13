/* input_adc_set_hook1  (FUN_a00f39e0)
 *
 * Store entry 1 of the calibration's four-entry hook record.
 * Name basis: descriptive - word at 0xA802B79C + 4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f39e0 @ 0xa00f39e0, 12 bytes, leaf, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the return delay slot).
 */
extern unsigned int input_adc_cal_hook1;

/* Store the second word of the record at 0xA802B79C. Nothing calls this routine. */
void input_adc_set_hook1(unsigned int value)
{
    input_adc_cal_hook1 = value;
}
