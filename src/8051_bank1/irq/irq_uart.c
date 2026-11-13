/* irq_uart  (FUN_CODE_bfdd)
 *
 * Serve the serial port interrupt: store a received byte, send the next queued one.
 * Name basis: proven - interrupt 4 (serial) 'using 1'; receive ring 0xA1E8 (port 1 of uart_read_rx_ring),
 *   transmit ring 0xA1F8
 *
 * Matching notes
 * --------------
 * FUN_CODE_bfdd, 8051_bank1. OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) added).
 * Serial-port interrupt service routine: interrupt 4 (the vector at CODE 0x0023 jumps here), 'using 1'; Keil saves only
 * ACC, DPH, DPL, PSW.
 */
#include <reg51.h>
extern unsigned char idata uart_rx_write_index_port1, uart_tx_write_index_port1, uart_tx_read_index_port1, uart_tx_idle_flag_port1, uart_rx_last_byte_port1;
extern unsigned char xdata uart_rx_ring_port1[];
extern unsigned char xdata uart_tx_ring_port1[];
/*
 * irq_uart - serial port interrupt (vector at CODE 0x0023).
 * Receive (RI): clear RI, read SBUF and put the byte into the 16-byte receive ring at the write index (IDATA 0x42,
 * wraps after 15).
 * Transmit (TI): clear TI; when the transmit read index (IDATA 0x45) differs from the write index (IDATA 0x43), send
 * the byte at the read index of the transmit ring and advance the index (wraps after 15); otherwise set the idle flag
 * (IDATA 0x46 = 1). The routine that queues a byte (uart_tx_ring_put) restarts the transmitter when the idle flag is set.
 */
void irq_uart(void) interrupt 4 using 1
{
    if (RI) {
        RI = 0;
        uart_rx_last_byte_port1 = SBUF;
        uart_rx_ring_port1[uart_rx_write_index_port1] = uart_rx_last_byte_port1;
        if (++uart_rx_write_index_port1 > 0x0f) uart_rx_write_index_port1 = 0;
    }
    if (TI) {
        TI = 0;
        if (uart_tx_read_index_port1 != uart_tx_write_index_port1) {
            SBUF = uart_tx_ring_port1[uart_tx_read_index_port1];
            if (++uart_tx_read_index_port1 > 0x0f) uart_tx_read_index_port1 = 0;
        } else uart_tx_idle_flag_port1 = 1;
    }
}
