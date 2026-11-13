/* uart_get_rx_head_port2  (FUN_CODE_0006)
 *
 * Return the write index of the port 2 receive ring.
 * Returns: write index
 * Note: No caller in the bank-1 image; sits between the interrupt vectors.
 * Name basis: derived - IDATA 0x47 = write index of ring 2 (0xA208) in uart_read_rx_ring; no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_0006 @ 0x0006 (5 bytes, between the interrupt vectors at 0x0003 and 0x000B), OPTIMIZE(7,SPEED).
 */
extern unsigned char idata uart_rx_write_index_port2;

/*
 * uart_get_rx_head_port2 - return the write index of the port 2 receive ring (0xA208). The serial interrupt
 * stores each received byte at this index and moves it on; uart_read_rx_ring reads up to it.
 * Nothing in the bank 1 program calls this routine.
 */
unsigned char uart_get_rx_head_port2(void)
{
    return uart_rx_write_index_port2;
}
