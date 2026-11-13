/* osd_move_cursor_blue_to_green  (FUN_a00967b8)
 *
 * Move the gain editor cursor from the B row to the G row.
 * Note: State 0xCC -> 0xCB.
 * Name basis: derived - handler table 0xA802422C: up on state 0xCC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00967b8 @ 0xa00967b8 (-mcpu=v8 -O2 -g)
 * Source form: the decompiler's six-parameter prototype is kept. Parameters 2 to 6 are passed on to the tail
 * call of osd_draw_green_gain, which is declared without a parameter list. The callees are declared without
 * parameter lists.
 */
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern int osd_draw_blue_gain();
extern int osd_draw_green_gain();

#define MENU_STATE_GAIN_EDITOR_GREEN 0xcb       /* gain editor, green row (red 0xCA, blue 0xCC) */
#define GAIN_ROW_GREEN               1          /* choice row of the green gain in the editor (red 0, blue 2) */
#define GAIN_ROW_BLUE                2
#define GAIN_ACTIVE                  1          /* argument of the gain draw: this is the row being edited */
#define GAIN_INACTIVE                0
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * Cursor move in the gain editor from the blue row to the green row: the menu state becomes 0xCB, the highlight
 * of choice row 2 is cleared, the blue gain is drawn as not being edited, row 1 is highlighted and the green gain
 * is drawn as the edited row.
 *
 * Parameters 2 to 6 are not used by the routine itself; they are passed on unchanged to osd_draw_green_gain.
 */
void osd_move_cursor_blue_to_green(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_menu_state = MENU_STATE_GAIN_EDITOR_GREEN;
  osd_clear_choice_highlight(GAIN_ROW_BLUE);
  osd_draw_blue_gain(GAIN_INACTIVE);
  osd_highlight_choice_row(GAIN_ROW_GREEN,CHOICE_ROW_EDGED);
  osd_draw_green_gain(GAIN_ACTIVE,forwarded_2,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
