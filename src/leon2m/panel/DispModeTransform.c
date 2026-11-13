/* DispModeTransform  (FUN_a0151c84)
 *
 * Derive the display mode from a panel mode row.
 * Name basis: proven - prints '------>DispModeTransform %d,%d , %d' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0151c84 @ 0xa0151c84, flags -mcpu=v8 -O3, no -g (with -g gcc adds a nop after the final printf).
 * Source form: (1) the case order 0x10, 0x24, 0x20, 0x11, 0x21, 0x40, 0x41, 0x22/0x42: the register names inside
 *   the cases come from -frename-registers, so the computing cases must stand in the order 0x11, 0x21, 0x40,
 *   0x41, 0x22 and the constant cases first; (2) case 0x22/0x42 is an if / else-if chain (with ?: its tail is
 *   cross-jumped differently); the other cases may use if/else or ?:; (3) display_mode = 0 before the switch, no
 *   default; (4) the printed field is the bitfield RowHdr.fmt (makes the firmware re-read word 0 after the switch).
 */

/* The 3-bit field of word 0 of the panel row that selects between variants of a display mode (word & mask). */
#define ROW_FIELD_MASK 0xe0000
#define ROW_FIELD_1    0x20000
#define ROW_FIELD_2    0x40000

/* Word 0 of a panel row; fmt is the 3-bit field under ROW_FIELD_MASK. */
struct RowHdr
{
  unsigned int hi : 12;
  unsigned int fmt : 3;
  unsigned int lo : 9;
  unsigned char mode;
  unsigned char b7;
};
extern unsigned char *panel_get_active_row(void);
extern int dbg_printf();

/*
 * Derive the display mode number from the active panel row: its byte +6 (the row's display mode) together with
 * the 3-bit field of word 0 (field = 0, 1 or 2 where it matters). Prints byte, field and result; returns the
 * mode, 0 for a byte not listed here.
 *
 *   byte 0x10 -> 1       0x11 -> 3 if field 1, else 4      0x20 -> 5     0x21 -> 17 if field 0, else 8
 *   byte 0x22 or 0x42 -> 13 if field 2, 12 if field 0, else 11             0x24 -> 14
 *   byte 0x40 -> 6 if field 0, else 5                      0x41 -> 10 if field 2, 9 if field 0, else 8
 *
 * Called from panel_transform_row and startup_init_display_output; inlined in Disp_Init and panel_setup_output_after_row_change.
 */
int DispModeTransform(void)
{
  unsigned char *row = panel_get_active_row();
  int display_mode = 0;
  switch (row[6])
  {
    case 0x10: display_mode = 1; break;
    case 0x24: display_mode = 14; break;
    case 0x20: display_mode = 5; break;
    case 0x11: if ((*(unsigned int *)row & ROW_FIELD_MASK) == ROW_FIELD_1) display_mode = 3; else display_mode = 4; break;
    case 0x21: if ((*(unsigned int *)row & ROW_FIELD_MASK) == 0) display_mode = 17; else display_mode = 8; break;
    case 0x40: if ((*(unsigned int *)row & ROW_FIELD_MASK) == 0) display_mode = 6; else display_mode = 5; break;
    case 0x41: if ((*(unsigned int *)row & ROW_FIELD_MASK) == ROW_FIELD_2) display_mode = 10; else if ((*(unsigned int *)row & ROW_FIELD_MASK) == 0) display_mode = 9; else display_mode = 8; break;
    case 0x22: case 0x42: if ((*(unsigned int *)row & ROW_FIELD_MASK) == ROW_FIELD_2) display_mode = 13; else if ((*(unsigned int *)row & ROW_FIELD_MASK) == 0) display_mode = 12; else display_mode = 11; break;
  }
  dbg_printf("------>DispModeTransform %d,%d , %d\r\n", row[6], ((struct RowHdr *)row)->fmt, display_mode);
  return display_mode;
}
