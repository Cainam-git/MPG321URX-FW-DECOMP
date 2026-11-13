/* osd_draw_info_on_screen_switch  (FUN_a00b7944)
 *
 * Draw the Info. On Screen switch of the Settings page.
 * Note: Value = bit 22 of settings word +0xAC.
 * Name basis: proven - row 5 of the Settings items (osd_draw_settings_items, first page)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7944 @ 0xa00b7944 (-mcpu=v8 -O3 -g).
 * Source form: two separate calls, each followed by a return (a single call with a computed value compiles
 * differently).
 */
#define SETTINGS_ITEM_INFO_ON_SCREEN 5          /* item number on the Settings page */
#define INFO_ON_SCREEN_BIT 0x400000             /* bit 22 of settings word +0xAC */

extern unsigned int user_settings_settings_page_flags;  /* settings word +0xAC */
extern int osd_draw_toggle_switch();

/* Draw the Info. On Screen switch: on when bit 22 of settings word +0xAC is set. */
void osd_draw_info_on_screen_switch(void)

{
  if ((user_settings_settings_page_flags & INFO_ON_SCREEN_BIT) != 0) {
    osd_draw_toggle_switch(SETTINGS_ITEM_INFO_ON_SCREEN,1);
    return;
  }
  osd_draw_toggle_switch(SETTINGS_ITEM_INFO_ON_SCREEN,0);
  return;
}
