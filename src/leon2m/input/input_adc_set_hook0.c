/* input_adc_set_hook0  (FUN_a00f39d4)
 *
 * Store entry 0 of the calibration's four-entry hook record.
 * Name basis: descriptive - word at 0xA802B79C + 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f39d4 @ 0xa00f39d4, 12 bytes, leaf, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the return delay slot).
 */
extern unsigned int input_adc_cal_hooks;

/* Store the first word of the four-word record at 0xA802B79C (words 1 to 3 are input_adc_set_hook1..3).
 * The calibration code calls this word as a function pointer, with a progress number, when it is not zero
 * (input_adc_auto_adjust). Nothing calls this routine that stores it. */
void input_adc_set_hook0(unsigned int value)
{
    input_adc_cal_hooks = value;
}
