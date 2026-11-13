/* uart_test_no_rx_data  (FUN_CODE_de50)
 *
 * Report whether no serial port has received data to pass on.
 * Returns: 1 when none
 * Name basis: derived - uart_find_port_with_rx_data returns the port 1..4 with data or 0xFF; tested by the
 *   report builder before a type 3 report
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de50 @ 0xde50 (not the bank-2 FUN_CODE_de50)
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
#define UART_NO_PORT 0xff   /* uart_find_port_with_rx_data: no port has data */

unsigned char uart_find_port_with_rx_data(void);

/* Return 1 when uart_find_port_with_rx_data finds no serial port with
 * received data, else 0. Only caller: the call at 0x39ee. */
bit uart_test_no_rx_data(void)
{
    if (uart_find_port_with_rx_data() != UART_NO_PORT) return 0;
    return 1;
}
