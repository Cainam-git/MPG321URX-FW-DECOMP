/* osd_draw_key_guide_text  (FUN_a00b344c)
 *
 * Draw one key guide text in the key guide column.
 *   text_number: text index
 * Name basis: derived - texts 0x1928B0 'Move|Enter|Switch|Adjust|Select|Save|Exit|Back'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b344c @ 0xa00b344c, flags -mcpu=v8 -O3 -g.
 * Source form: the parameter is an unsigned int and is masked explicitly ('& 0xff'), which produces the
 * firmware's 'and' of the argument register; the text index is an unsigned short expression.
 */
extern unsigned char osd_key_guide_texts[];
extern void osd_api_set_glyph_write_address(unsigned int address, unsigned int layer); /* 0xa0146b50 */
extern void osd_api_set_text_mode(unsigned int mode, unsigned int layer); /* 0xa0146b6c */
extern void osd_api_fill_cells(unsigned int column, unsigned int row, unsigned int count, unsigned int value, unsigned int layer); /* 0xa0146a80 */
extern unsigned int osd_get_text(int table, unsigned short index); /* 0xa00a3844 */
extern void osd_draw_text(int plane, int column, int row, int width, unsigned int text, int layer); /* 0xa00a31a4 */
extern unsigned char user_settings_language; /* 0xa802d298 */

#define PLANE_0                 0
#define MENU_LAYER_MAIN         0
#define TEXT_ALIGN_CENTRE       2
#define LANGUAGE_COUNT          29      /* texts of one entry for every language, in language order */
#define KEY_GUIDE_COLUMN        0x37
#define KEY_GUIDE_WIDTH         4       /* cells of one key guide text */
#define KEY_GUIDE_ROW           9       /* the first of the three key guide rows (the others are 0xE and 0x13) */
#define KEY_GUIDE_GLYPH_ADDRESS 0x1e5   /* glyph memory address given before the text is drawn */
#define CELL_TEXT_FIELD         0x596   /* value the text field is cleared with */

/* Draw one key guide text (Move, Enter, Switch, Adjust, Select, Save, Exit or Back) in the first key guide
 * row, in the menu language.
 *   text_number: entry of osd_key_guide_texts, 0..7 in the order listed above.
 * The field is cleared first and the text is drawn centred. */
void osd_draw_key_guide_text(unsigned int text_number)
{
    unsigned int masked_number;
    unsigned short text_index;

    osd_api_set_glyph_write_address(KEY_GUIDE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    masked_number = text_number & 0xff;
    osd_api_fill_cells(KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, KEY_GUIDE_WIDTH, CELL_TEXT_FIELD, MENU_LAYER_MAIN);
    text_index = (masked_number * LANGUAGE_COUNT + user_settings_language) & 0xffff;
    masked_number = osd_get_text(osd_key_guide_texts, text_index);
    osd_draw_text(PLANE_0, KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, KEY_GUIDE_WIDTH, masked_number, MENU_LAYER_MAIN);
}
