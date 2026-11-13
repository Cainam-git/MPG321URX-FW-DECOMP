/* osd_draw_pip_location_choices_copy  (FUN_a00b3070)
 *
 * Draw the five location choices (four corners and Customize) of the Alarm Clock Location list.
 * Note: Identical copy of osd_draw_pip_location_choices.
 * Name basis: proven - texts 0x18E9F8; called by osd_open_alarm_clock_location
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3070 @ 0xa00b3070, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the language is read through a one-field record at the start of user_settings, and the loop
 * is a do-while over i = 0..4.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_location_texts[];
extern void osd_clear_choice_column(void);
extern void osd_api_set_glyph_write_address(int address, int layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define LANGUAGE_COUNT       29      /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN   0x2a    /* column of the choice texts */
#define CHOICE_FIRST_ROW     6       /* row of the first choice; the choices are two rows apart */
#define CHOICE_GLYPH_ADDRESS 0x111   /* glyph memory address given before choice texts are drawn */
#define LOCATION_CHOICES     5       /* four corners and Customize */

/* Draw the five location choices (the four corners and Customize) as the choice list: the choice column
 * is cleared and entry i of osd_location_texts in the menu language is drawn left-aligned on row 2 * i + 6.
 * Identical in code to osd_draw_pip_location_choices; called by osd_open_alarm_clock_location. */
void osd_draw_pip_location_choices_copy(void)
{
    unsigned char i;

    osd_clear_choice_column();
    osd_api_set_glyph_write_address(CHOICE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    i = 0;
    do {
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + CHOICE_FIRST_ROW, 1, osd_get_text(osd_location_texts, (unsigned short)(i * LANGUAGE_COUNT + user_settings.language)), MENU_LAYER_MAIN);
        i++;
    } while (i < LOCATION_CHOICES);
}
