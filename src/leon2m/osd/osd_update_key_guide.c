/* osd_update_key_guide  (FUN_a00b34d4)
 *
 * Redraw the two key guide texts that changed.
 *   upper: first text
 *   lower: second text
 * Note: Last shown pair = nibbles of byte 0xA802D419.
 * Name basis: derived - texts 0x1928B0; called by almost every item handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b34d4 @ 0xa00b34d4, flags -mcpu=v8 -O3 -g.
 * Source form: the two-step draw (clear the field, draw the text) is a static helper written once and
 * inlined twice; the same step appears alone in osd_draw_key_guide_text.
 */
extern unsigned char osd_key_guide_texts[];
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                 /* +8 */
    unsigned char pad2[0x189 - 9];
    unsigned char key_guide_shown;          /* +0x189: text numbers last shown, upper nibble = row 0xE, lower nibble = row 0x13 */
};
extern struct user_settings_record user_settings;
extern void osd_api_set_glyph_write_address(int address, int layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern void osd_api_fill_cells(int column, int row, int count, int value, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define PLANE_0                  0
#define MENU_LAYER_MAIN          0
#define TEXT_ALIGN_CENTRE        2
#define LANGUAGE_COUNT           29      /* texts of one entry for every language, in language order */
#define KEY_GUIDE_COLUMN         0x37
#define KEY_GUIDE_WIDTH          4       /* cells of one key guide text */
#define KEY_GUIDE_ROW_2          0xe     /* second key guide row (the first, row 9, is drawn by osd_draw_key_guide_text) */
#define KEY_GUIDE_ROW_3          0x13
#define KEY_GUIDE_GLYPH_ADDRESS_2 0x1ee  /* glyph memory address given before the text of row 0xE */
#define KEY_GUIDE_GLYPH_ADDRESS_3 0x1f7  /* the same for row 0x13 */
#define CELL_TEXT_FIELD          0x596   /* value the text field is cleared with */

/* Clear one key guide field and draw the text in the menu language. */
static void draw_key_text(unsigned int row, unsigned int text_number)
{
    osd_api_fill_cells(KEY_GUIDE_COLUMN, row, KEY_GUIDE_WIDTH, CELL_TEXT_FIELD, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, KEY_GUIDE_COLUMN, row, KEY_GUIDE_WIDTH, osd_get_text((unsigned int *)osd_key_guide_texts, text_number * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
}

/* Show the key guide texts of the second and third key guide rows, redrawing only the one that changed.
 *   upper: text number for row 0xE (Move 0, Enter 1, Switch 2, Adjust 3, Select 4, Save 5, Exit 6, Back 7).
 *   lower: text number for row 0x13.
 * The texts last shown are kept in user_settings byte +0x189 (upper in the high nibble, lower in the low
 * nibble); a text is redrawn only when its number differs from the stored one. 0xFF stored there matches no
 * text number and so forces both to be redrawn. Called by almost every item handler. */
void osd_update_key_guide(unsigned char upper, unsigned char lower)
{
    osd_api_set_glyph_write_address(KEY_GUIDE_GLYPH_ADDRESS_2, 0);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    if (upper != user_settings.key_guide_shown >> 4)
        draw_key_text(KEY_GUIDE_ROW_2, upper);
    osd_api_set_glyph_write_address(KEY_GUIDE_GLYPH_ADDRESS_3, 0);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    if (lower != (user_settings.key_guide_shown & 0xf))
        draw_key_text(KEY_GUIDE_ROW_3, lower);
    user_settings.key_guide_shown = (upper << 4) + lower;
}
