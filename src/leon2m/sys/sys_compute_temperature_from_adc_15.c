/* sys_compute_temperature_from_adc_15  (FUN_a00da65c)
 *
 * Compute a temperature value with a fixed formula from ADC channel 15, which always reads 0xFF.
 * Returns: 3400.65 / log(r / 0.000112) - 273.15
 * Note: v = x * 3.3 / 255; r = (33 - 10 v) / v. Nothing calls it.
 * Name basis: descriptive - formula on the result of gpio_read_adc_channel_15 (always 0xFF); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da65c @ 0xa00da65c-0xa00da714 (46 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the arithmetic mixes float and double as written below and runs through the soft-float routines
 * (__floatsidf, __muldf3, __divdf3, __truncdfsf2, __mulsf3, __subsf3, __divsf3, __extendsfdf2, log, __subdf3,
 * __fixunssfsi). The result is truncated to an unsigned char.
 */
extern unsigned char gpio_read_adc_channel_15(void);
extern double log(double);

/*
 * Compute a temperature in degrees from the byte x that gpio_read_adc_channel_15 returns (always 0xFF):
 *   v = x * 3.3 / 255;  r = (33 - 10 * v) / v;  t = 3400.65 / log(r / 0.000112) - 273.15.
 * The result is returned as an unsigned char. Nothing calls this routine.
 */
unsigned char sys_compute_temperature_from_adc_15(void)
{
    float v = gpio_read_adc_channel_15() * 3.3 / 255.0;
    float r = (33.0f - v * 10.0f) / v;
    float t = 3400.65 / log(r / 0.000112) - 273.15;

    return t;
}
