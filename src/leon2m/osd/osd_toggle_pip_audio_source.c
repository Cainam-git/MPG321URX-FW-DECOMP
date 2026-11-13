/* osd_toggle_pip_audio_source  (FUN_a0097cc4)
 *
 * Switch the sound between the main and sub-window input (Audio Switch)
 * Note: Toggles bit 14 of settings word +0xA8 (audio_user_toggle_source), then returns to the PIP/PBP list.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x7E = 'Audio Switch'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097cc4 @ 0xa0097cc4 (-mcpu=v8 -O3 -g)
 * Source form: the decompiler's two-parameter prototype is kept; the return value is built with CONCAT44 from the
 * two parameters, which is the first parameter. The callees are declared without parameter lists.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned char osd_request_bits;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern void osd_draw_key_guide();
extern int osd_update_key_guide();
extern int audio_user_toggle_source();

#define MENU_STATE_PIP_LIST          0x7a       /* + row: the PIP settings list (Source, PIP Size, Location, ...) */
#define MENU_STATE_PIP_ITEM          0x24       /* PIP/PBP page, item PIP (item row 1) */
#define PIP_ITEM_ROW                 1          /* item row of the PIP item */
#define LIST_ID_PIP_PBP_ITEMS        5          /* value of osd_list_id set when the PIP/PBP item list is shown again */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * OK on Audio Switch in the PIP list (menu state 0x7E): toggle which picture's sound is played
 * (audio_user_toggle_source) and go back to the PIP item of the PIP/PBP list.
 *
 * The steps after the toggle are those of osd_leave_pip_settings: the highlight of the list row is cleared, the
 * menu state returns to 0x24 with its item row highlighted, the key guide is redrawn and osd_list_id becomes 5.
 * The settings-changed request bit is set at the end.
 *
 * The two parameters are not used; the routine returns them combined (the low half is param_1).
 */
int osd_toggle_pip_audio_source(unsigned int param_1,unsigned int param_2)

{
  audio_user_toggle_source();
  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PIP_LIST & 0xff);
  osd_draw_key_guide(1,2);
  osd_menu_state = MENU_STATE_PIP_ITEM;
  osd_highlight_item_row(PIP_ITEM_ROW,HIGHLIGHT_ITEM_ACTIVE);
  osd_draw_key_guide(1,2);
  osd_update_key_guide(0,1);
  osd_list_id = LIST_ID_PIP_PBP_ITEMS;
  osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
  return CONCAT44(param_2,param_1);
}
