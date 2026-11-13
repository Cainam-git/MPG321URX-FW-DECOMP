/* gpio_init_adc_and_pin_groups  (FUN_a00dd904)
 *
 * Set up the analogue key measurement and the two pin group registers.
 * Name basis: descriptive - 0xCF03CF00..0C, bits of the argument into 0xCF03C02C and 0xCF03C200; called from
 *   startup_init_pins
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd904 @ 0xa00dd904, flags -mcpu=v8 -O3 -g.
 * Source form: one 'if' per bit of the argument, in ascending order; the first seven tests use the masked copy
 * `bits`, the last one (0x80) tests the parameter itself.
 */

/* Measurement block registers written at start-up. */
#define ADC_REG_CF00 (*(volatile unsigned int *)0xcf03cf00)
#define ADC_REG_CF04 (*(volatile unsigned int *)0xcf03cf04)
#define ADC_REG_CF08 (*(volatile unsigned int *)0xcf03cf08)
#define ADC_REG_CF0C (*(volatile unsigned int *)0xcf03cf0c)
/* Pin group registers: bits 0..3 of pin_bits go to the first, bits 4..7 to bits 0..3 of the second. */
#define PIN_GROUP_A_REG (*(volatile unsigned int *)0xcf03c02c)
#define PIN_GROUP_B_REG (*(volatile unsigned int *)0xcf03c200)

/*
 * Write the start values of the measurement block (registers 0xCF03CF00..0C; register 0xCF03CF04 gets 0x1b,
 * then 0x19, then 0x1b again at the end) and set the pin group bits that pin_bits selects. Bits are only ever
 * set here, never cleared.
 *
 *   pin_bits  bits 0..3: bits to set in 0xCF03C02C; bits 4..7: bits 0..3 to set in 0xCF03C200
 *
 * Called from startup_init_pins with 0x70.
 */
void gpio_init_adc_and_pin_groups(unsigned char pin_bits)
{
    unsigned int bits;
    
    ADC_REG_CF00 = 0;
    ADC_REG_CF04 = 0x1b;
    ADC_REG_CF08 = 0x80;
    
    bits = pin_bits & 0xff;
    
    ADC_REG_CF0C = 1;
    
    if (bits & 1) PIN_GROUP_A_REG |= 1;
    if (bits & 2) PIN_GROUP_A_REG |= 2;
    if (bits & 4) PIN_GROUP_A_REG |= 4;
    if (bits & 8) PIN_GROUP_A_REG |= 8;
    if (bits & 0x10) PIN_GROUP_B_REG |= 1;
    if (bits & 0x20) PIN_GROUP_B_REG |= 2;
    if (bits & 0x40) PIN_GROUP_B_REG |= 4;
    if (pin_bits & 0x80) PIN_GROUP_B_REG |= 8;
    
    ADC_REG_CF04 = 0x19;
    ADC_REG_CF04 = 0x1b;
}
