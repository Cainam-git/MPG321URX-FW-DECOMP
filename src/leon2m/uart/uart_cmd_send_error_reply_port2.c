/* uart_cmd_send_error_reply_port2  (FUN_a00bb49c)
 *
 * Send the '5600-' reply (command refused) from the port 2 reply frame on the given port.
 *   port
 * Note: Unused standalone copy.
 * Name basis: derived - frame '5600-\r' in 0xA802D128
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb49c, flags -mcpu=v8 -O3 -g.
 * The call to uart_api_send_bytes is a tail call.
 */
extern unsigned char uart_cmd_tx_frame_port2[];
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Send the reply "5600-\r" (command refused) from the reply frame of port 2 on `port`. Not called. */
void uart_cmd_send_error_reply_port2(unsigned char port)
{
    uart_cmd_tx_frame_port2[0] = '5';
    uart_cmd_tx_frame_port2[1] = '6';
    uart_cmd_tx_frame_port2[2] = '0';
    uart_cmd_tx_frame_port2[3] = '0';
    uart_cmd_tx_frame_port2[4] = '-';
    uart_cmd_tx_frame_port2[5] = '\r';
    uart_api_send_bytes(port, 6, uart_cmd_tx_frame_port2);
}
