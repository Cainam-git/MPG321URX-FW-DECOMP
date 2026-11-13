/* uart_cmd_get_pro_mode  (FUN_a00bd070)
 *
 * Report the Professional mode to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800300 (get row 0x23); reply 5b00300 + three digits.
 * Name basis: proven - get frame 5800300; settings byte +0x181; set uses UserSetProMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bd070 @ 0xa00bd070-0xa00bd244 (117 words), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with one case per value (jump table switchdataD_a00ba3e8); case 7 is written first, which
 * makes it the block that follows the jump. The function covers its case blocks up to 0xa00bd244.
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char user_settings_pro_mode;             /* user settings byte +0x181 */
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_PRO_MODE  0x23      /* row of uart_cmd_get_rows: "5800300" */
#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800300" with the Professional mode (user settings byte +0x181) as '0', '0' and one
 * digit.
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. Bytes 7..9 of uart_cmd_tx_frame get the value. Only the values 0..7 have a case; for any other value byte 9
 *      keeps what the previous reply left there.
 *   2. The reply head: bytes 0 and 2..6 are copied from the table row ('5' and the id "00300"), byte 1 is 'b',
 *      byte 10 is CR.
 *   3. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   4. GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_pro_mode(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    switch (user_settings_pro_mode) {
    case 7:                         /* first: see the matching notes */
        uart_cmd_tx_frame[9] = '7';
        break;
    case 0:
        uart_cmd_tx_frame[9] = '0';
        break;
    case 1:
        uart_cmd_tx_frame[9] = '1';
        break;
    case 2:
        uart_cmd_tx_frame[9] = '2';
        break;
    case 3:
        uart_cmd_tx_frame[9] = '3';
        break;
    case 4:
        uart_cmd_tx_frame[9] = '4';
        break;
    case 5:
        uart_cmd_tx_frame[9] = '5';
        break;
    case 6:
        uart_cmd_tx_frame[9] = '6';
        break;
    }
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_PRO_MODE, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_PRO_MODE, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_PRO_MODE, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_PRO_MODE, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_PRO_MODE, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_PRO_MODE, 6);
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
