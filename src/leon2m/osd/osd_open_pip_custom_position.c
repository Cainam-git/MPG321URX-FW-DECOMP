/* osd_open_pip_custom_position  (FUN_a0093b04)
 *
 * Open the free positioning of the PIP window (Customize location)
 * Note: Hides the menu layer and sets state 0x107.
 * Name basis: derived - OK/right on state 0xDC = 'Customize' of the PIP location list (texts 0x18E9F8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093b04, flags -mcpu=v8 -O3 -g.
 * Source form: the routine takes six unsigned int parameters; the last four are passed on to osd_api_enable,
 * which is declared without a prototype, as in the firmware. The callees have no prototypes either.
 */
#define MENU_STATE_PIP_CUSTOM_POSITION 0x107    /* free positioning of the PIP window */
#define KEY_TEXT_MOVE                  0        /* key guide texts: Move, Enter */
#define KEY_TEXT_ENTER                 1

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned int user_settings_pip_location;
extern void osd_draw_choice_mark();
extern int osd_clear_choice_highlight();
extern void osd_draw_key_guide();
extern void osd_highlight_choice_row();
extern int osd_update_key_guide();
extern int osd_api_enable();

/*
 * OK key on the Customize entry of the PIP Location choices: start the free positioning of the PIP window.
 * The highlight and the mark of the row in osd_edit_value are cleared, the PIP location (bits 4 to 7 of settings
 * word +0x30) becomes the new osd_edit_value and its row is highlighted, the key guide is drawn with Move and
 * Enter, the menu state becomes 0x107 and the menu layer 0 is switched off (osd_api_enable: first argument 0 = off, second = layer).
 * Parameters 3 to 6 are passed on to osd_api_enable; parameters 1 and 2 are not used.
 */
void osd_open_pip_custom_position(unsigned int unused_1, unsigned int unused_2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  unsigned int location;
  
  osd_clear_choice_highlight(osd_edit_value);
  osd_draw_choice_mark(1,osd_edit_value,0);
  location = user_settings_pip_location >> 4 & 0xf;
  osd_edit_value = (unsigned char)location;
  osd_highlight_choice_row(location,1);
  osd_draw_key_guide(1,2);
  osd_update_key_guide(KEY_TEXT_MOVE,KEY_TEXT_ENTER);
  osd_menu_state = MENU_STATE_PIP_CUSTOM_POSITION;
  osd_api_enable(0,0,arg3,arg4,arg5,arg6);
  return;
}
