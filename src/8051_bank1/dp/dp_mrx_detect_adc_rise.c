/* dp_mrx_detect_adc_rise  (FUN_CODE_a6cf)
 *
 * Report a rise of a DP port's analog sense level above its lowest reading.
 *   port: DP port 0/1
 * Returns: 1 on a rise
 * Name basis: derived - ADC channel from 0xA755/0xA756 by port (gpio_read_adc); minimum kept at 0xA751; rise >
 *   0x50; callers wake kinds 7..10 (mrx wake up)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a6cf @ 0xa6cf (166 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameter port at XDATA 0xA476, local level at 0xA477.
 * Source form: the result is the bit power_wake_entry_option_flag (BITS_20_1), cleared first and returned in the
 *   carry; the difference test is cast to unsigned char (8-bit subtraction).
 */
extern unsigned char xdata dp_mrx_adc_min_levels[2], dp_mrx_adc_sample_counts[2];
extern unsigned char xdata dp_mrx_adc_channel_port0, dp_mrx_adc_channel_port1;
extern bit power_wake_entry_option_flag;
extern unsigned char gpio_read_adc(unsigned char channel);

#define DP_PORT0           0
#define BASE_READINGS      2      /* readings that only set the base level */
#define ADC_RISE_MIN       0x50   /* a rise above the base by more than this counts */

/*
 * dp_mrx_detect_adc_rise - read the analog sense input of DP port 0 or 1 and return 1 when it has risen by more
 * than ADC_RISE_MIN above the lowest reading so far.
 *   port  0 or 1 (any other value is taken as 0)
 * power_init_wake_detection sets the ADC channel of each port (dp_mrx_adc_channel_port0/1) and clears the
 * reading counts. The first two readings are stored as the base level; after that a lower reading becomes the
 * new base.
 * Caller: power_check_wake_entry, for wake-up table entries of kinds 7 and 8 (port 0) and 9 and 10 (port 1).
 */
bit dp_mrx_detect_adc_rise(unsigned char port)
{
    unsigned char level;
    power_wake_entry_option_flag = 0;
    if (port > 1) port = DP_PORT0;
    if (port == DP_PORT0) level = gpio_read_adc(dp_mrx_adc_channel_port0); else level = gpio_read_adc(dp_mrx_adc_channel_port1);
    if (dp_mrx_adc_sample_counts[port] < BASE_READINGS) {
        dp_mrx_adc_min_levels[port] = level;
        dp_mrx_adc_sample_counts[port]++;
    } else if (level < dp_mrx_adc_min_levels[port]) {
        dp_mrx_adc_min_levels[port] = level;
    } else if (level > dp_mrx_adc_min_levels[port] && (unsigned char)(level - dp_mrx_adc_min_levels[port]) > ADC_RISE_MIN) {
        power_wake_entry_option_flag = 1;
    }
    return power_wake_entry_option_flag;
}
