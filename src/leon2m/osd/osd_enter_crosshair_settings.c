/* osd_enter_crosshair_settings  (FUN_a0095930)
 *
 * Open the Smart Crosshair settings (Icon, Color, Position, Reset)
 * Note: Saves the current icon byte +0x190 in 0xA8025C56; state 0x3F.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x0C = 'Smart Crosshair' (texts 0x18A360)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095930 @ 0xa0095930 (-mcpu=v8 -O3 -g)
 * Source form: the decompiler's six-parameter prototype is kept, because the last four are forwarded to
 * osd_highlight_choice_row, which is declared without a parameter list.
 */
extern unsigned char osd_choice_row;
extern unsigned char user_settings_crosshair_icon;
extern unsigned int osd_menu_state;
extern int osd_draw_choice_mark();
extern void osd_highlight_item_row();
extern int osd_highlight_choice_row();

#define MENU_STATE_CROSSHAIR_SETTINGS 0x3f      /* Smart Crosshair items, first row (Icon) */
#define GI_ITEM_STATE_BASE 0xb                  /* G.I. page item state minus this = item row (state 0x0C = row 1) */

/*
 * Open the Smart Crosshair settings (Icon, Color, Position, Reset) from the G.I. page item (OK or right key in
 * menu state 0x0C). The current icon is saved in osd_choice_row. The item row (menu state minus 0x0B) is
 * left highlighted as the parent of the open list, the menu state becomes 0x3F and the first row (Icon) is
 * highlighted.
 *
 * The six parameters are not used by the routine itself; the last four are passed on unchanged to
 * osd_highlight_choice_row.
 */
void osd_enter_crosshair_settings(unsigned int unused_1,unsigned int unused_2,unsigned int forwarded_3,unsigned int forwarded_4,
                 unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_choice_row = user_settings_crosshair_icon;
  osd_highlight_item_row(osd_menu_state - GI_ITEM_STATE_BASE & 0xff,2);
  osd_menu_state = MENU_STATE_CROSSHAIR_SETTINGS;
  osd_draw_choice_mark(1,0,0);
  osd_highlight_choice_row(0,1,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
