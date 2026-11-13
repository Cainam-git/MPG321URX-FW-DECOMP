/* uart_cmd_send_tx_buffer  (FUN_a00bab80)
 *
 * Send the first bytes of a port's transmit buffer.
 *   port: command port
 *   length: byte count
 * Name basis: derived - uart_api_send_bytes with the port's reply frame
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bab80, flags -mcpu=v8 -O3 -g.
 * All three calls to uart_api_send_bytes are tail calls.
 */
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Send the first `length` bytes of the port's reply frame (port 2 and port 3 have their own frame; every other
   port uses uart_cmd_tx_frame). */
void uart_cmd_send_tx_buffer(unsigned char port, unsigned char length)
{
    if (port == 2)
        uart_api_send_bytes(2, length, uart_cmd_tx_frame_port2);
    else if (port == 3)
        uart_api_send_bytes(3, length, uart_cmd_tx_frame_port3);
    else
        uart_api_send_bytes(port, length, uart_cmd_tx_frame);
}
