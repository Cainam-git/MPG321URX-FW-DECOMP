/* osd_select_pbp_mode2  (FUN_a0097f48)
 *
 * Switch PBP to Mode 2 and return to the PIP/PBP list (OK)
 * Note: Writes 1 to settings byte +0x2F; when the layout changes it closes the menu and returns without
 *   redrawing the list.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x80 = 'Mode 2' (texts 0x18E89C)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097f48 @ 0xa0097f48, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the sleep word (+4) is a bit-field view (bit 15, a 4-bit field, bit 10) as in osd_close_menu;
 *  - each menu-state case (0x7F, 0x80, any other) has its own compare, store and call sequence, as in
 *    osd_select_pbp_mode1 (the compiler merges the call sequences); the close-menu steps appear in the 0x80 and
 *    "other" cases only.
 */

enum {
    MENU_STATE_CLOSED = 0,
    MENU_STATE_PBP_MODE_1 = 0x7f,               /* PBP settings list: 0x7F Mode 1, 0x80 Mode 2, 0x81 Customize */
    MENU_STATE_PBP_MODE_2 = 0x80,
    MENU_STATE_PIP_PBP_PBP = 0x25               /* the PBP item of the PIP/PBP item list (0x23 + 2) */
};
#define PBP_LAYOUT_0            0               /* values of pbp_layout (PBP_LAYOUT_*) */
#define PBP_LAYOUT_1            1
#define LIST_KIND_CHOICES       1               /* osd_draw_choice_mark: a choice list */
#define ALL_PORTS               4               /* input_rearm_port_event: every port */
#define MAIN_CHANNEL            0
#define SECOND_CHANNEL          1
#define RESTART_LEVEL_1         1               /* sys_api_restart_channel_at_level: level 1 */
#define LIST_ID_PIP_PBP_ITEMS   5               /* value of osd_list_id set when the PIP/PBP item list is shown again */

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
    unsigned char pad0[0x2f];
    unsigned char pbp_layout;                   /* +0x2F: the PBP layout (PBP_LAYOUT_*) */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_saved_choice_value;
extern unsigned char osd_list_id;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(int, int);
extern void panel_user_set_output_on(unsigned char);
extern void sys_api_restart_channel_at_level(int, int);
extern void UserSetPIPMode(void);
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_hide_menu(void);

/*
 * OK on 'Mode 2' (menu state 0x80) of the PBP settings list: make Mode 2 the PBP layout. osd_menu_key_table
 * calls it for that state only. Same steps as osd_select_pbp_mode1, with one difference: when the layout changes
 * the menu is closed (the steps of osd_close_menu, between the output going off and the channels restarting) and
 * the routine returns without redrawing the list. When the layout was already Mode 2, the list is redrawn and the
 * menu state returns to 0x25 as in osd_select_pbp_mode1.
 *
 * In order:
 *   1. When the open row (state - 0x7F) is not the row carrying the choice mark (osd_saved_choice_value), that
 *      row's highlight is removed and its mark cleared.
 *   2. The new layout is 0 for state 0x7F, 1 for state 0x80 and the marked row for any other state. When it
 *      differs from the stored layout it is stored, the output goes off, and, except for state 0x7F, the menu is
 *      closed; both channels restart and UserSetPIPMode applies the layout.
 *   3. With the menu still open: the open row's highlight is removed, the mark drawn on the layout, the layout
 *      row highlighted, the menu state set to 0x25, item row 2 highlighted, the key guide redrawn and
 *      osd_list_id set to 5.
 */
void osd_select_pbp_mode2(void)
{
    if (osd_menu_state - MENU_STATE_PBP_MODE_1 != osd_saved_choice_value) {
        osd_clear_choice_highlight(osd_saved_choice_value);
        osd_draw_choice_mark(LIST_KIND_CHOICES, osd_saved_choice_value, 0);
    }
    if (osd_menu_state == MENU_STATE_PBP_MODE_1) {
        if (user_settings.pbp_layout != PBP_LAYOUT_0) {
            user_settings.pbp_layout = PBP_LAYOUT_0;
            panel_user_set_output_on(0);
            sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
            UserSetPIPMode();
        }
    } else if (osd_menu_state == MENU_STATE_PBP_MODE_2) {
        if (user_settings.pbp_layout != PBP_LAYOUT_1) {
            user_settings.pbp_layout = PBP_LAYOUT_1;
            panel_user_set_output_on(0);
            if (app_state_record.bit15) {
                app_state_record.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
            UserSetPIPMode();
        }
    } else if (user_settings.pbp_layout != osd_saved_choice_value) {
        user_settings.pbp_layout = osd_saved_choice_value;
        panel_user_set_output_on(0);
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(ALL_PORTS, 0);
        }
        osd_menu_state = MENU_STATE_CLOSED;
        osd_hide_menu();
        sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
        UserSetPIPMode();
    }
    if (osd_menu_state == MENU_STATE_CLOSED)
        return;
    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PBP_MODE_1);
    osd_draw_choice_mark(LIST_KIND_CHOICES, user_settings.pbp_layout, 1);
    osd_highlight_choice_row(user_settings.pbp_layout, 0);
    osd_draw_key_guide(1, 2);
    osd_menu_state = MENU_STATE_PIP_PBP_PBP;
    osd_highlight_item_row(2, 1);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
    osd_list_id = LIST_ID_PIP_PBP_ITEMS;
}
