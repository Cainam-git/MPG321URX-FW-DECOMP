/* gpio_read_adc_channel  (FUN_a00ddae4)
 *
 * Read one of the ten analogue measurement channels.
 * Returns: value or 0xFF
 * Name basis: derived - low byte of 0xCF03CF14..0xCF03CF58; used by the key scan
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ddae4 @ 0xa00ddae4-0xa00ddbe0 (63 words).
 * Source form: cases 1..10 are listed before case 0; the result is an unsigned char local.
 */
/* Result registers of the measurement block. */
#define ADC_RESULT_CF14 (*(volatile unsigned int *)0xcf03cf14)
#define ADC_RESULT_CF18 (*(volatile unsigned int *)0xcf03cf18)
#define ADC_RESULT_CF1C (*(volatile unsigned int *)0xcf03cf1c)
#define ADC_RESULT_CF20 (*(volatile unsigned int *)0xcf03cf20)
#define ADC_RESULT_CF24 (*(volatile unsigned int *)0xcf03cf24)
#define ADC_RESULT_CF28 (*(volatile unsigned int *)0xcf03cf28)
#define ADC_RESULT_CF2C (*(volatile unsigned int *)0xcf03cf2c)
#define ADC_RESULT_CF30 (*(volatile unsigned int *)0xcf03cf30)
#define ADC_RESULT_CF54 (*(volatile unsigned int *)0xcf03cf54)
#define ADC_RESULT_CF58 (*(volatile unsigned int *)0xcf03cf58)

/*
 * Return the low byte of one measurement register.
 *
 *   channel  1..8: registers 0xCF03CF14, 18, .. 30 in steps of 4; 9: 0xCF03CF54; 10: 0xCF03CF58.
 *            Channel 0 and every number above 10 give 0xFF.
 *
 * input_scan_keys reads channels 6 and 5 for the analogue keys.
 */
unsigned char gpio_read_adc_channel(unsigned char channel)
{
    unsigned char value;

    switch (channel) {
    case 1: value = ADC_RESULT_CF14; break;
    case 2: value = ADC_RESULT_CF18; break;
    case 3: value = ADC_RESULT_CF1C; break;
    case 4: value = ADC_RESULT_CF20; break;
    case 5: value = ADC_RESULT_CF24; break;
    case 6: value = ADC_RESULT_CF28; break;
    case 7: value = ADC_RESULT_CF2C; break;
    case 8: value = ADC_RESULT_CF30; break;
    case 9: value = ADC_RESULT_CF54; break;
    case 10: value = ADC_RESULT_CF58; break;
    case 0: value = -1; break;
    default: value = -1; break;
    }
    return value;
}
