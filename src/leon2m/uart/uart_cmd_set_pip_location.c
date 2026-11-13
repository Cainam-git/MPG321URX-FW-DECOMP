/* uart_cmd_set_pip_location  (FUN_a00c91dc)
 *
 * Set the PIP location from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00640; digit 0..4; returns 0xFF for a bad value (the task then replies 5600-), else 0 after
 *   '5600+'.
 * Name basis: proven - set frame 5b00640; bits 4..7 of +0x30 (osd_enter_pip_location_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c91dc @ 0xa00c91dc-0xa00c93e0 (129 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested as an unsigned char;
 *  - bits 4..7 of settings word +0x30 are a 4-bit bit-field (pip_location) assigned from (unsigned char)location;
 *    the plain assignment or a mask expression allocates other registers.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* receive record byte with the value character */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define PIP_PBP_OFF               0
#define PIP_LOCATION_CUSTOMIZE    4         /* locations 0..3 are the four corners, 4 is Customize */
#define SOURCE_OFF_DURING_RESIZE  1         /* sys_user_resize_window_channel1: switch the source off meanwhile */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (docs/RECORDS.md) used here; the record is stored with the most
   significant bit first, so the first bit-field of a word is its top bits. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = PIP/PBP off */
    unsigned char pad20[0x30 - 0x20];
    unsigned int bits_31_8 : 24,
                 pip_location : 4,              /* +0x30 bits 4..7: the PIP location */
                 second_location : 4;           /* +0x30 bits 0..3 */
};
extern struct user_settings_record user_settings;
extern void sys_user_resize_window_channel1(int);
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
 * Set row 14 (row id 00640) of uart_cmd_dispatch_set: set the PIP Location (bits 4..7 of settings word +0x30)
 * from a frame of MSI's PC tool ("5b00640" + two '0' + the location character '0'..'4'). The location is the row
 * of the PIP Location list: the four corners, then Customize (osd_enter_pip_location_choices).
 *
 *   port  the command port the frame came in on; it selects the receive record and the reply frame (port 2 and
 *         port 3 have their own, every other port uses uart_cmd_rx_record and uart_cmd_tx_frame). The only
 *         caller, uart_cmd_dispatch_set, is called by uart_cmd_run_tool_task with port 4.
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a location above 4 or while
 * PIP/PBP is off; then nothing has changed and the dispatcher answers "5600-".
 *
 * In this order:
 *   1. Read the location from frame byte 9 (location plus 0x30).
 *   2. Refuse it while PIP/PBP is off (settings byte +0x1F is 0).
 *   3. Store it and recompute the window of channel 1, the second picture, with its source switched off while
 *      the window is handed over (sys_user_resize_window_channel1(1)); request that the settings are saved.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_pip_location(unsigned char port)
{
    unsigned char value_char;
    unsigned short location;

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    location = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)location > PIP_LOCATION_CUSTOMIZE)
        return UART_CMD_REFUSED;
    /* There is no second picture while PIP/PBP is off. */
    if (user_settings.pip_pbp_mode == PIP_PBP_OFF)
        return UART_CMD_REFUSED;

    user_settings.pip_location = (unsigned char)location;
    sys_user_resize_window_channel1(SOURCE_OFF_DURING_RESIZE);
    osd_mark_settings_changed_copy();

    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
