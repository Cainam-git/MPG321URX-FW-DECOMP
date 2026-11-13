/* sys_apply_pip_layout_and_windows  (FUN_a013129c)
 *
 * Apply the picture-in-picture layout and set up the windows of all four channels.
 * Name basis: derived - sys_apply_pip_layout, then size and window set-up per channel; called from
 *   SYSAPI_ConfigSystemPIPMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013129c @ 0xa013129c (-mcpu=v8 -O2 -g)
 * Returns void: the 'and %l1,0xff,%l0' before ret is the delay slot of the loop's ble, not a return value.
 */
extern int sys_apply_pip_layout(void);
extern int sys_set_channel_window_size(int);
extern int sys_setup_channel_window(int);

#define CHANNEL_COUNT 4

/*
 * Apply the picture-in-picture layout (sys_apply_pip_layout), then for each of the four channels set the
 * window size and set up the window.
 */
void sys_apply_pip_layout_and_windows(void)
{
    int ch;
    sys_apply_pip_layout();
    ch = 0;
    do {
        sys_set_channel_window_size(ch & 0xff);
        sys_setup_channel_window(ch & 0xff);
        ch++;
    } while (ch < CHANNEL_COUNT);
}
