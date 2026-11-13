/* oled_user_apply_multi_logo  (FUN_a00dac00)
 *
 * Apply the multi-logo detection setting, or 0 when the function is off.
 * Name basis: proven - oled_set_multi_logo
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dac00 @ 0xa00dac00, flags -mcpu=v8 -O2 -g (section default; -O3 -g gives the same bytes).
 * Source form: the off case is written first, with its own call and return.
 */

/* The two bytes of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1e8];
    unsigned char multi_logo_detection;    /* +0x1E8: Multi Logo Detection on (non-zero) or off */
    unsigned char multi_logo_level;        /* +0x1E9: the Multi Logo Detection level */
};
extern struct user_settings_record user_settings;
extern int oled_set_multi_logo(unsigned char);

/*
 * Send the Multi Logo Detection setting of the OLED Care menu to the OLED panel controller: the chosen
 * level when the detection is on, 0 when it is off.
 */
void oled_user_apply_multi_logo(void)
{
    if (user_settings.multi_logo_detection == 0) {
        oled_set_multi_logo(0);
        return;
    }
    oled_set_multi_logo(user_settings.multi_logo_level);
}
