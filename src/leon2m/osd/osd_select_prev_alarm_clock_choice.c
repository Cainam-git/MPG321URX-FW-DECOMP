/* osd_select_prev_alarm_clock_choice  (FUN_a009aa34)
 *
 * Move to the previous allowed Alarm Clock choice (up key) and store it.
 * Note: Wraps inside the states 0x56..0x5B; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0x56..0x5B; writes settings byte +0x1A0 (timer
 *   number)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009aa34 @ 0xa009aa34, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk back is written (u16)state - BASE + (COUNT - 1), taken modulo the choice count in a second statement;
 *  - the settings record is a byte array; the timer choice is the byte at +0x1A0;
 *  - osd_menu_state and osd_choice_row are read again for each use.
 */

#define MENU_STATE_ALARM_CHOICES    0x56        /* + choice row: 0 Location, 1 OFF, 2..5 the timers */
#define ALARM_CHOICE_COUNT          6
#define USER_SETTINGS_ALARM_CLOCK   0x1a0       /* the Alarm Clock timer choice (0 = OFF, 1..4 = timers) */
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Up key in the Alarm Clock choice list (rows Location, OFF and four timers): move the highlight to the previous
 * row, wrapping from the first row to the last. Rows that osd_is_choice_enabled rejects are skipped.
 *
 * Every row below Location stores its number minus 1 in the timer choice byte (+0x1A0); on the Location row the
 * saved choice in osd_choice_row is written back. The mark of the saved choice (row osd_choice_row + 1) is
 * switched off while the highlight is on that row and on otherwise.
 */
void osd_select_prev_alarm_clock_choice(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_ALARM_CHOICES);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_ALARM_CHOICES + (ALARM_CHOICE_COUNT - 1);
        row = row % ALARM_CHOICE_COUNT;
        osd_menu_state = row + MENU_STATE_ALARM_CHOICES;
    } while (osd_is_choice_enabled(row) != 1);
    if (osd_menu_state > MENU_STATE_ALARM_CHOICES)
        user_settings[USER_SETTINGS_ALARM_CLOCK] = osd_menu_state - (MENU_STATE_ALARM_CHOICES + 1);
    else
        user_settings[USER_SETTINGS_ALARM_CLOCK] = osd_choice_row;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_ALARM_CHOICES, CHOICE_ROW_EDGED);
    if (osd_menu_state - MENU_STATE_ALARM_CHOICES == osd_choice_row + 1)
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row + 1, CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row + 1, CHOICE_MARK_ON);
}
