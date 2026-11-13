/* osd_draw_game_mode_quick_menu  (FUN_a00b8ca8)
 *
 * Draw one page of the Game Mode quick menu and highlight the current mode when it is on that page.
 *   page: 0 = entries 0..3, other = entries 4 and 5
 * Name basis: proven - texts 0x195f24 'Premium Color|User|FPS|...'; callers
 *   osd_select_next/prev_quick_game_mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b8ca8 @ 0xa00b8ca8-0xa00b8e7c (117 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the 'k > 3' test and its subtraction are kept although k = osd_choice_row & 3 never exceeds 3;
 * the last call is a tail call.
 */
#define TEXT_MODE_NUMBER      2
#define GLYPH_WRITE_ADDRESS   0x6f
#define QUICK_MENU_TEXT_COLUMN 6
#define QUICK_MENU_TEXT_WIDTH 0xa
#define LANGUAGE_COUNT        29                /* text index = entry * 29 + language byte of the settings */
#define QUICK_MENU_WINDOW     4                 /* highlight window switched off when no row is highlighted */
#define MARK_GLYPH_FIRST      0x1c              /* glyph values written next to the highlighted row */

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_game_mode_texts[];
extern unsigned char osd_choice_row;
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_clear_quick_menu_rows(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned short, int, unsigned int, int);
extern void osd_highlight_quick_menu_row(unsigned char, unsigned char);
extern void osd_api_set_window_enable(int, int, int);

/*
 * Draw one page of the Game Mode quick menu.
 *
 *   page  0: the game mode entries 0..3 at rows 5, 7, 9 and 11
 *         other: the entries 4 and 5 at rows 5 and 7
 *
 * osd_choice_row holds the highlighted entry: its bits 2 and up give the page it is on, its low two bits the
 * row on that page. When it is on the page drawn here, that row is highlighted and two cells beside it (columns
 * 4 and 5) get the byte values 0x1c and 0x1d; otherwise window 4 is switched off.
 * Callers: osd_select_next_quick_game_mode and osd_select_prev_quick_game_mode.
 */
void osd_draw_game_mode_quick_menu(unsigned char page)
{
    unsigned char i, row;

    osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_clear_quick_menu_rows();
    if (page != 0) {
        for (i = 4; i <= 5; i++)
            osd_draw_text(0, QUICK_MENU_TEXT_COLUMN, i * 2 - 3, QUICK_MENU_TEXT_WIDTH, osd_get_text(osd_game_mode_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
    } else {
        for (i = 0; i <= 3; i++)
            osd_draw_text(0, QUICK_MENU_TEXT_COLUMN, i * 2 + 5, QUICK_MENU_TEXT_WIDTH, osd_get_text(osd_game_mode_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
    }
    if (page == osd_choice_row >> 2) {
        osd_highlight_quick_menu_row(osd_choice_row & 3, 0);
        row = osd_choice_row & 3;
        if (row > 3)
            row -= 4;
        for (i = 0; i <= 1; i++)
            osd_api_fill_cell_bytes(0, i + 4, row * 2 + 5, 1, i + MARK_GLYPH_FIRST, 0);
    } else {
        osd_api_set_window_enable(QUICK_MENU_WINDOW, 0, 0);
    }
}
