/* usb_cc_read_line_levels  (FUN_CODE_c644)
 *
 * Read the analog levels of the USB-C CC lines into the readings.
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - gpio_read_adc channels 9/10 or 11/12 by 0xA6A5 into 0xA672/0xA673
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c644 @ 0xC644..0xC698 (84 bytes)  Byte-exact with OPTIMIZE(8,SPEED) (no register file).
 * Source form: Keil cross-jumps the shared 'usb_cc_line_readings[1] = gpio_read_adc(R7)' tail of the two branches.
 */
extern unsigned char xdata DAT_EXTMEM_a77f, usb_c_port_info, usb_c_port_info_port_select, usb_cc_adc_reading;
extern unsigned char xdata usb_cc_line_readings[2];
extern void sys_empty_function_3(void);
extern void sys_empty_function_4(void);
extern void sys_empty_function_5(void);
extern unsigned char gpio_read_adc(unsigned char channel);

/*
 * Read the analog levels of the two CC lines into usb_cc_line_readings[0]
 * and [1]. Bits 1..0 of the port select byte choose the channel pair: 0 reads
 * channels 9 and 10, 1 reads channels 11 and 12; any other value leaves the
 * readings alone. A third reading (channel = high nibble of usb_c_port_info)
 * goes to usb_cc_adc_reading. No caller in the bank-1 image.
 */
void usb_cc_read_line_levels(void)
{
    DAT_EXTMEM_a77f = 10;
    sys_empty_function_3();
    sys_empty_function_4();
    sys_empty_function_5();
    usb_cc_adc_reading = gpio_read_adc(usb_c_port_info >> 4);
    if ((usb_c_port_info_port_select & 3) == 0) {
        usb_cc_line_readings[0] = gpio_read_adc(9);
        usb_cc_line_readings[1] = gpio_read_adc(10);
    } else if ((usb_c_port_info_port_select & 3) == 1) {
        usb_cc_line_readings[0] = gpio_read_adc(11);
        usb_cc_line_readings[1] = gpio_read_adc(12);
    }
}
