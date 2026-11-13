/* input_adc_set_level0  (FUN_a00f3904)
 *
 * Write the first level value of the analogue input stage.
 * Name basis: descriptive - register 0xCF020000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3904 @ 0xa00f3904, flags -mcpu=v8 -O2 -g (section default).
 */

#define reg_input_adc_level0 (*(volatile unsigned int *)0xcf020000)

/* Write the low byte of value to the first level register (0xCF020000) of the analogue input stage. */
void input_adc_set_level0(unsigned int value)

{
  reg_input_adc_level0 = value & 0xff;
  return;
}