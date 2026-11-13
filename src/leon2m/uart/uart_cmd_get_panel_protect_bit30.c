/* uart_cmd_get_panel_protect_bit30  (FUN_a00be470)
 *
 * Report the Panel Protect request bit 30 to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800;11 (row 0x72).
 * Name basis: descriptive - get frame 5800;11; bit 30 of +0x1DC; set stores +0x1E5 = 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00be470, flags -mcpu=v8 -O3 -g.
 */
extern unsigned int user_settings_oled_care_flags;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern unsigned char uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "5800;11" (row 0x72 of uart_cmd_get_rows) with Panel Protect request: bit 30 of the OLED
 * care flags (user settings word +0x1DC). The value goes out as the characters '0', '0' and the bit plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_panel_protect_bit30(unsigned char port)
{
    unsigned int bit;

    bit = (user_settings_oled_care_flags >> 0x1e) & 1;
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
    (void)uart_cmd_build_get_reply(0x72);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
