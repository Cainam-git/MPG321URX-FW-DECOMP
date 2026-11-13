/* osd_draw_night_vision_choices  (FUN_a00a835c)
 *
 * Draw the Night Vision choices and mark the current one.
 * Note: Choices OFF, Normal, Strong, Strongest, A.I.; current = settings byte +0x15B.
 * Name basis: proven - texts 0x1890D4; same byte as the Night Vision quick menu (state 0x102)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a835c @ 0xa00a835c, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is declared as a struct with the language byte at +8 and the Night Vision
 * byte at +0x15B.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; unsigned char pad2[0x15b - 9]; unsigned char night_vision; };
extern struct user_settings_record user_settings;
extern unsigned int osd_night_vision_texts[];
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

/* Draw the five Night Vision choices (OFF, Normal, Strong, Strongest, A.I.)
 * in the choice text column, one per row 6, 8 .. 14, and mark the current one
 * (settings byte +0x15B) with the two mark glyphs. Rows wrap after entry 6
 * (entry 7 and above start again at row 6). */
void osd_draw_night_vision_choices(void)
{
  unsigned char i, row;
  osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
  osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
  for (i = 0; i <= 4; i++)
    osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_night_vision_texts, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
  if (user_settings.night_vision <= 6)
    row = user_settings.night_vision * 2 + 6;
  else
    row = user_settings.night_vision * 2 - 8;
  osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN, row, 1, CHOICE_MARK_CODE, MENU_LAYER_MAIN);
  osd_api_fill_cell_bytes(PLANE_0, CHOICE_MARK_COLUMN + 1, row, 1, CHOICE_MARK_CODE + 1, MENU_LAYER_MAIN);
}
