/* osd_enter_refresh_rate_choices  (FUN_a0093464)
 *
 * Open the Refresh Rate choices (On/Off, Location) on the current setting.
 * Note: Choice states 0x53 (Location), 0x54/0x55 (off/on = bit 12 of settings +0xA8); saved copy in
 *   0xA8025C56.
 * Name basis: derived - OK/right on Gaming item 0x11 = 'Refresh Rate' (texts 0x188DA0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093464, flags -mcpu=v8 -O3 -g.
 * Source form: the Refresh Rate switch is a 1-bit bit-field of the settings record (hi:19, refresh_rate:1,
 * lo:12, first field = most significant bit), read again from memory at each use. A mask-and-shift on the word
 * folds the 0xA8 offset into the symbol; the bit-field keeps the base and the offset as the firmware does.
 * The last call is a tail call.
 */
#define MENU_STATE_GAME_ITEMS_BASE     0x0e     /* menu state of the first Gaming item (Game Mode) */
#define MENU_STATE_REFRESH_RATE_CHOICES 0x53    /* + choice row: row 0 Location, row 1 OFF, row 2 ON (states 0x53..0x55) */

/* Settings word +0xA8: only bit 12 is used here. */
struct settings_gaming_flags {
    unsigned char pad[0xa8];
    unsigned int flags_high : 19;
    unsigned int refresh_rate : 1;              /* bit 12 (GAMING_FLAG_REFRESH_RATE 0x1000): Refresh Rate display on */
    unsigned int flags_low : 12;
};
extern struct settings_gaming_flags user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * OK or right key on the Refresh Rate item of the Gaming page: open its choice list on the present setting.
 * The mark at the row of the present value (row 1 OFF, row 2 ON) is cleared, the value is saved in
 * osd_choice_row so that the left key can restore it, the item row is highlighted with style 2, and the menu
 * state becomes the state of the OFF or ON row, whose choice row is then highlighted.
 */
void osd_enter_refresh_rate_choices(void)
{
    osd_draw_choice_mark(1, user_settings.refresh_rate + 1, 0);
    osd_choice_row = user_settings.refresh_rate;
    osd_highlight_item_row(osd_menu_state - MENU_STATE_GAME_ITEMS_BASE, 2);
    osd_menu_state = user_settings.refresh_rate + MENU_STATE_REFRESH_RATE_CHOICES + 1;
    osd_highlight_choice_row(user_settings.refresh_rate + 1, 1);
}
