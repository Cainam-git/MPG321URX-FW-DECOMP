/* input_adc_set_offset1  (FUN_a00f3930)
 *
 * Write the second offset value of the analogue input stage.
 * Name basis: descriptive - register 0xCF020010
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3930 @ 0xa00f3930, flags -mcpu=v8 -O2 -g (section default).
 */

#define reg_input_adc_offset1 (*(volatile unsigned int *)0xcf020010)

/* Write the low byte of value to the second offset register (0xCF020010) of the analogue input stage. */
void input_adc_set_offset1(unsigned int value)

{
  reg_input_adc_offset1 = value & 0xff;
  return;
}