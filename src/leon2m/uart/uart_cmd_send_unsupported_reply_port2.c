/* uart_cmd_send_unsupported_reply_port2  (FUN_a00bb454)
 *
 * Send the '56006' reply (command not supported) from the port 2 reply frame on the given port.
 *   port
 * Note: Unused standalone copy; port 2 has its own frame 0xA802D128.
 * Name basis: derived - frame '56006\r'; uart_cmd_poll_port2 sends it for an unknown command
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb454, flags -mcpu=v8 -O3 -g.
 * The call to uart_api_send_bytes is a tail call.
 */
extern unsigned char uart_cmd_tx_frame_port2[];
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Send the reply "56006\r" (command not supported) from the reply frame of port 2 on `port`. Not called;
   uart_cmd_poll_port2 sends the same reply itself. */
void uart_cmd_send_unsupported_reply_port2(unsigned char port)
{
    uart_cmd_tx_frame_port2[0] = '5';
    uart_cmd_tx_frame_port2[1] = '6';
    uart_cmd_tx_frame_port2[2] = '0';
    uart_cmd_tx_frame_port2[3] = '0';
    uart_cmd_tx_frame_port2[4] = '6';
    uart_cmd_tx_frame_port2[5] = '\r';
    uart_api_send_bytes(port, 6, uart_cmd_tx_frame_port2);
}
