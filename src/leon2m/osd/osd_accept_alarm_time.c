/* osd_accept_alarm_time  (FUN_a00939b0)
 *
 * Select the edited alarm timer, store its time and go back to the Alarm Clock item.
 * Note: Sets settings +0x1A0 to the timer number and +0x1A1/+0x1A2 to its minutes/seconds.
 * Name basis: derived - OK on states 0xC5..0xC9 (handler table)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00939b0 @ 0xa00939b0-0xa0093b04 (85 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the alarm_clock byte (+0x1A0) is assigned first and then copied to osd_alarm_clock_choice (the other order
 *    gives other registers in the |= sequences);
 *  - the minutes and seconds bytes are both loaded before both are stored; the tables are indexed with the
 *    alarm_clock value minus 1 from +0x198 and +0x19C.
 */

#define MENU_STATE_ALARM_TIME_LIST   0x58    /* + row: the Alarm Clock time list, one state per timer */
#define MENU_STATE_ALARM_CLOCK_ITEM  0x12    /* Gaming page, item Alarm Clock */

#define ALARM_OFF                    0       /* alarm_clock value 0: no timer; 1..4 select a timer */

#define APP_STATE_ALARM_RUNNING      0x4000  /* app_state_record flags_0x0, bit 14 */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02    /* bit of osd_request_bits: event 0x80 */

/* The alarm part of the user settings record (user_settings, 0xA802D290). */
struct user_settings_record {
    unsigned char pad000[0x198];
    unsigned char alarm_minutes_table[4];   /* +0x198: minutes of timers 1..4 (alarm_table_0x197[alarm_clock]) */
    unsigned char alarm_seconds_table[4];   /* +0x19C: seconds of timers 1..4 (alarm_table_0x19b[alarm_clock]) */
    unsigned char alarm_clock;              /* +0x1A0: the Alarm Clock timer choice */
    unsigned char alarm_minutes;            /* +0x1A1 */
    unsigned char alarm_seconds;            /* +0x1A2 */
    unsigned char alarm_cursor_row;         /* +0x1A3: the row of the alarm digit cursor (byte_0x1a3) */
};

extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_alarm_clock_choice;
extern unsigned short app_state_record;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_draw_alarm_clock_choices(int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(int, int);
extern void osd_draw_key_guide_text(int);
extern void osd_update_key_guide(int, int);

/* OK in the Alarm Clock time list: take the timer that was edited (row alarm_cursor_row, so timer
 * alarm_cursor_row + 1) as the Alarm Clock choice, load its minutes and seconds into settings +0x1A1 / +0x1A2,
 * and go back to the Alarm Clock item (menu state 0x12). No parameters, no result.
 * In order:
 *  1. clear the highlight of the choice row osd_choice_row + 1 and set the alarm-running bit of
 *     app_state_record;
 *  2. the menu state becomes 0x58 + alarm_cursor_row; alarm_clock (and osd_alarm_clock_choice) becomes that
 *     state minus 0x57; the choice marks are redrawn for the old and the new row;
 *  3. for a timer (alarm_clock not 0) the minutes and seconds come from the two tables at +0x198 / +0x19C;
 *  4. the Alarm Clock choices are drawn again, the item row of the Alarm Clock item is highlighted, the key
 *     guide is redrawn, OSD_REQUEST_SETTINGS_CHANGED is raised and alarm_cursor_row is cleared.
 */
void osd_accept_alarm_time(void)
{
    osd_clear_choice_highlight(osd_choice_row + 1);
    app_state_record |= APP_STATE_ALARM_RUNNING;
    osd_api_set_window_enable(0, 0, 0);
    osd_menu_state = user_settings.alarm_cursor_row + MENU_STATE_ALARM_TIME_LIST;
    osd_draw_choice_mark(1, osd_choice_row + 1, 0);
    user_settings.alarm_clock = osd_menu_state - 0x57;
    osd_alarm_clock_choice = user_settings.alarm_clock;
    osd_draw_choice_mark(1, osd_menu_state - 0x56, 1);
    if (user_settings.alarm_clock != ALARM_OFF) {
        user_settings.alarm_minutes = user_settings.alarm_minutes_table[user_settings.alarm_clock - 1];
        user_settings.alarm_seconds = user_settings.alarm_seconds_table[user_settings.alarm_clock - 1];
    }
    osd_draw_alarm_clock_choices(1);
    osd_highlight_choice_row(osd_menu_state - 0x56, 0);
    osd_draw_choice_mark(1, user_settings.alarm_clock + 1, 1);
    osd_menu_state = MENU_STATE_ALARM_CLOCK_ITEM;
    osd_highlight_item_row(4, 1);
    osd_draw_key_guide(2, 5);
    osd_draw_key_guide(0, 0);
    osd_draw_key_guide(1, 2);
    osd_draw_key_guide_text(7);
    osd_update_key_guide(0, 1);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    user_settings.alarm_cursor_row = 0;
}
