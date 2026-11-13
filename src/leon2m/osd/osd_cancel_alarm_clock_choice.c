/* osd_cancel_alarm_clock_choice  (FUN_a0093808)
 *
 * Restore the alarm clock choice saved on entry and go back (left key)
 * Note: Copies 0xA8025C56 back into settings byte +0x1A0.
 * Name basis: derived - left on states 0x56..0x5B (handler table)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093808, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a plain byte array; osd_choice_row and the timer byte are read again at
 * each use; osd_highlight_item_row is a tail call.
 */
#define SETTINGS_ALARM_CLOCK     0x1a0          /* offset of the Alarm Clock timer choice */
#define MENU_STATE_ALARM_CHOICES 0x56           /* + choice row: row 0 Location, row 1 OFF, rows 2..5 the four timers */
#define MENU_STATE_ALARM_CLOCK_ITEM 0x12        /* Gaming page, item Alarm Clock (item row 4) */

extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned char osd_alarm_clock_choice;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * Left key in the Alarm Clock choices: put back the choice that was saved in osd_choice_row when the list was
 * opened (settings byte +0x1A0), clear the highlight of the row the menu state was on, highlight the restored
 * row and draw its mark, copy the choice to osd_alarm_clock_choice, and go back to the Alarm Clock item and its row.
 */
void osd_cancel_alarm_clock_choice(void)
{
  user_settings[SETTINGS_ALARM_CLOCK] = osd_choice_row;
  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_ALARM_CHOICES);
  osd_highlight_choice_row(osd_choice_row + 1, 0);
  osd_draw_choice_mark(1, osd_choice_row + 1, 1);
  osd_alarm_clock_choice = user_settings[SETTINGS_ALARM_CLOCK];
  osd_menu_state = MENU_STATE_ALARM_CLOCK_ITEM;
  osd_highlight_item_row(4, 1);
}
