/* osd_draw_tab_icons  (FUN_a00a7aec)
 *
 * Draw the tab icons of the left column (tabs 0..6, or 7..8 on the second page)
 *   second_page: 0 first page, else second page
 * Name basis: derived - icon cells in column 2 per tab row; called by osd_select_prev_tab /
 *   osd_select_next_tab
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a7aec @ 0xa00a7aec, flags -mcpu=v8 -O3 -g.
 * Source form: the end bound is assigned before the start bound; the switch on the tab index and the 6/7/0 test
 * come in that order.
 */
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);

#define TAB_COUNT_PAGE_0   7            /* tabs 0..6 are shown on the first page, tabs 7..8 on the second */
#define TAB_COUNT          9
#define TAB_ICON_COLUMN    2
#define TAB_ICON_WIDTH     3            /* cells of an icon, across */

/*
 * Draw the icons in the left column of the main menu: the seven tabs of the first page, or the two of the
 * second.
 *
 *   second_page  0: tabs 0..6; anything else: tabs 7..8
 *
 * Tab i is drawn at cell row (i % 7) * 2 + 6, in column 2, as runs of three cells whose glyph numbers rise
 * by one. Tabs 0, 6 and 7 have a taller icon: three runs, one cell row above, on and below that row, with
 * glyphs first_glyph, +3 and +6. The other tabs have one run on the row, with attribute 0x659a instead of 0x629a.
 * first_glyph is 0x49 for tab 0, 0x52 + 3 * i for tabs 1..5, 0x64, 0x70 and 0x7c for tabs 6, 7 and 8.
 *
 * Called when the highlight moves to the previous or next tab and the tab column is redrawn (page 0 or 1), and
 * with page 0 from a third routine.
 */
void osd_draw_tab_icons(unsigned char second_page)
{
    unsigned char tab, first_tab, end_tab, row;
    unsigned char first_glyph = 0;

    end_tab = TAB_COUNT;
    first_tab = TAB_COUNT_PAGE_0;
    if (second_page == 0) {
        end_tab = TAB_COUNT_PAGE_0;
        first_tab = 0;
    }
    for (tab = first_tab; tab < end_tab; tab++) {
        switch (tab) {
        case 0:
            first_glyph = 0x49;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            first_glyph = tab * 3 + 0x52;
            break;
        case 6:
            first_glyph = 0x64;
            break;
        case 7:
            first_glyph = 0x70;
            break;
        case 8:
            first_glyph = 0x7c;
            break;
        }
        row = (tab % TAB_COUNT_PAGE_0) * 2 + 6;
        if (tab == 6 || tab == 7 || tab == 0) {
            osd_draw_cell_run(1, 1, 0x629a, TAB_ICON_COLUMN, row - 1, TAB_ICON_WIDTH, first_glyph);
            osd_draw_cell_run(1, 1, 0x629a, TAB_ICON_COLUMN, row, TAB_ICON_WIDTH, first_glyph + 3);
            osd_draw_cell_run(1, 1, 0x629a, TAB_ICON_COLUMN, row + 1, TAB_ICON_WIDTH, first_glyph + 6);
        } else {
            osd_draw_cell_run(1, 1, 0x659a, TAB_ICON_COLUMN, row, TAB_ICON_WIDTH, first_glyph);
        }
    }
}
