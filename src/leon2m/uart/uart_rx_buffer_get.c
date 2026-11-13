/* uart_rx_buffer_get  (FUN_a00deea4)
 *
 * Take one character from the receive buffer of the debug serial port.
 * Returns: 1 when a character was taken
 * Name basis: proven - 128-byte ring at 0xA802B0EC; used by the command line
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00deea4 @ 0xa00deea4-0xa00deef0 (19 words).
 * Source form: the next tail index is computed in an unsigned char and the wrap is tested as bit 7 of it.
 */

/* Receive ring of the debug serial port: 128 data bytes, then the head and the tail index (see uart_rx_isr). */
struct uart_rx_ring {
    unsigned char data[0x80];
    unsigned char head;                         /* +0x80: where the interrupt stores the next byte */
    unsigned char tail;                         /* +0x81: where the reader takes the next byte; head == tail: empty */
};
extern struct uart_rx_ring dbg_uart_rx_ring;

#define UART_RX_RING_SIZE 0x80

/*
 * Take the oldest character from the receive ring (filled by uart_rx_isr).
 *
 *   out  receives the character
 *
 * Returns 0 when the ring is empty (head equals tail), else stores the character at the tail through out, moves
 * the tail on (back to 0 after index 127) and returns 1. Called by dbg_command_shell.
 */
int uart_rx_buffer_get(unsigned char *out)
{
    unsigned char next;

    if (dbg_uart_rx_ring.head == dbg_uart_rx_ring.tail)
        return 0;
    *out = dbg_uart_rx_ring.data[dbg_uart_rx_ring.tail];
    next = dbg_uart_rx_ring.tail + 1;
    if (next & UART_RX_RING_SIZE)
        dbg_uart_rx_ring.tail = 0;
    else
        dbg_uart_rx_ring.tail = next;
    return 1;
}
