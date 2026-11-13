/* uart_find_port_with_data  (FUN_a0133a10)
 *
 * Return a serial port 1..4 that has received data waiting.
 * Returns: port or 0
 * Name basis: derived - read index differs from write index; no direct caller, reached through a table
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133a10 @ 0xa0133a10-0xa0133ad8 (50 words), flags -mcpu=v8 -O3 -g.
 */

#define UART_PORT_LAST  4       /* highest port number with a ring */

/* Receive ring of one serial port (see uart_read_rx_ring). */
struct uart_rx_ring {
    unsigned char write_index;
    unsigned char read_index;
    unsigned char data[32];
    unsigned char overflow;
};
extern struct uart_rx_ring uart_rx_rings[];

/*
 * Tell whether serial port `port` has received bytes waiting (its ring is not empty), or with port 0 find the
 * first of ports 1..4 that has.
 *
 *   port  1..4 to test that port, 0 to search ports 1..4 in order
 *
 * Returns the port with data, or 0 when there is none. Nothing calls it directly; it is reached through a table.
 */
unsigned char uart_find_port_with_data(unsigned char port)
{
    unsigned char found = 0;
    unsigned char i;

    if (port != 0) {
        if (uart_rx_rings[port].write_index != uart_rx_rings[port].read_index)
            found = port;
    } else {
        for (i = 1; i <= UART_PORT_LAST; i++)
            if (uart_rx_rings[i].write_index != uart_rx_rings[i].read_index) {
                found = i;
                break;
            }
    }
    return found;
}
