/* osd_draw_navi_key_items  (FUN_a00a8230)
 *
 * Draw the Navi Key items: Up, Down, Left, Right.
 * Name basis: proven - texts 0x19158C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8230 @ 0xa00a8230, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the row loop is a static helper (draw_item_rows) inlined with (osd_navi_key_item_texts, 0x14, 4); the row
 *    count is its parameter (the firmware compares with 4 in the loop) and the table a const pointer parameter;
 *  - the settings record is declared as a struct with the language byte at +8;
 *  - built with -msoft-float, like osd_draw_pip_pbp_items, which has the same loop.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_navi_key_item_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define MENU_LAYER_MAIN  0
#define PLANE_0          0
#define TEXT_ALIGN_LEFT  0
#define LANGUAGE_COUNT   29   /* texts of one entry for every language, in language order */
#define ITEM_COLUMN      0x14

/* Draw n item texts down the item column, one per row 6, 8, 10 ...; entry i
 * is the text at index i * LANGUAGE_COUNT + language of the table. */
static void draw_item_rows(unsigned int *const texts, int column, unsigned char n)
{
  unsigned char i;
  for (i = 0; i < n; i++)
    osd_draw_text(PLANE_0, column, i * 2 + 6, 1, osd_get_text(texts, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
}

/* Draw the four items of the Navi Key page (Up, Down, Left, Right) in the
 * item column, using the glyph write address 0x92. */
void osd_draw_navi_key_items(void)
{
  osd_api_set_glyph_write_address(0x92, MENU_LAYER_MAIN);
  osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
  draw_item_rows(osd_navi_key_item_texts, ITEM_COLUMN, 4);
}
