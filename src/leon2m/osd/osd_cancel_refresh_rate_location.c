/* osd_cancel_refresh_rate_location  (FUN_a0094e70)
 *
 * Restore the refresh rate display location saved on entry and go back (left)
 * Note: Returns to state 0x53.
 * Name basis: derived - handler table 0xA802422C: left on states 0xDD..0xE1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094e70, flags -mcpu=v8 -O3 -g.
 */
#define MENU_STATE_REFRESH_RATE_CHOICES      0x53       /* Refresh Rate choices, on the Location row (row 0) */

extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings_refresh_rate_location;

extern void osd_clear_choice_column(void);
extern void osd_draw_refresh_rate_choices(void);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * Left key in the location choices of the Refresh Rate display: put back the location saved in osd_edit_value
 * when the list was opened (settings byte +0x13E) and return to the Refresh Rate choices, as
 * osd_accept_refresh_rate_location does, but without the settings-changed request.
 */
void osd_cancel_refresh_rate_location(void)
{
    user_settings_refresh_rate_location = osd_edit_value;
    osd_clear_choice_column();
    osd_draw_refresh_rate_choices();
    osd_draw_choice_mark(1, osd_choice_row + 1, 1);
    osd_highlight_choice_row(osd_choice_row + 1, 0);
    osd_menu_state = MENU_STATE_REFRESH_RATE_CHOICES;
    osd_highlight_choice_row(0, 1);
}
