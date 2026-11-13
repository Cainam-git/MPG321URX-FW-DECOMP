/* osd_accept_crosshair_icon  (FUN_a0095984)
 *
 * Keep the chosen crosshair icon and go back to the crosshair settings (OK)
 * Note: Returns to state 0x3F.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x43
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095984, flags -mcpu=v8 -O3 -g.
 * Source form: the routine takes two unsigned int parameters and returns the first one; the callees are
 * declared without prototypes.
 */
#define MENU_STATE_CROSSHAIR_ICON_ITEM 0x3f     /* Smart Crosshair items, Icon row (item row 0) */
#define OSD_REQUEST_SETTINGS_CHANGED   0x02     /* bit of osd_request_bits */
#define KEY_TEXT_MOVE                  0        /* key guide texts: Move, Enter */
#define KEY_TEXT_ENTER                 1

extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_draw_crosshair_items();
extern int osd_clear_choice_column();
extern void osd_draw_key_guide();
extern void osd_highlight_choice_row();
extern int osd_draw_key_guide_text();
extern void osd_update_key_guide();
extern void osd_api_set_window_enable();

/*
 * OK key in the Smart Crosshair icon choices: back to the Smart Crosshair items. The choice column is cleared,
 * windows 3 and 4 are switched off, the items are drawn, the menu state becomes the Icon item with its row
 * highlighted, the key guide is drawn (Move and Enter, then key guide text 7), and the settings-changed
 * request is made. Returns its first parameter; the second is not used.
 */
int osd_accept_crosshair_icon(unsigned int first_arg, unsigned int unused)

{
  osd_clear_choice_column();
  osd_api_set_window_enable(3,0,0);
  osd_api_set_window_enable(4,0,0);
  osd_draw_crosshair_items();
  osd_menu_state = MENU_STATE_CROSSHAIR_ICON_ITEM;
  osd_highlight_choice_row(0,1);
  osd_draw_key_guide(2,5);
  osd_draw_key_guide(0,0);
  osd_draw_key_guide(1,2);
  osd_update_key_guide(KEY_TEXT_MOVE,KEY_TEXT_ENTER);
  osd_draw_key_guide_text(7);
  osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
  return first_arg;
}
