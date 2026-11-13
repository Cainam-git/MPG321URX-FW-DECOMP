/* uart_cmd_set_rgb_brightness  (FUN_a00cbbb0)
 *
 * Set the RGB LED brightness from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00740; three digits 20..100 stored as (v - 20) / 20; returns 0xFF for a bad value (the task
 *   then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00740; settings byte +0xAC, applied by UserSetAuroraLEDBarBrightness
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cbbb0 @ 0xa00cbbb0-0xa00cbe2c (159 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - uart_cmd_parse_value and the three port helpers are defined in this file, so GCC inlines them at -O3 and
 *    each copy repeats the port test;
 *  - the range test is one unsigned char compare: (unsigned char)(value - 20) > 80;
 *  - the level is stored through the byte-wide extern user_settings_settings_page_flags (the first byte of the
 *    settings word +0xAC).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define BAD_VALUE                 0xff      /* uart_cmd_parse_value: the frame holds no valid value */

/* The PC tool sends the brightness in steps of 20 from 20 to 100; it is stored as a level 0..4. */
#define RGB_BRIGHTNESS_LOWEST     20
#define RGB_BRIGHTNESS_STEP       20
#define RGB_BRIGHTNESS_SPAN       80        /* 100 - 20 */

/* The RGB LED brightness level 0..4 is the first byte of the settings word +0xAC (user_settings_settings_page_flags,
   whose lower bits hold other switches). */
#define rgb_brightness_level      user_settings_settings_page_flags

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings_settings_page_flags;
extern void UserSetAuroraLEDBarBrightness(unsigned char);
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
 * Set row 0x7F (127, row id 00740) of uart_cmd_dispatch_set: set the RGB LED brightness from one frame of the PC
 * tool and send it to the LED light bar.
 *
 *   port  the command port the frame came in on (2, 3 or another; uart_cmd_run_tool_task passes 4); it selects
 *         the receive record and the reply frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value outside 20..100 or a
 * frame without a valid value; then the dispatcher answers "5600-" and nothing has changed.
 *
 * Phases:
 *   1. Read the three-digit value from frame bytes 7..9 (uart_cmd_parse_value) and check that it is 20..100.
 *   2. Turn it into the level (value - 20) / 20, 0..4; a value between two steps is rounded down.
 *   3. Store the level and pass it to UserSetAuroraLEDBarBrightness, which sends level * 20 + 20 to the light
 *      bar on port 2 in a frame with the same row id (5b00740). Request a settings save.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_rgb_brightness(unsigned char port)
{
    unsigned char value, level;

    /* Phase 1: the value; BAD_VALUE (0xFF) also fails this test. */
    value = uart_cmd_parse_value(port);
    if ((unsigned char)(value - RGB_BRIGHTNESS_LOWEST) > RGB_BRIGHTNESS_SPAN)
        return UART_CMD_REFUSED;

    /* Phase 2: the level. */
    level = (value - RGB_BRIGHTNESS_LOWEST) / RGB_BRIGHTNESS_STEP;

    /* Phase 3: store, apply, request a save. */
    rgb_brightness_level = level;
    UserSetAuroraLEDBarBrightness(level);
    osd_mark_settings_changed_copy();

    /* Phase 4: acknowledge. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
