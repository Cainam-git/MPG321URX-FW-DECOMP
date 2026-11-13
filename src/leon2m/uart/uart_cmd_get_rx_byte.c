/* uart_cmd_get_rx_byte  (FUN_a00bab30)
 *
 * Return one byte of a port's receive record.
 *   port
 *   index: byte index
 * Returns: the byte
 * Note: Unused.
 * Name basis: derived - port 2/3/other records
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bab30, flags -mcpu=v8 -O3 -g.
 * Source form: an if/else chain assigning an unsigned char result.
 */
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];

/* Return byte `index` of the receive record of the port (port 2 and port 3 have their own record; every other
   port uses uart_cmd_rx_record). Not called. */
unsigned char uart_cmd_get_rx_byte(unsigned char port, unsigned char index)
{
    unsigned char value;

    if (port == 2)
        value = uart_cmd_rx_record_port2[index];
    else if (port == 3)
        value = uart_cmd_rx_record_port3[index];
    else
        value = uart_cmd_rx_record[index];
    return value;
}
