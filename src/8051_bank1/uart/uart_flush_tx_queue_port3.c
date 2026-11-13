/* uart_flush_tx_queue_port3  (FUN_CODE_cfe7)
 *
 * Send the queued bytes of serial port 3 and empty the queue.
 * Note: Waits while the transmit buffer is full (status bit 3).
 * Name basis: derived - twin of uart_flush_tx_queue_port2; message type 3 sub 3, data reg 0xF037, baud regs
 *   0xF033/34
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cfe7 @ 0xcfe7  OPTIMIZE(7,SPEED)
 * Source form: the count is defined here (not declared extern) as 'unsigned char idata ... _at_ 0x50'; Keil
 * rejects an extern declaration with '_at_'. This produces 'MOV R0,#0x50' for the count accesses.
 */
unsigned char idata uart_tx_queue_count_port3 _at_ 0x50;
extern unsigned char xdata reg_uart3_status;
extern unsigned char xdata reg_uart3_tx_data;
extern unsigned char xdata DAT_EXTMEM_f00a;

/*
 * Send the bytes queued for serial port 3 (buffer at 0xA2E8, count in
 * uart_tx_queue_count_port3) one by one to the transmit data register.
 * Before each byte it waits while bit 3 of the status register is set (an
 * empty 100-step loop per poll). Then the count is cleared and 0x55 is
 * written to 0xF00A. Same code as the flush routine of port 2.
 */
void uart_flush_tx_queue_port3(void) 
{
    unsigned char i;
    unsigned char j;
    
    for (i = 0; i < uart_tx_queue_count_port3; i++) {
        while ((reg_uart3_status & 0x08) != 0) {
            for (j = 0; j < 100; j++) {
                /* empty delay loop */
            }
        }
        reg_uart3_tx_data = ((unsigned char xdata *)0xA2E8)[i];
    }
    uart_tx_queue_count_port3 = 0;
    DAT_EXTMEM_f00a = 0x55;
}
