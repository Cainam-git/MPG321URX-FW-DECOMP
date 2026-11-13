/* uart_cmd_accept_code440  (FUN_a00c0ff4)
 *
 * Acknowledge command 5b00440 when its value is 0 or 1, storing nothing.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF
 * Note: Returns 0xFF for other values.
 * Name basis: descriptive - set row 0x16; the digit is checked but not stored
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: one exit with the result held in a variable (as in uart_cmd_set_alarm_slot); the digit is an
 * unsigned short, tested as unsigned char.
 */
#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */
#define VALUE_CHAR_BASE          0x30   /* a one-digit value arrives as the character '0' + value */

extern unsigned char uart_cmd_rx_units_digit_port2, uart_cmd_rx_units_digit_port3, uart_cmd_rx_units_digit;
extern void osd_mark_settings_changed_copy(void);
extern void uart_cmd_build_ok_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_tx_buffer(unsigned char, int);

/*
 * Set command 00440 (set row 0x16): accepts the value 0 or 1 and stores nothing; only a settings save is
 * requested (osd_mark_settings_changed_copy). The value is the character in byte 9 of the port's receive record
 * (port 2 and port 3 have their own records, every other port uses the third).
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED for any other value. The same code is inlined in
 * uart_cmd_dispatch_set.
 */
int uart_cmd_accept_code440(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;
    int result;

    if (port == 2)
        value_char = uart_cmd_rx_units_digit_port2;
    else if (port == 3)
        value_char = uart_cmd_rx_units_digit_port3;
    else
        value_char = uart_cmd_rx_units_digit;
    value = value_char - VALUE_CHAR_BASE;
    result = UART_CMD_REFUSED;
    if ((unsigned char)value <= 1) {
        osd_mark_settings_changed_copy();
        uart_cmd_build_ok_reply(port);
        uart_cmd_clear_rx(port);
        uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
        result = 0;
    }
    return result;
}
