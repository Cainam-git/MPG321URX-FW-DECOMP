/* osd_cancel_refresh_rate_display  (FUN_a00935e8)
 *
 * Restore the Refresh Rate on/off setting saved on entry and go back (left key)
 * Note: Copies 0xA8025C56 back into bit 12 of the settings word +0xA8.
 * Name basis: derived - left on states 0x53..0x55 (handler table)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00935e8, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a struct with bit 12 of the word at +0xA8 as a 1-bit bit-field; its base
 * stays in a register and the bit is read again at each use. osd_highlight_item_row is a tail call.
 */
#define MENU_STATE_REFRESH_RATE_CHOICES 0x53    /* + choice row: row 0 Location, row 1 OFF, row 2 ON */
#define MENU_STATE_REFRESH_RATE_ITEM    0x11    /* Gaming page, item Refresh Rate (item row 3) */

struct settings_gaming_flags {
    unsigned char pad[0xa8];
    unsigned int flags_high : 19;
    unsigned int refresh_rate : 1;              /* bit 12 (GAMING_FLAG_REFRESH_RATE 0x1000): Refresh Rate display on */
    unsigned int flags_low : 12;
};
extern struct settings_gaming_flags user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);

/*
 * Left key in the Refresh Rate choices: put back the setting that was saved in osd_choice_row when the list was
 * opened, clear the highlight of the row the menu state was on, highlight the restored row, clear and draw its
 * mark, and go back to the Refresh Rate item and its row.
 */
void osd_cancel_refresh_rate_display(void)
{
    user_settings.refresh_rate = osd_choice_row;
    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_REFRESH_RATE_CHOICES);
    osd_highlight_choice_row(user_settings.refresh_rate + 1, 0);
    osd_draw_choice_mark(1, user_settings.refresh_rate + 1, 0);
    osd_draw_choice_mark(1, user_settings.refresh_rate + 1, 1);
    osd_menu_state = MENU_STATE_REFRESH_RATE_ITEM;
    osd_highlight_item_row(3, 1);
}
