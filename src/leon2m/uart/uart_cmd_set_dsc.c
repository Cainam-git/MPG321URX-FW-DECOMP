/* uart_cmd_set_dsc  (FUN_a00c9f44)
 *
 * Set the DSC switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b002D0; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b002D0; bit 31 of +0x1F4 (osd_toggle_dsc)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c9f44 @ 0xa00c9f44-0xa00ca158 (133 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are
 * defined in this file and inlined by GCC at -O3 (as in uart_cmd_set_transparency). Bit 31 of the settings word +0x1F4 is a
 * 1-bit bit-field, read back for the Screen Size test (Screen Size is tested first).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* byte 9 of a set frame: the one-character value */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define SWITCH_VALUE_MAX          1         /* a switch: 0 off, 1 on */
#define SCREEN_SIZE_16_10         3         /* the Screen Size list entry "16:10" */
#define SCREEN_SIZE_INPUT_ASPECT  0         /* Screen Size: width from the input's aspect */
#define LINK_SELECTOR_2           2         /* selector argument of sys_user_apply_input_link_settings */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The two fields of the user settings record (user_settings, docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad_0x0[0x1a4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
    unsigned char pad_0x1a5[0x1f4 - 0x1a5];
    unsigned int dsc_switch : 1, rest : 31;     /* +0x1F4: bit 31 = the DSC switch */
};
extern struct user_settings_record user_settings;
extern void sys_user_apply_input_link_settings(int);
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
 * Set row 0x8A of uart_cmd_dispatch_set (id 002D0): set the DSC switch.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-".
 *
 * Frame byte 9 is the switch as a character '0' or '1'; any other character is refused. The switch goes into
 * bit 31 of settings word +0x1F4. The rest is what the menu's DSC item does (osd_toggle_dsc): with DSC on, a
 * Screen Size of 16:10 is set back to the input's aspect, and the per-input link settings are applied for
 * selector 2. A settings save is requested. Then the reply "5600+\r" is built, the port's receive record cleared
 * and the reply sent.
 */
int uart_cmd_set_dsc(unsigned char port)
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
    if ((unsigned char)value > SWITCH_VALUE_MAX)
        return UART_CMD_REFUSED;
    user_settings.dsc_switch = (unsigned char)value;
    /* 16:10 is not kept with DSC on. */
    if (user_settings.screen_size == SCREEN_SIZE_16_10 && user_settings.dsc_switch)
        user_settings.screen_size = SCREEN_SIZE_INPUT_ASPECT;
    sys_user_apply_input_link_settings(LINK_SELECTOR_2);
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
