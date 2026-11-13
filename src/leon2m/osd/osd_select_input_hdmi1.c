/* osd_select_input_hdmi1  (FUN_a0096e9c)
 *
 * Switch to the HDMI 1 input and close the menu, or go back if it is already active.
 * Note: Stores input_api_menu_index_to_source_id(0) in settings byte +0x1E, then osd_apply_input_change;
 *   'already active' compares input_api_source_id_to_menu_index of that byte with 0.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x1E; texts 0x196B24: HDMI 1, HDMI 2, DP, Type C,
 *   Auto Scan
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096e9c @ 0xa0096e9c-0xa0096f40 (164 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a byte array; the callees are declared with byte parameters, and
 * osd_apply_input_change is declared and called without arguments (its twins pass 0 and 1). One of four twins
 * (HDMI 1 = 0, HDMI 2 = 1, DP = 2, Type C = 3). The routine has no parameters.
 */
extern unsigned char user_settings[];
extern unsigned int osd_menu_state;
extern unsigned char input_api_source_id_to_menu_index(unsigned char x);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void osd_clear_item_highlight(unsigned char);
extern void osd_draw_input_item_state(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_draw_key_guide(unsigned char sel, unsigned char mode);
extern void osd_update_key_guide(unsigned char hi, unsigned char lo);
extern void osd_apply_input_change(void);

#define USER_SETTINGS_INPUT_SOURCE    0x1e      /* offset of the Input Source byte in the settings record */
#define PAGE_INPUT_SOURCE_ITEMS 0x1e      /* first item state of the Input Source page; item row = state - 0x1E */
#define MENU_STATE_TAB_INPUT_SOURCE   6         /* menu state of the Input Source tab (tab 4, state = 2 + tab) */
#define TAB_INPUT_SOURCE              4
#define TAB_STYLE_CURSOR              1         /* osd_highlight_tab: the cursor is on the tabs */
#define HIGHLIGHT_ITEM_MODE_0         0         /* mode 0 of osd_highlight_item_row */
#define INPUT_HDMI_1                  0         /* the input of this routine, as passed to the two translation routines */

/*
 * OK on the HDMI 1 item of the Input Source page.
 *
 * When the translation of the stored input source (input_api_source_id_to_menu_index) already gives this input,
 * nothing is switched: the item row is un-highlighted and osd_draw_input_item_state is called for it, the item
 * row of the stored input is highlighted in mode 0, and the menu state returns to the Input Source tab (state 6) with the
 * tab highlighted and the key guide redrawn.
 *
 * Otherwise the Input Source setting is set to input_api_menu_index_to_source_id(INPUT_HDMI_1) and
 * osd_apply_input_change switches the display path to the new input and closes the menu.
 */
void osd_select_input_hdmi1(void)
{
    if (input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_INPUT_SOURCE]) == INPUT_HDMI_1) {
        osd_clear_item_highlight(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS);
        osd_draw_input_item_state(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS, 0);
        osd_highlight_item_row(input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_INPUT_SOURCE]), HIGHLIGHT_ITEM_MODE_0);
        osd_menu_state = MENU_STATE_TAB_INPUT_SOURCE;
        osd_highlight_tab(TAB_INPUT_SOURCE, TAB_STYLE_CURSOR);
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(0, 1);
    } else {
        user_settings[USER_SETTINGS_INPUT_SOURCE] = input_api_menu_index_to_source_id(INPUT_HDMI_1);
        osd_apply_input_change();
    }
}
