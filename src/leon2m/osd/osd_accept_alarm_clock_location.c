/* osd_accept_alarm_clock_location  (FUN_a0094ed8)
 *
 * Keep the highlighted corner for the alarm clock display and go back (OK)
 * Note: States 0xE2..0xE5 = Left Top .. Right Bottom; returns to the Location entry (0x56).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xE2..0xE5; texts 0x18E9F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094ed8, flags -mcpu=v8 -O3 -g.
 * Source form: the row of the location is computed as (menu state + 0x1e) & 0xff, which is the menu state minus
 * 0xE2 taken modulo 256; osd_request_bits is written as 'x = x | 2'.
 */
#define MENU_STATE_ALARM_CHOICES       0x56     /* Alarm Clock choices, on the Location row (row 0) */
#define MENU_STATE_ALARM_LOCATION_LIST 0xe2     /* + location (0..4): the location choices */
#define OSD_REQUEST_SETTINGS_CHANGED   0x02     /* bit of osd_request_bits */

extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_column(void);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_alarm_clock_choices(int);

/*
 * OK key in the location choices of the Alarm Clock display: leave the location list and return to the
 * Alarm Clock choices. The highlight of the location row is cleared, the choice column is cleared and the
 * Alarm Clock choices are drawn again, with the mark and the highlight on the row osd_choice_row + 1 (the
 * choice saved when the choices were opened). The menu state becomes 0x56 with the Location row highlighted, and
 * the settings-changed request is made.
 */
void osd_accept_alarm_clock_location(void)
{
    osd_clear_choice_highlight((osd_menu_state + (0x100U - MENU_STATE_ALARM_LOCATION_LIST)) & 0xff);
    osd_clear_choice_column();
    osd_draw_alarm_clock_choices(1);
    osd_draw_choice_mark(1, osd_choice_row + 1, 1);
    osd_highlight_choice_row(osd_choice_row + 1, 0);
    osd_menu_state = MENU_STATE_ALARM_CHOICES;
    osd_highlight_choice_row(0, 1);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
