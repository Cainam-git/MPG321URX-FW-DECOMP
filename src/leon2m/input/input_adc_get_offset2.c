/* input_adc_get_offset2  (FUN_a00f3998)
 *
 * Return the third of the three offset bytes that the calibration routines save and restore.
 * Returns: byte
 * Name basis: descriptive - register 0xCF020014; called 'offset' after its use in the calibration routines,
 *   which is all the code shows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3998 @ 0xa00f3998, flags -mcpu=v8 -O3 -g.
 */
#define reg_input_adc_offset2 (*(volatile unsigned int *)0xcf020014)

/* Read the low byte of the register at 0xCF020014; saved and restored by the calibration like the other offsets. */
unsigned int input_adc_get_offset2(void)
{
    return reg_input_adc_offset2 & 0xff;
}
