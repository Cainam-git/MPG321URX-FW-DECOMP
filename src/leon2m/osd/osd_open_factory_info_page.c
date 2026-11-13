/* osd_open_factory_info_page  (FUN_a008d2e0)
 *
 * Draw the factory information page and set the menu state to 0x113.
 * Name basis: proven - calls osd_draw_factory_info_page, then osd_set_menu_state(0x113)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008d2e0, flags -mcpu=v8 -O2 -g.
 * Source form: the callees are declared without a parameter list; the five trailing arguments are handed to
 * osd_set_menu_state as the decompiler had them.
 */

#define MENU_STATE_FACTORY_INFO 0x113           /* the factory information page */

extern int osd_draw_factory_info_page();
extern int osd_set_menu_state();

/*
 * Draw the factory information page and set the menu state to 0x113. The arguments after the first are
 * handed on to osd_set_menu_state (which takes only the state); arg1 is not used.
 */
void osd_open_factory_info_page(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_draw_factory_info_page();
  osd_set_menu_state(MENU_STATE_FACTORY_INFO, arg2, arg3, arg4, arg5, arg6);
  return;
}
