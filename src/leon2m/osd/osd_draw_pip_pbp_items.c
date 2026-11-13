/* osd_draw_pip_pbp_items  (FUN_a00b3c80)
 *
 * Draw the PIP/PBP items: OFF, PIP, PBP.
 * Name basis: proven - texts 0x196678; called by osd_draw_tab_page
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3c80 @ 0xa00b3c80, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: a plain for loop over i = 0..2; with -msoft-float the build keeps only the high part of the
 * settings address outside the loop (at plain -O3 -g the whole address is hoisted).
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_pip_pbp_texts[];
extern void osd_api_set_glyph_write_address(unsigned short address, unsigned char layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define LANGUAGE_COUNT       29      /* texts of one entry for every language, in language order */
#define PIP_PBP_COLUMN       0x16    /* column of the item texts */
#define ITEM_FIRST_ROW       6       /* row of the first item; the items are two rows apart */
#define ITEM_GLYPH_ADDRESS   0x92    /* glyph memory address given before the item texts are drawn */
#define PIP_PBP_ITEMS        3       /* OFF, PIP, PBP */

/* Draw the three items of the PIP/PBP page (OFF, PIP, PBP): entry i of osd_pip_pbp_texts in the menu
 * language, left-aligned at column 0x16 on row 2 * i + 6. Called by osd_draw_tab_page. */
void osd_draw_pip_pbp_items(void)
{
  unsigned char i;

  osd_api_set_glyph_write_address(ITEM_GLYPH_ADDRESS, 0);
  osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
  for (i = 0; i < PIP_PBP_ITEMS; i++)
    osd_draw_text(PLANE_0, PIP_PBP_COLUMN, i * 2 + ITEM_FIRST_ROW, 1, osd_get_text(osd_pip_pbp_texts, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
}
