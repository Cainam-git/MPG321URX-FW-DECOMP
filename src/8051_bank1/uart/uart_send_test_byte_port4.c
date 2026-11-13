/* uart_send_test_byte_port4  (FUN_CODE_d83f)
 *
 * Send a counting test byte on serial port 4 and log it.
 * Note: Not called anywhere.
 * Name basis: derived - prints 'k %BX'; no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d83f @ 0xd83f..0xd862 (35 B)
 * The format string "k %BX\r\n" is at CODE 0xDDAE. Nothing in the bank-1 image calls or jumps to 0xD83F.
 */
extern unsigned char xdata uart_test_byte_value;
extern void uart_queue_tx_byte_port4(unsigned char v);
extern void uart_flush_tx_queue_port4(void);
extern void lib_printf517(void *fmt, ...) large;

/*
 * Test output: queue the counting test byte for serial port 4, send the queue, print the byte as "k %BX" and
 * count it up. Nothing in the image calls this routine.
 */
void uart_send_test_byte_port4(void)
{
    uart_queue_tx_byte_port4(uart_test_byte_value);
    uart_flush_tx_queue_port4();
    lib_printf517((void code *)0xddae, uart_test_byte_value);
    uart_test_byte_value++;
}
