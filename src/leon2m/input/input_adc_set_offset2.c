/* input_adc_set_offset2  (FUN_a00f3918)
 *
 * Write the third offset value of the analogue input stage.
 * Name basis: descriptive - register 0xCF020014
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3918 @ 0xa00f3918, flags -mcpu=v8 -O2 -g (section default).
 */

#define reg_input_adc_offset2 (*(volatile unsigned int *)0xcf020014)

/* Write the low byte of value to the third offset register (0xCF020014) of the analogue input stage. */
void input_adc_set_offset2(unsigned int value)

{
  reg_input_adc_offset2 = value & 0xff;
  return;
}