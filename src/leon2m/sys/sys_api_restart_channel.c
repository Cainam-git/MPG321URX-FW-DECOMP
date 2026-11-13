/* sys_api_restart_channel  (FUN_a014a060)
 *
 * Restart a channel at level 3.
 * Name basis: descriptive - channel state reset for channels 0..3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a060 @ 0xa014a060-0xa014a0d8 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: the switch is emitted as a compare chain with case 1 tested first. The 'channel <= 3' arm comes
 * first; both calls to sys_restart_channel are tail calls (a '> 3' first arm makes gcc share one tail call). The
 * second argument of sys_restart_channel is a u8.
 */
extern void dbg_printf(const char *);
extern void sys_restart_channel(unsigned char, unsigned char);

#define CHANNEL_NONE 0xff       /* the value the remap gives to a number that is no channel */

/*
 * Restart a channel at level 3.
 *
 *   port  channel number 0..3; any other value prints "SYS remapping channel OOR" and channel 0 is used
 */
void sys_api_restart_channel(unsigned char port)
{
    unsigned char channel;

    switch (port) {
    case 1: channel = 1; break;
    case 0: channel = 0; break;
    case 2: channel = 2; break;
    case 3: channel = 3; break;
    default: channel = CHANNEL_NONE; break;
    }
    if (channel <= 3) {
        sys_restart_channel(channel, 3);
    } else {
        dbg_printf("SYS remapping channel OOR\r\n");
        sys_restart_channel(0, 3);
    }
}
