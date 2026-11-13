/* osd_draw_refresh_rate_choices  (FUN_a00a8440)
 *
 * Draw the Refresh Rate choices (OFF, ON, Location) and mark the current one.
 * Note: Mark from bit 12 of settings word +0xA8.
 * Name basis: derived - texts 0x193248 OFF/ON and 0x18E9F8 'Location'; called by
 *   osd_accept|cancel_refresh_rate_location
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8440 @ 0xa00a8440, flags -mcpu=v8 -O3 -g.
 * Source form: every access names user_settings directly (a local pointer to it moves the address load); the
 * language byte is at +8 and the gaming flags word at +0xA8.
 */
extern unsigned char osd_location_texts[];
extern unsigned char osd_off_on_texts[];
struct user_settings_record { unsigned char pad[8]; unsigned char language; unsigned char pad2[0xa8 - 9]; unsigned int gaming_flags; };
extern struct user_settings_record user_settings;
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cell_bytes(unsigned int plane, unsigned int column, unsigned int row, unsigned char count, unsigned char value, unsigned char layer);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a
#define CHOICE_MARK_COLUMN  0x28   /* mark cells 0x28 and 0x29 */
#define CHOICE_MARK_CODE    0x0f   /* glyph byte of the first mark cell; the second is the next one */
#define LOCATION_TEXT_INDEX 0x91   /* = 5 * 29: the Location text is entry 5 of its table */
#define REFRESH_RATE_SHIFT  12     /* Refresh Rate display, bit of gaming_flags */

/* Draw the Refresh Rate choices in the choice text column: row 6 Location, row
 * 8 OFF, row 10 ON, and mark the current one (row 8 or 10, from bit 12 of the
 * gaming flags) with the two mark glyphs. Called by the accept and cancel
 * handlers of the Refresh Rate location list. */
void osd_draw_refresh_rate_choices(void)
{
    unsigned char i;
    unsigned char sel;
    unsigned char row;
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, 6, 1, osd_get_text((unsigned int *)osd_location_texts, user_settings.language + LOCATION_TEXT_INDEX), MENU_LAYER_MAIN);
    for (i = 1; i <= 2; i++)
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text((unsigned int *)osd_off_on_texts, (i - 1) * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
    sel = ((user_settings.gaming_flags >> REFRESH_RATE_SHIFT) & 1) + 1;
    if (sel <= 6)
        row = sel * 2 + 6;
    else
        row = sel * 2 - 8;
    osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN, row, 1, CHOICE_MARK_CODE, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN + 1, row, 1, CHOICE_MARK_CODE + 1, MENU_LAYER_MAIN);
}
