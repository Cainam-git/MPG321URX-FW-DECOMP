/* uart_cmd_set_color_gains  (FUN_a00c573c)
 *
 * Set the custom red, green and blue gains from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00434; colour temperature set to user (3), three digits into +0x12..+0x14; returns 0xFF for
 *   a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00434; settings bytes +0x12..+0x14 together
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c573c @ 0xa00c573c-0xa00c5a00 (177 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three frame-byte readers and the three port helpers are defined in this file, so GCC inlines them at
 *    -O3;
 *  - each reader takes the frame byte into an unsigned int and the value into an unsigned short, tests it as an
 *    unsigned char and returns it masked with 0xff;
 *  - the readers' results go into one unsigned char local (gain), compared with 0xff.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': a value byte of the frame is the value plus 0x30 */
#define FRAME_VALUE_MAX           100       /* largest value the three frame-byte readers accept */
#define BAD_VALUE                 0xff      /* reader result for a value above FRAME_VALUE_MAX */

/* Color Temperature choices (user_settings.color_temperature). */
#define COLOR_TEMP_COOL           0
#define COLOR_TEMP_NORMAL         1
#define COLOR_TEMP_WARM           2
#define COLOR_TEMP_CUSTOMIZATION  3         /* "Customization": the custom gains are used */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x11];
    unsigned char color_temperature;            /* +0x11: Color Temperature */
    unsigned char red_gain;                     /* +0x12: the custom red gain */
    unsigned char green_gain;                   /* +0x13: the custom green gain */
    unsigned char blue_gain;                    /* +0x14: the custom blue gain */
};
extern struct user_settings_record user_settings;
extern void pq_user_apply_color_settings(void);

/* The three readers below take one byte of the port's receive record as a value 0..100 (byte minus 0x30) and
   return BAD_VALUE (0xFF) above that. They read bytes 7, 8 and 9, the three value bytes of a set frame; in a
   command with a three-digit value these are its hundreds, tens and units digits. */

/* Frame byte 7. */
int uart_cmd_get_hundreds_digit(unsigned char port)
{
    unsigned int frame_byte;
    unsigned short value;

    if (port == 2)
        frame_byte = uart_cmd_rx_record_port2[7];
    else if (port == 3)
        frame_byte = uart_cmd_rx_record_port3[7];
    else
        frame_byte = uart_cmd_rx_record[7];
    value = frame_byte - VALUE_CHAR_BASE;
    if ((unsigned char)value > FRAME_VALUE_MAX)
        return BAD_VALUE;
    return value & 0xff;
}

/* Frame byte 8. */
int uart_cmd_get_tens_digit(unsigned char port)
{
    unsigned int frame_byte;
    unsigned short value;

    if (port == 2)
        frame_byte = uart_cmd_rx_record_port2[8];
    else if (port == 3)
        frame_byte = uart_cmd_rx_record_port3[8];
    else
        frame_byte = uart_cmd_rx_record[8];
    value = frame_byte - VALUE_CHAR_BASE;
    if ((unsigned char)value > FRAME_VALUE_MAX)
        return BAD_VALUE;
    return value & 0xff;
}

/* Frame byte 9. */
int uart_cmd_get_units_digit(unsigned char port)
{
    unsigned int frame_byte;
    unsigned short value;

    if (port == 2)
        frame_byte = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        frame_byte = uart_cmd_rx_record_port3[9];
    else
        frame_byte = uart_cmd_rx_record[9];
    value = frame_byte - VALUE_CHAR_BASE;
    if ((unsigned char)value > FRAME_VALUE_MAX)
        return BAD_VALUE;
    return value & 0xff;
}

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
 * Set row 0x15 (21) of uart_cmd_dispatch_set: set the three custom colour gains from one frame of MSI's PC tool
 * and apply them.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a gain above 100; then the
 * dispatcher answers "5600-".
 *
 * Phases:
 *   1. Switch Color Temperature to Customization. This stays even when a gain is refused below.
 *   2. Red, green and blue gain from frame bytes 7, 8 and 9 (each the gain plus 0x30, 0..100), stored in that
 *      order; a bad gain stops the routine, the gains before it keep their new values.
 *   3. Apply the colour settings (pq_user_apply_color_settings) and request that the settings are saved.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_color_gains(unsigned char port)
{
    unsigned char gain;

    /* Phase 1. */
    if (user_settings.color_temperature != COLOR_TEMP_CUSTOMIZATION)
        user_settings.color_temperature = COLOR_TEMP_CUSTOMIZATION;

    /* Phase 2. */
    gain = uart_cmd_get_hundreds_digit(port);
    if (gain == BAD_VALUE)
        return UART_CMD_REFUSED;
    user_settings.red_gain = gain;
    gain = uart_cmd_get_tens_digit(port);
    if (gain == BAD_VALUE)
        return UART_CMD_REFUSED;
    user_settings.green_gain = gain;
    gain = uart_cmd_get_units_digit(port);
    if (gain == BAD_VALUE)
        return UART_CMD_REFUSED;
    user_settings.blue_gain = gain;

    /* Phase 3. */
    pq_user_apply_color_settings();
    osd_mark_settings_changed_copy();

    /* Phase 4. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
