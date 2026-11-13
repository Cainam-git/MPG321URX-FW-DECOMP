/* osd_apply_pip_pbp_mode  (FUN_a0097508)
 *
 * Store the highlighted PIP/PBP layout and switch off the features it excludes.
 * Note: Turns off Optix Scope, Adaptive-Sync, DSC and similar options before writing settings byte +0x1F.
 * Name basis: derived - called by osd_enter_pip_settings / osd_enter_pbp_settings; layout = menu state - 0x23
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097508 @ 0xa0097508, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - bit 31 of word +0x1F4 is a signed 1-bit bit-field (a mask test places the clear block out of line);
 *  - the test of the HDMI CEC bit comes after the layout is stored and is written out as its own if.
 */

#define MENU_STATE_PIP_PBP_OFF          0x23    /* first of the three layout items; item = state - 0x23 */
#define GAMING_FLAG_ADAPTIVE_SYNC       0x80    /* gaming_flags bit 7: Adaptive-Sync */
#define SETTINGS_HDMI_CEC_ON            0x100000    /* settings_page_flags bit 20: the HDMI CEC menu switch */
#define SELECT_PORTS_0X10               0x10    /* first argument of input_api_select_ports here */
#define MAIN_CHANNEL                    0
#define SECOND_CHANNEL                  1
#define RESTART_LEVEL_1                 1       /* sys_api_restart_channel_at_level: level 1 */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x19];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad1a[0x1e - 0x1a];
    unsigned char input_source;                 /* +0x1E: Input Source */
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = off, 1 = PIP, 2 = PBP (PIP_PBP_MODE_*) */
    unsigned char pad20[0x4a - 0x20];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad4b[0x8f - 0x4b];
    unsigned char byte_0x8f;                    /* +0x8F: copy of response_time saved when the PIP/PBP page opens */
    unsigned char pad90[0xa8 - 0x90];
    unsigned int gaming_flags, settings_page_flags, blur_free_mode;     /* +0xA8, +0xAC, +0xB0 */
    unsigned char padb4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
    unsigned char pad1a5[0x1f4 - 0x1a5];
    union {
        unsigned int value;
        struct {
            signed int dsc_switch : 1;          /* bit 31 */
            unsigned int rest : 31;
        } bits;
    } word_0x1f4;
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern unsigned char sys_is_mode_4_to_6(void);
extern void sys_user_clear_second_picture_request(void);
extern void sys_user_apply_second_picture_enable(int);
extern void audio_mute_outputs(void);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void input_api_select_ports(int, int);
extern void sys_api_restart_channel_at_level(int, int);

/*
 * Store the PIP/PBP layout of the highlighted item (menu state 0x23 = off, 0x24 = PIP, 0x25 = PBP) and clear
 * the settings that go with the old layout.
 *
 * Called by osd_select_pip_pbp_off, osd_enter_pip_settings and osd_enter_pbp_settings, each followed by
 * osd_commit_pip_pbp_layout, and by osd_apply_choice_on_timeout at menu time-out. It does not apply the layout.
 *
 * Off (0x23): Screen Size is set back to osd_edit_value (the value the PIP and PBP settings lists save when they
 * open) and the response time back to the copy in +0x8F (saved by osd_enter_pip_pbp_items when it opens with the
 * layout off).
 * PIP or PBP: Screen Size is cleared when sys_is_mode_4_to_6 says 1 or it is 3; blur_free_mode is cleared (with
 * the second picture request); HDMI CEC and the DSC switch (bit 31 of +0x1F4) are cleared; Optix Scope is
 * switched off; Adaptive-Sync is switched off (sound muted, output off, DSC setting applied again).
 *
 * Then the layout is stored as menu state - 0x23. With HDMI CEC still on (only possible after the off case,
 * the other case cleared it), a layout different from osd_choice_row and an input source whose menu index gives
 * source 0, the sound is muted, the output goes off, the ports are selected again and both channels restart.
 */
void osd_apply_pip_pbp_mode(void)
{
    if (osd_menu_state == MENU_STATE_PIP_PBP_OFF) {
        user_settings.screen_size = osd_edit_value;
        user_settings.response_time = user_settings.byte_0x8f;
    } else {
        if (sys_is_mode_4_to_6() == 1)
            user_settings.screen_size = 0;
        if (user_settings.screen_size == 3)
            user_settings.screen_size = 0;
        if (user_settings.blur_free_mode != 0) {
            user_settings.blur_free_mode = 0;
            sys_user_clear_second_picture_request();
        }
        user_settings.settings_page_flags &= ~SETTINGS_HDMI_CEC_ON;
        if (user_settings.word_0x1f4.bits.dsc_switch)
            user_settings.word_0x1f4.bits.dsc_switch = 0;
        if (user_settings.optix_scope == 1) {
            user_settings.optix_scope = 0;
            sys_user_apply_second_picture_enable(0);
        }
        if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) {
            user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
            audio_mute_outputs();
            panel_user_set_output_on(0);
            sys_user_apply_adaptive_sync_setting();
        }
    }
    user_settings.pip_pbp_mode = osd_menu_state - MENU_STATE_PIP_PBP_OFF;
    if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode != osd_choice_row && !input_api_source_id_to_menu_index(user_settings.input_source)) {
        audio_mute_outputs();
        panel_user_set_output_on(0);
        input_api_select_ports(SELECT_PORTS_0X10, 1);
        sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
    }
}
