/* uart_cmd_get_pip_source  (FUN_a00bee64)
 *
 * Report the PIP source to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800610 (get row 0x34); reply 5b00610 + three digits.
 * Name basis: derived - get frame 5800610; settings byte +0x20 (osd_enter_pip_source_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bee64 @ 0xa00bee64-0xa00bef90 (75 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record clears are written in ascending offset order (0, 1, 7, 10, 0x19) in all three arms
 * (as in uart_cmd_get_pbp_source1).
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char user_settings_second_source;        /* user settings byte +0x20: a source id */
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_PIP_SOURCE  0x34    /* row of uart_cmd_get_rows: "5800610" */
#define GET_REPLY_LENGTH    11      /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800610" with the PIP source, the source of the second picture (user settings byte
 * +0x20), as '0', '0' and its menu index. input_api_source_id_to_menu_index turns the stored source id into the menu
 * index (6 -> 1, 5 -> 0, 0xD -> 3, 0xC -> 2); any other id gives 0xFF, which goes out as '/' (0xFF + '0' in a
 * byte).
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. Bytes 7..9 of uart_cmd_tx_frame get the value.
 *   2. The reply head: bytes 0 and 2..6 are copied from the table row ('5' and the id "00610"), byte 1 is 'b',
 *      byte 10 is CR.
 *   3. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   4. GET_REPLY_LENGTH bytes go out on `port`.
 * uart_cmd_get_pbp_source2 (row 0x36) and uart_cmd_get_second_source (row 0x37) send the same value.
 */
void uart_cmd_get_pip_source(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = input_api_source_id_to_menu_index(user_settings_second_source) + '0';
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_PIP_SOURCE, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_PIP_SOURCE, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_PIP_SOURCE, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_PIP_SOURCE, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_PIP_SOURCE, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_PIP_SOURCE, 6);
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
