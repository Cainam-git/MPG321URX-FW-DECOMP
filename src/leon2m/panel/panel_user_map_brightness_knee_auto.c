/* panel_user_map_brightness_knee_auto  (FUN_a00d3f80)
 *
 * Map a brightness setting through the two-segment line with the knee 272 or 879.
 * Returns: percent
 * Name basis: descriptive - knee chosen by settings flags; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d3f80 @ 0xa00d3f80-0xa00d4084 (260 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two static conversion routines with the knee written in (map_knee_879 is the body of
 * panel_user_map_brightness_knee_879), each inlined.
 */

#define GAMING_FLAG_PRO_MODE 0x800          /* bit 11 of settings word +0xA8: 1 = Professional modes, 0 = Game modes */
#define PRO_MODE_7           7

/* Panel brightness levels run from LEVEL_MIN to LEVEL_MAX. */
#define LEVEL_MIN    126
#define LEVEL_MAX    0x3ff                  /* 1023 */
#define LEVEL_RANGE  897                    /* LEVEL_MAX - LEVEL_MIN */
#define KNEE_SETTING 70                     /* the brightness setting (0..100) at which the line bends */

/* The two fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0xa8];
    unsigned int gaming_flags;              /* +0xA8: switch word of the Gaming menu */
    unsigned char padac[0x181 - 0xac];
    unsigned char pro_mode;                 /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;

/* Brightness 0..100 to a percentage of the level range, bend at level 879. */
static unsigned char map_knee_879(unsigned char brightness)
{
    unsigned short level;
    if (brightness > KNEE_SETTING - 1)
        level = (unsigned int)((brightness - KNEE_SETTING) * (LEVEL_MAX - 879) + 15) / 30 + 879;
    else
        level = (unsigned int)(brightness * (879 - LEVEL_MIN) + 35) / KNEE_SETTING + LEVEL_MIN;
    return (level - LEVEL_MIN) * 100 / LEVEL_RANGE;
}
/* The same with the bend at level 272. */
static unsigned char map_knee_272(unsigned char brightness)
{
    unsigned short level;
    if (brightness > KNEE_SETTING - 1)
        level = (unsigned int)((brightness - KNEE_SETTING) * (LEVEL_MAX - 272) + 15) / 30 + 272;
    else
        level = (unsigned int)(brightness * (272 - LEVEL_MIN) + 35) / KNEE_SETTING + LEVEL_MIN;
    return (level - LEVEL_MIN) * 100 / LEVEL_RANGE;
}

/*
 * Turn a brightness setting (0..100) into a percentage of the panel's level range (126..1023), with the bend of
 * the line at setting 70 placed at level 272 in Professional mode 7 and at level 879 in every other mode.
 *
 * Nothing in the image calls this copy; sys_user_apply_brightness contains the same conversion built in and uses
 * it whenever the stored-knee line (panel_user_map_brightness_knee) does not apply.
 */
unsigned char panel_user_map_brightness_knee_auto(unsigned char brightness)
{
    if ((user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) && user_settings.pro_mode == PRO_MODE_7)
        return map_knee_272(brightness);
    return map_knee_879(brightness);
}
