/* osd_set_menu_state  (FUN_a0090fa0)
 *
 * Set the current menu state (page or item code)
 *   state: menu state, 0 = closed
 * Note: Word 0xA802AFEC.
 * Name basis: derived - 0 = closed (osd_close_menu), 0x10D closed by OSDCloseWhenSyncDet, 0x111..0x113 factory
 *   pages
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0090fa0, flags -mcpu=v8 -O2 -g.
 */

extern unsigned int osd_menu_state;

/* Set the menu state (the screen the menu is on; 0 = closed). */
void osd_set_menu_state(unsigned int state)

{
  osd_menu_state = state;
  return;
}
