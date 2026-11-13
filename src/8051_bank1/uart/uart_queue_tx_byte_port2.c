/* uart_queue_tx_byte_port2  (FUN_CODE_db32)
 *
 * Queue one byte for serial port 2, sending the queue when it is full.
 *   byte
 * Name basis: derived - message type 3 sub 2; flush by uart_flush_tx_queue_port2 at 0x37 bytes
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_db32 @ 0xdb32
 * Options: OPTIMIZE(8,SPEED).
 * The count must be idata (MOV R0,#4DH / MOV A,@R0 / INC @R0); as data Keil gives MOV R6,dir / INC dir (27 B).
 */
#define UART_TX_QUEUE_FULL 0x37   /* queue length at which it is sent */

extern unsigned char idata uart_tx_queue_count_port2;
extern unsigned char xdata uart_tx_queue_port2[];
void uart_flush_tx_queue_port2(void);

/* Append byte to the transmit queue of serial port 2. When the queue has
 * reached UART_TX_QUEUE_FULL bytes, call uart_flush_tx_queue_port2 (it sends
 * the queue and clears the count). Same code as the port 3 and port 4
 * versions. Only caller: ipc_run_message. */
void uart_queue_tx_byte_port2(unsigned char byte)
{
    uart_tx_queue_port2[uart_tx_queue_count_port2++] = byte;
    if (uart_tx_queue_count_port2 >= UART_TX_QUEUE_FULL) uart_flush_tx_queue_port2();
}
