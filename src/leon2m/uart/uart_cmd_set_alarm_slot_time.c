/* uart_cmd_set_alarm_slot_time  (FUN_a00c2bd8)
 *
 * Set the time of the selected alarm clock timer from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00262; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: derived - set frame 5b00262; settings arrays +0x197 / +0x19B indexed by the selected slot
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c2bd8 @ 0xa00c2bd8-0xa00c2f08 (816 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the receive-record byte reader rx_char and the three port helpers are defined in this file and inlined by
 *    GCC at -O3 (as in uart_cmd_set_alarm_presets, uart_cmd_set_alarm_presets);
 *  - slot is an int; the alarm_clock test is written as '!=' with 'index = slot - 1' assigned in both arms (first
 *    in the equal arm), and index is an unsigned char;
 *  - alarm_running (+0 bit 14) and the sleep state (+4 bits 13..14) are bit-fields of one application state
 *    structure, and alarm_slot_index (+9) is a member of it.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           '0'       /* each value byte of the frame is the value plus 0x30 */
#define ALARM_TIME_MAX            99        /* largest minutes or seconds value of a timer */
#define ALARM_CHOICE_MAX          4         /* alarm_clock 0: no timer; 1..4 choose one of the four timers */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record { unsigned char pad000[0x198];
                              unsigned char alarm_minutes_table[4];     /* +0x198: minutes of timers 1..4 */
                              unsigned char alarm_seconds_table[4];     /* +0x19C: seconds of timers 1..4 */
                              unsigned char alarm_clock;                /* +0x1A0: the Alarm Clock timer choice */
                              unsigned char alarm_minutes;              /* +0x1A1: minutes of the chosen timer */
                              unsigned char alarm_seconds; };           /* +0x1A2: seconds of the chosen timer */
extern struct user_settings_record user_settings;
/* The application state record (0xA802CFF4) as far as it is used here. */
struct app_state_record { unsigned short flags_bit15 : 1,
                                         alarm_running : 1,             /* +0 bit 14: an alarm clock timer runs */
                                         flags_rest : 14;
                          unsigned short half_0x2;
                          unsigned short sleep_bit15 : 1,
                                         sleep_state : 2,               /* +4 bits 13..14 */
                                         sleep_rest : 13;
                          unsigned char pad6[3];
                          unsigned char alarm_slot_index; };            /* +9: uart_cmd_alarm_slot_index, the timer
                                                                           slot chosen by set row 00261 (0..4) */
extern struct app_state_record app_state_record;
extern void osd_close_menu(void);
extern void osd_open_menu_state_0x106(void);

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
extern void uart_api_send_bytes(unsigned char, int, unsigned char *);
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
 * Set row 0x34 (52, row id 00262) of uart_cmd_dispatch_set: store the minutes and seconds of one alarm clock
 * timer from a frame of the PC tool. The timer is the slot chosen before with set row 00261, which stores it in
 * uart_cmd_alarm_slot_index (app_state_record +9, 0..4); get row 00262 reads the same slot back.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed when a value
 * is above 99 or the stored Alarm Clock choice is above 4; then the dispatcher answers "5600-".
 *
 * Frame bytes read (each holds the value plus 0x30):
 *   8   minutes, 0..99
 *   9   seconds, 0..99
 *
 * Phases:
 *   1. Read and check both values and the stored Alarm Clock choice.
 *   2. Slot 0 while the Alarm Clock is off is taken as slot 1 (and stored as 1).
 *   3. When the Alarm Clock choice is this slot, the alarm-running bit is set and the values also go into
 *      alarm_minutes / alarm_seconds.
 *   4. The values go into entry slot - 1 of alarm_minutes_table / alarm_seconds_table. The index is a byte: slot 0
 *      with the Alarm Clock on gives index 0xFF, so the bytes land at settings +0x297 / +0x29B.
 *   5. Save request (osd_mark_settings_changed_copy); when the sleep state is 0 the menu is closed and menu state
 *      0x106, which draws the screen overlays, is opened.
 *   6. Reply "5600+\r", clear the port's receive record, send the reply.
 */
int uart_cmd_set_alarm_slot_time(unsigned char port)
{
    unsigned char minutes_char, seconds_char;
    unsigned char index;
    int slot;

    /* Phase 1. */
    minutes_char = rx_char(port, 8);
    seconds_char = rx_char(port, 9);
    if ((unsigned char)(minutes_char - VALUE_CHAR_BASE) > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    if ((unsigned char)(seconds_char - VALUE_CHAR_BASE) > ALARM_TIME_MAX)
        return UART_CMD_REFUSED;
    if (user_settings.alarm_clock > ALARM_CHOICE_MAX)
        return UART_CMD_REFUSED;
    /* Phase 2. */
    if (user_settings.alarm_clock == 0 && app_state_record.alarm_slot_index == 0)
        app_state_record.alarm_slot_index = 1;
    slot = app_state_record.alarm_slot_index;
    /* Phase 3: the timer being changed is the one chosen in the Alarm Clock setting. */
    if (user_settings.alarm_clock != slot)
        index = slot - 1;
    else {
        index = slot - 1;
        app_state_record.alarm_running = 1;
        user_settings.alarm_minutes = minutes_char - VALUE_CHAR_BASE;
        user_settings.alarm_seconds = seconds_char - VALUE_CHAR_BASE;
    }
    /* Phase 4. */
    user_settings.alarm_minutes_table[index] = minutes_char - VALUE_CHAR_BASE;
    user_settings.alarm_seconds_table[index] = seconds_char - VALUE_CHAR_BASE;
    /* Phase 5. */
    osd_mark_settings_changed_copy();
    if (app_state_record.sleep_state == 0) {
        osd_close_menu();
        osd_open_menu_state_0x106();
    }
    /* Phase 6. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
