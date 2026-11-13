/* uart_cmd_set_alarm_clock  (FUN_a00c2f08)
 *
 * Set the Alarm Clock timer choice from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00260; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00260; settings byte +0x1A0 (osd_enter_alarm_clock_choices); also loads the
 *   timer presets +0x1A1/+0x1A2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c2f08 @ 0xa00c2f08-0xa00c3180 (158 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file and inlined by GCC at -O3; the value byte is read with the
 *    port test written out in the routine;
 *  - choice is an unsigned short, cast to a byte for the range test and for the two table indexes;
 *  - the halfwords +0 and +4 of the application state record are members of one structure (the code reaches +4
 *    from the record's base); alarm_running is set through a 1-bit bit-field (the mask form schedules two
 *    instructions differently);
 *  - the alarm tables are declared from +0x197 / +0x19B so that the choice itself is the index.
 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define ALARM_OFF                 0         /* alarm_clock 0: no timer; 1..4 choose one of the four timers */
#define ALARM_CHOICE_MAX          4
#define GAMING_FLAG_REFRESH_RATE  0x1000    /* user settings +0xA8 bit 12: Refresh Rate display */
#define SETTINGS_INFO_ON_SCREEN   0x400000  /* user settings +0xAC bit 22: Info. On Screen */

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0xa8];
    unsigned int gaming_flags;                  /* +0xA8: GAMING_FLAG_* switches */
    unsigned int settings_page_flags;           /* +0xAC: SETTINGS_* switches */
    unsigned char pad0b0[0x190 - 0xb0];
    unsigned char crosshair_icon;               /* +0x190: the Smart Crosshair icon (0 = none) */
    unsigned char pad191[0x197 - 0x191];
    unsigned char alarm_minutes_by_choice[4];   /* +0x197: entry n = minutes of timer n (alarm_minutes_table
                                                   starts at +0x198) */
    unsigned char alarm_seconds_by_choice[5];   /* +0x19B: entry n = seconds of timer n (alarm_seconds_table
                                                   starts at +0x19C) */
    unsigned char alarm_clock;                  /* +0x1A0: the Alarm Clock timer choice */
    unsigned char alarm_minutes;                /* +0x1A1: minutes of the chosen timer */
    unsigned char alarm_seconds;                /* +0x1A2: seconds of the chosen timer */
};
/* The application state record (0xA802CFF4) as far as it is used here: halfword +0 and the sleep word +4. */
struct app_state_record {
    union { unsigned short flags;
            struct { unsigned short flags_bit15 : 1,
                                    alarm_running : 1,      /* +0 bit 14: an alarm clock timer runs */
                                    flags_rest : 14; } flag_bits; };
    unsigned short half_0x2;
    struct { unsigned short sleep_bit15 : 1, sleep_state : 2, sleep_rest : 13; } sleep_word;   /* +4: sleep state
                                                                                                  in bits 13..14 */
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
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
 * Set row 0x32 (50, row id 00260) of uart_cmd_dispatch_set: set the Alarm Clock choice (0 = off, 1..4 = one of
 * the four timers) from a frame of the PC tool and load that timer's time.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed for a choice
 * above 4; then the dispatcher answers "5600-".
 *
 * Frame byte read: 9, the choice plus 0x30.
 *
 * Phases:
 *   1. Read and check the choice.
 *   2. Set the alarm-running bit (for every choice, 0 included), store the choice in alarm_clock and copy the
 *      chosen timer's minutes and seconds into alarm_minutes / alarm_seconds. For choice 0 the bytes copied are
 *      settings +0x197 and +0x19B (the last minutes entry).
 *   3. When the sleep state is 0: close the menu, open menu state 0x106, which draws the screen overlays, and
 *      close the menu again when no overlay setting is on (crosshair icon 0, Refresh Rate display off, no alarm
 *      timer, Info. On Screen off).
 *   4. Reply "5600+\r", clear the port's receive record, send the reply. No save request is made here.
 */
int uart_cmd_set_alarm_clock(unsigned char port)
{
    unsigned char value;
    unsigned short choice;

    /* Phase 1. */

    if (port == 2)
        value = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value = uart_cmd_rx_record_port3[9];
    else
        value = uart_cmd_rx_record[9];
    choice = value - VALUE_CHAR_BASE;
    if ((unsigned char)choice > ALARM_CHOICE_MAX)
        return UART_CMD_REFUSED;
    /* Phase 2. */
    app_state_record.flag_bits.alarm_running = 1;
    user_settings.alarm_clock = choice;
    user_settings.alarm_minutes = user_settings.alarm_minutes_by_choice[(unsigned char)choice];
    user_settings.alarm_seconds = user_settings.alarm_seconds_by_choice[(unsigned char)choice];
    /* Phase 3: redraw the screen overlays. */
    if (app_state_record.sleep_word.sleep_state == 0) {
        osd_close_menu();
        osd_open_menu_state_0x106();
        /* No overlay is switched on: nothing to show, close again. */
        if (user_settings.crosshair_icon == 0 && !(user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE) &&
            user_settings.alarm_clock == ALARM_OFF && !(user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN))
            osd_close_menu();
    }
    /* Phase 4. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
