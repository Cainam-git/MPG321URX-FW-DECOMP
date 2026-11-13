/* audio_user_update_routing  (FUN_a00d5cd8)
 *
 * Work out the sound source for the active input and route it.
 * Name basis: derived - settings byte +0x3E from the source tables, then sys_api_request_acr_unit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5cd8 @ 0xa00d5cd8-0xa00d5d8c (45 words).
 * Source form: separate arms for pip_pbp_mode zero / non-zero, each with its own bit 17 test and calls; the
 * final audio_api_route_source call is a tail call.
 */

#define SETTINGS_REPORTED_TO_PC   0x20000   /* settings_page_flags bit 17 (as in audio_user_toggle_source) */
#define SOUND_FROM_SECOND_PICTURE 0x4000    /* gaming_flags bit 14: the sound of channel 1 is played */
#define AUDIO_ROUTE_ARGUMENT      7         /* second argument of audio_api_route_source; its meaning is not shown here */

/* The part of the user settings record (docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = one picture */
    unsigned char pad20[0x3e - 0x20];
    unsigned char byte_0x3e;                    /* +0x3E: value looked up for the source that gets the sound */
    unsigned char pad3f[0xa8 - 0x3f];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned int settings_page_flags;           /* +0xAC */
};
extern struct user_settings_record user_settings;
extern unsigned char input_api_get_channel_port_code(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_lookup_source_value(unsigned char);
extern void audio_api_route_source(unsigned char, unsigned char);

/*
 * Set byte +0x3E of the user settings and route the sound to it.
 *
 * The byte is 0 when bit 17 of settings_page_flags is clear. Otherwise it is the value that
 * input_api_lookup_source_value gives for the port code of the channel that carries the sound: channel 1 when
 * a picture-in-picture mode is on and the sound-from-second-picture bit (bit 14 of gaming_flags) is set,
 * channel 0 in every other case.
 * Called from audio_user_toggle_source and from many other places.
 */
void audio_user_update_routing(void)
{
    if (user_settings.pip_pbp_mode == 0) {
        if (user_settings.settings_page_flags & SETTINGS_REPORTED_TO_PC)
            user_settings.byte_0x3e = input_api_lookup_source_value(input_api_source_id_to_menu_index(input_api_get_channel_port_code(0)));
        else
            user_settings.byte_0x3e = 0;
    } else if (user_settings.settings_page_flags & SETTINGS_REPORTED_TO_PC) {
        if (user_settings.gaming_flags & SOUND_FROM_SECOND_PICTURE)
            user_settings.byte_0x3e = input_api_lookup_source_value(input_api_source_id_to_menu_index(input_api_get_channel_port_code(1)));
        else
            user_settings.byte_0x3e = input_api_lookup_source_value(input_api_source_id_to_menu_index(input_api_get_channel_port_code(0)));
    } else
        user_settings.byte_0x3e = 0;
    audio_api_route_source(user_settings.byte_0x3e, AUDIO_ROUTE_ARGUMENT);
}
