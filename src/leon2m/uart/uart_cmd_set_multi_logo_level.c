/* uart_cmd_set_multi_logo_level  (FUN_a00cb1c8)
 *
 * Set the Multi Logo Detection level from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00;51; digit 0..2 stored + 1; returns 0xFF for a bad value (the task then replies 5600-),
 *   else 0 after '5600+'.
 * Name basis: proven - set frame 5b00;51; settings byte +0x1E9
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cb1c8 @ 0xa00cb1c8-0xa00cb3a8 (120 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3, which repeats the port test in
 *    each of them;
 *  - the received character is read into an unsigned char and widened into an unsigned int (value) before the
 *    range test; the range test uses an unsigned short difference tested as an unsigned char, and the stored level
 *    is computed from the widened copy (value - 0x2f).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define DETECTION_TOOL_LEVEL_MAX  2         /* tool values 0..2 = stored levels 1..3 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings_multi_logo_level;
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern void oled_user_apply_multi_logo(void);
extern void osd_mark_settings_changed_copy(void);

/* Put the acknowledge "5600+\r" into the reply frame of the port. */
void uart_cmd_build_ok_reply(unsigned char port)
{
    if (port == 2) {
        uart_cmd_tx_frame_port2[0] = '5';
        uart_cmd_tx_frame_port2[1] = '6';
        uart_cmd_tx_frame_port2[2] = '0';
        uart_cmd_tx_frame_port2[3] = '0';
        uart_cmd_tx_frame_port2[4] = '+';
        uart_cmd_tx_frame_port2[5] = '\r';
    } else if (port == 3) {
        uart_cmd_tx_frame_port3[0] = '5';
        uart_cmd_tx_frame_port3[1] = '6';
        uart_cmd_tx_frame_port3[2] = '0';
        uart_cmd_tx_frame_port3[3] = '0';
        uart_cmd_tx_frame_port3[4] = '+';
        uart_cmd_tx_frame_port3[5] = '\r';
    } else {
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = '6';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = '+';
        uart_cmd_tx_frame[5] = '\r';
    }
}

/* Make the port ready for the next command: clear its receive state byte and bytes 0, 1, 7, 10 and 0x19 of its
   receive record. */
void uart_cmd_clear_rx(unsigned char port)
{
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
}

/* Send the first `length` bytes of the port's reply frame through the 8051. */
void uart_cmd_send_tx_buffer(unsigned char port, unsigned char length)
{
    if (port == 2)
        uart_api_send_bytes(2, length, uart_cmd_tx_frame_port2);
    else if (port == 3)
        uart_api_send_bytes(3, length, uart_cmd_tx_frame_port3);
    else
        uart_api_send_bytes(port, length, uart_cmd_tx_frame);
}

/*
 * Set row 0x82 (130, row id 00;51) of uart_cmd_dispatch_set: set the Multi Logo Detection level from a frame of
 * the PC tool and apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value above 2; then nothing
 * has changed and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the value from frame byte 9 (value plus 0x30).
 *   2. Store value + 1 as the level (settings byte +0x1E9), apply it (oled_user_apply_multi_logo, which sends 0
 *      while the detection is off) and request that the settings are saved.
 *   3. Reply "5600+\r".
 * The get command (uart_cmd_get_multi_logo_level) reports the level minus 1, so both use the tool values 0..2.
 * The menu slider of this level runs 1..2 (osd_get_detection_field); tool value 2 stores level 3.
 */
int uart_cmd_set_multi_logo_level(unsigned char port)
{
    unsigned char value_char;
    unsigned int value;
    unsigned short tool_level;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    value = value_char;
    tool_level = value - VALUE_CHAR_BASE;
    if ((unsigned char)tool_level > DETECTION_TOOL_LEVEL_MAX)
        return UART_CMD_REFUSED;

    /* Phase 2: the stored level is the tool value plus 1. */
    user_settings_multi_logo_level = value - (VALUE_CHAR_BASE - 1);
    oled_user_apply_multi_logo();
    osd_mark_settings_changed_copy();

    /* Phase 3. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
