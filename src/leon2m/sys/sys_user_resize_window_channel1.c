/* sys_user_resize_window_channel1  (FUN_a00d7a70)
 *
 * Compute the window of channel 1 and update it, with its source briefly off when asked.
 * Name basis: derived - used by the PIP size and position editors
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d7a70 @ 0xa00d7a70-0xa00d7b20 (44 words), flags -mcpu=v8 -O2 -g.
 * Source form: the window is a 16-byte, 8-aligned record copied as a whole into a second record before it is
 * passed on. Same record form as sys_user_rebuild_window_channel2.
 */
/* A window as filled by APP_ConfigDispSize: 16 bytes (eight halfwords). */
struct window_record { unsigned long long q0, q1; };
extern void APP_ConfigDispSize(int channel, void *window);
extern void input_api_set_capture_window(int channel, void *window);
extern void sys_api_update_channel_window_size(unsigned char channel);
extern void sys_api_set_channel_source_enable(unsigned char channel, unsigned char enable);
extern void timer_api_sleep_ticks(unsigned short ticks);

/*
 * Compute the display window of channel 1, hand it over as its capture window and recompute the window size.
 * When source_off is not 0, the source of channel 1 is switched off before the window is handed over and on
 * again after a wait of 0x32 ticks.
 */
void sys_user_resize_window_channel1(unsigned char source_off)
{
    struct window_record window;
    struct window_record window_copy;

    APP_ConfigDispSize(1, &window);
    if (source_off)
        sys_api_set_channel_source_enable(1, 0);
    window_copy = window;
    input_api_set_capture_window(1, &window_copy);
    sys_api_update_channel_window_size(1);
    if (source_off) {
        timer_api_sleep_ticks(0x32);
        sys_api_set_channel_source_enable(1, 1);
    }
}
