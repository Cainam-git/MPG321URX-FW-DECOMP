/* osd_draw_color_temp_choices  (FUN_a00a8570)
 *
 * Draw the Color Temperature choices and mark the current one.
 * Note: Choices Cool, Normal, Warm, Customization; current = settings byte +0x11.
 * Name basis: proven - texts 0x18DB28
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8570 @ 0xa00a8570, flags -mcpu=v8 -O3 -g.
 * Source form: one record user_settings (the firmware hoists the full address, so a plain for loop); the settings
 * record is declared as a struct with the language byte at +8 and the colour temperature byte at +0x11.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; unsigned char pad2[8]; unsigned char color_temperature; };
extern struct user_settings_record user_settings;
extern unsigned int osd_color_temp_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);
extern void osd_api_fill_cell_bytes(unsigned int plane, unsigned int column, unsigned int row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a
#define CHOICE_MARK_COLUMN  0x28   /* mark cells 0x28 and 0x29 */
#define CHOICE_MARK_CODE    0x0f   /* glyph byte of the first mark cell; the second is the next one */

/* Draw the four Color Temperature choices (Cool, Normal, Warm, Customization)
 * in the choice text column, rows 6, 8, 10, 12, and mark the current one
 * (settings byte +0x11) with the two mark glyphs. Rows wrap after entry 6. */
void osd_draw_color_temp_choices(void)
{
  unsigned char i, row;
  osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
  osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
  for (i = 0; i <= 3; i++)
    osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_color_temp_texts, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
  if (user_settings.color_temperature <= 6)
    row = user_settings.color_temperature * 2 + 6;
  else
    row = user_settings.color_temperature * 2 - 8;
  osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN, row, 1, CHOICE_MARK_CODE, MENU_LAYER_MAIN);
  osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN + 1, row, 1, CHOICE_MARK_CODE + 1, MENU_LAYER_MAIN);
}
