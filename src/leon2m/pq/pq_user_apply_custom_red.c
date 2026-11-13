/* pq_user_apply_custom_red  (FUN_a00d45f8)
 *
 * Limit the custom red value to 100 and apply it.
 * Name basis: derived - settings byte +0x12; pq_api_set_rgb_gain(0, v)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d45f8 @ 0xa00d45f8, flags -mcpu=v8 -Os -g.
 * Source form: simple sequence; no special constructs.
 */
/* The custom red gain setting lives at offset 0x12 in the user settings record. */
#define USER_SETTINGS_CUSTOM_RED_GAIN_OFFSET 0x12
#define MAX_CUSTOM_RED_GAIN 100
#define RGB_CHANNEL_RED 0

extern unsigned char user_settings[]; /* 0xa802d290 */
extern int pq_api_set_rgb_gain(int, int);   /* 0xa014a11c */

/*
 * Limit the custom red gain to 100 and apply it.
 * Reads the current value from the user settings, clamps it to 100, writes it back,
 * and passes it to pq_api_set_rgb_gain for the red channel.
 * Callers: App_Initialize, ddc_handle_request, the red gain menu items, uart_cmd_set_red_gain.
 */
void pq_user_apply_custom_red(void)
{
    unsigned char red_gain = user_settings[USER_SETTINGS_CUSTOM_RED_GAIN_OFFSET];
    if (red_gain > MAX_CUSTOM_RED_GAIN)
        red_gain = MAX_CUSTOM_RED_GAIN;
    user_settings[USER_SETTINGS_CUSTOM_RED_GAIN_OFFSET] = red_gain;
    pq_api_set_rgb_gain(RGB_CHANNEL_RED, red_gain);
}
