/* uart_cmd_get_resolution_code  (FUN_a00bf7dc)
 *
 * Report the input resolution code to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 58001;0 (get row 0x49); reply 5b001;0 + three digits.
 * Name basis: derived - get frame 58001;0; code from the active width/height pair (3840x2160 ...)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bf7dc @ 0xa00bf7dc-0xa00bfb28 (211 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - an if/else-if chain of (width == a && height == b) tests, one store of byte 9 per arm; GCC evaluates each
 *    pair as two flag values;
 *  - the reply head is filled call by call after the value bytes, and the receive-record clears (uart_cmd_clear_rx,
 *    written inline) stand in ascending offset order (0, 1, 7, 10, 0x19) in all three arms.
 */

#define GET_ROW           0x49      /* row of uart_cmd_get_rows: "58001;0" CR */
#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/* Fields of the measured input timing (input_api_get_timing_field). */
#define TIMING_WIDTH      7
#define TIMING_HEIGHT     8

extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern int input_api_get_timing_field(int, int);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/*
 * Answer the get command "58001;0" (row 0x49 of uart_cmd_get_rows) with a code for the size of the picture on
 * channel 0: "00" and one character '0' + code, code 0..15 (the characters after '9' are ':' ';' '<' '=' '>' '?').
 *
 *   port  the command port the frame came in on; uart_cmd_dispatch_get passes it on. It selects the receive record
 *         to clear; the reply always goes out from uart_cmd_tx_frame.
 *
 * Width and height are timing fields 7 and 8 of channel 0. The pairs are tested in the order below, largest code
 * first; a size not in the list gives code 0:
 *    15 '?' 5120 x 1440     11 ';' 2560 x 1080      7 '7' 1680 x 1050      3 '3' 1366 x 768
 *    14 '>' 3440 x 1440     10 ':' 2560 x 1440      6 '6' 1600 x 900       2 '2' 1280 x 1024
 *    13 '=' 3840 x 1080      9 '9' 1920 x 1200      5 '5' 1440 x 900       1 '1' 1024 x 768
 *    12 '<' 3840 x 2160      8 '8' 1920 x 1080      4 '4' 1440 x 1050      0 '0' any other size
 *
 * The reply is "5b" + the id of the row + the three value characters + CR (character 1 is 'b' in place of the
 * row's '8'). The port's receive state and record are then cleared and GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_resolution_code(unsigned char port)
{
    unsigned short width = input_api_get_timing_field(0, TIMING_WIDTH);
    unsigned short height = input_api_get_timing_field(0, TIMING_HEIGHT);

    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    if (width == 5120 && height == 1440)
        uart_cmd_tx_frame[9] = '?';
    else if (width == 3440 && height == 1440)
        uart_cmd_tx_frame[9] = '>';
    else if (width == 3840 && height == 1080)
        uart_cmd_tx_frame[9] = '=';
    else if (width == 3840 && height == 2160)
        uart_cmd_tx_frame[9] = '<';
    else if (width == 2560 && height == 1080)
        uart_cmd_tx_frame[9] = ';';
    else if (width == 2560 && height == 1440)
        uart_cmd_tx_frame[9] = ':';
    else if (width == 1920 && height == 1200)
        uart_cmd_tx_frame[9] = '9';
    else if (width == 1920 && height == 1080)
        uart_cmd_tx_frame[9] = '8';
    else if (width == 1680 && height == 1050)
        uart_cmd_tx_frame[9] = '7';
    else if (width == 1600 && height == 900)
        uart_cmd_tx_frame[9] = '6';
    else if (width == 1440 && height == 900)
        uart_cmd_tx_frame[9] = '5';
    else if (width == 1440 && height == 1050)
        uart_cmd_tx_frame[9] = '4';
    else if (width == 1366 && height == 768)
        uart_cmd_tx_frame[9] = '3';
    else if (width == 1280 && height == 1024)
        uart_cmd_tx_frame[9] = '2';
    else if (width == 1024 && height == 768)
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
