/* uart_cmd_set_pip_size  (FUN_a00c8a44)
 *
 * Set the PIP size from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00630; digit 0..2 stored as 2 - digit; returns 0xFF for a bad value or while PIP/PBP is off
 *   (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00630; settings byte +0x31 (osd_enter_pip_size_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c8a44 @ 0xa00c8a44-0xa00c8c38 (125 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested as an unsigned char;
 *  - the settings record is a byte array indexed by offset.
 */

#define UART_CMD_REFUSED            0xff    /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH    6       /* "5600+\r" */
#define VALUE_CHAR_OFFSET           9       /* receive record byte with the value character */
#define VALUE_CHAR_BASE             0x30    /* '0': the value byte of the frame is the value plus 0x30 */
#define USER_SETTINGS_PIP_PBP_MODE  0x1f    /* settings byte: 0 = PIP/PBP off */
#define USER_SETTINGS_PIP_SIZE      0x31    /* settings byte: the PIP size (0..2) */
#define PIP_PBP_OFF                 0
#define PIP_SIZE_LAST               2       /* the list row of a size is 2 minus the size (osd_enter_pip_size_choices) */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings[];
extern void sys_user_rebuild_window_channel1(void);
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
/* Make the port ready for the next command: clear its receive state and bytes 0, 1, 7, 10 and 0x19 of its
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
/* Send the first `length` bytes of the port's reply frame. */
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
 * Set row 13 (row id 00630) of uart_cmd_dispatch_set: set the PIP Size (settings byte +0x31) from a frame of
 * MSI's PC tool ("5b00630" + two '0' + the row character '0'..'2').
 *
 * The tool sends the row of the PIP Size list (Small, Medium, Large); the setting holds 2 minus the row, as in
 * osd_enter_pip_size_choices, and the get command reports '2' minus the setting, so the tool sees its row again.
 *
 *   port  the command port the frame came in on; it selects the receive record and the reply frame (port 2 and
 *         port 3 have their own, every other port uses uart_cmd_rx_record and uart_cmd_tx_frame). The only
 *         caller, uart_cmd_dispatch_set, is called by uart_cmd_run_tool_task with port 4.
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a row above 2 or while
 * PIP/PBP is off; then nothing has changed and the dispatcher answers "5600-".
 *
 * In this order:
 *   1. Read the row from frame byte 9 (row plus 0x30).
 *   2. Refuse it while PIP/PBP is off (settings byte +0x1F is 0).
 *   3. Store 2 minus the row, rebuild the window of channel 1, the second picture
 *      (sys_user_rebuild_window_channel1), and request that the settings are saved.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_pip_size(unsigned char port)
{
    unsigned char value_char;
    unsigned short row;

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    row = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)row > PIP_SIZE_LAST)
        return UART_CMD_REFUSED;
    /* There is no second picture while PIP/PBP is off. */
    if (user_settings[USER_SETTINGS_PIP_PBP_MODE] == PIP_PBP_OFF)
        return UART_CMD_REFUSED;

    user_settings[USER_SETTINGS_PIP_SIZE] = PIP_SIZE_LAST - row;
    sys_user_rebuild_window_channel1();
    osd_mark_settings_changed_copy();

    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
