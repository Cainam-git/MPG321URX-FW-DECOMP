/* UserSetAuroraLEDBarBrightness  (FUN_a00da754)
 *
 * Send the brightness of the LED light bar to its controller.
 * Name basis: proven - prints 'UserSetAuroraLEDBarBrightness %d' (original name); text command over the serial
 *   link
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da754 @ 0xa00da754-0xa00da840 (59 words), flags -mcpu=v8 -O3 -g.
 * Source form: the digits are computed into unsigned char locals of one inner block before the stores (as in
 * UartSetI2CEnable).
 */
extern unsigned char sys_led_bar_tx_frame[11];
extern int dbg_printf(const char *fmt, ...);
extern void uart_api_send_bytes(unsigned char port, unsigned short length, unsigned char *data);
extern void ipc_8051_tx_queue_flush(void);

/*
 * Send a brightness command to the LED light bar: value = level * 20 + 20 is printed and sent as the 11
 * characters "5b00740" + three decimal digits of value + carriage return, built in sys_led_bar_tx_frame and
 * sent with uart_api_send_bytes(2, ...). ipc_8051_tx_queue_flush() follows.
 */
void UserSetAuroraLEDBarBrightness(unsigned char level)
{
    unsigned char value = level * 20 + 20;

    dbg_printf("UserSetAuroraLEDBarBrightness %d\r\n", value);
    {
        unsigned char hundreds, rest, tens, ones;
        hundreds = value / 100;
        rest = value - hundreds * 100;
        tens = rest / 10;
        ones = rest - tens * 10;
        sys_led_bar_tx_frame[0] = '5';
        sys_led_bar_tx_frame[1] = 'b';
        sys_led_bar_tx_frame[2] = '0';
        sys_led_bar_tx_frame[3] = '0';
        sys_led_bar_tx_frame[4] = '7';
        sys_led_bar_tx_frame[5] = '4';
        sys_led_bar_tx_frame[6] = '0';
        sys_led_bar_tx_frame[7] = hundreds + '0';
        sys_led_bar_tx_frame[8] = tens + '0';
        sys_led_bar_tx_frame[9] = ones + '0';
        sys_led_bar_tx_frame[10] = '\r';
    }
    uart_api_send_bytes(2, 11, sys_led_bar_tx_frame);
    ipc_8051_tx_queue_flush();
}
