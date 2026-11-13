/* sys_api_stop_channel  (FUN_a0149fb8)
 *
 * Restart a channel at level 2 and switch its source enable off.
 * Name basis: descriptive - channel state reset, then the source enable bit cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149fb8 @ 0xa0149fb8-0xa014a060 (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: the channel remap is a static helper with a switch (same form as in sys_api_get_channel_flag29).
 */
extern int dbg_printf();
extern void sys_restart_channel(unsigned char, int);
extern unsigned char sys_get_channel_source_class(unsigned char);
extern void sys_frc_set_source_class_enable(unsigned char, int);

/* Channel number 0..3 as it is, anything else -1. */
static int remap_channel(int channel)
{
    switch (channel) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Restart a channel at level 2 and then switch off the frame-rate converter enable bit of the source class
 * of that channel.
 *
 *   channel  channel number 0..3; any other value prints "SYS remapping channel OOR" and channel 0 is used
 */
void sys_api_stop_channel(unsigned char channel)
{
    unsigned char i = remap_channel(channel);

    if (i > 3) {
        dbg_printf("SYS remapping channel OOR\r\n");
        i = 0;
    }
    sys_restart_channel(i, 2);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(i), 0);
}
