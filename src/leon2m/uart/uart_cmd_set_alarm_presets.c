/* uart_cmd_set_alarm_presets  (FUN_a00c49b8)
 *
 * Set the four alarm clock timer times and the chosen timer from a PC tool command.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b001f (26-byte frame); minutes/seconds into +0x198..+0x19F, choice into +0x1A0; redraws the
 *   overlays.
 * Name basis: proven - set row 0x8e; same fields as osd_open_alarm_time_editor (+0x198 minutes / +0x19C
 *   seconds) and +0x1A0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c49b8 @ 0xa00c49b8-0xa00c4ec4 (1292 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are defined in
 *    this file, so GCC inlines them at -O3;
 *  - the minutes byte of each timer is read through the inlined static rx_byte() (one return per port), the
 *    seconds byte and the choice byte through an explicit port if-chain into an unsigned char that is copied into
 *    an int (char_copy) before the minutes test; seconds is computed into an unsigned short;
 *  - the choice is tested through an unsigned char copy (choice_test) for both tests;
 *  - app_state_record and its sleep word are one structure with bit-fields.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': each value byte of the frame is the value plus 0x30 */

#define ALARM_TIME_MAX            99        /* largest minutes or seconds value of a timer */
#define ALARM_OFF                 0         /* alarm_clock 0: no timer; 1..4 choose one of the four timers */
#define ALARM_CHOICE_MAX          4

#define GAMING_FLAG_REFRESH_RATE  0x1000    /* user settings +0xA8 bit 12: Refresh Rate display */
#define SETTINGS_INFO_ON_SCREEN   0x400000  /* user settings +0xAC bit 22: Info. On Screen */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The application state record (0xA802CFF4) as far as it is used here: halfword +0 and the sleep word +4. */
struct app_state_record {
    unsigned short flags_bit15 : 1,
                   alarm_running : 1,           /* +0 bit 14: an alarm clock timer runs */
                   flags_rest : 14;
    unsigned short half_0x2;
    unsigned short sleep_bit15 : 1,
                   sleep_state : 2,             /* +4 bits 13..14 (2 = fake sleep) */
                   sleep_rest : 13;
};
extern struct app_state_record app_state_record;

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0xa8];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned char pad0b0[0x190 - 0xb0];
    unsigned char crosshair_icon;               /* +0x190: the Smart Crosshair icon */
    unsigned char pad191[0x198 - 0x191];
    unsigned char alarm_minutes_table[4];       /* +0x198: minutes of timers 1..4 */
    unsigned char alarm_seconds_table[4];       /* +0x19C: seconds of timers 1..4 */
    unsigned char alarm_clock;                  /* +0x1A0: the Alarm Clock timer choice */
    unsigned char alarm_minutes;                /* +0x1A1: minutes of the chosen timer */
    unsigned char alarm_seconds;                /* +0x1A2: seconds of the chosen timer */
};
extern struct user_settings_record user_settings;
extern void uart_api_send_bytes(unsigned char, int, unsigned char *);
extern void osd_mark_settings_changed_copy(void);
extern void osd_close_menu(void);
extern void osd_open_menu_state_0x106(void);
extern void panel_wait_sync_pulse(void);

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
static unsigned char rx_byte(unsigned char port, int offset)
{
    if (port == 2)
        return uart_cmd_rx_record_port2[offset];
    if (port == 3)
        return uart_cmd_rx_record_port3[offset];
    return uart_cmd_rx_record[offset];
}

/*
 * Set row 0x8E (142) of uart_cmd_dispatch_set: store the times of the four alarm clock timers and the timer
 * choice, all from one frame of MSI's PC tool.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value out of range; then
 * nothing is replied here and the dispatcher answers "5600-".
 *
 * Frame bytes read (each value byte holds the value plus 0x30):
 *   6 + 2n, 7 + 2n   minutes and seconds of timer n + 1 (n = 0..3), each 0..99
 *   0xE              the timer choice 0..4 (0 = off)
 *
 * Phases:
 *   1. Timers 1 to 4, in order: read, check and store minutes and seconds. A bad value stops the routine at
 *      once, so the timers before it keep their new times.
 *   2. The choice: stored in alarm_clock; for a timer (1..4) the alarm-running bit is set and the timer's times
 *      are copied into alarm_minutes / alarm_seconds.
 *   3. Save request (osd_mark_settings_changed_copy).
 *   4. When the sleep state is 0: close the menu, wait four sync pulses, open menu state 0x106, which draws the
 *      screen overlays, and close the menu again when no overlay setting is on (crosshair icon 0, Refresh Rate
 *      display off, no alarm timer, Info. On Screen off).
 *   5. Reply "5600+\r", clear the port's receive record, send the reply.
 */
