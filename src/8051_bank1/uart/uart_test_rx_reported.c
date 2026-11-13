/* uart_test_rx_reported  (FUN_CODE_ddb6)
 *
 * Report whether serial port n's received data is already reported.
 *   port
 * Returns: bit
 * Name basis: derived - bit n of 0xA3E3, set by the report builder after a type 3 (serial data) report
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ddb6 @ 0xddb6
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
extern unsigned char xdata uart_rx_reported_mask;

/* Return bit port of uart_rx_reported_mask: set while the received data of
 * that serial port still sits in a mailbox slot.
 *   port: serial port number */
bit uart_test_rx_reported(unsigned char port)
{
    return (uart_rx_reported_mask >> port) & 1;
}
