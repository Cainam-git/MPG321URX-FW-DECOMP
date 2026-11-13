/* uart_cmd_set_crosshair_color  (FUN_a00c3380)
 *
 * Set the Smart Crosshair colour from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00271; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00271; settings byte +0x17B (osd_open_crosshair_color)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c3380 @ 0xa00c3380-0xa00c35d0 (148 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file and inlined by GCC at -O3; the value byte is read with the
 *    port test written out in the routine;
 *  - value is an unsigned short, cast to a byte for the range test;
 *  - the sleep state is a 2-bit bit-field of the halfword (a mask test swaps two registers).
 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define CROSSHAIR_COLOR_MAX       12        /* largest value this command accepts */
#define GAMING_FLAG_REFRESH_RATE  0x1000    /* user settings +0xA8 bit 12: Refresh Rate display */
#define SETTINGS_INFO_ON_SCREEN   0x400000  /* user settings +0xAC bit 22: Info. On Screen */

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0xa8];
    unsigned int gaming_flags;                  /* +0xA8: GAMING_FLAG_* switches */
    unsigned int settings_page_flags;           /* +0xAC: SETTINGS_* switches */
    unsigned char pad0b0[0x17b - 0xb0];
    unsigned char crosshair_color;              /* +0x17B: the Smart Crosshair colour (2 = automatic) */
    unsigned char pad17c[0x190 - 0x17c];
    unsigned char crosshair_icon;               /* +0x190: the Smart Crosshair icon (0 = none) */
    unsigned char pad191[0x1a0 - 0x191];
    unsigned char alarm_clock;                  /* +0x1A0: the Alarm Clock timer choice (0 = off) */
};
extern struct user_settings_record user_settings;
/* The sleep word of the application state record (app_state_record +4, 0xA802CFF8). */
struct app_state_sleep_word { unsigned short bit15 : 1; unsigned short sleep_state : 2; unsigned short rest : 13; };
extern struct app_state_sleep_word app_state_record_sleep_word;
extern void osd_close_menu(void);
extern void osd_open_menu_state_0x106(void);
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
/*
 * Set row 0x2A (42, row id 00271) of uart_cmd_dispatch_set: set the Smart Crosshair colour from a frame of the
 * PC tool. The menu offers three colours, 'White', 'Red' and 'Auto' (osd_crosshair_color_texts; 2 = automatic);
 * this command accepts any value up to CROSSHAIR_COLOR_MAX (12).
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed for a value
 * above 12; then the dispatcher answers "5600-".
 *
 * Frame byte read: 9, the colour plus 0x30.
 *
 * Phases:
 *   1. Read and check the colour, store it in crosshair_color.
 *   2. When the sleep state is 0: close the menu, open menu state 0x106, which draws the screen overlays, and
 *      close the menu again when no overlay setting is on (crosshair icon 0, Refresh Rate display off, no alarm
 *      timer, Info. On Screen off).
 *   3. Reply "5600+\r", clear the port's receive record, send the reply. No save request is made here.
 */
int uart_cmd_set_crosshair_color(unsigned char port)
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
    if ((unsigned char)value > CROSSHAIR_COLOR_MAX)
        return UART_CMD_REFUSED;
    user_settings.crosshair_color = value;
    /* Phase 2: redraw the screen overlays. */
    if (app_state_record_sleep_word.sleep_state == 0) {
        osd_close_menu();
        osd_open_menu_state_0x106();
        /* No overlay is switched on: nothing to show, close again. */
        if (user_settings.crosshair_icon == 0 && !(user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE) &&
            user_settings.alarm_clock == 0 && !(user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN))
            osd_close_menu();
    }
    /* Phase 3. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
