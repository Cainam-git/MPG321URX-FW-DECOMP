/* osd_draw_input_choices  (FUN_a00b621c)
 *
 * Draw the four input names as a choice list.
 * Name basis: proven - input names 0x196B24; called by osd_enter_pip_source_choices and
 *   osd_enter_pbp_source*_choices
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b621c @ 0xa00b621c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the table pointer is passed as a const char pointer and the loop keeps a separate unsigned
 * char counter next to the unsigned int index; the draw call and the counter increment are one comma
 * expression.
 */
extern unsigned char osd_input_name_texts[];
extern void osd_clear_choice_column(void); /* 0xa00a8c88 */
extern void osd_api_set_glyph_write_address(unsigned int address, unsigned int layer); /* 0xa0146b50 */
extern void osd_api_set_text_mode(unsigned int mode, unsigned int layer); /* 0xa0146b6c */
extern unsigned int osd_get_text(const char *table, unsigned int index); /* 0xa00a3844 */
extern void osd_draw_text(unsigned int plane, unsigned int column, unsigned int row, unsigned int width, unsigned int text, unsigned int layer); /* 0xa00a31a4 */

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define CHOICE_TEXT_COLUMN   0x2a    /* column of the choice texts */
#define CHOICE_FIRST_ROW     6       /* row of the first choice; the choices are two rows apart */
#define CHOICE_GLYPH_ADDRESS 0x111   /* glyph memory address given before choice texts are drawn */
#define INPUT_CHOICES        4

/* Draw the four input names as the choice list: the choice column is cleared and entry i of
 * osd_input_name_texts (the same in every language) is drawn left-aligned on row 2 * i + 6. Called by
 * osd_enter_pip_source_choices and osd_enter_pbp_source1_choices / osd_enter_pbp_source2_choices. */
void osd_draw_input_choices(void)
{
    unsigned char counter;
    unsigned int index;
    unsigned int text;

    osd_clear_choice_column();
    counter = 0;
    osd_api_set_glyph_write_address(CHOICE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    index = 0;
    do {
        text = osd_get_text((const char *)osd_input_name_texts, index);
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, index * 2 + CHOICE_FIRST_ROW, 1, text, MENU_LAYER_MAIN), counter++;
        index = counter & 0xff;
    } while (index < INPUT_CHOICES);
}
