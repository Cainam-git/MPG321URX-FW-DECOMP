/* uart_cmd_get_image_enhancement  (FUN_a00bd294)
 *
 * Report the Image Enhancement level to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800340 (row 0x25).
 * Name basis: proven - get frame 5800340; bits of +0x34 (osd_enter_image_enhancement_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bd294, flags -mcpu=v8 -O3 -g.
 * Source form: the low nibble is taken into an unsigned short local first; written inside the byte store, GCC
 * narrows the halfword load to a byte load.
 */
extern unsigned short user_settings_image_enhancement;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "5800340" (row 0x25 of uart_cmd_get_rows) with the Image Enhancement level: bits 0..3 of
 * the user settings halfword +0x34. The value goes out as the characters '0', '0' and the level plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_image_enhancement(unsigned char port)
{
    unsigned short level = user_settings_image_enhancement & 0xf;

    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = level + VALUE_CHAR_BASE;
    uart_cmd_build_get_reply(0x25);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
