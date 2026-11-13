/* osd_close_brightness_slider  (FUN_a0096374)
 *
 * Close the Brightness slider, store the value and go back to the item (OK)
 * Note: Saves the picture slot (sys_user_save_mode_slot); returns to state 0x18.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x69 (opened from 'Brightness') (Image texts
 *   0x18CA88)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096374 @ 0xa0096374 (-mcpu=v8 -O2 -g)
 * Source form: the decompiler's six-parameter prototype is kept. Parameters 2 to 6 are passed on to the tail
 * call of osd_draw_brightness_slider, which is declared without a parameter list. The callees are declared
 * without parameter lists.
 */
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern int osd_draw_brightness_slider();
extern int sys_user_save_mode_slot();

#define MENU_STATE_BRIGHTNESS_ITEM 0x18         /* Image page, item Brightness (item row 0) */
#define BRIGHTNESS_ITEM_ROW        0            /* item row of the Brightness item */
#define HIGHLIGHT_ITEM_ACTIVE      1            /* highlight style of an item row with the cursor in the item list */
#define SLIDER_EDITING             0            /* argument of the slider draw: 0 = the slider is no longer edited */

/*
 * OK on the open Brightness slider: close it. The highlight of choice row 0 is cleared, the menu state returns to
 * the Brightness item (0x18) with its row highlighted, the picture settings are saved to the slot of the picture
 * mode (sys_user_save_mode_slot) and the slider is drawn again as not being edited.
 *
 * Parameters 2 to 6 are not used by the routine itself; they are passed on unchanged to
 * osd_draw_brightness_slider.
 */
void osd_close_brightness_slider(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_clear_choice_highlight(0);
  osd_menu_state = MENU_STATE_BRIGHTNESS_ITEM;
  osd_highlight_item_row(BRIGHTNESS_ITEM_ROW,HIGHLIGHT_ITEM_ACTIVE);
  sys_user_save_mode_slot();
  osd_draw_brightness_slider(SLIDER_EDITING,forwarded_2,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
