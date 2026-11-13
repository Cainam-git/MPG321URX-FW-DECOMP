/* osd_accept_alarm_clock_off  (FUN_a0093754)
 *
 * Leave the Alarm Clock list on OK at the OFF entry: redraw the marks and go back.
 * Note: Does not test or write the timer choice; copies settings byte +0x1A0 to 0xA802AFEA and returns to
 *   state 0x12.
 * Name basis: derived - OK on state 0x57 (handler table)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093754, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a plain byte array and the timer byte is read again at each use;
 * osd_alarm_clock_choice is a byte.
 */
#define SETTINGS_ALARM_CLOCK     0x1a0          /* offset of the Alarm Clock timer choice */
#define MENU_STATE_ALARM_CHOICES 0x56           /* + choice row: row 0 Location, row 1 OFF, rows 2..5 the four timers */
#define MENU_STATE_ALARM_CLOCK_ITEM 0x12        /* Gaming page, item Alarm Clock (item row 4) */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits */

extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned char osd_alarm_clock_choice;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * OK key on the OFF row of the Alarm Clock choices. Clear the highlight and the mark of the row saved on entry
 * (osd_choice_row + 1), take the highlight off the row the menu state is on, clear the mark at the row of
 * settings byte +0x1A0 (the Alarm Clock choice), copy that byte to osd_alarm_clock_choice, and draw the mark.
 * Back to the Alarm Clock item and its row, and the settings-changed request.
 */
void osd_accept_alarm_clock_off(void)
{
  osd_clear_choice_highlight(osd_choice_row + 1);
  osd_draw_choice_mark(1, osd_choice_row + 1, 0);
  osd_highlight_choice_row(osd_menu_state - MENU_STATE_ALARM_CHOICES, 0);
  osd_draw_choice_mark(1, user_settings[SETTINGS_ALARM_CLOCK] + 1, 0);
  osd_alarm_clock_choice = user_settings[SETTINGS_ALARM_CLOCK];
  osd_draw_choice_mark(1, user_settings[SETTINGS_ALARM_CLOCK] + 1, 1);
  osd_menu_state = MENU_STATE_ALARM_CLOCK_ITEM;
  osd_highlight_item_row(4, 1);
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
