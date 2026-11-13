/* gpio_read_adc_channel_15  (FUN_a0125c54)
 *
 * Ask gpio_read_adc_channel for channel 0x0F, which it does not serve: the result is always 0xFF.
 * Returns: 0xFF
 * Note: The key scan reads channels 6 and 5, not this one; its one caller turns the result into a temperature
 *   value.
 * Name basis: descriptive - gpio_read_adc_channel(0x0F); that routine has cases 1..10 and answers 0xFF for
 *   every other channel
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125c54 @ 0xa0125c54, flags -mcpu=v8 -O2 -g.
 * The constant 0x0F is also stored in a local first, as the decompiler had it; neither parameter is used.
 */
extern int gpio_read_adc_channel();

#define ADC_CHANNEL_KEYS 0xf        /* the channel the key scan reads */

/*
 * Return the low byte of analogue measurement channel 0x0F. Neither parameter is used.
 */
unsigned char gpio_read_adc_channel_15(unsigned int unused_1, unsigned int unused_2)
{
    unsigned int channel;

    channel = ADC_CHANNEL_KEYS;
    return gpio_read_adc_channel(ADC_CHANNEL_KEYS);
}
