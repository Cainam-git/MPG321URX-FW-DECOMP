/* sys_user_rebuild_window_channel1  (FUN_a00d7b20)
 *
 * Compute the window of channel 1, hand it over and rebuild it.
 * Name basis: derived - APP_ConfigDispSize(1), input_api_set_capture_window, sys_api_rebuild_channel_window
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d7b20 @ 0xa00d7b20-0xa00d7b60 (16 words), flags -mcpu=v8 -O2 -g.
 * Source form: the window is a pair of 64-bit values filled by APP_ConfigDispSize and copied as a whole into a
 * second local before it is passed on. The two parameters are declared and not used; nothing is returned.
 */
extern void APP_ConfigDispSize(int channel, void *window);
extern void input_api_set_capture_window(int channel, void *window);
extern void sys_api_rebuild_channel_window(unsigned char channel);

/* Compute the display window of channel 1, hand it over as its capture window and rebuild the channel's window. */
void sys_user_rebuild_window_channel1(int unused_1, int unused_2)
{
    unsigned long long window[2];
    unsigned long long window_copy[2];

    APP_ConfigDispSize(1, window);
    window_copy[0] = window[0];
    window_copy[1] = window[1];
    input_api_set_capture_window(1, window_copy);
    sys_api_rebuild_channel_window(1);
}
