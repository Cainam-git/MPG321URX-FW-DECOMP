/* osd_draw_pro_mode_choices  (FUN_a00b6bec)
 *
 * Draw the Professional mode list and grey out modes not usable now.
 *   page: list page to draw
 * Note: Rows 5 and 6 (sRGB, Adobe RGB) are greyed while sys_user_get_picture_state is not 0; Display P3 is
 *   never greyed.
 * Name basis: proven - texts 0x1951dc 'Eco|User|Anti-Blue|Movie|Office|sRGB|Adobe RGB|Display P3'; called by
 *   the pro mode handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6bec @ 0xa00b6bec, flags -mcpu=v8 -O3 -g -msoft-float.
 * Callers: osd_cancel_pro_mode, osd_select_prev_pro_mode, osd_select_next_pro_mode, osd_draw_item_choices, osd_redraw_page_after_notice.
 * Source form: osd_step_pro_mode_index (osd_step_pro_mode_index, the step function at 0xa00b6b88) is written in the file as a
 * static copy and inlined; the row tests compare i with its three results osd_step_pro_mode_index(4, 0), (5, 0)
 * and (6, 0) (fw: cmp 5 / cmp 6 at the loop end, cmp 7 at the body top). The second loop limit reuses n
 * (n = 3), which keeps the 'cmp 3; bcs' form. The table osd_pro_mode_texts is an extern array symbol; with a
 * cast integer constant the compiler keeps the whole user_settings address in a register.
 */
/* Fields of the settings record used here. */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };   /* +8: menu language */
extern struct user_settings_record user_settings;
extern unsigned int osd_pro_mode_texts[];
extern void osd_clear_choice_column(void);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern int sys_user_get_picture_state(void);
extern void osd_api_fill_cells(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_write_reg_cc(int, int);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);

#define PRO_MODES_ON_PAGE_0   7     /* modes 0..6 are on page 0, mode 7 alone on page 1 */
#define TEXTS_PER_ITEM        29    /* a text table holds one text per menu language for every item */
#define CHOICE_COLUMN         0x2a  /* column of the choice texts */
#define CHOICE_FIRST_ROW      6     /* row of the first choice; the rows are two cells apart */
#define CHOICE_GREY_WIDTH     0xb   /* cells covered by the grey attribute */
#define CHOICE_GREY_ATTR      0x296
#define CELL_BLANK            0x792

/* Step a Pro mode index (0..7) one place with wrap-around: direction 1 steps down (0 gives 7), any other
 * value steps up (7 gives 0). An index above 7 comes back unchanged. */
static unsigned char osd_step_pro_mode_index(unsigned char index, unsigned char direction)
{
    unsigned char previous;

    if (direction == 1) {
        if (index == 0)
            return 7;
        previous = index - 1;
        if (previous <= 6)
            return previous;
        return index;
    }
    if (index == 7)
        return 0;
    if (index > 6)
        return index;
    return index + 1;
}

/* Draw the choice column of the Pro mode list: one text per row, two cells apart from row 6, then three
 * glyph cells on row 0x1c.
 *   page: 0 draws seven rows (modes 0..6), any other value one row; the text of a row is item
 *         (row + page * 7) of osd_pro_mode_texts in the menu language.
 * Rows 5 and 6 (the results of osd_step_pro_mode_index(4, 0) and (5, 0), i.e. the texts sRGB and Adobe RGB
 * on page 0) get the attribute 0x296 over 0xb cells before their text when sys_user_get_picture_state()
 * is not 0. The test also names row 7, which never occurs. Called by the Pro mode list handlers. */
void osd_draw_pro_mode_choices(unsigned char page)
{
    unsigned char n;
    unsigned char i;

    osd_clear_choice_column();
    osd_api_set_glyph_write_address(0x111, 0);
    osd_api_set_text_mode(0, 0);
    n = (page == 0) ? PRO_MODES_ON_PAGE_0 : 1;
    for (i = 0; i < n; i++) {
        if ((i == osd_step_pro_mode_index(4, 0) || i == osd_step_pro_mode_index(5, 0) || i == osd_step_pro_mode_index(6, 0)) && sys_user_get_picture_state())
            osd_api_fill_cells(CHOICE_COLUMN, i * 2 + CHOICE_FIRST_ROW, CHOICE_GREY_WIDTH, CHOICE_GREY_ATTR, 0);
        osd_draw_text(0, CHOICE_COLUMN, i * 2 + CHOICE_FIRST_ROW, 1, osd_get_text(osd_pro_mode_texts, (i + page * PRO_MODES_ON_PAGE_0) * TEXTS_PER_ITEM + user_settings.language), 0);
    }
    osd_api_write_reg_cc(CELL_BLANK, 0);
    n = 3;
    for (i = 0; i < n; i++)
        osd_api_fill_cell_bytes(1, i + 0x2f, 0x1c, 1, i + 0x28, 0);
}
