/* uart_cmd_get_blur_free  (FUN_a00bcb38)
 *
 * Report the blur reduction mode to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800230 (row 0x16).
 * Name basis: derived - get frame 5800230; settings word +0xB0, kept by APPBlurFree_AfterMute
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bcb38, flags -mcpu=v8 -O3 -g.
 * Source form: the blur reduction mode is read as an unsigned int (settings word +0xB0), the head builder and
 * uart_cmd_clear_rx take an unsigned char.
 */
extern unsigned char uart_cmd_tx_frame[];
extern unsigned int user_settings_blur_free_mode;
extern void uart_cmd_build_get_reply(unsigned char row);
extern void uart_cmd_clear_rx(unsigned char port);
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800230" (row 0x16 of uart_cmd_get_rows): the blur reduction mode (user settings word +0xB0), as '0', '0' and the value plus '0'.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_blur_free(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = user_settings_blur_free_mode + '0';
    uart_cmd_build_get_reply(0x16);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
