/* uart_cmd_get_version_code  (FUN_a00bdb88)
 *
 * Report the fixed version text 'V23' for command 5800150 to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get (row 0x30).
 * Name basis: descriptive - reply digits 'V23'; differs from the firmware version '021' of command 58001<0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bdb88, flags -mcpu=v8 -O3 -g.
 * Source form: the parameter is an unsigned char (the compiler narrows it on entry).
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern int uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800150" (row 0x30 of uart_cmd_get_rows) with the fixed text "V23" in the three value
 * bytes. No setting is read.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_version_code(unsigned char port)
{
    uart_cmd_tx_frame[7] = 'V';
    uart_cmd_tx_frame[8] = '2';
    uart_cmd_tx_frame[9] = '3';
    (void)uart_cmd_build_get_reply(0x30);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
