/* osd_close_factory_info_page  (FUN_a008b330)
 *
 * Close the menu when a factory information page (state 0x113 or 0x114) is open.
 *   param_1: passed through
 * Returns: param_1, or the result of osd_close_menu
 * Name basis: derived - tests osd_get_menu_state for 0x113 (set after osd_draw_factory_info_page) / 0x114,
 *   calls osd_close_menu
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008b330, flags -mcpu=v8 -O3 -g.
 * Source form: the decompiler's six-argument form is kept; the callee osd_close_menu is declared without a
 * parameter list and the no-close path returns the 64-bit join of arg2 and arg1 (CONCAT44), which the int
 * result takes the low word of.
 */

typedef unsigned long long ulonglong;
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

#define MENU_STATE_FACTORY_INFO       0x113     /* the factory information page */
#define MENU_STATE_FACTORY_INFO_DONE  0x114

extern unsigned short osd_get_menu_state();
extern int osd_close_menu();

/*
 * Close the menu when it is on the factory information page (state 0x113 or 0x114). Otherwise do nothing.
 * The six arguments are handed on unchanged to osd_close_menu (which takes none); when the menu is not closed,
 * arg1 is returned.
 */
int osd_close_factory_info_page(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
            unsigned int arg5, unsigned int arg6)

{
  unsigned short menu_state;

  menu_state = osd_get_menu_state();
  if ((menu_state != MENU_STATE_FACTORY_INFO) && (menu_state = osd_get_menu_state(), menu_state != MENU_STATE_FACTORY_INFO_DONE)) {
    return CONCAT44(arg2, arg1);
  }
  return osd_close_menu(arg1, arg2, arg3, arg4, arg5, arg6);
}
