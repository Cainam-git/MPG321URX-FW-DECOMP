/* input_adc_set_offset0  (FUN_a00f3948)
 *
 * Write the first offset value of the analogue input stage.
 * Name basis: descriptive - register 0xCF02000C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3948 @ 0xa00f3948, flags -mcpu=v8 -O2 -g (section default).
 */

#define reg_input_adc_offset0 (*(volatile unsigned int *)0xcf02000c)

/* Write the low byte of value to the first offset register (0xCF02000C) of the analogue input stage. */
void input_adc_set_offset0(unsigned int value)

{
  reg_input_adc_offset0 = value & 0xff;
  return;
}