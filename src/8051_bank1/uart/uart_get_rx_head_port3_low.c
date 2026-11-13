/* uart_get_rx_head_port3_low  (FUN_CODE_000e)
 *
 * Return the low byte of the write index of the port 3 receive ring.
 * Returns: index low byte
 * Note: No caller in the bank-1 image; sits between the interrupt vectors.
 * Name basis: descriptive - IDATA 0x49 = low byte of the 16-bit ring-3 write index 0x48 in uart_read_rx_ring;
 *   no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_000e @ 0x000e (5 bytes, between the interrupt vectors at 0x000B and 0x0013), OPTIMIZE(7,SPEED).
 * Source form: the byte at IDATA 0x49 is declared as its own unsigned char, so the code reads one byte only.
 */
extern unsigned char idata uart_rx_write_index_port3_low;

/*
 * uart_get_rx_head_port3_low - return the low byte of the 16-bit write index of the port 3 receive ring. The
 * index is stored high byte first at IDATA 0x48, so its low byte is IDATA 0x49.
 * Nothing in the bank 1 program calls this routine.
 */
unsigned char uart_get_rx_head_port3_low(void)
{
    return uart_rx_write_index_port3_low;
}
