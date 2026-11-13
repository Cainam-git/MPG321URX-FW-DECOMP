/* uart_cmd_get_navi_key_left  (FUN_a00bd59c)
 *
 * Report the Navi Key left function to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800920 (get row 0x2a); reply 5b00920 + three digits.
 * Name basis: proven - get frame 5800920; settings byte +0x18C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bd59c @ 0xa00bd59c-0xa00bd6e4 (82 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record clears are written in ascending offset order (0, 1, 7, 10, 0x19) in all three arms;
 * the value is an unsigned char local of an inner block and the "above 9" arm comes first.
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char user_settings_navi_key_left;        /* user settings byte +0x18C */
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);     /* declared, not called here */
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_NAVI_KEY_LEFT  0x2a /* row of uart_cmd_get_rows: "5800920" */
#define GET_REPLY_LENGTH       11   /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800920" with the Navi Key left function (user settings byte +0x18C) as three
 * characters: '0', then the tens digit '0' or '1', then the ones digit.
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. Bytes 7..9 of uart_cmd_tx_frame get the value. Only one tens digit is handled: every value above 9 is sent
 *      as '1' and the value minus 10, so a value above 19 gives a character after '9' in byte 9.
 *   2. The reply head: bytes 0 and 2..6 are copied from the table row ('5' and the id "00920"), byte 1 is 'b',
 *      byte 10 is CR.
 *   3. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   4. GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_navi_key_left(unsigned char port)
{
    {
        unsigned char function = user_settings_navi_key_left;
        uart_cmd_tx_frame[7] = '0';
        if (function > 9) {
            uart_cmd_tx_frame[8] = '1';
            uart_cmd_tx_frame[9] = function - 10 + '0';
        } else {
            uart_cmd_tx_frame[8] = '0';
            uart_cmd_tx_frame[9] = function + '0';
        }
    }
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_NAVI_KEY_LEFT, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_NAVI_KEY_LEFT, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_NAVI_KEY_LEFT, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_NAVI_KEY_LEFT, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_NAVI_KEY_LEFT, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_NAVI_KEY_LEFT, 6);
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
