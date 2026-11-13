/* osd_highlight_item_row  (FUN_a00a900c)
 *
 * Highlight an item row in the item column.
 *   item: item row
 *   mode: highlight style
 * Note: Mode 0 only moves window 6 over the row; mode 1 = active row; mode 2 and any other value = parent of
 *   an open list.
 * Name basis: derived - called by the enter/leave/select item handlers; menu columns: tabs 1..0x12, items
 *   0x14.., choices 0x27.., key guide 0x37..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a900c @ 0xa00a900c, flags -mcpu=v8 -O3 -g.
 * Source form: the three attribute values are set per mode in a switch with the arms case 1, case 2 and default
 * (the callers pass 0, 1 and 2). Case 2 and the default carry the same values and the firmware holds that
 * assignment once (0xa00a9034-0xa00a9040). Three assignment sites are what the register choice shows: the
 * firmware keeps middle_attr in %l0, row in %l1 and edge_row_attr in %l2; with one assignment for every mode
 * other than 1 GCC gives middle_attr %l2, row %l0 and edge_row_attr %l1. The list-id tests for 6 and 8 are nested
 * ifs (branches), the tests for 3 and 5 one &&.
 */
extern unsigned char osd_list_id;
extern void panel_wait_sync_pulse(void);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_window_effect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_set_window_rect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned short osd_get_menu_state(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_set_highlight_window(unsigned char, unsigned char, unsigned int, unsigned int);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

/* The mode argument. */
#define HIGHLIGHT_ITEM_MODE_0         0   /* only the item window (window 6) is moved onto the row */
#define HIGHLIGHT_ITEM_ACTIVE         1   /* the cursor is in the item list */
#define HIGHLIGHT_ITEM_LIST_OPEN      2   /* the row is the parent of an open choice list; every other value is drawn alike */

#define ITEM_COLUMN           0x14      /* first column of the item column; a row is 0x11 cells wide */
#define ITEM_WIDTH            0x11
#define ITEM_WINDOW           6         /* menu window that lies over the item row in mode 0 */
#define ITEM_RIGHT_EDGE_COLUMN 0x25     /* column of the right-hand edge glyphs */
#define ITEM_LEFT_EDGE_COLUMN 0x13      /* column of the left-hand edge glyphs */
#define SWITCH_COLUMN         0x22      /* the on/off switch cells of an item row (osd_draw_gaming_item_state) */
#define CELL_ROW_PIXELS       36        /* height of a cell row in window rectangles */

/*
 * Mark one item row of the item column (columns 0x14..0x24) as the active item or as the parent of an open list.
 *
 *   item  item row 0..13, seven rows per page; the item occupies three cell rows from
 *         row = 2 * item + 5 (items 0..6) or 2 * item - 9 (items 7 and up)
 *   mode  HIGHLIGHT_ITEM_MODE_0 / _ACTIVE / _LIST_OPEN
 *
 * Mode 0 only puts window 6 over the row (effect 0xC, rectangle from row * 36 + 0x16 to row * 36 + 0x55) and
 * returns. Otherwise:
 *   1. window 6 is switched off, except in the menu states 30..34 and 35..37;
 *   2. the three cell rows are filled with the attributes of the mode: edge_row_attr on the first and third,
 *      middle_attr on the middle row (mode 1: 0x392 / 0x742; other modes: 0xb92 / 0x7c2);
 *   3. in mode 1 three cells at column 0x22 on the middle row get attribute 0x342, and their glyphs (plane 0)
 *      are cleared unless osd_list_id is 3, 5, 6 or 8;
 *   4. mode 1: the highlight window is put over the row (column 0x13, width 0x13), edge glyphs 0xA6.. are drawn
 *      at column 0x13 and 0xA9.. at column 0x25, glyph plane 0 of the first and third row gets 0x30 and 0x31,
 *      windows 1 and 2 are switched on. Other modes: the same edge glyphs with attribute 0x5b9a instead of
 *      0x589a, plane 0 of the first and third row gets 0x32 and 0x33, and no window is switched on.
 *
 * Called from about 150 places: every handler that enters, leaves or steps through an item list.
 */
void osd_highlight_item_row(unsigned char item, unsigned char mode)
{
    unsigned char row;
    unsigned short edge_row_attr, middle_attr, edge_glyph_attr;

    if (item > 6)
        row = item * 2 - 9;
    else
        row = item * 2 + 5;
    switch (mode) {
    case 1:
        edge_glyph_attr = 0x589a;
        edge_row_attr = 0x392;
        middle_attr = 0x742;
        break;
    case 2:
        edge_glyph_attr = 0x5b9a;
        edge_row_attr = 0xb92;
        middle_attr = 0x7c2;
        break;
    default:
        edge_glyph_attr = 0x5b9a;
        edge_row_attr = 0xb92;
        middle_attr = 0x7c2;
        break;
    }
    panel_wait_sync_pulse();
    if (mode == HIGHLIGHT_ITEM_MODE_0) {
        osd_api_set_window_enable(ITEM_WINDOW, 0, 0);
        osd_api_set_window_effect(ITEM_WINDOW, 0, 0, 0, 0, 0xc, 0, 0, 0, 0, 0);
        osd_api_set_window_rect(ITEM_WINDOW, 0x1c8, row * CELL_ROW_PIXELS + 0x16, 0x38f, row * CELL_ROW_PIXELS + 0x55, 0);
        osd_api_set_window_enable(ITEM_WINDOW, 1, 0);
        return;
    }
    if ((osd_get_menu_state() < 30 || osd_get_menu_state() > 34) && (osd_get_menu_state() < 35 || osd_get_menu_state() > 37))
        osd_api_set_window_enable(ITEM_WINDOW, 0, 0);
    osd_api_fill_cells(ITEM_COLUMN, row, ITEM_WIDTH, edge_row_attr, 0);
    osd_api_fill_cells(ITEM_COLUMN, row + 1, ITEM_WIDTH, middle_attr, 0);
    if (mode == HIGHLIGHT_ITEM_ACTIVE)
        osd_api_fill_cells(SWITCH_COLUMN, row + 1, 3, 0x342, 0);
    if (osd_list_id != 3 && osd_list_id != 5)
        if (osd_list_id != 6)
            if (osd_list_id != 8)
                if (mode == HIGHLIGHT_ITEM_ACTIVE)
                    osd_api_fill_cell_bytes(0, SWITCH_COLUMN, row + 1, 3, 0, 0);
    osd_api_fill_cells(ITEM_COLUMN, row + 2, ITEM_WIDTH, edge_row_attr, 0);
    if (mode == HIGHLIGHT_ITEM_ACTIVE) {
        osd_set_highlight_window(1, ITEM_LEFT_EDGE_COLUMN, row, 0x13);
        osd_draw_cell_run(0, 1, edge_glyph_attr, ITEM_LEFT_EDGE_COLUMN, row, 3, 0xa6);
        osd_api_fill_cell_bytes(0, ITEM_COLUMN, row, ITEM_WIDTH, 0x30, 0);
        osd_api_fill_cell_bytes(0, ITEM_COLUMN, row + 2, ITEM_WIDTH, 0x31, 0);
        osd_draw_cell_run(0, 1, edge_glyph_attr, ITEM_RIGHT_EDGE_COLUMN, row, 3, 0xa9);
        osd_api_set_window_enable(1, 1, 0);
        osd_api_set_window_enable(2, 1, 0);
    } else {
        osd_api_fill_cell_bytes(0, ITEM_COLUMN, row, ITEM_WIDTH, 0x32, 0);
        osd_api_fill_cell_bytes(0, ITEM_COLUMN, row + 2, ITEM_WIDTH, 0x33, 0);
        osd_draw_cell_run(0, 1, edge_glyph_attr, ITEM_LEFT_EDGE_COLUMN, row, 3, 0xa6);
        osd_draw_cell_run(0, 1, edge_glyph_attr, ITEM_RIGHT_EDGE_COLUMN, row, 3, 0xa9);
    }
}
