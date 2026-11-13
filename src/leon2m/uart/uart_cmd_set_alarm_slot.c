/* uart_cmd_set_alarm_slot  (FUN_a00c0c74)
 *
 * Set the selected alarm clock timer slot from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00261; digit 0..4 into byte 0xA802CFFD; returns 0xFF for a bad value (the task then replies
 *   5600-), else 0 after '5600+'.
 * Name basis: derived - set frame 5b00261; byte 0xA802CFFD, index used by the alarm time command
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: digit is an int with an unsigned char test (the firmware keeps the unsigned char value re-extended
 * with 'and 0xff' and stores the unmasked digit); a single return, the result held in a variable.
 */
extern unsigned char uart_cmd_rx_units_digit_port2, uart_cmd_rx_units_digit_port3, uart_cmd_rx_units_digit;
extern unsigned char uart_cmd_alarm_slot_index;
extern void uart_cmd_build_ok_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_tx_buffer(unsigned char, int);

#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */
#define VALUE_CHAR_BASE          0x30   /* a one-digit value arrives as the character '0' + value */
#define ALARM_SLOT_MAX           4      /* alarm timer slots 0..4 */

/*
 * Set command 00261 (set row 0x33): choose which alarm timer slot (0..4) the get command 00262 reports the
 * time of. The slot number is the value character of the frame (byte 9 of the port's receive record; port 2 and
 * port 3 have their own records, every other port uses the third).
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is above 4. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_alarm_slot(unsigned char port)
{
    unsigned char value_char;
    int slot;
    int result;

    if (port == 2)
        value_char = uart_cmd_rx_units_digit_port2;
    else if (port == 3)
        value_char = uart_cmd_rx_units_digit_port3;
    else
        value_char = uart_cmd_rx_units_digit;
    slot = value_char - VALUE_CHAR_BASE;
    result = UART_CMD_REFUSED;
    if ((unsigned char)slot <= ALARM_SLOT_MAX) {
        uart_cmd_alarm_slot_index = slot;
        uart_cmd_build_ok_reply(port);
        uart_cmd_clear_rx(port);
        uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
        result = 0;
    }
    return result;
}
