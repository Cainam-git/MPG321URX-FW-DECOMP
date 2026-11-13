/* osd_draw_language_list  (FUN_a00a87cc)
 *
 * Draw the visible page of seven menu languages.
 * Name basis: proven - texts 0x18D3D4 (language names); callers osd_select_prev|next_language
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a87cc @ 0xa00a87cc, flags -mcpu=v8 -O3 -g.
 * Source form: the five pages are an if / else if chain with one loop each, as in the firmware.
 */
extern unsigned int osd_language_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned short row, int width, unsigned int text, int layer);
extern void osd_draw_cell_run(unsigned int across, unsigned int rising, unsigned int attribute, unsigned int column, unsigned int row, unsigned int count, unsigned int first_glyph);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define CHOICE_TEXT_COLUMN  0x2a
#define CELL_BLANK          0x792

/* Draw one page of the language list in the choice text column. page 0..3 each
 * show seven language names (table entries 7 * page + 0..6) at rows 6, 8 .. 18;
 * page 4 shows the single last name (entry 0x1c) at row 6. Then a run of two
 * cells with attribute CELL_BLANK and glyphs 0x28, 0x29 is drawn at column 0x2d,
 * row 0x15. Called by osd_select_prev_language and osd_select_next_language. */
void osd_draw_language_list(unsigned char page)
{
    unsigned char i;
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    if (page == 0) {
        for (i = 0; i <= 6; i++)
            osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_language_texts, i), MENU_LAYER_MAIN);
    } else if (page == 1) {
        for (i = 0; i <= 6; i++)
            osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_language_texts, i + 7), MENU_LAYER_MAIN);
    } else if (page == 2) {
        for (i = 0; i <= 6; i++)
            osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_language_texts, i + 0xe), MENU_LAYER_MAIN);
    } else if (page == 3) {
        for (i = 0; i <= 6; i++)
            osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_language_texts, i + 0x15), MENU_LAYER_MAIN);
    } else if (page == 4) {
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, 6, 1, osd_get_text(osd_language_texts, 0x1c), MENU_LAYER_MAIN);
    }
    osd_draw_cell_run(1, 1, CELL_BLANK, 0x2d, 0x15, 2, 0x28);
}
