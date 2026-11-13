/* pq_user_apply_custom_green  (FUN_a00d462c)
 *
 * Limit the custom green value to 100 and apply it.
 * Name basis: derived - settings byte +0x13; pq_api_set_rgb_gain(1, v)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d462c @ 0xa00d462c (-mcpu=v8 -Os -g)
 * Source form: straightforward.
 */
extern unsigned char user_settings[23]; /* 0xa802d290 */
extern int pq_api_set_rgb_gain(int, int);     /* 0xa014a11c */

#define CUSTOM_GREEN_GAIN_OFFSET 0x13   /* offset in user_settings */
#define MAX_GAIN 100                    /* maximum allowed gain */
#define CHANNEL_GREEN 1                 /* green channel index for pq_api_set_rgb_gain */

/*
 * Limit the custom green gain to 100 and apply it.
 * Reads the green gain from the user settings record, clamps it to 100,
 * stores it back and passes it to pq_api_set_rgb_gain for the green channel.
 * Callers: App_Initialize, ddc_handle_request, the green gain menu items, uart_cmd_set_green_gain.
 */
void pq_user_apply_custom_green(void)
{
    unsigned char green_gain = user_settings[CUSTOM_GREEN_GAIN_OFFSET];
    if (green_gain > MAX_GAIN)
        green_gain = MAX_GAIN;
    user_settings[CUSTOM_GREEN_GAIN_OFFSET] = green_gain;
    pq_api_set_rgb_gain(CHANNEL_GREEN, green_gain);
}
