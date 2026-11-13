/* uart_cmd_set_static_screen_settings  (FUN_a00ca878)
 *
 * Set all Static Screen Detection settings from one PC tool command.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b001n (26-byte frame): switch, start time, time required, reduce level.
 * Name basis: proven - set row 0x97; bit 15 of +0x1DC, bytes +0x1E0, +0x1E1, +0x1DF (OLED Care menu fields)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ca878 @ 0xa00ca878-0xa00cab68 (188 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - each value has its own port selection, read into an unsigned char, computed into an unsigned short and
 *    tested as an unsigned char;
 *  - the switch (bit 15) and the reduce level (+0x1DF) are bit-fields of the word at +0x1DC, so all four
 *    destinations are members of one structure.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': a value byte of the frame is the value plus 0x30 */

/* Frame bytes of the 26-byte command (each the value plus 0x30) and their limits. */
#define FRAME_STATIC_SCREEN       6         /* Static Screen Detection off / on */
#define FRAME_START_TIME          7
#define FRAME_TIME_REQUIRED       8
#define FRAME_REDUCE_LEVEL        9
#define ON_OFF_MAX                1
#define START_TIME_MAX            1
#define TIME_REQUIRED_MAX         1
#define REDUCE_LEVEL_MAX          8

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x1dc];
    unsigned int oled_care_bits_31_16 : 16,     /* +0x1DC oled_care_flags word, from the top bit down */
                 static_screen : 1,             /* bit 15: Static Screen Detection on */
                 oled_care_bits_14_8 : 7,
                 static_screen_level : 8;       /* +0x1DF: the reduce level */
    unsigned char static_screen_start_time;     /* +0x1E0 */
    unsigned char static_screen_time_required;  /* +0x1E1 */
};
extern struct user_settings_record user_settings;
extern void oled_user_apply_screen_saver_range(void);
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
 * Set row 0x97 (151) of uart_cmd_dispatch_set, the 26-byte frame "5b001n": set the four Static Screen Detection
 * settings of the OLED Care menu from one frame of the PC tool and send them to the OLED panel controller.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) at the first value out of range;
 * then nothing is replied here and the dispatcher answers "5600-". The values stored before it keep their new
 * values.
 *
 * Phases:
 *   1. Frame byte 6: the switch (0..1), bit 15 of the oled_care_flags word.
 *   2. Frame byte 7: the start time (0..1).
 *   3. Frame byte 8: the time required (0..1).
 *   4. Frame byte 9: the reduce level (0..8).
 *   5. oled_user_apply_screen_saver_range sends all four to the controller (register 0x60, written by
 *      oled_set_screen_saver_range); request a save and reply "5600+\r".
 */
int uart_cmd_set_static_screen_settings(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[FRAME_STATIC_SCREEN];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[FRAME_STATIC_SCREEN];
    else
        value_char = uart_cmd_rx_record[FRAME_STATIC_SCREEN];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > ON_OFF_MAX)
        return UART_CMD_REFUSED;
    user_settings.static_screen = (unsigned char)value;

    /* Phase 2. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[FRAME_START_TIME];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[FRAME_START_TIME];
    else
        value_char = uart_cmd_rx_record[FRAME_START_TIME];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > START_TIME_MAX)
        return UART_CMD_REFUSED;
    user_settings.static_screen_start_time = value;

    /* Phase 3. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[FRAME_TIME_REQUIRED];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[FRAME_TIME_REQUIRED];
    else
        value_char = uart_cmd_rx_record[FRAME_TIME_REQUIRED];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > TIME_REQUIRED_MAX)
        return UART_CMD_REFUSED;
    user_settings.static_screen_time_required = value;

    /* Phase 4. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[FRAME_REDUCE_LEVEL];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[FRAME_REDUCE_LEVEL];
    else
        value_char = uart_cmd_rx_record[FRAME_REDUCE_LEVEL];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > REDUCE_LEVEL_MAX)
        return UART_CMD_REFUSED;
    user_settings.static_screen_level = value;

    /* Phase 5. */
    oled_user_apply_screen_saver_range();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
