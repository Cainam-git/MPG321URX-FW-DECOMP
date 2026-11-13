/* uart_cmd_put_alarm_time_digits  (FUN_a00badf8)
 *
 * Write the time of one alarm clock timer as digits into the reply frame.
 * Note: Unused standalone copy; bytes 7..9 = '0', +0x197[k], +0x19B[k].
 * Name basis: descriptive - same fields as the alarm time get command 5800262; slot = byte 0xA802CFFD
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00badf8, flags -mcpu=v8 -O3 -g.
 */
/* The two alarm time tables of the user settings, seen one byte early so that the index is the timer number
   (the tables themselves start at +0x198 and +0x19C). */
struct user_settings_view {
    unsigned char pad[0x197];
    unsigned char alarm_minutes_by_choice[4];   /* +0x197 */
    unsigned char alarm_seconds_by_choice[5];   /* +0x19B */
};
extern unsigned char uart_cmd_alarm_slot_index;
extern struct user_settings_view user_settings;
extern unsigned char uart_cmd_tx_frame[];

/* Put the time of the timer slot picked by the PC tool into reply frame bytes 7..9: '0', then its minutes and
   its seconds, each plus '0'. Not called; uart_cmd_get_alarm_slot_time does the same and sends the reply. */
void uart_cmd_put_alarm_time_digits(void)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = user_settings.alarm_minutes_by_choice[uart_cmd_alarm_slot_index] + '0';
    uart_cmd_tx_frame[9] = user_settings.alarm_seconds_by_choice[uart_cmd_alarm_slot_index] + '0';
}
