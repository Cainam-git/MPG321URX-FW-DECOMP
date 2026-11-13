/* uart_flush_tx_queue_port4  (FUN_CODE_d021)
 *
 * Send the queued bytes of serial port 4 and empty the queue.
 * Note: Waits while the transmit buffer is full (status bit 3).
 * Name basis: derived - twin of uart_flush_tx_queue_port2; record type 3 sub 4 of the message handler, baud
 *   regs 0xF06F/70
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d021 @ 0xd021  Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 * Source form: the status register is volatile (it is polled).
 */
extern unsigned char idata uart_tx_queue_count_port4;
extern unsigned char xdata uart_tx_queue_port4[];
extern unsigned char volatile xdata reg_uart4_status;
extern unsigned char xdata reg_uart4_tx_data;
extern unsigned char xdata DAT_EXTMEM_f00a;

/*
 * Send the bytes queued for serial port 4 (uart_tx_queue_port4, count in
 * uart_tx_queue_count_port4) one by one to the transmit data register. Before
 * each byte it waits while bit 3 of the status register is set (an empty
 * 100-step loop per poll). Then the count is cleared and 0x55 is written to
 * 0xF00A. Same code as the flush routine of port 2. Callers: the code at
 * 0x2006, 0xD847 and 0xDB79.
 */
void uart_flush_tx_queue_port4(void)
{
    unsigned char i, j;
    for (i = 0; i < uart_tx_queue_count_port4; i++) {
        while (reg_uart4_status & 0x08) {
            for (j = 0; j < 100; j++) ;
        }
        reg_uart4_tx_data = uart_tx_queue_port4[i];
    }
    uart_tx_queue_count_port4 = 0;
    DAT_EXTMEM_f00a = 0x55;
}
