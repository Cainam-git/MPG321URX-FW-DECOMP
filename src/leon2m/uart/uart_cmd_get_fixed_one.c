/* uart_cmd_get_fixed_one  (FUN_a00bc914)
 *
 * Report the fixed value 001 for command 5800415 to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get (row 0x0f).
 * Name basis: descriptive - reply digits '001'; nothing else is read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bc914, flags -mcpu=v8 -O3 -g.
 * Source form: the head builder (the copy) is declared with an unsigned char parameter, uart_cmd_clear_rx without a
 * parameter list (result dropped); the port is masked to a byte (the parameter is an unsigned int) before it is
 * passed on.
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply_copy(unsigned char);
extern int uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800415" (row 0x0f of uart_cmd_get_rows): the fixed characters "001"; nothing is read from the settings.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_fixed_one(unsigned int port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = '1';
    uart_cmd_build_get_reply_copy(0xf);
    port &= 0xff;
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
