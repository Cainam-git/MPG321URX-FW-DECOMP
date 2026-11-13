/* osd_draw_professional_items  (FUN_a00aa9d8)
 *
 * Draw the Professional items: Pro Mode, Low Blue Light, Image Enhancement.
 * Name basis: proven - texts 0x188634
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa9d8 @ 0xa00aa9d8, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the text table is an extern array symbol, not a cast integer constant; with a symbol the compiler
 * keeps only the high part of the table address and of the address of user_settings in registers across the loop,
 * as the firmware does. The settings record is a struct with the language byte at +8. The routine ends with a tail
 * call.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_professional_item_texts[];
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char plane, unsigned short column, unsigned short row, unsigned char width, unsigned int text, unsigned char layer);
extern void osd_draw_low_blue_light_switch(void);

#define MENU_LAYER_MAIN    0
#define PLANE_0            0
#define TEXT_ALIGN_LEFT    0
#define LANGUAGE_COUNT     29   /* texts of one entry for every language, in language order */
#define ITEM_COLUMN        0x14
#define CELL_ITEM_DISABLED 0x292   /* cell value of an item osd_is_item_enabled reports as disabled */

/* Draw the three Professional items (Pro Mode, Low Blue Light, Image
 * Enhancement) in the item column, rows 6, 8, 10. An item that
 * osd_is_item_enabled reports as disabled first gets 15 cells set to
 * CELL_ITEM_DISABLED. Ends by drawing the Low Blue Light switch. Not called
 * directly (reached through a table). */
void osd_draw_professional_items(void)
{
    unsigned char i;
    osd_api_set_glyph_write_address(0x92, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    for (i = 0; i <= 2; i++) {
        if (!osd_is_item_enabled(i))
            osd_api_fill_cells(ITEM_COLUMN, i * 2 + 6, 0xf, CELL_ITEM_DISABLED, MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, ITEM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_professional_item_texts, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
    }
    osd_draw_low_blue_light_switch();
}
