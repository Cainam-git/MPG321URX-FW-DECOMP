/* osd_draw_crosshair_items  (FUN_a00a82c4)
 *
 * Draw the Smart Crosshair items: Icon, Color, Position, Reset.
 * Name basis: proven - texts 0x18F984 entries 1..4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a82c4 @ 0xa00a82c4, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the same loop is inlined in osd_draw_item_choices (same flags).
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_crosshair_item_texts[];
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(unsigned char c, unsigned char v);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a

/* Draw the four items of the Smart Crosshair page (Icon, Color, Position,
 * Reset): entries 1..4 of the crosshair text table, one per row 6, 8, 10, 12 in
 * the choice text column, using the glyph write address 0x111. Called by the accept and cancel handlers of the
 * crosshair colour and icon lists and by osd_close_position_editor. */
void osd_draw_crosshair_items(void)
{
    unsigned char i;
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    for (i = 0; i <= 3; i++)
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_crosshair_item_texts, i * LANGUAGE_COUNT + user_settings.language + LANGUAGE_COUNT), MENU_LAYER_MAIN);
}
