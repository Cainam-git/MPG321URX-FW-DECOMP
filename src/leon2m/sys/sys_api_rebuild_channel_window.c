/* sys_api_rebuild_channel_window  (FUN_a0149e8c)
 *
 * Restart a channel and set up its output window again, with its source briefly off.
 * Name basis: derived - channel restart, source enable off, two window set-up calls, 100-tick wait, source
 *   enable on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149e8c @ 0xa0149e8c, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the channel number goes through a switch that maps 0..3 to
 * themselves and everything else to 0xff, and is then tested against 3.
 */
extern int dbg_printf();
extern int sys_frc_set_source_class_enable();
extern int sys_restart_channel();
extern int sys_get_channel_source_class(unsigned int);
extern int sys_set_channel_window_size();
extern int sys_setup_channel_window();
extern int timer_sleep_ticks();

/*
 * Bring one picture channel's output window up again after its window has been changed.
 *
 *   channel   0..3. Any other value prints "SYS remapping channel OOR" and channel 0 is used.
 *
 * The channel is first set back to state 3 (sys_restart_channel(channel, 3)). Then the enable bit of the
 * channel's source class is cleared, the window size is computed and programmed, the window is set up, and
 * after 100 timer ticks the source class is enabled again. So the source stays off while the window is
 * rebuilt.
 *
 * Called with channel 1 or 2 by the two routines that recompute a channel's display window and capture window
 * (sys_user_rebuild_window_channel1, sys_user_rebuild_window_channel2) and with channel 1 from sys_user_factory_reset.
 */
void sys_api_rebuild_channel_window(unsigned char channel)
{
    unsigned char checked;

    /* Reject anything outside 0..3. */
    switch (channel) {
    case 1:
        checked = 1;
        break;
    case 2:
        checked = 2;
        break;
    case 3:
        checked = 3;
        break;
    case 0:
        checked = 0;
        break;
    default:
        checked = 0xff;
        break;
    }

    checked = checked & 0xff;
    if (checked > 3) {
        dbg_printf("SYS remapping channel OOR\r\n");
        checked = 0;
    }

    sys_restart_channel(checked, 3);
    /* Source class off while the window is rebuilt, on again after the wait. */
    sys_frc_set_source_class_enable(sys_get_channel_source_class(checked) & 0xff, 0);
    sys_set_channel_window_size(checked);
    sys_setup_channel_window(checked);
    timer_sleep_ticks(100);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(checked) & 0xff, 1);
}
