/* uart_cmd_get_pip_location  (FUN_a00bdc60)
 *
 * Report the PIP location to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800640 (row 0x39).
 * Name basis: proven - get frame 5800640; bits 4..7 of +0x30 (osd_enter_pip_location_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bdc60, flags -mcpu=v8 -O3 -g.
 * Source form: the prototypes of the three callees are declared with the parameter types shown (the firmware sets
 * only one argument for uart_cmd_build_get_reply).
 */
extern unsigned int user_settings_pip_location;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply(unsigned char row);
extern unsigned char uart_cmd_clear_rx(unsigned char port);
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "5800640" (row 0x39 of uart_cmd_get_rows) with the PIP location: bits 4..7 of the user
 * settings word +0x30. The value goes out as the characters '0', '0' and the location plus '0'.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_pip_location(unsigned char port)
{
    unsigned int location;

    location = (user_settings_pip_location >> 4) & 0xf;
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (location + VALUE_CHAR_BASE);
    uart_cmd_build_get_reply(0x39);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
