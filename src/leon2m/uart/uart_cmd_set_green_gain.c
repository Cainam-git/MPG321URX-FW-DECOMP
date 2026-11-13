/* uart_cmd_set_green_gain  (FUN_a00cc9c0)
 *
 * Set the custom green gain from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00432; colour temperature set to user (3), three digits 0..100; returns 0xFF for a bad value
 *   (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00432; settings byte +0x13 (osd_draw_green_gain,
 *   pq_user_apply_custom_green)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cc9c0 @ 0xa00cc9c0-0xa00ccc20 (152 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - uart_cmd_parse_value and the three port helpers are defined in this file, so GCC inlines them at -O3 and
 *    each copy repeats the port test;
 *  - color_temperature and the gain are members of one user_settings structure, so its address stays in one
 *    register;
 *  - BAD_VALUE and the limit are two separate tests.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define BAD_VALUE                 0xff      /* uart_cmd_parse_value: the frame holds no valid value */
#define GAIN_MAX                  100       /* largest custom gain */
#define COLOR_TEMP_CUSTOMIZATION  3         /* Color Temperature "Customization": the custom gains are used */

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
extern void pq_user_apply_custom_green(void);
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
 * Set row 0x13 (19, row id 00432) of uart_cmd_dispatch_set: set the custom green gain from one frame of the PC
 * tool and apply it. Rows 0x12 (red, uart_cmd_set_red_gain) and 0x14 (blue, uart_cmd_set_blue_gain) work the
 * same way.
 *
 *   port  the command port the frame came in on (2, 3 or another; uart_cmd_run_tool_task passes 4); it selects
 *         the receive record and the reply frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value above 100 or a frame
 * without a valid value; then the dispatcher answers "5600-".
 *
 * Phases:
 *   1. When Color Temperature is not Customization, switch it to Customization and apply the colour settings
 *      (pq_user_apply_color_settings). This happens before the value is checked, so it stays even when the value
 *      is refused.
 *   2. Read the three-digit value from frame bytes 7..9 (uart_cmd_parse_value) and check that it is 0..100.
 *   3. Store it as the custom green gain, apply it (pq_user_apply_custom_green) and request a settings save.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_green_gain(unsigned char port)
{
    unsigned char gain;

    /* Phase 1: the custom gains only count in Customization. */
    if (user_settings.color_temperature != COLOR_TEMP_CUSTOMIZATION) {
        user_settings.color_temperature = COLOR_TEMP_CUSTOMIZATION;
        pq_user_apply_color_settings();
    }

    /* Phase 2: the value. */
    gain = uart_cmd_parse_value(port);
    if (gain == BAD_VALUE)
        return UART_CMD_REFUSED;
    if (gain > GAIN_MAX)
        return UART_CMD_REFUSED;

    /* Phase 3: store, apply, request a save. */
    user_settings.green_gain = gain;
    pq_user_apply_custom_green();
    osd_mark_settings_changed_copy();

    /* Phase 4: acknowledge. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
