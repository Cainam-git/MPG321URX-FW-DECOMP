/* uart_cmd_set_setting_bit9  (FUN_a00c9788)
 *
 * Set the settings bit 9 from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00510; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: descriptive - set frame 5b00510; bit 9 of settings word +0, applied by sys_api_set_config_bit31
 *   (same field as ddc_tool_set_setting_bit9)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c9788 @ 0xa00c9788-0xa00c9980 (126 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are
 * defined in this file and inlined by GCC at -O3 (as in uart_cmd_set_transparency). Bit 9 of the first settings word is a
 * 1-bit bit-field, and the value passed on is read back from that field.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* byte 9 of a set frame: the one-character value */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define SWITCH_VALUE_MAX          1         /* a switch: 0 off, 1 on */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The first word of the user settings record (user_settings, docs/RECORDS.md). Bit 9 is the switch that
   osd_draw_auto_scan_switch shows at item row 4 of the Input Source page. */
struct user_settings_record {
    unsigned int bits_31_10 : 22, auto_scan : 1, bits_8_0 : 9;
};
extern struct user_settings_record user_settings;
extern void sys_api_set_config_bit31(unsigned char);
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
 * Set row 0x5B of uart_cmd_dispatch_set (id 00510): set bit 9 of the first settings word, the Input Source
 * auto scan switch.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-".
 *
 * Frame byte 9 is the switch as a character '0' or '1'; any other character is refused. The bit is stored,
 * handed to sys_api_set_config_bit31 (which keeps it as configuration bit 31) and a settings save is requested.
 * Then the reply "5600+\r" is built, the port's receive record cleared and the reply sent.
 */
int uart_cmd_set_setting_bit9(unsigned char port)
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
    user_settings.auto_scan = (unsigned char)value;
    sys_api_set_config_bit31(user_settings.auto_scan);
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
