/* osd_accept_refresh_rate_location  (FUN_a0094df0)
 *
 * Keep the highlighted corner for the refresh rate display and go back (OK)
 * Note: States 0xDD..0xE0 = Left Top .. Right Bottom; returns to the Location entry (0x53).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xDD..0xE0; texts 0x18E9F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094df0, flags -mcpu=v8 -O3 -g.
 * Source form: the row of the location is computed as (menu state + 0x23U) & 0xff, which is the menu state
 * minus 0xDD taken modulo 256; osd_request_bits is written as 'x = x | 2'.
 */
#define MENU_STATE_REFRESH_RATE_CHOICES      0x53       /* Refresh Rate choices, on the Location row (row 0) */
#define MENU_STATE_REFRESH_RATE_LOCATION_LIST 0xdd      /* + location (0..4): the location choices */
#define OSD_REQUEST_SETTINGS_CHANGED         0x02       /* bit of osd_request_bits */

extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;

extern void osd_clear_choice_highlight(unsigned char);
extern void osd_clear_choice_column(void);
extern void osd_draw_refresh_rate_choices(void);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * OK key in the location choices of the Refresh Rate display: leave the location list and return to the
 * Refresh Rate choices. The highlight of the location row is cleared, the choice column is cleared and the
 * Refresh Rate choices are drawn again, with the mark and the highlight on the OFF/ON row of osd_choice_row
 * (the value saved when the choices were opened). The menu state becomes 0x53 with the Location row
 * highlighted, and the settings-changed request is made.
 */
void osd_accept_refresh_rate_location(void)
{
    osd_clear_choice_highlight((osd_menu_state + (0x100U - MENU_STATE_REFRESH_RATE_LOCATION_LIST)) & 0xff);
    osd_clear_choice_column();
    osd_draw_refresh_rate_choices();
    osd_draw_choice_mark(1, osd_choice_row + 1, 1);
    osd_highlight_choice_row(osd_choice_row + 1, 0);
    osd_menu_state = MENU_STATE_REFRESH_RATE_CHOICES;
    osd_highlight_choice_row(0, 1);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
