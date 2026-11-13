/* uart_cmd_build_ok_reply_port2  (FUN_a00bb4e8)
 *
 * Put the '5600+' acknowledge into the port 2 reply frame.
 * Note: Unused standalone copy.
 * Name basis: derived - frame '5600+\r' in 0xA802D128
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb4e8, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char uart_cmd_tx_frame_port2[];

/* Put the acknowledge "5600+\r" into the reply frame of port 2. Nothing is sent. Not called. */
void uart_cmd_build_ok_reply_port2(void)
{
    uart_cmd_tx_frame_port2[0] = '5';
    uart_cmd_tx_frame_port2[1] = '6';
    uart_cmd_tx_frame_port2[2] = '0';
    uart_cmd_tx_frame_port2[3] = '0';
    uart_cmd_tx_frame_port2[4] = '+';
    uart_cmd_tx_frame_port2[5] = '\r';
}
