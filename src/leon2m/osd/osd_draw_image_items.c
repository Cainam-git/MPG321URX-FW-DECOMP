/* osd_draw_image_items  (FUN_a00aabf0)
 *
 * Draw the Image items: Brightness, Contrast, Sharpness, Color Temperature, ...
 * Name basis: proven - texts 0x18CA88
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aabf0 @ 0xa00aabf0, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the table is the symbol osd_image_item_texts; a plain for loop over i = 0..5 (with -msoft-float the
 * firmware hoists only the high part of the address of user_settings out of the loop; at plain -O3 -g the loop pass
 * hoists the full address). The settings record is a struct with the language byte at +8. Same family as
 * osd_draw_pip_pbp_items.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_image_item_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_api_fill_cells(unsigned int column, unsigned int row, unsigned char count, unsigned int value, unsigned char layer);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char plane, unsigned short column, unsigned short row, unsigned char width, unsigned int text, unsigned char layer);

#define MENU_LAYER_MAIN    0
#define PLANE_0            0
#define TEXT_ALIGN_LEFT    0
#define LANGUAGE_COUNT     29   /* texts of one entry for every language, in language order */
#define ITEM_COLUMN        0x14
#define CELL_ITEM_DISABLED 0x292   /* cell value of an item osd_is_item_enabled reports as disabled */

/* Draw the six Image items (Brightness, Contrast, Sharpness, Color
 * Temperature, ...) in the item column, rows 6, 8 .. 16. An item that
 * osd_is_item_enabled reports as disabled first gets 13 cells set to
 * CELL_ITEM_DISABLED. */
void osd_draw_image_items(void)
{
  unsigned char i;
  osd_api_set_glyph_write_address(0x92, MENU_LAYER_MAIN);
  osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
  for (i = 0; i < 6; i++) {
    if (osd_is_item_enabled(i) == 0)
      osd_api_fill_cells(ITEM_COLUMN, i * 2 + 6, 0xd, CELL_ITEM_DISABLED, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, ITEM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_image_item_texts, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
  }
}
