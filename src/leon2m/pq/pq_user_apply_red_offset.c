/* pq_user_apply_red_offset  (FUN_a00d4690)
 *
 * Limit the red offset to 100 and apply it.
 * Name basis: derived - settings byte +0x15; pq_api_set_rgb_offset(0, v)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4690 @ 0xa00d4690 (-mcpu=v8 -Os -g)
 * Source form: the original if statement and assignment are kept.
 */
extern unsigned char user_settings[]; /* 0xa802d290 */
extern int pq_api_set_rgb_offset(int, int);   /* 0xa014a2a0 */

#define RED_OFFSET_INDEX 0x15   /* offset of red offset in user_settings */
#define RED_OFFSET_MAX 100      /* maximum allowed red offset */
#define RED_CHANNEL 0           /* channel index for red in pq_api_set_rgb_offset */

/*
 * Limit the red offset to 100 and apply it.
 * Reads the red offset from user_settings, clamps it to 100, writes it back,
 * and passes it to pq_api_set_rgb_offset for the red channel.
 */
void pq_user_apply_red_offset(void)
{
    unsigned char red_offset = user_settings[RED_OFFSET_INDEX];
    if (red_offset > RED_OFFSET_MAX)
        red_offset = RED_OFFSET_MAX;
    user_settings[RED_OFFSET_INDEX] = red_offset;
    pq_api_set_rgb_offset(RED_CHANNEL, red_offset);
}
