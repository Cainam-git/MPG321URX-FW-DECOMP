/* uart_cmd_get_type_c_pd_charge  (FUN_a00be2a0)
 *
 * Report the Type C PD Charge switch to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 58008A0 (row 0x6b).
 * Name basis: proven - get frame 58008A0; bit 7 of +0x1EC (osd_draw_type_c_pd_charge_switch)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00be2a0, flags -mcpu=v8 -O3 -g.
 */
extern unsigned int user_settings_boundary_detection;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern unsigned char uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "58008A0" (row 0x6b of uart_cmd_get_rows) with Type C PD Charge: bit 7 of the word at
 * user settings +0x1EC. The value goes out as the characters '0', '0' and the bit plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_type_c_pd_charge(unsigned char port)
{
    unsigned int bit;

    bit = (user_settings_boundary_detection >> 0x7) & 1;
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
    (void)uart_cmd_build_get_reply(0x6b);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
