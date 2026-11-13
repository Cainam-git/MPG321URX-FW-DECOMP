/* input_adc_set_hook2  (FUN_a00f39ec)
 *
 * Store entry 2 of the calibration's four-entry hook record.
 * Name basis: descriptive - word at 0xA802B79C + 8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f39ec @ 0xa00f39ec, 12 bytes, leaf, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the return delay slot).
 */
extern unsigned int input_adc_cal_hook2;

/* Store the third word of the record at 0xA802B79C. Nothing calls this routine. */
void input_adc_set_hook2(unsigned int value)
{
    input_adc_cal_hook2 = value;
}
