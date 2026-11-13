/* osd_select_input_hdmi2  (FUN_a0096f40)
 *
 * Switch to the HDMI 2 input and close the menu, or go back if it is already active.
 * Note: Stores input_api_menu_index_to_source_id(1) in settings byte +0x1E, then osd_apply_input_change;
 *   'already active' compares input_api_source_id_to_menu_index of that byte with 1.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x1F; texts 0x196B24: HDMI 1, HDMI 2, DP, Type C,
 *   Auto Scan
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096f40 @ 0xa0096f40-0xa0096fe8 (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is reached through a struct pointer. The argument of
 * input_api_menu_index_to_source_id is the constant 1, and osd_apply_input_change is called with the two arguments
 * 0 and 1 as the firmware does (declared with two int parameters). One of four twins (HDMI 1 = 0, HDMI 2 = 1,
 * DP = 2, Type C = 3). The routine has no parameters.
 */
/* The field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1e];
    unsigned char input_source;                 /* +0x1E: the selected Input Source */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(int, int);
extern void osd_draw_input_item_state(unsigned char, int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_highlight_tab(int, int);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void osd_apply_input_change(int, int);

#define PAGE_INPUT_SOURCE_ITEMS 0x1e      /* first item state of the Input Source page; item row = state - 0x1E */
#define MENU_STATE_TAB_INPUT_SOURCE   6         /* menu state of the Input Source tab (tab 4, state = 2 + tab) */
#define TAB_INPUT_SOURCE              4
#define TAB_STYLE_CURSOR              1         /* osd_highlight_tab: the cursor is on the tabs */
#define HIGHLIGHT_ITEM_MODE_0         0         /* mode 0 of osd_highlight_item_row */
#define INPUT_HDMI_2                  1        /* the input of this routine, as passed to the two translation routines */

/*
 * OK on the HDMI 2 item of the Input Source page.
 *
 * When the translation of the stored input source (input_api_source_id_to_menu_index) already gives this input,
 * nothing is switched: the item row is un-highlighted and osd_draw_input_item_state is called for it, the item
 * row of the stored input is highlighted in mode 0, and the menu state returns to the Input Source tab (state 6) with the
 * tab highlighted and the key guide redrawn.
 *
 * Otherwise the Input Source setting is set to input_api_menu_index_to_source_id(INPUT_HDMI_2) and
 * osd_apply_input_change switches the display path to the new input and closes the menu.
 */
void osd_select_input_hdmi2(void)
{
    struct user_settings_record *settings = &user_settings;

    if (input_api_source_id_to_menu_index(settings->input_source) == INPUT_HDMI_2) {
        osd_clear_item_highlight(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS);
        osd_draw_input_item_state(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS, 0);
        osd_highlight_item_row(input_api_source_id_to_menu_index(settings->input_source), HIGHLIGHT_ITEM_MODE_0);
        osd_menu_state = MENU_STATE_TAB_INPUT_SOURCE;
        osd_highlight_tab(TAB_INPUT_SOURCE, TAB_STYLE_CURSOR);
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(0, 1);
    } else {
        settings->input_source = input_api_menu_index_to_source_id(INPUT_HDMI_2);
        osd_apply_input_change(0, 1);
    }
}
