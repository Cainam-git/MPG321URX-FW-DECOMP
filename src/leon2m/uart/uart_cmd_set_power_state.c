/* uart_cmd_set_power_state  (FUN_a00c0de0)
 *
 * Take a power on/off request from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00100: '0' is refused while channel 0 is off, '1' while the power status bit is set; both
 *   set the request byte.
 * Name basis: derived - set frame 5b00100; '0' checked against sys_api_get_channel_state_code(0), '1' against
 *   bit 31 of device_settings; sets uart_cmd_power_request to 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c0de0 @ 0xa00c0de0-0xa00c0ff4 (133 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers and a fourth one, rx_char(port, 9), are defined in this file, so GCC inlines them;
 *  - the value byte goes into an int (value_char) before the sys_api_get_channel_state_code call, and the
 *    unsigned char value = value_char - '0' is taken after the call;
 *  - the power status bit of device_settings is read as a 1-bit bit-field.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_UNITS_DIGIT         9         /* byte 9 of a set frame: the units digit of the value */
#define CHANNEL_STATE_CODE_OFF    0         /* sys_api_get_channel_state_code: raw state 0 (CH_STATE_OFF) */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char uart_cmd_power_request;

/* The device settings record (device_settings, 0xA802E1A0): only its first word is used here. */
struct device_settings_record {
    unsigned int power_status : 1,              /* +0 bit 31: power status */
                 rest : 31;
};
extern struct device_settings_record device_settings;
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

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

/* Byte `offset` of the port's receive record. */
static unsigned char rx_char(unsigned char port, int offset)
{
    if (port == 2)
        return uart_cmd_rx_record_port2[offset];
    else if (port == 3)
        return uart_cmd_rx_record_port3[offset];
    else
        return uart_cmd_rx_record[offset];
}

/*
 * Set row 0 of uart_cmd_dispatch_set (id 00100): the power state command of MSI's PC tool.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF); then the dispatcher answers
 * "5600-".
 *
 * Phases:
 *   1. Read the units digit of the value (frame byte 9) and the state code of channel 0
 *      (sys_api_get_channel_state_code(0); it is read for every value).
 *   2. By the value:
 *        0  refused while the state code of channel 0 is CHANNEL_STATE_CODE_OFF; else uart_cmd_power_request = 1
 *        1  refused while the power status bit of device_settings is set; else uart_cmd_power_request = 1
 *        any other value changes nothing and is acknowledged all the same.
 *      Both accepted values set the same flag to 1.
 *   3. Reply "5600+\r".
 */
int uart_cmd_set_power_state(unsigned char port)
{
    int value_char;
    unsigned char value;
    unsigned char state_code;

    /* Phase 1. */
    value_char = rx_char(port, VALUE_UNITS_DIGIT);
    state_code = sys_api_get_channel_state_code(0);
    value = value_char - '0';
    /* Phase 2. */
    switch (value) {
    case 0:
        if (state_code == CHANNEL_STATE_CODE_OFF)
            return UART_CMD_REFUSED;
        uart_cmd_power_request = 1;
        break;
    case 1:
        if (device_settings.power_status)
            return UART_CMD_REFUSED;
        uart_cmd_power_request = 1;
        break;
    }
    /* Phase 3. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
