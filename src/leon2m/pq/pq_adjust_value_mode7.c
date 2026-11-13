/* pq_adjust_value_mode7  (FUN_a0083be0)
 *
 * Rescale *p when settings bit 11 is set and mode byte +0x181 is 7.
 *   brightness_ptr: value to adjust
 * Note: No direct caller; rescaling done by panel_user_rescale_brightness.
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m pq_adjust_value_mode7 @ 0xa0083be0-0xa0083c20 (64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: single if with short-circuit &&; tail call to panel_user_rescale_brightness.
 */
#define GAMING_FLAG_PRO_MODE 0x800   /* gaming_flags bit 11: Pro (1) / Game (0) */
#define PRO_MODE_7           7       /* the Pro mode value that enables the rescale */

struct user_settings_record {
    unsigned char pad0[0xa8];
    unsigned int gaming_flags;                /* +0xA8 */
    unsigned char pad_ac[0x181 - 0xac];
    unsigned char pro_mode;                   /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;
extern void panel_user_rescale_brightness(unsigned short *p);

/*
 * Rescale the brightness value pointed to by brightness_ptr (panel_user_rescale_brightness) when the Pro flag
 * (gaming_flags bit 11) is set and the Pro mode (+0x181) is 7. No direct call to it was found in the image.
 */
void pq_adjust_value_mode7(unsigned short *brightness_ptr)
{
    if ((user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) && user_settings.pro_mode == PRO_MODE_7)
        panel_user_rescale_brightness(brightness_ptr);
}
