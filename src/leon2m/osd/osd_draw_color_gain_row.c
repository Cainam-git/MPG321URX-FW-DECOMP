/* osd_draw_color_gain_row  (FUN_a00ab96c)
 *
 * Draw the red, green or blue gain row of the custom colour page.
 *   row: 0 red, 1 green, 2 blue
 *   active
 * Note: Gains = settings bytes +0x12 / +0x13 / +0x14.
 * Name basis: derived - same code as osd_draw_red|green|blue_gain by row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ab96c @ 0xa00ab96c, flags -mcpu=v8 -O3 -g.
 * Source form: user_settings is a byte array; one osd_draw_value_slider call per row arm; byte and unsigned short
 * prototypes. The cell value is chosen first (the compiler turns the choice into arithmetic without a branch).
 */
extern unsigned char user_settings[];
extern void osd_draw_value_slider(unsigned char column, unsigned char row, unsigned char value, unsigned char kind, unsigned char active);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);

#define MENU_LAYER_MAIN       0
#define GAIN_SLIDER_COLUMN    0x2c
#define GAIN_SLIDER_KIND      7
#define GAIN_NUMBER_COLUMN    0x29
#define CELL_GAIN_ACTIVE      0x742   /* cell value of the gain row cells, row active */
#define CELL_GAIN_NORMAL      0x792   /* same, row not active */

#define SETTING_RED_GAIN      0x12    /* byte offsets in user_settings */
#define SETTING_GREEN_GAIN    0x13
#define SETTING_BLUE_GAIN     0x14

/* Draw one gain row of the custom colour page: the slider and number of the
 * gain (red row 6, green row 8, blue row 10) and the cells around the number.
 *   row:    0 red, 1 green, 2 blue (the gains are settings bytes +0x12,
 *           +0x13, +0x14)
 *   active: non-zero for the row the cursor is on; it picks the cell value
 *           CELL_GAIN_ACTIVE instead of CELL_GAIN_NORMAL
 * The cells set are 3 at column 0x28, and one each at columns 0x2B and 0x32.
 * Same drawing as osd_draw_red_gain, osd_draw_green_gain and
 * osd_draw_blue_gain. */
void osd_draw_color_gain_row(unsigned char row, unsigned char active)
{
  unsigned short cell;
  unsigned short y;
  if (active)
    cell = CELL_GAIN_ACTIVE;
  else
    cell = CELL_GAIN_NORMAL;
  if (row == 0)
    osd_draw_value_slider(GAIN_SLIDER_COLUMN, 6, user_settings[SETTING_RED_GAIN], GAIN_SLIDER_KIND, active);
  else if (row == 1)
    osd_draw_value_slider(GAIN_SLIDER_COLUMN, 8, user_settings[SETTING_GREEN_GAIN], GAIN_SLIDER_KIND, active);
  else
    osd_draw_value_slider(GAIN_SLIDER_COLUMN, 10, user_settings[SETTING_BLUE_GAIN], GAIN_SLIDER_KIND, active);
  y = row * 2 + 6;
  osd_api_fill_cells(0x28, y, 3, cell, MENU_LAYER_MAIN);
  osd_api_fill_cells(0x2b, y, 1, cell, MENU_LAYER_MAIN);
  osd_api_fill_cells(0x32, y, 1, cell, MENU_LAYER_MAIN);
}
