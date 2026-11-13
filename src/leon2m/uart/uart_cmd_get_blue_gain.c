/* uart_cmd_get_blue_gain  (FUN_a00bc6f0)
 *
 * Report the custom blue gain to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800433 (get row 0x09); reply 5b00433 + three digits.
 * Name basis: proven - get frame 5800433; settings byte +0x14 (osd_draw_blue_gain, pq_user_set_custom_blue)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bc6f0 @ 0xa00bc6f0-0xa00bc86c (95 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three digits are computed into unsigned char locals of one inner block and stored afterwards
 * (digit expressions written straight into the stores give other registers).
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char user_settings_blue_gain;
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_BLUE_GAIN 0x09    /* get row 00433: frame "5800433" + CR */
#define GET_REPLY_LENGTH 11      /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get frame "5800433" with the custom blue gain (user settings byte +0x14) as three decimal digits:
 * "5b00433" + hundreds, tens, units + CR. Called by uart_cmd_dispatch_get for get row 0x09.
 *
 *   port  the command port the frame came in on (the only caller of uart_cmd_dispatch_get passes 4)
 *
 * The answer is always built in uart_cmd_tx_frame, the reply frame of the port-4 tool link; the port decides
 * which receive record is cleared and where the answer is sent. The clear is the body of uart_cmd_clear_rx:
 * ports 2 and 3 clear their own count and record bytes 0, 1, 7, 10 and 0x19, every other port those of
 * uart_cmd_rx_count and uart_cmd_rx_record.
 */
void uart_cmd_get_blue_gain(unsigned char port)
{
    {
        unsigned char value = user_settings_blue_gain, hundreds, rest, tens, units;
        hundreds = value / 100;
        rest = value - hundreds * 100;
        tens = rest / 10;
        units = rest - tens * 10;
        uart_cmd_tx_frame[7] = hundreds + '0';
        uart_cmd_tx_frame[8] = tens + '0';
        uart_cmd_tx_frame[9] = units + '0';
    }
    /* "5", 'b' and the id of the get row, then the CR. */
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_BLUE_GAIN, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_BLUE_GAIN, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_BLUE_GAIN, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_BLUE_GAIN, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_BLUE_GAIN, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_BLUE_GAIN, 6);
    uart_cmd_tx_frame[10] = '\r';
    /* Forget the received frame. */
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
