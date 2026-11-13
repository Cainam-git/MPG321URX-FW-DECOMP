/* pq_user_apply_mode_colors  (FUN_a00d4560)
 *
 * Re-apply the first six colour values of the picture modes.
 * Name basis: derived - pq_api_set_mode_color_value(n, stored value, apply) for n = 0..5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4560 @ 0xa00d4560-0xa00d45f8 (38 words).
 * Source form: the six calls are written out explicitly.
 */
extern unsigned char pq_api_get_mode_color_value(unsigned char);
extern void pq_api_set_mode_color_value(unsigned char, unsigned char, unsigned char);

/*
 * Re-apply the first six colour values of the picture modes.
 * Called by App_Initialize during initialization.
 */
void pq_user_apply_mode_colors(void)
{
    pq_api_set_mode_color_value(0, pq_api_get_mode_color_value(0), 1);
    pq_api_set_mode_color_value(1, pq_api_get_mode_color_value(1), 1);
    pq_api_set_mode_color_value(2, pq_api_get_mode_color_value(2), 1);
    pq_api_set_mode_color_value(3, pq_api_get_mode_color_value(3), 1);
    pq_api_set_mode_color_value(4, pq_api_get_mode_color_value(4), 1);
    pq_api_set_mode_color_value(5, pq_api_get_mode_color_value(5), 1);
}
