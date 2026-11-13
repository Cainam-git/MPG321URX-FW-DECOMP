/* uart_cmd_set_display_hdr  (FUN_a00c9be0)
 *
 * Set the DisplayHDR setting from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b004:0; digit 0..2; returns 0xFF while PIP/PBP is on (tested first) or for a bad value (the
 *   task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b004:0; bits 18..19 of +0xAC (osd_enter_display_hdr_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c9be0 @ 0xa00c9be0-0xa00c9df4 (133 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are
 * defined in this file and inlined by GCC at -O3 (as in uart_cmd_set_transparency). The value is computed before the two
 * tests, and the PIP/PBP test comes first. Bits 18..19 of the settings word +0xAC are a 2-bit bit-field.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* byte 9 of a set frame: the one-character value */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define PIP_PBP_OFF               0         /* user_settings pip_pbp_mode: one picture only */
#define DISPLAY_HDR_MODE_MAX      2         /* menu choices 0..2: True Black 400, Peak 1000 nits, EOTF Boost */
#define OSD_REQUEST_EVENT_83      0x04      /* osd_request_bits bit 2: turned into OSD event 0x83 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The two fields of the user settings record (user_settings, docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad_0x0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 off, 1 PIP, 2 PBP */
    unsigned char pad_0x20[0xac - 0x20];
    unsigned int bits_31_20 : 12,               /* +0xAC: settings page flags */
                 display_hdr_mode : 2,          /*   bits 18..19: the DisplayHDR choice */
                 bits_17_0 : 18;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void sys_user_apply_startup_settings(void);
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
 * Set row 0x71 of uart_cmd_dispatch_set (id 004:0): set the DisplayHDR mode.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-".
 *
 * The command is refused while PIP or PBP is on (pip_pbp_mode not 0), and when frame byte 9 is not a character
 * '0'..'2' (True Black 400, Peak 1000 nits, EOTF Boost, the order of the menu choices). The mode goes into
 * bits 18..19 of settings word +0xAC and the stored settings are applied again
 * (sys_user_apply_startup_settings), as the menu's own accept handler (osd_accept_display_hdr) does after a
 * change. A settings save and OSD event 0x83 are requested. Then the reply "5600+\r" is built, the port's receive
 * record cleared and the reply sent.
 */
int uart_cmd_set_display_hdr(unsigned char port)
{
    unsigned char value_char;
    unsigned short mode;

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    mode = value_char - VALUE_CHAR_BASE;
    if (user_settings.pip_pbp_mode != PIP_PBP_OFF)
        return UART_CMD_REFUSED;
    if ((unsigned char)mode > DISPLAY_HDR_MODE_MAX)
        return UART_CMD_REFUSED;
    user_settings.display_hdr_mode = (unsigned char)mode;
    sys_user_apply_startup_settings();
    osd_mark_settings_changed_copy();
    osd_request_bits |= OSD_REQUEST_EVENT_83;
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
