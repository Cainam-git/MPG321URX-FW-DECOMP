/* osd_clear_crosshair_icon_highlight  (FUN_a00a9cc8)
 *
 * Remove the highlight of a Smart Crosshair icon row.
 *   row
 * Name basis: descriptive - called by osd_select_prev|next_crosshair_icon
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a9cc8 @ 0xa00a9cc8, flags -mcpu=v8 -O3 -g.
 * Source form: osd_draw_cell_run and osd_set_highlight_window are declared without prototypes; the row is a byte.
 */
extern void osd_draw_cell_run();
extern int osd_set_highlight_window();
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern int osd_api_set_window_enable();
extern void panel_wait_sync_pulse(void);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define CHOICE_COLUMN       0x27   /* left glyph column of a choice row */
#define CHOICE_RIGHT_COLUMN 0x34   /* right glyph column of a choice row */

/* Remove the highlight of a Smart Crosshair icon row (rows 2 * row + 5 ..
 * + 7): after panel_wait_sync_pulse, clear the glyph bytes in the left and
 * right columns, set the three cells of each column to attribute 0x796 with
 * glyph 0, switch window 3 of the menu layer off and the highlight window off.
 * Called by osd_select_prev_crosshair_icon and osd_select_next_crosshair_icon. */
void osd_clear_crosshair_icon_highlight(unsigned char row)
{
    unsigned char first_row, i;
    first_row = row * 2 + 5;
    panel_wait_sync_pulse();
    for (i = 0; i < 3; i++) {
        osd_api_fill_cell_bytes(PLANE_0, CHOICE_COLUMN, first_row + i, 1, 0, MENU_LAYER_MAIN);
        osd_api_fill_cell_bytes(PLANE_0, CHOICE_RIGHT_COLUMN, first_row + i, 1, 0, MENU_LAYER_MAIN);
    }
    osd_draw_cell_run(0, 0, 0x796, CHOICE_COLUMN, first_row, 3, 0);
    osd_draw_cell_run(0, 0, 0x796, CHOICE_RIGHT_COLUMN, first_row, 3, 0);
    osd_api_set_window_enable(3, 0, MENU_LAYER_MAIN);
    osd_set_highlight_window(0, 0, 0, 0);
}
