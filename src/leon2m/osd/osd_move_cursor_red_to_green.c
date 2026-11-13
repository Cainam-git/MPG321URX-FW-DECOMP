/* osd_move_cursor_red_to_green  (FUN_a0096704)
 *
 * Move the gain editor cursor from the R row to the G row.
 * Note: State 0xCA -> 0xCB.
 * Name basis: derived - handler table 0xA802422C: OK/down on state 0xCA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096704 @ 0xa0096704 (-mcpu=v8 -O2 -g)
 * Source form: the decompiler's six-parameter prototype is kept. Parameters 2 to 6 are passed on to the tail
 * call of osd_draw_green_gain, which is declared without a parameter list. The callees are declared without
 * parameter lists.
 */
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern int osd_draw_green_gain();
extern int osd_draw_red_gain();

#define MENU_STATE_GAIN_EDITOR_GREEN 0xcb       /* gain editor, green row (red 0xCA, blue 0xCC) */
#define GAIN_ROW_RED                 0          /* choice row of the red gain in the editor (green 1, blue 2) */
#define GAIN_ROW_GREEN               1
#define GAIN_ACTIVE                  1          /* argument of the gain draw: this is the row being edited */
#define GAIN_INACTIVE                0
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * Cursor move in the gain editor from the red row to the green row: the menu state becomes 0xCB, the highlight
 * of choice row 0 is cleared, the red gain is drawn as not being edited, row 1 is highlighted and the green gain
 * is drawn as the edited row.
 *
 * Parameters 2 to 6 are not used by the routine itself; they are passed on unchanged to osd_draw_green_gain.
 */
void osd_move_cursor_red_to_green(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_menu_state = MENU_STATE_GAIN_EDITOR_GREEN;
  osd_clear_choice_highlight(GAIN_ROW_RED);
  osd_draw_red_gain(GAIN_INACTIVE);
  osd_highlight_choice_row(GAIN_ROW_GREEN,CHOICE_ROW_EDGED);
  osd_draw_green_gain(GAIN_ACTIVE,forwarded_2,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
