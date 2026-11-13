/* uart_cmd_set_alarm_clock_location  (FUN_a00c29d8)
 *
 * Set the Alarm Clock location from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00263; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00263; settings byte +0x13F (osd_open_alarm_clock_location)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c29d8 @ 0xa00c29d8-0xa00c2bd8 (128 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are defined in
 *    this file and inlined by GCC at -O3 (as in uart_cmd_set_transparency);
 *  - the sleep state test reads a 2-bit bit-field of the halfword (as in uart_cmd_set_crosshair_color).
 * The same code as uart_cmd_set_refresh_rate_location (uart_cmd_set_refresh_rate_location) except the byte written.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* byte 9 of a set frame: the one-character value */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define OVERLAY_LOCATION_MAX      4         /* OVERLAY_LOCATION_LEFT_TOP 0 / RIGHT_TOP 1 / LEFT_BOTTOM 2 /
                                               RIGHT_BOTTOM 3 / CUSTOMIZE 4 */
#define SLEEP_STATE_AWAKE         0         /* app_state_record sleep_state */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings_alarm_clock_location;
/* Halfword +4 of the application state record (app_state_record_sleep_word). */
struct app_state_sleep_word {
    unsigned short bit15 : 1;
    unsigned short sleep_state : 2;             /* bits 13..14: SLEEP_STATE_FAKE_SLEEP 2 */
    unsigned short rest : 13;
};
extern struct app_state_sleep_word app_state_record_sleep_word;
extern void osd_close_menu(void);
extern void osd_open_menu_state_0x106(void);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

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
 * Set row 53 of uart_cmd_dispatch_set (id 00263): the location of the Alarm Clock overlay (user settings byte
 * +0x13F).
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-".
 *
 * Phases:
 *   1. Frame byte 9 is the location as a character '0'..'4' (left top, right top, left bottom, right bottom,
 *      customize); any other character is refused.
 *   2. Store it. No settings save is requested here.
 *   3. While the sleep state is 0 the menu is closed and menu state 0x106, which draws the screen overlays, is
 *      opened.
 *   4. Reply "5600+\r", clear the port's receive record, send the reply.
 */
int uart_cmd_set_alarm_clock_location(unsigned char port)
{
    unsigned char value_char;
    unsigned short location;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    location = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)location > OVERLAY_LOCATION_MAX)
        return UART_CMD_REFUSED;
    /* Phase 2. */
    user_settings_alarm_clock_location = location;
    /* Phase 3. */
    if (app_state_record_sleep_word.sleep_state == SLEEP_STATE_AWAKE) {
        osd_close_menu();
        osd_open_menu_state_0x106();
    }
    /* Phase 4. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
