/* osd_draw_item_row_state  (FUN_a00aacb4)
 *
 * Redraw an item row in normal or greyed colours by whether it can be selected.
 *   page
 *   row: item row
 * Note: Greyed (0x292) when osd_is_item_enabled says no; row 1 of page 2 also redraws Low Blue Light.
 * Name basis: derived - called by the Pro mode handlers and osd_toggle_ai_vision
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aacb4 @ 0xa00aacb4, flags -mcpu=v8 -O2 -g.
 * Source form: the zero test of osd_is_item_enabled is written first; the two tests on page and row are nested
 * ifs (an && merges them into flag arithmetic). The routine ends with a tail call.
 */
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_draw_low_blue_light_switch(void);

#define MENU_LAYER_MAIN    0
#define ITEM_COLUMN        0x14
#define CELL_BLANK         0x792
#define CELL_ITEM_DISABLED 0x292   /* cell value of an item osd_is_item_enabled reports as disabled */

/* Redraw the cells of an item row (13 cells from the item column, row
 * 2 * row + 6) as CELL_ITEM_DISABLED when osd_is_item_enabled reports the item
 * as disabled, else as CELL_BLANK. For page 2, row 1 (the Low Blue Light item)
 * the Low Blue Light switch is drawn again afterwards. Called by the Pro mode
 * handlers and osd_toggle_ai_vision. */
void osd_draw_item_row_state(unsigned char page, unsigned char row)
{
    if (!osd_is_item_enabled(row))
        osd_api_fill_cells(ITEM_COLUMN, row * 2 + 6, 0xd, CELL_ITEM_DISABLED, MENU_LAYER_MAIN);
    else
        osd_api_fill_cells(ITEM_COLUMN, row * 2 + 6, 0xd, CELL_BLANK, MENU_LAYER_MAIN);
    if (page == 2)
        if (row == 1)
            osd_draw_low_blue_light_switch();
}
