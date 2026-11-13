/* uart_cmd_get_alarm_slot_time  (FUN_a00bccf4)
 *
 * Report the time of the selected alarm clock timer to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800262 (row 0x1c).
 * Name basis: derived - get frame 5800262; settings arrays at +0x198 (minutes) and +0x19C (seconds) indexed by
 *   the selected slot
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bccf4, flags -mcpu=v8 -O3 -g.
 * Source form: the two alarm time tables are seen one byte early (the structure view below), so the slot index is the
 * index; the head builder and uart_cmd_clear_rx take an unsigned char.
 */
/* The two alarm time tables of the user settings, seen one byte early so that the index is the timer number
   (the tables themselves start at +0x198 and +0x19C). */
struct user_settings_view {
    unsigned char pad[0x197];
    unsigned char alarm_minutes_by_choice[4];   /* +0x197 */
    unsigned char alarm_seconds_by_choice[4];   /* +0x19B */
};
extern struct user_settings_view user_settings;
extern unsigned char uart_cmd_alarm_slot_index;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "5800262" (row 0x1c of uart_cmd_get_rows): the minutes and the seconds of the timer slot selected by the PC tool (uart_cmd_alarm_slot_index): byte 7 is '0', byte 8 the minutes plus '0', byte 9 the seconds plus '0'.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_alarm_slot_time(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = user_settings.alarm_minutes_by_choice[uart_cmd_alarm_slot_index] + '0';
    uart_cmd_tx_frame[9] = user_settings.alarm_seconds_by_choice[uart_cmd_alarm_slot_index] + '0';
    uart_cmd_build_get_reply(0x1c);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
