/* uart_cmd_get_serial_number  (FUN_a00bd9d8)
 *
 * Report the serial number from the factory record to the PC tool in a 21-byte frame.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800130 (get row 0x2e); factory_record_serial_length characters from frame byte 7 on, CR at
 *   byte 0x14 (room for 13).
 * Name basis: proven - get frame 5800130; copies factory_record_serial (the text the factory menu draws after
 *   'SN:')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bd9d8 @ 0xa00bd9d8-0xa00bdb48 (92 words), flags -mcpu=v8 -O3 -g.
 */
extern unsigned char uart_cmd_tx_frame[0x25];
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
/* The start of the factory record: the serial number, a count followed by up to 0x12 characters (the text the
   factory information page shows after "SN:"). */
struct factory_record_serial {
    unsigned char byte_0x0, byte_0x1;
    unsigned char serial_length;    /* +0x02 */
    unsigned char serial[0x12];     /* +0x03 */
};
extern struct factory_record_serial factory_record;
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_FACTORY_RECORD  0x2e        /* row of uart_cmd_get_rows: "5800130" */
#define SERIAL_REPLY_FIRST      7           /* frame byte of the first serial character */
#define SERIAL_REPLY_END        0x14        /* frame byte of the CR */
#define SERIAL_REPLY_LENGTH     0x15        /* "5b" + 5-character id + 13 character places + CR */

/*
 * Answer the get command "5800130" with the serial number kept in the factory record.
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. The reply head: bytes 0 and 2..6 of uart_cmd_tx_frame are copied from the table row ('5' and the id
 *      "00130"), byte 1 is 'b'.
 *   2. serial_length characters of the serial are copied to the frame from byte 7 on. The frame has room for 13
 *      (bytes 7..0x13); the count is not checked, so with a longer serial the CR of step 3 overwrites the 14th
 *      character and the rest are not sent.
 *   3. Byte 0x14 is CR.
 *   4. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   5. SERIAL_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_serial_number(unsigned char port)
{
    unsigned char i;

    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_FACTORY_RECORD, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_FACTORY_RECORD, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_FACTORY_RECORD, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_FACTORY_RECORD, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_FACTORY_RECORD, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_FACTORY_RECORD, 6);
    for (i = 0; i < factory_record.serial_length; i++)
        uart_cmd_tx_frame[SERIAL_REPLY_FIRST + i] = factory_record.serial[i];
    uart_cmd_tx_frame[SERIAL_REPLY_END] = '\r';
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
    uart_api_send_bytes(port, SERIAL_REPLY_LENGTH, uart_cmd_tx_frame);
}
