/* osd_draw_frame_highlight  (FUN_a00ad5a4)
 *
 * Draw the plain or selected frame of a three-row block: quick menu row or dialog button.
 *   kind
 *   column
 *   row
 *   selected
 * Note: Kind 2 = quick menu row (16 cells wide), kind 3 = dialog button (10 cells wide).
 * Name basis: derived - called by osd_highlight_quick_menu_row (kind 2) and by osd_highlight_dialog_button for
 *   every button (kind 3)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ad5a4 @ 0xa00ad5a4-0xa00ad86c (178 words), flags -mcpu=v8 -O3 -g.
 * Source form: two if/else blocks on selected: the first sets edge_attr and glyph (selects at 0xa00ad5d4 and
 * 0xa00ad618), the second sets fill_attr, run_attr and makes the selected calls; the 'and 0x7c2' / 'and 0xb92' at
 * 0xa00ad73c / 0xa00ad754 are the zero-extension of fill_attr / run_attr at the calls.
 */
/* Frame kinds. Kind 2 is a quick menu row (called by osd_highlight_quick_menu_row); kind 3 is a
 * dialog button (called by osd_highlight_dialog_button); both are three cell rows high. */
#define FRAME_KIND_QUICK_MENU_ROW 2
#define FRAME_KIND_DIALOG_BUTTON  3
#define FRAME_WIDTH_BUTTON        10
#define FRAME_WIDTH_ROW           16
#define FRAME_LEFT_GLYPH          0x29
#define FRAME_RIGHT_GLYPH         0x2c

/* app_state_record dialog_button_index (+0x3F). */
extern unsigned char osd_dialog_button_index;
extern void osd_set_highlight_window(unsigned char, unsigned char, unsigned int, unsigned int);
extern void osd_draw_cell_run(unsigned char dir, unsigned char inc, unsigned short c, unsigned short x, unsigned char y,
                         unsigned char n, unsigned char ch);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_window_enable(int, int, int);

/* Draw, or take back, the frame around one three-row cell block.
 *   kind:     FRAME_KIND_QUICK_MENU_ROW (width 16) or FRAME_KIND_DIALOG_BUTTON (width 10).
 *   column:   left column of the block.
 *   row:      top row of the block.
 *   selected: 0 draws the plain frame, non-zero the selected one.
 * Selected: the highlight window is placed over the block (width - 2) and the left and right edges
 * are written (glyphs 0x29 and 0x2c, attribute 0x589a), then windows 1 and 2 are switched on. For
 * a quick menu row at row 10 the left edge is two cells high and a third cell with glyph 0x2f
 * (attribute 0xa59a) follows below it. For a dialog button the top and bottom edge runs
 * (glyph, and glyph + 1) and the cleared middle row are written with the selected or plain
 * attributes; the plain button also redraws its two edges with attribute 0x5b9a. The top/bottom
 * glyph is 0x38/0x3a (selected/plain) when osd_dialog_button_index is 0, else 0x3c/0x3e. */
void osd_draw_frame_highlight(unsigned char kind, unsigned char column, unsigned char row, unsigned char selected)
{
    unsigned char width = (kind == FRAME_KIND_DIALOG_BUTTON) ? FRAME_WIDTH_BUTTON : FRAME_WIDTH_ROW;
    unsigned char glyph;
    unsigned short edge_attr, fill_attr, run_attr;

    /* edge_attr: attribute of the edges; glyph: glyph of the top edge (the bottom one is glyph + 1). */
    if (selected == 0) {
        edge_attr = 0x5b9a;
        glyph = osd_dialog_button_index == 0 ? 0x3a : 0x3e;
    } else {
        edge_attr = 0x589a;
        glyph = osd_dialog_button_index == 0 ? 0x38 : 0x3c;
    }
    /* fill_attr: attribute of the middle row, run_attr: attribute of the top and bottom edge runs. */
    if (selected == 0) {
        fill_attr = 0x7c2;
        run_attr = 0xb92;
    } else {
        fill_attr = 0x742;
        run_attr = 0x392;
        osd_set_highlight_window(1, column, row, (unsigned char)(width - 2));
        if (row == 0xa && kind == FRAME_KIND_QUICK_MENU_ROW) {
            osd_draw_cell_run(0, 1, 0x589a, column, row, 2, FRAME_LEFT_GLYPH);
            osd_draw_cell_run(0, 0, 0xa59a, column, row + 2, 1, 0x2f);
        } else
            osd_draw_cell_run(0, 1, 0x589a, column, row, 3, FRAME_LEFT_GLYPH);
        osd_draw_cell_run(0, 1, 0x589a, column + width - 1, row, 3, FRAME_RIGHT_GLYPH);
        osd_api_set_window_enable(1, 1, 0);
        osd_api_set_window_enable(2, 1, 0);
    }
    if (kind == FRAME_KIND_DIALOG_BUTTON) {
        if (selected == 0) {
            osd_draw_cell_run(0, 1, edge_attr, column, row, 3, FRAME_LEFT_GLYPH);
            osd_draw_cell_run(0, 1, edge_attr, column + width - 1, row, 3, FRAME_RIGHT_GLYPH);
        }
        osd_api_fill_cells(column + 1, row + 1, width - 2, fill_attr, 0);
        osd_draw_cell_run(1, 0, run_attr, column + 1, row, width - 2, glyph);
        osd_draw_cell_run(1, 0, run_attr, column + 1, row + 2, width - 2, glyph + 1);
    }
}
