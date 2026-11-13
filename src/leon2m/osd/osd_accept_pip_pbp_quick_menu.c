/* osd_accept_pip_pbp_quick_menu  (FUN_a00972cc)
 *
 * Apply the PIP/PBP layout highlighted in the quick menu and close it.
 * Note: Quick menu state 0xFF; switches off features that conflict, then UserSetPIPMode.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xFF; copies +0x1A3 to the layout byte +0x1F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00972cc @ 0xa00972cc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the sleep word (+4) is a bit-field view (bit 15, a 4-bit field, bit 10) as in osd_accept_pbp_custom_split;
 *  - the "same layout" case and the "layout changed" case each write out the close-menu steps, so they appear
 *    twice (the first case returns at once);
 *  - the two bits of app_state_record +0x18 are set with two separate |= statements.
 */

#define MENU_STATE_CLOSED               0
#define ALL_PORTS                       4       /* input_rearm_port_event: every port */
#define APP_FLAGS_0X18_BIT14            0x4000
#define APP_FLAGS_0X18_BIT13            0x2000
#define GAMING_FLAG_ADAPTIVE_SYNC       0x80    /* gaming_flags bit 7: Adaptive-Sync */
#define SETTINGS_HDMI_CEC_ON            0x100000    /* settings_page_flags bit 20: the HDMI CEC menu switch */
#define OSD_REQUEST_SETTINGS_CHANGED    0x02    /* osd_request_bits bit 1 */

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned char pad[4];
    unsigned short bit15 : 1,                   /* sleep word (+4) bit 15: closing the menu re-arms the port events */
                   bits_11_14 : 4,
                   bit10 : 1,                   /* set together with that re-arm */
                   rest : 10;
    unsigned char pad6[0x18 - 6];
    unsigned short flags_0x18;                  /* +0x18: bits 14 and 13 are set when the layout changes */
};

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: the layout, 0 = off, 1 = PIP, 2 = PBP (PIP_PBP_MODE_*) */
    unsigned char pad20[0x4a - 0x20];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int gaming_flags, settings_page_flags, blur_free_mode;     /* +0xA8, +0xAC, +0xB0 */
    unsigned char padb4[0x1a3 - 0xb4];
    unsigned char byte_0x1a3;                   /* +0x1A3: the layout highlighted in the quick menu */
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_hide_menu(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void sys_user_clear_second_picture_request(void);
extern void sys_user_apply_second_picture_enable(int);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);

/*
 * OK in the PIP/PBP quick menu (menu state 0xFF): take the layout highlighted there and close the menu.
 *
 * The highlighted layout is user_settings.byte_0x1a3; osd_choice_row is the layout it is compared with. Called
 * through osd_menu_key_table (OK on state 0xFF) and by osd_apply_choice_on_timeout when the menu times out on
 * that state.
 *
 * When the highlighted layout equals osd_choice_row the menu is only closed. Otherwise, after closing it:
 *   - bits 14 and 13 of app_state_record +0x18 are set;
 *   - the layout becomes the PIP/PBP mode;
 *   - for a layout other than 0 (off), the following are switched off or cleared when set: Optix Scope; Adaptive-Sync
 *     (output switched off, DSC setting applied again); Screen Size when sys_is_mode_4_to_6 says 1 or it is 3;
 *     blur_free_mode (with the second picture request cleared); HDMI CEC;
 *   - UserSetPIPMode applies the layout and the settings are marked changed.
 * Unlike osd_commit_pip_pbp_layout it does not restart the channels itself.
 */
void osd_accept_pip_pbp_quick_menu(void)
{
    if (user_settings.byte_0x1a3 == osd_choice_row) {
        /* Same layout: just close the menu (the steps of osd_close_menu). */
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(ALL_PORTS, 0);
        }
        osd_menu_state = MENU_STATE_CLOSED;
        osd_hide_menu();
        return;
    }
    if (app_state_record.bit15) {
        app_state_record.bit10 = 1;
        input_rearm_port_event(ALL_PORTS, 0);
    }
    osd_menu_state = MENU_STATE_CLOSED;
    osd_hide_menu();
    app_state_record.flags_0x18 |= APP_FLAGS_0X18_BIT14;
    app_state_record.flags_0x18 |= APP_FLAGS_0X18_BIT13;
    user_settings.pip_pbp_mode = user_settings.byte_0x1a3;
    if (user_settings.byte_0x1a3 != 0) {
        if (user_settings.optix_scope == 1) {
            user_settings.optix_scope = 0;
            sys_user_apply_second_picture_enable(0);
        }
        if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) {
            user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
            panel_user_set_output_on(0);
            sys_user_apply_adaptive_sync_setting();
        }
        if (sys_is_mode_4_to_6() == 1)
            user_settings.screen_size = 0;
        if (user_settings.screen_size == 3)
            user_settings.screen_size = 0;
        if (user_settings.blur_free_mode != 0) {
            user_settings.blur_free_mode = 0;
            sys_user_clear_second_picture_request();
        }
        user_settings.settings_page_flags &= ~SETTINGS_HDMI_CEC_ON;
    }
    UserSetPIPMode();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
