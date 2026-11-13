/* uart_cmd_get_color_temperature  (FUN_a00bc3b0)
 *
 * Report the Color Temperature to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800430 (row 0x06).
 * Name basis: proven - get frame 5800430; settings byte +0x11 (osd_enter_color_temp_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bc3b0, flags -mcpu=v8 -O3 -g.
 * Source form: the head builder (the copy) and uart_cmd_clear_rx are declared with a unsigned char parameter; the reply
 * goes out with uart_api_send_bytes directly (a tail call).
 */
extern unsigned char user_settings_color_temperature;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply_copy(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800430" (row 0x06 of uart_cmd_get_rows): the Color Temperature (user settings byte +0x11), as '0', '0' and the value plus '0'.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_color_temperature(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = user_settings_color_temperature + '0';
    uart_cmd_build_get_reply_copy(6);
    uart_cmd_clear_rx(port);
    uart_api_send_bytes(port, GET_REPLY_LENGTH, uart_cmd_tx_frame);
}
