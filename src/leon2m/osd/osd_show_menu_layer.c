/* osd_show_menu_layer  (FUN_a00a45a8)
 *
 * Switch the main menu layer on.
 * Note: Thin forwarder: osd_api_enable(1, 0).
 * Name basis: derived - osd_api_enable(1, 0); called after the menu pages are drawn
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a45a8 @ 0xa00a45a8, flags -mcpu=v8 -O2 -g.
 * Source form: Ghidra's type and symbol names are kept.
 */
extern int osd_api_enable();

/* Switch the menu layer (layer 0) on. Callers pass nothing; the second
 * argument of osd_api_enable is the layer number. */
void osd_show_menu_layer(void)

{
  osd_api_enable(1,0);
  return;
}
