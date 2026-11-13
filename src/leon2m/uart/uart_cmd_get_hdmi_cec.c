/* uart_cmd_get_hdmi_cec  (FUN_a00be140)
 *
 * Report the HDMI CEC switch to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 58008:0 (row 0x4c).
 * Name basis: proven - get frame 58008:0; bit 20 of +0xAC (osd_toggle_hdmi_cec); reports off while PIP/PBP is
 *   on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00be140, flags -mcpu=v8 -O3 -g.
 */
/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
    unsigned char pad020[0xac - 0x20];
    unsigned int settings_page_flags;           /* +0xAC: bit 20 = HDMI CEC */
};
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "58008:0" (row 0x4c of uart_cmd_get_rows) with the HDMI CEC switch: bit 20 of the
 * settings page flags (user settings word +0xAC). While a PIP or PBP mode is on, the reply value is 0 whatever the
 * bit says. The value goes out as the characters '0', '0' and the bit plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_hdmi_cec(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    if (user_settings.pip_pbp_mode == 0)
        uart_cmd_tx_frame[9] = ((user_settings.settings_page_flags >> 20) & 1) + VALUE_CHAR_BASE;
    else
        uart_cmd_tx_frame[9] = '0';
    uart_cmd_build_get_reply(0x4c);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
