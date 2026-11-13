/* osd_draw_adaptive_sync_switch  (FUN_a00b69d0)
 *
 * Draw the Adaptive-Sync switch of the Gaming page.
 * Note: Value = bit 7 of settings word +0xA8.
 * Name basis: derived - osd_draw_toggle_switch(5, ...); called by osd_draw_gaming_items
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b69d0 @ 0xa00b69d0, flags -mcpu=v8 -O3 -g.
 * Source form: the decompiler's declaration of osd_draw_toggle_switch without a prototype and the plain
 * 'return;' are kept.
 */
extern unsigned int user_settings_gaming_flags;   /* settings word +0xA8 */
extern int osd_draw_toggle_switch();

#define GAMING_ITEM_ADAPTIVE_SYNC 5   /* item row of the Gaming page */
#define GAMING_FLAG_ADAPTIVE_SYNC_BIT 7   /* bit of the gaming flags word: Adaptive-Sync on */

/* Draw the Adaptive-Sync switch (item row 5) of the Gaming page from bit 7 of the settings word at +0xA8.
 * Called by osd_draw_gaming_items. */
void osd_draw_adaptive_sync_switch(void)

{
  osd_draw_toggle_switch(GAMING_ITEM_ADAPTIVE_SYNC, user_settings_gaming_flags >> GAMING_FLAG_ADAPTIVE_SYNC_BIT & 1);
  return;
}
