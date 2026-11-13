/* uart_cmd_set_hdmi_cec  (FUN_a00c7818)
 *
 * Set the HDMI CEC switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b008:0; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b008:0; bit 20 of +0xAC (osd_toggle_hdmi_cec); restarts the input channels
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c7818 @ 0xa00c7818-0xa00c7a5c (145 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested and stored as an unsigned char;
 *  - bit 20 of settings word +0xAC is a 1-bit bit-field (hdmi_cec_on), not a mask on the word.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* receive record byte with the value character */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define HDMI_CEC_MAX              1         /* 0 = OFF, 1 = ON */
#define PIP_PBP_OFF               0         /* pip_pbp_mode: one picture */
#define LEVEL_1                   1         /* level argument of sys_api_restart_channel_at_level */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (docs/RECORDS.md) used here; as in osd_toggle_hdmi_cec. */
struct user_settings_record {
    unsigned char pad0[0x1e];
    unsigned char input_source;                 /* +0x1E: the selected input source */
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = PIP/PBP off */
    unsigned char pad20[0xac - 0x20];
    unsigned int hi : 11, hdmi_cec_on : 1, lo : 20;  /* +0xAC: bit 20 = HDMI CEC (SETTINGS_HDMI_CEC_ON) */
};
extern struct user_settings_record user_settings;
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void panel_user_set_output_on(int);
extern void input_api_select_ports(int, int);
extern void sys_api_restart_channel_at_level(int, int);
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
 * Set row 80 (row id 008:0) of uart_cmd_dispatch_set: switch HDMI CEC (bit 20 of settings word +0xAC) from a
 * frame of MSI's PC tool ("5b008:0" + two '0' + the value character '0' OFF or '1' ON).
 *
 *   port  the command port the frame came in on; it selects the receive record and the reply frame (port 2 and
 *         port 3 have their own, every other port uses uart_cmd_rx_record and uart_cmd_tx_frame). The only
 *         caller, uart_cmd_dispatch_set, is called by uart_cmd_run_tool_task with port 4.
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value other than 0 or 1;
 * then nothing has changed and the dispatcher answers "5600-".
 *
 * In this order:
 *   1. Read the value from frame byte 9 (value plus 0x30).
 *   2. Only while PIP/PBP is off: store the switch, and when the Input Source is menu index 0 (as the menu's own
 *      toggle, osd_toggle_hdmi_cec, tests it) switch the picture output off, select the ports again and restart
 *      channels 0 and 1 at level 1. While PIP/PBP is on the value is dropped, but the command still succeeds.
 *      Unlike osd_toggle_hdmi_cec, PIP/PBP is not switched off here.
 *   3. Request that the settings are saved and reply "5600+\r".
 */
int uart_cmd_set_hdmi_cec(unsigned char port)
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
    if ((unsigned char)value > HDMI_CEC_MAX)
        return UART_CMD_REFUSED;

    if (user_settings.pip_pbp_mode == PIP_PBP_OFF) {
        user_settings.hdmi_cec_on = (unsigned char)value;
        /* Restart the pictures only for the input at menu index 0. */
        if (input_api_source_id_to_menu_index(user_settings.input_source) == 0) {
            panel_user_set_output_on(0);
            input_api_select_ports(1, 1);
            sys_api_restart_channel_at_level(0, LEVEL_1);
            sys_api_restart_channel_at_level(1, LEVEL_1);
        }
    }
    osd_mark_settings_changed_copy();

    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
