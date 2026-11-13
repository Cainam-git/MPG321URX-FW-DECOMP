/* sys_api_restart_channel_at_level  (FUN_a0148268)
 *
 * Restart a channel at the given level 0..3.
 * Name basis: derived - channel state reset; prints 'SYS remapping channel OOR' for channels above 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148268 @ 0xa0148268-0xa0148350 (232 bytes), -mcpu=v8 -O3 -g.
 * Source form: remap is an inlined static helper returning int (its return value is copied into the
 * int local, as in pq_api_load_level_table); the four mode tests are separate if statements, so the calls for
 * modes 0..2 are plain calls and only the mode 3 call is a sibling call.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_restart_channel(unsigned char ch, unsigned char mode);

/* Return ch for 0..3, else -1. */
static int remap(unsigned char ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Call sys_restart_channel for channel ch with the given mode, for modes 0, 1, 2 and 3; any other mode
 * calls nothing. A channel above 3 prints "SYS remapping channel OOR" and is treated as channel 0. */
void sys_api_restart_channel_at_level(unsigned char ch, unsigned char mode)
{
    int channel = remap(ch);

    if ((unsigned char)channel > 3) {
        dbg_printf("SYS remapping channel OOR\r\n");
        channel = 0;
    }
    if (mode == 0)
        sys_restart_channel(channel, 0);
    if (mode == 1)
        sys_restart_channel(channel, 1);
    if (mode == 2)
        sys_restart_channel(channel, 2);
    if (mode == 3)
        sys_restart_channel(channel, 3);
}
