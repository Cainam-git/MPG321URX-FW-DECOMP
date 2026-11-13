/* osd_draw_input_source_items  (FUN_a00b3ba0)
 *
 * Draw the Input Source items (the inputs) and the auto scan switch.
 * Name basis: proven - input names 0x196B24; called by osd_draw_tab_page
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3ba0 @ 0xa00b3ba0, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: user_settings is used as {u32 at +0; u8 at +8}; the row-4 test is an if/else inside the loop
 * with one draw call in each arm.
 */
extern unsigned char osd_input_name_texts[];
struct user_settings_record { unsigned int word_0x0; unsigned char pad[4]; unsigned char language; };
extern struct user_settings_record user_settings;
extern void osd_api_set_glyph_write_address(int address, int layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);
extern void osd_draw_toggle_switch(unsigned char item, unsigned char on);

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define ITEM_COLUMN          0x14    /* column of the item texts */
#define ITEM_FIRST_ROW       6       /* row of the first item; the items are two rows apart */
#define ITEM_GLYPH_ADDRESS   0x92    /* glyph memory address given before the item texts are drawn */
#define INPUT_ITEMS          5
#define INPUT_ITEM_AUTO_SCAN 4       /* the item with the switch */
#define AUTO_SCAN_BIT        9       /* bit of settings word 0 shown by the switch */

/* Draw the five items of the Input Source page, then the Auto Scan switch. Items 0..3 are entries 0..3 of
 * osd_input_name_texts (the input names, the same in every language); item 4 is entry 4 + language of the
 * same table. The texts are left-aligned in the item column (0x14), two rows apart from row 6. The switch is
 * drawn from bit 9 of the first settings word. Called by osd_draw_tab_page. */
void osd_draw_input_source_items(void)
{
    unsigned char i;

    osd_api_set_glyph_write_address(ITEM_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    for (i = 0; i < INPUT_ITEMS; i++) {
        if (i == INPUT_ITEM_AUTO_SCAN)
            osd_draw_text(PLANE_0, ITEM_COLUMN, i * 2 + ITEM_FIRST_ROW, 1, osd_get_text((unsigned int *)osd_input_name_texts, i + user_settings.language), MENU_LAYER_MAIN);
        else
            osd_draw_text(PLANE_0, ITEM_COLUMN, i * 2 + ITEM_FIRST_ROW, 1, osd_get_text((unsigned int *)osd_input_name_texts, i), MENU_LAYER_MAIN);
    }
    osd_draw_toggle_switch(INPUT_ITEM_AUTO_SCAN, (user_settings.word_0x0 >> AUTO_SCAN_BIT) & 1);
}
