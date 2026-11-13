/* panel_user_map_brightness_knee  (FUN_a00d3e28)
 *
 * Map a brightness setting through a two-segment line with a stored knee.
 * Returns: percent
 * Name basis: descriptive - knee at 0xA802D46A; (v - 126) * 100 / 897; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d3e28 @ 0xa00d3e28-0xa00d3ee0 (184 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: both segment formulas are cast to unsigned int before the division (unsigned divisions); the level
 * is an unsigned short and the final percentage is computed signed.
 */
extern unsigned short user_settings_brightness_knee;

/* Panel brightness levels run from LEVEL_MIN to LEVEL_MAX. */
#define LEVEL_MIN    126
#define LEVEL_MAX    0x3ff                  /* 1023 */
#define LEVEL_RANGE  897                    /* LEVEL_MAX - LEVEL_MIN */
#define KNEE_SETTING 70                     /* the brightness setting (0..100) at which the line bends */

/*
 * Turn a brightness setting (0..100) into a percentage of the panel's level range, through a line with a bend.
 *
 *   brightness  the menu's Brightness value, 0..100
 *
 * Settings 0..70 run from level 126 up to the knee level (settings halfword +0x1DA), settings 70..100 from the knee
 * level up to 1023, both with rounding. The level found is then given as a percentage of the range 126..1023.
 *
 * Nothing in the image calls this copy; sys_user_apply_brightness contains the same conversion built in, which
 * it uses in Professional mode 7 when bit 6 of settings word +0x1D4 is set.
 */
unsigned char panel_user_map_brightness_knee(unsigned char brightness)
{
    unsigned short level;

    if (brightness > KNEE_SETTING - 1)
        level = (unsigned int)((brightness - KNEE_SETTING) * (LEVEL_MAX - user_settings_brightness_knee) + 15) / 30
                + user_settings_brightness_knee;
    else
        level = (unsigned int)(brightness * (user_settings_brightness_knee - LEVEL_MIN) + 35) / KNEE_SETTING
                + LEVEL_MIN;
    return (level - LEVEL_MIN) * 100 / LEVEL_RANGE;
}
