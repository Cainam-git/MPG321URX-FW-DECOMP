/* osd_switch_adaptive_sync  (FUN_a00b69f4)
 *
 * Toggle Adaptive-Sync, apply it and redraw its switch.
 * Note: Starts application timer 0x14 (5000 ms) on one path.
 * Name basis: derived - bit 7 of settings +0xA8; called by osd_toggle_adaptive_sync
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b69f4 @ 0xa00b69f4-0xa00b6b68 (93 words), flags -mcpu=v8 -O3 -g.
 */
/* Fields of the settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;        /* +0x1F: PIP/PBP mode (0 off) */
    unsigned char pad20[0x4a - 0x20];
    unsigned char optix_scope;         /* +0x4A: the Optix Scope switch */
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int gaming_flags;         /* +0xA8 */
    unsigned int settings_page_flags;  /* +0xAC */
    unsigned char padb0[0x1a4 - 0xb0];
    unsigned char screen_size;         /* +0x1A4: Screen Size */
};
/* Fields of the application state record used here. */
struct app_state_fields {
    unsigned char pad[0xa];
    unsigned short notice_origin;      /* +0xA: bit 6 = APP_STATE_CEC_SOURCE_HOLD */
};
extern struct user_settings_record user_settings;
extern struct app_state_fields app_state_record;
extern unsigned char osd_request_bits;
extern void osd_close_menu(void);
extern void audio_mute_outputs(void);
extern void panel_user_set_output_on(int);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void sys_api_restart_channel_at_level(int, int);
extern void pq_update_input_window(int);
extern void sys_user_apply_second_picture_enable(int);
extern void sys_user_save_mode_slot(void);
extern void osd_draw_toggle_switch(unsigned char, unsigned char);
extern void timer_api_sleep_ticks(unsigned short ms);
extern unsigned char input_api_get_channel_port_code(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void sys_app_timer_start(int, int);
extern void sys_user_apply_adaptive_sync_setting(void);

#define GAMING_FLAG_ADAPTIVE_SYNC  0x80       /* bit 7 of gaming_flags */
#define GAMING_FLAG_BIT13          0x2000     /* set whenever Adaptive-Sync is switched on */
#define SETTINGS_HDMI_CEC_ON       0x100000   /* bit 20 of settings_page_flags */
#define APP_STATE_CEC_SOURCE_HOLD  0x40       /* bit 6 of notice_origin */
#define APP_TIMER_CEC_SOURCE_HOLD  0x14       /* application timer, 5000 ms here */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02     /* bit 1 of osd_request_bits */
#define TOGGLE_SWITCH_ADAPTIVE_SYNC 5         /* first argument of osd_draw_toggle_switch */

/* Toggle Adaptive-Sync (bit 7 of the gaming flags) from its menu switch, apply it and redraw the switch.
 * Switching it off only clears the bit. Switching it on first leaves the modes it cannot be combined with:
 *   - PIP/PBP on (settings byte +0x1F not 0): turn it off (byte cleared, menu closed, outputs muted and
 *     output switched off, PIP mode applied);
 *   - sys_is_mode_4_to_6() true: Screen Size (+0x1A4) is set to 0, both channels are restarted at level 1,
 *     the PIP mode is applied again and pq_update_input_window(0) is called;
 * then Optix Scope (+0x4A) is cleared, the second picture is disabled, bit 7 and bit 13 of the flags are set
 * and the mode slot is saved.
 * Both ways then: close the menu, mute, switch the output off, draw the switch (function 5, new state), wait
 * 50 ticks; when the source of port code 0 is not 0 and HDMI CEC is on (bit 20 of +0xAC), set bit 6 of
 * app_state_record +0xA and start application timer 0x14 for 5000 ms; finally apply the DSC setting and
 * request a settings save. Called by osd_toggle_adaptive_sync. */
void osd_switch_adaptive_sync(void)
{
    if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) {
        user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
    } else {
        if (user_settings.pip_pbp_mode != 0) {
            user_settings.pip_pbp_mode = 0;
            osd_close_menu();
            audio_mute_outputs();
            panel_user_set_output_on(0);
            UserSetPIPMode();
        }
        if (sys_is_mode_4_to_6() == 1) {
            user_settings.screen_size = 0;
            sys_api_restart_channel_at_level(0, 1);
            sys_api_restart_channel_at_level(1, 1);
            UserSetPIPMode();
            pq_update_input_window(0);
        }
        user_settings.optix_scope = 0;
        sys_user_apply_second_picture_enable(0);
        user_settings.gaming_flags |= GAMING_FLAG_ADAPTIVE_SYNC;
        if (!(user_settings.gaming_flags & GAMING_FLAG_BIT13))
            user_settings.gaming_flags |= GAMING_FLAG_BIT13;
        sys_user_save_mode_slot();
    }
    osd_close_menu();
    audio_mute_outputs();
    panel_user_set_output_on(0);
    osd_draw_toggle_switch(TOGGLE_SWITCH_ADAPTIVE_SYNC, (user_settings.gaming_flags >> 7) & 1);
    timer_api_sleep_ticks(50);
    if (input_api_source_id_to_menu_index(input_api_get_channel_port_code(0)) && (user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON)) {
        app_state_record.notice_origin |= APP_STATE_CEC_SOURCE_HOLD;
        sys_app_timer_start(APP_TIMER_CEC_SOURCE_HOLD, 5000);
    }
    sys_user_apply_adaptive_sync_setting();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
