/* leon2m FUN_a0151c84 @ 0xa0151c84  DispModeTransform
 * Flags: -mcpu=v8 -O3, no -g (with -g gcc adds a nop after the final printf call).
 *
 * Converts the RAW active panel row's byte +6 (FUN_a01241fc() = 0xA802E378) into a display mode number using the
 * 3-bit field b = row word 0 bits 17..19 (word & 0xE0000), prints "------>DispModeTransform %d,%d , %d" (byte,
 * field, mode) and returns the mode. Jump table on byte - 0x10 (0x10..0x42; firmware table at run-time 0xF1008):
 *   0x10 -> 1      0x11 -> 3 if b == 1 else 4      0x20 -> 5      0x21 -> 17 if b == 0 else 8
 *   0x22, 0x42 -> 13 if b == 2, 12 if b == 0, else 11              0x24 -> 14
 *   0x40 -> 6 if b == 0 else 5                     0x41 -> 10 if b == 2, 9 if b == 0, else 8      other -> 0
 * This panel's rows have word 0 = 0x2C120400 (b = 1): raw 0x42 -> 11 (rows 0/1, and row 2 in FW.012), raw 0x40 ->
 * 5 (row 2 in FW.021). Byte-identical in FW.012. Callers: FUN_a0141840, FUN_a0141964; inlined (same source file,
 * gcc -O3) in Disp_Init FUN_a0151db4 and in FUN_a015373c.
 * Source form: (1) case SOURCE order 0x10, 0x24, 0x20, 0x11, 0x21, 0x40, 0x41, 0x22/0x42: the
 *   register names inside the cases come from -frename-registers (least-recently-used register, ticks over the
 *   basic blocks in source order), so the computing cases must be in the order 0x11, 0x21, 0x40, 0x41, 0x22; the
 *   constant cases first; (2) case 0x22/0x42 written as an if / else-if chain (with ?: its tail is cross-jumped
 *   differently and bb-reorder puts case 0x41 or 0x24 first after the jmp instead of 0x40); the other cases may use
 *   if/else or ?: (same code); (3) int m = 0 before the switch, no default; (4) the printed field is the bitfield
 *   RowHdr.fmt (makes the original re-read word 0 after the switch).
 */
struct RowHdr
{
  unsigned int hi : 12;
  unsigned int fmt : 3;
  unsigned int lo : 9;
  unsigned char mode;
  unsigned char b7;
};
extern unsigned char *FUN_a01241fc(void);
extern int FUN_a00df170();
extern char s_001a74f0[];
int FUN_a0151c84(void)
{
  unsigned char *row = FUN_a01241fc();
  int m = 0;
  switch (row[6])
  {
    case 0x10: m = 1; break;
    case 0x24: m = 14; break;
    case 0x20: m = 5; break;
    case 0x11: if ((*(unsigned int *)row & 0xe0000) == 0x20000) m = 3; else m = 4; break;
    case 0x21: if ((*(unsigned int *)row & 0xe0000) == 0) m = 17; else m = 8; break;
    case 0x40: if ((*(unsigned int *)row & 0xe0000) == 0) m = 6; else m = 5; break;
    case 0x41: if ((*(unsigned int *)row & 0xe0000) == 0x40000) m = 10; else if ((*(unsigned int *)row & 0xe0000) == 0) m = 9; else m = 8; break;
    case 0x22: case 0x42: if ((*(unsigned int *)row & 0xe0000) == 0x40000) m = 13; else if ((*(unsigned int *)row & 0xe0000) == 0) m = 12; else m = 11; break;
  }
  FUN_a00df170(s_001a74f0, row[6], ((struct RowHdr *)row)->fmt, m);
  return m;
}
