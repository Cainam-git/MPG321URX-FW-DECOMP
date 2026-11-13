/* panel_user_map_brightness_knee_879  (FUN_a00d3ee0)
 *
 * Map a brightness setting through the two-segment line with the knee 879.
 * Returns: percent
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d3ee0 @ 0xa00d3ee0-0xa00d3f80 (160 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the panel_user_map_brightness_knee expressions with the knee 879 written in (the compiler folds
 * them to brightness * 144 - 10065 and brightness * 753 + 35).
 */

/* Panel brightness levels run from LEVEL_MIN to LEVEL_MAX. */
#define LEVEL_MIN    126
#define LEVEL_MAX    0x3ff                  /* 1023 */
#define LEVEL_RANGE  897                    /* LEVEL_MAX - LEVEL_MIN */
#define KNEE_SETTING 70                     /* the brightness setting (0..100) at which the line bends */
#define KNEE_LEVEL   879                    /* the level at the bend */

/*
 * The conversion of panel_user_map_brightness_knee with the knee level fixed at 879: brightness 0..100 to a
 * percentage of the level range 126..1023.
 *
 * Nothing in the image calls this copy; the same conversion is built into panel_user_map_brightness_knee_auto
 * and sys_user_apply_brightness.
 */
unsigned char panel_user_map_brightness_knee_879(unsigned char brightness)
{
    unsigned short level;

    if (brightness > KNEE_SETTING - 1)
        level = (unsigned int)((brightness - KNEE_SETTING) * (LEVEL_MAX - KNEE_LEVEL) + 15) / 30 + KNEE_LEVEL;
    else
        level = (unsigned int)(brightness * (KNEE_LEVEL - LEVEL_MIN) + 35) / KNEE_SETTING + LEVEL_MIN;
    return (level - LEVEL_MIN) * 100 / LEVEL_RANGE;
}
