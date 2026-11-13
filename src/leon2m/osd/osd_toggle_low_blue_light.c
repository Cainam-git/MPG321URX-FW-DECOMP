/* osd_toggle_low_blue_light  (FUN_a00961a4)
 *
 * Switch Low Blue Light on or off and re-apply the colours.
 * Note: Toggles bit 4 of settings word +0x11C (osd_flip_low_blue_light_setting).
 * Name basis: proven - handler table 0xA802422C: OK on state 0x16 = Professional item 'Low Blue Light' (texts
 *   0x188634)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00961a4 @ 0xa00961a4 (-mcpu=v8 -O3 -g)
 * Source form: the decompiler's six-parameter prototype is kept; all six are passed on to the tail call
 * of pq_user_apply_color_settings, which is declared without a parameter list. The callees are declared without
 * parameter lists.
 */
extern unsigned int osd_menu_state;
extern void osd_draw_professional_item_state();
extern int osd_flip_low_blue_light_setting();
extern int pq_user_apply_color_settings();

#define PAGE_PROFESSIONAL_ITEMS 0x15           /* first item state of the Professional page; item row = state - 0x15 */
#define HIGHLIGHT_ITEM_ACTIVE    1              /* highlight style of an item row with the cursor in the item list */

/*
 * OK on the Low Blue Light item of the Professional page: flip the setting (osd_flip_low_blue_light_setting also
 * redraws its switch and saves the mode slot), redraw the item's state for the present item row, and apply the
 * colour settings.
 *
 * The six parameters are not used by the routine itself; they are passed on unchanged to
 * pq_user_apply_color_settings.
 */
void osd_toggle_low_blue_light(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_flip_low_blue_light_setting();
  osd_draw_professional_item_state(osd_menu_state - PAGE_PROFESSIONAL_ITEMS & 0xff,HIGHLIGHT_ITEM_ACTIVE);
  pq_user_apply_color_settings(forwarded_1,forwarded_2,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
