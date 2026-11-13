/* osd_apply_screen_size  (FUN_a0096858)
 *
 * Switch the menu layer off, turn off features the new screen size excludes, apply the layout.
 * Note: For sizes 1:1, 24.5" and 27" turns off Optix Scope, blur reduction and Adaptive-Sync; the menu is
 *   closed only when Adaptive-Sync was on.
 * Name basis: derived - called by osd_accept_screen_size and osd_apply_choice_on_timeout; sys_is_mode_4_to_6
 *   tests the screen size byte +0x1A4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096858 @ 0xa0096858-0xa0096b54 (764 bytes), flags -mcpu=v8 -O3 -g.
 * Called by osd_accept_screen_size and osd_apply_choice_on_timeout (osd_apply_choice_on_timeout).
 * Source form: the app_state_record flags are unsigned short bit-fields (bit 14 of +0x18 cleared, bit 15 of +4
 * tested as a HImode mask and bit 10 set from the same load); one complete SYSAPI_ConfigSystemPIPMode call per
 * arm; the three tests of osd_choice_row 5, 6 and 4 are separate ifs in that order.
 */
struct app_state_record {
    unsigned short half_0x0, half_0x2;
    unsigned short bit15 : 1, bits11_14 : 4, bit10 : 1, rest : 10;     /* halfword +4: bit 15 = SLEEP_WORD_BIT15, bit 10 = SLEEP_WORD_BIT10 */
    unsigned short half_0x6, half_0x8, half_0xa, half_0xc, half_0xe, half_0x10, half_0x12, half_0x14, half_0x16;
    unsigned short bit15_0x18 : 1, bit14_0x18 : 1, rest_0x18 : 14;    /* halfword +0x18 */
};
struct user_settings_record {
    unsigned char p00[0x4a];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char p4b[0xa8 - 0x4b];
    unsigned int gaming_flags;                  /* +0xA8: bit 7 Adaptive-Sync */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned int blur_free_mode;                /* +0xB0 */
    unsigned char pb4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size, SCREEN_SIZE_* */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern unsigned char osd_choice_row;
extern void osd_api_enable(int, int);
extern unsigned char sys_get_channel_source_class(unsigned char ch);
extern void sys_frc_set_source_class_enable(unsigned char sel, unsigned char on);
extern unsigned char sys_is_mode_4_to_6(void);
extern void sys_user_apply_second_picture_enable(int);
extern void UserSetPIPMode(void);
extern void sys_user_save_mode_slot(void);
extern void sys_user_clear_second_picture_request(void);
extern void input_rearm_port_event(int, int);
extern void osd_hide_menu(void);
extern void audio_mute_outputs(void);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSwitchEDID(int, int);
extern unsigned char input_api_get_channel_port_code(int);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void sys_app_timer_start(int, int);
extern void sys_api_restart_channel_at_level(int, int);
extern void sys_api_set_channel_timeout(int, int, int);
extern void SYSAPI_ConfigSystemPIPMode(unsigned int mode);
extern void timer_api_sleep_ticks(unsigned short ms);
extern int dbg_printf(const char *fmt, ...);

#define SCREEN_SIZE_16_10             3         /* the Screen Size list entry "16:10" (texts: Auto, 4:3, 16:9, 16:10, 1:1, 24.5", 27") */
#define SCREEN_SIZE_1_1               4         /* "1:1"; 4, 5 and 6 are the sizes that sys_is_mode_4_to_6 reports */
#define SCREEN_SIZE_24_5              5         /* 24.5" */
#define SCREEN_SIZE_27                6         /* 27" */
#define GAMING_FLAG_ADAPTIVE_SYNC     0x80      /* bit 7 of the gaming flags */
#define SETTINGS_PAGE_FLAG_BIT20      0x100000  /* bit 20 of the settings page flags */
#define APP_STATE_CEC_SOURCE_HOLD     0x40      /* bit 6 of app_state_record halfword +0xA */
#define APP_TIMER_CEC_SOURCE_HOLD     0x14      /* started with 5000 ms together with APP_STATE_CEC_SOURCE_HOLD */
#define CEC_SOURCE_HOLD_MS            5000

/*
 * Apply a Screen Size (user_settings.screen_size) after it was stored. Called by osd_accept_screen_size and by
 * osd_apply_choice_on_timeout. osd_choice_row is read as the other screen size of the change (the size saved
 * when the Screen Size list was opened). No parameters, no return value.
 *
 * Order of work:
 *  1. Switch the menu layer off and clear bit 14 of app_state_record halfword +0x18. When Optix Scope is on, its
 *     FRC source class (channel 1) is disabled.
 *  2. When the Screen Size is one of 1:1, 24.5" or 27" (sys_is_mode_4_to_6), these features are switched off:
 *     Optix Scope and the second picture (always, then UserSetPIPMode), blur reduction (only if it was on:
 *     mode 0, mode slot saved) and Adaptive-Sync (only if it was on: the menu is closed, the sound muted, the DSC
 *     setting reapplied).
 *  3. Print the screen size and osd_choice_row ("-->(%x %x)").
 *  4. If either of them is 16:10: switch the EDID (UserSwitchEDID), start the CEC source hold for 5000 ms when
 *     channel 0 has a source and settings page flag bit 20 is set, restart channels 0 and 1 at level 1, set the
 *     timeout of all four channels to 1000, then set the PIP mode to 0 if the size is 4..6, else 2.
 *  5. Otherwise: wait 50 ticks, restart channels 0 and 1 at level 1; if osd_choice_row is 5, 6 or 4 and the
 *     size is not 4..6, set the PIP mode to 2; if the size is 4..6, set the PIP mode to 0.
 */
void osd_apply_screen_size(void)
{
    osd_api_enable(0, 0);
    app_state_record.bit14_0x18 = 0;
    if (user_settings.optix_scope == 1)
        sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 0);
    /* Sizes 4..6: no Optix Scope, no blur reduction, no Adaptive-Sync. */
    if (sys_is_mode_4_to_6() == 1) {
        user_settings.optix_scope = 0;
        sys_user_apply_second_picture_enable(0);
        UserSetPIPMode();
    }
    if (sys_is_mode_4_to_6() == 1 && user_settings.blur_free_mode != 0) {
        user_settings.blur_free_mode = 0;
        sys_user_save_mode_slot();
        sys_user_clear_second_picture_request();
    }
    if (sys_is_mode_4_to_6() == 1 && (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC)) {
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(4, 0);
        }
        osd_menu_state = 0;
        osd_hide_menu();
        user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
        audio_mute_outputs();
        sys_user_apply_adaptive_sync_setting();
        osd_request_bits |= 2;
    }
    dbg_printf("-->(%x %x)\r\n", user_settings.screen_size, osd_choice_row);
    if (user_settings.screen_size == SCREEN_SIZE_16_10 || osd_choice_row == SCREEN_SIZE_16_10) {
        UserSwitchEDID(2, 0);
        if (input_api_source_id_to_menu_index(input_api_get_channel_port_code(0)) && (user_settings.settings_page_flags & SETTINGS_PAGE_FLAG_BIT20)) {
            app_state_record.half_0xa |= APP_STATE_CEC_SOURCE_HOLD;
            sys_app_timer_start(APP_TIMER_CEC_SOURCE_HOLD, CEC_SOURCE_HOLD_MS);
        }
        sys_api_restart_channel_at_level(0, 1);
        sys_api_restart_channel_at_level(1, 1);
        sys_api_set_channel_timeout(4, 1, 1000);
        if (sys_is_mode_4_to_6())
            SYSAPI_ConfigSystemPIPMode(0);
        else
            SYSAPI_ConfigSystemPIPMode(2);
    } else {
        timer_api_sleep_ticks(0x32);
        sys_api_restart_channel_at_level(0, 1);
        sys_api_restart_channel_at_level(1, 1);
        if (osd_choice_row == SCREEN_SIZE_24_5 && !sys_is_mode_4_to_6())
            SYSAPI_ConfigSystemPIPMode(2);
        if (osd_choice_row == SCREEN_SIZE_27 && !sys_is_mode_4_to_6())
            SYSAPI_ConfigSystemPIPMode(2);
        if (osd_choice_row == SCREEN_SIZE_1_1 && !sys_is_mode_4_to_6())
            SYSAPI_ConfigSystemPIPMode(2);
        if (sys_is_mode_4_to_6() == 1)
            SYSAPI_ConfigSystemPIPMode(0);
    }
}
