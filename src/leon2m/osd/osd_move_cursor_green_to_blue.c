/* osd_move_cursor_green_to_blue  (FUN_a009673c)
 *
 * Move the gain editor cursor from the G row to the B row.
 * Note: State 0xCB -> 0xCC.
 * Name basis: derived - handler table 0xA802422C: OK/down on state 0xCB
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009673c @ 0xa009673c (-mcpu=v8 -O2 -g)
 * Source form: the decompiler's six-parameter prototype is kept. Parameters 3 to 6 are passed on to the tail
 * call of osd_update_key_guide, which is declared without a parameter list. The callees are declared without
 * parameter lists.
 */
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern void osd_highlight_choice_row();
extern int osd_draw_blue_gain();
extern int osd_draw_green_gain();
extern int osd_update_key_guide();

#define MENU_STATE_GAIN_EDITOR_BLUE  0xcc       /* gain editor, blue row (red 0xCA, green 0xCB) */
#define GAIN_ROW_GREEN               1          /* choice row of the green gain in the editor (red 0, blue 2) */
#define GAIN_ROW_BLUE                2
#define GAIN_ACTIVE                  1          /* argument of the gain draw: this is the row being edited */
#define GAIN_INACTIVE                0
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * Cursor move in the gain editor from the green row to the blue row: the menu state becomes 0xCC, the highlight
 * of choice row 1 is cleared, the green gain is drawn as not being edited, row 2 is highlighted, the blue gain is
 * drawn as the edited row and the key guide texts 3 and 5 are shown (osd_update_key_guide).
 *
 * Parameters 3 to 6 are not used by the routine itself; they are passed on unchanged to osd_update_key_guide.
 */
void osd_move_cursor_green_to_blue(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  osd_menu_state = MENU_STATE_GAIN_EDITOR_BLUE;
  osd_clear_choice_highlight(GAIN_ROW_GREEN);
  osd_draw_green_gain(GAIN_INACTIVE);
  osd_highlight_choice_row(GAIN_ROW_BLUE,CHOICE_ROW_EDGED);
  osd_draw_blue_gain(GAIN_ACTIVE);
  osd_update_key_guide(3,5,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
