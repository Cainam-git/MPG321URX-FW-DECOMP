/* osd_draw_oled_care_items  (FUN_a00aa83c)
 *
 * Draw the MSI OLED Care items on the current page.
 * Name basis: proven - texts 0x185E78 'Pixel Shift|Panel Protect|...|OLED Panel Info.'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa83c @ 0xa00aa83c, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the row count is an unsigned int variable (count = page ? 1 : 7), the table an extern array symbol
 * and the settings record accessed directly (a struct with the language byte at +8).
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_oled_care_item_texts[];
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_set_window_enable(int window, int on, int layer);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char plane, unsigned short column, unsigned short row, unsigned char width, unsigned int text, unsigned char layer);
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned short column, unsigned char row, unsigned char count, unsigned char first_glyph);

#define MENU_LAYER_MAIN    0
#define PLANE_0            0
#define TEXT_ALIGN_LEFT    0
#define LANGUAGE_COUNT     29   /* texts of one entry for every language, in language order */
#define ITEMS_PER_PAGE     7
#define ITEM_COLUMN        0x14
#define ITEM_WIDTH         0x11
#define CELL_BLANK         0x792
#define CELL_ITEM_DISABLED 0x292   /* cell value of an item osd_is_item_enabled reports as disabled */

/* Draw the MSI OLED Care items of one page in the item column. The area of
 * rows 5..0x14 from column 0x13 (19 cells wide) is cleared first (after
 * panel_wait_sync_pulse), and so are two glyph bytes at column 0x1C, row
 * 0x15; window 5 is switched off. Then the item texts are written at rows 6, 8
 * ...: seven items for page 0, one item for any other page; the text of item i
 * is entry (i + page * 7) of the OLED Care text table. An item that
 * osd_is_item_enabled reports as disabled first gets its cells set to
 * CELL_ITEM_DISABLED. Last, a run of two cells at column 0x1C, row 0x15 is
 * drawn with glyphs 0x28, 0x29. Called by osd_draw_tab_page, osd_redraw_page_after_notice and the select
 * prev / next OLED Care item handlers. */
void osd_draw_oled_care_items(unsigned char page)
{
    unsigned char i;
    panel_wait_sync_pulse();
    for (i = 5; i <= 0x14; i++) {
        osd_api_fill_cell_bytes(PLANE_0, 0x13, i, 0x13, 0, MENU_LAYER_MAIN);
        osd_api_fill_cells(0x13, i, 0x13, CELL_BLANK, MENU_LAYER_MAIN);
    }
    osd_api_fill_cell_bytes(PLANE_0, 0x1c, 0x15, 2, 0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(5, 0, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0x92, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    {
        unsigned int count = page ? 1 : ITEMS_PER_PAGE;
        for (i = 0; i < count; i++) {
            if (!osd_is_item_enabled(i))
                osd_api_fill_cells(ITEM_COLUMN, i * 2 + 6, ITEM_WIDTH, CELL_ITEM_DISABLED, MENU_LAYER_MAIN);
            osd_draw_text(PLANE_0, ITEM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_oled_care_item_texts, (i + page * ITEMS_PER_PAGE) * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
        }
    }
    osd_draw_cell_run(1, 1, CELL_BLANK, 0x1c, 0x15, 2, 0x28);
}
