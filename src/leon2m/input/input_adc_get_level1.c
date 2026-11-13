/* input_adc_get_level1  (FUN_a00f3974)
 *
 * Return the second of the three level bytes that the calibration routines save and restore.
 * Returns: byte
 * Name basis: descriptive - register 0xCF020004; called 'level' after its use in the calibration routines,
 *   which is all the code shows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3974 @ 0xa00f3974, flags -mcpu=v8 -O3 -g.
 */

#define reg_input_adc_level1 (*(volatile unsigned int *)0xcf020004)

/* Return the low byte of the second level register (0xCF020004) of the analogue input stage. */
unsigned int input_adc_get_level1(void)

{
  return reg_input_adc_level1 & 0xff;
}