/* sys_user_apply_second_picture_enable  (FUN_a00d5eac)
 *
 * Switch the second picture's source and port on or off as the settings say.
 * Name basis: derived - source enable and port enable for channel 1; stops the channel when the stop argument
 *   is not 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5eac @ 0xa00d5eac-0xa00d5f3c (36 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is an unsigned char array indexed with the offsets below.
 */
extern unsigned char user_settings[];
extern void sys_api_set_channel_source_enable(unsigned char channel, unsigned char enable);
extern void sys_api_enable_channel_port(unsigned char channel, unsigned char enable);
extern void sys_api_stop_channel(unsigned char channel);

#define SETTINGS_PIP_PBP_MODE 0x1f      /* PIP/PBP mode: 0 = off */
#define SETTINGS_BYTE_0x4A    0x4a      /* non-zero: the second picture is switched on */

/*
 * Does nothing when the PIP/PBP mode setting is not 0. Otherwise it switches the source and the port of
 * channel 1 on when settings byte +0x4A is not 0 (port first, then source), or off when it is 0 (source
 * first, then port). When stop is not 0 it then switches the source of channel 1 off again and stops the
 * channel.
 */
void sys_user_apply_second_picture_enable(unsigned char stop)
{
    if (user_settings[SETTINGS_PIP_PBP_MODE] != 0)
        return;
    if (user_settings[SETTINGS_BYTE_0x4A] != 0) {
        sys_api_enable_channel_port(1, 1);
        sys_api_set_channel_source_enable(1, 1);
    } else {
        sys_api_set_channel_source_enable(1, 0);
        sys_api_enable_channel_port(1, 0);
    }
    if (stop) {
        sys_api_set_channel_source_enable(1, 0);
        sys_api_stop_channel(1);
    }
}
