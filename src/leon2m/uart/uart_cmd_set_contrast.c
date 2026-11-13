/* uart_cmd_set_contrast  (FUN_a00c6690)
 *
 * Set the Contrast from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00410; three digits 0..100; returns 0xFF for a bad value (the task then replies 5600-), else
 *   0 after '5600+'.
 * Name basis: proven - set frame 5b00410; settings byte +0xA (contrast slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c6690 @ 0xa00c6690-0xa00c68d8 (146 words), flags -mcpu=v8 -O3 -g.
 * Source form: uart_cmd_parse_value and the three port helpers are defined in this file, so GCC inlines them at
 * -O3, which repeats the port test in each of them.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define BAD_VALUE                 0xff      /* uart_cmd_parse_value: the three bytes are not a number 0..199 */
#define CONTRAST_MAX              100

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings_contrast;
extern void pq_user_apply_color_gain(void);
extern void sys_user_save_mode_slot(void);
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

/* The value of a set frame: bytes 7, 8 and 9 of the port's receive record as three ASCII digits. The hundreds
   digit may only be '0' or '1', so the result is 0..199; any other byte gives BAD_VALUE (0xFF). */
unsigned char uart_cmd_parse_value(unsigned char port)
{
    unsigned char hundreds, tens, units;
    unsigned short value;

    if (port == 2) {
        hundreds = uart_cmd_rx_record_port2[7];
        tens = uart_cmd_rx_record_port2[8];
        units = uart_cmd_rx_record_port2[9];
    } else if (port == 3) {
        hundreds = uart_cmd_rx_record_port3[7];
        tens = uart_cmd_rx_record_port3[8];
        units = uart_cmd_rx_record_port3[9];
    } else {
        hundreds = uart_cmd_rx_record[7];
        tens = uart_cmd_rx_record[8];
        units = uart_cmd_rx_record[9];
    }
    if (hundreds < '0' || hundreds > '1')
        return BAD_VALUE;
    if (tens < '0' || tens > '9')
        return BAD_VALUE;
    if (units < '0' || units > '9')
        return BAD_VALUE;
    hundreds -= '0';
    tens -= '0';
    units -= '0';
    value = hundreds * 100 + tens * 10 + units;
    return value;
}

/*
 * Set row 4 of uart_cmd_dispatch_set: set the Contrast from a frame of MSI's PC tool and apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a frame that is not a number
 * or a value above 100; then nothing has changed and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the three-digit value from frame bytes 7..9 (uart_cmd_parse_value) and check it.
 *   2. Store the contrast and apply it: pq_user_apply_color_gain applies settings byte +0xA as the colour gain.
 *      Then copy the picture settings into the slot of the current mode (sys_user_save_mode_slot) and request
 *      that the settings are saved.
 *   3. Reply "5600+\r".
 */
int uart_cmd_set_contrast(unsigned char port)
{
    unsigned char contrast;

    /* Phase 1. */
    contrast = uart_cmd_parse_value(port);
    if (contrast == BAD_VALUE)
        return UART_CMD_REFUSED;
    if (contrast > CONTRAST_MAX)
        return UART_CMD_REFUSED;

    /* Phase 2. */
    user_settings_contrast = contrast;
    pq_user_apply_color_gain();
    sys_user_save_mode_slot();
    osd_mark_settings_changed_copy();

    /* Phase 3. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
