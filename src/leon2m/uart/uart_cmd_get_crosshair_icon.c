/* uart_cmd_get_crosshair_icon  (FUN_a00bcd9c)
 *
 * Report the Smart Crosshair icon to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800270 (row 0x1e).
 * Name basis: proven - get frame 5800270; settings byte +0x190 (osd_open_crosshair_icon)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bcd9c, flags -mcpu=v8 -O3 -g.
 * Source form: the builder and uart_cmd_clear_rx are declared without parameter lists (so no argument is converted);
 * the port is passed on to both without change.
 */
extern unsigned char user_settings_crosshair_icon;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern int uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800270" (row 0x1e of uart_cmd_get_rows): the Smart Crosshair icon (user settings byte +0x190), as '0', '0' and the value plus '0'.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_crosshair_icon(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (user_settings_crosshair_icon + '0');
    (void)uart_cmd_build_get_reply(0x1e);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
