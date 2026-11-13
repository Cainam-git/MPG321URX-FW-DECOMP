/* uart_read_rx_ring  (FUN_CODE_6917)
 *
 * Copy the bytes waiting in one serial port's receive ring to a buffer.
 *   port: serial port 1..4
 *   buf: destination
 * Returns: byte count
 * Name basis: derived - rings 0xA1E8 / 0xA208 / 0xA240 / 0xA278 with IDATA indexes; ring 1 is filled by the
 *   UART interrupt; message type 3 data
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_6917 @ 0x6917..0x6AA6 (399 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameters port (XDATA 0xA517) and buf (generic pointer, 0xA518..0xA51A); locals count 0xA51B, i 0xA51C.
 * Source form: the index increment and the wrap test are separate statements ('x++; if (x >= n) x = 0;'), which
 * gives the firmware's re-read of the index; '++x >= n' keeps it in a register.
 */
extern unsigned char xdata uart_rx_ring_port1[];
extern unsigned char xdata uart_rx_ring_port2[], uart_rx_ring_port3[];
extern unsigned char xdata uart_rx_ring_port4[];
extern unsigned char idata uart_rx_write_index_port1, uart_rx_read_index_port1, uart_rx_write_index_port2, uart_rx_read_index_port2;
extern unsigned int idata uart_rx_write_index_port3, uart_rx_read_index_port3, uart_rx_write_index_port4, uart_rx_read_index_port4;

#define RING_SIZE_PORT1  0x10
#define RING_SIZE        0x38   /* ports 2..4 */

/*
 * uart_read_rx_ring - copy the bytes waiting in one serial port's receive ring to buf and empty the ring.
 *   port  1: ring filled by irq_uart (16 bytes, byte indexes); 2 and 3: filled by irq_ext0_ddc_slave; 4: filled by
 *         irq_ext1_peripherals (0x38 bytes each; ports 3 and 4 have 16-bit indexes). Any other port: nothing.
 *   buf   destination
 * Returns the number of bytes copied (0 for an unknown port).
 * The loop copies first and then compares the read index with the write index, so an empty ring would be copied
 * once all the way round (the full ring size); the only caller, ipc_fill_report_record, calls it only
 * for a port that uart_find_port_with_rx_data has found with data waiting.
 */
unsigned char uart_read_rx_ring(unsigned char port, unsigned char *buf)
{
    unsigned char count, i;

    count = 0;
    if (port == 1) {
        for (i = 0; ; i++) {
            buf[i] = uart_rx_ring_port1[uart_rx_read_index_port1];
            uart_rx_read_index_port1++;
            if (uart_rx_read_index_port1 >= RING_SIZE_PORT1) uart_rx_read_index_port1 = 0;
            if (uart_rx_write_index_port1 == uart_rx_read_index_port1) { count = i + 1; break; }
        }
    } else if (port == 2) {
        for (i = 0; ; i++) {
            buf[i] = uart_rx_ring_port2[uart_rx_read_index_port2];
            uart_rx_read_index_port2++;
            if (uart_rx_read_index_port2 >= RING_SIZE) uart_rx_read_index_port2 = 0;
            if (uart_rx_write_index_port2 == uart_rx_read_index_port2) { count = i + 1; break; }
        }
    } else if (port == 3) {
        for (i = 0; ; i++) {
            buf[i] = uart_rx_ring_port3[uart_rx_read_index_port3];
            uart_rx_read_index_port3++;
            if (uart_rx_read_index_port3 >= RING_SIZE) uart_rx_read_index_port3 = 0;
            if (uart_rx_write_index_port3 == uart_rx_read_index_port3) { count = i + 1; break; }
        }
    } else if (port == 4) {
        for (i = 0; ; i++) {
            buf[i] = uart_rx_ring_port4[uart_rx_read_index_port4];
            uart_rx_read_index_port4++;
            if (uart_rx_read_index_port4 >= RING_SIZE) uart_rx_read_index_port4 = 0;
            if (uart_rx_write_index_port4 == uart_rx_read_index_port4) { count = i + 1; break; }
        }
    }
    return count;
}
