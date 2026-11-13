/* osd_draw_message_frame  (FUN_a00a5714)
 *
 * Draw the frame of a message box around a cell position.
 *   x: column
 *   y: row
 * Name basis: descriptive - eleven frame pieces around (x, y); called by the message page drawer
 *   osd_draw_signal_message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a5714 @ 0xa00a5714, flags -mcpu=v8 -O3 -g.
 * Source form: osd_draw_cell_run takes (u8, u8, u16, u16, u8, u8, u8); its last argument is passed on the stack.
 */
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned short column, unsigned char row, unsigned char count, unsigned char first_glyph);

#define CELL_FRAME 0x8a2

/* Draw the frame of a message box, eleven runs of cells placed relative to the
 * top left corner (x, y):
 *   x: column of the corner
 *   y: row of the corner
 * The runs use three cell attributes: 0x12AA (x+1 rows y, y+1, y+3 and x+0xB
 * row y+4), 0x89AE (x+3, x+0xC and x, rows y, y+1, y+4) and CELL_FRAME (x,
 * x+0xD and x+4, rows y, y+1, y+2, y+4). Called by the message page drawer. */
void osd_draw_message_frame(unsigned short x, unsigned char y)
{
    osd_draw_cell_run(1, 1, 0x12aa, x + 1, y, 2, 0);
    osd_draw_cell_run(1, 0, 0x12aa, x + 1, y + 1, 1, 2);
    osd_draw_cell_run(1, 0, 0x12aa, x + 1, y + 3, 1, 3);
    osd_draw_cell_run(1, 1, 0x89ae, x + 3, y, 0xb, 0);
    osd_draw_cell_run(1, 1, 0x89ae, x + 0xc, y + 1, 2, 0xb);
    osd_draw_cell_run(1, 1, 0x89ae, x, y + 4, 4, 0xd);
    osd_draw_cell_run(1, 1, 0x12aa, x + 0xb, y + 4, 3, 4);
    osd_draw_cell_run(1, 0, CELL_FRAME, x, y, 1, 1);
    osd_draw_cell_run(0, 0, CELL_FRAME, x, y + 1, 3, 7);
    osd_draw_cell_run(0, 0, CELL_FRAME, x + 0xd, y + 2, 2, 8);
    osd_draw_cell_run(1, 0, CELL_FRAME, x + 4, y + 4, 7, 6);
}
