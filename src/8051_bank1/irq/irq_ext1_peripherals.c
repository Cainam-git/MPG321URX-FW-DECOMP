/* irq_ext1_peripherals  (FUN_CODE_3091)
 *
 * Serve infrared, serial receive, DP AUX and four more DDC/CI slave ports.
 * Note: Serial bytes from 0xF074 go to the port 4 receive ring 0xA278.
 * Name basis: proven - external interrupt 1 vector; calls irq_record_ir_pulse and dp_aux_service; same DDC/CI
 *   arrays as irq_ext0_ddc_slave
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_3091 @ 0x3091, built with OPTIMIZE(7,SPEED) (the section default; no c51opts entry).
 * Vector 0x0013 'LJMP 0x3091'; 'using 3' = MOV PSW,#18H, and Keil saves ACC, B, DPH, DPL, PSW (it calls
 * functions). Source forms the exact build depends on:
 * - The ANL/JZ tests of reg_uart4_rx_irq_status, reg_uart4_status and reg_i2c7_irq_status are int-typed tests
 *   '(unsigned int)(x & n)'; the JB/JNB tests are plain char tests.
 * - 'reg_capture_irq_flags & irq_capture_enable_mask' in this operand order loads the mask first and keeps it in
 *   R7 for the store.
 * - In the port 5 block Keil reuses A = 0x20 from the preceding store for 'ddc_port_activity_flags |= 0x20'
 *   (ORL A,@R0).
 * - All 0xF0xx registers are declared volatile. No aids.
 */
extern unsigned char volatile xdata reg_irq_source_status, reg_capture_irq_flags, DAT_EXTMEM_f00a, reg_uart4_rx_irq_status, reg_i2c7_irq_status;
extern unsigned char volatile xdata reg_uart4_status, reg_uart4_rx_data;
extern unsigned char volatile xdata reg_i2c1_ctrl, reg_i2c1_status, reg_i2c1_mode, reg_i2c1_events, reg_i2c1_event_ack, reg_i2c1_tx_data, reg_i2c1_rx_data;
extern unsigned char volatile xdata reg_i2c3_ctrl, reg_i2c3_status, reg_i2c3_mode, reg_i2c3_events, reg_i2c3_event_ack, reg_i2c3_tx_data, reg_i2c3_rx_data;
extern unsigned char volatile xdata reg_i2c5_ctrl, reg_i2c5_status, reg_i2c5_mode, reg_i2c5_events, reg_i2c5_event_ack, reg_i2c5_tx_data, reg_i2c5_rx_data;
extern unsigned char volatile xdata reg_i2c7_ctrl, reg_i2c7_status, reg_i2c7_mode, reg_i2c7_events, reg_i2c7_event_ack, reg_i2c7_tx_data, reg_i2c7_rx_data;
extern unsigned char xdata irq_capture_enable_mask;
extern unsigned char xdata ddc_reply_buffers[], ddc_reply_buffer_row1[], ddc_reply_buffer_row2[], ddc_reply_buffer_row3[];
extern unsigned char xdata ddc_request_buffers[], ddc_request_buffer_row1[], ddc_request_buffer_row2[], ddc_request_buffer_row3[];
extern unsigned char xdata uart_rx_ring_port4[];
extern unsigned char idata ddc_port_activity_flags;
extern unsigned char idata ddc_request_index_port1, ddc_request_index_port3, ddc_request_index_port5, ddc_request_index_port7;
extern unsigned char idata ddc_reply_end_index_port1, ddc_reply_end_index_port3, ddc_reply_end_index_port5, ddc_reply_end_index_port7;
extern unsigned char idata ddc_reply_index_port1, ddc_reply_index_port3, ddc_reply_index_port5, ddc_reply_index_port7;
extern unsigned int idata uart_rx_write_index_port4;
void irq_record_ir_pulse(void);
void dp_aux_service(void);

/* Bits of reg_irq_source_status (0xF020) tested here. */
#define IRQ_SOURCE_CAPTURE   0x80  /* capture input (remote control) */
#define IRQ_SOURCE_DDC_PORT1 0x02
#define IRQ_SOURCE_DDC_PORT3 0x08
#define IRQ_SOURCE_DDC_PORT5 0x20
/* Port 7 is flagged in bit 7 of reg_i2c7_irq_status instead. */
#define IRQ_SOURCE_DDC_PORT7 0x80

