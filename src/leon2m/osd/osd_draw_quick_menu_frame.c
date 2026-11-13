/* osd_draw_quick_menu_frame  (FUN_a00a788c)
 *
 * Draw the frame and arrow cells of a quick menu by its kind.
 *   function: quick menu kind
 * Name basis: descriptive - called by the quick menu page drawer osd_draw_navi_quick_menu and
 *   osd_draw_input_quick_menu
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a788c @ 0xa00a788c, flags -mcpu=v8 -O3 -g.
 * Source form: x is assigned at the top of each outer arm (the firmware computes it before the inner tests), and
 * the "function 2..4 or 9" test is nested inside the outer else.
 */
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned char column, unsigned char row, unsigned char count, unsigned char first_glyph);

#define MENU_LAYER_MAIN       0
#define PLANE_0               0
#define NAVI_FUNCTION_BRIGHTNESS     1
#define NAVI_FUNCTION_REFRESH_RATE   7
#define NAVI_FUNCTION_INFO_ON_SCREEN 8
#define NAVI_FUNCTION_OPTIX_SCOPE    10
#define CELL_BLANK            0x792

/* Draw the frame cells of a quick menu, for the Navi Key function it belongs to
 * (function = the NAVI_FUNCTION_* number).
 *  - Brightness (1) and the three switches Refresh Rate (7), Info. On Screen (8)
 *    and Optix Scope (10): two single cells in row 8 (columns 3 and 0x12 for
 *    Brightness, 7 and 0xE for the others) get CELL_BLANK and glyph bytes 0x1A
 *    and 0x1B; the three runs below use attribute 0x399A.
 *  - Every other function uses attribute 0x3E9A; functions 2..4 and 9 also draw
 *    two 2-cell runs of attribute CELL_BLANK in column 10, rows 3 and 0xD.
 * Then six runs in rows 0xE..0x10 (left part with the attribute above, right
 * part with 0x489A). Called by the Navi Key quick menu drawer
 * (osd_draw_navi_quick_menu) and the input quick menu drawer
 * (osd_draw_input_quick_menu, which passes 5). */
void osd_draw_quick_menu_frame(unsigned char function)
{
  unsigned short x;
  unsigned char a, b;
  if (function == NAVI_FUNCTION_BRIGHTNESS || function == NAVI_FUNCTION_REFRESH_RATE || function == NAVI_FUNCTION_INFO_ON_SCREEN || function == NAVI_FUNCTION_OPTIX_SCOPE) {
    x = 0x399a;
    a = 7;
    b = 0xe;
    if (function == NAVI_FUNCTION_BRIGHTNESS) {
      a = 3;
      b = 0x12;
    }
    osd_api_fill_cells(a, 8, 1, CELL_BLANK, MENU_LAYER_MAIN);
    osd_api_fill_cells(b, 8, 1, CELL_BLANK, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, a, 8, 1, 0x1a, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, b, 8, 1, 0x1b, MENU_LAYER_MAIN);
  } else {
    x = 0x3e9a;
    if ((unsigned char)(function - 2) < 3 || function == 9) {
      osd_draw_cell_run(1, 1, CELL_BLANK, 10, 3, 2, 0x16);
      osd_draw_cell_run(1, 1, CELL_BLANK, 10, 0xd, 2, 0x18);
    }
  }
  osd_draw_cell_run(1, 0, x, 4, 0xe, 1, 0x75);
  osd_draw_cell_run(1, 0, 0x489a, 0xd, 0xe, 1, 0x75);
  osd_draw_cell_run(1, 1, x, 3, 0xf, 3, 0x76);
  osd_draw_cell_run(1, 1, 0x489a, 0xc, 0xf, 3, 0x76);
  osd_draw_cell_run(1, 0, x, 4, 0x10, 1, 0x79);
  osd_draw_cell_run(1, 0, 0x489a, 0xd, 0x10, 1, 0x7a);
}
