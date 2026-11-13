/* osd_draw_screen_size_choices  (FUN_a00aaf48)
 *
 * Draw the Screen Size choices and mark the current one.
 * Note: Choices Auto, 4:3, 16:9, 16:10, 1:1, 24.5", 27"; current = settings byte +0x1A4; unusable ones greyed.
 * Name basis: proven - texts 0x1910B0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aaf48 @ 0xa00aaf48, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the settings record is a byte array; the arm "choice <= 6" comes first;
 *  - the loop bound is a byte local count = 7: the firmware compares with 7 and branches on "unsigned >=", which
 *    only survives when the constant reaches the compare late (a literal 7 is folded to "i <= 6", comparing with 6).
 */
extern unsigned char osd_screen_size_texts[];
extern unsigned char osd_list_id;
extern unsigned char user_settings[];
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a
#define CHOICE_MARK_COLUMN  0x28   /* mark cells 0x28 and 0x29 */
#define CHOICE_MARK_CODE    0x0f   /* glyph byte of the first mark cell; the second is the next one */
#define CELL_CHOICE_GREYED  0x296
#define LIST_ID_SCREEN_SIZE 0x0e
#define SETTING_LANGUAGE    8      /* byte offsets in user_settings */
#define SETTING_SCREEN_SIZE 0x1a4

/* Draw the seven Screen Size choices (Auto, 4:3, 16:9, 16:10, 1:1, 24.5",
 * 27") in the choice text column, rows 6, 8 .. 18, and mark the current one
 * (settings byte +0x1A4). A choice that osd_is_choice_enabled reports as
 * disabled first gets 10 cells set to CELL_CHOICE_GREYED. While drawing, the
 * open list id (osd_list_id) is set to LIST_ID_SCREEN_SIZE, which
 * osd_is_choice_enabled reads, and restored at the end. */
void osd_draw_screen_size_choices(void)
{
    unsigned char saved_list_id;
    unsigned char i;
    unsigned char screen_size;
    unsigned char mark_row;
    unsigned char count = 7;
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    saved_list_id = osd_list_id;
    osd_list_id = LIST_ID_SCREEN_SIZE;
    for (i = 0; i < count; i++) {
        if (osd_is_choice_enabled(i) == 0)
            osd_api_fill_cells(CHOICE_TEXT_COLUMN, i * 2 + 6, 10, CELL_CHOICE_GREYED, MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, (unsigned short)(i * 2 + 6), 1,
                     osd_get_text((unsigned int *)osd_screen_size_texts, i * LANGUAGE_COUNT + user_settings[SETTING_LANGUAGE]), MENU_LAYER_MAIN);
    }
    screen_size = user_settings[SETTING_SCREEN_SIZE];
    if (screen_size <= 6)
        mark_row = screen_size * 2 + 6;
    else
        mark_row = screen_size * 2 - 8;
    osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN, mark_row, 1, CHOICE_MARK_CODE, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN + 1, mark_row, 1, CHOICE_MARK_CODE + 1, MENU_LAYER_MAIN);
    osd_list_id = saved_list_id;
}
