/* panel_user_rescale_brightness  (FUN_a00d3dbc)
 *
 * Rescale a brightness value around its base 0x7E under two setting flags.
 * Name basis: descriptive - (v - 0x7E) * 0x381 / 0x381 + 0x7E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d3dbc @ 0xa00d3dbc-0xa00d3e28 (108 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the difference is cast to unsigned int before the multiplication, so the scaling is unsigned.
 */

#define GAMING_FLAG_PRO_MODE 0x800      /* bit 11 of settings word +0xA8: 1 = Professional modes, 0 = Game modes */
#define PRO_MODE_7           7

/* Panel brightness levels run from LEVEL_MIN to LEVEL_MAX; LEVEL_RANGE = LEVEL_MAX - LEVEL_MIN. */
#define LEVEL_MIN            0x7e       /* 126 */
#define LEVEL_RANGE          0x381      /* 897 */

/* The two fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0xa8];
    unsigned int gaming_flags;          /* +0xA8: switch word of the Gaming menu */
    unsigned char padac[0x181 - 0xac];
    unsigned char pro_mode;             /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;

/*
 * Rescale a panel brightness level in place, in Professional mode 7 only.
 *
 *   level  the level to rescale (126..1023)
 *
 * The level is mapped from the range 126..1023 onto the same range (scale 897 / 897), so a level of 126 or more
 * comes back unchanged; only a level below 126 changes, because the unsigned difference wraps.
 * Called by pq_adjust_value_mode7, which is registered as callback 14 (sys_register_callback) and makes the same
 * mode test before the call.
 */
void panel_user_rescale_brightness(unsigned short *level)
{
    if ((user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) && user_settings.pro_mode == PRO_MODE_7)
        *level = (unsigned int)(*level - LEVEL_MIN) * LEVEL_RANGE / LEVEL_RANGE + LEVEL_MIN;
}
