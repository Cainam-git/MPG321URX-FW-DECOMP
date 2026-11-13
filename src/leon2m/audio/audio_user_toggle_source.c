/* audio_user_toggle_source  (FUN_a00d93c8)
 *
 * Toggle which picture's sound is played and route it.
 * Name basis: derived - bit 14 of the settings word at +0xA8, byte +0x3E; then the unit request
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d93c8 @ 0xa00d93c8, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - each arm of the toggle makes its own mute and routing calls;
 *  - the unmute test is two else-if arms that each read the sound-source bit again;
 *  - the limited audio level is held in an unsigned short (an unsigned char local drops the final and 0xff).
 */

/* The part of the user settings record (user_settings) used here. */
struct user_settings_record {
    unsigned char pad0[0x10];
    unsigned char audio_level;                  /* +0x10: at most 100 */
    unsigned char pad11[0x1e - 0x11];
    unsigned char input_source;                 /* +0x1E: source of the main picture */
    unsigned char pad1f;
    unsigned char second_source;                /* +0x20: source of the second picture */
    unsigned char pad21[0x3e - 0x21];
    unsigned char byte_0x3e;                    /* +0x3E: value looked up for the source that gets the sound */
    unsigned char pad3f[0xa8 - 0x3f];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned int settings_page_flags;           /* +0xAC */
};

/* gaming_flags: set = the sound of the second picture (channel 1) is played, clear = the main picture's (channel 0). */
#define SOUND_FROM_SECOND_PICTURE 0x4000        /* bit 14 */
/* settings_page_flags: bit 17 is reported to the PC tool. */
#define SETTINGS_REPORTED_TO_PC   0x20000
/* Code returned by sys_api_get_channel_state_code after which the sound is unmuted. */
#define CHANNEL_STATE_UNMUTE      10
#define AUDIO_LEVEL_MAX           100

extern struct user_settings_record user_settings;
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_lookup_source_value(unsigned char);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern void audio_api_set_mute(unsigned char);
extern void audio_user_update_routing(void);
extern void audio_api_set_level_percent(unsigned char);

/*
 * Move the sound to the other picture: the sound-source bit is flipped and the sound is routed again.
 * Called from the OK actions of Audio Switch in the PIP and PBP lists.
 *
 * Order:
 *  1. Set the reported-to-PC bit of settings_page_flags.
 *  2. Look up byte_0x3e for the source of the picture that gets the sound (input_source when the second picture
 *     had it, second_source otherwise), flip the bit, mute, and route (audio_user_update_routing).
 *  3. Unmute again when the channel that now has the sound reports state code 10.
 *  4. Send the audio level, limited to 100, to the audio output.
 */
void audio_user_toggle_source(void)
{
    unsigned short level;

    user_settings.settings_page_flags |= SETTINGS_REPORTED_TO_PC;
    if (user_settings.gaming_flags & SOUND_FROM_SECOND_PICTURE) {
        /* The sound goes back to the main picture. */
        user_settings.byte_0x3e = input_api_lookup_source_value(input_api_source_id_to_menu_index(user_settings.input_source) + 1);
        user_settings.gaming_flags &= ~SOUND_FROM_SECOND_PICTURE;
        audio_api_set_mute(1);
        audio_user_update_routing();
    } else {
        /* The sound goes to the second picture. */
        user_settings.byte_0x3e = input_api_lookup_source_value(input_api_source_id_to_menu_index(user_settings.second_source) + 1);
        user_settings.gaming_flags |= SOUND_FROM_SECOND_PICTURE;
        audio_api_set_mute(1);
        audio_user_update_routing();
    }
    /* Unmute when the picture that now has the sound is in state 10. */
    if (!(user_settings.gaming_flags & SOUND_FROM_SECOND_PICTURE) && sys_api_get_channel_state_code(0) == CHANNEL_STATE_UNMUTE)
        audio_api_set_mute(0);
    else if ((user_settings.gaming_flags & SOUND_FROM_SECOND_PICTURE) && sys_api_get_channel_state_code(1) == CHANNEL_STATE_UNMUTE)
        audio_api_set_mute(0);
    level = user_settings.audio_level;
    if (level > AUDIO_LEVEL_MAX)
        level = AUDIO_LEVEL_MAX;
    audio_api_set_level_percent(level);
}
