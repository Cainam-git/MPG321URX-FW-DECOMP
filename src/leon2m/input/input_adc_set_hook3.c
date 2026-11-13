/* input_adc_set_hook3  (FUN_a00f39f8)
 *
 * Store entry 3 of the calibration's four-entry hook record.
 * Name basis: descriptive - word at 0xA802B79C + 12; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f39f8 @ 0xa00f39f8, 12 bytes, leaf, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the return delay slot).
 */
extern unsigned int input_adc_cal_hook3;

/* Store the fourth word of the record at 0xA802B79C. input_adc_step_width_to_target calls this word as a function
 * pointer without arguments when it is not zero. Nothing calls this routine that stores it. */
void input_adc_set_hook3(unsigned int value)
{
    input_adc_cal_hook3 = value;
}
