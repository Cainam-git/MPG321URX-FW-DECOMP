/* input_adc_get_level2  (FUN_a00f3960)
 *
 * Return the third of the three level bytes that the calibration routines save and restore.
 * Returns: byte
 * Name basis: descriptive - register 0xCF020008; called 'level' after its use in the calibration routines,
 *   which is all the code shows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3960 @ 0xa00f3960, flags -mcpu=v8 -O3 -g.
 */

#define reg_input_adc_level2 (*(volatile unsigned int *)0xcf020008)

/* Return the low byte of the third level register (0xCF020008) of the analogue input stage. */
unsigned int input_adc_get_level2(void)

{
  return reg_input_adc_level2 & 0xff;
}