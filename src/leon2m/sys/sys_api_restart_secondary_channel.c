/* sys_api_restart_secondary_channel  (FUN_a014b900)
 *
 * Restart channel 2 or 3 when its enable value is 1.
 * Name basis: descriptive - tests stSysConfig bytes +0x2A/+0x2C, then the channel state reset
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b900 @ 0xa014b900 (-mcpu=v8 -O3 -g).
 * Source form: nested ifs rather than early returns, which the branch layout of the exact build depends on.
 */
extern unsigned char sys_config_channel2_enable;
extern unsigned char sys_config_channel3_enable;
extern int sys_restart_channel();

/*
 * Restart channel 2 or channel 3 at level 0 when its enable byte in the system configuration record is 1.
 *
 *   which  0 for channel 2 (byte +0x2A), 1 for channel 3 (byte +0x2C); other values do nothing
 */
void sys_api_restart_secondary_channel(unsigned char which)
{
    if (which == 0) {
        if (sys_config_channel2_enable == 1) {
            sys_restart_channel(2, 0);
        }
    } else if (which == 1) {
        if (sys_config_channel3_enable == 1) {
            sys_restart_channel(3, 0);
        }
    }
}
