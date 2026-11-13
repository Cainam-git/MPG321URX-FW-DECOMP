/* uart_tx_ring_put  (FUN_CODE_d1a8)
 *
 * Put one character into the serial port 1 transmit ring and restart sending.
 *   ch: character
 * Returns: 0 stored, 0xFF ring full
 * Name basis: derived - 16-entry ring with head/tail, sets TI to restart the serial interrupt
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d1a8 @ 0xd1a8  Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
#include <reg51.h>
extern unsigned char idata uart_tx_write_index_port1, uart_tx_read_index_port1, uart_tx_idle_flag_port1;
extern unsigned char xdata uart_tx_ring_port1[];

/* The port 1 transmit ring has 16 entries. */
#define UART_TX_RING_MASK 0x0f

/*
 * Put one character into the 16-entry transmit ring of serial port 1.
 * Returns 0xFF when the ring is full (nothing stored), else 0. With
 * interrupts off it stores the character and advances the write index
 * (wrapping after entry 15); when the idle flag is set it clears the flag
 * and sets TI, which restarts the transmit interrupt. Only caller: the code
 * at 0xD517.
 */
unsigned char uart_tx_ring_put(unsigned char ch)
{
    unsigned char head;
    head = uart_tx_write_index_port1;
    if (((head + 1) & UART_TX_RING_MASK) == uart_tx_read_index_port1) return 0xff;
    EA = 0;
    uart_tx_ring_port1[head] = ch;
    if (++uart_tx_write_index_port1 > UART_TX_RING_MASK) uart_tx_write_index_port1 = 0;
    if (uart_tx_idle_flag_port1) {
        uart_tx_idle_flag_port1 = 0;
        TI = 1;
    }
    EA = 1;
    return 0;
}
