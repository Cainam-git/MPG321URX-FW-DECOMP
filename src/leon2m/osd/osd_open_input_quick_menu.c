/* osd_open_input_quick_menu  (FUN_a0091648)
 *
 * Open the input quick menu (state 0xFE) and show the menu layer.
 * Note: Nothing refers to it; osd_dispatch_key_event opens the same menu inline when a key is pressed without
 *   a signal.
 * Name basis: derived - state 0xFE: OK = osd_accept_input_quick_menu (handler table);
 *   osd_draw_input_quick_menu draws the input names 0x196B24
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091648, flags -mcpu=v8 -O2 -g.
 * Source form: the callees are declared without a parameter list; the six arguments are handed to
 * osd_show_menu_layer as the decompiler had them.
 */

#define MENU_STATE_INPUT_QUICK_MENU 0xfe        /* the input quick menu */

extern unsigned int osd_menu_state;
extern int osd_show_menu_layer();
extern int osd_draw_input_quick_menu();

/*
 * Open the input quick menu: set the menu state to 0xFE, draw the menu and switch the menu layer on. The six
 * arguments are handed on to osd_show_menu_layer (which takes none).
 */
void osd_open_input_quick_menu(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_menu_state = MENU_STATE_INPUT_QUICK_MENU;
  osd_draw_input_quick_menu();
  osd_show_menu_layer(arg1, arg2, arg3, arg4, arg5, arg6);
  return;
}
