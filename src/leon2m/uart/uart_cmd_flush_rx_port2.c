/* uart_cmd_flush_rx_port2  (FUN_a00bb528)
 *
 * Clear the receive record of command port 2 and report success.
 * Returns: 0
 * Note: Unused standalone copy; same clear as uart_cmd_clear_rx_port2.
 * Name basis: derived - 0xA802B09A and the 0x32 bytes at 0xA802D040
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb528, flags -mcpu=v8 -O2 -g.
 * Source form: an unsigned char loop counter.
 */
extern unsigned char uart_cmd_rx_state_port2;
extern unsigned char uart_cmd_rx_record_port2[];

#define RX_RECORD_SIZE 0x32     /* bytes in a receive record */

/* Clear the receive state byte and the whole receive record of command port 2 and return 0. Not called; same
   clear as uart_cmd_clear_rx_port2. */
int uart_cmd_flush_rx_port2(void)
{
    unsigned char i;

    uart_cmd_rx_state_port2 = 0;
    for (i = 0; i < RX_RECORD_SIZE; i++)
        uart_cmd_rx_record_port2[i] = 0;
    return 0;
}
