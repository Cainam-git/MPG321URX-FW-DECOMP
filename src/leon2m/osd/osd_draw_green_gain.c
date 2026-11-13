/* osd_draw_green_gain  (FUN_a00abc64)
 *
 * Draw the green gain slider of the custom colour page.
 *   active
 * Note: Settings byte +0x13, row 8.
 * Name basis: derived - called by the osd_move_cursor_* colour handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00abc64 @ 0xa00abc64, flags -mcpu=v8 -O3 -g.
 * Source form: the same as its twin osd_draw_blue_gain - user_settings is a byte array (a load of the byte at +0x13), the
 * number is drawn with a tail call, the cell value is an unsigned short chosen with a conditional expression.
 */
extern unsigned char user_settings[];
extern void osd_draw_value_slider(unsigned char column, unsigned char row, unsigned char value, unsigned char kind, unsigned char active);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_draw_three_digit_number(unsigned char column, unsigned char row, unsigned char value);

#define MENU_LAYER_MAIN       0
#define GAIN_SLIDER_COLUMN    0x2c
#define GAIN_SLIDER_KIND      7
#define GAIN_NUMBER_COLUMN    0x29
#define CELL_GAIN_ACTIVE      0x742   /* cell value of the gain row cells, row active */
#define CELL_GAIN_NORMAL      0x792   /* same, row not active */

#define SETTING_GREEN_GAIN    0x13    /* byte offset in user_settings */
#define GREEN_GAIN_ROW        8

/* Draw the green gain row of the custom colour page (row 8): the slider and
 * the cells around the number, then the number itself with the glyph write
 * address 0xE8.
 *   active: non-zero for the row the cursor is on (cell value
 *           CELL_GAIN_ACTIVE instead of CELL_GAIN_NORMAL)
 * Called by the osd_move_cursor_* colour handlers. */
void osd_draw_green_gain(unsigned char active)
{
  unsigned short cell = active ? CELL_GAIN_ACTIVE : CELL_GAIN_NORMAL;
  osd_draw_value_slider(GAIN_SLIDER_COLUMN, GREEN_GAIN_ROW, user_settings[SETTING_GREEN_GAIN], GAIN_SLIDER_KIND, active);
  osd_api_fill_cells(0x28, GREEN_GAIN_ROW, 3, cell, MENU_LAYER_MAIN);
  osd_api_fill_cells(0x2b, GREEN_GAIN_ROW, 1, cell, MENU_LAYER_MAIN);
  osd_api_fill_cells(0x32, GREEN_GAIN_ROW, 1, cell, MENU_LAYER_MAIN);
  osd_api_set_glyph_write_address(0xe8, MENU_LAYER_MAIN);
  osd_draw_three_digit_number(GAIN_NUMBER_COLUMN, GREEN_GAIN_ROW, user_settings[SETTING_GREEN_GAIN]);
}
