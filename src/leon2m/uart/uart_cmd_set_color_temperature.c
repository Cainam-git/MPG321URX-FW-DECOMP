/* uart_cmd_set_color_temperature  (FUN_a00c5a00)
 *
 * Set the Color Temperature from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00430; digit 0..3; returns 0xFF for a bad value (the task then replies 5600-), else 0 after
 *   '5600+'.
 * Name basis: proven - set frame 5b00430; settings byte +0x11 (osd_enter_color_temp_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c5a00 @ 0xa00c5a00-0xa00c5c18 (134 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested and switched on as an unsigned char;
 *  - the store is a switch with its own constant in each case 0..3 and a default that returns 0xff, after the
 *    range test.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */

/* Color Temperature choices (user_settings_color_temperature, settings byte +0x11). */
#define COLOR_TEMP_COOL           0
#define COLOR_TEMP_NORMAL         1
#define COLOR_TEMP_WARM           2
#define COLOR_TEMP_CUSTOMIZATION  3         /* "Customization": the custom gains are used */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings_color_temperature;
extern void pq_user_apply_color_settings(void);
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
 * Set row 0x11 (17) of uart_cmd_dispatch_set: set the Color Temperature from a frame of MSI's PC tool and apply
 * it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value above 3; then nothing
 * has changed and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the choice from frame byte 9 (choice plus 0x30): 0 Cool, 1 Normal, 2 Warm, 3 Customization.
 *   2. Store it, apply the colour settings (pq_user_apply_color_settings) and request that the settings are
 *      saved.
 *   3. Reply "5600+\r".
 */
int uart_cmd_set_color_temperature(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > COLOR_TEMP_CUSTOMIZATION)
        return UART_CMD_REFUSED;

    /* Phase 2. */
    switch ((unsigned char)value) {
    case COLOR_TEMP_COOL:
        user_settings_color_temperature = COLOR_TEMP_COOL;
        break;
    case COLOR_TEMP_NORMAL:
        user_settings_color_temperature = COLOR_TEMP_NORMAL;
        break;
    case COLOR_TEMP_WARM:
        user_settings_color_temperature = COLOR_TEMP_WARM;
        break;
    case COLOR_TEMP_CUSTOMIZATION:
        user_settings_color_temperature = COLOR_TEMP_CUSTOMIZATION;
        break;
    default:
        return UART_CMD_REFUSED;
    }
    pq_user_apply_color_settings();
    osd_mark_settings_changed_copy();

    /* Phase 3. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
