/* irq_ext0_ddc_slave  (FUN_CODE_2c38)
 *
 * Serve the DDC/CI slave events of four input ports.
 * Note: Runs in register bank 1; marks active ports in IDATA 0x29 for the idle check.
 * Name basis: proven - external interrupt 0 vector; per-port in/out arrays 0xA0F4../0xA002.. are the DDC/CI
 *   buffers of message type 4 ('DATA_DDCCI')
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED). Interrupt routine of external interrupt 0: vector 0x0003 holds
 * 'LJMP 0x2C38'; 'using 1' gives MOV PSW,#08H, and Keil saves only ACC, DPH, DPL and PSW.
 * Source forms the exact build depends on:
 * - The tests of reg_uart_rx_irq_status, reg_uart2_status and reg_uart3_status are written
 *   '(unsigned int)(x & n)' (ANL / JZ); all other tests are plain char tests (JB / JNB).
 * - The 0xF0xx locations are chip registers (volatile).
 */
extern unsigned char volatile xdata reg_irq_source_status, DAT_EXTMEM_f00a, reg_uart_rx_irq_status;
extern unsigned char volatile xdata reg_i2c0_ctrl, reg_i2c0_status, reg_i2c0_mode, reg_i2c0_events,
    reg_i2c0_event_ack, reg_i2c0_tx_data, reg_i2c0_rx_data;
extern unsigned char volatile xdata reg_i2c2_ctrl, reg_i2c2_status, reg_i2c2_mode, reg_i2c2_events,
    reg_i2c2_event_ack, reg_i2c2_tx_data, reg_i2c2_rx_data;
extern unsigned char volatile xdata reg_i2c4_ctrl, reg_i2c4_status, reg_i2c4_mode, reg_i2c4_events,
    reg_i2c4_event_ack, reg_i2c4_tx_data, reg_i2c4_rx_data;
extern unsigned char volatile xdata reg_i2c6_ctrl, reg_i2c6_status, reg_i2c6_mode, reg_i2c6_events,
    reg_i2c6_event_ack, reg_i2c6_tx_data, reg_i2c6_rx_data;
extern unsigned char volatile xdata reg_uart2_status, reg_uart2_rx_data, reg_uart3_status, reg_uart3_rx_data;
extern unsigned char xdata ddc_reply_buffers[], ddc_reply_buffer_row1[], ddc_reply_buffer_row2[], ddc_reply_buffer_row3[];
extern unsigned char xdata ddc_request_buffers[], ddc_request_buffer_row1[], ddc_request_buffer_row2[], ddc_request_buffer_row3[];
extern unsigned char xdata uart_rx_ring_port2[], uart_rx_ring_port3[];
extern unsigned char idata ddc_port_activity_flags;
extern unsigned char idata ddc_request_index_port0, ddc_request_index_port2, ddc_request_index_port4, ddc_request_index_port6;
extern unsigned char idata ddc_reply_end_indexes, ddc_reply_end_index_port2, ddc_reply_end_index_port4, ddc_reply_end_index_port6;
extern unsigned char idata ddc_reply_index_port0, ddc_reply_index_port2, ddc_reply_index_port4, ddc_reply_index_port6;
extern unsigned char idata uart_rx_write_index_port2;
extern unsigned int idata uart_rx_write_index_port3;


/* Bits of reg_irq_source_status and of ddc_port_activity_flags: one per DDC/CI slave port. The odd ports are
   served by the external interrupt 1 routine. */
#define DDC_SLAVE_PORT0 0x01
#define DDC_SLAVE_PORT2 0x04
#define DDC_SLAVE_PORT4 0x10
#define DDC_SLAVE_PORT6 0x40

/* reg_i2c<N>_events bits; each is acknowledged by writing it to reg_i2c<N>_event_ack. */
#define DDC_EVT_BEGIN     0x80  /* starts a reply or a request (status bit 7 decides which) */
#define DDC_EVT_SEND_BYTE 0x40  /* the next reply byte goes to tx_data */
#define DDC_EVT_BYTE_IN   0x20  /* a request byte is waiting in rx_data */
#define DDC_EVT_BIT4      0x10  /* only acknowledged (with DDC_EVT_ACK_ALL) */
#define DDC_EVT_BIT3      0x08  /* only acknowledged (with DDC_EVT_ACK_ALL) */
#define DDC_EVT_ACK_ALL   0xff
#define DDC_STATUS_REPLY  0x80  /* reg_i2c<N>_status bit 7: the code answers with a reply */
#define DDC_MODE_REPLY    0xc0
#define DDC_MODE_REQUEST  0xa0
#define DDC_REQUEST_LAST    0x3b  /* last request index before the restart */
#define DDC_REQUEST_RESTART 2

