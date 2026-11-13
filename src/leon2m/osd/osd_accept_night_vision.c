/* osd_accept_night_vision  (FUN_a0095b58)
 *
 * Leave the Night Vision list on OK: move highlight and mark, go back, save the picture slot.
 * Note: Does not write the Night Vision setting; returns to state 0x0F and ends in sys_user_save_mode_slot.
 * Name basis: derived - handler table 0xA802422C: OK on states 0x4E..0x52
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095b58 @ 0xa0095b58 (-mcpu=v8 -O3 -g)
 * Source form: the decompiler's two-parameter prototype is kept; both are passed on to the tail call of
 * sys_user_save_mode_slot, which is declared without a parameter list. osd_menu_state is declared volatile.
 */
extern unsigned char osd_choice_row;
extern unsigned char user_settings_night_vision;
extern volatile unsigned int osd_menu_state;
extern int osd_draw_choice_mark();
extern void osd_highlight_item_row();
extern void osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern void osd_draw_adaptive_sync_status();
extern unsigned char sys_user_save_mode_slot();

#define MENU_STATE_NIGHT_VISION_LIST 0x4e       /* first state of the Night Vision list (states 0x4E..0x52, one per level) */
#define MENU_STATE_NIGHT_VISION_ITEM 0xf        /* Night Vision item of the picture page */

/*
 * OK in the Night Vision list (menu states 0x4E..0x52, reached through the handler table). The routine does not
 * write the Night Vision setting itself. It takes the highlight off the row in osd_choice_row and unmarks it,
 * highlights the row of the present state (state minus 0x4E), marks the row of the stored Night Vision
 * level, leaves the list (menu state 0x0F, item row 1 highlighted) and redraws the Adaptive-Sync status line.
 * It ends by tail-calling sys_user_save_mode_slot, which copies the picture settings into the slot of a
 * picture mode.
 *
 * The two parameters are not used by the routine itself; they are passed on unchanged to
 * sys_user_save_mode_slot.
 */
void osd_accept_night_vision(int forwarded_1, unsigned int forwarded_2)

{
  osd_clear_choice_highlight(osd_choice_row);
  osd_draw_choice_mark(1,osd_choice_row,0);
  osd_highlight_choice_row(osd_menu_state - MENU_STATE_NIGHT_VISION_LIST & 0xff,0);
  osd_draw_choice_mark(1,user_settings_night_vision,1);
  osd_menu_state = MENU_STATE_NIGHT_VISION_ITEM;
  osd_highlight_item_row(1,1);
  osd_draw_adaptive_sync_status();
  sys_user_save_mode_slot(forwarded_1,forwarded_2);
  return;
}
