/* sys_user_apply_pip_sources  (FUN_a00d5938)
 *
 * Select the source of extra picture 1, 2 or 3 from settings bytes +0x20 to +0x22.
 * Name basis: derived - sys_api_select_channel_source for channels 1..3 with settings bytes +0x20..+0x22
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5938 @ 0xa00d5938-0xa00d59d4 (39 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is declared with the bytes and the word this routine uses; the switch has
 * one case per port 1, 2, 3 and no default.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x20];
    unsigned char second_source;           /* +0x20: source of the second picture (channel 1) */
    unsigned char byte_0x21;               /* +0x21: source passed for channel 2 */
    unsigned char byte_0x22;               /* +0x22: source passed for channel 3 */
    unsigned char pad23[0xa8 - 0x23];
    unsigned int gaming_flags;             /* +0xA8 */
};
extern struct user_settings_record user_settings;
extern void audio_api_set_mute(unsigned char);
extern void sys_api_select_channel_source(unsigned char channel, unsigned char source);

#define GAMING_FLAG_BIT14 0x4000

/*
 * Select the source of one of the extra pictures from the settings. port is 1, 2 or 3 and is also the
 * channel number; any other value selects nothing. When bit 14 of gaming_flags is set, audio_api_set_mute(1)
 * is called first.
 */
void sys_user_apply_pip_sources(unsigned char port)
{
    if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
        audio_api_set_mute(1);
    switch (port) {
    case 1:
        sys_api_select_channel_source(1, user_settings.second_source);
        break;
    case 2:
        sys_api_select_channel_source(2, user_settings.byte_0x21);
        break;
    case 3:
        sys_api_select_channel_source(3, user_settings.byte_0x22);
        break;
    }
}
