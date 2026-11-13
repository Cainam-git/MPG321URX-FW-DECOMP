/* uart_cmd_get_osd_timeout  (FUN_a00bd328)
 *
 * Report the OSD Time out to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800820 (get row 0x27); reply 5b00820 + three digits.
 * Name basis: proven - get frame 5800820; settings byte +0xC (osd_open_timeout_slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bd328 @ 0xa00bd328-0xa00bd4a4 (95 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three digits are computed into unsigned char locals of one inner block and stored afterwards
 * (as in uart_cmd_get_brightness).
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char user_settings_osd_timeout;          /* user settings byte +0xC */
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_OSD_TIMEOUT  0x27   /* row of uart_cmd_get_rows: "5800820" */
#define GET_REPLY_LENGTH     11     /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800820" with the OSD Time out (user settings byte +0xC) as three decimal digits.
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. Bytes 7, 8 and 9 of uart_cmd_tx_frame get the hundreds, tens and ones digit of the value.
 *   2. The reply head: bytes 0 and 2..6 are copied from the table row ('5' and the id "00820"), byte 1 is 'b',
 *      byte 10 is CR.
 *   3. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   4. GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_osd_timeout(unsigned char port)
{
    {
        unsigned char value = user_settings_osd_timeout, hundreds, rest, tens, ones;
        hundreds = value / 100;
        rest = value - hundreds * 100;
        tens = rest / 10;
        ones = rest - tens * 10;
        uart_cmd_tx_frame[7] = hundreds + '0';
        uart_cmd_tx_frame[8] = tens + '0';
        uart_cmd_tx_frame[9] = ones + '0';
    }
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_OSD_TIMEOUT, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_OSD_TIMEOUT, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_OSD_TIMEOUT, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_OSD_TIMEOUT, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_OSD_TIMEOUT, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_OSD_TIMEOUT, 6);
    uart_cmd_tx_frame[10] = '\r';
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
    uart_api_send_bytes(port, GET_REPLY_LENGTH, uart_cmd_tx_frame);
}
