/* uart_read_rx_byte  (FUN_a0072c6c)
 *
 * Take the next received byte from the debug console ring buffer.
 *   out: receives the byte taken from the ring
 * Returns: 1 when a byte was read, 0 when empty
 * Name basis: proven - ring 0xA80788E8 filled by uart_rx_isr; caller dbg_handle_input_line
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * The read index is read from memory at each use, as in the firmware.
 */
#define UART_RX_RING_SIZE 0x80
#define RX_HEAD_INDEX 0x80 /* write index, kept behind the data bytes (see uart_rx_isr) */
#define RX_TAIL_INDEX 0x81 /* read index */
extern unsigned char uart_rx_buffer[];

/*
 * Take the oldest byte out of the debug console receive ring.
 *   out: receives the byte
 * Returns 1 when a byte was taken, 0 when the ring is empty (write index equals read index).
 */
int uart_read_rx_byte(unsigned char *out)
{
    if (uart_rx_buffer[RX_HEAD_INDEX] == uart_rx_buffer[RX_TAIL_INDEX])
        return 0;

    *out = uart_rx_buffer[uart_rx_buffer[RX_TAIL_INDEX]];

    {
        unsigned char next_tail = uart_rx_buffer[RX_TAIL_INDEX] + 1;
        uart_rx_buffer[RX_TAIL_INDEX] = next_tail;
        if (next_tail & UART_RX_RING_SIZE)
            uart_rx_buffer[RX_TAIL_INDEX] = 0;
    }

    return 1;
}
