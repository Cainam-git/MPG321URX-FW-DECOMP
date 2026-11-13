/* osd_draw_dialog_frame  (FUN_a00b0a90)
 *
 * Draw the frame of a dialog box and highlight its current button.
 * Note: Button = byte 0xA802D43A.
 * Name basis: derived - 30 frame pieces; called by the change notice openers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b0a90 @ 0xa00b0a90, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: osd_draw_cell_run and osd_highlight_dialog_button are declared
 * without a prototype (old-style), and osd_highlight_dialog_button is called with six arguments, the last four
 * being the routine's own parameters param_3..param_6 passed on unchanged. The routine therefore keeps six
 * parameters although it uses none of them itself; callers pass none.
 */
extern unsigned char user_settings_notice_button;
extern int osd_highlight_dialog_button();
extern void osd_draw_cell_run();

/* Draw the frame of the dialog box (used by the change notice) in a layer of 0x28 x 0xb cells, then
 * highlight the button given by settings byte +0x1AA (layout 0 of osd_highlight_dialog_button:
 * two buttons).
 * The frame is 30 calls of osd_draw_cell_run(across, rising, attribute, column, row, count, glyph):
 *   - the first six all use attribute 0x8a2: glyph 1 at column 0 row 0, glyph 4 at column 0x27
 *     row 10, glyph 5 over 7 cells from column 1 row 0, glyph 6 over 0x22 cells from column 5 row
 *     10, glyph 7 down 8 cells from column 0 row 1, glyph 8 down 7 cells from column 0x27 row 3;
 *   - the rest write runs of fixed glyph numbers (0x20 .. 0x91) with their own attributes; they
 *     build the pieces inside the frame, and what each run draws is not shown by the code.
 * None of the six parameters is used here; the last four are passed on to
 * osd_highlight_dialog_button unchanged. */
void osd_draw_dialog_frame(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4,
                 unsigned int param_5, unsigned int param_6)
{
    osd_draw_cell_run(1, 1, 0x8a2, 0, 0, 1, 1);
    osd_draw_cell_run(1, 1, 0x8a2, 0x27, 10, 1, 4);
    osd_draw_cell_run(1, 0, 0x8a2, 1, 0, 7, 5);
    osd_draw_cell_run(1, 0, 0x8a2, 5, 10, 0x22, 6);
    osd_draw_cell_run(0, 0, 0x8a2, 0, 1, 8, 7);
    osd_draw_cell_run(0, 0, 0x8a2, 0x27, 3, 7, 8);
    osd_draw_cell_run(1, 1, 0x12aa, 6, 0, 1, 0x72);
    osd_draw_cell_run(1, 1, 0xa89a, 0x20, 1, 1, 0x73);
    osd_draw_cell_run(1, 1, 0xa89a, 1, 8, 1, 0x74);
    osd_draw_cell_run(1, 1, 0x592, 3, 1, 2, 0x26);
    osd_draw_cell_run(1, 1, 0x592, 0x1f, 1, 1, 0x28);
    osd_draw_cell_run(1, 1, 0x592, 0x22, 1, 1, 0x29);
    osd_draw_cell_run(1, 1, 0x592, 6, 9, 1, 0x2a);
    osd_draw_cell_run(1, 1, 0x592, 0x24, 9, 1, 0x2b);
    osd_draw_cell_run(1, 1, 0x592, 0x25, 8, 2, 0x2c);
    osd_draw_cell_run(1, 1, 0x592, 0x25, 9, 2, 0x2e);
    osd_draw_cell_run(1, 1, 0x9aae, 8, 0, 0x18, 0x20);
    osd_draw_cell_run(1, 1, 0x9aaa, 0x20, 0, 4, 0x75);
    osd_draw_cell_run(1, 1, 0x9aaa, 0x21, 1, 1, 0x79);
    osd_draw_cell_run(1, 1, 0xa29a, 0x24, 0, 3, 0x7a);
    osd_draw_cell_run(1, 1, 0xaaaa, 0x27, 0, 1, 0x7d);
    osd_draw_cell_run(1, 1, 0x9aaa, 0x23, 1, 5, 0x7e);
    osd_draw_cell_run(1, 1, 0x9aaa, 0x23, 2, 5, 0x83);
    osd_draw_cell_run(1, 1, 0x9faa, 0, 9, 1, 0x8e);
    osd_draw_cell_run(1, 1, 0x9faa, 2, 9, 2, 0x8f);
    osd_draw_cell_run(1, 1, 0x9faa, 0, 10, 5, 0x91);
    osd_draw_cell_run(1, 1, 0x3392, 2, 8, 2, 0x30);
    osd_draw_cell_run(1, 1, 0x3392, 1, 9, 1, 0x32);
    osd_draw_cell_run(1, 1, 0x3092, 4, 8, 3, 0x33);
    osd_draw_cell_run(1, 1, 0x3092, 4, 9, 2, 0x36);
    osd_highlight_dialog_button(0, user_settings_notice_button, param_3, param_4, param_5, param_6);
    return;
}
