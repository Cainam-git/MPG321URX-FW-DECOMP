/* osd_accept_pbp_custom_split  (FUN_a00a10c8)
 *
 * Store the custom PBP split, switch PBP to it and close the editor (OK)
 * Note: Saves the split in settings +0x1F0/+0x1F2, sets PBP mode 2 and restarts both channels.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x109; prints 'X1 %d %d'; also called by the
 *   DDC/UART command handler uart_cmd_adjust_pbp_split
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a10c8 @ 0xa00a10c8-0xa00a13d8 (196 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the bit-field layout of the sleep word (+4) as in osd_accept_pip_pbp_quick_menu
 * (bit15, a 4-bit field, bit10); the 'osd_choice_row != PIP_PBP_MODE_PBP' arm written first (register names).
 */

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned char pad[4];
    unsigned short bit15 : 1,                   /* sleep word (+4) bit 15: closing the menu re-arms the port events */
                   bits_11_14 : 4,
                   bit10 : 1,                   /* set together with that re-arm */
                   rest : 10;
    unsigned char pad6[0x34 - 6];
    unsigned char split_editor;                 /* +0x34: SPLIT_EDITOR_OPEN set by osd_open_pbp_custom_split */
    unsigned char pad35;
    unsigned short split_x, split_lines;        /* +0x36 / +0x38: the split line of the editor (x, height) */
};

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x19];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad1a[0x1e - 0x1a];
    unsigned char input_source, pip_pbp_mode;   /* +0x1E, +0x1F: Input Source; PIP/PBP mode (PIP_PBP_MODE_*) */
    unsigned char pad20[0x2f - 0x20];
    unsigned char pbp_layout;                   /* +0x2F: the PBP layout */
    unsigned char pad30[0x4a - 0x30];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int gaming_flags, settings_page_flags, blur_free_mode;     /* +0xA8, +0xAC, +0xB0 */
    unsigned char padb4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
    unsigned char pad1a5[0x1ec - 0x1a5];
    unsigned int word_0x1ec;                    /* +0x1EC: SETTINGS_1EC_* */
    unsigned short custom_split_x, custom_split_lines;  /* +0x1F0 / +0x1F2: the stored custom split */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_saved_choice_value, osd_choice_row;
extern unsigned char osd_request_bits;
extern int dbg_printf();
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_hide_menu(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void sys_user_apply_second_picture_enable(int);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);
extern void audio_mute_outputs(void);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void input_api_select_ports(int, int);
extern void sys_api_restart_channel_at_level(int, int);
extern void pq_update_input_window(int);
extern void pq_user_reset_response_level(void);
extern void osd_draw_adaptive_sync_status(void);
extern void sys_user_save_mode_slot(void);
extern void audio_user_update_routing(void);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);

#define SPLIT_EDITOR_OPEN           2           /* app_state_record +0x34 while the custom split editor is open */
#define SETTINGS_1EC_SPLIT_STORED   0x40        /* word +0x1EC bit 6: osd_open_pbp_custom_split starts from the
                                                   stored split when set */
#define PIP_PBP_MODE_PBP            2           /* pip_pbp_mode: 0 off, 1 PIP, 2 PBP */
#define GAMING_FLAG_ADAPTIVE_SYNC   0x80        /* gaming_flags bit 7: Adaptive-Sync */
#define GAMING_FLAG_BIT14           0x4000      /* gaming_flags bit 14 */
#define SETTINGS_HDMI_CEC_ON        0x100000    /* settings_page_flags bit 20: the HDMI CEC menu switch */
#define SELECT_PORTS_0X10           0x10        /* first argument of input_api_select_ports here */
#define MAIN_CHANNEL                0
#define SECOND_CHANNEL              1
#define RESTART_LEVEL_1             1           /* sys_api_restart_channel_at_level: level 1 */
#define ALL_PORTS                   4           /* input_rearm_port_event: every port */
#define MENU_STATE_CLOSED           0
#define MENU_STATE_CHOICE_BASE      0x7f        /* compared with osd_saved_choice_value as menu state - 0x7F */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* osd_request_bits bit 1 */

