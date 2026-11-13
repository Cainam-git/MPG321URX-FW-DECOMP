/* input_adc_power_down  (FUN_a00f328c)
 *
 * Write the power-down values of the analogue input stage.
 * Name basis: descriptive - five 0xCF02xxxx registers; part of the shut-down sequence
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f328c @ 0xa00f328c, flags -mcpu=v8 -O3 -g.
 */

#define REG32(a) (*(volatile unsigned int *)(a))

/*
 * Write a fixed set of values to the registers at 0xCF0200xx / 0xCF0201xx: 0xCF0200D4 = 0,
 * bits 0xE0 of 0xCF020114 cleared, bits 0x41 of 0xCF0200CC cleared, 0xCF020134 = 0x50 and
 * 0xCF020138 = 0x22. The same values are written by input_adc_configure when it is called with 0.
 * Called by sys_shut_down_blocks.
 */
void input_adc_power_down(void)
{
    REG32(0xcf0200d4) = 0;
    REG32(0xcf020114) &= ~0xe0;
    REG32(0xcf0200cc) &= ~0x41;
    REG32(0xcf020134) = 0x50;
    REG32(0xcf020138) = 0x22;
}
