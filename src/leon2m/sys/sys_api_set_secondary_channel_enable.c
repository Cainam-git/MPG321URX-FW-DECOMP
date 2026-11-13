/* sys_api_set_secondary_channel_enable  (FUN_a014b844)
 *
 * Store the enable value of channel 2 or 3 and restart that channel.
 * Name basis: descriptive - stSysConfig bytes +0x2A/+0x2C; channel record bit, state reset, then two follow-up
 *   calls
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b844, flags -mcpu=v8 -O3 -g.
 * Source form: the `enable == 1` argument is written as an if/else of two calls (the firmware sets both argument
 * registers in each branch); the route call reads the stored byte back from sys_config instead of using
 * `enable`.
 */
extern unsigned char sys_config[];
extern void sys_set_channel_flag17(unsigned char ch, unsigned char on);
extern void sys_restart_channel(unsigned char ch, unsigned char mode);
extern void sys_api_set_block_route_first(unsigned char v);
extern void sys_api_set_block_route_second(unsigned char v);
extern void sys_apply_pip_layout_and_windows(void);

/* Byte offsets in the system configuration record (sys_config). */
#define SYS_CONFIG_CHANNEL2_ENABLE 0x2a     /* enable value of channel 2 */
#define SYS_CONFIG_CHANNEL3_ENABLE 0x2c     /* enable value of channel 3 */

/* Picture channels 2 and 3: the third and fourth picture. */
#define CHANNEL_2 2
#define CHANNEL_3 3

/*
 * Set the enable value of picture channel 2 or 3 and bring that channel up again.
 *
 *   which   0: channel 2, 1: channel 3; any other value only re-applies the layout
 *   enable  the value stored in the system configuration; 1 also sets flag bit 17 of the channel record, every
 *           other value clears it. The value also picks the route of the block that belongs to the channel
 *           (0, 1, 2 or 4; see sys_api_set_block_route_first/second).
 *
 * Called with the user setting by sys_user_apply_channel2_enable and sys_user_apply_channel3_enable.
 */
void sys_api_set_secondary_channel_enable(unsigned char which, unsigned char enable)
{
    if (which == 0) {
        sys_config[SYS_CONFIG_CHANNEL2_ENABLE] = enable;
        if (enable == 1)
            sys_set_channel_flag17(CHANNEL_2, 1);
        else
            sys_set_channel_flag17(CHANNEL_2, 0);
        sys_restart_channel(CHANNEL_2, 0);
        sys_api_set_block_route_first(sys_config[SYS_CONFIG_CHANNEL2_ENABLE]);
    } else if (which == 1) {
        sys_config[SYS_CONFIG_CHANNEL3_ENABLE] = enable;
        if (enable == 1)
            sys_set_channel_flag17(CHANNEL_3, 1);
        else
            sys_set_channel_flag17(CHANNEL_3, 0);
        sys_restart_channel(CHANNEL_3, 0);
        sys_api_set_block_route_second(sys_config[SYS_CONFIG_CHANNEL3_ENABLE]);
    }
    /* The window layout of all four channels is set up again in every case. */
    sys_apply_pip_layout_and_windows();
}
