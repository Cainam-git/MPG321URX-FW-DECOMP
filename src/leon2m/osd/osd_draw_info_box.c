/* osd_draw_info_box  (FUN_a00a5908)
 *
 * Draw the information box frame and, in mode 1, the input details inside it.
 *   x: column
 *   y: row
 *   mode: 1 with input details, 2 narrow
 * Note: Mode 1 fills in Input Source, resolution, refresh rate, colour and bit depth via
 *   osd_draw_info_box_values.
 * Name basis: derived - osd_draw_info_box_values rows from texts 0x191B30 'Input Source|Native
 *   Resolution|...|Bit Depth'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a5908 @ 0xa00a5908, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: height is set in both arms of 'if (mode != 2) { height = 0x16; loop }
 * else height = 0x11;' and the same variable is the loop limit and the third argument of osd_api_fill_cells, so
 * that argument is the box height (22), not a separate width constant.
 */
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_draw_info_box_values(unsigned short, unsigned short);

#define INFO_BOX_MODE_VALUES  1         /* frame plus the input details */
#define INFO_BOX_MODE_NARROW  2         /* shorter frame (0x11 rows), no clearing, no details */
#define INFO_BOX_FULL_HEIGHT  0x16      /* rows of the frame in every mode but 2 */
#define INFO_BOX_NARROW_HEIGHT 0x11     /* rows of the frame in mode 2 */
#define INFO_BOX_CLEAR_ATTR   0x796     /* attribute of the cells the frame is drawn on */

/*
 * Draw the frame of the Info. On Screen box at column x, row y; in mode 1 also fill in the input details.
 *
 *   x, y  top-left cell of the box
 *   mode  INFO_BOX_MODE_VALUES (1): frame and details; INFO_BOX_MODE_NARROW (2): shorter frame only
 *
 * Order: (1) in every mode but 2, blank the box, one row per call (the call is given 0x796 as attribute and
 * the box height as the count); (2) draw the frame as 27 cell runs, each at a fixed offset from x and y, the
 * bottom part at an offset from y + height so the shorter frame of mode 2 keeps its bottom edge; two runs
 * (down the left and right of the middle) have a length of height - 7 and height - 6; (3) in mode 1 only, select
 * glyph write address 0x101 and text mode 2 and let osd_draw_info_box_values write the rows 'Input Source',
 * resolutions, rate and so on.
 *
 * Called from the Info. On Screen display with mode 1 (two routines) and with mode 2 at (0, 0) (two routines).
 */
void osd_draw_info_box(unsigned short x, unsigned short y, unsigned char mode)
{
    unsigned char height, i;

    if (mode != INFO_BOX_MODE_NARROW) {
        height = INFO_BOX_FULL_HEIGHT;
        for (i = 0; i < height; i++)
            osd_api_fill_cells(x, i + y, height, INFO_BOX_CLEAR_ATTR, 0);
    } else
        height = INFO_BOX_NARROW_HEIGHT;
    osd_draw_cell_run(1, 1, 0x592, x + 2, y + 2, 2, 9);
    osd_draw_cell_run(1, 0, 0x592, x + 1, height + y - 5, 1, 0xb);
    osd_draw_cell_run(1, 0, 0x592, x + 4, height + y - 4, 1, 0xc);
    osd_draw_cell_run(1, 0, 0x592, x + 0x12, height + y - 3, 1, 0xd);
    osd_draw_cell_run(0, 1, 0x592, x + 0x13, height + y - 4, 2, 0xe);
    osd_draw_cell_run(1, 1, 0x9aaa, x + 1, y, 3, 0xd);
    osd_draw_cell_run(1, 1, 0x9aaa, x, y + 1, 3, 0x10);
    osd_draw_cell_run(1, 1, 0x9aaa, x, y + 2, 2, 0x13);
    osd_draw_cell_run(1, 1, 0x9aae, x + 4, y, 0xf, 0x11);
    osd_draw_cell_run(1, 1, 0x9faa, x + 0x13, y, 3, 0x15);
    osd_draw_cell_run(1, 1, 0x9faa, x + 0x13, y + 1, 3, 0x18);
    osd_draw_cell_run(1, 1, 0xa29a, x + 0x13, y + 2, 3, 0x1b);
    osd_draw_cell_run(1, 1, 0x9aaa, x + 0x13, y + 3, 3, 0x1e);
    osd_draw_cell_run(1, 1, 0x9aaa, x + 0x13, y + 4, 3, 0x21);
    osd_draw_cell_run(1, 1, 0x9faa, x, height + y - 4, 2, 0x24);
    osd_draw_cell_run(1, 1, 0x9faa, x, height + y - 3, 2, 0x26);
    osd_draw_cell_run(1, 1, 0x9faa, x, height + y - 2, 1, 0x28);
    osd_draw_cell_run(1, 1, 0x3092, x + 2, height + y - 5, 2, 0x10);
    osd_draw_cell_run(1, 1, 0x3092, x + 2, height + y - 4, 2, 0x12);
    osd_draw_cell_run(1, 1, 0x3092, x + 2, height + y - 3, 1, 0x14);
    osd_draw_cell_run(1, 1, 0x3092, x + 1, height + y - 2, 1, 0x15);
    osd_draw_cell_run(1, 0, 0x8a2, x, y, 1, 1);
    osd_draw_cell_run(0, 0, 0x8a2, x, y + 3, height - 7, 7);
    osd_draw_cell_run(0, 0, 0x8a2, x + 0x15, y + 5, height - 6, 8);
    osd_draw_cell_run(1, 0, 0x8a2, x, height + y - 1, 1, 3);
    osd_draw_cell_run(1, 0, 0x8a2, x + 1, height + y - 1, 0x14, 6);
    osd_draw_cell_run(1, 0, 0x8a2, x + 0x15, height + y - 1, 1, 4);
    if (mode == INFO_BOX_MODE_VALUES) {
        osd_api_set_glyph_write_address(0x101, 0);
        osd_api_set_text_mode(2, 0);
        osd_draw_info_box_values(x, y);
    }
}
