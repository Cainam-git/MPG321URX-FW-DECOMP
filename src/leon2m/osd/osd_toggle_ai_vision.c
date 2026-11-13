/* osd_toggle_ai_vision  (FUN_a0099440)
 *
 * Switch AI Vision on or off and redraw the item.
 * Note: Toggles bit 15 of settings word +0x174.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x10 = Gaming item 'AI Vision' (texts 0x188DA0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099440 @ 0xa0099440-0xa00994b8 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: an if/else of the '&= ~mask' and '|= mask' forms on the word (a 1-bit bit-field gives different
 * instructions); the RAM byte osd_request_bits is not volatile.
 */
/* The settings word +0x174; bit 15 is the AI Vision switch. */
struct user_settings_record { unsigned char pad[0x174]; unsigned int word_0x174; };
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_draw_gaming_item_state(unsigned char, int);
extern void osd_draw_item_row_state(int, int);
extern void ldc_user_apply_grid_enable(void);

#define SETTINGS_AI_VISION       0x8000 /* bit 15 of settings word +0x174 */
#define MENU_STATE_GAME_ITEMS_BASE 0x0e /* menu state of the first Gaming item (Game Mode) */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the AI Vision item of the Gaming page: flip the switch (bit 15 of settings word +0x174), redraw the
 * item's switch state (the item row is the menu state minus 0x0E) and the row, apply the grid setting
 * (ldc_user_apply_grid_enable) and report a settings change.
 */
void osd_toggle_ai_vision(void)
{
  if (user_settings.word_0x174 & SETTINGS_AI_VISION)
    user_settings.word_0x174 &= ~SETTINGS_AI_VISION;
  else
    user_settings.word_0x174 |= SETTINGS_AI_VISION;
  osd_draw_gaming_item_state(osd_menu_state - MENU_STATE_GAME_ITEMS_BASE, 1);
  osd_draw_item_row_state(1, 1);
  ldc_user_apply_grid_enable();
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
