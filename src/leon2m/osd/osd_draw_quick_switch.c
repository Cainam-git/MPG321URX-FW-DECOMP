/* osd_draw_quick_switch  (FUN_a00a4a30)
 *
 * Draw the OFF/ON switch of a quick menu in the given position.
 *   switch_on: 0 or 1, switch position
 * Note: Glyphs 0x22.. for p 0, 0x1E.. otherwise; the two halves swap highlight.
 * Name basis: descriptive - called by the quick menu page drawer osd_draw_navi_quick_menu
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a4a30 @ 0xa00a4a30, flags -mcpu=v8 -O3 -g.
 * Source form: the position test is inside one loop (if/else around the call). -O3 loop unswitching makes the two
 * loop copies, and both copies jump back to a common exit that re-tests the position; two hand-written loops let
 * jump threading skip that re-test. The "== 0" arms come first in both ifs.
 */
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define SWITCH_ROW          8
#define SWITCH_GLYPH_COLUMN 9      /* four glyph cells, columns 9..12 */
#define SWITCH_GLYPHS_ON    0x1e   /* first glyph of the set drawn for position 1 */
#define SWITCH_GLYPHS_OFF   0x22   /* first glyph of the set drawn for position 0 */
#define SWITCH_LEFT_COLUMN  3      /* two 5-cell halves, one at 3 and one at 14 */
#define SWITCH_RIGHT_COLUMN 0xe
#define CELL_BLANK          0x792
#define CELL_SWITCH_HALF    0x992

/* Draw the OFF/ON switch of a quick menu in row 8, for the position given in
 * switch_on (0 = off, 1 = on). First the cells 5..8 are blanked, then four
 * glyph bytes are written at columns 9..12 (the on set or the off set), then
 * the two 5-cell halves at columns 3 and 14 are filled with CELL_BLANK and
 * CELL_SWITCH_HALF, swapped between the two positions. Called by the quick
 * menu page drawer. */
void osd_draw_quick_switch(unsigned char switch_on)
{
    unsigned char i;

    osd_api_fill_cells(5, SWITCH_ROW, 4, CELL_BLANK, MENU_LAYER_MAIN);

    i = 0;
    do {
        if (switch_on == 0)
            osd_api_fill_cell_bytes(PLANE_0, (unsigned short)(i + SWITCH_GLYPH_COLUMN), SWITCH_ROW, 1, i + SWITCH_GLYPHS_OFF, MENU_LAYER_MAIN);
        else
            osd_api_fill_cell_bytes(PLANE_0, (unsigned short)(i + SWITCH_GLYPH_COLUMN), SWITCH_ROW, 1, i + SWITCH_GLYPHS_ON, MENU_LAYER_MAIN);
        i++;
    } while (i <= 3);

    if (switch_on == 0) {
        osd_api_fill_cells(SWITCH_LEFT_COLUMN, SWITCH_ROW, 5, CELL_BLANK, MENU_LAYER_MAIN);
        osd_api_fill_cells(SWITCH_RIGHT_COLUMN, SWITCH_ROW, 5, CELL_SWITCH_HALF, MENU_LAYER_MAIN);
    } else {
        osd_api_fill_cells(SWITCH_LEFT_COLUMN, SWITCH_ROW, 5, CELL_SWITCH_HALF, MENU_LAYER_MAIN);
        osd_api_fill_cells(SWITCH_RIGHT_COLUMN, SWITCH_ROW, 5, CELL_BLANK, MENU_LAYER_MAIN);
    }
}
