/* uart_queue_tx_byte_port4  (FUN_CODE_db64)
 *
 * Queue one byte for serial port 4, sending the queue when it is full.
 *   byte
 * Name basis: derived - message type 3 sub 4; flush by uart_flush_tx_queue_port4 at 0x37 bytes
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_db64 @ 0xdb64
 * Options: OPTIMIZE(8,SPEED).
 * The count must be idata (MOV R0,#53H / MOV A,@R0 / INC @R0); as data Keil gives MOV R6,dir / INC dir (27 B).
 */
#define UART_TX_QUEUE_FULL 0x37   /* queue length at which it is sent */

extern unsigned char idata uart_tx_queue_count_port4;
extern unsigned char xdata uart_tx_queue_port4[];
void uart_flush_tx_queue_port4(void);

/* Append byte to the transmit queue of serial port 4. When the queue has
 * reached UART_TX_QUEUE_FULL bytes, call uart_flush_tx_queue_port4 (it sends
 * the queue and clears the count). Same code as the port 2 and port 3
 * versions. Callers: ipc_run_message and the call at 0xd844. */
void uart_queue_tx_byte_port4(unsigned char byte)
{
    uart_tx_queue_port4[uart_tx_queue_count_port4++] = byte;
    if (uart_tx_queue_count_port4 >= UART_TX_QUEUE_FULL) uart_flush_tx_queue_port4();
}
