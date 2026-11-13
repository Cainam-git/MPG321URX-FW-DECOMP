/* osd_draw_display_hdr_choices  (FUN_a00a8654)
 *
 * Draw the DisplayHDR choices.
 * Note: Choices True Black 400, Peak 1000 nits, EOTF Boost.
 * Name basis: proven - texts 0x190CEC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8654 @ 0xa00a8654, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: a plain for loop, built with -msoft-float like osd_draw_pip_pbp_items (at plain -O3 -g the loop pass hoists
 * the full address of user_settings out of the loop; the firmware keeps only the high part outside). The settings
 * record is a struct with the language byte at +8. The text table is the symbol DAT_00190cec_hdr_mode_text.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int DAT_00190cec_hdr_mode_text[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a

/* Draw the three DisplayHDR choices (True Black 400, Peak 1000 nits, EOTF
 * Boost) in the choice text column, rows 6, 8, 10. Nothing is marked here. */
void osd_draw_display_hdr_choices(void)
{
  unsigned char i;
  osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
  osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
  for (i = 0; i <= 2; i++)
    osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(DAT_00190cec_hdr_mode_text, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
}
