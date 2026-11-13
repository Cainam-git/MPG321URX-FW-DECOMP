/* pq_user_set_custom_blue  (FUN_a00d972c)
 *
 * Limit the custom blue value to 100, apply it and re-apply the colour temperature.
 * Name basis: derived - settings byte +0x14; pq_api_set_rgb_gain(2, v)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d972c @ 0xa00d972c-0xa00d9764 (14 words), flags -mcpu=v8 -O2 -g (section default).
 * Source forms the exact build depends on: the record is reached through a struct pointer (sethi|or of
 * 0xa802d290, field +0x14); 'gain' is an unsigned short local, so the firmware compares the loaded byte
 * directly and extends it again only for the unsigned char argument ('and 0xff' in the call delay slot);
 * u32, int, short or u8 for it give other code.
 */

#define RGB_BLUE   2
#define GAIN_MAX   100

/* The one field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x14];
    unsigned char blue_gain;                    /* +0x14: the custom blue gain */
};
extern struct user_settings_record user_settings;
extern void pq_api_set_rgb_gain(int color, unsigned char gain);
extern void pq_user_apply_color_temperature(void);

/*
 * Limit the custom blue gain to 100, store the limited value back, give it to the colour matrix
 * (pq_api_set_rgb_gain) and then apply the colour values of the chosen colour temperature again
 * (pq_user_apply_color_temperature, a tail call).
 */
void pq_user_set_custom_blue(void)
{
    struct user_settings_record *settings = &user_settings;
    unsigned short gain = settings->blue_gain;

    if (gain > GAIN_MAX)
        gain = GAIN_MAX;
    settings->blue_gain = gain;
    pq_api_set_rgb_gain(RGB_BLUE, gain);
    pq_user_apply_color_temperature();
}
