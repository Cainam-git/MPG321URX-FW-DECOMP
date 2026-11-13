/* uart_cmd_get_power_state  (FUN_a00be9a8)
 *
 * Report the power state to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800100 (get row 0x00); reply 5b00100 + three digits.
 * Name basis: descriptive - get: '1' when the channel 0 state code is non-zero; set: '0' is refused while that
 *   code is 0, '1' while the power status bit is set
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00be9a8 @ 0xa00be9a8-0xa00beae0 (78 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record clears are written in ascending offset order (0, 1, 7, 10, 0x19) in all three arms;
 * byte 9 is stored in an if/else (a ?: expression gives an addx sequence).
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char sys_api_get_channel_state_code(int);
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);     /* declared, not called here */
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_POWER_STATE  0x00   /* row of uart_cmd_get_rows: "5800100" */
#define GET_REPLY_LENGTH     11     /* "5b" + 5-character id + 3 value characters + CR */
#define MAIN_CHANNEL         0

/*
 * Answer the get command "5800100" with the power state as "001" or "000": '1' when the state code of channel 0
 * (sys_api_get_channel_state_code) is not 0, '0' when it is 0 (raw channel state 0). The set command
 * (uart_cmd_set_power_state) refuses the value 0 while this code is 0.
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. Bytes 7..9 of uart_cmd_tx_frame get the value.
 *   2. The reply head: bytes 0 and 2..6 are copied from the table row ('5' and the id "00100"), byte 1 is 'b',
 *      byte 10 is CR.
 *   3. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   4. GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_power_state(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    if (sys_api_get_channel_state_code(MAIN_CHANNEL))
        uart_cmd_tx_frame[9] = '1';
    else
        uart_cmd_tx_frame[9] = '0';
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_POWER_STATE, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_POWER_STATE, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_POWER_STATE, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_POWER_STATE, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_POWER_STATE, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_POWER_STATE, 6);
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