/*
 * OK in the PBP custom split editor (menu state 0x109): keep the split and switch to PBP with it.
 *
 * Called from osd_menu_key_table (OK on state 0x109), by osd_apply_choice_on_timeout when the menu time-out
 * ends on that state, and by uart_cmd_adjust_pbp_split (PC tool command value 0).
 *
 * Phases, in order:
 *   1. With the editor open, store its split in settings +0x1F0 / +0x1F2 and mark it stored.
 *   2. Switch off Optix Scope and Adaptive-Sync when on (for Adaptive-Sync: sound muted, output off, DSC
 *      setting applied again); with HDMI CEC on, a PIP/PBP mode other than the highlighted row and input source menu
 *      index giving source 0, the output goes off and both channels restart. Screen Size is cleared when
 *      sys_is_mode_4_to_6 says 1.
 *   3. PBP mode 2, blur reduction 0, response time 0.
 *   4. Close the menu and restart both channels with the new mode. When the highlighted row was not already PBP,
 *      the input window, response level, Adaptive-Sync status line, mode slot and sound routing follow, the
 *      events of ports 0 and 1 are re-armed and the row becomes PBP; else the saved choice becomes the PBP
 *      layout.
 *   5. Move the choice mark when the menu state minus 0x7F differs from the saved choice, and mark the settings
 *      changed.
 */
void osd_accept_pbp_custom_split(void)
{
    /* 1. Store the split. */
    if (app_state_record.split_editor == SPLIT_EDITOR_OPEN) {
        user_settings.word_0x1ec |= SETTINGS_1EC_SPLIT_STORED;
        user_settings.custom_split_x = app_state_record.split_x;
        user_settings.custom_split_lines = app_state_record.split_lines;
        dbg_printf("X1 %d %d\r\n", app_state_record.split_x, app_state_record.split_lines);
    }

    /* 2. Optix Scope and Adaptive-Sync off. */
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
    if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode != osd_choice_row && input_api_source_id_to_menu_index(user_settings.input_source) == 0) {
        panel_user_set_output_on(0);
        input_api_select_ports(SELECT_PORTS_0X10, 1);
        sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
    }
    if (sys_is_mode_4_to_6() == 1)
        user_settings.screen_size = 0;

    /* 3. PBP. */
    user_settings.pip_pbp_mode = PIP_PBP_MODE_PBP;
    user_settings.blur_free_mode = 0;
    user_settings.response_time = 0;

    /* 4. Close the menu and apply the mode. */
    if (osd_choice_row != PIP_PBP_MODE_PBP) {
        /* The steps of osd_close_menu. */
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(ALL_PORTS, 0);
        }
        osd_menu_state = MENU_STATE_CLOSED;
        osd_hide_menu();
        panel_user_set_output_on(0);
        sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
        UserSetPIPMode();
        pq_update_input_window(0);
        pq_user_reset_response_level();
        osd_draw_adaptive_sync_status();
        sys_user_save_mode_slot();
        if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
            audio_user_update_routing();
        input_rearm_port_event(0, 0);
        input_rearm_port_event(1, 0);
        osd_choice_row = user_settings.pip_pbp_mode;
    } else {
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(ALL_PORTS, 0);
        }
        osd_menu_state = MENU_STATE_CLOSED;
        osd_hide_menu();
        panel_user_set_output_on(0);
        sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
        UserSetPIPMode();
        osd_saved_choice_value = user_settings.pbp_layout;
    }

    /* 5. Choice mark and request bit. */
    if (osd_menu_state - MENU_STATE_CHOICE_BASE != osd_saved_choice_value) {
        osd_clear_choice_highlight(osd_saved_choice_value);
        osd_draw_choice_mark(1, osd_saved_choice_value, 0);
    }
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
