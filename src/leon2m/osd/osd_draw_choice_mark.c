/* osd_draw_choice_mark  (FUN_a00a813c)
 *
 * Draw or clear the mark of the stored choice in a list.
 *   kind: list kind
 *   sel: row
 *   on: draw or clear
 * Note: Column 0x28 for choice lists (mode 1/2), 0x14 for item lists.
 * Name basis: derived - called by the accept/cancel/select handlers with the saved row; menu columns: tabs
 *   1..0x12, items 0x14.., choices 0x27.., key guide 0x37..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a813c @ 0xa00a813c, flags -mcpu=v8 -O3 -g.
 * Source form: the glyph is chosen first with a conditional expression; the column starts as 0x28 and is changed
 * in the "kind != 1" arm.
 */
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN   0
#define PLANE_0           0
#define CHOICE_MARK_ITEMS 0     /* item list: mark in column 0x14, glyphs 0x3A, 0x3B */
#define CHOICE_MARK_LIST  1     /* choice list: mark in column 0x28, glyphs 0x0F, 0x10 */
#define CHOICE_MARK_ICONS 2     /* crosshair icon list: as kind 1, but no page wrap of the row */
#define ITEM_MARK_COLUMN  0x14
#define CHOICE_MARK_COLUMN 0x28
#define ITEM_MARK_GLYPH   0x3a
#define CHOICE_MARK_GLYPH 0x0f

/* Draw or clear the mark of the stored choice of a list: two glyph bytes in
 * the cells (column, row) and (column + 1, row).
 *   kind: CHOICE_MARK_ITEMS / CHOICE_MARK_LIST / CHOICE_MARK_ICONS
 *   sel:  row index of the entry; entries 0..6 are drawn at rows 6, 8 .. 18,
 *         entry 7 and above start again at row 6 (the next page). Kind 2
 *         never wraps.
 *   on:   non-zero draws the mark, 0 clears both bytes
 * Called by the accept, cancel and select handlers of the menu lists. */
void osd_draw_choice_mark(unsigned char kind, unsigned char sel, unsigned char on)
{
    unsigned char glyph = (kind == CHOICE_MARK_ITEMS ? ITEM_MARK_GLYPH : CHOICE_MARK_GLYPH);
    unsigned char row;
    unsigned char col = CHOICE_MARK_COLUMN;
    if (sel <= 6)
        row = sel * 2 + 6;
    else
        row = sel * 2 - 8;
    if (kind != CHOICE_MARK_LIST) {
        col = ITEM_MARK_COLUMN;
        if (kind == CHOICE_MARK_ICONS) {
            row = sel * 2 + 6;
            col = CHOICE_MARK_COLUMN;
        }
    }
    if (on) {
        osd_api_fill_cell_bytes(PLANE_0, col, row, 1, glyph, MENU_LAYER_MAIN);
        osd_api_fill_cell_bytes(PLANE_0, col + 1, row, 1, glyph + 1, MENU_LAYER_MAIN);
    } else {
        osd_api_fill_cell_bytes(PLANE_0, col, row, 1, 0, MENU_LAYER_MAIN);
        osd_api_fill_cell_bytes(PLANE_0, col + 1, row, 1, 0, MENU_LAYER_MAIN);
    }
}
