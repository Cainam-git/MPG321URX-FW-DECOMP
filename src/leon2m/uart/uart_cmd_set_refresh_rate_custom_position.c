/* uart_cmd_set_refresh_rate_custom_position  (FUN_a00c1d54)
 *
 * Set the custom Refresh Rate position from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0
 * Note: Row '5b002?' + wildcard bytes of the 26-byte set table; two 4-digit numbers limited to 50 / 29;
 *   nothing is refused.
 * Name basis: derived - 26-byte set row 9 '5b002?'; bytes +0x1A5/+0x1A6, used with location +0x13E by
 *   osd_show_screen_overlays
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c1d54 @ 0xa00c1d54-0xa00c2180 (267 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the receive-record byte reader rx_char and the three port helpers are defined in this file and inlined by
 *    GCC at -O3, which repeats the port test for every byte read;
 *  - each number is one expression: the four bytes weighted 1000 / 100 / 10 / 1, minus '0' * 1111 at the end;
 *  - the user settings fields are members of one structure, so a single base register addresses them;
 *  - the sleep state is a 2-bit bit-field of the halfword (a mask test swaps two registers).
 */

#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define CUSTOM_X_MAX              50        /* largest value stored in refresh_rate_custom_x */
#define CUSTOM_Y_MAX              29        /* largest value stored in refresh_rate_custom_y */
#define GAMING_FLAG_REFRESH_RATE  0x1000    /* user settings +0xA8 bit 12: Refresh Rate display */
#define SETTINGS_INFO_ON_SCREEN   0x400000  /* user settings +0xAC bit 22: Info. On Screen */

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0xa8];
    unsigned int gaming_flags;                  /* +0xA8: GAMING_FLAG_* switches */
    unsigned int settings_page_flags;           /* +0xAC: SETTINGS_* switches */
    unsigned char pad0b0[0x190 - 0xb0];
    unsigned char crosshair_icon;               /* +0x190: the Smart Crosshair icon (0 = none) */
    unsigned char pad191[0x1a0 - 0x191];
    unsigned char alarm_clock;                  /* +0x1A0: the Alarm Clock timer choice (0 = off) */
    unsigned char pad1a1[0x1a5 - 0x1a1];
    unsigned char refresh_rate_custom_x;        /* +0x1A5: custom position of the Refresh Rate overlay */
    unsigned char refresh_rate_custom_y;        /* +0x1A6 */
};
extern struct user_settings_record user_settings;
/* The sleep word of the application state record (app_state_record +4, 0xA802CFF8). */
struct app_state_sleep_word {
    unsigned short bit15 : 1;
    unsigned short sleep_state : 2;             /* bits 13..14 */
    unsigned short rest : 13;
};
extern struct app_state_sleep_word app_state_record_sleep_word;
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern void osd_close_menu(void);
extern void osd_open_menu_state_0x106(void);
extern void osd_mark_settings_changed_copy(void);

/* Byte `offset` of the port's receive record. */
static unsigned char rx_char(unsigned char port, int offset)
{
    unsigned char c;

    if (port == 2)
        c = uart_cmd_rx_record_port2[offset];
    else if (port == 3)
        c = uart_cmd_rx_record_port3[offset];
    else
        c = uart_cmd_rx_record[offset];
    return c;
}

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
 * Set row 0x96 (150) of uart_cmd_dispatch_set: store the custom position of the Refresh Rate overlay from a
 * 26-byte frame of MSI's PC tool (table row "5b002?" followed by wildcard bytes, uart_cmd_set_rows26 row 9).
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 always, after the "5600+" reply has been sent: the bytes are not checked to be digits and nothing is
 * refused.
 *
 * Frame bytes read (ASCII decimal, four digits each):
 *   6..9    x, limited to CUSTOM_X_MAX (50)
 *   10..13  y, limited to CUSTOM_Y_MAX (29)
 *
 * Phases:
 *   1. Read both numbers, limit them, store them in refresh_rate_custom_x / _y (+0x1A5 / +0x1A6).
 *   2. When the sleep state is 0: close the menu, open menu state 0x106, which draws the screen overlays, and
 *      close the menu again when no overlay setting is on (crosshair icon 0, Refresh Rate display off, no alarm
 *      timer, Info. On Screen off).
 *   3. Request that the settings are saved, then reply "5600+\r".
 */
int uart_cmd_set_refresh_rate_custom_position(unsigned char port)
{
    unsigned short x, y;

    /* Phase 1. */
    x = rx_char(port, 6) * 1000 + rx_char(port, 7) * 100 + rx_char(port, 8) * 10 + rx_char(port, 9) - '0' * 1111;
    y = rx_char(port, 10) * 1000 + rx_char(port, 11) * 100 + rx_char(port, 12) * 10 + rx_char(port, 13) - '0' * 1111;
    if (x > CUSTOM_X_MAX)
        x = CUSTOM_X_MAX;
    if (y > CUSTOM_Y_MAX)
        y = CUSTOM_Y_MAX;
    user_settings.refresh_rate_custom_x = x;
    user_settings.refresh_rate_custom_y = y;
    /* Phase 2: redraw the screen overlays with the new position. */
    if (app_state_record_sleep_word.sleep_state == 0) {
        osd_close_menu();
        osd_open_menu_state_0x106();
        /* No overlay is switched on: nothing to show, close again. */
        if (user_settings.crosshair_icon == 0 && (user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE) == 0
            && user_settings.alarm_clock == 0 && (user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN) == 0)
            osd_close_menu();
    }
    /* Phase 3. */
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
