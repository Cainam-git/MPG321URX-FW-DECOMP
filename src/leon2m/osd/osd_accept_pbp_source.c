/* osd_accept_pbp_source  (FUN_a00951a8)
 *
 * Store the highlighted input for PBP Source 1 or 2, then go back or switch the input (OK)
 * Note: Source 1 = settings byte +0x1E, Source 2 = +0x20, by settings byte +0x1A3; a changed Source 1 ends in
 *   osd_apply_input_change without a new state, else state 0x82 / 0x83.
 * Name basis: derived - handler table 0xA802422C: OK on states 0xD4..0xD7; texts 0x182534 'Source 1' / 'Source
 *   2'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00951a8 @ 0xa00951a8-0xa009530c (89 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table). Source form: the clear of overlay_target comes before the |= on osd_request_bits in the source
 * (the build schedules the |= first); the source-1 arm calls input_api_menu_index_to_source_id twice.
 */
struct user_settings_record {
    unsigned char pad0[0x1e];
    unsigned char input_source;                 /* +0x1E: the input of the main picture (PBP Source 1) */
    unsigned char pad1f;
    unsigned char second_source;                /* +0x20: the input of the second picture (PBP Source 2) */
    unsigned char pad21[0x1a3 - 0x21];
    unsigned char source_slot;                  /* +0x1A3: 0 = editing Source 1, else Source 2 */
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_saved_choice_value;
extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned char osd_list_id;
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void osd_apply_input_change(void);
extern void sys_user_apply_pip_sources(unsigned char);
extern void osd_clear_choice_column(void);
extern void osd_draw_pbp_items(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

#define MENU_STATE_PBP_SOURCE_1 0x82            /* menu state of the PBP Source 1 item */
#define MENU_STATE_PBP_SOURCE_2 0x83            /* menu state of the PBP Source 2 item */

/*
 * OK on a row of the PBP source list (menu states 0xD4..0xD7, reached through the handler table). The row is
 * the menu state minus 0xD4; input_api_menu_index_to_source_id turns it into the value stored as the input.
 * user_settings.source_slot says which source is being chosen: 0 = Source 1 (input_source), else Source 2
 * (second_source).
 *
 * Source 1: if the chosen input differs from the present one it is stored and osd_apply_input_change switches
 * to it (that routine closes the menu); the page is not redrawn then. If it is the same input, the menu goes
 * back to the PBP items with state 0x82.
 * Source 2: the chosen input is stored; when it changed, sys_user_apply_pip_sources(1) applies it. The menu
 * then goes back to the PBP items with state 0x83.
 * Going back means: list id 0x10, choice column cleared, PBP items redrawn, the saved choice row
 * un-highlighted and marked, row 3 (Source 1) or 4 (Source 2) highlighted, and osd_edit_value set to the
 * screen_size byte. At the end source_slot is cleared and the settings-changed request is made.
 */
void osd_accept_pbp_source(void)
{
    unsigned char old_second_source = user_settings.second_source;

    if (user_settings.source_slot == 0) {
        if (user_settings.input_source != input_api_menu_index_to_source_id(osd_menu_state + 0x2c)) {
            user_settings.input_source = input_api_menu_index_to_source_id(osd_menu_state + 0x2c);
            osd_apply_input_change();
        } else {
            osd_list_id = 0x10;
            osd_clear_choice_column();
            osd_draw_pbp_items();
            osd_highlight_choice_row(osd_saved_choice_value, 2);
            osd_draw_choice_mark(1, osd_saved_choice_value, 1);
            osd_highlight_choice_row(3, 3);
            osd_menu_state = MENU_STATE_PBP_SOURCE_1;
            osd_edit_value = user_settings.screen_size;
        }
    } else {
        user_settings.second_source = input_api_menu_index_to_source_id(osd_menu_state + 0x2c);
        if (user_settings.second_source != old_second_source)
            sys_user_apply_pip_sources(1);
        osd_list_id = 0x10;
        osd_clear_choice_column();
        osd_draw_pbp_items();
        osd_highlight_choice_row(osd_saved_choice_value, 2);
        osd_draw_choice_mark(1, osd_saved_choice_value, 1);
        osd_highlight_choice_row(4, 3);
        osd_menu_state = MENU_STATE_PBP_SOURCE_2;
        osd_edit_value = user_settings.screen_size;
    }
    user_settings.source_slot = 0;
    osd_request_bits |= 2;
}
