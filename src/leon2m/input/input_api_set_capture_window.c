/* input_api_set_capture_window  (FUN_a0149b8c)
 *
 * Hand a capture window (eight 16-bit values) to a channel.
 * Name basis: derived - copies the record and calls the routine that stores the input capture window
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149b8c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the 16-byte record is copied halfword by halfword (2-byte aligned) into a local before the call.
 */
struct capture_window {
    unsigned short values[8];   /* the eight 16-bit window coordinates */
};
extern void input_store_capture_window(unsigned char ch, struct capture_window *v);

/*
 * Copy the given capture window into a local buffer and hand it to input_store_capture_window,
 * which stores it in the channel record after limiting it.
 * Called by sys_user_apply_window_channel1, sys_user_resize_window_channel2,
 * sys_user_rebuild_window_channel2, sys_user_resize_window_channel1,
 * sys_user_rebuild_window_channel1, UserSetPIPMode, and sys_user_factory_reset.
 */
void input_api_set_capture_window(unsigned char ch, const struct capture_window *window)
{
    struct capture_window copy = *window;

    input_store_capture_window(ch, &copy);
}
