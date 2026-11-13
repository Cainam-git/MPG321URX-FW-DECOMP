/* input_adc_get_offset0  (FUN_a00f39c0)
 *
 * Return the first of the three offset bytes that the calibration routines save and restore.
 * Returns: byte
 * Name basis: descriptive - register 0xCF02000C; called 'offset' after its use in the calibration routines,
 *   which is all the code shows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f39c0 @ 0xa00f39c0, flags -mcpu=v8 -O3 -g.
 */
#define reg_input_adc_offset0 (*(volatile unsigned int *)0xcf02000c)

/* Read the low byte of the register at 0xCF02000C; saved and restored by the calibration like the other offsets. */
unsigned int input_adc_get_offset0(void)
{
    return reg_input_adc_offset0 & 0xff;
}
