/* osd_open_menu_state_0x106  (FUN_a0090fac)
 *
 * Set menu state 0x106 and draw its window.
 * Note: Called after the service commands that store window positions.
 * Name basis: descriptive - state number and the draw call only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0090fac, flags -mcpu=v8 -O2 -g.
 */

#define MENU_STATE_SCREEN_OVERLAYS 0x106        /* the overlay screen: crosshair, alarm timer, refresh rate counter */

extern unsigned int osd_menu_state;
extern int osd_show_screen_overlays();

/* Set the menu state to 0x106 and draw the screen overlays. */
void osd_open_menu_state_0x106(void)

{
  osd_menu_state = MENU_STATE_SCREEN_OVERLAYS;
  osd_show_screen_overlays(1);
  return;
}
