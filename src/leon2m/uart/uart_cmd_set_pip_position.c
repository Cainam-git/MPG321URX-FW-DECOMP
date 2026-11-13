/* uart_cmd_set_pip_position  (FUN_a00c8c38)
 *
 * Set the PIP window position from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b006<; two 4-digit numbers limited by the panel size; no digit is checked; returns 0xFF only
 *   while PIP/PBP is off.
 * Name basis: derived - set frame 5b006<?; two 4-digit numbers limited by the panel size, then
 *   sys_user_resize_window_channel1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c8c38 @ 0xa00c8c38-0xa00c91dc (361 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - rx_byte() and the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - each number is one expression: four rx_byte() calls weighted 1000 / 100 / 10 / 1, minus '0' * 1111;
 *  - each limit calls panel_api_get_active_size twice (for the test and for the store).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */

#define FRAME_X_DIGITS            6         /* frame bytes 6..9: x, four decimal digits */
#define FRAME_Y_DIGITS            10        /* frame bytes 10..13: y, four decimal digits */

#define PIP_PBP_OFF               0         /* user_settings.pip_pbp_mode */

/* panel_api_get_active_size selectors. */
#define PANEL_SIZE_WIDTH          0
#define PANEL_SIZE_HEIGHT         1

/* PIP window size of each pip_size value, in pixels and lines. */
#define PIP_SIZE0_WIDTH           1728
#define PIP_SIZE0_LINES           972
#define PIP_SIZE1_WIDTH           1344
#define PIP_SIZE1_LINES           756
#define PIP_SIZE2_WIDTH           960
#define PIP_SIZE2_LINES           540

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 off, 1 PIP, 2 PBP */
    unsigned char pad020[0x31 - 0x20];
    unsigned char pip_size;                     /* +0x31: 0, 1 or 2 */
    unsigned char pad032[0x54 - 0x32];
    unsigned short pip_custom_x;                /* +0x54: left edge of the PIP window */
    unsigned short pip_custom_y;                /* +0x56: top edge of the PIP window */
};
extern struct user_settings_record user_settings;
extern unsigned short panel_api_get_active_size(int);
extern void sys_user_resize_window_channel1(int);

/* Byte `index` of the port's receive record. */
static unsigned char rx_byte(unsigned char port, int index)
{
    unsigned char frame_byte;

    if (port == 2)
        frame_byte = uart_cmd_rx_record_port2[index];
    else if (port == 3)
        frame_byte = uart_cmd_rx_record_port3[index];
    else
        frame_byte = uart_cmd_rx_record[index];
    return frame_byte;
}
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
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
 * Set row 0x93 (147) of uart_cmd_dispatch_set, the 26-byte frame "5b006<": set the position of the PIP window
 * from one frame of the PC tool.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns UART_CMD_REFUSED (0xFF) while PIP/PBP is off (the dispatcher then answers "5600-"); otherwise 0
 * after the "5600+" reply has been sent. The digits themselves are not checked.
 *
 * Phases:
 *   1. Refuse when the PIP/PBP mode is off.
 *   2. x from frame bytes 6..9 and y from bytes 10..13, each four decimal digits, most significant first;
 *      stored in pip_custom_x / pip_custom_y.
 *   3. Limit both so that the window of the current PIP size stays inside the active panel size: x to the
 *      panel width minus the window width, y to the panel height minus the window height.
 *   4. Recompute the window of channel 1 (sys_user_resize_window_channel1(1)), request a save and reply
 *      "5600+\r".
 */
int uart_cmd_set_pip_position(unsigned char port)
{
    unsigned short x, y;

    /* Phase 1. */
    if (user_settings.pip_pbp_mode == PIP_PBP_OFF)
        return UART_CMD_REFUSED;

    /* Phase 2. */
    x = rx_byte(port, FRAME_X_DIGITS) * 1000 + rx_byte(port, FRAME_X_DIGITS + 1) * 100
        + rx_byte(port, FRAME_X_DIGITS + 2) * 10 + rx_byte(port, FRAME_X_DIGITS + 3) - '0' * 1111;
    y = rx_byte(port, FRAME_Y_DIGITS) * 1000 + rx_byte(port, FRAME_Y_DIGITS + 1) * 100
        + rx_byte(port, FRAME_Y_DIGITS + 2) * 10 + rx_byte(port, FRAME_Y_DIGITS + 3) - '0' * 1111;
    user_settings.pip_custom_x = x;
    user_settings.pip_custom_y = y;

    /* Phase 3: keep the window on the panel. */
    if (user_settings.pip_size == 0) {
        if (user_settings.pip_custom_x > panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE0_WIDTH)
            user_settings.pip_custom_x = panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE0_WIDTH;
        if (user_settings.pip_custom_y > panel_api_get_active_size(PANEL_SIZE_HEIGHT) - PIP_SIZE0_LINES)
            user_settings.pip_custom_y = panel_api_get_active_size(PANEL_SIZE_HEIGHT) - PIP_SIZE0_LINES;
    } else if (user_settings.pip_size == 1) {
        if (user_settings.pip_custom_x > panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE1_WIDTH)
            user_settings.pip_custom_x = panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE1_WIDTH;
        if (user_settings.pip_custom_y > panel_api_get_active_size(PANEL_SIZE_HEIGHT) - PIP_SIZE1_LINES)
            user_settings.pip_custom_y = panel_api_get_active_size(PANEL_SIZE_HEIGHT) - PIP_SIZE1_LINES;
    } else {
        if (user_settings.pip_custom_x > panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE2_WIDTH)
            user_settings.pip_custom_x = panel_api_get_active_size(PANEL_SIZE_WIDTH) - PIP_SIZE2_WIDTH;
        if (user_settings.pip_custom_y > panel_api_get_active_size(PANEL_SIZE_HEIGHT) - PIP_SIZE2_LINES)
            user_settings.pip_custom_y = panel_api_get_active_size(PANEL_SIZE_HEIGHT) - PIP_SIZE2_LINES;
    }

    /* Phase 4. */
    sys_user_resize_window_channel1(1);
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
