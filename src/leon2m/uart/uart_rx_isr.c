/* uart_rx_isr  (FUN_a002e238)
 *
 * Move one received UART byte into the 128-byte receive ring.
 * Note: Installed by uart_init as level-4 source 0x20; drops the byte when the ring is full.
 * Name basis: proven - UART data/status 0xC00B0000/0xC00B0014 (same registers as the crash print); ring
 *   0xA802B0EC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002e238, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the wrap of the head index is tested as a signed char (next < 0 after next = head + 1);
 *  - the status register is read as a 32-bit value through reg_read32.
 */
/* Receive ring of the debug serial port: 128 data bytes, then the head and the tail index. */
struct Ring {
    unsigned char buf[0x80];
    unsigned char head;     /* where the interrupt stores the next byte */
    unsigned char tail;     /* where the reader takes the next byte; head == tail means empty */
};
extern struct Ring dbg_uart_rx_ring;
extern unsigned int reg_read32(unsigned int addr);

#define UART_DATA_REG       0xc00b0000
#define UART_STATUS_REG     0xc00b0014
#define UART_STATUS_RX_READY 1          /* bit 0 of the status register: a byte has arrived */

/*
 * Interrupt handler of the debug serial port: take the received byte into dbg_uart_rx_ring.
 * The byte is dropped when the ring is full (storing it would make head equal to tail).
 */
void uart_rx_isr(void)
{
    unsigned char rx_byte, next;

    if (reg_read32(UART_STATUS_REG) & UART_STATUS_RX_READY) {
        rx_byte = reg_read32(UART_DATA_REG);
        next = dbg_uart_rx_ring.head + 1;
        if ((signed char)next < 0)              /* past index 127: wrap to 0 */
            next = 0;
        if (next != dbg_uart_rx_ring.tail) {
            dbg_uart_rx_ring.buf[dbg_uart_rx_ring.head] = rx_byte;
            dbg_uart_rx_ring.head = next;
        }
    }
}
