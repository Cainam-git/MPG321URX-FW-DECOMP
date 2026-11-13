/* uart_find_port_with_rx_data  (FUN_CODE_ce87)
 *
 * Return the number of a serial port whose receive ring holds data.
 * Returns: port 1..4, or 0xFF
 * Name basis: derived - compares read and write indexes of rings 1..4 (IDATA 0x42/0x44, 0x47/0x4C, 0x48/0x4E,
 *   0x4A/0x51); caller ipc_fill_report_record
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ce87 @ 0xce87 (59 B).
 * Source form: all operands are read through @R0 / @R1 (idata); the ports 3 and 4 indices are 16-bit.
 */
extern unsigned char idata uart_rx_write_index_port1, uart_rx_read_index_port1, uart_rx_write_index_port2, uart_rx_read_index_port2;
extern unsigned int idata uart_rx_write_index_port3, uart_rx_read_index_port3, uart_rx_write_index_port4, uart_rx_read_index_port4;

/*
 * A port has data when the write index of its receive ring differs from the
 * read index. Returns 2, 3 or 4 for the first of those ports that has data;
 * port 1 (return 1) is reported only when ports 2..4 have none. Returns
 * 0xFF when no port has data. Callers: the code at 0x39F6 and 0xDE50.
 */
unsigned char uart_find_port_with_rx_data(void)
{
    unsigned char port;
    port = 0xff;
    if (uart_rx_write_index_port1 != uart_rx_read_index_port1) port = 1;
    if (uart_rx_write_index_port2 != uart_rx_read_index_port2) {
        port = 2;
    } else if (uart_rx_write_index_port3 != uart_rx_read_index_port3) {
        port = 3;
    } else if (uart_rx_write_index_port4 != uart_rx_read_index_port4) {
        port = 4;
    }
    return port;
}
