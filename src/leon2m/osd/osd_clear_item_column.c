/* osd_clear_item_column  (FUN_a00a7d70)
 *
 * Clear the item column rows 6..0x15.
 * Note: No reference to it was found in the handler or event tables.
 * Name basis: descriptive - same loop as the start of osd_redraw_settings_page
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a7d70 @ 0xa00a7d70, flags -mcpu=v8 -O2 -g. Reached through a table (no direct caller).
 * Source form: the row-5 and row-7 tests are two nested ifs.
 */
extern void panel_wait_sync_pulse(void);
extern void osd_draw_cell_run(unsigned int across, unsigned int rising, unsigned int attribute, unsigned int column, unsigned int row, unsigned int count, unsigned int first_glyph);

#define CELL_BLANK      0x792
#define CELL_ROW6_BLANK 0x7c2   /* row 6 only */

/* Clear the item column: after a call to panel_wait_sync_pulse, rows 6 to 0x15
 * except row 7 get a run across from column 7 with glyph 0: 10 cells of
 * 0x7C2 in row 6, 11 cells of CELL_BLANK in the other rows. (The code also
 * tests for row 5, which the loop never reaches.) */
void osd_clear_item_column(void)
{
    unsigned char i;
    panel_wait_sync_pulse();
    for (i = 6; i <= 0x15; i++) {
        if (i != 5)
            if (i != 7) {
                if (i == 6)
                    osd_draw_cell_run(1, 0, CELL_ROW6_BLANK, 7, 6, 10, 0);
                else
                    osd_draw_cell_run(1, 0, CELL_BLANK, 7, i, 0xb, 0);
            }
    }
}
