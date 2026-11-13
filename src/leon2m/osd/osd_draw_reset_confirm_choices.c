/* osd_draw_reset_confirm_choices  (FUN_a00a89e4)
 *
 * Draw the Yes and No choices of the Reset question.
 * Name basis: proven - texts 0x190748
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a89e4 @ 0xa00a89e4, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: user_settings is a byte array, the language byte is element 8; a plain for loop over i = 0..1.
 * With -msoft-float the firmware hoists only the high part of the address of user_settings out of the loop (at
 * plain -O3 -g the loop pass hoists the full address). The row argument of osd_draw_text is not narrowed (its
 * third parameter is a full word); the text index of osd_get_text is 16 bits. Family of osd_draw_display_hdr_choices.
 */
extern unsigned char user_settings[];
extern unsigned int osd_yes_no_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define TEXT_ALIGN_LEFT     0
#define LANGUAGE_COUNT      29   /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN  0x2a
#define SETTING_LANGUAGE    8    /* byte offset in user_settings */

/* Draw the Yes and No choices of the Reset question in the choice text
 * column, rows 6 and 8. */
void osd_draw_reset_confirm_choices(void)
{
    unsigned char i;
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    for (i = 0; i < 2; i++)
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1,
                     osd_get_text(osd_yes_no_texts, i * LANGUAGE_COUNT + user_settings[SETTING_LANGUAGE]), MENU_LAYER_MAIN);
}
