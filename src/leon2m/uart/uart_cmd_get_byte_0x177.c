/* uart_cmd_get_byte_0x177  (FUN_a00be1c0)
 *
 * Report the settings byte +0x177 to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 58008?0 (row 0x66).
 * Name basis: descriptive - get frame 58008?0; value 0/1; nothing in the menu reads it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00be1c0, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char user_settings_byte_0x177;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern int uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "58008?0" (row 0x66 of uart_cmd_get_rows) with user settings byte +0x177. The value goes
 * out as the characters '0', '0' and the value plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_byte_0x177(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (user_settings_byte_0x177 + VALUE_CHAR_BASE);
    (void)uart_cmd_build_get_reply(0x66);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
