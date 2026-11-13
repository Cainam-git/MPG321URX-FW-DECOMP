/* osd_decrease_green_gain  (FUN_a00abd00)
 *
 * Lower the green gain by 1 (left key) and apply it.
 * Note: Settings byte +0x13, range 0..100.
 * Name basis: derived - handler table 0xA802422C: left on state 0xCB (green gain)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00abd00 @ 0xa00abd00, flags -mcpu=v8 -O3 -g.
 * Source form: the clamp arm comes first ('if (v > 100) ... else { redraw }'); with the redraw arm first the
 * build differs in the argument set-up of the third osd_api_fill_cells call. Callee prototypes: the number and
 * slider drawers take byte parameters and return nothing (an int return changes the last call's argument set-up).
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern void osd_draw_value_slider(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_draw_three_digit_number(unsigned char, unsigned char, unsigned char);
extern void pq_user_apply_custom_green(void);

#define SETTING_GREEN_GAIN           0x13   /* user_settings byte: custom green gain */
#define GAIN_MAX                     100
#define GREEN_GAIN_ROW               8      /* menu row of the green gain slider (red 6, blue 0xA) */
#define GAIN_SLIDER_KIND             7
#define GAIN_NUMBER_COLUMN           0x29
#define GREEN_GAIN_GLYPH_ADDRESS     0xe8   /* glyph memory address given before the number is drawn */
#define CELL_SLIDER_ACTIVE           0x742  /* cell value of the row while its slider is being adjusted */
#define MENU_LAYER_MAIN              0
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */

/* Left key on the Green Gain slider (key table state 0xCB): lower the custom green gain by one and apply it.
 * At 0 the value stays 0 and nothing is redrawn. Otherwise the new value is stored, the row (slider bar,
 * the three label cell groups and the three-digit number) is redrawn in the active colours and the colour
 * is applied to the picture. The settings-changed request bit is always set. */
void osd_decrease_green_gain(void)
{
    unsigned char gain = user_settings[SETTING_GREEN_GAIN] - 1;

    if (gain > GAIN_MAX) {
        user_settings[SETTING_GREEN_GAIN] = 0;
    } else {
        user_settings[SETTING_GREEN_GAIN] = gain;
        osd_draw_value_slider(0x2c, GREEN_GAIN_ROW, gain, GAIN_SLIDER_KIND, 1);
        osd_api_fill_cells(0x28, GREEN_GAIN_ROW, 3, CELL_SLIDER_ACTIVE, MENU_LAYER_MAIN);
        osd_api_fill_cells(0x2b, GREEN_GAIN_ROW, 1, CELL_SLIDER_ACTIVE, MENU_LAYER_MAIN);
        osd_api_fill_cells(0x32, GREEN_GAIN_ROW, 1, CELL_SLIDER_ACTIVE, MENU_LAYER_MAIN);
        osd_api_set_glyph_write_address(GREEN_GAIN_GLYPH_ADDRESS, 0);
        osd_draw_three_digit_number(GAIN_NUMBER_COLUMN, GREEN_GAIN_ROW, user_settings[SETTING_GREEN_GAIN]);
        pq_user_apply_custom_green();
    }
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
