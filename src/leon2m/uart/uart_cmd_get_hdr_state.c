/* uart_cmd_get_hdr_state  (FUN_a00bf6b0)
 *
 * Report the HDR state to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800190 (get row 0x3f); reply 5b00190 + three digits.
 * Name basis: derived - get frame 5800190; sys_user_get_picture_state, which the info box prints as
 *   'HDR'/'SDR'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bf6b0 @ 0xa00bf6b0-0xa00bf7dc (75 words), flags -mcpu=v8 -O3 -g.
 * Source form: the reply head is filled call by call after the value bytes, and the receive-record clears
 * (uart_cmd_clear_rx, written inline) stand in ascending offset order (0, 1, 7, 10, 0x19) in all three arms.
 */

#define GET_ROW           0x3f      /* row of uart_cmd_get_rows: "5800190" CR */
#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   '0'       /* a one-digit value is sent as the value plus 0x30 */

extern unsigned char uart_cmd_tx_frame[11];
extern int sys_user_get_picture_state(void);
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);     /* declared, not used */
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/*
 * Answer the get command "5800190" (row 0x3F of uart_cmd_get_rows) with "001" when the picture state
 * (sys_user_get_picture_state) is non-zero, else "000". The Info. On Screen box shows "HDR" for a non-zero
 * picture state and "SDR" for 0 (osd_draw_info_box_values), so '1' here stands for HDR.
 *
 *   port  the command port the frame came in on; uart_cmd_dispatch_get passes it on. It selects the receive record
 *         to clear; the reply always goes out from uart_cmd_tx_frame.
 *
 * The reply is "5b" + the id of the row + the three value characters + CR (character 1 is 'b' in place of the
 * row's '8'). The port's receive state and record are then cleared and GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_hdr_state(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (sys_user_get_picture_state() != 0) + VALUE_CHAR_BASE;
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
