/* uart_cmd_get_port_status_flag  (FUN_a00bf3f8)
 *
 * Report the input port status flag to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800160 (get row 0x31); reply 5b00160 + three digits.
 * Name basis: descriptive - get frame 5800160; input_port_get_status_bit10 of port 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bf3f8 @ 0xa00bf3f8-0xa00bf538 (80 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - byte 9 is stored in an if/else (a ?: expression gives an addx sequence);
 *  - the reply head is filled call by call after the value bytes, and the receive-record clears (uart_cmd_clear_rx,
 *    written inline) stand in ascending offset order (0, 1, 7, 10, 0x19) in all three arms.
 */

#define GET_ROW           0x31      /* row of uart_cmd_get_rows: "5800160" CR */
#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

extern unsigned char uart_cmd_tx_frame[11];
extern int input_port_get_status_bit10(int);
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);     /* declared, not used */
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/*
 * Answer the get command "5800160" (row 0x31 of uart_cmd_get_rows) with "001" when bit 10 of the status halfword
 * of port record 0 is set (input_port_get_status_bit10(0) == 1), else "000".
 *
 *   port  the command port the frame came in on; uart_cmd_dispatch_get passes it on. It selects the receive record
 *         to clear; the reply always goes out from uart_cmd_tx_frame.
 *
 * The reply is "5b" + the id of the row + the three value characters + CR (character 1 is 'b' in place of the
 * row's '8'). The port's receive state and record are then cleared and GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_port_status_flag(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    if ((unsigned char)input_port_get_status_bit10(0) == 1)
        uart_cmd_tx_frame[9] = '1';
    else
        uart_cmd_tx_frame[9] = '0';
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW, 6);
    uart_cmd_tx_frame[10] = '\r';
    /* Forget the received frame (the code of uart_cmd_clear_rx). */
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