int uart_cmd_set_alarm_presets(unsigned char port)
{
    unsigned char minutes, seconds_char, choice_char, timer_index;
    unsigned short choice, seconds;
    unsigned char choice_test;
    int char_copy;

    /* Phase 1: timer 1, frame bytes 6 and 7. */
    minutes = rx_byte(port, 6);
    if (port == 2)
        seconds_char = uart_cmd_rx_record_port2[7];
    else if (port == 3)
        seconds_char = uart_cmd_rx_record_port3[7];
    else
        seconds_char = uart_cmd_rx_record[7];
    char_copy = seconds_char;
    minutes -= VALUE_CHAR_BASE;
    if (minutes > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    seconds = char_copy - VALUE_CHAR_BASE;
    if ((unsigned char)seconds > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    user_settings.alarm_minutes_table[0] = minutes;
    user_settings.alarm_seconds_table[0] = seconds;

    /* Timer 2, frame bytes 8 and 9. */
    minutes = rx_byte(port, 8);
    if (port == 2)
        seconds_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        seconds_char = uart_cmd_rx_record_port3[9];
    else
        seconds_char = uart_cmd_rx_record[9];
    char_copy = seconds_char;
    minutes -= VALUE_CHAR_BASE;
    if (minutes > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    seconds = char_copy - VALUE_CHAR_BASE;
    if ((unsigned char)seconds > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    user_settings.alarm_minutes_table[1] = minutes;
    user_settings.alarm_seconds_table[1] = seconds;

    /* Timer 3, frame bytes 10 and 11. */
    minutes = rx_byte(port, 10);
    if (port == 2)
        seconds_char = uart_cmd_rx_record_port2[11];
    else if (port == 3)
        seconds_char = uart_cmd_rx_record_port3[11];
    else
        seconds_char = uart_cmd_rx_record[11];
    char_copy = seconds_char;
    minutes -= VALUE_CHAR_BASE;
    if (minutes > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    seconds = char_copy - VALUE_CHAR_BASE;
    if ((unsigned char)seconds > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    user_settings.alarm_minutes_table[2] = minutes;
    user_settings.alarm_seconds_table[2] = seconds;

    /* Timer 4, frame bytes 12 and 13. */
    minutes = rx_byte(port, 12);
    if (port == 2)
        seconds_char = uart_cmd_rx_record_port2[13];
    else if (port == 3)
        seconds_char = uart_cmd_rx_record_port3[13];
    else
        seconds_char = uart_cmd_rx_record[13];
    char_copy = seconds_char;
    minutes -= VALUE_CHAR_BASE;
    if (minutes > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    seconds = char_copy - VALUE_CHAR_BASE;
    if ((unsigned char)seconds > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    user_settings.alarm_minutes_table[3] = minutes;
    user_settings.alarm_seconds_table[3] = seconds;

    /* Phase 2: the timer choice, frame byte 0xE. */
    if (port == 2)
        choice_char = uart_cmd_rx_record_port2[0xe];
    else if (port == 3)
        choice_char = uart_cmd_rx_record_port3[0xe];
    else
        choice_char = uart_cmd_rx_record[0xe];
    char_copy = choice_char;
    choice = char_copy - VALUE_CHAR_BASE;
    choice_test = choice;
    if (choice_test > ALARM_CHOICE_MAX)
        return UART_CMD_REFUSED;
    user_settings.alarm_clock = choice;
    if (choice_test != ALARM_OFF) {
        /* A timer is chosen: start it with its stored time (table row choice - 1). */
        app_state_record.alarm_running = 1;
        timer_index = char_copy - (VALUE_CHAR_BASE + 1);
        user_settings.alarm_minutes = user_settings.alarm_minutes_table[timer_index];
        user_settings.alarm_seconds = user_settings.alarm_seconds_table[timer_index];
    }

    /* Phase 3. */
    osd_mark_settings_changed_copy();

    /* Phase 4: redraw the screen overlays with the new alarm settings. */
    if (app_state_record.sleep_state == 0) {
        osd_close_menu();
        panel_wait_sync_pulse();
        panel_wait_sync_pulse();
        panel_wait_sync_pulse();
        panel_wait_sync_pulse();
        osd_open_menu_state_0x106();
        /* No overlay is switched on: nothing to show, close again. */
        if (user_settings.crosshair_icon == 0 && !(user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE) &&
            user_settings.alarm_clock == ALARM_OFF && !(user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN))
            osd_close_menu();
    }

    /* Phase 5. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
