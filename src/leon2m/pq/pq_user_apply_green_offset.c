/* pq_user_apply_green_offset  (FUN_a00d46c4)
 *
 * Limit the green offset to 100 and apply it.
 * Name basis: derived - settings byte +0x16; pq_api_set_rgb_offset(1, v)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d46c4 @ 0xa00d46c4, flags -mcpu=v8 -Os -g.
 */

#define RGB_GREEN        1
#define BLACK_LEVEL_MAX  100

/* The one field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x16];
    unsigned char green_black_level;            /* +0x16: green black level (DDC/CI VCP 0x6E) */
};
extern struct user_settings_record user_settings;
extern int pq_api_set_rgb_offset(int color, int offset);

/*
 * Limit the green black level setting to 100, store the limited value back and write it as the green offset
 * of the colour matrix (pq_api_set_rgb_offset). The DDC/CI request handlers (ddc_handle_request,
 * ddc_apply_maker_vcp_set) call it after storing a new green black level.
 */
void pq_user_apply_green_offset(void)
{
    unsigned char level = user_settings.green_black_level;
    if (level > BLACK_LEVEL_MAX)
        level = BLACK_LEVEL_MAX;
    user_settings.green_black_level = level;
    pq_api_set_rgb_offset(RGB_GREEN, level);
}
