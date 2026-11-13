/* osd_select_pbp_mode1  (FUN_a0097dec)
 *
 * Switch PBP to Mode 1 and return to the PIP/PBP list (OK)
 * Note: Writes 0 to settings byte +0x2F and re-applies the layout on change.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x7F = 'Mode 1' (texts 0x18E89C)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097dec @ 0xa0097dec, flags -mcpu=v8 -O3 -g.
 * Source form: each menu-state case (0x7F, 0x80, any other) has its own compare, store and call sequence, written
 * out three times (the compiler merges the call sequences).
 */

enum {
    MENU_STATE_PBP_MODE_1 = 0x7f,               /* PBP settings list: 0x7F Mode 1, 0x80 Mode 2, 0x81 Customize */
    MENU_STATE_PBP_MODE_2 = 0x80,
    MENU_STATE_PIP_PBP_PBP = 0x25               /* the PBP item of the PIP/PBP item list (0x23 + 2) */
};
#define PBP_LAYOUT_0            0               /* values of pbp_layout (PBP_LAYOUT_*) */
#define PBP_LAYOUT_1            1
#define LIST_KIND_CHOICES       1               /* osd_draw_choice_mark: a choice list */
#define MAIN_CHANNEL            0
#define SECOND_CHANNEL          1
#define RESTART_LEVEL_1         1               /* sys_api_restart_channel_at_level: level 1 */
#define LIST_ID_PIP_PBP_ITEMS   5               /* value of osd_list_id set when the PIP/PBP item list is shown again */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x2f];
    unsigned char pbp_layout;                   /* +0x2F: the PBP layout (PBP_LAYOUT_*) */
};
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

/*
 * OK on 'Mode 1' (menu state 0x7F) of the PBP settings list: make Mode 1 the PBP layout and go back to the
 * PIP/PBP item list. osd_menu_key_table calls it for that state only; osd_select_pbp_mode2 is the same routine for
 * 'Mode 2' and differs in closing the menu when the layout changes.
 *
 * In order:
 *   1. osd_saved_choice_value is the row that carries the choice mark. When the open row (state - 0x7F) is a
 *      different one, that row's highlight is removed and its mark cleared.
 *   2. The new layout is 0 for state 0x7F, 1 for state 0x80 and the marked row for any other state. When it
 *      differs from the stored layout, it is stored, the output goes off, both channels restart and UserSetPIPMode
 *      applies it.
 *   3. The list is redrawn for the new layout: the open row's highlight removed, the mark drawn on the layout
 *      and the layout row highlighted, the key guide drawn.
 *   4. The menu state returns to 0x25, item row 2 of the item list is highlighted, the key guide is drawn again
 *      and osd_list_id is set to 5.
 */
void osd_select_pbp_mode1(void)
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
            sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
            UserSetPIPMode();
        }
    } else if (user_settings.pbp_layout != osd_saved_choice_value) {
        user_settings.pbp_layout = osd_saved_choice_value;
        panel_user_set_output_on(0);
        sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
        UserSetPIPMode();
    }
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
