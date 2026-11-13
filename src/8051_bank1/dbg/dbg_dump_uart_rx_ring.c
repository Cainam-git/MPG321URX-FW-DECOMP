/* dbg_dump_uart_rx_ring  (FUN_CODE_cc38)
 *
 * Print the unread bytes of the port 2 receive ring.
 * Note: No caller in the bank-1 image.
 * Name basis: derived - ring 0xA208 from read index 0xA1E5 to write index IDATA 0x47
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cc38 @ 0xCC38..0xCC7D (69 bytes)  Byte-exact with OPTIMIZE(8,SPEED) (no register file).
 */
extern unsigned char idata uart_rx_write_index_port2;
extern unsigned char xdata dbg_uart_dump_read_index;
extern unsigned char xdata uart_rx_ring_port2[];
extern void lib_printf517(void *fmt, ...) large;

/* The port 2 receive ring holds 0x38 bytes. */
#define UART_RX_RING_SIZE 0x38

/*
 * Print every byte from the dump read index up to the write index of the
 * port 2 receive ring (uart_rx_ring_port2), using the format "%BX " (code
 * 0xDDA6) for each byte, then a line end (format at 0xDDAB). The dump read
 * index wraps at the ring size. Prints nothing when the two indices are
 * equal. No caller in the bank-1 image.
 */
void dbg_dump_uart_rx_ring(void)
{
    if (dbg_uart_dump_read_index != uart_rx_write_index_port2) {
        while (dbg_uart_dump_read_index != uart_rx_write_index_port2) {
            lib_printf517((void code *)0xdda6, uart_rx_ring_port2[dbg_uart_dump_read_index]);
            dbg_uart_dump_read_index++;
            if (dbg_uart_dump_read_index >= UART_RX_RING_SIZE) dbg_uart_dump_read_index = 0;
        }
        lib_printf517((void code *)0xddab);
    }
}
