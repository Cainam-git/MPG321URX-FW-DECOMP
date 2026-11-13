/* sys_user_apply_window_channel1  (FUN_a00d79b0)
 *
 * Compute the window of channel 1, hand it over and restart the channel.
 * Name basis: derived - APP_ConfigDispSize(1), input_api_set_capture_window, sys_api_restart_channel; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d79b0 @ 0xa00d79b0-0xa00d79f0 (16 words), flags -mcpu=v8 -O2 -g.
 * Source form: the window is a pair of 64-bit values filled by APP_ConfigDispSize and copied as a whole into a
 * second local before it is passed on. The two parameters are declared and not used; nothing is returned.
 */
extern void APP_ConfigDispSize(int channel, void *window);
extern void input_api_set_capture_window(int channel, void *window);
extern void sys_api_restart_channel(unsigned char channel);

/*
 * Compute the display window of channel 1 (APP_ConfigDispSize), hand it to the channel as its capture window
 * and restart the channel (sys_api_restart_channel). The window is 16 bytes (eight halfwords).
 */
void sys_user_apply_window_channel1(int unused_1, int unused_2)
{
    unsigned long long window[2];
    unsigned long long window_copy[2];

    APP_ConfigDispSize(1, window);
    window_copy[0] = window[0];
    window_copy[1] = window[1];
    input_api_set_capture_window(1, window_copy);
    sys_api_restart_channel(1);
}
