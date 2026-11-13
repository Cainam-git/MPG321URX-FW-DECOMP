/* uart_cmd_set_panel_protect_byte_0x1e5  (FUN_a00ca410)
 *
 * Store 1 in settings byte +0x1E5 for value 1 of a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00;11. Bit 30 of +0x1DC is not written and no run starts: oled_user_request_panel_refresh(1)
 *   changes nothing. Returns 0xFF for a bad value or while +0x1E5 is 1 and the panel protect prompt is shown.
 * Name basis: descriptive - set frame 5b00;11 (row 117, after the start command 5b00;10); value 1 stores
 *   +0x1E5 = 1 and clears a flag of app_state_record; refused while the panel protect prompt is shown
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ca410 @ 0xa00ca410-0xa00ca644 (141 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are
 * defined in this file and inlined by GCC at -O3 (as in uart_cmd_set_transparency); the two early-return tests are one ||
 * condition; bit 8 of app_state_record is a 1-bit bit-field, cleared after the byte store.
 */

#define UART_CMD_REFUSED                0xff    /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH        6       /* "5600+\r" */
#define VALUE_CHAR_OFFSET               9       /* byte 9 of a set frame: the one-character value */
#define VALUE_CHAR_BASE                 0x30    /* '0': the value byte of the frame is the value plus 0x30 */
#define SWITCH_VALUE_MAX                1       /* 0 or 1 */
#define MENU_STATE_PANEL_PROTECT_PROMPT 0x10a   /* the panel protect prompt is on screen */
#define PANEL_PROTECT_ROW_1             1       /* argument of oled_user_request_panel_refresh; only 0 starts the
                                                   refresh run, so this call changes nothing */

/* Settings byte +0x1E5 of the user settings record (user_settings, docs/RECORDS.md). The panel protect prompt
   (osd_accept_panel_protect_prompt) sets it to 1 when request bit 30 of +0x1DC is clear, and clears it again on
   the next OK. */
#define SETTINGS_BYTE_0x1E5             0x1e5

extern unsigned char user_settings[];
/* First halfword of the application state record; bit 8 is the flag osd_show_input_info_message sets. */
struct app_state_flags { unsigned short bits_15_9 : 7, after_display : 1, bits_7_0 : 8; };
extern struct app_state_flags app_state_record;
extern void oled_user_request_panel_refresh(int);
extern unsigned short osd_get_menu_state(void);
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

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
 * Set row 0x75 of uart_cmd_dispatch_set (id 00;11), the second of the two panel protect commands (row 0x74,
 * uart_cmd_start_panel_protect, is the first).
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-".
 *
 * Frame byte 9 must be '0' or '1'. The command is also refused while settings byte +0x1E5 is 1 and the panel
 * protect prompt is on screen. Value 1 repeats steps of the prompt's OK handler (osd_accept_panel_protect_prompt)
 * for row 1: byte +0x1E5 is set to 1, bit 8 of app_state_record is cleared and oled_user_request_panel_refresh is
 * called with 1, which returns without a change. Bit 30 of +0x1DC itself is not written here. Value 0 changes nothing.
 * Both values request a settings save and send "5600+\r" after clearing the port's receive record.
 */
int uart_cmd_set_panel_protect_byte_0x1e5(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > SWITCH_VALUE_MAX
        || (user_settings[SETTINGS_BYTE_0x1E5] == 1 && osd_get_menu_state() == MENU_STATE_PANEL_PROTECT_PROMPT))
        return UART_CMD_REFUSED;
    if ((unsigned char)value == 1) {
        user_settings[SETTINGS_BYTE_0x1E5] = 1;
        app_state_record.after_display = 0;
        oled_user_request_panel_refresh(PANEL_PROTECT_ROW_1);
    }
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
