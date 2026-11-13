/* osd_draw_night_vision_quick_menu  (FUN_a00ad970)
 *
 * Draw the Night Vision quick menu list.
 * Name basis: proven - texts 0x1890D4; quick menu state 0x102
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ad970 @ 0xa00ad970-0xa00adaf4 (97 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the second loop has its own counter j; the mode != 0 arm comes first.
 */
#define LANGUAGE_COUNT 29  /* languages per text entry */

/* Settings record (user_settings): the menu language. */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;  /* +8 */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_night_vision_texts[];
extern unsigned char osd_choice_row;
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned short, int, unsigned int, int);
extern void osd_highlight_quick_menu_row(unsigned char, unsigned char);
extern void osd_draw_quick_menu_mark(unsigned char, unsigned char);
extern void osd_api_set_window_enable(int, int, int);

/* Draw the list of the Night Vision quick menu (menu state 0x102). The quick menu area (rows
 * 4..11) is cleared first.
 *   mode: the page of the list. Page 0 draws the first four texts of the Night Vision table
 *         (entries 0..3) at column 6, rows 5, 7, 9 and 11; any other page draws entry 4 alone at row 5.
 * osd_choice_row holds the cursor: bits 2.. are its page, bits 0..1 its row on the page. When the
 * cursor is on the page just drawn, its row is highlighted and marked; otherwise highlight
 * window 4 is switched off. */
void osd_draw_night_vision_quick_menu(unsigned char mode)
{
    unsigned char i, j;

    osd_api_set_text_mode(2, 0);
    osd_api_set_glyph_write_address(0x6f, 0);
    panel_wait_sync_pulse();
    for (i = 4; i <= 0xb; i++) {
        osd_api_fill_cell_bytes(0, 3, i, 0x10, 0, 0);
        osd_api_fill_cells(3, i, 0x10, 0x792, 0);
    }
    if (mode != 0) {
        /* Entry 4. */
        osd_draw_text(0, 6, 5, 0xa, osd_get_text(osd_night_vision_texts, user_settings.language + 4 * LANGUAGE_COUNT), 0);
    } else {
        for (j = 0; j <= 3; j++)
            osd_draw_text(0, 6, j * 2 + 5, 0xa, osd_get_text(osd_night_vision_texts, j * LANGUAGE_COUNT + user_settings.language), 0);
    }
    if (mode == osd_choice_row >> 2) {
        osd_highlight_quick_menu_row(osd_choice_row & 3, 0);
        osd_draw_quick_menu_mark(osd_choice_row & 3, 1);
    } else {
        osd_api_set_window_enable(4, 0, 0);
    }
}
