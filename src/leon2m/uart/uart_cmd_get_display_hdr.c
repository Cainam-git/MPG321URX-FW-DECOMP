/* uart_cmd_get_display_hdr  (FUN_a00be250)
 *
 * Report the DisplayHDR setting to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 58004:0 (row 0x6a).
 * Name basis: proven - get frame 58004:0; bits 18..19 of +0xAC (osd_enter_display_hdr_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00be250, flags -mcpu=v8 -O3 -g.
 */
/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad[0xac];
    unsigned int settings_page_flags;           /* +0xAC: bits 18..19 = the display HDR setting */
};
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "58004:0" (row 0x6a of uart_cmd_get_rows) with the two-bit field in bits 18..19 of the
 * settings page flags (user settings word +0xAC). The value 0..3 goes out as the characters '0', '0' and the field
 * plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_display_hdr(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = ((user_settings.settings_page_flags >> 18) & 3) + VALUE_CHAR_BASE;
    uart_cmd_build_get_reply(0x6a);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
