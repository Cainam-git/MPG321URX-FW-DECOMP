/* osd_draw_pip_items  (FUN_a00a86e8)
 *
 * Draw the PIP items: Source, PIP Size, Location, Display Switch, Audio Switch.
 * Note: Greys Display Switch and Audio Switch (rows 12 and 14) when both inputs are the same.
 * Name basis: proven - texts 0x1828C0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a86e8 @ 0xa00a86e8, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: a plain for loop, built with -msoft-float like its siblings osd_draw_display_hdr_choices and osd_draw_pip_pbp_items (the
 * firmware keeps only the high part of the address of user_settings outside the loop).
 */
extern unsigned char user_settings[];
extern unsigned int osd_pip_item_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a
#define CELL_CHOICE_GREYED  0x296
#define SETTING_LANGUAGE      8
#define SETTING_INPUT_SOURCE  0x1e
#define SETTING_SECOND_SOURCE 0x20

/* Draw the five PIP items (Source, PIP Size, Location, Display Switch, Audio
 * Switch) in the choice text column, rows 6, 8 .. 14. When the main input and
 * the second input are the same, the cells of rows 12 and 14 (items 3 and 4)
 * are first set to CELL_CHOICE_GREYED over 11 cells, so those two texts are
 * drawn on the greyed cells. */
void osd_draw_pip_items(void)
{
    unsigned char i;
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    if (user_settings[SETTING_INPUT_SOURCE] == user_settings[SETTING_SECOND_SOURCE]) {
        osd_api_fill_cells(CHOICE_TEXT_COLUMN, 0xc, 0xb, CELL_CHOICE_GREYED, MENU_LAYER_MAIN);
        osd_api_fill_cells(CHOICE_TEXT_COLUMN, 0xe, 0xb, CELL_CHOICE_GREYED, MENU_LAYER_MAIN);
    }
    for (i = 0; i <= 4; i++)
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1,
                     osd_get_text(osd_pip_item_texts, i * LANGUAGE_COUNT + user_settings[SETTING_LANGUAGE]), MENU_LAYER_MAIN);
}
