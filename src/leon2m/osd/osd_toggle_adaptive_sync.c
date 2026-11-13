/* osd_toggle_adaptive_sync  (FUN_a0095acc)
 *
 * Switch Adaptive-Sync on or off and redraw the item (OK key)
 * Note: Toggles bit 7 of the settings word +0xA8 (osd_switch_adaptive_sync).
 * Name basis: proven - handler table 0xA802422C: OK on state 0x13 = Gaming item 'Adaptive-Sync' (texts
 *   0x188DA0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095acc, flags -mcpu=v8 -O3 -g.
 * Source form: the routine takes six unsigned int parameters, all passed on to
 * osd_draw_adaptive_sync_status, which is declared without a prototype, as in the firmware.
 */
#define MENU_STATE_GAME_ITEMS_BASE 0x0e         /* menu state of the first Gaming item (Game Mode) */

extern unsigned int osd_menu_state;
extern void osd_draw_gaming_item_state();
extern int osd_draw_adaptive_sync_status();
extern int osd_switch_adaptive_sync();

/*
 * OK key on the Adaptive-Sync item of the Gaming page (menu state 0x13): switch Adaptive-Sync with
 * osd_switch_adaptive_sync, redraw the switch state of the item (item row = menu state - 0x0E), and redraw the
 * Adaptive-Sync status line. The six parameters are passed on to osd_draw_adaptive_sync_status.
 */
void osd_toggle_adaptive_sync(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_switch_adaptive_sync();
  osd_draw_gaming_item_state(osd_menu_state - MENU_STATE_GAME_ITEMS_BASE & 0xff,1);
  osd_draw_adaptive_sync_status(arg1,arg2,arg3,arg4,arg5,arg6);
  return;
}
