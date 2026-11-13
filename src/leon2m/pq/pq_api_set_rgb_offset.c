/* pq_api_set_rgb_offset  (FUN_a014a2a0)
 *
 * Store the offset 0..100 of the red, green or blue channel and apply it.
 * Name basis: derived - three stSysConfig bytes; value scaled to (v * 2 + 28) and passed to the colour matrix
 *   parameters
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a2a0 @ 0xa014a2a0-0xa014a388 (232 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the scaling expression written out in every case, the sum cast to unsigned int
 * before the division; the setters are tail calls.
 */
extern unsigned char sys_config_red_offset, sys_config_green_offset, sys_config_blue_offset;
extern void pq_color_matrix_set_green_offset(unsigned char);
extern void pq_color_matrix_set_blue_offset(unsigned char);
extern void pq_color_matrix_set_red_offset(unsigned char);

#define RGB_RED     0
#define RGB_GREEN   1
#define RGB_BLUE    2
#define OFFSET_BASE 0x1c        /* matrix offset of setting 0; each step adds 2 */

/*
 * Store the offset setting of one colour in sys_config (bytes +0xF..+0x11) and write it to the colour matrix
 * as the offset of that colour's row, (offset * 200 + 50) / 100 + OFFSET_BASE.
 *
 *   color   RGB_RED, RGB_GREEN or RGB_BLUE; any other value does nothing
 *   offset  the setting 0..100 (the callers limit it to 100)
 *
 * Callers: pq_user_apply_red_offset, pq_user_apply_green_offset and pq_user_apply_blue_offset.
 */
void pq_api_set_rgb_offset(unsigned char color, unsigned char offset)
{
    switch (color) {
    case RGB_RED:
        sys_config_red_offset = offset;
        pq_color_matrix_set_red_offset((unsigned int)(offset * 200 + 50) / 100 + OFFSET_BASE);
        break;
    case RGB_GREEN:
        sys_config_green_offset = offset;
        pq_color_matrix_set_green_offset((unsigned int)(offset * 200 + 50) / 100 + OFFSET_BASE);
        break;
    case RGB_BLUE:
        sys_config_blue_offset = offset;
        pq_color_matrix_set_blue_offset((unsigned int)(offset * 200 + 50) / 100 + OFFSET_BASE);
        break;
    }
}
