/* uart_cmd_get_refresh_rate  (FUN_a00bf538)
 *
 * Report the current refresh rate to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800170 (get row 0x32); reply 5b00170 + three digits.
 * Name basis: proven - get frame 5800170; input_user_get_rounded_refresh_rate
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bf538 @ 0xa00bf538-0xa00bf6b0 (94 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - as in uart_cmd_get_brightness (uart_cmd_get_brightness), the rate and its three digits are unsigned char locals of one
 *    inner block;
 *  - the reply head is filled call by call after the value bytes, and the receive-record clears (uart_cmd_clear_rx,
 *    written inline) stand in ascending offset order (0, 1, 7, 10, 0x19) in all three arms.
 */

#define GET_ROW           0x32      /* row of uart_cmd_get_rows: "5800170" CR */
#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   '0'       /* each digit is sent as the digit plus 0x30 */

extern unsigned char uart_cmd_tx_frame[11];
extern int input_user_get_rounded_refresh_rate(void);
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/*
 * Answer the get command "5800170" (row 0x32 of uart_cmd_get_rows) with the refresh rate of channel 0 in whole
 * hertz, as three decimal digits ("060", "144", ...). The rate is the one the on-screen refresh rate display
 * shows (input_user_get_rounded_refresh_rate); it is kept in one byte here, so the reply covers 0..255.
 *
 *   port  the command port the frame came in on; uart_cmd_dispatch_get passes it on. It selects the receive record
 *         to clear; the reply always goes out from uart_cmd_tx_frame.
 *
 * The reply is "5b" + the id of the row + the three digits + CR (character 1 is 'b' in place of the row's '8').
 * The port's receive state and record are then cleared and GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_refresh_rate(unsigned char port)
{
    {
        unsigned char rate = input_user_get_rounded_refresh_rate(), hundreds, rest, tens, ones;
        hundreds = rate / 100;
        rest = rate - hundreds * 100;
        tens = rest / 10;
        ones = rest - tens * 10;
        uart_cmd_tx_frame[7] = hundreds + VALUE_CHAR_BASE;
        uart_cmd_tx_frame[8] = tens + VALUE_CHAR_BASE;
        uart_cmd_tx_frame[9] = ones + VALUE_CHAR_BASE;
    }
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
