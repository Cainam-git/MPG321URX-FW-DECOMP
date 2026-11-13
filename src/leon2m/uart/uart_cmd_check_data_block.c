/* uart_cmd_check_data_block  (FUN_a00cbe9c)
 *
 * Check the byte sum of a 12-byte data block from the PC tool and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0
 * Note: Command 5b001i (26-byte frame). Match: bit 2 of 0xA802AF44 set, '5600+'. Bad sum: '5600' + 0xEE goes
 *   into the port-4 reply frame whatever the port, so ports 2 and 3 send their own unchanged frame. The data
 *   is not stored.
 * Name basis: descriptive - set row 0x91; sum of bytes 6..17 against byte 18
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cbe9c @ 0xa00cbe9c-0xa00cc140 (169 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the receive-record byte getter rx_byte and the three port helpers are defined in this file, so GCC inlines
 *    them at -O3 and unswitches the summing loop per port;
 *  - the loop counter and the sum are unsigned chars.
 */

#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r", and the error reply "5600" 0xEE "\r" */
#define UART_REPLY_SUM_ERROR      0xee      /* fifth reply byte in place of '+' when the byte sum does not match */

/* The 26-byte frame of this row: data bytes 6..17, their 8-bit sum in byte 18. */
#define FRAME_DATA_FIRST          6
#define FRAME_DATA_END            0x12      /* one past the last data byte */
#define FRAME_SUM                 0x12

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern void sys_set_app_flag44_bit2(void);

/* Byte `index` of the port's receive record. */
static unsigned char rx_byte(unsigned char port, int index)
{
    unsigned char value;

    if (port == 2)
        value = uart_cmd_rx_record_port2[index];
    else if (port == 3)
        value = uart_cmd_rx_record_port3[index];
    else
        value = uart_cmd_rx_record[index];
    return value;
}
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern void osd_mark_settings_changed_copy(void);

/* Put the acknowledge "5600+\r" into the reply frame of the port. */
void uart_cmd_build_ok_reply(unsigned char port)
{
    if (port == 2) {
        uart_cmd_tx_frame_port2[0] = '5';
        uart_cmd_tx_frame_port2[1] = '6';
        uart_cmd_tx_frame_port2[2] = '0';
        uart_cmd_tx_frame_port2[3] = '0';
        uart_cmd_tx_frame_port2[4] = '+';
        uart_cmd_tx_frame_port2[5] = '\r';
    } else if (port == 3) {
        uart_cmd_tx_frame_port3[0] = '5';
        uart_cmd_tx_frame_port3[1] = '6';
        uart_cmd_tx_frame_port3[2] = '0';
        uart_cmd_tx_frame_port3[3] = '0';
        uart_cmd_tx_frame_port3[4] = '+';
        uart_cmd_tx_frame_port3[5] = '\r';
    } else {
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = '6';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = '+';
        uart_cmd_tx_frame[5] = '\r';
    }
}

/* Make the port ready for the next command: clear its receive state byte and bytes 0, 1, 7, 10 and 0x19 of its
   receive record. */
void uart_cmd_clear_rx(unsigned char port)
{
    if (port == 2) {
        uart_cmd_rx_state_port2 = 0;
        uart_cmd_rx_record_port2[0] = 0;
        uart_cmd_rx_record_port2[1] = 0;
        uart_cmd_rx_record_port2[7] = 0;
        uart_cmd_rx_record_port2[10] = 0;
        uart_cmd_rx_record_port2[0x19] = 0;
    } else if (port == 3) {
        uart_cmd_rx_state_port3 = 0;
        uart_cmd_rx_record_port3[0] = 0;
        uart_cmd_rx_record_port3[1] = 0;
        uart_cmd_rx_record_port3[7] = 0;
        uart_cmd_rx_record_port3[10] = 0;
        uart_cmd_rx_record_port3[0x19] = 0;
    } else {
        uart_cmd_rx_count = 0;
        uart_cmd_rx_record[0] = 0;
        uart_cmd_rx_record[1] = 0;
        uart_cmd_rx_record[7] = 0;
        uart_cmd_rx_record[10] = 0;
        uart_cmd_rx_record[0x19] = 0;
    }
}

/* Send the first `length` bytes of the port's reply frame through the 8051. */
void uart_cmd_send_tx_buffer(unsigned char port, unsigned char length)
{
    if (port == 2)
        uart_api_send_bytes(2, length, uart_cmd_tx_frame_port2);
    else if (port == 3)
        uart_api_send_bytes(3, length, uart_cmd_tx_frame_port3);
    else
        uart_api_send_bytes(port, length, uart_cmd_tx_frame);
}

/*
 * Set row 0x91 (145, row id 001i, 26-byte frame) of uart_cmd_dispatch_set: check the 8-bit byte sum of the 12
 * data bytes the PC tool sent and, when it is right, request that the part record is written to the settings
 * memory.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 in every case; the result of the check is only in the reply.
 *
 * Phases:
 *   1. Add frame bytes 6..17 as an 8-bit sum and compare it with frame byte 18. The data bytes themselves are not
 *      used or kept.
 *   2. Sum right: build the "5600+\r" reply and set APP_FLAG44_STORE_MODES_0 (sys_set_app_flag44_bit2); the
 *      one-second step of sys_run_app_timer_task then calls nvram_api_store_by_selector(0).
 *      Sum wrong: write "5600" 0xEE "\r" into uart_cmd_tx_frame. That is the reply frame of the ports other than
 *      2 and 3; on ports 2 and 3 the frame sent below is the port's own, which this routine has not written.
 *   3. Clear the port's receive state and send the 6-byte reply frame.
 */
int uart_cmd_check_data_block(unsigned char port)
{
    unsigned char i;
    unsigned char sum = 0;

    /* Phase 1. */
    for (i = FRAME_DATA_FIRST; i < FRAME_DATA_END; i++)
        sum += rx_byte(port, i);

    /* Phase 2. */
    if (sum == rx_byte(port, FRAME_SUM)) {
        uart_cmd_build_ok_reply(port);
        sys_set_app_flag44_bit2();
    } else {
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = '6';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = UART_REPLY_SUM_ERROR;
        uart_cmd_tx_frame[5] = '\r';
    }

    /* Phase 3. */
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