#define UART2_RX_IRQ       0x40 /* reg_uart_rx_irq_status bits */
#define UART3_RX_IRQ       0x80
#define UART_RX_EMPTY      0x01 /* reg_uart<N>_status bit 0: no byte left to read */
#define UART_STATUS_BIT4   0x10 /* written back when set (purpose not shown) */
#define UART_RX_RING_SIZE  0x38

/*
 * irq_ext0_ddc_slave - external interrupt 0: serve the DDC/CI slaves of the even ports 0, 2, 4, 6 and the receive
 * side of serial ports 2 and 3.
 * Each DDC/CI port has a request row (ddc_request_buffers.., filled here; its rows go to the main processor as report type 4,
 * docs/MAILBOX.md) and
 * a reply row (ddc_reply_buffers.., filled by message type 4 from the main processor, sent here up to the end
 * index that message stores). Every byte moved writes 0x55 to 0xF00A.
 *
 * Phases:
 *   1..4  ports 0, 2, 4, 6, each only when its bit in reg_irq_source_status is set, all with the same steps:
 *         a. DDC_EVT_BEGIN: status bit 7 set -> start a reply (ack 0x44, first reply byte out, reply mode, reply
 *            index 1); clear -> start a request (request mode, bit 6 of ctrl set, request index 0, port marked in
 *            ddc_port_activity_flags);
 *         b. while DDC_EVT_SEND_BYTE: send the next reply byte;
 *         c. while DDC_EVT_BYTE_IN: store the byte in the request row and mark the port active;
 *         d. DDC_EVT_BIT4 and DDC_EVT_BIT3: acknowledge all events.
 *   5, 6  serial ports 2 and 3: move every waiting byte into the port's 0x38-byte receive ring.
 */

