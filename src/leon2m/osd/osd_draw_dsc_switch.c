/* osd_draw_dsc_switch  (FUN_a00b6b68)
 *
 * Draw the DSC switch of the Gaming page.
 * Note: Value = bit 31 of settings word +0x1F4.
 * Name basis: derived - osd_draw_toggle_switch(6, ...); called by osd_draw_gaming_items
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6b68 @ 0xa00b6b68 (-mcpu=v8 -O2 -g)
 */
#define GAMING_ITEM_DSC 6                       /* item number of the DSC switch on the Gaming page */

extern unsigned int user_settings_word_0x1f4;   /* settings word +0x1F4; bit 31 is the DSC switch */
extern int osd_draw_toggle_switch();

/* Draw the DSC switch: the switch shows bit 31 of settings word +0x1F4. */
void osd_draw_dsc_switch(void)

{
  osd_draw_toggle_switch(GAMING_ITEM_DSC,user_settings_word_0x1f4 >> 0x1f);
  return;
}
