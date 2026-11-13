/* uart_cmd_clear_rx_port2  (FUN_a00bb414)
 *
 * Clear the receive state byte and the whole receive record of command port 2.
 * Note: Unused standalone copy.
 * Name basis: derived - 0xA802B09A and the 0x32 bytes at 0xA802D040
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb414, flags -mcpu=v8 -O2 -g.
 * Source form: an unsigned char loop counter.
 */
extern unsigned char uart_cmd_rx_state_port2;
extern unsigned char uart_cmd_rx_record_port2[];

#define RX_RECORD_SIZE 0x32     /* bytes in a receive record */

/* Clear the receive state byte and the whole receive record of command port 2. Not called; uart_cmd_poll_port2
   has the same clear in its code. */
void uart_cmd_clear_rx_port2(void)
{
    unsigned char i;

    uart_cmd_rx_state_port2 = 0;
    for (i = 0; i < RX_RECORD_SIZE; i++)
        uart_cmd_rx_record_port2[i] = 0;
}
