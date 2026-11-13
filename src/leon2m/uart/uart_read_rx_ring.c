/* uart_read_rx_ring  (FUN_a0133950)
 *
 * Read received bytes of serial port 0..4 from its ring buffer.
 * Name basis: proven - prints 'UART buf index over!' for a wrong port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133950 @ 0xa0133950, flags -mcpu=v8 -O3 -g.
 */

#define UART_PORT_LAST      4       /* highest port number with a ring */
#define UART_RING_MASK      0x1f    /* the ring holds 32 bytes */

/* Receive ring of one serial port: 35 bytes in uart_rx_rings, one ring per port. */
struct uart_rx_ring {
    unsigned char write_index;      /* next place to store; moved on by ipc_8051_decode_message */
    unsigned char read_index;       /* next byte to read; the ring is empty when it equals write_index */
    unsigned char data[32];
    unsigned char overflow;         /* set by ipc_8051_decode_message when a write catches up with the read index; not used here */
};
extern struct uart_rx_ring uart_rx_rings[];
extern int dbg_printf();

/*
 * Copy up to len received bytes of a serial port from its ring into buf.
 *
 *   port  serial port 0..4; any other value prints "UART buf index over!" and returns with *count untouched
 *   len   room in buf
 *   buf   destination
 *   count (out) number of bytes copied; stops early when the ring runs empty
 *
 * Called through uart_api_read_rx_ring by uart_cmd_read_frame and uart_cmd_read_frame_port2.
 */
void uart_read_rx_ring(unsigned char port, unsigned short len, unsigned char *buf, unsigned short *count)
{
    unsigned short i;

    if (port > UART_PORT_LAST) {
        dbg_printf("UART buf index over!");
        return;
    }
    *count = 0;
    for (i = 0; i < len; i++) {
        if (uart_rx_rings[port].write_index == uart_rx_rings[port].read_index) return;
        buf[i] = uart_rx_rings[port].data[uart_rx_rings[port].read_index];
        (*count)++;
        uart_rx_rings[port].read_index = (uart_rx_rings[port].read_index + 1) & UART_RING_MASK;
    }
}
