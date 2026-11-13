/* osd_draw_adaptive_sync_status  (FUN_a00acef4)
 *
 * Draw the two top status lines for Adaptive-Sync: the item name and OFF or ON.
 * Note: Value = bit 7 of settings word +0xA8. The OFF/ON text uses the menu language only for languages 0, 6,
 *   7 and 10, else English.
 * Name basis: derived - texts 0x188DA0 entry 'Adaptive-Sync', 0x193248 OFF/ON; called by
 *   osd_toggle_adaptive_sync
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00acef4 @ 0xa00acef4, flags -mcpu=v8 -O3 -g.
 * Source form: every access names user_settings directly (a local pointer to it changes the registers and drops
 * the reload of the language byte in the assignment).
 */
extern unsigned char osd_gaming_item_texts[];
extern unsigned char osd_off_on_texts[];
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                 /* +8 */
    unsigned char pad2[0xa8 - 9];
    unsigned int gaming_flags;              /* +0xA8 */
};
extern struct user_settings_record user_settings;
extern void osd_api_set_glyph_write_address(int address, int layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern void osd_api_fill_cells(int column, int row, int count, int value, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define PLANE_0                  0
#define MENU_LAYER_MAIN          0
#define TEXT_ALIGN_LEFT          0
#define TEXT_ALIGN_CENTRE        2
#define LANGUAGE_COUNT           29       /* texts of one entry for every language, in language order */
#define LANGUAGE_ENGLISH         1
#define STATUS_COLUMN            0x2a
#define STATUS_WIDTH             10       /* cells of the label and of the value */
#define STATUS_GLYPH_ADDRESS     0x191    /* glyph memory address given before the two texts are drawn */
#define CELL_TEXT_FIELD          0x596    /* value the text field is cleared with */
#define ADAPTIVE_SYNC_ITEM_TEXT  (5 * LANGUAGE_COUNT)   /* entry 5 of osd_gaming_item_texts (0x91 + language) */
#define GAMING_FLAG_ADAPTIVE_SYNC_BIT 7   /* bit of gaming_flags: Adaptive-Sync on */

/* Draw the two-line Adaptive-Sync status at the top of the menu: row 1 holds the item name (text 5 of
 * osd_gaming_item_texts in the menu language), row 2 the OFF or ON text for bit 7 of gaming_flags.
 * The OFF/ON text is looked up with the menu language when that is 0, 6, 7 or 10, and with English
 * (language 1) for every other language. Both lines are centred; the text mode is put back to left-aligned
 * afterwards. Takes no argument. */
void osd_draw_adaptive_sync_status(void)
{
    unsigned char text_language;

    if (user_settings.language == 0 || user_settings.language == 6 || user_settings.language == 7 || user_settings.language == 10)
        text_language = user_settings.language;
    else
        text_language = LANGUAGE_ENGLISH;
    osd_api_set_glyph_write_address(STATUS_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    osd_api_fill_cells(STATUS_COLUMN, 1, STATUS_WIDTH, CELL_TEXT_FIELD, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, STATUS_COLUMN, 1, STATUS_WIDTH, osd_get_text((unsigned int *)osd_gaming_item_texts, user_settings.language + ADAPTIVE_SYNC_ITEM_TEXT), MENU_LAYER_MAIN);
    osd_api_fill_cells(STATUS_COLUMN, 2, STATUS_WIDTH, CELL_TEXT_FIELD, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, STATUS_COLUMN, 2, STATUS_WIDTH, osd_get_text((unsigned int *)osd_off_on_texts, ((user_settings.gaming_flags >> GAMING_FLAG_ADAPTIVE_SYNC_BIT) & 1) * LANGUAGE_COUNT + text_language), MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
}
