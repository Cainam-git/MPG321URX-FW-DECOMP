/* osd_quick_switch_optix_scope_on  (FUN_a00a5218)
 *
 * Turn Optix Scope on in its quick menu (right key)
 * Note: Only when Optix Scope was off: clears blur reduction, Screen Size 1:1 / 24.5" / 27", the PIP/PBP mode
 *   and Adaptive-Sync, sets byte +0x4A and redraws the switch.
 * Name basis: derived - handler table 0xA802422C: right on state 0x103 (Navi Key quick menu 'Optix Scope')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a5218 @ 0xa00a5218, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the switch is drawn by one loop with the test (?:) inside the argument,
 * so the loop is unswitched after jump threading and the test of `switch_state` after the loop stays;
 * `switch_state` is read from the setting again after it was set.
 */
/* The fields of the user settings record used here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char p000[0x1f];
    unsigned char pip_pbp_mode;             /* +0x1F: 0 off, 1 PIP, 2 PBP */
    unsigned char p020[0x4a - 0x20];
    unsigned char optix_scope;              /* +0x4A: the Optix Scope switch */
    unsigned char p04b[0xa8 - 0x4b];
    unsigned int gaming_flags;              /* +0xA8: bit 7 Adaptive-Sync */
    unsigned int settings_page_flags;       /* +0xAC */
    unsigned int blur_free_mode;            /* +0xB0 */
    unsigned char p0b4[0x1a4 - 0xb4];
    unsigned char screen_size;              /* +0x1A4 */
};
#define GAMING_ADAPTIVE_SYNC    0x80        /* bit 7 of gaming_flags */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */
#define CELL_BLANK              0x792       /* cell value of an empty menu cell */
#define CELL_SWITCH_HALF        0x992       /* cell value under one of the two halves of the switch; the other half gets CELL_BLANK */
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_close_menu(void);
extern void audio_mute_outputs(void);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void pq_update_input_window(int);
extern void sys_user_apply_second_picture_enable(int);
extern void sys_user_save_mode_slot(void);
extern void sys_user_clear_second_picture_request(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

/*
 * Right key in the Optix Scope quick menu: switch Optix Scope on.
 *
 * When the scope is already on, only the settings-changed request is raised. Otherwise the routine first
 * switches off, in this order, whatever is active and has to be off before the scope can be on:
 *   1. Blur Free mode (+0xB0), if set: cleared, the picture settings are saved to the mode slot and the
 *      pending second-picture request is cleared;
 *   2. when sys_is_mode_4_to_6() returns 1: the picture output is switched off, Screen Size (+0x1A4) is set to 0
 *      and the input window is recomputed;
 *   3. PIP/PBP mode (+0x1F), if set: cleared and applied;
 *   4. Adaptive-Sync (bit 7 of +0xA8), if set: cleared, the menu is closed, the sound is muted, the picture output
 *      is switched off and the DSC setting is applied.
 * Then Optix Scope (+0x4A) is set to 1, the second picture is applied and the OFF/ON switch of the quick menu is
 * redrawn (the same drawing as osd_draw_quick_switch). Reached through the key table for the state 0x103
 * (Navi Key quick menu "Optix Scope").
 */
void osd_quick_switch_optix_scope_on(void)
{
    unsigned char i, switch_state;

    if (user_settings.optix_scope == 0) {
        if (user_settings.blur_free_mode != 0) {
            user_settings.blur_free_mode = 0;
            sys_user_save_mode_slot();
            sys_user_clear_second_picture_request();
        }
        if (sys_is_mode_4_to_6() == 1) {
            panel_user_set_output_on(0);
            user_settings.screen_size = 0;
            pq_update_input_window(0);
        }
        if (user_settings.pip_pbp_mode != 0) {
            user_settings.pip_pbp_mode = 0;
            UserSetPIPMode();
        }
        if (user_settings.gaming_flags & GAMING_ADAPTIVE_SYNC) {
            user_settings.gaming_flags &= ~GAMING_ADAPTIVE_SYNC;
            osd_close_menu();
            audio_mute_outputs();
            panel_user_set_output_on(0);
            sys_user_apply_adaptive_sync_setting();
        }
        user_settings.optix_scope = 1;
        sys_user_apply_second_picture_enable(0);
        /* Redraw the switch: clear its four cells, write the glyphs of the position (0x22.. when the switch state
           is 0, 0x1E.. otherwise), then the cell values of the two halves. */
        switch_state = user_settings.optix_scope;
        osd_api_fill_cells(5, 8, 4, CELL_BLANK, 0);
        for (i = 0; i < 4; i++)
            osd_api_fill_cell_bytes(0, i + 9, 8, 1, switch_state == 0 ? i + 0x22 : i + 0x1e, 0);
        if (switch_state == 0) {
            osd_api_fill_cells(3, 8, 5, CELL_BLANK, 0);
            osd_api_fill_cells(0xe, 8, 5, CELL_SWITCH_HALF, 0);
        } else {
            osd_api_fill_cells(3, 8, 5, CELL_SWITCH_HALF, 0);
            osd_api_fill_cells(0xe, 8, 5, CELL_BLANK, 0);
        }
    }
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
