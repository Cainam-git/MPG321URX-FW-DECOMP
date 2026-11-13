/* osd_draw_adjust_key_guide  (FUN_a00ab4bc)
 *
 * Draw the three-row key guide icons used beside adjustable values.
 * Name basis: descriptive - glyph cells in the key guide column 0x37..0x3A; called by OLED Care and colour
 *   gain handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ab4bc @ 0xa00ab4bc, flags -mcpu=v8 -O3 -g.
 * Source form: two nested byte do-while loops; plain arithmetic on the byte and unsigned short locals. The last
 * glyph of a row is "2 * i + 0x2b" (the firmware adds 0x2b to 2 * i).
 */
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN 0
#define PLANE_0         0
#define KEY_GUIDE_COLUMN 0x37    /* the guide occupies columns 0x37..0x3A */

/* Draw the key guide icons for adjustable values in all three row groups at
 * the right edge (rows 6..8, 11..13 and 16..18, the same groups as
 * osd_draw_key_guide). Each row gets cell value 0x992 at columns 0x37 and 0x3A
 * and 0x349E at columns 0x38, 0x39, and four glyph bytes: 2 * k + 0x2a,
 * 2 * k + 0x17, 2 * k + 0x18 and 2 * k + 0x2b at columns 0x37..0x3A, where k is
 * the row within its group (0..2). Called by the OLED Care and colour gain
 * handlers. */
void osd_draw_adjust_key_guide(void)
{
  unsigned char k;
  unsigned char group;
  unsigned char group_offset;
  unsigned short row;
  group = 0;
  do
  {
    group_offset = group * 5;
    k = 0;
    do
    {
      row = k + group_offset + 6;
      osd_api_fill_cells(KEY_GUIDE_COLUMN, row, 1, 0x992, MENU_LAYER_MAIN);
      osd_api_fill_cells(0x38, row, 2, 0x349e, MENU_LAYER_MAIN);
      osd_api_fill_cells(0x3a, row, 1, 0x992, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, KEY_GUIDE_COLUMN, row, 1, k * 2 + 0x2a, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, 0x38, row, 1, k * 2 + 0x17, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, 0x39, row, 1, k * 2 + 0x18, MENU_LAYER_MAIN);
      osd_api_fill_cell_bytes(PLANE_0, 0x3a, row, 1, k * 2 + 0x2b, MENU_LAYER_MAIN);
      k++;
    }
    while (k <= 2);
    group++;
  }
  while (group <= 2);
}
