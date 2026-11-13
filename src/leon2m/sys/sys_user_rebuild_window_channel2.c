/* sys_user_rebuild_window_channel2  (FUN_a00d7a30)
 *
 * Compute the window of channel 2, hand it over and rebuild it.
 * Name basis: derived - APP_ConfigDispSize(2), input_api_set_capture_window, sys_api_rebuild_channel_window;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d7a30 @ 0xa00d7a30-0xa00d7a70 (16 words), flags -mcpu=v8 -O2 -g.
 * Source form: the window is a 16-byte, 8-aligned record; it is copied as a whole (two ldd/std pairs) into a
 * second record before it is passed on. Twin of sys_user_resize_window_channel2.
 */
/* A window as filled by APP_ConfigDispSize: 16 bytes (eight halfwords). */
struct window_record { unsigned long long q0, q1; };
extern void APP_ConfigDispSize(int channel, void *window);
extern void input_api_set_capture_window(int channel, void *window);
extern void sys_api_rebuild_channel_window(unsigned char channel);

/* Compute the display window of channel 2, hand it over as its capture window and rebuild the channel's window. */
void sys_user_rebuild_window_channel2(void)
{
    struct window_record window;
    struct window_record window_copy;

    APP_ConfigDispSize(2, &window);
    window_copy = window;
    input_api_set_capture_window(2, &window_copy);
    sys_api_rebuild_channel_window(2);
}
