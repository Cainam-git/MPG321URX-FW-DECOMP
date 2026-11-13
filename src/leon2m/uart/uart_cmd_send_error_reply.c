/* uart_cmd_send_error_reply  (FUN_a00baa20)
 *
 * Send the '5600-' reply (command refused) on a command port.
 *   port
 * Note: Unused standalone copy.
 * Name basis: derived - frame '5600-\r'; the command task replies '-' when a handler returns 0xFF
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00baa20, flags -mcpu=v8 -O3 -g.
 * The call to uart_api_send_bytes is a tail call.
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Send the reply "5600-\r" (command refused) from the shared reply frame on `port`. Not called; the command
   tasks build the same reply themselves. */
void uart_cmd_send_error_reply(unsigned char port)
{
    uart_cmd_tx_frame[0] = '5';
    uart_cmd_tx_frame[1] = '6';
    uart_cmd_tx_frame[2] = '0';
    uart_cmd_tx_frame[3] = '0';
    uart_cmd_tx_frame[4] = '-';
    uart_cmd_tx_frame[5] = '\r';
    uart_api_send_bytes(port, 6, uart_cmd_tx_frame);
}
