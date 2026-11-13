/* input_adc_get_level0  (FUN_a00f3988)
 *
 * Return the first of the three level bytes that the calibration routines save and restore.
 * Returns: byte
 * Name basis: descriptive - register 0xCF020000; called 'level' after its use in the calibration routines,
 *   which is all the code shows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3988 @ 0xa00f3988, flags -mcpu=v8 -O2.
 */
#define reg_input_adc_level0 (*(volatile unsigned int *)0xcf020000)

/* Read the low byte of the register at 0xCF020000. The calibration routine input_adc_auto_color reads it
 * (together with the other levels and offsets) to save it before the calibration and put it back afterwards. */
unsigned int input_adc_get_level0(void)
{
    return reg_input_adc_level0 & 0xff;
}
