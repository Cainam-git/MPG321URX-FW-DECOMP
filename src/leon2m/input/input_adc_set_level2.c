/* input_adc_set_level2  (FUN_a00f38d4)
 *
 * Write the third level value of the analogue input stage.
 * Name basis: descriptive - register 0xCF020008
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f38d4 @ 0xa00f38d4, flags -mcpu=v8 -O2 -g (section default).
 */

#define reg_input_adc_level2 (*(volatile unsigned int *)0xcf020008)

/* Write the low byte of value to the third level register (0xCF020008) of the analogue input stage. */
void input_adc_set_level2(unsigned int value)

{
  reg_input_adc_level2 = value & 0xff;
  return;
}