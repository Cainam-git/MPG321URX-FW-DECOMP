/* osd_set_highlight_window  (FUN_a00b3ed0)
 *
 * Place the highlight window over a menu area, or switch it off.
 *   param_1: on
 *   param_2: column
 *   param_3: row
 *   param_4: width
 * Note: Off when the first argument is 0; margins depend on the column.
 * Name basis: derived - osd_api_set_window_rect / _effect calls; called by every highlight routine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3ed0 @ 0xa00b3ed0, flags -mcpu=v8 -O3 -g.
 * Source form: the width is assigned (window_width = width) before the column tests; in the off case the two
 * assignments to edge_a_first / edge_a_second are dead stores that stay, osd_api_set_window_enable is called
 * with width as a fourth argument and the routine ends with 'return <call>'; the unused last two parameters and
 * the 'return CONCAT44(...)' of a void routine stay as they are (the build depends on them).
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern void osd_api_set_window_effect();
extern void osd_api_set_window_rect();
extern void osd_api_configure_window_reg30();
extern void osd_api_set_window_enable();

#define CELL_WIDTH_PIXELS 24    /* width of a menu cell in window rectangles */
#define CELL_ROW_PIXELS   36    /* height of a cell row in window rectangles */

/* Place the highlight over a menu area, or take it away. The highlight is two thin windows of the menu layer:
 * window 2 lies 0x16..0x19 lines below the top of the row, window 1 lies 0x3c lines lower (0x52..0x55). Both
 * span the same columns: from (column + 1) * 24 to (column + width) * 24 + 0x17.
 *   on:     0 switches windows 1 and 2 off and does nothing else;
 *   column: first cell column of the area;
 *   row:    cell row of the area (36 lines per row);
 *   width:  width in cells.
 * With on set, both windows are switched off, given the effect record (0xe), their rectangle and three register
 * groups (reg30 groups 0, 1 and 2), and the width used is reduced by 3 for column 1 and by 2 for columns 0x13
 * and 0x27. The first two numbers of the register groups 0 and 1 are (2, 3) and (4, 4) for column 1,
 * (2, 3) and (4, 5) for columns 0x13 and 0x27, and (7, 0x1c) and (0xb, 0x1f) for every other column.
 * The last two parameters are not used. Called by the highlight routines of the menus. */
void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width, unsigned int unused_5,
            unsigned int unused_6)

{
  unsigned int window_width;
  int row_top;
  int left;
  int right;
  unsigned char edge_b_first;
  unsigned char edge_b_second;
  unsigned char edge_a_first;
  unsigned char edge_a_second;
  
  column = column & 0xff;
  window_width = width;
  if (column == 1) {
    window_width = width - 3;
    edge_a_first = 2;
    edge_a_second = 3;
    edge_b_first = 4;
    edge_b_second = 4;
  }
  else if (column == 0x13 || column == 0x27) {
    edge_a_first = 2;
    edge_a_second = 3;
    edge_b_first = 4;
    window_width = width - 2;
    edge_b_second = 5;
  }
  else {
    edge_a_first = 7;
    edge_a_second = 0x1c;
    edge_b_first = 0xb;
    edge_b_second = 0x1f;
  }
  if (on == '\0') {
    osd_api_set_window_enable(1,0,0);
    edge_a_first = 2;
    edge_a_second = 0;
    return osd_api_set_window_enable(2,0,0,width);
  }
  osd_api_set_window_enable(1,0,0);
  osd_api_set_window_enable(2,0,0);
  osd_api_set_window_effect(2,0,0,0,0,0xe,0,0,0,0,0);
  row_top = (row & 0xff) * CELL_ROW_PIXELS;
  left = column * CELL_WIDTH_PIXELS + CELL_WIDTH_PIXELS;
  right = (column + (window_width & 0xff)) * CELL_WIDTH_PIXELS + 0x17;
  osd_api_set_window_rect(2,left,row_top + 0x16,right,row_top + 0x19,0);
  osd_api_configure_window_reg30(2,0,0,1,edge_a_first,edge_a_second,0);
  osd_api_configure_window_reg30(2,1,0,0,edge_b_first,edge_b_second,0);
  osd_api_configure_window_reg30(2,2,0,0,0,0,0);
  osd_api_set_window_effect(1,0,0,0,0,0xe,0,0,0,0,0);
  osd_api_set_window_rect(1,left,row_top + 0x52,right,row_top + 0x55,0);
  osd_api_configure_window_reg30(1,0,0,1,edge_a_first,edge_a_second,0);
  osd_api_configure_window_reg30(1,1,0,0,edge_b_first,edge_b_second,0);
  osd_api_configure_window_reg30(1,2,0,0,0,0,0);
  return CONCAT44((row & 0xff) * 8,column * 3);
}
