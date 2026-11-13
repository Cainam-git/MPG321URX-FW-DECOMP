/* osd_decrease_blue_gain  (FUN_a00abad0)
 *
 * Lower the blue gain by 1 (left key) and apply it.
 * Note: Settings byte +0x14, range 0..100.
 * Name basis: derived - handler table 0xA802422C: left on state 0xCC (blue gain)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00abad0 @ 0xa00abad0, flags -mcpu=v8 -O3 -g.
 * Source form: the same form as osd_increase_red_gain - the new value is computed once into a byte (the subtraction is
 * done once and the range test is on it), the clamp arm comes first; void and unsigned char prototypes.
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern void osd_draw_value_slider(unsigned char column, unsigned char row, unsigned char value, unsigned char kind, unsigned char active);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_draw_three_digit_number(unsigned char column, unsigned char row, unsigned char value);
extern void pq_user_set_custom_blue(void);

#define MENU_LAYER_MAIN       0
#define GAIN_SLIDER_COLUMN    0x2c
#define GAIN_SLIDER_KIND      7
#define GAIN_NUMBER_COLUMN    0x29
#define CELL_GAIN_ACTIVE      0x742   /* cell value of the gain row cells, row active */
#define CELL_GAIN_NORMAL      0x792   /* same, row not active */

#define SETTING_BLUE_GAIN     0x14    /* byte offset in user_settings */
#define BLUE_GAIN_ROW         0xa
#define OSD_REQUEST_SETTINGS_CHANGED 0x02

/* Left key on the blue gain row (menu state 0xCC): lower the custom blue gain
 * by one, down to 0. A result above 100 means the byte wrapped from 0, so the
 * gain stays 0 and nothing is redrawn. Otherwise the new value is stored,
 * the slider, the cells and the number are redrawn in the active colours and
 * pq_user_set_custom_blue applies it. The settings-changed request is raised
 * in both cases. */
void osd_decrease_blue_gain(void)
{
  unsigned char new_value = user_settings[SETTING_BLUE_GAIN] - 1;
  if (new_value > 100) {
    user_settings[SETTING_BLUE_GAIN] = 0;
  } else {
    user_settings[SETTING_BLUE_GAIN] = new_value;
    osd_draw_value_slider(GAIN_SLIDER_COLUMN, BLUE_GAIN_ROW, new_value, GAIN_SLIDER_KIND, 1);
    osd_api_fill_cells(0x28, BLUE_GAIN_ROW, 3, CELL_GAIN_ACTIVE, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x2b, BLUE_GAIN_ROW, 1, CELL_GAIN_ACTIVE, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x32, BLUE_GAIN_ROW, 1, CELL_GAIN_ACTIVE, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0xea, MENU_LAYER_MAIN);
    osd_draw_three_digit_number(GAIN_NUMBER_COLUMN, BLUE_GAIN_ROW, user_settings[SETTING_BLUE_GAIN]);
    pq_user_set_custom_blue();
  }
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
