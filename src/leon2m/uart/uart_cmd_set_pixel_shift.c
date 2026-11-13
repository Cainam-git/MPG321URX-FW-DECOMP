/* uart_cmd_set_pixel_shift  (FUN_a00ca380)
 *
 * Set the Pixel Shift speed from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00;00; digit 0..2; returns 0xFF for a bad value (the task then replies 5600-), else 0 after
 *   '5600+'.
 * Name basis: proven - set frame 5b00;00; settings byte +0x1DD (osd_accept_pixel_shift_speed)
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the digit is an unsigned short (value - '0'), tested as unsigned char; the parameter is an int
 * masked with 0xff in its first statement.
 */
#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */

extern unsigned char uart_cmd_rx_units_digit_port2;
extern unsigned char uart_cmd_rx_units_digit_port3;
extern unsigned char uart_cmd_rx_units_digit;
extern unsigned char user_settings_pixel_shift;
extern void oled_user_apply_pixel_shift_speed(void);
extern void osd_mark_settings_changed_copy(void);
extern int uart_cmd_build_ok_reply();
extern int uart_cmd_clear_rx();
extern int uart_cmd_send_tx_buffer();

/*
 * Set command 00;00 (set row 0x73): the Pixel Shift speed (settings byte +0x1DD), 0..2. It is applied at once
 * (oled_user_apply_pixel_shift_speed) and a settings save is requested. The value is the character in byte 9 of
 * the port's receive record (port 2 and port 3 have their own records, every other port uses the third).
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is above 2. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_pixel_shift(int port)
{
    unsigned char value_char;
    unsigned short value;
    
    port = port & 0xff;
    if (port == 2) {
        value_char = uart_cmd_rx_units_digit_port2;
    } else if (port == 3) {
        value_char = uart_cmd_rx_units_digit_port3;
    } else {
        value_char = uart_cmd_rx_units_digit;
    }
    
    value = value_char - 0x30;
    if ((unsigned char)value > 2) {
        return UART_CMD_REFUSED;
    }
    
    user_settings_pixel_shift = value;
    oled_user_apply_pixel_shift_speed();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