#define UART_RX_IRQ_PORT4    0x40  /* bit of reg_uart4_rx_irq_status */
#define UART_RX_RING_SIZE    0x38  /* bytes in each serial receive ring */

/* Bit of ddc_port_activity_flags for each port: bit n = port n. */
#define DDC_ACTIVE_PORT1     0x02
#define DDC_ACTIVE_PORT3     0x08
#define DDC_ACTIVE_PORT5     0x20
#define DDC_ACTIVE_PORT7     0x80

/* Event bits of a slave port (reg_i2c<N>_events); writing a bit to reg_i2c<N>_event_ack acknowledges it. */
#define DDC_EVENT_ADDRESSED  0x80  /* a transfer to this slave starts */
#define DDC_EVENT_SEND_BYTE  0x40  /* the slave needs the next byte to send */
#define DDC_EVENT_RECEIVED   0x20  /* a byte has arrived in reg_i2c<N>_rx_data */
#define DDC_EVENT_ACK_ALL    0xFF
#define DDC_STATUS_SENDING   0x80  /* reg_i2c<N>_status bit 7: this transfer reads from the slave */

/* The odd ports use their buffer row from the back: byte 0x3B first, counting down. */
#define DDC_ROW_LAST         0x3B
#define DDC_REQ_WRAP         0x39  /* request index after it reaches 1 */

/* irq_ext1_peripherals - external interrupt 1 (register bank 3).
 *
 * Serves, in this order, every source of interrupt 1 that has something pending:
 *   1. Remote control: when the capture interrupt fired for an enabled source, acknowledge it (write the enabled
 *      sources back to reg_capture_irq_flags) and let irq_record_ir_pulse store the pulse length.
 *   2. Serial port 4: move every received byte into uart_rx_ring_port4 (a 0x38-byte ring; received serial bytes go to
 *      the main processor as message type 3, docs/MAILBOX.md).
 *   3. DP AUX: dp_aux_service serves pending AUX requests of both DP receivers.
 *   4. The DDC/CI slaves of the odd ports 1, 3, 5 and 7 (the even ports are served by irq_ext0_ddc_slave).
 *
 * DDC/CI buffers: two ports share one 0x3C-byte row of ddc_request_buffers (what the computer writes) and of
 * ddc_reply_buffers (what it reads back): port 2k+1 uses row k from the back (index 0x3B downwards), its even
 * partner from the front. A reply runs from index 0x3B down to ddc_reply_end_index_port<N>, which message type 4
 * from the main processor sets. Every received request byte sets the port's bit in ddc_port_activity_flags;
 * ddc_rearm_idle_slaves clears it again.
 *
 * Each step that moves a byte also writes 0x55 to XDATA 0xF00A.
 */
