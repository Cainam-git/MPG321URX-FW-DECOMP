/* sys_api_update_channel_window_size  (FUN_a0149f44)
 *
 * Recompute the window size of a channel.
 * Name basis: descriptive - forwards to the window size routine for channels 0..3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149f44 @ 0xa0149f44-0xa0149fb8 (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: the switch is emitted as a compare chain; the arm for channel <= 3 comes first. Both calls to
 * sys_set_channel_window_size are tail calls.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_set_channel_window_size(unsigned char);

#define CHANNEL_NONE 0xff       /* the value the remap gives to a number that is no channel */

/*
 * Recompute the window size of a channel.
 *
 *   port  channel number 0..3; any other value prints "SYS remapping channel OOR" and channel 0 is used
 */
void sys_api_update_channel_window_size(unsigned char port)
{
    unsigned char channel;

    switch (port) {
    case 0: channel = 0; break;
    case 1: channel = 1; break;
    case 2: channel = 2; break;
    case 3: channel = 3; break;
    default: channel = CHANNEL_NONE; break;
    }
    if (channel <= 3) {
        sys_set_channel_window_size(channel);
        return;
    }
    dbg_printf("SYS remapping channel OOR\r\n");
    sys_set_channel_window_size(0);
}
