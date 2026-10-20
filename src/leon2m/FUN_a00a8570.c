/* leon2m FUN_a00a8570 @ 0xa00a8570-0xa00a8654 (57 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0..3 (u8): FUN_a00a31a4(0, 0x2a, i*2 + 6, 1,
 * FUN_a00a3844(ROM word table 0x18db28, (u16)(i*29 + byte 0xa802d290+8)), 0); b = byte +0x11;
 * row = (u8)(b <= 6 ? b*2 + 6 : b*2 - 8); FUN_a0146b20(0, 0x28, row, 1, 0xf, 0); tail FUN_a0146b20(0, 0x29, row, 1, 0x10, 0).
 * Fix vs the autoc draft (76.27): the table is 0x18db28 (fw sethi %hi(0x18d800) | 0x328; the draft read 0x18d828),
 * one record DAT_a802d290 (the fw hoists the full address: plain for loop), u8/void prototypes. Aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; unsigned char pad2[8]; unsigned char b11; };
extern struct St DAT_a802d290;
extern unsigned int DAT_0018db28[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);

void FUN_a00a8570(void)
{
  unsigned char i, row;

  FUN_a0146b50(0x111, 0);
  FUN_a0146b6c(0, 0);
  for (i = 0; i <= 3; i++)
    FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018db28, i * 29 + DAT_a802d290.b08), 0);
  if (DAT_a802d290.b11 <= 6)
    row = DAT_a802d290.b11 * 2 + 6;
  else
    row = DAT_a802d290.b11 * 2 - 8;
  FUN_a0146b20(0, 0x28, row, 1, 0xf, 0);
  FUN_a0146b20(0, 0x29, row, 1, 0x10, 0);
}
