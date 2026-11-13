/* osd_apply_optix_scope  (FUN_a0099658)
 *
 * Switch Optix Scope on or off from the menu state, turning off features it excludes.
 * Note: ON (state 0x47) writes settings byte +0x4A first, then turns off blur reduction, Screen Size 1:1 /
 *   24.5" / 27", the PIP/PBP layout and Adaptive-Sync.
 * Name basis: derived - called by osd_accept_optix_scope; state 0x46/0x47 = OFF/ON
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099658 @ 0xa0099658, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the sleep word (+4) is a bit-field view (bit 15, a 4-bit field, bit 10) as in osd_close_menu;
 *  - the close-menu steps are written out in each of the three blocks that close the menu, and the three blocks
 *    keep their own call sequences (the compiler merges them);
 *  - the ON branch ends with "if (osd_menu_state == 0) return;" before the shared test "osd_menu_state > 0x45".
 */

#define MENU_STATE_CLOSED               0
#define MENU_STATE_OPTIX_SCOPE_OFF      0x46    /* Optix Scope list: 0x46 OFF, 0x47 ON; switch value = state - 0x46 */
#define MENU_STATE_OPTIX_SCOPE_ON       0x47
#define ALL_PORTS                       4       /* input_rearm_port_event: every port */
#define MAIN_CHANNEL                    0
#define SECOND_CHANNEL                  1
#define RESTART_LEVEL_1                 1       /* sys_api_restart_channel_at_level: level 1 */
#define GAMING_FLAG_ADAPTIVE_SYNC       0x80    /* gaming_flags bit 7: Adaptive-Sync */
#define OSD_REQUEST_SETTINGS_CHANGED    0x02    /* osd_request_bits bit 1 */

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned char pad[4];
    unsigned short bit15 : 1,                   /* sleep word (+4) bit 15: closing the menu re-arms the port events */
                   bits_11_14 : 4,
                   bit10 : 1,                   /* set together with that re-arm */
                   rest : 10;
};

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = off, 1 = PIP, 2 = PBP (PIP_PBP_MODE_*) */
    unsigned char pad20[0x4a - 0x20];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int gaming_flags, settings_page_flags, blur_free_mode;     /* +0xA8, +0xAC, +0xB0 */
    unsigned char padb4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_hide_menu(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void sys_user_save_mode_slot(void);
extern void sys_user_clear_second_picture_request(void);
extern void sys_user_apply_second_picture_enable(int);
extern void panel_user_set_output_on(int);
extern void audio_mute_outputs(void);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);
extern void sys_api_restart_channel_at_level(int, int);
extern void pq_update_input_window(int);

/*
 * Set the Optix Scope switch from the menu state (0x46 = OFF, 0x47 = ON) and apply it. Switching it ON first
 * clears blur_free_mode, the PIP/PBP layout and Adaptive-Sync, and acts on the mode that sys_is_mode_4_to_6
 * tests; each of the last three steps closes the menu when it acts.
 *
 * Called by osd_accept_optix_scope (OK) and by osd_apply_choice_on_timeout when the menu times out on 0x46 or
 * 0x47.
 *
 * ON (state 0x47), in order:
 *   1. optix_scope = 1. When blur_free_mode is set it is cleared, the mode slot is saved and the second picture
 *      request is cleared.
 *   2. When sys_is_mode_4_to_6 says 1: output off, menu closed, Screen Size cleared, both channels restart,
 *      UserSetPIPMode applies it, the input window is updated.
 *   3. When a PIP/PBP layout is on: the layout is set to 0, the menu closed, sound muted, output off and
 *      UserSetPIPMode applies it.
 *   4. When Adaptive-Sync is on: it is cleared, the menu closed, sound muted, output off and the DSC setting
 *      applied again.
 *   5. The Optix Scope setting is applied and the settings are marked changed. When one of the steps closed the
 *      menu (osd_menu_state is 0) the routine ends here.
 * Otherwise (OFF, or ON with the menu still open): optix_scope = state - 0x46 and the setting is applied.
 */
void osd_apply_optix_scope(void)
{
    if (osd_menu_state == MENU_STATE_OPTIX_SCOPE_ON) {
        user_settings.optix_scope = 1;
        if (user_settings.blur_free_mode != 0) {
            user_settings.blur_free_mode = 0;
            sys_user_save_mode_slot();
            sys_user_clear_second_picture_request();
        }
        if (sys_is_mode_4_to_6() == 1) {
            panel_user_set_output_on(0);
            if (app_state_record.bit15) {
                app_state_record.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            user_settings.screen_size = 0;
            sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
            UserSetPIPMode();
            pq_update_input_window(0);
        }
        if (user_settings.pip_pbp_mode != 0) {
            user_settings.pip_pbp_mode = 0;
            if (app_state_record.bit15) {
                app_state_record.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            audio_mute_outputs();
            panel_user_set_output_on(0);
            UserSetPIPMode();
        }
        if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) {
            user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
            if (app_state_record.bit15) {
                app_state_record.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            audio_mute_outputs();
            panel_user_set_output_on(0);
            sys_user_apply_adaptive_sync_setting();
        }
        sys_user_apply_second_picture_enable(0);
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        if (osd_menu_state == MENU_STATE_CLOSED)
            return;
    }
    if (osd_menu_state > MENU_STATE_OPTIX_SCOPE_OFF - 1) {
        user_settings.optix_scope = osd_menu_state - MENU_STATE_OPTIX_SCOPE_OFF;
        sys_user_apply_second_picture_enable(0);
    }
}
