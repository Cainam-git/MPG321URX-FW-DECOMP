/* osd_commit_pip_pbp_layout  (FUN_a00976f8)
 *
 * Close the menu and rebuild the picture when the PIP/PBP layout changed.
 * Note: Restarts channels 0 and 1, runs UserSetPIPMode and updates the input windows.
 * Name basis: derived - compares byte +0x1F with the copy saved on entry
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00976f8 @ 0xa00976f8, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the sleep word (+4) is a bit-field view (bit 15, a 4-bit field, bit 10) as in osd_close_menu, and +0x18 has
 *    single-bit bit-fields for bits 15, 14 and 13;
 *  - the comparison of the layout with osd_choice_row is written twice, as two separate if statements.
 */

#define MENU_STATE_CLOSED       0
#define ALL_PORTS               4       /* input_rearm_port_event: every port */
#define MAIN_CHANNEL            0
#define SECOND_CHANNEL          1
#define RESTART_LEVEL_1         1       /* sys_api_restart_channel_at_level: level 1 */
#define GAMING_FLAG_BIT14       0x4000  /* gaming_flags bit 14 */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = off, 1 = PIP, 2 = PBP (PIP_PBP_MODE_*) */
    unsigned char pad20[0xa8 - 0x20];
    unsigned int gaming_flags;                  /* +0xA8 */
};

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned char pad[4];
    unsigned short bit15 : 1,                   /* sleep word (+4) bit 15: closing the menu re-arms the port events */
                   bits_11_14 : 4,
                   bit10 : 1,                   /* set together with that re-arm */
                   rest : 10;
    unsigned char pad2[0x18 - 6];
    unsigned short flags_0x18_bit15 : 1, flags_0x18_bit14 : 1, flags_0x18_bit13 : 1, flags_0x18_rest : 13;
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_hide_menu(void);
extern void panel_user_set_output_on(int);
extern void sys_api_restart_channel_at_level(int, int);
extern void UserSetPIPMode(void);
extern void pq_update_input_window(int);
extern void pq_user_reset_response_level(void);
extern void sys_user_save_mode_slot(void);
extern void audio_user_update_routing(void);

/*
 * Apply a changed PIP/PBP layout: close the menu and rebuild the picture. Does nothing when the layout
 * (settings +0x1F) equals osd_choice_row, the layout that was active when the list opened.
 *
 * Called after osd_apply_pip_pbp_mode by osd_select_pip_pbp_off, osd_enter_pip_settings,
 * osd_enter_pbp_settings and osd_apply_choice_on_timeout.
 *
 * When the layout changed:
 *   1. the menu is closed (the steps of osd_close_menu) and bits 14 and 13 of app_state_record +0x18 are set;
 *   2. the output goes off, both channels restart, UserSetPIPMode applies the layout, and the input window,
 *      response level and the mode slot are updated; the sound routing follows when gaming_flags bit 14 is set;
 *      the events of ports 0 and 1 are re-armed.
 */
void osd_commit_pip_pbp_layout(void)
{
    if (user_settings.pip_pbp_mode != osd_choice_row) {
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(ALL_PORTS, 0);
        }
        osd_menu_state = MENU_STATE_CLOSED;
        osd_hide_menu();
        app_state_record.flags_0x18_bit14 = 1;
        app_state_record.flags_0x18_bit13 = 1;
    }
    if (user_settings.pip_pbp_mode != osd_choice_row) {
        panel_user_set_output_on(0);
        sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
        UserSetPIPMode();
        pq_update_input_window(0);
        pq_user_reset_response_level();
        sys_user_save_mode_slot();
        if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
            audio_user_update_routing();
        input_rearm_port_event(0, 0);
        input_rearm_port_event(1, 0);
    }
}
