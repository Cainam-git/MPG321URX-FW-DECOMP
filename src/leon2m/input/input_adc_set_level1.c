/* input_adc_set_level1  (FUN_a00f38ec)
 *
 * Write the second level value of the analogue input stage.
 * Name basis: descriptive - register 0xCF020004
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f38ec @ 0xa00f38ec, flags -mcpu=v8 -O2 -g (section default).
 */

#define reg_input_adc_level1 (*(volatile unsigned int *)0xcf020004)

/* Write the low byte of value to the second level register (0xCF020004) of the analogue input stage. */
void input_adc_set_level1(unsigned int value)

{
  reg_input_adc_level1 = value & 0xff;
  return;
}