void irq_ext1_peripherals(void) interrupt 2 using 3
{
    /* 1. Remote-control capture. */
    if (reg_irq_source_status & IRQ_SOURCE_CAPTURE) {
        if (reg_capture_irq_flags & irq_capture_enable_mask) {
            reg_capture_irq_flags = irq_capture_enable_mask;
            irq_record_ir_pulse();
        }
    }
    /* 2. Serial port 4: read bytes while status bit 0 is clear; the ring index wraps at the ring size. */
    if ((unsigned int)(reg_uart4_rx_irq_status & UART_RX_IRQ_PORT4)) {
        while (!(unsigned int)(reg_uart4_status & 0x01)) {
            uart_rx_ring_port4[uart_rx_write_index_port4++] = reg_uart4_rx_data;
            if (uart_rx_write_index_port4 >= UART_RX_RING_SIZE) uart_rx_write_index_port4 = 0;
            DAT_EXTMEM_f00a = 0x55;
        }
        /* Status bit 4 is written back when it is set. */
        if ((unsigned int)(reg_uart4_status & 0x10)) reg_uart4_status |= 0x10;
    }
    /* 3. DP AUX requests. */
    dp_aux_service();
    /* 4a. DDC/CI slave port 1 (row 0, from the back). */
    if (reg_irq_source_status & IRQ_SOURCE_DDC_PORT1) {
        if (reg_i2c1_events & DDC_EVENT_ADDRESSED) {
            reg_i2c1_event_ack = DDC_EVENT_ADDRESSED;
            if (reg_i2c1_status & DDC_STATUS_SENDING) {
                /* The computer reads: load the first reply byte, the next one comes from 0x3A. */
                reg_i2c1_event_ack = 0x44;
                reg_i2c1_tx_data = ddc_reply_buffers[DDC_ROW_LAST];
                reg_i2c1_mode = 0xc0;
                ddc_reply_index_port1 = 0x3a;
            } else {
                /* The computer writes: collect the request from the back of the row. */
                reg_i2c1_mode = 0xa0;
                reg_i2c1_ctrl |= 0x40;
                ddc_request_index_port1 = DDC_ROW_LAST;
                ddc_port_activity_flags |= DDC_ACTIVE_PORT1;
            }
        }
        /* Send the reply; at its end the last byte is sent again and the index goes back to the start. */
        while (reg_i2c1_events & DDC_EVENT_SEND_BYTE) {
            if (ddc_reply_index_port1 != ddc_reply_end_index_port1) {
                reg_i2c1_tx_data = ddc_reply_buffers[ddc_reply_index_port1--];
                reg_i2c1_event_ack = DDC_EVENT_SEND_BYTE;
            } else {
                reg_i2c1_tx_data = ddc_reply_buffers[ddc_reply_index_port1];
                reg_i2c1_event_ack = DDC_EVENT_SEND_BYTE;
                ddc_reply_index_port1 = DDC_ROW_LAST;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        /* Store request bytes; the index never runs below 2 (it wraps to 0x39). */
        while (reg_i2c1_events & DDC_EVENT_RECEIVED) {
            ddc_request_buffers[ddc_request_index_port1--] = reg_i2c1_rx_data;
            reg_i2c1_event_ack = DDC_EVENT_RECEIVED;
            ddc_port_activity_flags |= DDC_ACTIVE_PORT1;
            if (ddc_request_index_port1 <= 1) ddc_request_index_port1 = DDC_REQ_WRAP;
            DAT_EXTMEM_f00a = 0x55;
        }
        /* Events 4 and 3 are acknowledged together with everything else. */
        if (reg_i2c1_events & 0x10) reg_i2c1_event_ack = DDC_EVENT_ACK_ALL;
        if (reg_i2c1_events & 0x08) reg_i2c1_event_ack = DDC_EVENT_ACK_ALL;
    }
    /* 4b. Port 3 (row 1), same steps. */
    if (reg_irq_source_status & IRQ_SOURCE_DDC_PORT3) {
        if (reg_i2c3_events & DDC_EVENT_ADDRESSED) {
            reg_i2c3_event_ack = DDC_EVENT_ADDRESSED;
            if (reg_i2c3_status & DDC_STATUS_SENDING) {
                reg_i2c3_event_ack = 0x44;
                reg_i2c3_tx_data = ddc_reply_buffer_row1[DDC_ROW_LAST];
                reg_i2c3_mode = 0xc0;
                ddc_reply_index_port3 = 0x3a;
            } else {
                reg_i2c3_mode = 0xa0;
                reg_i2c3_ctrl |= 0x40;
                ddc_request_index_port3 = DDC_ROW_LAST;
                ddc_port_activity_flags |= DDC_ACTIVE_PORT3;
            }
        }
        while (reg_i2c3_events & DDC_EVENT_SEND_BYTE) {
            if (ddc_reply_index_port3 != ddc_reply_end_index_port3) {
                reg_i2c3_tx_data = ddc_reply_buffer_row1[ddc_reply_index_port3--];
                reg_i2c3_event_ack = DDC_EVENT_SEND_BYTE;
            } else {
                reg_i2c3_tx_data = ddc_reply_buffer_row1[ddc_reply_index_port3];
                reg_i2c3_event_ack = DDC_EVENT_SEND_BYTE;
                ddc_reply_index_port3 = DDC_ROW_LAST;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (reg_i2c3_events & DDC_EVENT_RECEIVED) {
            ddc_request_buffer_row1[ddc_request_index_port3--] = reg_i2c3_rx_data;
            reg_i2c3_event_ack = DDC_EVENT_RECEIVED;
            ddc_port_activity_flags |= DDC_ACTIVE_PORT3;
            if (ddc_request_index_port3 <= 1) ddc_request_index_port3 = DDC_REQ_WRAP;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (reg_i2c3_events & 0x10) reg_i2c3_event_ack = DDC_EVENT_ACK_ALL;
        if (reg_i2c3_events & 0x08) reg_i2c3_event_ack = DDC_EVENT_ACK_ALL;
    }
    /* 4c. Port 5 (row 2), same steps. */
    if (reg_irq_source_status & IRQ_SOURCE_DDC_PORT5) {
        if (reg_i2c5_events & DDC_EVENT_ADDRESSED) {
            reg_i2c5_event_ack = DDC_EVENT_ADDRESSED;
            if (reg_i2c5_status & DDC_STATUS_SENDING) {
                reg_i2c5_event_ack = 0x44;
                reg_i2c5_tx_data = ddc_reply_buffer_row2[DDC_ROW_LAST];
                reg_i2c5_mode = 0xc0;
                ddc_reply_index_port5 = 0x3a;
            } else {
                reg_i2c5_mode = 0xa0;
                reg_i2c5_ctrl |= 0x40;
                ddc_request_index_port5 = DDC_ROW_LAST;
                ddc_port_activity_flags |= DDC_ACTIVE_PORT5;
            }
        }
        while (reg_i2c5_events & DDC_EVENT_SEND_BYTE) {
            if (ddc_reply_index_port5 != ddc_reply_end_index_port5) {
                reg_i2c5_tx_data = ddc_reply_buffer_row2[ddc_reply_index_port5--];
                reg_i2c5_event_ack = DDC_EVENT_SEND_BYTE;
            } else {
                reg_i2c5_tx_data = ddc_reply_buffer_row2[ddc_reply_index_port5];
                reg_i2c5_event_ack = DDC_EVENT_SEND_BYTE;
                ddc_reply_index_port5 = DDC_ROW_LAST;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (reg_i2c5_events & DDC_EVENT_RECEIVED) {
            ddc_request_buffer_row2[ddc_request_index_port5--] = reg_i2c5_rx_data;
            reg_i2c5_event_ack = DDC_EVENT_RECEIVED;
            ddc_port_activity_flags |= DDC_ACTIVE_PORT5;
            if (ddc_request_index_port5 <= 1) ddc_request_index_port5 = DDC_REQ_WRAP;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (reg_i2c5_events & 0x10) reg_i2c5_event_ack = DDC_EVENT_ACK_ALL;
        if (reg_i2c5_events & 0x08) reg_i2c5_event_ack = DDC_EVENT_ACK_ALL;
    }
    /* 4d. Port 7 (row 3), same steps; its interrupt flag sits in its own status register. */
    if ((unsigned int)(reg_i2c7_irq_status & IRQ_SOURCE_DDC_PORT7)) {
        if (reg_i2c7_events & DDC_EVENT_ADDRESSED) {
            reg_i2c7_event_ack = DDC_EVENT_ADDRESSED;
            if (reg_i2c7_status & DDC_STATUS_SENDING) {
                reg_i2c7_event_ack = 0x44;
                reg_i2c7_tx_data = ddc_reply_buffer_row3[DDC_ROW_LAST];
                reg_i2c7_mode = 0xc0;
                ddc_reply_index_port7 = 0x3a;
            } else {
                reg_i2c7_mode = 0xa0;
                reg_i2c7_ctrl |= 0x40;
                ddc_request_index_port7 = DDC_ROW_LAST;
                ddc_port_activity_flags |= DDC_ACTIVE_PORT7;
            }
        }
        while (reg_i2c7_events & DDC_EVENT_SEND_BYTE) {
            if (ddc_reply_index_port7 != ddc_reply_end_index_port7) {
                reg_i2c7_tx_data = ddc_reply_buffer_row3[ddc_reply_index_port7--];
                reg_i2c7_event_ack = DDC_EVENT_SEND_BYTE;
            } else {
                reg_i2c7_tx_data = ddc_reply_buffer_row3[ddc_reply_index_port7];
                reg_i2c7_event_ack = DDC_EVENT_SEND_BYTE;
                ddc_reply_index_port7 = DDC_ROW_LAST;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (reg_i2c7_events & DDC_EVENT_RECEIVED) {
            ddc_request_buffer_row3[ddc_request_index_port7--] = reg_i2c7_rx_data;
            reg_i2c7_event_ack = DDC_EVENT_RECEIVED;
            ddc_port_activity_flags |= DDC_ACTIVE_PORT7;
            if (ddc_request_index_port7 <= 1) ddc_request_index_port7 = DDC_REQ_WRAP;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (reg_i2c7_events & 0x10) reg_i2c7_event_ack = DDC_EVENT_ACK_ALL;
        if (reg_i2c7_events & 0x08) reg_i2c7_event_ack = DDC_EVENT_ACK_ALL;
    }
}
