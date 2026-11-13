/* osd_draw_value_slider  (FUN_a00ab5f0)
 *
 * Draw a value slider: bar cells for the value and its number.
 *   x: column
 *   y: row
 *   val: value
 *   sel: slider kind
 *   active
 * Name basis: derived - called by all slider drawers (brightness, contrast, colour gains); same cell logic as
 *   osd_draw_slider_bar
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ab5f0 @ 0xa00ab5f0, flags -mcpu=v8 -O3 -g.
 * Source form: the count 6 is held in the local 'cells', so the test 'full < cells - 2' compiles to a signed
 * 'cmp full, 4' and 'rest = cells - full; rest -= 2;' to 'mov 6; sub; add -2' on the unmasked quotient; the two
 * attributes are set in an if/else with the active arm first; empty_attr lives in a stack halfword (register
 * allocator spill).
 */
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern unsigned short osd_get_menu_state(void);
extern void osd_draw_adjust_key_guide(void);
extern void osd_draw_key_guide_text(unsigned int);

#define SLIDER_CELLS          6         /* width of the bar */
#define SLIDER_STEP           10        /* half-values per cell */
#define SLIDER_KIND_WITH_GUIDE 6        /* sel value whose callers also set the key guide */
#define KEY_TEXT_MOVE         0         /* key guide texts (osd_update_key_guide) */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_ADJUST       3
#define KEY_TEXT_SAVE         5
#define KEY_TEXT_BACK         7
#define MENU_STATE_5          5         /* in this state the key guide is left alone */

/*
 * Draw a value slider: a bar of 6 cells starting at column x, row y, showing val.
 *
 *   x, y    first cell of the bar
 *   val     the value; the bar shows val / 2 on a scale of 10 per cell
 *   sel     slider kind; 6 also sets the key guide, the other kind used by callers (7) does not
 *   active  nonzero while the slider is being edited: bar and rest are drawn with the attributes 0x864a and
 *           0x834a, otherwise 0x809a and 0x839a
 *
 * With v = val / 2, full = v / 10 and part = v % 10 (full is one less when part is 0 and full is not 0):
 *   - cells x .. x + full - 1 are drawn as filled (glyph 1, plane 0);
 *   - at x + full a cell with glyph part * 2 + 1 and, when full <= 5, at x + full + 1 one with glyph
 *     part * 2 + 2, both with the bar attribute; for v == 0 the cell at x gets glyph 2 and the cell after it
 *     glyph 1 with the empty attribute 0x839a;
 *   - the remaining cells up to the width of the bar (4 - full of them, none when full >= 4) from x + full + 2
 *     get glyph 1 with the second attribute.
 * For sel == 6 the key guide is set last: while active, icon sets (2, 6), (0, 1), (1, 3) and the texts
 * 'Adjust' / 'Save'; while not active, unless the menu state is 5, osd_draw_adjust_key_guide, icon sets (2, 5),
 * (0, 0), (1, 2), the texts 'Move' / 'Enter' and the single text 'Back'.
 *
 * Called by the drawers of every slider of the menu (brightness, contrast, colour gains and others) with
 * x = 0x2c.
 */
void osd_draw_value_slider(unsigned char x, unsigned char y, unsigned char val, unsigned char sel, unsigned char active)
{
    unsigned char v, full, part, rest, i;
    unsigned char cells;
    unsigned short bar_attr;
    unsigned short empty_attr;

    v = val >> 1;
    full = v / SLIDER_STEP;
    part = v % SLIDER_STEP;
    rest = 0;
    if (part == 0 && full != 0)
        full--;
    cells = SLIDER_CELLS;
    if (full < cells - 2) {
        rest = cells - full;
        rest -= 2;
    }
    if (active) {
        bar_attr = 0x864a;
        empty_attr = 0x834a;
    } else {
        bar_attr = 0x809a;
        empty_attr = 0x839a;
    }
    if (full != 0)
        for (i = 0; i < full; i++) {
            osd_api_fill_cells(x + i, y, 1, bar_attr, 0);
            osd_api_fill_cell_bytes(0, x + i, y, 1, 1, 0);
        }
    if (v == 0) {
        osd_api_fill_cells(x + full, y, 1, bar_attr, 0);
        osd_api_fill_cell_bytes(0, x + full, y, 1, 2, 0);
        osd_api_fill_cells(x + full + 1, y, 1, 0x839a, 0);
        osd_api_fill_cell_bytes(0, x + full + 1, y, 1, 1, 0);
    } else {
        osd_api_fill_cells(x + full, y, 1, bar_attr, 0);
        osd_api_fill_cell_bytes(0, x + full, y, 1, part * 2 + 1, 0);
        if (full <= 5) {
            osd_api_fill_cells(x + full + 1, y, 1, bar_attr, 0);
            osd_api_fill_cell_bytes(0, x + full + 1, y, 1, part * 2 + 2, 0);
        }
    }
    for (i = 0; i < rest; i++) {
        osd_api_fill_cells(x + full + i + 2, y, 1, empty_attr, 0);
        osd_api_fill_cell_bytes(0, x + full + i + 2, y, 1, 1, 0);
    }
    if (active == 1) {
        if (sel == SLIDER_KIND_WITH_GUIDE) {
            osd_draw_key_guide(2, 6);
            osd_draw_key_guide(0, 1);
            osd_draw_key_guide(1, 3);
            osd_update_key_guide(KEY_TEXT_ADJUST, KEY_TEXT_SAVE);
        }
    } else if (sel == SLIDER_KIND_WITH_GUIDE) {
        if (osd_get_menu_state() != MENU_STATE_5) {
            osd_draw_adjust_key_guide();
            osd_draw_key_guide(2, 5);
            osd_draw_key_guide(0, 0);
            osd_draw_key_guide(1, 2);
            osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
            osd_draw_key_guide_text(KEY_TEXT_BACK);
        }
    }
}
