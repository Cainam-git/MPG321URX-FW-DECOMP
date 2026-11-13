/* uart_cmd_write_factory_record  (FUN_a00cc140)
 *
 * Store a factory record block from the PC tool after checking its byte sum.
 *   port: command port (2, 3 or 4)
 * Returns: 0 in every case
 * Note: Command 5b001j; bytes go to 0xA802D277 (factory record + 3) and are saved at EEPROM 0x2E0; a bad byte
 *   sum is reported by the reply '5600' + 0xEE only on port 4, ports 2 and 3 send their old frame.
 * Name basis: derived - set row 0x92; SYSAPI_WriteEEPROM of the factory record 0xA802D274
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cc140 @ 0xa00cc140-0xa00cc760 (392 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the receive-record byte reader (rx_byte) and the three port helpers are defined in this file, so GCC
 *    inlines them at -O3 and each copy repeats the port test;
 *  - the copy is 13 separate statements; the sum is a loop with an unsigned char counter, which GCC unswitches
 *    per port;
 *  - the error reply is written into uart_cmd_tx_frame for every port.
 */

#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r", and the error reply "5600" 0xEE "\r" */
#define UART_REPLY_SUM_ERROR      0xee      /* fifth reply byte in place of '+' when the byte sum does not match */

/* The 26-byte frame of this row: data bytes 6..18, their 8-bit sum in byte 19. */
#define FRAME_DATA_FIRST          6
#define FRAME_DATA_END            0x13      /* one past the last data byte */
#define FRAME_SUM                 0x13

/* SYSAPI_WriteEEPROM: the one area code it knows, and where the factory record lies in that area. */
#define EEPROM_AREA               0x30
#define FACTORY_RECORD_OFFSET     0x2e0
#define FACTORY_RECORD_SIZE       0x1c

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The factory record (0xA802D274, 0x1C bytes). From +2 it starts with the serial number: a length byte, then the
   characters from +3 on (the factory information page draws them after "SN:"). */
extern unsigned char factory_record[];
extern int SYSAPI_WriteEEPROM(int, void *, int, int);

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
 * Set row 0x92 (146, row id 001j, 26-byte frame) of uart_cmd_dispatch_set: write 13 bytes from the PC tool into
 * the factory record, from +3 on (the first 13 characters of the serial number), and save the record when the
 * frame's byte sum is right.
 *
 *   port  the command port the frame came in on (2, 3 or another; uart_cmd_run_tool_task passes 4); it selects
 *         the receive record and the reply frame
 *
 * Returns 0 in every case; the result of the check is only in the reply.
 *
 * Phases:
 *   1. Copy frame bytes 6..18 to factory record +3..+0xF. This happens before the check, so after a bad sum the
 *      record in memory still holds the new bytes; they are only not saved.
 *   2. Add frame bytes 6..18 as an 8-bit sum and compare it with frame byte 19.
 *   3. Sum right: build the "5600+\r" reply and save the whole factory record (0x1C bytes at EEPROM offset
 *      0x2E0). Sum wrong: write "5600" 0xEE "\r" into uart_cmd_tx_frame. That is the reply frame of the ports
 *      other than 2 and 3; on ports 2 and 3 the frame sent below is the port's own, which this routine has not
 *      written.
 *   4. Clear the port's receive state and send the 6-byte reply frame.
 */
int uart_cmd_write_factory_record(unsigned char port)
{
    unsigned char i;
    unsigned char sum = 0;

    /* Phase 1: frame bytes 6..18 -> factory record +3..+0xF. */
    factory_record[3] = rx_byte(port, 6);
    factory_record[4] = rx_byte(port, 7);
    factory_record[5] = rx_byte(port, 8);
    factory_record[6] = rx_byte(port, 9);
    factory_record[7] = rx_byte(port, 10);
    factory_record[8] = rx_byte(port, 11);
    factory_record[9] = rx_byte(port, 12);
    factory_record[10] = rx_byte(port, 13);
    factory_record[11] = rx_byte(port, 14);
    factory_record[12] = rx_byte(port, 15);
    factory_record[13] = rx_byte(port, 16);
    factory_record[14] = rx_byte(port, 17);
    factory_record[15] = rx_byte(port, 18);

    /* Phase 2: the byte sum. */
    for (i = FRAME_DATA_FIRST; i < FRAME_DATA_END; i++)
        sum += rx_byte(port, i);

    /* Phase 3: save, or report the bad sum. */
    if (sum == rx_byte(port, FRAME_SUM)) {
        uart_cmd_build_ok_reply(port);
        SYSAPI_WriteEEPROM(EEPROM_AREA, factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    } else {
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = '6';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = UART_REPLY_SUM_ERROR;
        uart_cmd_tx_frame[5] = '\r';
    }

    /* Phase 4: reply. */
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
