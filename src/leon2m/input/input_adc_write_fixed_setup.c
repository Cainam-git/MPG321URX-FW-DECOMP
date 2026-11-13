/* input_adc_write_fixed_setup  (FUN_a00f3194)
 *
 * Write two fixed values of the analogue input stage.
 * Name basis: descriptive - 0xE0 to 0xCF0200D4 and into 0xCF020114; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3194 @ 0xa00f3194, flags -mcpu=v8 -O3 -g. A leaf.
 */

/*
 * Write 0xE0 to the word register 0xCF0200D4 and set bits 5..7 (0xE0) of the word register 0xCF020114.
 * No code calls this routine.
 */
void input_adc_write_fixed_setup(void)
{
    *(volatile unsigned int *)0xcf0200d4 = 0xe0;
    *(volatile unsigned int *)0xcf020114 |= 0xe0;
}
