/* osd_close_sharpness_slider  (FUN_a009645c)
 *
 * Close the Sharpness slider, store the value and go back to the item (OK)
 * Note: Returns to state 0x1A.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x6B
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009645c @ 0xa009645c (-mcpu=v8 -O2 -g)
 * Source form: the decompiler's six-parameter prototype is kept. Parameters 2 to 6 are passed on to the tail
 * call of osd_draw_sharpness_slider, which is declared without a parameter list. The callees are declared
 * without parameter lists.
 */
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern int osd_draw_sharpness_slider();
extern int sys_user_save_mode_slot();

#define MENU_STATE_SHARPNESS_ITEM 0x1a          /* Image page, item Sharpness (item row 2) */
#define SHARPNESS_ITEM_ROW        2             /* item row of the Sharpness item */
#define HIGHLIGHT_ITEM_ACTIVE     1             /* highlight style of an item row with the cursor in the item list */
#define SLIDER_EDITING            0             /* argument of the slider draw: 0 = the slider is no longer edited */

/*
 * OK on the open Sharpness slider: close it. The highlight of choice row 0 is cleared, the menu state returns to
 * the Sharpness item (0x1A) with its row highlighted, the picture settings are saved to the slot of the picture
 * mode (sys_user_save_mode_slot) and the slider is drawn again as not being edited.
 *
 * Parameters 2 to 6 are not used by the routine itself; they are passed on unchanged to
 * osd_draw_sharpness_slider.
 */
void osd_close_sharpness_slider(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_clear_choice_highlight(0);
  osd_menu_state = MENU_STATE_SHARPNESS_ITEM;
  osd_highlight_item_row(SHARPNESS_ITEM_ROW,HIGHLIGHT_ITEM_ACTIVE);
  sys_user_save_mode_slot();
  osd_draw_sharpness_slider(SLIDER_EDITING,forwarded_2,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
