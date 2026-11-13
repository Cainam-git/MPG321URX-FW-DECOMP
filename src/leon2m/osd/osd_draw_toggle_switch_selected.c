/* osd_draw_toggle_switch_selected  (FUN_a00a5420)
 *
 * Draw the OFF/ON switch of a Settings item in selected colours.
 *   item: item index
 *   switch_on: switch state
 * Note: Row from the item index; the second argument picks OFF or ON.
 * Name basis: derived - called by osd_toggle_info_on_screen / _hdmi_cec / _type_c_pd_charge / _power_led;
 *   attributes 0x742/0x542
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a5420 @ 0xa00a5420, flags -mcpu=v8 -O3 -g.
 * Source form: one j loop with the "switch_on == 0" test inside it (the off arm first); -O3 loop unswitching makes
 * the two loops. Same form as osd_draw_toggle_switch with other cell values.
 */
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN      0
#define PLANE_0              0
#define SWITCH_COLUMN        0x22
#define CELL_SELECTED_OFF    0x542   /* cell value of the three switch cells, off */
#define CELL_SELECTED_ON     0x742   /* same, on */
#define SWITCH_OFF_GLYPHS    0x34    /* first of three glyph bytes, off */
#define SWITCH_ON_GLYPHS     0x37    /* first of three glyph bytes, on */

/* Draw the OFF/ON switch of a Settings item in the selected-item colours.
 *   item:      item index on its page; items 0..6 are drawn at rows 6, 8 .. 18,
 *              and item 7 and above start again at row 6 (the next page)
 *   switch_on: 0 = off, else on
 * The switch is three cells wide at column 0x22: a cell value for each, then
 * a glyph byte for each. Called by the Settings toggle handlers. */
void osd_draw_toggle_switch_selected(unsigned char item, unsigned char switch_on)
{
  unsigned char row;
  unsigned char j;
  if (item > 6)
    row = item * 2 - 8;
  else
    row = item * 2 + 6;
  for (j = 0; j < 3; j++) {
    if (switch_on == 0) {
      osd_api_fill_cells(SWITCH_COLUMN, row, 3, CELL_SELECTED_OFF, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, j + SWITCH_COLUMN, row, 1, j + SWITCH_OFF_GLYPHS, MENU_LAYER_MAIN);
    } else {
      osd_api_fill_cells(SWITCH_COLUMN, row, 3, CELL_SELECTED_ON, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, j + SWITCH_COLUMN, row, 1, j + SWITCH_ON_GLYPHS, MENU_LAYER_MAIN);
    }
  }
}
