/* pq_api_set_rgb_gain  (FUN_a014a11c)
 *
 * Store the gain 0..100 of the red, green or blue channel and apply it.
 * Name basis: derived - three stSysConfig bytes; value scaled to (v * 2 + 0x38) and passed to the colour
 *   matrix parameters
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a11c, flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the scaling expression written out in every case (unsigned arithmetic); the
 * setters take an unsigned short and are tail calls.
 */
extern unsigned char sys_config_red_gain, sys_config_green_gain, sys_config_blue_gain;
extern void pq_color_matrix_set_red_gain(unsigned short gain);
extern void pq_color_matrix_set_green_gain(unsigned short gain);
extern void pq_color_matrix_set_blue_gain(unsigned short gain);

#define RGB_RED   0
#define RGB_GREEN 1
#define RGB_BLUE  2
#define GAIN_BASE 0x38          /* matrix gain of setting 0; each step adds 2, so setting 100 gives 0x100 */

/*
 * Store the gain setting of one colour in sys_config (bytes +0xC..+0xE) and give it to the colour matrix as
 * the gain of that colour's row, (gain * 200 + 50) / 100 + GAIN_BASE, which rebuilds the matrix.
 *
 *   color  RGB_RED, RGB_GREEN or RGB_BLUE; any other value does nothing
 *   gain   the setting 0..100 (the callers limit it to 100)
 *
 * Callers: pq_user_apply_custom_red / _green, pq_user_set_custom_blue, pq_user_apply_color_settings,
 * sys_user_reset_settings_keep_source and sys_user_factory_reset.
 */
void pq_api_set_rgb_gain(unsigned char color, unsigned char gain)
{
    switch (color) {
    case RGB_RED:
        sys_config_red_gain = gain;
        pq_color_matrix_set_red_gain((gain * 200u + 50) / 100 + GAIN_BASE);
        break;
    case RGB_GREEN:
        sys_config_green_gain = gain;
        pq_color_matrix_set_green_gain((gain * 200u + 50) / 100 + GAIN_BASE);
        break;
    case RGB_BLUE:
        sys_config_blue_gain = gain;
        pq_color_matrix_set_blue_gain((gain * 200u + 50) / 100 + GAIN_BASE);
        break;
    }
}
