/* uart_cmd_get_color_gains  (FUN_a00bc86c)
 *
 * Report the custom red, green and blue gains to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800434 (row 0x0a).
 * Name basis: proven - get frame 5800434; settings bytes +0x12..+0x14 together
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bc86c, flags -mcpu=v8 -O3 -g.
 * Source form: the record bases are the symbols user_settings and uart_cmd_tx_frame; the stores are written in
 * ascending order 7, 8, 9 (the scheduler emits them 9, 7, 8, as in the firmware).
 */
/* The bytes of the user settings record that this routine reads. */
struct user_settings_view {
    unsigned char pad[0x12];
    unsigned char red_gain;             /* +0x12: the custom gains */
    unsigned char green_gain;           /* +0x13 */
    unsigned char blue_gain;            /* +0x14 */
};
extern struct user_settings_view user_settings;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply_copy(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800434" (row 0x0a of uart_cmd_get_rows): the custom red, green and blue gains (user settings bytes +0x12, +0x13, +0x14), one character each: the value plus '0'.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_color_gains(unsigned char port)
{
    uart_cmd_tx_frame[7] = user_settings.red_gain + '0';
    uart_cmd_tx_frame[8] = user_settings.green_gain + '0';
    uart_cmd_tx_frame[9] = user_settings.blue_gain + '0';
    uart_cmd_build_get_reply_copy(10);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
