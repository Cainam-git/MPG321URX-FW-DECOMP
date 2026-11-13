/* osd_draw_pip_size_choices  (FUN_a00ab2a8)
 *
 * Draw the PIP Size choices: Small, Medium, Large.
 * Name basis: proven - texts 0x18F550; called by osd_enter_pip_size_choices
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ab2a8 @ 0xa00ab2a8, flags -mcpu=v8 -O3 -g.
 * Source form: user_settings is a byte array (language byte = element 8); the loop is a label and
 * "if (i <= 2) goto next_choice". Same code as osd_draw_scope_size_choices with other constants.
 */
extern unsigned char user_settings[];
extern unsigned int osd_size_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_clear_choice_column(void);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a
#define SETTING_LANGUAGE    8    /* byte offset in user_settings */

/* Draw the three PIP Size choices (Small, Medium, Large) in the choice text
 * column, rows 6, 8, 10, after osd_clear_choice_column. Called by
 * osd_enter_pip_size_choices. */
void osd_draw_pip_size_choices(void)
{
    unsigned char i;
    osd_clear_choice_column();
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    i = 0;
next_choice:
    osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1,
                 osd_get_text(osd_size_texts, i * LANGUAGE_COUNT + user_settings[SETTING_LANGUAGE]), MENU_LAYER_MAIN);
    i++;
    if (i <= 2)
        goto next_choice;
}
