/* uart_cmd_set_power_led  (FUN_a00ca158)
 *
 * Set the Power LED switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b008B0; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b008B0; bit 30 of +0x1F4 (osd_toggle_power_led)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ca158 @ 0xa00ca158-0xa00ca380 (138 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are
 * defined in this file and inlined by GCC at -O3 (as in uart_cmd_set_transparency). The pin choice tests the value itself
 * (cast to unsigned char), and the switch is stored after the pin calls. Bit 30 of the settings word +0x1F4 is a
 * 1-bit bit-field.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* byte 9 of a set frame: the one-character value */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define SWITCH_VALUE_MAX          1         /* a switch: 0 off, 1 on */
#define POWER_LED_ON              1
#define PIN_MODE_ALLOW            1         /* mode byte 1: the *_if_allowed pin routines drive their pin */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The one field of the user settings record (user_settings, docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad_0x0[0x1f4];
    unsigned int dsc_switch : 1,                /* +0x1F4: bit 31 = the DSC switch */
                 power_led : 1,                 /*   bit 30 = the Power LED switch */
                 rest : 30;
};
extern struct user_settings_record user_settings;
extern void sys_set_mode_byte_c9f8(unsigned char);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void sys_user_apply_mode_byte(void);
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
 * Set row 0x8B of uart_cmd_dispatch_set (id 008B0): set the Power LED switch.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-".
 *
 * Frame byte 9 is the switch as a character '0' or '1'; any other character is refused. Then the same calls as
 * the menu's Power LED item (osd_toggle_power_led): the mode byte is set to 1 so that the pin routines act, pin 7
 * of GPIO port 4 is driven high for on and low for off, pin 4 of port 4 is driven low, the switch goes into
 * bit 30 of settings word +0x1F4 and sys_user_apply_mode_byte sets the mode byte to the switch. A settings save
 * is requested. Then the reply "5600+\r" is built, the port's receive record cleared and the reply sent.
 */
int uart_cmd_set_power_led(unsigned char port)
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
    sys_set_mode_byte_c9f8(PIN_MODE_ALLOW);
    if ((unsigned char)value == POWER_LED_ON)
        gpio_set_port4_bit7_high_if_allowed();
    else
        gpio_set_port4_bit7_low_if_allowed();
    gpio_set_port4_bit4_low_if_allowed();
    user_settings.power_led = (unsigned char)value;
    sys_user_apply_mode_byte();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
