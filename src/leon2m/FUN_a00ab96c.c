/* leon2m FUN_a00ab96c @ 0xa00ab96c-0xa00aba34 (50 words), flags -mcpu=v8 -O3 -g.
 * FUN_a00abd00 / a00b7e68 family.
 * Code facts: col = 0x742 when the u8 'on' is set, else 0x792 (if-converted: cmp %g0 / addx -1 / and 0x50 / add
 * 0x742); FUN_a00ab5f0(0x2c, 6 / 8 / 10, DAT_a802d290 byte +0x12 / +0x13 / +0x14, 7, on) for row 0 / 1 / other; y
 * = row * 2 + 6; FUN_a0146a80(0x28, y, 3, col, 0), (0x2b, y, 1, col, 0), tail (0x32, y, 1, col, 0) (the 'and
 * 0xffe' is the u16 extension of col narrowed by its known bits). void.
 * Source form: the record base DAT_a802d290; one call per row arm; u8/u16 prototypes.
 * Compiler aids: none.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

void FUN_a00ab96c(unsigned char row, unsigned char on)
{
  unsigned short col;
  unsigned short y;

  if (on)
    col = 0x742;
  else
    col = 0x792;
  if (row == 0)
    FUN_a00ab5f0(0x2c, 6, DAT_a802d290[0x12], 7, on);
  else if (row == 1)
    FUN_a00ab5f0(0x2c, 8, DAT_a802d290[0x13], 7, on);
  else
    FUN_a00ab5f0(0x2c, 10, DAT_a802d290[0x14], 7, on);
  y = row * 2 + 6;
  FUN_a0146a80(0x28, y, 3, col, 0);
  FUN_a0146a80(0x2b, y, 1, col, 0);
  FUN_a0146a80(0x32, y, 1, col, 0);
}
