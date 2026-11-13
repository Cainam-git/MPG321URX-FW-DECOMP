/* osd_draw_gi_items  (FUN_a00aaaac)
 *
 * Draw the G.I. items: KVM, Smart Crosshair, Optix Scope.
 * Name basis: proven - texts 0x18A360
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aaaac @ 0xa00aaaac, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the same shape as osd_draw_pip_pbp_items / osd_draw_display_hdr_choices -
 *  - the language byte is the field of one struct user_settings (the firmware has "or ...,0x290" inside the loop
 *    and a load of [+8]); a separate symbol for user_settings + 8 would let the loop pass hoist the full address;
 *  - the text table is an extern array symbol;
 *  - the item loop is a label and "if (item <= 2) goto next_item", not a for loop.
 */
extern void FUN_4008e2a4(void);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_set_window_enable(unsigned char window, unsigned short on, unsigned char layer);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(unsigned char, unsigned char);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char plane, unsigned short column, unsigned short row, unsigned char width, unsigned int text, unsigned char layer);
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_gi_item_texts[];

#define panel_wait_sync_pulse FUN_4008e2a4
#define MENU_LAYER_MAIN    0
#define PLANE_0            0
#define TEXT_ALIGN_LEFT    0
#define LANGUAGE_COUNT     29   /* texts of one entry for every language, in language order */
#define ITEM_COLUMN        0x14
#define CELL_BLANK         0x792
#define CELL_ITEM_DISABLED 0x292   /* cell value of an item osd_is_item_enabled reports as disabled */

/* Draw the three G.I. items (KVM, Smart Crosshair, Optix Scope) in the item
 * column, rows 6, 8, 10. First the area of rows 5..20 from column 0x13 (19
 * cells wide) is cleared (after panel_wait_sync_pulse), and so are two glyph
 * bytes at column 0x1C, row 0x15; window 5 is switched off. An item that
 * osd_is_item_enabled reports as disabled gets 13 cells set to
 * CELL_ITEM_DISABLED before its text is drawn. */
void osd_draw_gi_items(void)
{
    unsigned char i, item;
    unsigned int text;
    panel_wait_sync_pulse();
    for (i = 5; i <= 20; i++) {
        osd_api_fill_cell_bytes(PLANE_0, 0x13, i, 0x13, 0, MENU_LAYER_MAIN);
        osd_api_fill_cells(0x13, i, 0x13, CELL_BLANK, MENU_LAYER_MAIN);
    }
    osd_api_fill_cell_bytes(PLANE_0, 0x1c, 0x15, 2, 0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(5, 0, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0x92, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    item = 0;
next_item:
    if ((osd_is_item_enabled(item) & 0xff) == 0)
        osd_api_fill_cells(ITEM_COLUMN, item * 2 + 6, 0xd, CELL_ITEM_DISABLED, MENU_LAYER_MAIN);
    text = osd_get_text(osd_gi_item_texts, item * LANGUAGE_COUNT + user_settings.language);
    osd_draw_text(PLANE_0, ITEM_COLUMN, item * 2 + 6, 1, text, MENU_LAYER_MAIN);
    item++;
    if (item <= 2)
        goto next_item;
}
