/* pq_user_apply_theme_mode  (FUN_a00d58b0)
 *
 * Apply the theme mode setting, limited to 4.
 * Name basis: derived - SetThemeMode with settings byte +0x1A; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d58b0 @ 0xa00d58b0-0xa00d58d8 (10 words).
 * Source form: the limited value is held in an unsigned short (an unsigned char drops the and 0xff before the call).
 */
#define THEME_MODE_MAX 4   /* the highest theme mode value accepted */

extern unsigned char user_settings_theme_mode;
extern void SetThemeMode(unsigned char);

/*
 * Apply the theme mode setting from user settings, limited to 4.
 * Reads user_settings_theme_mode (settings byte +0x1A), clamps it to 4,
 * and passes the result to SetThemeMode, which applies the picture theme
 * preset mode to one or both channels.
 */
void pq_user_apply_theme_mode(void)
{
    unsigned short theme_mode = user_settings_theme_mode;

    if (theme_mode > THEME_MODE_MAX)
        theme_mode = THEME_MODE_MAX;
    SetThemeMode(theme_mode);
}
