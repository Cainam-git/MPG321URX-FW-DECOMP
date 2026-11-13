/* osd_draw_tab_names  (FUN_a00b3d14)
 *
 * Draw the tab names of the left column (first or second page)
 *   second: page
 * Note: Greys PIP/PBP when it cannot be used.
 * Name basis: proven - texts 0x196DC0 'G.I.|Gaming|...|MSI OLED Care'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3d14 @ 0xa00b3d14, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: bit 31 of the word at +0x1F4 is tested as '(word >> 31)' on an unsigned int (a signed '< 0' test
 * gives another block order); the operand order of the two text index sums differs between the two loops (the
 * language comes first in the first loop, last in the second).
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int user_settings_word_0x1f4;   /* bit 31 = the DSC switch */
extern unsigned int osd_tab_name_texts[];
extern void osd_api_set_glyph_write_address(int address, int layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern int sys_user_get_picture_state(void);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_write_reg_cc(unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(unsigned char plane, unsigned short column, unsigned short row, unsigned char width, unsigned int text, unsigned char layer);

#define PLANE_0              0
#define PLANE_1              1
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define LANGUAGE_COUNT       29      /* texts of one entry for every language, in language order */
#define TAB_NAME_COLUMN      6
#define TAB_NAME_FIRST_ROW   6       /* row of the first tab name; the names are two rows apart */
#define TAB_NAME_GLYPH_ADDRESS 0x46  /* glyph memory address given before the names are drawn */
#define TABS_ON_FIRST_PAGE   7       /* tabs 0..6; tabs 7 and 8 (Settings, MSI OLED Care) are on the second page */
#define LAST_TAB             8
#define TAB_PIP_PBP_ROW      0x10    /* row of tab 5, PIP/PBP */
#define TAB_PIP_PBP_WIDTH    10
#define CELL_TAB_PIP_PBP     0x692   /* cell value put on the PIP/PBP name row before the names are drawn */
#define CELL_BLANK           0x792
#define MARK_ROW             0x15    /* row of the two glyph cells at the end */
#define MARK_COLUMN          9       /* columns 9 and 10, glyphs 0x28 and 0x29 */
#define MARK_GLYPH           0x28

/* Draw the tab names of the left column: page 0 holds tabs 0..6 (rows 2 * i + 6), page 1 holds tabs 7 and 8
 * (rows 2 * i - 8, so they start again at row 6). Entry i of osd_tab_name_texts in the menu language is drawn
 * left-aligned at column 6.
 *   second: 0 for the first page, non-zero for the second page.
 * Before the names, the ten cells of the PIP/PBP name row (row 0x10) are set to cell value 0x692 when
 * sys_user_get_picture_state() is not 0 or the DSC switch (bit 31 of the settings word at +0x1F4) is set.
 * After the names, two glyph cells (0x28, 0x29) are written at columns 9 and 10 of row 0x15 in plane 1. */
void osd_draw_tab_names(unsigned char second)
{
    unsigned char i;
    unsigned char n;

    osd_api_set_glyph_write_address(TAB_NAME_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    if (sys_user_get_picture_state() != 0 || (user_settings_word_0x1f4 >> 31))
        osd_api_fill_cells(TAB_NAME_COLUMN, TAB_PIP_PBP_ROW, TAB_PIP_PBP_WIDTH, CELL_TAB_PIP_PBP, MENU_LAYER_MAIN);
    if (second == 0) {
        n = TABS_ON_FIRST_PAGE;
        for (i = 0; i < n; i++)
            osd_draw_text(PLANE_0, TAB_NAME_COLUMN, i * 2 + TAB_NAME_FIRST_ROW, 1, osd_get_text(osd_tab_name_texts, user_settings.language + i * LANGUAGE_COUNT), MENU_LAYER_MAIN);
    } else {
        for (i = TABS_ON_FIRST_PAGE; i <= LAST_TAB; i++)
            osd_draw_text(PLANE_0, TAB_NAME_COLUMN, i * 2 - 8, 1, osd_get_text(osd_tab_name_texts, i * LANGUAGE_COUNT + user_settings.language), MENU_LAYER_MAIN);
    }
    osd_api_write_reg_cc(CELL_BLANK, 0);
    n = 2;
    for (i = 0; i < n; i++)
        osd_api_fill_cell_bytes(PLANE_1, i + MARK_COLUMN, MARK_ROW, 1, i + MARK_GLYPH, 0);
}
