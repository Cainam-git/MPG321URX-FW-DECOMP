/* osd_draw_pip_location_choices  (FUN_a00ab340)
 *
 * Draw the PIP Location choices (four corners and Customize)
 * Name basis: proven - texts 0x18E9F8; called by osd_enter_pip_location_choices
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ab340 @ 0xa00ab340, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the settings record is a struct with the language byte at +8; the text index is narrowed to
 * unsigned short at the call; the loop is a do-while.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_location_texts[];
extern void osd_clear_choice_column(void);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a

/* Draw the five PIP Location choices (the four corners and Customize) in the
 * choice text column, rows 6, 8 .. 14, after osd_clear_choice_column. Called
 * by osd_enter_pip_location_choices. */
void osd_draw_pip_location_choices(void)
{
    unsigned char i;
    osd_clear_choice_column();
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    i = 0;
    do {
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_location_texts, (unsigned short)(i * LANGUAGE_COUNT + user_settings.language)), MENU_LAYER_MAIN);
        i++;
    } while (i <= 4);
}
