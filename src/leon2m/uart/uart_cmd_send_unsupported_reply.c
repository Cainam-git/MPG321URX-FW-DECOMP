/* uart_cmd_send_unsupported_reply  (FUN_a00ba9d8)
 *
 * Send the '56006' reply (command not supported) on a command port.
 *   port
 * Note: Unused standalone copy; the port 2 task sends the same reply for an unknown command.
 * Name basis: derived - frame '56006\r'; uart_cmd_poll_port2 sends '6' when no command row matches
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ba9d8, flags -mcpu=v8 -O3 -g.
 * The call to uart_api_send_bytes is a tail call.
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Send the reply "56006\r" (command not supported) from the shared reply frame on `port`. Not called; the
   command tasks build the same reply themselves. */
void uart_cmd_send_unsupported_reply(unsigned char port)
{
    uart_cmd_tx_frame[0] = '5';
    uart_cmd_tx_frame[1] = '6';
    uart_cmd_tx_frame[2] = '0';
    uart_cmd_tx_frame[3] = '0';
    uart_cmd_tx_frame[4] = '6';
    uart_cmd_tx_frame[5] = '\r';
    uart_api_send_bytes(port, 6, uart_cmd_tx_frame);
}
