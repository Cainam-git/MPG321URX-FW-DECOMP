/* uart_rx_isr  (FUN_a0061450)
 *
 * Store a received debug-console byte in the receive ring buffer.
 * Note: Drops the byte when the 128-byte ring is full.
 * Name basis: proven - interrupt-4 source handler (table 0xA80787A8); bit 0 of 0xC00C0014 = byte received;
 *   ring 0xA80788E8
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * The received register is read before the full test, so a byte arriving with a full ring is still read
 * (and dropped). The address word of the ring is at 0xa00b87c0. Hardware registers are volatile.
 */
/* Debug console receive ring: 128 data bytes, then the write index (head) and the read index (tail). */
#define UART_RX_RING_SIZE 0x80
struct uart_rx_ring {
    unsigned char data[UART_RX_RING_SIZE];
    unsigned char head; /* next position to write; uart_rx_isr advances it */
    unsigned char tail; /* next position to read; uart_read_rx_byte advances it */
};
extern struct uart_rx_ring uart_rx_buffer;
#define UART_STATUS_REG (*(volatile unsigned int *)0xc00c0014)
#define UART_DATA_REG   (*(volatile unsigned int *)0xc00c0000)
#define UART_STATUS_RX_READY 0x01 /* a received byte is waiting */

/*
 * Interrupt handler of the debug console receive interrupt. When a byte is waiting it is read and put
 * in the ring. The ring is full when the next write index equals the read index; the byte is then lost.
 */
void uart_rx_isr(void)
{
    unsigned char head, next_head, byte;

    if (UART_STATUS_REG & UART_STATUS_RX_READY) {
        head = uart_rx_buffer.head;
        next_head = head + 1;
        if (next_head >= UART_RX_RING_SIZE)
            next_head = 0;
        byte = UART_DATA_REG;
        if (next_head != uart_rx_buffer.tail) {
            uart_rx_buffer.data[head] = byte;
            uart_rx_buffer.head = next_head;
        }
    }
}
