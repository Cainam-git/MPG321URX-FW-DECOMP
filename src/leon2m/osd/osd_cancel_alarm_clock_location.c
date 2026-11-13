/* osd_cancel_alarm_clock_location  (FUN_a0094f58)
 *
 * Restore the alarm clock location saved on entry and go back (left)
 * Note: Copies 0xA8025C55 back into settings byte +0x13F; returns to state 0x56.
 * Name basis: derived - handler table 0xA802422C: left on states 0xE2..0xE6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094f58, flags -mcpu=v8 -O3 -g. The last call is a tail call.
 */
#define MENU_STATE_ALARM_CHOICES       0x56     /* Alarm Clock choices, on the Location row (row 0) */

extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern unsigned char user_settings_alarm_clock_location;
extern unsigned int osd_menu_state;

extern void osd_clear_choice_column(void);
extern void osd_draw_alarm_clock_choices(int);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * Left key in the location choices of the Alarm Clock display: put back the location saved in osd_edit_value
 * when the list was opened (settings byte +0x13F) and return to the Alarm Clock choices, as
 * osd_accept_alarm_clock_location does, but without the settings-changed request.
 */
void osd_cancel_alarm_clock_location(void)
{
    user_settings_alarm_clock_location = osd_edit_value;
    osd_clear_choice_column();
    osd_draw_alarm_clock_choices(1);
    osd_draw_choice_mark(1, osd_choice_row + 1, 1);
    osd_highlight_choice_row(osd_choice_row + 1, 0);
    osd_menu_state = MENU_STATE_ALARM_CHOICES;
    osd_highlight_choice_row(0, 1);
}
