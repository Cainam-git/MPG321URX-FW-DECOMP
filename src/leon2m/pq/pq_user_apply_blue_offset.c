/* pq_user_apply_blue_offset  (FUN_a00d46f8)
 *
 * Limit the blue offset to 100 and apply it.
 * Name basis: derived - settings byte +0x17; pq_api_set_rgb_offset(2, v)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d46f8 @ 0xa00d46f8, flags -mcpu=v8 -Os -g.
 */

#define RGB_BLUE         2
#define BLACK_LEVEL_MAX  100

/* The one field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x17];
    unsigned char blue_black_level;             /* +0x17: blue black level (DDC/CI VCP 0x70) */
};
extern struct user_settings_record user_settings;
extern int pq_api_set_rgb_offset(int color, int offset);

/*
 * Limit the blue black level setting to 100, store the limited value back and write it as the blue offset
 * of the colour matrix (pq_api_set_rgb_offset). The DDC/CI request handlers (ddc_handle_request,
 * ddc_apply_maker_vcp_set) call it after storing a new blue black level.
 */
void pq_user_apply_blue_offset(void)
{
    unsigned char level = user_settings.blue_black_level;
    if (level > BLACK_LEVEL_MAX)
        level = BLACK_LEVEL_MAX;
    user_settings.blue_black_level = level;
    pq_api_set_rgb_offset(RGB_BLUE, level);
}