void irq_ext0_ddc_slave(void) interrupt 0 using 1
{
    /* Phase 1: DDC/CI slave port 0 (reply row 0 front, request row 0). */
    if (reg_irq_source_status & DDC_SLAVE_PORT0) {
        if (reg_i2c0_events & DDC_EVT_BEGIN) {
            reg_i2c0_event_ack = DDC_EVT_BEGIN;
            if (reg_i2c0_status & DDC_STATUS_REPLY) {
                /* Reply: first byte out now, the rest from index 1 on. */
                reg_i2c0_event_ack = 0x44;
                reg_i2c0_tx_data = ddc_reply_buffers[0];
                reg_i2c0_mode = DDC_MODE_REPLY;
                ddc_reply_index_port0 = 1;
            } else {
                /* Request: collect from the start of the request row. */
                reg_i2c0_mode = DDC_MODE_REQUEST;
                reg_i2c0_ctrl |= 0x40;
                ddc_request_index_port0 = 0;
                ddc_port_activity_flags |= DDC_SLAVE_PORT0;
            }
        }
        while (reg_i2c0_events & DDC_EVT_SEND_BYTE) {
            /* At the end index the byte there is sent and the index starts again at 0. */
            if (ddc_reply_index_port0 != ddc_reply_end_indexes) {
                reg_i2c0_tx_data = ddc_reply_buffers[ddc_reply_index_port0++];
                reg_i2c0_event_ack = DDC_EVT_SEND_BYTE;
            } else {
                reg_i2c0_tx_data = ddc_reply_buffers[ddc_reply_index_port0];
                reg_i2c0_event_ack = DDC_EVT_SEND_BYTE;
                ddc_reply_index_port0 = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (reg_i2c0_events & DDC_EVT_BYTE_IN) {
            /* Past byte 0x3B the index restarts at 2, so bytes 0 and 1 of the row are kept. */
            ddc_request_buffers[ddc_request_index_port0++] = reg_i2c0_rx_data;
            reg_i2c0_event_ack = DDC_EVT_BYTE_IN;
            ddc_port_activity_flags |= DDC_SLAVE_PORT0;
            if (ddc_request_index_port0 > DDC_REQUEST_LAST) ddc_request_index_port0 = DDC_REQUEST_RESTART;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (reg_i2c0_events & DDC_EVT_BIT4) reg_i2c0_event_ack = DDC_EVT_ACK_ALL;
        if (reg_i2c0_events & DDC_EVT_BIT3) reg_i2c0_event_ack = DDC_EVT_ACK_ALL;
    }
    /* Phase 2: port 2, same steps on row 1. */
    if (reg_irq_source_status & DDC_SLAVE_PORT2) {
        if (reg_i2c2_events & DDC_EVT_BEGIN) {
            reg_i2c2_event_ack = DDC_EVT_BEGIN;
            if (reg_i2c2_status & DDC_STATUS_REPLY) {
                reg_i2c2_event_ack = 0x44;
                reg_i2c2_tx_data = ddc_reply_buffer_row1[0];
                reg_i2c2_mode = DDC_MODE_REPLY;
                ddc_reply_index_port2 = 1;
            } else {
                reg_i2c2_mode = DDC_MODE_REQUEST;
                reg_i2c2_ctrl |= 0x40;
                ddc_request_index_port2 = 0;
                ddc_port_activity_flags |= DDC_SLAVE_PORT2;
            }
        }
        while (reg_i2c2_events & DDC_EVT_SEND_BYTE) {
            if (ddc_reply_index_port2 != ddc_reply_end_index_port2) {
                reg_i2c2_tx_data = ddc_reply_buffer_row1[ddc_reply_index_port2++];
                reg_i2c2_event_ack = DDC_EVT_SEND_BYTE;
            } else {
                reg_i2c2_tx_data = ddc_reply_buffer_row1[ddc_reply_index_port2];
                reg_i2c2_event_ack = DDC_EVT_SEND_BYTE;
                ddc_reply_index_port2 = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (reg_i2c2_events & DDC_EVT_BYTE_IN) {
            ddc_request_buffer_row1[ddc_request_index_port2++] = reg_i2c2_rx_data;
            reg_i2c2_event_ack = DDC_EVT_BYTE_IN;
            ddc_port_activity_flags |= DDC_SLAVE_PORT2;
            if (ddc_request_index_port2 > DDC_REQUEST_LAST) ddc_request_index_port2 = DDC_REQUEST_RESTART;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (reg_i2c2_events & DDC_EVT_BIT4) reg_i2c2_event_ack = DDC_EVT_ACK_ALL;
        if (reg_i2c2_events & DDC_EVT_BIT3) reg_i2c2_event_ack = DDC_EVT_ACK_ALL;
    }
    /* Phase 3: port 4, row 2. */
    if (reg_irq_source_status & DDC_SLAVE_PORT4) {
        if (reg_i2c4_events & DDC_EVT_BEGIN) {
            reg_i2c4_event_ack = DDC_EVT_BEGIN;
            if (reg_i2c4_status & DDC_STATUS_REPLY) {
                reg_i2c4_event_ack = 0x44;
                reg_i2c4_tx_data = ddc_reply_buffer_row2[0];
                reg_i2c4_mode = DDC_MODE_REPLY;
                ddc_reply_index_port4 = 1;
            } else {
                reg_i2c4_mode = DDC_MODE_REQUEST;
                reg_i2c4_ctrl |= 0x40;
                ddc_request_index_port4 = 0;
                ddc_port_activity_flags |= DDC_SLAVE_PORT4;
            }
        }
        while (reg_i2c4_events & DDC_EVT_SEND_BYTE) {
            if (ddc_reply_index_port4 != ddc_reply_end_index_port4) {
                reg_i2c4_tx_data = ddc_reply_buffer_row2[ddc_reply_index_port4++];
                reg_i2c4_event_ack = DDC_EVT_SEND_BYTE;
            } else {
                reg_i2c4_tx_data = ddc_reply_buffer_row2[ddc_reply_index_port4];
                reg_i2c4_event_ack = DDC_EVT_SEND_BYTE;
                ddc_reply_index_port4 = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (reg_i2c4_events & DDC_EVT_BYTE_IN) {
            ddc_request_buffer_row2[ddc_request_index_port4++] = reg_i2c4_rx_data;
            reg_i2c4_event_ack = DDC_EVT_BYTE_IN;
            ddc_port_activity_flags |= DDC_SLAVE_PORT4;
            if (ddc_request_index_port4 > DDC_REQUEST_LAST) ddc_request_index_port4 = DDC_REQUEST_RESTART;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (reg_i2c4_events & DDC_EVT_BIT4) reg_i2c4_event_ack = DDC_EVT_ACK_ALL;
        if (reg_i2c4_events & DDC_EVT_BIT3) reg_i2c4_event_ack = DDC_EVT_ACK_ALL;
    }
    /* Phase 4: port 6, row 3. */
    if (reg_irq_source_status & DDC_SLAVE_PORT6) {
        if (reg_i2c6_events & DDC_EVT_BEGIN) {
            reg_i2c6_event_ack = DDC_EVT_BEGIN;
            if (reg_i2c6_status & DDC_STATUS_REPLY) {
                reg_i2c6_event_ack = 0x44;
                reg_i2c6_tx_data = ddc_reply_buffer_row3[0];
                reg_i2c6_mode = DDC_MODE_REPLY;
                ddc_reply_index_port6 = 1;
            } else {
                reg_i2c6_mode = DDC_MODE_REQUEST;
                reg_i2c6_ctrl |= 0x40;
                ddc_request_index_port6 = 0;
                ddc_port_activity_flags |= DDC_SLAVE_PORT6;
            }
        }
        while (reg_i2c6_events & DDC_EVT_SEND_BYTE) {
            if (ddc_reply_index_port6 != ddc_reply_end_index_port6) {
                reg_i2c6_tx_data = ddc_reply_buffer_row3[ddc_reply_index_port6++];
                reg_i2c6_event_ack = DDC_EVT_SEND_BYTE;
            } else {
                reg_i2c6_tx_data = ddc_reply_buffer_row3[ddc_reply_index_port6];
                reg_i2c6_event_ack = DDC_EVT_SEND_BYTE;
                ddc_reply_index_port6 = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (reg_i2c6_events & DDC_EVT_BYTE_IN) {
            ddc_request_buffer_row3[ddc_request_index_port6++] = reg_i2c6_rx_data;
            reg_i2c6_event_ack = DDC_EVT_BYTE_IN;
            ddc_port_activity_flags |= DDC_SLAVE_PORT6;
            if (ddc_request_index_port6 > DDC_REQUEST_LAST) ddc_request_index_port6 = DDC_REQUEST_RESTART;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (reg_i2c6_events & DDC_EVT_BIT4) reg_i2c6_event_ack = DDC_EVT_ACK_ALL;
        if (reg_i2c6_events & DDC_EVT_BIT3) reg_i2c6_event_ack = DDC_EVT_ACK_ALL;
    }
    /* Phase 5: serial port 2 receive. */
    if ((unsigned int)(reg_uart_rx_irq_status & UART2_RX_IRQ)) {
        while (!(unsigned int)(reg_uart2_status & UART_RX_EMPTY)) {
            uart_rx_ring_port2[uart_rx_write_index_port2++] = reg_uart2_rx_data;
            if (uart_rx_write_index_port2 >= UART_RX_RING_SIZE) uart_rx_write_index_port2 = 0;
            DAT_EXTMEM_f00a = 0x55;
        }
        if ((unsigned int)(reg_uart2_status & UART_STATUS_BIT4)) reg_uart2_status |= UART_STATUS_BIT4;
    }
    /* Phase 6: serial port 3 receive (16-bit write index). */
    if ((unsigned int)(reg_uart_rx_irq_status & UART3_RX_IRQ)) {
        while (!(unsigned int)(reg_uart3_status & UART_RX_EMPTY)) {
            uart_rx_ring_port3[uart_rx_write_index_port3++] = reg_uart3_rx_data;
            if (uart_rx_write_index_port3 >= UART_RX_RING_SIZE) uart_rx_write_index_port3 = 0;
            DAT_EXTMEM_f00a = 0x55;
        }
        if ((unsigned int)(reg_uart3_status & UART_STATUS_BIT4)) reg_uart3_status |= UART_STATUS_BIT4;
    }
}
