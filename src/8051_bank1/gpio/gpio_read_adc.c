/* gpio_read_adc  (FUN_CODE_aeb2)
 *
 * Return the reading of one numbered analog input.
 *   channel: channel 1..12
 * Returns: reading, 0xFF for other n
 * Name basis: derived - channels 1..12 = 0xF3C5.., 0xF5D5/6; used by the ADC key scan ('ADC key') and the CC
 *   line checks
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_aeb2, OPTIMIZE(8,SPEED) LARGE. Keil switch with a 3-byte LJMP table; every case and the default
 * leave through one shared tail.
 */
extern unsigned char xdata reg_adc_ch1_value;
extern unsigned char xdata reg_adc_ch2_value;
extern unsigned char xdata reg_adc_ch3_value;
extern unsigned char xdata reg_adc_ch4_value;
extern unsigned char xdata reg_adc_ch5_value;
extern unsigned char xdata reg_adc_ch6_value;
extern unsigned char xdata reg_adc_ch7_value;
extern unsigned char xdata reg_adc_ch8_value;
extern unsigned char xdata reg_adc_ch9_value;
extern unsigned char xdata reg_adc_ch10_value;
extern unsigned char xdata reg_adc_ch11_value;
extern unsigned char xdata reg_adc_ch12_value;
/*
 * gpio_read_adc - return the byte in the result register of analog input n (1..12: XDATA 0xF3C5..0xF3CC, 0xF3D5,
 * 0xF3D6, 0xF5D5, 0xF5D6). Any other n returns 0xFF.
 */
unsigned char gpio_read_adc(unsigned char channel)
{
    unsigned char reading;
    switch (channel) {
    case 1: reading = reg_adc_ch1_value; break;
    case 2: reading = reg_adc_ch2_value; break;
    case 3: reading = reg_adc_ch3_value; break;
    case 4: reading = reg_adc_ch4_value; break;
    case 5: reading = reg_adc_ch5_value; break;
    case 6: reading = reg_adc_ch6_value; break;
    case 7: reading = reg_adc_ch7_value; break;
    case 8: reading = reg_adc_ch8_value; break;
    case 9: reading = reg_adc_ch9_value; break;
    case 10: reading = reg_adc_ch10_value; break;
    case 11: reading = reg_adc_ch11_value; break;
    case 12: reading = reg_adc_ch12_value; break;
    default: reading = 0xff; break;
    }
    return reading;
}
