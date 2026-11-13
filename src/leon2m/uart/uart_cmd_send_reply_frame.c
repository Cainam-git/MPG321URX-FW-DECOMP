/* uart_cmd_send_reply_frame  (FUN_a00babe4)
 *
 * Send the shared reply frame on a command port.
 *   port: command port
 *   length: byte count
 * Note: Frame buffer 0xA802D078.
 * Name basis: derived - uart_api_send_bytes(port, len, uart_cmd_tx_frame) with the shared reply frame
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00babe4, flags -mcpu=v8 -O2 -g.
 * The call is a tail call. Both parameters are unsigned char (masked with 0xff before the call);
 * uart_api_send_bytes takes the length as an unsigned short.
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Send the first `length` bytes of the shared reply frame uart_cmd_tx_frame on `port`. Used by the get replies. */
void uart_cmd_send_reply_frame(unsigned char port, unsigned char length)
{
    uart_api_send_bytes(port, length, uart_cmd_tx_frame);
}
