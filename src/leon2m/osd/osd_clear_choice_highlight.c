/* osd_clear_choice_highlight  (FUN_a00a93bc)
 *
 * Remove the highlight of a choice row.
 *   choice: choice row
 * Name basis: derived - called before osd_highlight_choice_row in every choice step handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a93bc @ 0xa00a93bc, flags -mcpu=v8 -O3 -g.
 * Source form: base is an unsigned short local, the counter an unsigned char; each row is (base & 0xff) + counter.
 * osd_set_highlight_window is called with all four arguments (the firmware sets all four argument registers).
 */
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern void osd_api_set_window_enable(unsigned int window, unsigned int on, unsigned int layer);
extern int panel_wait_sync_pulse(void);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define CHOICE_COLUMN       0x27   /* left glyph column of a choice row */
#define CHOICE_RIGHT_COLUMN 0x34   /* right glyph column of a choice row */

/* Remove the highlight of a choice row: wait twice for panel_wait_sync_pulse,
 * switch window 3 of the menu layer off and the highlight window off, wait
 * once more, then clear the glyph bytes in the left and right columns of the
 * three rows of the choice (rows 2 * choice + 5 .. + 7). Called before
 * osd_highlight_choice_row in every choice step handler. */
void osd_clear_choice_highlight(unsigned char choice)
{
    unsigned char i;
    unsigned short row;
    unsigned short base;
    base = choice * 2 + 5;
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_api_set_window_enable(3, 0, MENU_LAYER_MAIN);
    osd_set_highlight_window(0, 0, 0, 0);
    panel_wait_sync_pulse();
    i = 0;
    do {
        row = (base & 0xff) + i;
        osd_api_fill_cell_bytes(PLANE_0, CHOICE_COLUMN, row, 1, 0, MENU_LAYER_MAIN);
        osd_api_fill_cell_bytes(PLANE_0, CHOICE_RIGHT_COLUMN, row, 1, 0, MENU_LAYER_MAIN);
        i++;
    } while (i < 3);
}
