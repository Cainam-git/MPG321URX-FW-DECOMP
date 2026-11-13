/* osd_open_sharpness_slider  (FUN_a0096420)
 *
 * Open the Sharpness slider (OK or right key)
 * Note: Menu state 0x6B.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x1A = 'Sharpness' (Image texts 0x18CA88)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096420 @ 0xa0096420 (-mcpu=v8 -O3 -g)
 * Source form: the decompiler's six-parameter prototype is kept. The last four are passed on to the tail call
 * of osd_highlight_choice_row, which is declared without a parameter list. The callees are declared without
 * parameter lists.
 */
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row();
extern int osd_highlight_choice_row();
extern int osd_draw_sharpness_slider();

#define PAGE_IMAGE_ITEMS  0x18       /* first item state of the Image page: Brightness (item row = state - 0x18) */
#define MENU_STATE_SHARPNESS_SLIDER  0x6b       /* the Sharpness slider is open */
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list or slider is open */
#define SLIDER_EDITING               1          /* argument of the slider draw: the slider is being edited */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row */

/*
 * OK or right on the Sharpness item: open its slider.
 *
 * The item row is highlighted in the "open" style, the menu state becomes 0x6B, the slider is drawn in editing
 * state and choice row 0 is highlighted.
 *
 * The first two parameters are not used; parameters 3 to 6 are passed on unchanged to osd_highlight_choice_row.
 */
void osd_open_sharpness_slider(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_highlight_item_row(osd_menu_state - PAGE_IMAGE_ITEMS & 0xff,HIGHLIGHT_ITEM_LIST_OPEN);
  osd_menu_state = MENU_STATE_SHARPNESS_SLIDER;
  osd_draw_sharpness_slider(SLIDER_EDITING);
  osd_highlight_choice_row(0,CHOICE_ROW_EDGED,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
