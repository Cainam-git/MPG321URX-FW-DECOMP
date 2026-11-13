/* input_adc_get_offset1  (FUN_a00f39ac)
 *
 * Return the second of the three offset bytes that the calibration routines save and restore.
 * Returns: byte
 * Name basis: descriptive - register 0xCF020010; called 'offset' after its use in the calibration routines,
 *   which is all the code shows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f39ac @ 0xa00f39ac, flags -mcpu=v8 -O3 -g.
 */
#define reg_input_adc_offset1 (*(volatile unsigned int *)0xcf020010)

/* Read the low byte of the register at 0xCF020010; saved and restored by the calibration like the other offsets. */
unsigned int input_adc_get_offset1(void)
{
    return reg_input_adc_offset1 & 0xff;
}
