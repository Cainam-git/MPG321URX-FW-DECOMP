/* uart_cmd_get_screen_size  (FUN_a00bcecc)
 *
 * Report the Screen Size to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 58002:0 (get row 0x22); reply 5b002:0 + three digits.
 * Name basis: proven - get frame 58002:0; settings byte +0x1A4 (osd_draw_screen_size_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bcecc @ 0xa00bcecc-0xa00bd070 (420 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: an if/else chain tested in the order 0, 1, 2, 4, 3, 5, 6.
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char user_settings_screen_size;
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_SCREEN_SIZE 0x22   /* get row 002:0: frame "58002:0" + CR */
#define GET_REPLY_LENGTH    11     /* "5b" + 5-character id + 3 value characters + CR */

/* Screen Size settings, in the order of the menu list (Auto, 4:3, 16:9, 16:10, 1:1, 24.5", 27"). */
enum {
    SCREEN_SIZE_INPUT_ASPECT = 0,   /* Auto */
    SCREEN_SIZE_4_3          = 1,
    SCREEN_SIZE_16_9         = 2,
    SCREEN_SIZE_16_10        = 3,
    SCREEN_SIZE_1_1          = 4,
    SCREEN_SIZE_24_5_INCH    = 5,
    SCREEN_SIZE_27_INCH      = 6
};

/*
 * Answer the get frame "58002:0" with the Screen Size (user settings byte +0x1A4) as "5b002:0" + "00" + one
 * digit + CR. Called by uart_cmd_dispatch_get for get row 0x22.
 *
 *   port  the command port the frame came in on (the only caller of uart_cmd_dispatch_get passes 4)
 *
 * The PC tool numbers the sizes its own way: Auto 0, 4:3 1, 16:9 2, 1:1 3, 16:10 5, 24.5" 7, 27" 8 (4 and 6 are
 * never sent). A setting outside 0..6 is sent as 0.
 *
 * As in the other get routines, the answer is always built in uart_cmd_tx_frame and the port decides which
 * receive record is cleared (the body of uart_cmd_clear_rx) and where the answer is sent.
 */
void uart_cmd_get_screen_size(unsigned char port)
{
    unsigned char tool_value = 0;

    if (user_settings_screen_size == SCREEN_SIZE_INPUT_ASPECT)
        tool_value = 0;
    else if (user_settings_screen_size == SCREEN_SIZE_4_3)
        tool_value = 1;
    else if (user_settings_screen_size == SCREEN_SIZE_16_9)
        tool_value = 2;
    else if (user_settings_screen_size == SCREEN_SIZE_1_1)
        tool_value = 3;
    else if (user_settings_screen_size == SCREEN_SIZE_16_10)
        tool_value = 5;
    else if (user_settings_screen_size == SCREEN_SIZE_24_5_INCH)
        tool_value = 7;
    else if (user_settings_screen_size == SCREEN_SIZE_27_INCH)
        tool_value = 8;
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = tool_value + '0';
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_SCREEN_SIZE, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_SCREEN_SIZE, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_SCREEN_SIZE, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_SCREEN_SIZE, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_SCREEN_SIZE, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_SCREEN_SIZE, 6);
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
