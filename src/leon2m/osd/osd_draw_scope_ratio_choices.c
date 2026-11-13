/* osd_draw_scope_ratio_choices  (FUN_a00b3238)
 *
 * Draw the Optix Scope zoom ratio choices.
 * Name basis: derived - table 0x18F52C (x1.5, x2, ...); called by osd_enter_scope_ratio_choices
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3238 @ 0xa00b3238, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the table has no data label of its own; its address is written as s_0018f400 + 0x12c (0x18F52C).
 * The loop counter is an unsigned char that is incremented and masked with 0xff before the comparison, and
 * the draw call is followed by the increment in one comma expression.
 */
extern char s_0018f400[];
extern void osd_clear_choice_column(void); /* 0xa00a8c88 */
extern void osd_api_set_glyph_write_address(unsigned int address, unsigned int layer); /* 0xa0146b50 */
extern void osd_api_set_text_mode(unsigned int mode, unsigned int layer); /* 0xa0146b6c */
extern unsigned int osd_get_text(int table, unsigned short index); /* 0xa00a3844 */
extern void osd_draw_text(int plane, int column, int row, int width, unsigned int text, int layer); /* 0xa00a31a4 */

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define CHOICE_TEXT_COLUMN   0x2a    /* column of the choice texts */
#define CHOICE_FIRST_ROW     6       /* row of the first choice; the choices are two rows apart */
#define CHOICE_GLYPH_ADDRESS 0x111   /* glyph memory address given before choice texts are drawn */
#define SCOPE_RATIO_CHOICES  3       /* x1.5, x2, x3 */
#define SCOPE_RATIO_TEXTS_OFFSET 0x12c   /* the text table lies at 0x18F400 + 0x12C */

/* Draw the three Optix Scope ratio choices as the choice list: the choice column is cleared and entry i of
 * the ratio text table at 0x18F52C is drawn left-aligned on row 2 * i + 6. The index is the entry number
 * alone (no language offset). Called by osd_enter_scope_ratio_choices. */
void osd_draw_scope_ratio_choices(void)
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
        text = osd_get_text(s_0018f400 + SCOPE_RATIO_TEXTS_OFFSET, index);
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, index * 2 + CHOICE_FIRST_ROW, 1, text, MENU_LAYER_MAIN), counter++;
        index = counter & 0xff;
    } while (index < SCOPE_RATIO_CHOICES);
}
