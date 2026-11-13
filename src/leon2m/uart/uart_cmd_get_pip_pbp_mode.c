/* uart_cmd_get_pip_pbp_mode  (FUN_a00bdbcc)
 *
 * Report the PIP/PBP mode to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800600 (row 0x33).
 * Name basis: proven - get frame 5800600; settings byte +0x1F (osd_enter_pip_pbp_items)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bdbcc, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char user_settings_pip_pbp_mode;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern int uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "5800600" (row 0x33 of uart_cmd_get_rows) with the PIP/PBP mode (user settings byte
 * +0x1F; 0 off, 1 PIP, 2 PBP). The value goes out as the characters '0', '0' and the value plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_pip_pbp_mode(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (user_settings_pip_pbp_mode + VALUE_CHAR_BASE);
    (void)uart_cmd_build_get_reply(0x33);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
