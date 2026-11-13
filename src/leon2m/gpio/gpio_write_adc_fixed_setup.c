/* gpio_write_adc_fixed_setup  (FUN_a00dda4c)
 *
 * Write the fixed values of the analogue measurement block.
 * Name basis: descriptive - registers 0xCF03CF40..0xCF03CF6C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dda4c @ 0xa00dda4c-0xa00ddac4, 120 bytes, leaf, flags -mcpu=v8 -O3 -g.
 * Source form: eleven volatile word stores in the order below; register 0xCF03CF44 is written three times.
 */

/* Measurement block registers written here (the registers 0xCF03CF00..0C are set by gpio_init_adc_and_pin_groups). */
#define ADC_REG_CF40 (*(volatile unsigned int *)0xcf03cf40)
#define ADC_REG_CF44 (*(volatile unsigned int *)0xcf03cf44)
#define ADC_REG_CF48 (*(volatile unsigned int *)0xcf03cf48)
#define ADC_REG_CF4C (*(volatile unsigned int *)0xcf03cf4c)
#define ADC_REG_CF5C (*(volatile unsigned int *)0xcf03cf5c)
#define ADC_REG_CF60 (*(volatile unsigned int *)0xcf03cf60)
#define ADC_REG_CF64 (*(volatile unsigned int *)0xcf03cf64)
#define ADC_REG_CF68 (*(volatile unsigned int *)0xcf03cf68)
#define ADC_REG_CF6C (*(volatile unsigned int *)0xcf03cf6c)

/*
 * Write fixed values to the measurement block registers 0xCF03CF40..4C and 0xCF03CF5C..6C: register 0xCF03CF44
 * gets 0x1b, then 0x19, then 0x1b again, the registers CF5C..CF68 get 0xff and CF6C gets 0xf.
 * Nothing in the image calls this routine or stores its address.
 */
void gpio_write_adc_fixed_setup(void)
{
    ADC_REG_CF40 = 0x10;
    ADC_REG_CF44 = 0x1b;
    ADC_REG_CF48 = 2;
    ADC_REG_CF4C = 1;
    ADC_REG_CF44 = 0x19;
    ADC_REG_CF44 = 0x1b;
    ADC_REG_CF5C = 0xff;
    ADC_REG_CF60 = 0xff;
    ADC_REG_CF64 = 0xff;
    ADC_REG_CF68 = 0xff;
    ADC_REG_CF6C = 0xf;
}
