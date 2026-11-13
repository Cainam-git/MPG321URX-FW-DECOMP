/* dp_mrx_test_adc_level  (FUN_CODE_c8cd)
 *
 * Report whether a DP port's ADC level is above 0xA0 and its ADC channel number is 0x0C or less.
 *   dp_port: DP port 0 or 1 (a higher number counts as 0)
 * Returns: 1 when both hold, else 0
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - ADC channel 0xA755/0xA756 via gpio_read_adc, value kept at 0xA77E; level > 0xA0
 *   and channel <= 0x0C
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c8cd @ 0xC8CD..0xC919 (76 bytes)  Byte-exact with OPTIMIZE(8,SPEED) (no register file).
 * Source form: the result is a local bit returned in the carry; the build was not exact when that local was
 * renamed ('b' = 1 means the level is high).
 */
extern unsigned char xdata dp_mrx_adc_channel_port0, dp_mrx_adc_channel_port1, dp_mrx_adc_level;
extern unsigned char gpio_read_adc(unsigned char channel);

/*
 * Read the analog level of the ADC channel stored for DP port 0 or 1 into
 * dp_mrx_adc_level. Returns 1 when the level is above 0xA0 and the channel
 * number is 0x0C or less, else 0. A port number above 1 is treated as 0.
 * No caller in the bank-1 image.
 */
bit dp_mrx_test_adc_level(unsigned char dp_port)
{
    bit b;
    b = 0;
    if (dp_port > 1) dp_port = 0;
    if (dp_port == 0) {
        dp_mrx_adc_level = gpio_read_adc(dp_mrx_adc_channel_port0);
        if (dp_mrx_adc_level > 0xa0 && dp_mrx_adc_channel_port0 <= 0x0c) b = 1;
    } else {
        dp_mrx_adc_level = gpio_read_adc(dp_mrx_adc_channel_port1);
        if (dp_mrx_adc_level > 0xa0 && dp_mrx_adc_channel_port1 <= 0x0c) b = 1;
    }
    return b;
}
