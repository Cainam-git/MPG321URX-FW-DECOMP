/* osd_draw_navi_key_function_choices  (FUN_a00b7b8c)
 *
 * Draw one page of the functions a Navi key direction can start.
 *   mode: list page 0/1
 * Note: Page 0 = list entries 0..6 (screen rows 6..18), page 1 = entries 7..11 (rows 6..14).
 * Name basis: proven - texts 0x1935bc 'OFF|Brightness|Game Mode|Smart Crosshair|...'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7b8c @ 0xa00b7b8c-0xa00b7d14 (98 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: built like osd_draw_night_vision_quick_menu; the last loop compares with a limit variable n = 2 (cmp 2; bcs).
 */
#define GLYPH_WRITE_ADDRESS   0x111
#define TEXT_MODE_NORMAL      0
#define CHOICE_TEXT_COLUMN    0x2A              /* column of the choice texts */
#define LANGUAGE_COUNT        29                /* text index = entry * 29 + language byte of the settings */
#define NAVI_PAGE0_LAST       6                 /* page 0 holds entries 0..6, page 1 entries 7..11 */
#define NAVI_PAGE1_LAST       11
#define CELL_PAGE_MARK        0x692
#define CELL_BLANK            0x792

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_navi_function_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_write_reg_cc(int, int);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned short, int, unsigned int, int);

/*
 * Draw one page of the list of functions a Navi key direction can start.
 *
 *   mode  0: the entries 0..6 (rows 6, 8 ... 18)
 *         other: the entries 7..11 (rows 6, 8 ... 14)
 *
 * Before the texts, two cells at columns 0x2d and 0x2e of row 0x14 are filled with 0x692. After them the
 * layer's registers 0xCC/0xCD are set to 0x792 and, in byte plane 1, the two cells at columns 0x2d and 0x2e of
 * row 0x15 are given the values 0x28 and 0x29.
 * Called by osd_cancel_navi_key_function, osd_select_prev_navi_key_function, osd_select_next_navi_key_function and osd_draw_item_choices (osd_draw_item_choices).
 */
void osd_draw_navi_key_function_choices(unsigned char mode)
{
    unsigned char i, n;

    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
    osd_api_fill_cells(0x2d, 0x14, 2, CELL_PAGE_MARK, 0);
    if (mode == 0) {
        for (i = 0; i <= NAVI_PAGE0_LAST; i++)
            osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_navi_function_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
    } else {
        for (i = NAVI_PAGE0_LAST + 1; i <= NAVI_PAGE1_LAST; i++)
            osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 - 8, 1, osd_get_text(osd_navi_function_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
    }
    osd_api_write_reg_cc(CELL_BLANK, 0);
    n = 2;
    for (i = 0; i < n; i++)
        osd_api_fill_cell_bytes(1, i + 0x2d, 0x15, 1, i + 0x28, 0);
}
