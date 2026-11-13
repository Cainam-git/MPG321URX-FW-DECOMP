/* uart_cmd_clear_rx  (FUN_a00ba950)
 *
 * Clear the receive state and receive record of a tool command port.
 *   port: command port
 * Note: Port 2 -> 0xA802D040, port 3 -> 0xA802D098, other -> 0xA802D0D0.
 * Name basis: derived - called by every command handler before the reply
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ba950, flags -mcpu=v8 -O3 -g.
 * Source form: the clears are written in ascending offset order (0, 1, 7, 10, 0x19); the compiler emits them as
 * 0, 0x19, 1, 7, 10.
 */
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];

/* Make the port ready for the next command: clear its receive state byte and bytes 0, 1, 7, 10 and 0x19 of its
   receive record. Port 2 and port 3 have their own state byte and record; every other port (the tool port, 4)
   uses uart_cmd_rx_count and uart_cmd_rx_record. */
void uart_cmd_clear_rx(unsigned char port)
{
    if (port == 2) {
        uart_cmd_rx_state_port2 = 0;
        uart_cmd_rx_record_port2[0] = 0;
        uart_cmd_rx_record_port2[1] = 0;
        uart_cmd_rx_record_port2[7] = 0;
        uart_cmd_rx_record_port2[10] = 0;
        uart_cmd_rx_record_port2[0x19] = 0;
    } else if (port == 3) {
        uart_cmd_rx_state_port3 = 0;
        uart_cmd_rx_record_port3[0] = 0;
        uart_cmd_rx_record_port3[1] = 0;
        uart_cmd_rx_record_port3[7] = 0;
        uart_cmd_rx_record_port3[10] = 0;
        uart_cmd_rx_record_port3[0x19] = 0;
    } else {
        uart_cmd_rx_count = 0;
        uart_cmd_rx_record[0] = 0;
        uart_cmd_rx_record[1] = 0;
        uart_cmd_rx_record[7] = 0;
        uart_cmd_rx_record[10] = 0;
        uart_cmd_rx_record[0x19] = 0;
    }
}
