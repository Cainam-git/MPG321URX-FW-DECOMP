/* osd_highlight_crosshair_icon  (FUN_a00a9dac)
 *
 * Highlight a Smart Crosshair icon row.
 *   sel: row
 *   selected
 * Name basis: descriptive - called by osd_open_crosshair_icon, osd_select_prev|next_crosshair_icon
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a9dac @ 0xa00a9dac, flags -mcpu=v8 -O3 -g.
 * Source form: a 5-byte local struct (window_params) is filled ({0, code, 0, 0, 0} with code = 4 when selected,
 * else 0xC) and never read; the firmware keeps these stack stores (the same values are passed to osd_api_set_window_effect in
 * osd_highlight_quick_menu_row).
 */
struct window_params { unsigned char byte_0, code, byte_2, byte_3, byte_4; };
extern void osd_api_set_window_enable(int window, int on, int layer);
extern void osd_api_set_window_rect(unsigned int window, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int layer);
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned short column, unsigned char row, unsigned char count, unsigned char first_glyph);

#define MENU_LAYER_MAIN     0
#define CHOICE_COLUMN       0x27   /* left glyph column of a choice row */
#define CHOICE_RIGHT_COLUMN 0x34   /* right glyph column of a choice row */

/* Highlight a Smart Crosshair icon row (rows 2 * sel + 5 .. + 7).
 *   sel:      row of the icon
 *   selected: non-zero uses window 3 (the cursor row); 0 uses window 4
 * The chosen window is switched off, given its rectangle, and switched on.
 * For the cursor row the highlight window is also placed over the row
 * (column 0x27, width 0xE), the edge cells of both columns get attribute
 * 0x589A with glyphs 0xA6.. (left) and 0xA9.. (right), and windows 1 and 2 are
 * switched on. Called by osd_open_crosshair_icon and the select prev / next
 * crosshair icon handlers. */
void osd_highlight_crosshair_icon(unsigned char sel, unsigned char selected)
{
    unsigned char window = selected ? 3 : 4;
    unsigned char row = sel * 2 + 5;
    struct window_params params;
    osd_api_set_window_enable(window, 0, MENU_LAYER_MAIN);
    params.byte_0 = 0;
    params.byte_2 = 0;
    params.byte_3 = 0;
    params.byte_4 = 0;
    if (selected) {
        params.code = 4;
        osd_api_set_window_rect(window, 0x3a8, row * 36 + 0x1a, 0x4f7, row * 36 + 0x51, MENU_LAYER_MAIN);
    } else {
        params.code = 0xc;
        osd_api_set_window_rect(window, 0x3a8, row * 36 + 0x16, 0x4f7, row * 36 + 0x55, MENU_LAYER_MAIN);
    }
    osd_api_set_window_enable(window, 1, MENU_LAYER_MAIN);
    if (selected) {
        osd_set_highlight_window(1, CHOICE_COLUMN, row, 0xe);
        osd_draw_cell_run(0, 1, 0x589a, CHOICE_COLUMN, row, 3, 0xa6);
        osd_draw_cell_run(0, 1, 0x589a, CHOICE_RIGHT_COLUMN, row, 3, 0xa9);
        osd_api_set_window_enable(1, 1, MENU_LAYER_MAIN);
        osd_api_set_window_enable(2, 1, MENU_LAYER_MAIN);
    }
}
