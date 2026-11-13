/* uart_flush_tx_queue_port2  (FUN_CODE_cfad)
 *
 * Send the queued bytes of serial port 2 and empty the queue.
 * Note: Waits while the transmit buffer is full (status bit 3).
 * Name basis: derived - record type 3 sub 2 of the message handler (port numbers 1..4); baud regs 0xF0F7/F8
 *   set with data reg 0xF0FB
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cfad @ 0xcfad  OPTIMIZE(8,SPEED)
 * Source form: the status register is volatile (it is polled).
 */
extern unsigned char idata uart_tx_queue_count_port2;
extern unsigned char xdata uart_tx_queue_port2[];
extern unsigned char volatile xdata reg_uart2_status;
extern unsigned char xdata reg_uart2_tx_data;
extern unsigned char xdata DAT_EXTMEM_f00a;

/*
 * Send the bytes queued for serial port 2 (uart_tx_queue_port2, count in
 * uart_tx_queue_count_port2) one by one to the transmit data register. Before
 * each byte it waits while bit 3 of the status register is set (an empty
 * 100-step loop per poll). Then the count is cleared and 0x55 is written to
 * 0xF00A. Same code as the flush routines of ports 3 and 4 with other
 * addresses. Callers: the code at 0x1F87 and 0xDB47.
 */
void uart_flush_tx_queue_port2(void)
{
    unsigned char i, j;
    for (i = 0; i < uart_tx_queue_count_port2; i++) {
        while (reg_uart2_status & 0x08) {
            for (j = 0; j < 100; j++) ;
        }
        reg_uart2_tx_data = uart_tx_queue_port2[i];
    }
    uart_tx_queue_count_port2 = 0;
    DAT_EXTMEM_f00a = 0x55;
}
