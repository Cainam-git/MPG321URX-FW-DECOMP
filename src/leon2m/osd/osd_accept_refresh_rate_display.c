/* osd_accept_refresh_rate_display  (FUN_a0093534)
 *
 * Keep the chosen Refresh Rate on/off setting and go back (OK key)
 * Note: Returns to the Refresh Rate item (state 0x11).
 * Name basis: derived - OK on states 0x54/0x55 (handler table)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093534, flags -mcpu=v8 -O3 -g.
 * Source form: the Refresh Rate switch is a 1-bit bit-field of the settings record (bit 12 of the word at
 * +0xA8), read through a struct pointer, again at each use.
 */
#define MENU_STATE_REFRESH_RATE_CHOICES 0x53    /* + choice row: row 0 Location, row 1 OFF, row 2 ON */
#define MENU_STATE_REFRESH_RATE_ITEM    0x11    /* Gaming page, item Refresh Rate (item row 3) */
#define OSD_REQUEST_SETTINGS_CHANGED    0x02    /* bit of osd_request_bits */

struct settings_gaming_flags {
    unsigned char pad[0xa8];
    struct {
        unsigned int flags_high : 19;
        unsigned int refresh_rate : 1;          /* bit 12 (GAMING_FLAG_REFRESH_RATE 0x1000): Refresh Rate display on */
        unsigned int flags_low : 12;
    } gaming_flags;                             /* +0xA8 */
};
extern struct settings_gaming_flags user_settings;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * OK key in the Refresh Rate choices. Clear the highlight and the mark of the row saved on entry (osd_choice_row + 1), take
 * the highlight off the present row, and draw the mark at the row of the present setting (the mark there is
 * cleared and drawn again). Back to the Refresh Rate item and its row, and the settings-changed request.
 */
void osd_accept_refresh_rate_display(void)
{
    struct settings_gaming_flags *settings;

    osd_clear_choice_highlight(osd_choice_row + 1);
    osd_draw_choice_mark(1, osd_choice_row + 1, 0);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_REFRESH_RATE_CHOICES, 0);
    settings = &user_settings;
    osd_draw_choice_mark(1, settings->gaming_flags.refresh_rate + 1, 0);
    osd_draw_choice_mark(1, settings->gaming_flags.refresh_rate + 1, 1);
    osd_menu_state = MENU_STATE_REFRESH_RATE_ITEM;
    osd_highlight_item_row(3, 1);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
