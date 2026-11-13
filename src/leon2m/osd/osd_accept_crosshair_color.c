/* osd_accept_crosshair_color  (FUN_a00956a0)
 *
 * Keep the highlighted crosshair colour and go back (OK)
 * Note: States 0xED..0xEF = White, Red, Auto; returns to 'Color' (0x40).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xED..0xEF; texts 0x18E54C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00956a0, flags -mcpu=v8 -O3 -g.
 * Source form: the routine takes two unsigned int parameters and returns the first one; the callees are
 * declared without prototypes.
 */
#define MENU_STATE_CROSSHAIR_COLOR_ITEM 0x40    /* Smart Crosshair items, Color row (item row 1) */
#define OSD_REQUEST_SETTINGS_CHANGED    0x02    /* bit of osd_request_bits */
#define KEY_TEXT_MOVE                   0       /* key guide texts: Move, Enter */
#define KEY_TEXT_ENTER                  1

extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern int osd_draw_crosshair_items();
extern int osd_clear_choice_column();
extern void osd_draw_key_guide();
extern void osd_highlight_choice_row();
extern int osd_update_key_guide();
extern int osd_update_crosshair_color();

/*
 * OK key in the Smart Crosshair Color choices: back to the Smart Crosshair items. The choice column is cleared,
 * the items are drawn, osd_update_crosshair_color(1) recolours the crosshair, the menu state becomes the Color
 * item with its row highlighted, the key guide is drawn with Move and Enter, and the settings-changed request
 * is made. Returns its first parameter; the second is not used.
 */
int osd_accept_crosshair_color(unsigned int first_arg, unsigned int unused)

{
  osd_clear_choice_column();
  osd_draw_crosshair_items();
  osd_update_crosshair_color(1);
  osd_menu_state = MENU_STATE_CROSSHAIR_COLOR_ITEM;
  osd_highlight_choice_row(1,1);
  osd_draw_key_guide(1,2);
  osd_update_key_guide(KEY_TEXT_MOVE,KEY_TEXT_ENTER);
  osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
  return first_arg;
}
