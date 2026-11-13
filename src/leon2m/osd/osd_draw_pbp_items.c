/* osd_draw_pbp_items  (FUN_a00a9abc)
 *
 * Draw the PBP items: mode, sources, display and audio switch, and mark the mode.
 * Name basis: proven - texts 0x182534 'Source 1|Source 2', 0x1828C0, 0x18E89C 'Mode 1|Mode 2|Customize'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a9abc @ 0xa00a9abc, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on: the three text tables are extern array symbols (cast integer
 * constants change which addresses the compiler keeps in registers across the loops); user_settings is accessed
 * directly.
 */
struct user_settings_head {
    unsigned char pad_0x0[8];
    unsigned char language;                     /* +8: added to item * 29 to index the text tables */
    unsigned char pad_0x9[0x1e - 9];
    unsigned char input_source;                 /* +0x1E */
    unsigned char pad_0x1f;
    unsigned char second_source;                /* +0x20 */
    unsigned char pad_0x21[0x2f - 0x21];
    unsigned char pbp_layout;                   /* +0x2F: 0 Mode 1, 1 Mode 2, 2 Customize */
};
extern struct user_settings_head user_settings;
extern unsigned int osd_pbp_mode_texts[];
extern unsigned int osd_pbp_source_texts[];
extern unsigned int osd_pip_item_texts[];
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_fill_cell_bytes(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define TEXTS_PER_ITEM        29        /* languages: text index = item * 29 + language */
#define PBP_TEXT_COLUMN       0x2a      /* column of the item texts */
#define PBP_MARK_COLUMN_LEFT  0x28      /* the two cells that mark the layout in effect */
#define PBP_MARK_COLUMN_RIGHT 0x29
#define DISABLED_ATTR         0x296     /* attribute of a choice that cannot be selected */
#define CHOICE_ROW_PLAIN      0         /* osd_highlight_choice_row style */

/*
 * Draw the rows of the PBP list: three layout texts (Mode 1, Mode 2, Customize), two source texts (Source 1,
 * Source 2) and two more rows from the item text table, then mark the layout in effect. No parameters.
 *
 * Order: select glyph write address 0x111 and text mode 0; when the two sources are the same
 * (user_settings.input_source == second_source) rows 0x10 and 0x12 are first given the attribute of a choice
 * that cannot be selected (osd_is_choice_enabled refuses items 5 and 6 of the PBP list in that case);
 * the texts go to column 0x2a on the rows 6, 8, 10 (layouts, table osd_pbp_mode_texts), 12, 14 (sources,
 * osd_pbp_source_texts) and 16, 18 (osd_pip_item_texts entries 3 and 4). Last, the choice row of the current
 * layout is highlighted in the plain style, and plane 0 of columns 0x28 and 0x29 on its row gets the glyphs 0xF
 * and 0x10. The row of layout n is 2 * n + 6 (2 * n - 8 above 6).
 *
 * Called when the PBP list is opened or redrawn (three routines).
 */
void osd_draw_pbp_items(void)
{
    unsigned char item;
    unsigned char row;

    osd_api_set_glyph_write_address(0x111, 0);
    osd_api_set_text_mode(0, 0);
    if (user_settings.input_source == user_settings.second_source) {
        osd_api_fill_cells(PBP_TEXT_COLUMN, 0x10, 0xb, DISABLED_ATTR, 0);
        osd_api_fill_cells(PBP_TEXT_COLUMN, 0x12, 0xb, DISABLED_ATTR, 0);
    }
    for (item = 0; item <= 2; item++)
        osd_draw_text(0, PBP_TEXT_COLUMN, item * 2 + 6, 1, osd_get_text(osd_pbp_mode_texts, item * TEXTS_PER_ITEM + user_settings.language), 0);
    for (item = 0; item <= 1; item++)
        osd_draw_text(0, PBP_TEXT_COLUMN, item * 2 + 0xc, 1, osd_get_text(osd_pbp_source_texts, item * TEXTS_PER_ITEM + user_settings.language), 0);
    for (item = 3; item <= 4; item++)
        osd_draw_text(0, PBP_TEXT_COLUMN, item * 2 + 10, 1, osd_get_text(osd_pip_item_texts, item * TEXTS_PER_ITEM + user_settings.language), 0);
    osd_highlight_choice_row(user_settings.pbp_layout, CHOICE_ROW_PLAIN);
    if (user_settings.pbp_layout <= 6)
        row = user_settings.pbp_layout * 2 + 6;
    else
        row = user_settings.pbp_layout * 2 - 8;
    osd_api_fill_cell_bytes(0, PBP_MARK_COLUMN_LEFT, row, 1, 0xf, 0);
    osd_api_fill_cell_bytes(0, PBP_MARK_COLUMN_RIGHT, row, 1, 0x10, 0);
}
