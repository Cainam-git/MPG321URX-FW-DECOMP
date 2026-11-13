/* osd_draw_crosshair_color_choices  (FUN_a00b3ac8)
 *
 * Draw the Smart Crosshair colour choices: White, Red, Auto.
 * Name basis: proven - texts 0x18E54C; called by osd_open_crosshair_color
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3ac8 @ 0xa00b3ac8, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the language is read as byte 8 of user_settings (an unsigned char array); a plain for loop over
 * i = 0..2. With -msoft-float the build keeps only the high part of the settings address outside the loop (at
 * plain -O3 -g the whole address is hoisted). The table address is 0x18E54C.
 */
extern unsigned char user_settings[];
extern unsigned int osd_crosshair_color_texts[];
extern void osd_api_set_glyph_write_address(unsigned short address, unsigned char layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define LANGUAGE_COUNT       29      /* texts of one entry for every language, in language order */
#define SETTING_LANGUAGE     8       /* user_settings byte: menu language */
#define CHOICE_TEXT_COLUMN   0x2a    /* column of the choice texts */
#define CHOICE_FIRST_ROW     6       /* row of the first choice; the choices are two rows apart */
#define CHOICE_GLYPH_ADDRESS 0x111   /* glyph memory address given before choice texts are drawn */
#define CROSSHAIR_COLOR_CHOICES 3    /* White, Red, Auto */

/* Draw the three Smart Crosshair colour choices (White, Red, Auto): entry i of osd_crosshair_color_texts in the
 * menu language is drawn left-aligned on row 2 * i + 6. The choice column is not cleared here. Called by
 * osd_open_crosshair_color. */
void osd_draw_crosshair_color_choices(void)
{
    unsigned char i;

    osd_api_set_glyph_write_address(CHOICE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    for (i = 0; i < CROSSHAIR_COLOR_CHOICES; i++)
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + CHOICE_FIRST_ROW, 1,
                     osd_get_text(osd_crosshair_color_texts, i * LANGUAGE_COUNT + user_settings[SETTING_LANGUAGE]), MENU_LAYER_MAIN);
}
