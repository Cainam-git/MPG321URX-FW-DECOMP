/* osd_move_cursor_green_to_red  (FUN_a0096780)
 *
 * Move the gain editor cursor from the G row to the R row.
 * Note: State 0xCB -> 0xCA.
 * Name basis: derived - handler table 0xA802422C: up on state 0xCB
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096780 @ 0xa0096780 (-mcpu=v8 -O2 -g)
 * Source form: the decompiler's six-parameter prototype is kept. Parameters 2 to 6 are passed on to the tail
 * call of osd_draw_red_gain, which is declared without a parameter list. The callees are declared without
 * parameter lists.
 */
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern int osd_draw_green_gain();
extern int osd_draw_red_gain();

#define MENU_STATE_GAIN_EDITOR_RED   0xca       /* gain editor, red row (green 0xCB, blue 0xCC) */
#define GAIN_ROW_RED                 0          /* choice row of the red gain in the editor (green 1, blue 2) */
#define GAIN_ROW_GREEN               1
#define GAIN_ACTIVE                  1          /* argument of the gain draw: this is the row being edited */
#define GAIN_INACTIVE                0
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * Cursor move in the gain editor from the green row to the red row: the menu state becomes 0xCA, the highlight
 * of choice row 1 is cleared, the green gain is drawn as not being edited, row 0 is highlighted and the red gain
 * is drawn as the edited row.
 *
 * Parameters 2 to 6 are not used by the routine itself; they are passed on unchanged to osd_draw_red_gain.
 */
void osd_move_cursor_green_to_red(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_menu_state = MENU_STATE_GAIN_EDITOR_RED;
  osd_clear_choice_highlight(GAIN_ROW_GREEN);
  osd_draw_green_gain(GAIN_INACTIVE);
  osd_highlight_choice_row(GAIN_ROW_RED,CHOICE_ROW_EDGED);
  osd_draw_red_gain(GAIN_ACTIVE,forwarded_2,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
