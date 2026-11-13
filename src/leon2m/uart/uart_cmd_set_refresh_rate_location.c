/* uart_cmd_set_refresh_rate_location  (FUN_a00c3180)
 *
 * Set the Refresh Rate display location from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00251; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00251; settings byte +0x13E (osd_open_refresh_rate_location)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c3180 @ 0xa00c3180-0xa00c3380 (128 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested as an unsigned char;
 *  - the sleep state is a 2-bit bit-field of the halfword app_state_record_sleep_word.
 * Same code as uart_cmd_set_alarm_clock_location (uart_cmd_set_alarm_clock_location) except the byte written.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */

/* Overlay locations, in the order of the location list of the menu. */
enum {
    OVERLAY_LOCATION_LEFT_TOP     = 0,
    OVERLAY_LOCATION_RIGHT_TOP    = 1,
    OVERLAY_LOCATION_LEFT_BOTTOM  = 2,
    OVERLAY_LOCATION_RIGHT_BOTTOM = 3,
    OVERLAY_LOCATION_CUSTOMIZE    = 4       /* the refresh_rate_custom_x / _y position */
};

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings_refresh_rate_location;
/* Application state halfword +4. */
struct app_state_sleep_word {
    unsigned short bit15 : 1;
    unsigned short sleep_state : 2;             /* bits 13..14; 2 = fake sleep */
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
 * Set row 0x31 (49, row id 00251) of uart_cmd_dispatch_set: set the location of the Refresh Rate overlay from a
 * frame of MSI's PC tool.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value above 4; then nothing
 * has changed and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the location from frame byte 9 (location plus 0x30): 0 left top, 1 right top, 2 left bottom,
 *      3 right bottom, 4 customize.
 *   2. Store it (settings byte +0x13E). When the sleep state is 0, close the menu and open menu state 0x106
 *      (MENU_STATE_SCREEN_OVERLAYS), which draws the screen overlays again.
 *   3. Reply "5600+\r". No settings save is requested here.
 */
int uart_cmd_set_refresh_rate_location(unsigned char port)
{
    unsigned char value_char;
    unsigned short location;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    location = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)location > OVERLAY_LOCATION_CUSTOMIZE)
        return UART_CMD_REFUSED;

    /* Phase 2. */
    user_settings_refresh_rate_location = location;
    if (app_state_record_sleep_word.sleep_state == 0) {
        osd_close_menu();
        osd_open_menu_state_0x106();
    }

    /* Phase 3. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
