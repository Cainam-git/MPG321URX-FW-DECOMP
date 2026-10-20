/* leon2m FUN_a00a835c @ 0xa00a835c-0xa00a8440 (57 words).
 * Row loop over 5 entries: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0..4: FUN_a00a31a4(0, 0x2a, i * 2 + 6,
 * 1, FUN_a00a3844(word table 0x1890d4, i * 29 + byte 0xa802d298), 0). Then the row of the selected entry, byte
 * 0xa802d3eb (offset 0x15b of the block at 0xa802d290), b * 2 + 6 for b <= 6 and b * 2 - 8 otherwise, is marked with
 * FUN_a0146b20(0, 0x28, row, 1, 0xf, 0) and FUN_a0146b20(0, 0x29, row, 1, 0x10, 0). Same code as FUN_a00a8570 with
 * another table, row count and selection byte.
 */
struct St { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0x15b - 9]; unsigned char b15b; };
extern struct St DAT_a802d290;
extern unsigned int DAT_001890d4[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);

void FUN_a00a835c(void)
{
  unsigned char i, row;

  FUN_a0146b50(0x111, 0);
  FUN_a0146b6c(0, 0);
  for (i = 0; i <= 4; i++)
    FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_001890d4, i * 29 + DAT_a802d290.b08), 0);
  if (DAT_a802d290.b15b <= 6)
    row = DAT_a802d290.b15b * 2 + 6;
  else
    row = DAT_a802d290.b15b * 2 - 8;
  FUN_a0146b20(0, 0x28, row, 1, 0xf, 0);
  FUN_a0146b20(0, 0x29, row, 1, 0x10, 0);
}
