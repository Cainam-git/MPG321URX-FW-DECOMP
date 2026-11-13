/* osd_draw_toggle_switch  (FUN_a00a9f30)
 *
 * Draw the OFF/ON switch of a Settings item in normal colours.
 *   item: item index
 *   switch_on: switch state
 * Note: Normal-colour twin of osd_draw_toggle_switch_selected.
 * Name basis: derived - same layout as osd_draw_toggle_switch_selected with attributes 0x792/0x592
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a9f30 @ 0xa00a9f30, flags -mcpu=v8 -O3 -g.
 * Source form: one j loop with the "switch_on == 0" test inside it (the off arm first); -O3 loop unswitching makes
 * the two loops. Same form as osd_draw_toggle_switch_selected with other cell values.
 */
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN      0
#define PLANE_0              0
#define SWITCH_COLUMN        0x22
#define CELL_NORMAL_OFF      0x592   /* cell value of the three switch cells, off */
#define CELL_NORMAL_ON       0x792   /* same, on */
#define SWITCH_OFF_GLYPHS    0x34    /* first of three glyph bytes, off */
#define SWITCH_ON_GLYPHS     0x37    /* first of three glyph bytes, on */

/* Draw the OFF/ON switch of a Settings item in the normal (not selected)
 * colours; the twin of osd_draw_toggle_switch_selected.
 *   item:      item index on its page; items 0..6 are drawn at rows 6, 8 .. 18,
 *              and item 7 and above start again at row 6 (the next page)
 *   switch_on: 0 = off, else on
 * Called by the Settings toggle handlers. */
void osd_draw_toggle_switch(unsigned char item, unsigned char switch_on)
{
  unsigned char row;
  unsigned char j;
  if (item > 6)
    row = item * 2 - 8;
  else
    row = item * 2 + 6;
  for (j = 0; j < 3; j++) {
    if (switch_on == 0) {
      osd_api_fill_cells(SWITCH_COLUMN, row, 3, CELL_NORMAL_OFF, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, j + SWITCH_COLUMN, row, 1, j + SWITCH_OFF_GLYPHS, MENU_LAYER_MAIN);
    } else {
      osd_api_fill_cells(SWITCH_COLUMN, row, 3, CELL_NORMAL_ON, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, j + SWITCH_COLUMN, row, 1, j + SWITCH_ON_GLYPHS, MENU_LAYER_MAIN);
    }
  }
}
