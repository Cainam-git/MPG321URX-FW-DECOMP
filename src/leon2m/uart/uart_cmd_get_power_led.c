/* uart_cmd_get_power_led  (FUN_a00be38c)
 *
 * Report the Power LED switch to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 58008B0 (row 0x6f).
 * Name basis: proven - get frame 58008B0; bit 30 of +0x1F4 (osd_toggle_power_led)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00be38c, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char uart_cmd_tx_frame[];
extern unsigned int user_settings_word_0x1f4;
extern void uart_cmd_build_get_reply(unsigned char row);
extern void uart_cmd_clear_rx(unsigned char port);
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "58008B0" (row 0x6f of uart_cmd_get_rows) with bit 30 of the user settings word +0x1F4.
 * The value goes out as the characters '0', '0' and the bit plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_power_led(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = ((user_settings_word_0x1f4 >> 0x1e) & 1) + VALUE_CHAR_BASE;
    uart_cmd_build_get_reply(0x6f);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
