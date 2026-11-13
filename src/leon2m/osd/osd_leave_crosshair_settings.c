/* osd_leave_crosshair_settings  (FUN_a00958c4)
 *
 * Leave the Smart Crosshair settings and return to the G.I. list (left key)
 * Name basis: derived - handler table 0xA802422C: left on states 0x3F..0x42
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00958c4, flags -mcpu=v8 -O3 -g.
 * Source form: the callees are declared without prototypes (osd_highlight_item_row takes two arguments, so the
 * routine has no parameters). The store of the menu state and the call of osd_highlight_item_row are written
 * once, after the if; the compiler copies them into both paths (written twice, the first copy would use another
 * register for 0xC).
 */
#define MENU_STATE_CROSSHAIR_ICON_ITEM  0x3f    /* Smart Crosshair items, Icon row (states 0x3F..0x42) */
#define MENU_STATE_CROSSHAIR_RESET_ITEM 0x42    /* Smart Crosshair items, Reset row */
#define MENU_STATE_GI_CROSSHAIR_ITEM    0x0c    /* G.I. page, item Smart Crosshair (item row 1) */
#define KEY_TEXT_MOVE                   0       /* key guide texts: Move, Enter */
#define KEY_TEXT_ENTER                  1

extern unsigned int osd_menu_state;
extern void osd_highlight_item_row();
extern void osd_clear_choice_highlight();
extern void osd_draw_key_guide();
extern void osd_update_key_guide();

/*
 * Left key in the Smart Crosshair items: leave them and return to the Smart Crosshair item of the G.I. page.
 * The highlight of the choice row (state - 0x3F) is cleared; when the menu state is the Reset item, the key
 * guide is drawn with Move and Enter. The menu state becomes the G.I. item and its row is highlighted.
 */
void osd_leave_crosshair_settings(void)
{
  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_CROSSHAIR_ICON_ITEM & 0xff);
  if (osd_menu_state == MENU_STATE_CROSSHAIR_RESET_ITEM) {
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
  }
  osd_menu_state = MENU_STATE_GI_CROSSHAIR_ITEM;
  osd_highlight_item_row(1, 1);
}
